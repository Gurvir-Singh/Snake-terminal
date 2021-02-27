#include "Game.h"
#include <pthread.h>



void Game::PlayGame() {
     
    //void(*getKeyPtr);
    //getKeyPtr = &this->GetKey;
    
    Grid playGrid = Grid();
    playGrid.setupGrid();
    int snakePosX = 20;
    int snakePosY = 10;
    int snakeLength = 1;
    std::random_device generator;
    std::uniform_int_distribution<int> distributionX(1, 38);
    std::uniform_int_distribution<int> distributionY(1, 18);
    int applePosX = 1;
    int applePosY = 1;
    do {
        applePosX = distributionX(generator);
    } while (applePosX == snakePosX);
    do {
        applePosY = distributionY(generator);
    } while (applePosY == snakePosY);
    playGrid.updateGrid(applePosX, applePosY, '0');

    std::vector<std::vector<int>> positionsDrawnOver = std::vector<std::vector<int>>();


    char direction = 'u';
    char lastFramesDirection = 'u';
    
    unsigned long framesToPlay = 0;
    
    while (gameRunning) {
        //std::this_thread::sleep_for(std::chrono::milliseconds(100));

        if (!keyBuffer.empty()) {
            direction = keyBuffer.front();
            keyBuffer.pop();
        }
        if (lastFramesDirection == 'u' && direction == 'd') {
            direction = lastFramesDirection;
        }
        else if (lastFramesDirection == 'd' && direction == 'u') {
            direction = lastFramesDirection;
        }
        else if (lastFramesDirection == 'l' && direction == 'r') {
            direction = lastFramesDirection;
        }
        else if (lastFramesDirection == 'r' && direction == 'l') {
            direction = lastFramesDirection;
        }
        
            if (direction == 'u') {
                snakePosY--;
            }
            else if (direction == 'd') {
                snakePosY++;
            }
            else if (direction == 'r') {
                snakePosX++;
            }
            else if (direction == 'l') {
                snakePosX--;
            }
            lastFramesDirection = direction;
            if (playGrid.grid.at(snakePosY).at(snakePosX) == "X" || playGrid.grid.at(snakePosY).at(snakePosX) == "#") {
                gameRunning = false;
            }
            else {
                if (playGrid.grid.at(snakePosY).at(snakePosX) == "0") {
                    do {
                        applePosX = distributionX(generator);
                    } while (applePosX == snakePosX);
                    do {
                        applePosY = distributionY(generator);
                    } while (applePosY == snakePosY);
                    playGrid.updateGrid(applePosX, applePosY, '0');
                    snakeLength++;
                    for (std::vector<int>& arr : positionsDrawnOver) {
                        arr.at(2)++;
                    }
                }
                playGrid.updateGrid(snakePosX, snakePosY, 'O');
                std::vector<int> posWritingOver = { snakePosX, snakePosY, snakeLength };
                positionsDrawnOver.push_back(posWritingOver);
            }
            if (positionsDrawnOver.size() != 0) {
                for (std::vector<int>& arr : positionsDrawnOver) {
                    if (arr != positionsDrawnOver.at(positionsDrawnOver.size() - 1)) {
                        playGrid.updateGrid(arr.at(0), arr.at(1), '#');
                    }
                    arr.at(2)--;
                }
                if (positionsDrawnOver.at(0).at(2) < 0 && playGrid.grid.at(positionsDrawnOver.at(0).at(1)).at(positionsDrawnOver.at(0).at(0)) != "O") {
                    playGrid.updateGrid(positionsDrawnOver.at(0).at(0), positionsDrawnOver.at(0).at(1), '.');
                    positionsDrawnOver.erase(positionsDrawnOver.begin());
                }
            }
        
        //system("CLS");
        //if (framesToPlay % 100000) {
            playGrid.printGrid();
        //}
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        //framesToPlay++;
        
        

    }
    gameRunning = false;
}

