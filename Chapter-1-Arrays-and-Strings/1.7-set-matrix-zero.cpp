/*
   Source: Cracking the Coding Interview by Gayle Laakmann McDowell,
   Chapter Name: Arrays and strings
   Problem Number: 1.7 

   Problem Statement:

   Write an algorithm such that if an element in an MxN matrix is 0, its entire row
   and column are set to 0.

   Solutions Analysis:

   Better Solution:
      Time Complexity: O(rows*cols)
      Space Complexity: O(cols)

   Optimal Solution:
      Time Complexity: O(rows*cols)
      Space Complexity: O(rows+cols),
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

void setMatrixZero_optimal(int** arr, int rows, int cols){
    bool* rowZeros = new bool[rows]{false};
    bool* colZeros = new bool[cols]{false};

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            
            if(arr[i][j] == 0){
               rowZeros[i] = true;
               colZeros[j] = true;
            }
            
        }
    }

    for (int i = 0; i < rows; ++i) {

        if(rowZeros[i] ){
           for (int j = 0; j < cols; ++j) {
          
             arr[i][j] = 0;
           }
        }
        
    }

    for (int i = 0; i < cols; ++i) {

        if(colZeros[i] ){
           for (int j = 0; j < rows; ++j) {
             // Your code here
             arr[j][i] = 0;
           }
        }
        
    }

    delete[] rowZeros;
    delete[] colZeros;
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

    arr[1][1] = 0;
    
    printMultiDimensionalArray(arr, rows, cols);
    std::cout << "-----------------------------------" << std::endl;
    setMatrixZero_optimal(arr, rows, cols);
    printMultiDimensionalArray(arr, rows, cols);
   

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}