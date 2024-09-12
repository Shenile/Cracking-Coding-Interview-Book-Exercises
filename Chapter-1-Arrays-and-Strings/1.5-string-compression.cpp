/*
   Source: Cracking the Coding Interview by Gayle Laakmann McDowell,
   Chapter Name: Array and strings
   Problem Number: 1.5

   Problem Statement:

   Implement a method to perform basic string compression using the counts
   of repeated characters. For example, the string aabcccccaaa would become
   a2blc5a3. If the "compressed" string would not become smaller than the original string, 
   your method should return the original string.

   Solutions Analysis:

      Time Complexity: O(n)
      Space Complexity: O(n),
*/

#include <iostream>
#include <string>


std::string stringCompressor(std::string str) {
    // Implement optimal solution here
    std::string result;
    int i = 0, j = 1, count = 1;


    while(j < str.length()){
         
        if(str[i] == str[j] ){
            count++;
            j++;
           
        }else{
            result += str[i];
            result += std::to_string(count);
            count = 1;
            i = j;
            j++;

        }
    }
    result += str[i];
    result += std::to_string(count);
    return (result.length() > str.length()) ? str : result;
    
}

int main() {
    std::string testString = "aabbccdd";

    // Test Optimal Solution
    std::cout << "Running Optimal Solution..." << std::endl;
    std::cout << "Result : " << stringCompressor(testString) << std::endl ;

    return 0;
}