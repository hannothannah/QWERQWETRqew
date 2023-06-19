#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <windows.h>

#pragma execution_character_set( "utf-8" )

using namespace std;

int rollDice()
{
    return (rand() % 6) + 1;
}

void printDice(int num) {
    std::cout << "┌───────┐" << std::endl;
    switch (num) {
        case 1:
            std::cout << "│       │" << std::endl;
	        std::cout << "│   O   │" << std::endl;
	        std::cout << "│       │" << std::endl;
	        break;
	    case 2:
	        std::cout << "│ O     │" << std::endl;
	        std::cout << "│       │" << std::endl;
	        std::cout << "│     O │" << std::endl;
	        break;
        case 3:
	        std::cout << "│ O     │" << std::endl;
	        std::cout << "│   O   │" << std::endl;
	        std::cout << "│     O │" << std::endl;
	        break;
        case 4:
	        std::cout << "│ O   O │" << std::endl;
	        std::cout << "│       │" << std::endl;
	        std::cout << "│ O   O │" << std::endl;
	        break;
        case 5:
	        std::cout << "│ O   O │" << std::endl;
	        std::cout << "│   O   │" << std::endl;
	        std::cout << "│ O   O │" << std::endl;
	        break;
        case 6:
	        std::cout << "│ O   O │" << std::endl;
	        std::cout << "│ O   O │" << std::endl;
	        std::cout << "│ O   O │" << std::endl;
	        break;
        default:
            std::cout << "│       │" << std::endl;
	        std::cout << "│       │" << std::endl;
	        std::cout << "│       │" << std::endl;
            break;
    }
    std::cout << "└───────┘" << std::endl;
}

int main()
{
	SetConsoleCP(65001); // 
	SetConsoleOutputCP(65001); // 
    srand(time(0)); // Ініціалізуємо генератор випадкових чисел

    int playerScore = 100;
    int totalGames = 0;
    int totalWins = 0;
    int totalLosses = 0;

    std::ofstream outputFile("statistics.txt"); // Файл для збереження статистики

    char playAgain = 'y';
    while (playAgain == 'y')
    {
        int chosenNumber, bet;
        std::cout << "Введіть число від 2 до 12: ";
        std::cin >> chosenNumber;

        if (chosenNumber < 2 || chosenNumber > 12)
        {
            std::cout << "Неправильні дані! Число має бути від 2 до 12. " << std::endl;
            continue;
        }

        std::cout << "Введіть свою ставку: ";
        std::cin >> bet;

        if (bet > playerScore)
        {
            std::cout << "Недостатньо балів! У вас є лише " << playerScore << " балів" << std::endl;
            continue;
        }

        int dice1 = rollDice();
        int dice2 = rollDice();
        int sum = dice1 + dice2;

        printDice(dice1); //
        printDice(dice2); //
        std::cout << "Кубик 1: " << dice1 << std::endl;
        std::cout << "Кубик 2: " << dice2 << std::endl;
        std::cout << "Сума: " << sum << std::endl;

        if ((sum < 7 && chosenNumber < 7) || (sum > 7 && chosenNumber > 7))
        {
            std::cout << "Вітаю! Ви перемогли." << std::endl;
            playerScore += bet;
            if (chosenNumber == sum)
            {
                playerScore += 3 * bet;
            }
            totalWins++;
        }
        else
        {
            std::cout << "Пробачте, але ви програли." << std::endl;
            playerScore -= bet;
            totalLosses++;
        }

        totalGames++;

        std::cout << "Ваш поточний рахунок: " << playerScore << std::endl;
        std::cout << "Грати ще раз? (y/n): ";
        std::cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'n')
        {
            std::cout << "Некоректне введення! Припускаю, що ви відповіли 'n'." << std::endl;
            playAgain = 'n';
        }
    }

    std::cout << "Дякую за гру!" << std::endl;
    std::cout << "Загальна кількість зіграних ігор: " << totalGames << std::endl;
    std::cout << "Загальна кількість перемог: " << totalWins << std::endl;
    std::cout << "Загальна кількість поразок: " << totalLosses << std::endl;

    outputFile << "Загальна кількість зіграних ігор: " << totalGames << std::endl;
    outputFile << "Загальна кількість перемог: " << totalWins << std::endl;
    outputFile << "Загальна кількість поразок: " << totalLosses << std::endl;

    outputFile.close();

    return 0;
}

void printDices(int first, int second) {

}