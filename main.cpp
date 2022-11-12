#include <iostream> //needed for outputting to screen
#include <fstream> //needed for file input
#include <string> //needed for use of strings inside funtions
#include <iomanip> //needed for setw() in functions
 
using namespace std; //called so that i dont have to write "std::" a billion times

//precondition: in order for the input function to run, it needs to have the values passed by reference thats already inside the function () otherwise i would have to declare them inside the actual fucntion itself
//poscondition: everything is calculated and outputted to the screen
void input( char &data, ifstream &inFile, unsigned int &num, string &binaryNum, bool &startWithZero ); //call to declare input function
 
//precondition: program cannot be executed without main
//postondition: program is executed
int main() //int main
{
    string binaryNum; //string for when adding the numbers together to later on output under "Binary Number"
    bool startWithZero = false; //bool set to false, checks to see if binary number starts with zero in the infile
    char data; //character data called to grab the numbers from the infile as characters
    ifstream inFile; //creates ifstream and names in inFile so that the function can evaluate whatever is in the infile
    unsigned int num = 0; //int num = 0 called to later help calculate decimal equivalent... used unsigned because it was making the calculation wrong without it

    input(data, inFile, num, binaryNum, startWithZero); //called input function inside the main so that it outputs everything
 
    return 0; //return call
}

void input( char &data, ifstream &inFile, unsigned int &num, string &binaryNum, bool &startWithZero ) //input function does everything in the code
{
    inFile.open("/Users/austinbergum/Desktop/Xcode Projects/Lab 6/BinaryIn.dat"); //opens input file, gonna need to change name because I can only put in the location of file
    
    cout << setw(28) << "Binary Number" << setw(51) << "Decimal Equivalent" << endl; //sets widths and outputs phrases at the top
    
    if (!inFile) //called for if the code cannot locate the infile
    {
        cout << "Can't find the file..." << endl;
    }
    
    inFile.get(data); //called to grab first character so that it can be evaluated
    
    while (inFile) //while loop runs while it reads in from the infile
    {
        while (data != '\n' && inFile) //while loop runs when theres no \n character, when \n is found it exits the while loop and grabs a new character and goes right back in the loop
        {
            num *= 2; //num calculation for decimal equivalent=
            
            if (data == '1') //following is executed if char data value = 1
            {
                startWithZero = true; //sets bool = to true if data = 1 for later if statement
                num++; //adds one to num everytime it finds one.... used for calculating decimal equivalent
                //x++;
                if (startWithZero == true) //runs if bool = true
                {
                    binaryNum += '1'; //adds character 1 to binarynum and then sets it back equal to itself
                }
                inFile.get(data); //gets new character
            }
            else if (data == '0') //executed if char data = 0
            {
                if (startWithZero == true) //executes if bool is true
                {
                    binaryNum += '0'; //adds character 0 to binarynum and sets it back equal to itself
                }
                inFile.get(data); //gets new character
            }
            else if (data == ' ') //executes if character data = space
            {
                inFile.get(data); //gets new character
            }
            else //executes if not any of the conditions above
            {
                binaryNum = "Bad digit on input\n"; //outputs bad digit if valid
                inFile.ignore(100, '\n'); //ignores the next 100 character until it reaches \n
                inFile.get(data); //gets new character
            }
        }
        inFile.get(data); //gets new character
        
        cout << binaryNum; //outputs the binary number to the screen
       
        if (num != 0) //executed in num is not = to 0
        {
            cout << "\t\t\t\t\t\t\t" << num << endl; //outputs num to screen
        }
        
        startWithZero = false; //set bool back = to false so that the previous if statements can be executed in the while loop
        binaryNum = '\0';
        num = 0; //sets num back to zero
    }
}

