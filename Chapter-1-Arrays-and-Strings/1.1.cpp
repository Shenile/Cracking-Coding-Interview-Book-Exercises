

/* 

   Source: Cracking the Coding Interview by Gayle Laakmann McDowell,
   Chapter Name : Arrays and Strings,
   Problem Number - 1.1,

   Problem Statement :
   
   Implement an algorithm to determine if a string has all unique characters. What
   if you cannot use additional data structures?  

   Solutions Analysis : 

   Brute Force Solution :
      
      Time Complexity  - O(n^2)
      Space Complexity - O(1)

   Optimal Solution : 

      Time Complexity  - O(n log n)
      Space Complexity - O(1)
   
*/

#include <iostream>
#include <string>
#include <algorithm>

bool optimalSolution(std::string testString) {
 
    std::sort(testString.begin(), testString.end());
    
    bool hasDuplicate = false;
    
    
  
    for (size_t i = 1; i < testString.length(); ++i) {
        if (testString[i - 1] == testString[i]) {
            hasDuplicate = true;
            break; 
        }
    }
    
    return hasDuplicate;
}

bool bruteForceSolution(const std::string& testString) {
    bool hasDuplicate = false;
    for (size_t i = 0; i < testString.length(); ++i) {
        for (size_t j = i + 1; j < testString.length(); ++j) {
            if (testString[i] == testString[j]) {
                hasDuplicate = true;
                break; 
            }
        }
        if (hasDuplicate) {
            break; 
        }
    }
    return hasDuplicate;
}

int main() {
    std::string testString = "Vhla";
   
    // Brute Force Method
    std::cout << "Brute force solution result: " << (bruteForceSolution(testString) ? "True" : "False") << std::endl;

    // Optimal method Using Sorting
    std::cout << "Optimal solution result: " << (optimalSolution(testString) ? "True" : "False") << std::endl;
    
    return 0;
}
