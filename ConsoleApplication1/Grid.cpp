#include "Grid.h"
#include <curses.h>
void Grid::printGrid() {
    //std::cout << std::endl;
    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    clear();
    bool screenHasColor = has_colors();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_BLACK);
    for (int i = 0; i < grid.size(); i++)
    {
        
        for (int j = 0; j < grid.at(i).size(); j++) {
            if (grid.at(i).at(j) == "X") {
                
                attron(COLOR_PAIR(1));
                printw(grid.at(i).at(j).c_str());
                attroff(COLOR_PAIR(1));
            }
            else if (grid.at(i).at(j) == "0") {
                
                attron(COLOR_PAIR(2));
                printw(grid.at(i).at(j).c_str());
                attroff(COLOR_PAIR(2));
            }
            else if (grid.at(i).at(j) == "O" || grid.at(i).at(j) == "#") {
                
                attron(COLOR_PAIR(3));
                printw(grid.at(i).at(j).c_str());
                attroff(COLOR_PAIR(3));
            }
            else {
                
                attron(COLOR_PAIR(4));
                printw(grid.at(i).at(j).c_str());
                attroff(COLOR_PAIR(4));
            }
            

            
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