// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include "Game.h"
#include <curses.h>

void GetKey(Game* g) {
    while (g->gameRunning) {
        if (_kbhit()) {
            char keyPressed = _getch();
            switch (keyPressed) {
            case 'w':
                if (g->keyBuffer.size() == 0 || (g->keyBuffer.back() != 'u' && g->keyBuffer.size() <= 3)) {
                    g->keyBuffer.push('u');
                }
                break;
            case 's':
                if (g->keyBuffer.size() == 0 || (g->keyBuffer.back() != 'd' && g->keyBuffer.size() <= 3)) {
                    g->keyBuffer.push('d');
                }
                break;
            case 'a':
                if (g->keyBuffer.size() == 0 || (g->keyBuffer.back() != 'l' && g->keyBuffer.size() <= 3)) {
                    g->keyBuffer.push('l');
                }
                break;
            case 'd':
                if(g->keyBuffer.size() == 0 || (g->keyBuffer.back() != 'r' && g->keyBuffer.size() <= 3)) {
                    g->keyBuffer.push('r');
                }
                break;
            //up
            case 72:
                if (g->keyBuffer.size() == 0 || (g->keyBuffer.back() != 'u' && g->keyBuffer.size() <= 3)) {
                    g->keyBuffer.push('u');
                }
                break;
            //down
            case 80:
                if (g->keyBuffer.size() == 0 || (g->keyBuffer.back() != 'd' && g->keyBuffer.size() <= 3)) {
                    g->keyBuffer.push('d');
                }
                break;
            //left
            case 75:
                if (g->keyBuffer.size() == 0 || (g->keyBuffer.back() != 'l' && g->keyBuffer.size() <= 3)) {
                    g->keyBuffer.push('l');
                }
                break;
            //right
            case 77:
                if (g->keyBuffer.size() == 0 || (g->keyBuffer.back() != 'r' && g->keyBuffer.size() <= 3)) {
                    g->keyBuffer.push('r');
                }
                break;
            }
        }
    }
}

int main()
{
    initscr();
    Game* game = new Game();
    std::thread th(GetKey, game);
    game->PlayGame();
    th.join();
    endwin();
    
}

