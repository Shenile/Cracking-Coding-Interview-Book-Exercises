/*
   Source: Cracking the Coding Interview by Gayle Laakmann McDowell,
   Chapter Name: Array and Strings
   Problem Number: 1.3

   Problem Statement:

   -> Given two strings, write a method to decide if one is a permutation of the other.

   Solutions Analysis:

    Brute Force Solution:
      -> Time Complexity: O(n log n)  // Due to sorting of both strings
      -> Space Complexity: O(1)       // Sorting in-place, no extra space required

   Optimal Solution:
      -> Time Complexity: O(n)        // Single pass through both strings to count characters
      -> Space Complexity: O(1)       // Fixed-size hashmap of 256 characters (constant space)
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

bool ispermutation_bruteForce(std::string str1, std::string str2) {
    // Implement brute force solution here
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    for(int i = 0; i < str1.length(); i++){
        if(str1[i] != str2[i]){
           return false;
        }
    }
    return true;
}

bool ispermutation_optimal(std::string str1, std::string str2) {
     //using a hashmap
     std::unordered_map<char, int> map;

     if(str1.length() != str2.length()){
        return false;
     }

     for(auto s : str1){
        map[s]++;
     }

     for(auto s : str1){
        map[s]--;
        if(map[s] < 0){
            return false;
        }
     }

     return true;

}

int main() {
    
    std::string str1 = "batman";
    std::string str2 = "nabatm";

    // Test Brute Force Solution
    std::cout << "Running Brute Force Solution..." << std::endl;
    std::cout << "Result : " <<  ((ispermutation_bruteForce(str1, str2)) ? "yes" : "no") << std::endl;

    // Test Optimal Solution
    std::cout << "Running Optimal Solution..." << std::endl;
    std::cout << "Result : " << ((ispermutation_optimal(str1, str2)) ? "yes" : "no") << std::endl;

    return 0;
}