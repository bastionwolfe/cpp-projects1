//    ---FIZZBUZZ application---
// 1. add headers needed
// 2. print fizz for multiples of 3 and buzz for multiples of 5
//    If it is a multiple of both 3 and 5, print fizzbuzz instead
// 3. make it out of 100. Add a comma after every entry unless it is the last one.

#include <iostream>
#include <string>

int main() {
    for (int i = 1; i <= 100; ++i) {
        bool multiples = false;
        if (i % 3 == 0) {
            multiples = true;
            std::cout << "FIZZ";
        }
        if (i % 5 == 0) {
            multiples = true;
            std::cout << "BUZZ";
        }
        if (!multiples) {
            std::cout << i;
        }
        if ( i < 100) {
            std::cout << ", ";
        }
    }
}
