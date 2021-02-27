// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include "Game.h"
#include <curses.h>

int main()
{
    initscr();
    Game* game = new Game();
    game->PlayGame();
    endwin();
    
}

