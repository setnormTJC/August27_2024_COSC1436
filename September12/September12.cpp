

#include <iostream>

#include<string>

using namespace std; 

int main()
{

    //basic arithmetic operations in C++
    //+, -, *, /, %

    //cout << 5 / 2 << "\n";
    //cout << "The remainder of 5/2 is: " << 5 % 2 << "\n";

    double dividend = 34.5; 

    //cout << sizeof(float) << "\t" << sizeof(double) << "\n";
    double divisor = 6.5; // gets interpreted as 3?  

    //cout << "dividend/divisor = " << dividend << "/" << divisor << " = "
    //    << dividend / divisor << "\n";


    int totalInches = 48; 
    int equivalentFeet =totalInches / 12; 
    int remainingInches = totalInches % 12;

    //cout << pow(3, 2) << "\n"; //hat and caret

    //cout << totalInches << " is equal to " << equivalentFeet 
    //    << " feet and " << remainingInches << " inches.\n";
    //
    //typecasting
    //cout << (double)5 << "\n";//C-style cast
    //static_cast<int> (5.423) //C++ style cast //hold off on this stuff until F -> C conversion 
    int aNumber = 34; 

    //const int DOZEN = 12; 

    //const int BAKERS_DOZEN = 13; //SCREAMING_SNAKE case 

    //const double TAX_RATE = 0; //what about "tax free weekend" 
    ////constant 
    ////TAX_RATE = 0.0825; 


    //double priceWithoutTax = 10.00; 

    //double totalPrice = priceWithoutTax + (priceWithoutTax *TAX_RATE);

    //cout << "Total price is: " << totalPrice << "\n";

    cout << "enter your name: \n"; 
    string yourName; 
    cin >> yourName; 
    //getline(cin, yourName); 

    //echo user's input back at them (getch) 

    cout << "You entered: " << yourName << "\n\n\n\n\n";





















    int numberOfLikes = 12;

    cout << "BEFORE: " << numberOfLikes << "\n";
    numberOfLikes++;  //the SINGLE equals sign is the "assignment operator" (high-fallutin'!) 
    numberOfLikes++;

    numberOfLikes += 123; 

    numberOfLikes = 42; 

    int firstNumber{}; //0? (the brace initializer syntax) -> 2011 
    int secondNumber = 123; 

    int product; //declare a variable to hold the value of the product (uninitialized) 

    //firstNumber* secondNumber = product; 
    //2 * 4 = 8
    //    8 = 2 * 4

    product = firstNumber * secondNumber; 
    cout << "product is: " << product << "\n";

    //char letterGrade = 'B+';
    //int age = "11 years" //months? 
    //cout << "Is letter B+? " << letterGrade << "\n";
    //x = x + 1 ? 
    //0 = 0 + 1? 
    
    //C++ -> the C langauge "plus 1" (version 2.0) 
    
    cout << "AFTER the incrementation operation: " << numberOfLikes << "\n";
    //0 = 1

}
