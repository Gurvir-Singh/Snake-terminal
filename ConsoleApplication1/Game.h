#pragma once
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <Windows.h>
#include "Grid.h"
#include <conio.h>
#include <random>
class Game
{
	public:
		std::thread* keyReader;
		bool gameRunning = true;
		std::vector<char> keyBuffer = {'u'};
		void GetKey();
		void PlayGame();
		void startKeyReader();
		Game() {
			
		}
		~Game() {
			keyReader->join();
			delete keyReader;
		}
};

