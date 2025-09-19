#include <iostream>
#include <string>

const char* alphabet[26] 
{ "Alpha", "Beta", "Charlie", "Gamma", "Hover", "Indigo" };

int printarray(const char** begin,const char** end, int& count) {
    if (begin == nullptr || end == nullptr || begin > end) {
        return 0;
    }
    count = 0;
    
    for (const char** ptr = begin; ptr != end; ++ptr) {
        if (*ptr != nullptr){
            std::cout << *ptr << std::endl;
            ++count;
        }
    }
    return 1;
}


int main() {
    int count = 0;
    
    if (printarray(alphabet, alphabet + 5, count)) {
        std::cout << "Printed " << count << " strings successfully.\n";
    } 
    else {
        std::cout << "Error in printarray()\n";
    }
    
    if (printarray(alphabet + 5, alphabet, count)) {
        std::cout << "Printed " << count << " strings successfully.\n";
    } 
    else {
        std::cout << "Error in printarray() due to invalid pointers.\n";
    }

    if (printarray(alphabet, alphabet + 26, count)) {
        std::cout << "Printed " << count << " strings successfully.\n";
    } 
    else {
        std::cout << "Error in printarray()\n";
    }

    return 0;
    
}
