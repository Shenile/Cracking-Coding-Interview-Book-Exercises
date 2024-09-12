/*
   Source: Cracking the Coding Interview by Gayle Laakmann McDowell,
   Chapter Name: Arrays and strings,
   Problem Number: 1.4,

   Problem Statement:

   This problem is also known as URLify ..,

   Write a method to replace all spaces in a string with '%20'. You may assume that
   the string has sufficient space at the end of the string to hold the additional
   characters, and that you are given the "true" length of the string. 

   EXAMPLE ->
    Input:  "Mr John Smith    "
    Output: "Mr%20Dohn%20Smith"
   

   Solutions Analysis:

   Brute Force Solution:
      Time Complexity: O(n),
      Space Complexity: O(n)

   Optimal Solution:
      Time Complexity: O(n)
      Space Complexity: O(1),
*/

#include <iostream>
#include <string>


std::string urlify_bruteForce(std::string str) {

    // Implement brute force solution here
    std::string result_str;
    int size = str.length();
    int i = 0;
    while(i < str.length()){

      
        if(str[i] == ' ' && (result_str.length() < size) ){
            result_str += "%20";
        }else{
            result_str += str[i];
        }

        i++;
    }

    return result_str;

}

std::string urlify_Optimal(std::string str) {


    std::string result_str;

    //intialize result with null values;
    result_str.resize(str.length());
    std::string replacement_str = "%20";

    int i = 0, j = 0;

    while(j < str.length()){

        if(str[i] == ' '){

            for(auto r : replacement_str){
                result_str[j] = r;
                j++;
            }
            i++;

        }else{

            result_str[j] = str[i];
            i++;
            j++;
        }
    }

    return result_str;
}

int main() {

    std::string testString = "Mr John Smith    ";

    // Test Brute Force Solution
    std::cout << "Running Brute Force Solution..." << std::endl;
    std::cout << "Result : " << urlify_bruteForce(testString) << std::endl ;

    // Test Optimal Solution
    std::cout << "Running Optimal Solution..." << std::endl;
    std::cout << "Result : " << urlify_Optimal(testString) << std::endl ;

    return 0;
}