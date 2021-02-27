#include "Grid.h"
#include <curses.h>
void Grid::printGrid() {
    //std::cout << std::endl;
    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    clear();
    for (int i = 0; i < grid.size(); i++)
    {
        
        for (int j = 0; j < grid.at(i).size(); j++) {
            if (grid.at(i).at(j) == "X") {
                //SetConsoleTextAttribute(hConsole, );
                //system("Color 7");
            }
            else if (grid.at(i).at(j) == "0") {
                //SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                //system("Color 4");
            }
            else if (grid.at(i).at(j) == "O" || grid.at(i).at(j) == "#") {
                //SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                //system("Color 2");
            }
            else {
                //SetConsoleTextAttribute(hConsole, 30);
                //system("Color 0");
            }
            printw(grid.at(i).at(j).c_str());
            if (j != grid.at(i).size()) {
                addch(' ');
            }
            
        }
        if (i != grid.size() - 1) {
            addch('\n');
        }
        
    }
    refresh();
}

void Grid::setupGrid() {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions
    MoveWindow(console, r.left, r.top, 610, 364, TRUE);
    
    std::string charachterForGrid = ".";
    std::vector<std::string> gridBoundry;
    for (int i = 0; i < 40; i++) {
        gridBoundry.push_back("X");
    }
    grid.push_back(gridBoundry);
    std::vector<std::string> gridLine = { "X", charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, charachterForGrid, "X" };
    for (int i = 0; i < 18; i++) {
        grid.push_back(gridLine);
    }
    grid.push_back(gridBoundry);
}
void Grid::updateGrid(int x, int y, char newChar) {
    std::string newStr(1, newChar);
    grid.at(y).at(x).assign(newStr);
}