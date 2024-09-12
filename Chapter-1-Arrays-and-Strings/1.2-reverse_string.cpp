
/*
   Source: Cracking the Coding Interview by Gayle Laakmann McDowell,
   Chapter Name: Arrays and Strings,
   Problem Number: 1.2

   Problem Statement:

   Implement a function void reverse(char* str) in C or C++ which reverses a nullterminated string.
   
*/

#include <iostream>
#include <cstring> 
#include <algorithm> 

void reverse(char* str) {
    int i = 0, j = strlen(str) - 1; 
    while (i < j) {
        std::swap(str[i], str[j]);
        i++;
        j--;
    }
}

int main() {
    
    char str[] = "teststring";
    std::cout << "Original String: " << str << std::endl;

    reverse(str); 

    std::cout << "Reversed String: " << str << std::endl;

    return 0;
}
