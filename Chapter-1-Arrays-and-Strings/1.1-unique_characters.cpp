

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
#include <cctype>

bool isUnique_optimal(std::string testString) {
 
    std::sort(testString.begin(), testString.end());
    
    bool isUnique = true;
    
    
  
    for (size_t i = 1; i < testString.length(); ++i) {
        if (testString[i - 1] == testString[i]) {
            isUnique = false;
            break; 
        }
    }
    
    return isUnique;
}

bool isUnique_brute_force(const std::string& testString) {
    bool isUnique = true;
    for (size_t i = 0; i < testString.length(); ++i) {
        for (size_t j = i + 1; j < testString.length(); ++j) {
            if (testString[i] == testString[j]) {
                isUnique = false;
                break; 
            }
        }
        if (!isUnique) {
            break; 
        }
    }
    return isUnique;
}

int main() {
    std::string testString = "Vohla";
    
    for(auto& s : testString){
        s = tolower(s);
    }
    // Brute Force Method
    std::cout << "Brute force solution result: " << (isUnique_brute_force(testString) ? "True" : "False") << std::endl;

    // Optimal method Using Sorting
    std::cout << "Optimal solution result: " << (isUnique_optimal(testString) ? "True" : "False") << std::endl;
    
    return 0;
}
