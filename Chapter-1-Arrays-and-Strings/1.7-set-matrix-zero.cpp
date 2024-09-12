/*
   Source: Cracking the Coding Interview by Gayle Laakmann McDowell,
   Chapter Name: 
   Problem Number: 

   Problem Statement:
   

   Solutions Analysis:

   Brute Force Solution:
      Time Complexity: 
      Space Complexity: 

   Optimal Solution:
      Time Complexity: 
      Space Complexity: ,
*/

#include <iostream>
#include <unordered_map>

void printMultiDimensionalArray(int** arr, int rows, int cols){
     for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " " ;
        }
        std::cout << std::endl;
    }
}


void setMatrixZero_betterSolution(int** arr, int rows, int cols){
     
     std::unordered_map<int, bool> map;
     
     for (size_t i = 0; i < cols; i++)
     {
        map[i] = false;
     }
     
     bool isColumnZero = false;
     for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            
            if(arr[i][j] == 0){
                if(!map[j]){
                  
                  for (size_t i = 0; i < rows; i++)
                  {
                    arr[i][j] = 0;
                  }
                  map[j] = true; 
                }
            }
        }
     }
}

int main() {
    int rows = 3, cols =3;

    //Dynamic 2d array
    int** arr = new int*[rows];
    for(int i = 0; i < rows; i++){
        arr[i] = new int[cols];
    }
    
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
             arr[i][j] = count++;
        }
    }

    arr[2][2] = 0;
    
    printMultiDimensionalArray(arr, rows, cols);
    setMatrixZero_betterSolution(arr, rows, cols);
    printMultiDimensionalArray(arr, rows, cols);
   

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}