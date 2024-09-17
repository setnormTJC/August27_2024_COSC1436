#include <iostream>
#include <iomanip>
#include <fstream> // Include this header for std::ofstream

//using namespace std; 

int main()
{
    system("chcp 65001");

    std::locale::global(std::locale("en_US.UTF-8"));
    std::wcout.imbue(std::locale());
    
    std::wcout << L"\U00000393\n"; //Gamma

    std::wcout << L"\U00003041\n"; // some hiragana character 

    //"dingbats"
    std::wcout << L"\U0000270A\n"; //the yella fist! 
    //https://en.wikipedia.org/wiki/Raised_fist
    std::wcout << L"\U00002728\n"; //sparkles ("I have anxiety ...")

    //"emojis"
    std::wcout << L"\U0000261C\n"; //pointy finger
    std::wcout << L"\U00002639\n"; //frowny

    //system("pause");

    for (unsigned int ch = 0x0000; ch <= 0xFFFF; ++ch) //65,000 characters
    {
        std::wcout << L"U+" 
            << std::hex << std::setw(4) 
            << std::setfill(L'0') << ch << L": " 
            << static_cast<wchar_t>(ch) << L"\n";
    }
    //for (wchar_t ch = 0x0000; ch <= 0xFFFF; ++ch) //65,000 characters
    //{
    //    std::wcout << L"U+" 
    //        << std::hex << std::setw(4) 
    //        << std::setfill(L'0') << ch << L": " 
    //        << ch << L"\n";
    //}
    //open cmd prompt -> systeminfo (sans space) command displays locale 

    std::wcout << "\n";
    
    std::wcout << L"こんにちは世界\n\n"; //ko-nee-chee-wa, se-kai (Japanese)

    std::wcout << L"नमस्ते, संसार\n\n"; //namaste, sansara (Nepali) 
    
    std::wcout << L"안녕, 세계\n\n"; //ann-yong, seg-yeh (Korean) 
    
    std::cout << "Hello, World!\n\n";
}
