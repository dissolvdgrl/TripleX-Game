#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breakig into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;    

    // Print CodeSum and CodeProduct to terminal
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code" ;
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The product of the 3 numbers are: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;

    // Store player guess
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = CodeA * CodeB * CodeC;

    // Check if player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou're in! Keep going...";
        return true;
    }
    else
    {
        std::cout << "\nYou entered the incorrect code, try again.";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // create a new random sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // loop the game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }        
    }
    std::cout << "\n*** GREAT WORK, AGENT! You got all the files. Now get out of here before they notice anything! ***\n";    
    return 0;
}