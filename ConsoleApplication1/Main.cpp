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
                g->keyBuffer.push('u');
            case 's':
                g->keyBuffer.push('d');
                break;
            case 'a':
                g->keyBuffer.push('l');
                break;
            case 'd':
                g->keyBuffer.push('r');
                break;
            case 72:
                g->keyBuffer.push('u');
                break;
            case 80:
                g->keyBuffer.push('d');
                break;
            case 75:
                g->keyBuffer.push('l');
                break;
            case 77:
                g->keyBuffer.push('r');
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

