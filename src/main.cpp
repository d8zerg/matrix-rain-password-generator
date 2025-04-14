#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

constexpr int WIDTH = 80;
constexpr int HEIGHT = 20;

constexpr auto GREEN_TEXT = "\033[32m";
constexpr auto RESET_TEXT = "\033[0m";

void clearScreen() 
{
    std::cout << "\033[2J\033[1;1H";
}

void setConsoleColor() 
{
    std::cout << GREEN_TEXT;
}

void resetConsoleColor() 
{
    std::cout << RESET_TEXT;
}

int main() {
    std::srand(std::time(nullptr));
    std::vector<std::vector<char>> screen(HEIGHT, std::vector<char>(WIDTH, ' '));
    std::vector<int> columnPositions(WIDTH, -1);
    setConsoleColor(); 
    while (true) 
    {
        clearScreen();
        for (int x = 0; x < WIDTH; ++x) {
            if (columnPositions[x] == -1 && std::rand() % 10 == 0) 
            {
                columnPositions[x] = 0;
            }
            
            if (columnPositions[x] != -1) 
            {
                if (columnPositions[x] < HEIGHT) 
                {
                    screen[columnPositions[x]][x] = static_cast<char>(33 + std::rand() % 94); // Random ASCII char
                }

                if (columnPositions[x] > 0) 
                {
                    screen[columnPositions[x] - 1][x] = ' ';
                }

                columnPositions[x]++;

                if (columnPositions[x] >= HEIGHT) {
                    columnPositions[x] = -1;
                }
            }
        }

        for (const auto& row : screen) {
            for (const auto& ch : row) {
                std::cout << ch;
            }
            std::cout << "\n";
        }

        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    resetConsoleColor(); 
    return 0;
}