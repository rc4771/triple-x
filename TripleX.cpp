#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print intro message to the terminal
    std::cout << "\n\nYou're Secret Agent Michael Scarn breaking into a level " << Difficulty << " secret passage under the NHL Stadium...\n";
    std::cout << "You need to enter the correct codes to save the ones held hostage by Goldenface...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " <<  CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n***Correct! You make your way through while Goldenface sweats through his posterior profusely***";
        return true;
    }
    else
    {
        std::cout << "\n***Incorrect! Goldenface rubs it in by bringing up your dead wife. Try again!***";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // loop the game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clears any errors
        std::cin.ignore(); // discards the buffer
        if(bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    
    std::cout << "\n\nYou finally make it to Goldenface and the hostages. You save the hostages and tell Goldenface to go puck himself. Congratulations, now it's time to do the Scarn!\n\n";
     return 0;

}