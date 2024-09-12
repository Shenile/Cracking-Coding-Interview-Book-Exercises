/*
   Source: Cracking the Coding Interview by Gayle Laakmann McDowell,
   Chapter Name: Arrays and Strings
   Problem Number: 1.6

   Problem Statement:

   Given an image represented by an NxN matrix, where each pixel in the image is
   4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
   place? 

   Solutions Analysis:

    Time Complexity: O(n^2),
    Space Complexity: O(1),
*/

#include <iostream>
#include <algorithm>

void reverse(int** arr, int rows, int cols){
     int i = 0, j = cols-1;
     while(i < j){
         std::swap(arr[rows][i], arr[rows][j]);
         i++;
         j--;
     }
}

void RotateArray(int** arr, int rows, int cols) {

    for(int i =0 ; i < rows; i++){
        for(int j = i; j < cols; j++){
           
            std::swap(arr[i][j], arr[j][i]);
        }
    }

    reverse(arr, 0, 3);
    reverse(arr, 1, 3);
    reverse(arr, 2, 3);

}

void print2dArray(int** arr, int rows, int cols){

     for(int i =0 ; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout<< std::endl;
     }
}


int main() {
    int rows = 3, cols = 3;
    
    //creating dynamic array..
    int** arr = new int*[rows];
    for(int i=0; i < rows; ++i){
        arr[i] = new int [cols];
    }
    
    int count = 1;
    for(int i =0 ; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arr[i][j] = count++;
        }
    }

    std::cout << "Array Before rotation :" << std::endl;
    print2dArray(arr, rows, cols);

    RotateArray(arr, rows, cols);

    std::cout << "Array after rotation by 90 degree :" << std::endl;
    print2dArray(arr, rows, cols);
    

    

    return 0;
}