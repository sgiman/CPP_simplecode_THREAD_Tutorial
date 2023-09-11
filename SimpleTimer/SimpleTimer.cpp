// ***************************************************************************
//  Время выполнения учаcтка кода. SimpleTimer.cpp
// ---------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// ---------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
// ***************************************************************************

#include "iostream"
#include <thread>	

using namespace std;

/*
 *  Время выполнения учаcтка кода
 */


class SimpleTimer
{
public:
	SimpleTimer()	// Конструрктор
	{
		start = std::chrono::high_resolution_clock::now();			// текущее время старта 
	}
	~SimpleTimer()	// Деструктор
	{
		end = std::chrono::high_resolution_clock::now();			// время конца (перед удалением объекта)
		std::chrono::duration<float> duration = end - start;			// продолжительность
		cout << "\n**** Duration: " << duration.count() << "s\n" << endl;
	}

private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;			// типы данных времени - "start", "end"

};


int Sum(int a, int b)
{
	SimpleTimer st;

	this_thread::sleep_for(chrono::milliseconds(2000));

	cout << "ID потока: " << this_thread::get_id() << " =============\tSum STARTED \t=============" << endl;

	this_thread::sleep_for(chrono::milliseconds(5000));

	cout << "ID потока: " << this_thread::get_id() << " =============\tSum STOPED \t=============" << endl;

	return a + b;
}


int main(int argc, char* argv[])
{
	SimpleTimer st;	// создть объект "st" 

	setlocale(LC_CTYPE, "rus");
	cout << "*********** SIMPLE TIMER ***********" << endl;
	cout << endl;

	//auto start = chrono::high_resolution_clock::now();	// возвращает текущую "точку" времени в автопеременной "start" 

	int result;
	thread t([&result]() { result = Sum(2, 5); });		// THREAD/LAMDA - выполние в двух потоках 
	//result = Sum(2, 5);					// выполнение в одном потоке

	//auto start = chrono::high_resolution_clock::now();	// возвращает текущую "точку" времени в автопеременной "start" 
	for (size_t i = 1; i <= 10; i++)
	{
		cout << "ID потока = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	//auto end = chrono::high_resolution_clock::now();	// возвращает конечную "точку" времени в автопеременной "end" 
	//chrono::duration<float> duration = end - start;
	//cout << "\n**** Duration: " << duration.count() << "s\n" << endl;

	t.join();
	cout << "\n Sum Result = " << result << endl;

	cout << endl;
	return 0;
}
