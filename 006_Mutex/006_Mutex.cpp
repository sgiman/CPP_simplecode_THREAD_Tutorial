// **********************************************************************************
// recursive_mutex C++. Рекурсивный мьютекс | Многопоточное программирование C++ #9
// ----------------------------------------------------------------------------------
// Visual Studio 2022 
// ----------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
// **********************************************************************************

#include <iostream>
#include <thread>	
#include <mutex>
#include "SimpleTimer.h"

using namespace std;

/*
*	Многопоточное программирование
*	mutex
*   Защита разделяемых данных синхронизации потока
*
*/

mutex mtx;

// --- Отрисовать прямоугольник принятым символом "ch" ---
void Print(char ch) {

	mtx.lock();		// эта часть используется только одним потоком до "unlock"

	for (int i = 0; i < 5; ++i)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << endl;

	mtx.unlock();
};


int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "rus");
	cout << "*********** MUTEX THREAD ***********\n" << endl;

	//Print('*');
	//Print('#');

	SimpleTimer timer;

	thread t1(Print, '*');		// поток 1
	thread t2(Print, '#');		// поток 2

	t1.join();					// завершить до коцна поток 1 
	t1.join();					// завершить до коцна поток 2

	return 0;
}