#include <iostream>
#include <cstdint>
using namespace std;

/*
Decompiler Snippet:

undefined4 __cdecl encrypt_password_input(char param_1)

{
  char cVar1;
  
  if (('`' < param_1) && (param_1 < '{')) {
    param_1 = param_1 + (char)_DAT_00403008_is_4;
  }
  cVar1 = param_1;
  if (('@' < param_1) && (param_1 < '[')) {
    param_1 = param_1 + (char)_DAT_00403008_is_4;
  }
  return CONCAT31(cVar1 >> 7,param_1);
}

*/
void reverser(char *stringInput)
{
    char cVar1;
    
    while (*stringInput != '\0') {
        cVar1 = *stringInput;
        
        // Check if the character lowercase
        if (cVar1 >= 'a' && cVar1 <= 'z') {
            cVar1 = cVar1 - 4;

            // for wrap-around
            if (cVar1 < 'a') {
                cVar1 = 'z' - ('a' - cVar1 - 1);
            }
            
            *stringInput = cVar1;
        }
        // Check if the character is uppercase
        if (cVar1 >= 'A' && cVar1 <= 'Z') {
            cVar1 = cVar1 - 4;

            // if wrap-around 
            if (cVar1 < 'A') {
                cVar1 = 'Z' - ('A' - cVar1 - 1);
            }
            
            *stringInput = cVar1;
        }
        stringInput = stringInput + 1;
    }
}


int main() {
    cout << "input string: " << endl;
    char inputString[100];
    cin.getline(inputString, 100);
    reverser(inputString);
    cout << "reversed string: " << inputString << endl;
    return 0;
};