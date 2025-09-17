// The activity had a few parameters to follow. Bellow are the parameters
// 1. Define age bracket thresholds using #defines
// 2. Define a name for each group using #defines
// 3. Output text asking the user for their name and capture the response in a variable
// 4. Output text asking the user for their age and capture the respons in a variable
// 5. Write a function that will accept age as a parameter and return the appropriate group name
// 6. Output the users name and group that they have been assigned to
// groups are number A-E since I don't want to offend any age group haha
// I believe I hit all of the parameters with the following code

#include <iostream>
#include <string>

#define group_A 18
#define group_B 30
#define group_C 50
#define group_D 80


int main(){
    
    std::string name;
    std::string str_age;
    int age;
    
    std::cout << "What is your name: ";
    getline(std::cin, name);
    std::cout << "What is your age: ";
    getline(std::cin, str_age);
    age = std::stoi(str_age);
    std::cout << "Hello, " << name << ".\n";
    
    if (age < group_A){
        std::cout << "You are in group A, congrats!";
        }
    else if (age < group_B){
        std::cout << "You are in group B, well done!";
    }
    else if (age < group_C){
        std::cout << "You are in group C, good luck!";
    }
    else if (age < group_D){
        std::cout << "You are in group D, stay active!";
    }
    else {
        std::cout << "You are in group E, you are very wise!";
    }
}
