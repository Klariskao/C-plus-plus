#include <iostream>
#include <stdlib.h>   
#include <time.h>

class Hangman
{
private:
    std::string wordList[7] = { "pain", "dog", "horse", "bottle", "trip", "awe", "mind" };
    std::string wordToGuess;
    std::string wordGuessed;
    char letterGuessed;
    int guessesNo = 15;
    
public:

    std::string GetWordToGuess()
    {
        return wordToGuess;
    }

    std::string GetWordGuessed()
    {
        return wordGuessed;
    }

    void Welcome()
    {
        std::cout << "Welcome to Hangman.\n";
        std::cout << "Choose difficulty level.\n";
        std::cout << "Enter 1 for easy.\n";
        std::cout << "Enter 2 for medium.\n";
        std::cout << "Enter 3 for hard.\n";
    }

    void ChooseLevel()
    {
        int level;
        std::cin >> level;
        std::cin.clear();

        switch (level)
        {
        case 1:
            guessesNo = 20;
            break;
        case 2:
            break;
        case 3:
            guessesNo = 10;
            break;
        default:
            std::cout << "Invalid choice.\n";
            std::cout << "Medium level set as default.\n";
        }
    }

    void PickRandomWord()
    {
        srand((unsigned)time(0));
        int randomNo = rand() % 6 + 0;
        wordToGuess = wordList[randomNo];
        wordGuessed = wordToGuess;
    }

    void AssignWordToGuess()
    {
        for (unsigned int i = 0; i < size(wordToGuess); i++)
        {
            wordGuessed[i] = '_';
            std::cout << wordGuessed[i] << " ";
        }

        std::cout << "\nGuess a letter.\n";
        std::cout << "You have " << guessesNo << " guesses left.\n";
    }

    void ValidateLetter()
    {   
        std::string alphabat = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::cin.ignore();
        std::cin >> letterGuessed;
        int letter = 0;
        
        for (unsigned int i = 0; i < size(alphabat); i++)
        {
            if (letterGuessed == alphabat[i])
            {
                letter++;
            }
        }

        if (!letter)
        {
            std::cout << "Invalid guess. ";
            std::cout << "Guess again.\n";
            ValidateLetter();
        }   
    }

    void CheckIfPresent()
    {
        for (unsigned int i = 0; i < size(wordToGuess); i++)
        {
            if (letterGuessed == wordToGuess[i])
            {
                wordGuessed[i] = wordToGuess[i];
            }
        }
    }

    void ReprintAndCount()
    {
        for (unsigned int i = 0; i < size(wordToGuess); i++)
        {
            std::cout << wordGuessed[i] << " ";
        }
        guessesNo--;
        std::cout << "\nYou have " << guessesNo << " guesses left.\n";
    }

    void GuessLoop()
    {
        while (wordGuessed != wordToGuess && guessesNo > 0)
        {
            ValidateLetter();
            CheckIfPresent();
            ReprintAndCount();
        }
    }

    void YouWin()
    {
        std::cout << "\nYou win!";
    }

    void GameOver()
    {
        std::cout << "       ,--- \n";
        std::cout << "       O  | \n";
        std::cout << "      /|\\ | \n";
        std::cout << "      / \\ | \n";
        std::cout << "     _____| \n";
        std::cout << "***Game Over***\n";
    }

};

int main()
{
    Hangman game;
    game.Welcome();
    game.ChooseLevel();
    game.PickRandomWord();
    game.AssignWordToGuess();
    game.GuessLoop();
    
    if (game.GetWordGuessed() == game.GetWordToGuess())
    {
        game.YouWin();
    }
    else
    {
        game.GameOver();
    }
}
