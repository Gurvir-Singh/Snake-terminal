#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <Windows.h>
#include <stdlib.h>


class Grid {
    public:

        std::vector<std::vector<std::string>> grid;
        void setupGrid();
        void printGrid();
        void updateGrid(int x, int y, char newChar);

};
