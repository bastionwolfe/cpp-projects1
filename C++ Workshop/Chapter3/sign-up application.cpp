// Sign-up application ch. 3
// 1. start by including the headers needed
// 2. Next, define the class that will represent a record in the system. This is going to be a person, containing both a name and an age. 
//   Also, declare a vector of this type to store these records. A vector is used for the flexibility it gives in not having to declare an array size upfront.
// 3. write a function that accept two parameters of age and name. make it add it to the reccord vector. name it add record
// 4, add a function to fetch a record. This functino should accept only a userID and return said user. Name it Fetch Record
// 5. enter the main function have an outer main loop and give three options.
// The try catch isn't something the book has gone over but was provided for this example in the book.
// The rest of the points are hints on how to do so. cutting them to avoid clutter.

#include <iostream>
#include <vector>
#include <string>

std::string input;

void str2int (std::string& x ,int& y) {
    getline(std::cin, x);
    y = std::stoi(x);
}


// self-note: blueprint for a vector
struct person {
    std::string name;
    int age;
};

std::vector<person> users;


void addRecord () {
    person newperson;
    std::cout << "Please enter the new user's name: ";
    getline (std::cin, newperson.name);
    std::cout << "Please enter the new user's age: ";
    str2int (input, newperson.age);
    users.push_back(newperson);
    std::cout << "Your user ID is: " << users.size() - 1 << std::endl;
}

void fetchRecord () {
    int ID;
    std::cout << "Please enter the user's ID: ";
    str2int (input, ID);
    std::cout << "The User's name is: " << users[ID].name << "\n";
    std::cout << "The User's age is: " << users[ID].age << "\n";
}

int main () {
    int userChoice;
    bool isrunning = true;
    std::cout << "Hello and welcoem to privacy-plus corperations internal and top-secret user ID system.\n";
    while (isrunning == true) {
        std::cout << "please choose one of the following options by entering the assocaited number.\n";
        std::cout << "1. Add a new user. \n";
        std::cout << "2. Look up an existing user. \n";
        std::cout << "3. Exit this program. \n";
        str2int (input, userChoice);
        switch (userChoice) {
            case 1: {
                addRecord ();
                break;
            }
            case 2: {
                try 
                {
                fetchRecord ();
                }
                catch (const std::out_of_range& oor)
                {
                std::cout << "\nError: Invalid UserID.\n\n";
                }
                break;
            }
            case 3: {
                std::cout <<"quitting current program" << std::endl;
                isrunning = false;
                break;
            }
            default: {
                std::cout << "input not recognized, Please try again. \n";
            }
        }
    }   
}
