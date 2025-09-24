//    encyclopedia application
//1. include all files that will be needed for application
//2. Create a struct, AnimalInfo, That can store Name, Origin, Life Expectancy, and Weight.
//3. Create a function to print that data out in a neat format. Name it PrintAnimalInfo.
//4. Create a base class for animals. Name it Animal.
//5. Define main
//6. Output the application title
//7. Create a loop where it lists the animals in the encyclopedia and you can visit the page by clicking the number it lists. -1 is to quit program
#include <iostream>
#include <string>
#include <stdexcept>

struct AnimalInfo {
    std::string name;
    std::string origin;
    int lifeExpectancy;
    int weight;
};

void printAnimalInfo(const AnimalInfo& animal) {
    std::cout << "Name: " << animal.name << std::endl;
    std::cout << "Origin: " << animal.origin << std::endl;
    std::cout << "Life Expectancy: " << animal.lifeExpectancy << " years" << std::endl;
    std::cout << "Weight: " << animal.weight << " pounds" << std::endl;
    std::cout << "---------------------------" << std::endl;
}

class Animal {
public:
    Animal(const std::string& name, const std::string& origin, int lifeExpectancy, int weight)
        : m_info{name, origin, lifeExpectancy, weight} {}

    const AnimalInfo& getInfo() const {
        return m_info;
    }

    virtual ~Animal() = default;

private:
    AnimalInfo m_info;
};

class Lion final : public Animal {
public:
    Lion() : Animal("Lion", "Eastern and Southern Africa", 12, 280) {}
};

class Tiger final : public Animal {
public:
    Tiger() : Animal("Tiger", "Indochina", 13, 300) {}
};

class Bear final : public Animal {
public:
    Bear() : Animal("Bear", "Eocene Epoch", 20, 350) {}
};

int main() {
    bool isRunning = true;
    std::string input;
    int choice;

    Lion lion;
    Tiger tiger;
    Bear bear;

    std::cout << " ---Animal Encyclopedia--- " << std::endl;

    while (isRunning) {
        std::cout << "\nChoose an animal for more information:" << std::endl;
        std::cout << "0) Lion" << std::endl;
        std::cout << "1) Tiger" << std::endl;
        std::cout << "2) Bear" << std::endl;
        std::cout << "-1) Quit program" << std::endl;
        std::cout << "Enter choice: ";

        std::getline(std::cin, input);

        try {
            choice = std::stoi(input);
        } catch (const std::invalid_argument&) {
            std::cout << "Invalid input: not a number." << std::endl;
            continue;
        }

        switch (choice) {
            case 0:
                printAnimalInfo(lion.getInfo());
                break;
            case 1:
                printAnimalInfo(tiger.getInfo());
                break;
            case 2:
                printAnimalInfo(bear.getInfo());
                break;
            case -1:
                isRunning = false;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}
