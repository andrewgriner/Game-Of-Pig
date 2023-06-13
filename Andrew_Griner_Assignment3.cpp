#include <iostream>
#include <random>

// Function to roll a dice and get a random number between 1 and 6
int rollDice() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    return dis(gen);
}

// Function for human's turn
int humanTurn(int humanTotalScore) {
    int turnTotal = 0;
    std::cout << "It's your turn! Enter 'r' to roll." << std::endl;
    std::string action;
    std::cin >> action;
    bool ended = false;

    // Continue rolling as long as the player chooses to roll ('r')
    while (!ended && action == "r") {
        int roll = rollDice();
        if (roll == 1) {
            std::cout << "You rolled a 1. Your turn ends with no points." << std::endl;
            ended = true;
        }
        else {
            turnTotal += roll;
            std::cout << "You rolled: " << roll << std::endl;
            std::cout << "Your score this round is: " << turnTotal << std::endl;
            std::cout << "If you hold, your total score would be: " << humanTotalScore + turnTotal << std::endl;
            std::cout << "Press 'h' to hold or 'r' to roll again." << std::endl;
            std::cin >> action;
        }
    }

    // Return 0 if the turn ended with rolling a 1, otherwise return the turn total
    if (ended) {
        return 0;
    }
    return turnTotal;
}

// Function for computer's turn
int computerTurn(int computerTotalScore) {
    int turnTotal = 0;
    std::cout << "It's the computer's turn!" << std::endl;
    bool ended = false;

    // Continue rolling until the turn total reaches 20 or a 1 is rolled
    while (true) {
        int roll = rollDice();
        if (roll == 1) {
            std::cout << "The computer rolled 1. The computer loses its turn. Enter 'c' to continue." << std::endl;
            ended = true;
            break;
        }
        else {
            turnTotal += roll;
            std::cout << "The computer rolled: " << roll << std::endl;
            std::cout << "The computer's score this round is: " << turnTotal << std::endl;
            std::cout << "If the computer holds, its total score would be: " << computerTotalScore + turnTotal << std::endl;

            // If the turn total reaches 20 or more, the computer holds
            if (turnTotal >= 20) {
                std::cout << "The computer holds. Enter 'c' to continue." << std::endl;
                break;
            }
        }
    }

    // Return 0 if the turn ended with rolling a 1, otherwise return the turn total
    if (ended) {
        return 0;
    }
    return turnTotal;
}

// Function to play the game
void playGame() {
    int humanTotalScore = 0;
    int computerTotalScore = 0;

    while (true) {
        std::cout << "----- Human's Turn -----" << std::endl;
        std::cout << "Human's total score: " << humanTotalScore << std::endl;

        // Execute human's turn and get the turn score
        int humanTurnScore = humanTurn(humanTotalScore);

        // If the turn score is 0, the player rolled a 1 and no points are added
        if (humanTurnScore == 0) {
            // The message for rolling a 1 is already printed in the 'humanTurn' function
        }
        else {
            humanTotalScore += humanTurnScore;
            std::cout << "You scored " << humanTurnScore << " points this turn." << std::endl;
            std::cout << "Your total score is now " << humanTotalScore << std::endl;
        }

        // Check if the human's total score reaches 100 or more to win the game
        if (humanTotalScore >= 100) {
            std::cout << "Congratulations! You win!" << std::endl;
            break;
        }

        std::cout << "\n----- Computer's Turn -----" << std::endl;
        std::cout << "Computer's total score: " << computerTotalScore << std::endl;

        // Execute computer's turn and get the turn score
        int computerTurnScore = computerTurn(computerTotalScore);

        // If the turn score is 0, the computer rolled a 1 and no points are added
        if (computerTurnScore == 0) {
            // The message for rolling a 1 is already printed in the 'computerTurn' function
        }
        else {
            computerTotalScore += computerTurnScore;
            std::cout << "Computer scored " << computerTurnScore << " points this turn." << std::endl;
            std::cout << "Computer's total score is now " << computerTotalScore << std::endl;
        }

        // Check if the computer's total score reaches 100 or more to win the game
        if (computerTotalScore >= 100) {
            std::cout << "Sorry, the computer wins." << std::endl;
            break;
        }

        std::cout << "Press 'y' to continue or 'n' to exit: ";
        std::string choice;
        std::cin >> choice;

        // If the player chooses to exit, end the game
        if (choice == "n") {
            break;
        }
    }
}

// Main function
int main() {
    playGame();
    return 0;
}
