#include <iostream>

using namespace std;

int main()
{
    //comment 
    //Cout << ""

    //initialize an integer type variable to hold the value 2
    int aNumber = 2; 

    /*
    * This code below does this and this. 
    * It also does this other thing. 
    */

    //
    //
    //
    //5 + 2 //+ is called an "operator" 
        //5 and 2 are called "operands"

        //int old = 31; 

    //int oldVariable = 856; //camelCase

    int someInteger = INT_MAX + 1;
    std::locale l(""); 
    cout.imbue(l); 

    cout << "Int max + 1: " << someInteger << "\n";
    cout << "sizeof(int) is: " << sizeof(int) << " Bytes \n";

    //cout << UINT_MAX << "\n";

    //8 bits = 1 Byte
    //1111 1111 


    return 0;
}