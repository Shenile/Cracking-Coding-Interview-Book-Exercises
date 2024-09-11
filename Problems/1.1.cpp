#include <iostream>
#include <string>
#include <algorithm>

bool optimalSolution(std::string test) {
 
    std::sort(test.begin(), test.end());
    
    bool hasDuplicate = false;
    
    
  
    for (size_t i = 1; i < test.length(); ++i) {
        if (test[i - 1] == test[i]) {
            hasDuplicate = true;
            break; 
        }
    }
    
    return hasDuplicate;
}

bool bruteForceSolution(const std::string& test) {
    bool hasDuplicate = false;
    for (size_t i = 0; i < test.length(); ++i) {
        for (size_t j = i + 1; j < test.length(); ++j) {
            if (test[i] == test[j]) {
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
    std::string test = "Vhla";
   
    // Brute Force Method
    std::cout << "Brute force solution result: " << (bruteForceSolution(test) ? "True" : "False") << std::endl;

    // Optimal method Using Sorting
    std::cout << "Optimal solution result: " << (optimalSolution(test) ? "True" : "False") << std::endl;
    
    return 0;
}
