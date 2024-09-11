/*
   Source: Cracking the Coding Interview by Gayle Laakmann McDowell,
   Chapter Name: Arrays and Strings
   Problem Number: 1.2

   Problem Statement:
   
   Implement a function void reverse(char* str) in C or C++ which reverses a null - terminated string.

   Solutions Analysis:

   Optimal Solution :  

      -> Time Complexity: O(n)
      -> Space Complexity: O(1)
*/

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <conio.h>


void reverse(char* str){
     int i = 0, j = strlen(str);
    
     while (i < j){
        std::swap(str[i], str[j]);
        i++;
        j--;
     }
     
}

int main() {

    char str[] = "teststring";
    
    reverse(str);
    
    for(auto s : str){
        std::cout << s << " ";
    }

    _getch();
    return 0;

}