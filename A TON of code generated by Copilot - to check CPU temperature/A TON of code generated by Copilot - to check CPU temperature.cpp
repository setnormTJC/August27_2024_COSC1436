#include <iostream>
#include <comdef.h>
#include <Wbemidl.h>

#pragma comment(lib, "wbemuuid.lib")

void initializeCOM() {
    HRESULT hres = CoInitializeEx(0, COINIT_MULTITHREADED);
    if (FAILED(hres)) {
        std::cerr << "Failed to initialize COM library. Error code = 0x"
            << std::hex << hres << std::endl;
        exit(1);
    }
}

void initializeSecurity() {
    HRESULT hres = CoInitializeSecurity(
        NULL,
        -1,                          // COM authentication
        NULL,                        // Authentication services
        NULL,                        // Reserved
        RPC_C_AUTHN_LEVEL_DEFAULT,   // Default authentication 
        RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation  
        NULL,                        // Authentication info
        EOAC_NONE,                   // Additional capabilities 
        NULL                         // Reserved
    );

    if (FAILED(hres)) {
        std::cerr << "Failed to initialize security. Error code = 0x"
            << std::hex << hres << std::endl;
        CoUninitialize();
        exit(1);
    }
}

IWbemLocator* initializeWbemLocator() {
    IWbemLocator* pLoc = NULL;
    HRESULT hres = CoCreateInstance(
        CLSID_WbemLocator,
        0,
        CLSCTX_INPROC_SERVER,
        IID_IWbemLocator, (LPVOID*)&pLoc);

    if (FAILED(hres)) {
        std::cerr << "Failed to create IWbemLocator object. "
            << "Error code = 0x" << std::hex << hres << std::endl;
        CoUninitialize();
        exit(1);
    }

    return pLoc;
}

IWbemServices* connectWbemServices(IWbemLocator* pLoc) {
    IWbemServices* pSvc = NULL;
    HRESULT hres = pLoc->ConnectServer(
        _bstr_t(L"ROOT\\WMI"), // Object path of WMI namespace
        NULL,                    // User name. NULL = current user
        NULL,                    // User password. NULL = current
        0,                       // Locale. NULL indicates current
        NULL,                    // Security flags.
        0,                       // Authority (e.g. Kerberos)
        0,                       // Context object 
        &pSvc                    // pointer to IWbemServices proxy
    );

    if (FAILED(hres)) {
        std::cerr << "Could not connect. Error code = 0x"
            << std::hex << hres << std::endl;
        pLoc->Release();
        CoUninitialize();
        exit(1);
    }

    return pSvc;
}

void setProxySecurity(IWbemServices* pSvc) {
    HRESULT hres = CoSetProxyBlanket(
        pSvc,                        // Indicates the proxy to set
        RPC_C_AUTHN_WINNT,           // RPC_C_AUTHN_xxx 
        RPC_C_AUTHZ_NONE,            // RPC_C_AUTHZ_xxx 
        NULL,                        // Server principal name 
        RPC_C_AUTHN_LEVEL_CALL,      // RPC_C_AUTHN_LEVEL_xxx 
        RPC_C_IMP_LEVEL_IMPERSONATE, // RPC_C_IMP_LEVEL_xxx
        NULL,                        // client identity
        EOAC_NONE                    // proxy capabilities 
    );

    if (FAILED(hres)) {
        std::cerr << "Could not set proxy blanket. Error code = 0x"
            << std::hex << hres << std::endl;
        pSvc->Release();
        CoUninitialize();
        exit(1);
    }
}

void queryTemperature(IWbemServices* pSvc) {
    IEnumWbemClassObject* pEnumerator = NULL;
    HRESULT hres = pSvc->ExecQuery(
        bstr_t("WQL"),
        bstr_t("SELECT * FROM MSAcpi_ThermalZoneTemperature"),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
        NULL,
        &pEnumerator);

    if (FAILED(hres)) {
        std::cerr << "Query for temperature probes failed. "
            << "Error code = 0x" << std::hex << hres << std::endl;
        pSvc->Release();
        CoUninitialize();
        exit(1);
    }

    IWbemClassObject* pclsObj = NULL;
    ULONG uReturn = 0;

    while (pEnumerator) {
        HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
            &pclsObj, &uReturn);

        if (0 == uReturn) {
            break;
        }

        VARIANT vtProp;
        hr = pclsObj->Get(L"CurrentTemperature", 0, &vtProp, 0, 0);
        if (SUCCEEDED(hr)) {
            // The temperature is reported in tenths of Kelvin
            double temperatureKelvin = vtProp.uintVal / 10.0;
            std::wcout << "Current Temperature : " << temperatureKelvin << " K" << std::endl;
        }
        VariantClear(&vtProp);
        pclsObj->Release();
    }

    pEnumerator->Release();
}

int main() {
    initializeCOM();
    initializeSecurity();
    IWbemLocator* pLoc = initializeWbemLocator();
    IWbemServices* pSvc = connectWbemServices(pLoc);
    setProxySecurity(pSvc);
    queryTemperature(pSvc);

    pSvc->Release();
    pLoc->Release();
    CoUninitialize();

    return 0;
}