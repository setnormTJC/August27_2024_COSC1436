
#include <iostream>

//using namespace std; 

int main()
{
    system("chcp 65001");

    std::locale::global(std::locale("en_US.UTF-8"));
    std::wcout.imbue(std::locale());

    //open cmd prompt -> systeminfo (sans space) command displays locale 

    std::wcout << "\n";
    
    std::wcout << L"こんにちは世界\n\n"; //ko-nee-chee-wa, se-kai (Japanese)
    
    std::wcout << L"नमस्ते, संसार\n\n"; //namaste, sansara (Nepali) 
    
    std::wcout << L"안녕, 세계\n\n"; //ann-yong, seg-yeh (Korean) 
    
    std::cout << "Hello, World!\n\n";



}
