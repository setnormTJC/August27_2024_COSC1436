//requires C++ version 17

#include<filesystem>

#include <iostream>

void demoPrayKitty()
{
    std::filesystem::current_path("C:\\Users\\Work\\Desktop\\misc\\someVideos");
    system("prayKitty.mp4");
}

void demoOpenWebPage()
{
    system("start https://vimeo.com/375468729");
}


int main()
{
    //demoPrayKitty(); 

    demoOpenWebPage(); 

    std::cout << "Hello World!\n";
}

