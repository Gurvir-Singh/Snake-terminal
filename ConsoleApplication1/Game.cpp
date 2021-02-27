#include "Game.h"


void Game::GetKey() {
    while (gameRunning) {
        if (_kbhit != 0) {
            char keyPressed = _getch();
            switch (keyPressed) {
                case 'w':
                    keyBuffer.push_back('u');
                    break;
                case 's':
                    keyBuffer.push_back('d');
                    break;
                case 'a':
                    keyBuffer.push_back('l');
                    break;
                case 'd':
                    keyBuffer.push_back('r');
                    break;
            }
            if (keyPressed == 0 || keyPressed == 224) {
                switch (_getch()) {
                    case 72:
                        keyBuffer.push_back('u');
                        break;
                    case 80:
                        keyBuffer.push_back('d');
                        break;
                    case 75:
                        keyBuffer.push_back('l');
                        break;
                    case 77:
                        keyBuffer.push_back('r');
                        break;
                }
            }

        }

    }
}

void Game::PlayGame() {
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
    if (_kbhit()) {
        char keyPressed = _getch();
        switch (keyPressed) {
        case 'w':
            if (direction != 'd') {
                direction = 'u';
            }
            break;
        case 's':
            if (direction != 'u') {
                direction = 'd';
            }
            break;
        case 'a':
            if (direction != 'r') {
                direction = 'l';
            }
            break;
        case 'd':
            if (direction != 'l') {
                direction = 'r';
            }
            break;
        case 72:
            if (direction != 'd') {
                direction = 'u';
            }
            break;
        case 80:
            if (direction != 'u') {
                direction = 'd';
            }
            break;
        case 75:
            if (direction != 'r') {
                direction = 'l';
            }
            break;
        case 77:
            if (direction != 'l') {
                direction = 'r';
            }
            break;
        }
    }
    unsigned long framesToPlay = 0;
    
    while (gameRunning) {
        //std::this_thread::sleep_for(std::chrono::milliseconds(100));

        if (_kbhit()) {
            char keyPressed = _getch();
            switch (keyPressed) {
            case 'w':
                if (direction != 'd') {
                    direction = 'u';
                }
                break;
            case 's':
                if (direction != 'u') {
                    direction = 'd';
                }
                break;
            case 'a':
                if (direction != 'r') {
                    direction = 'l';
                }
                break;
            case 'd':
                if (direction != 'l') {
                    direction = 'r';
                }
                break;
            case 72:
                if (direction != 'd') {
                    direction = 'u';
                }
                break;
            case 80:
                if (direction != 'u') {
                    direction = 'd';
                }
                break;
            case 75:
                if (direction != 'r') {
                    direction = 'l';
                }
                break;
            case 77:
                if (direction != 'l') {
                    direction = 'r';
                }
                break;
            }
        }
        if (framesToPlay % 10 == 0) {
            if (direction == 'u') {
                if (lastFramesDirection != 'd') {
                    snakePosY--;
                }
            }
            else if (direction == 'd') {
                if (lastFramesDirection != 'u') {
                    snakePosY++;
                }
            }
            else if (direction == 'r') {
                if (lastFramesDirection != 'l') {
                    snakePosX++;
                }
            }
            else if (direction == 'l') {
                if (lastFramesDirection != 'r') {
                    snakePosX--;
                }
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
        }
        //system("CLS");
        //if (framesToPlay % 100000) {
            playGrid.printGrid();
        //}
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        //framesToPlay++;
        
        

    }
    gameRunning = false;
}

