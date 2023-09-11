#pragma once

#include <iostream>
#include <thread>	

using namespace std;

class SimpleTimer
{
public:
	
	SimpleTimer()	// Конструрктор
	{
		start = std::chrono::high_resolution_clock::now();					// текущее время старта 
	}
	
	~SimpleTimer()	// Деструктор
	{
		end = std::chrono::high_resolution_clock::now();					// время конца (перед удалением объекта)
		std::chrono::duration<float> duration = end - start;				// продолжительность
		cout << "\n**** Duration: " << duration.count() << "s\n" << endl;
	}

private:
	
	std::chrono::time_point<std::chrono::steady_clock> start, end;			// типы данных времени - "start", "end"

};
