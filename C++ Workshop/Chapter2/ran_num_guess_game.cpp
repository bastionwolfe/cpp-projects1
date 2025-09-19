// Creating a number guessing game using loops and conditional statements
// 1. Delcare all the variables needed. This includes guesscount, minNumber, maxNumber, and randomNumber
// 2. create the main outer loop that will run the application
// 3. present the user with some introductory texts and get from them the following: number of guesses, min number, and max num
// 4. Generate a random number within the range given by the user
// 5. Create a loop that will iterate the number of times that the user specified their guess count
// 6. Inside the count loop, fetch the user's guess
// 7. Inside the count loop, check whether the user's guess is correct or too high/low.
//    Break here when the correct value is guessed
// 8. When the number has been found or if the user is out of guesses, oresent them the option to quit or continue

#include <iostream>
#include <string>
#include <cstdlib>




int main() {
    bool isRunning = true;
    
    
    while (isRunning){
        int count = 0;
        int userGuess;
        int guessCount;
        int minNumber;
        int maxNumber;
        int randomNumber;
        int choice;
        
        std::string input;
        std::cout << "Welcome to the Random Number Guessing Game!" << "\n";
        std::cout << "Would you like to play?" << "\n";
        std::cout << " Please type either 1 or 2 to choose." << "\n";
        std::cout << "1. yes" << "\n";
        std::cout << "2. no" << "\n";
        getline(std::cin, input);
        choice = std::stoi(input);
        switch (choice){
            case 1:
                std::cout << "Please enter the amount of guesses you want: ";
                getline(std::cin, input);
                guessCount = std::stoi(input);
                std::cout << "Please enter the smallest number that it could be: ";
                getline(std::cin, input);
                minNumber = std::stoi(input);
                std::cout << "Please enter the highest number that it could be: ";
                getline(std::cin, input);
                maxNumber = std::stoi(input);
                randomNumber = minNumber + (rand() % (maxNumber - minNumber + 1));
                do {
                    std::cout << "Please enter your guess: " << "\n";
                    getline(std::cin, input);
                    userGuess = std::stoi(input);
                    ++count;
                    if (userGuess > randomNumber) {
                        std::cout << "Your guess is higher than the chosen number" << "\n";
                    }
                    else if (userGuess < randomNumber) {
                        std::cout << "Your guess is smaller than the chosen number" << "\n";
                    }
                    else {
                        continue;
                    } 
                } while (userGuess != randomNumber && count != guessCount);
                if (userGuess == randomNumber) {
                    std::cout << "Congratulations! You won the game!" << "\n";
                    continue;
                }
                else {
                    std::cout << "You didn't get the number in time, better luck next time!" << "\n";
                }
                
                break;
            case 2:
                isRunning = false;
                break;
            default:
                break;
        }
            
    }
    
}
