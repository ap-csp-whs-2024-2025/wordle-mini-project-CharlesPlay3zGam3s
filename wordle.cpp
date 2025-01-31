/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string
#include <vector>    // std::vector

// Static secret code for testing
std::vector<int> createSecret() {
    return {1, 9, 0, 8};  // Fixed secret code for testing
}

std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> guess) {
    std::vector<std::string> hint;
    for (size_t i = 0; i < secret.size(); ++i) {
        if (secret[i] == guess[i]) {
            hint.push_back("O");
        } else {
            hint.push_back("X");
        }
    }
    return hint;
}

bool winGame(std::vector<int> secret, std::vector<int> guess) {
    return secret == guess;
}

int main() {
    // No need to seed RNG as we're using a static secret code
    std::vector<int> secret_code = createSecret();
    std::vector<int> user_guess = {-1, -1, -1, -1};
    std::vector<std::string> hint;

    int secret_code_length = 4;
    int num_guesses = 0;

    std::cout << "Welcome to Number Wordle!\n";

    while (!winGame(secret_code, user_guess)) {
        std::cout << "\nEnter your guess (4 numbers): ";
        user_guess.clear();  // Reset the user_guess for the next round
        
        for (int i = 0; i < secret_code_length; ++i) {
            int input;
            std::cin >> input;
            user_guess.push_back(input);
        }

        hint = getHint(secret_code, user_guess);
        display(hint);  // Display the hint
        num_guesses += 1;
    }

    std::cout << "Congrats! You guessed the code! It took you " << num_guesses << " tries.\n";
    return 0;
}
