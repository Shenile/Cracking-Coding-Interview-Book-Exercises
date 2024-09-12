#include <iostream>
#include <cstring> 
#include <algorithm> 
#include <conio.h>

void reverse(char* str) {
    int i = 0, j = strlen(str) - 1; 
    while (i < j) {
        std::swap(str[i], str[j]);
        i++;
        j--;
    }
}

int main() {
    int size;
    std::cout << "Enter the size of the string (including null terminator): ";
    std::cin >> size;
    std::cin.ignore(); 

    char* str = new char[size]; 

    std::cout << "Enter the string: ";
    std::cin.getline(str, size); 
     
    std::cout << "Original String: " << str << std::endl;

    reverse(str); 

    std::cout << "Reversed String: " << str << std::endl;

    delete[] str; 
    _getch();
    return 0;
}
