// **************************************************************************
// Потоки с параметрами  | Многопоточное программирование | Уроки  C++ #2
// --------------------------------------------------------------------------
// Visual Studio 2022 
// --------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
// **************************************************************************

#include "iostream"
#include <string>
#include <thread>	
#include <chrono>		 

using namespace std;

/*
 *	Многопоточное программирование
 *	Передача параметров в поток
 */

void DoWork(int a, int b, string msg)
{
	cout << msg << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "==========\t" << "DoWork STARTED\t==========" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "a + b = " << a + b << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "==========\t" << "DoWork STOPPED\t==========" << endl;
}


int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "rus");
	cout << "*********** THREAD PARAMETERS ***********" << endl;
	cout << endl;

	cout << "\n*** START MAIN ****\n" << endl;
	// DoWork(2, 3, "our message");
	thread th(DoWork, 1, 6, "our message");		// Создание потока c параметрами		 
	cout << endl;

	for (size_t i = 0; true; i++)
	{
		cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;	// id текущего потока
		this_thread::sleep_for(chrono::milliseconds(500));	// "усыпить" поток на 0.5 сек. (1000 msec. = 1 sec.)
	}

	th.join();	// Завершение потока

	cout << "\n*** END MAIN ****" << endl;

	cout << endl;
	return 0;
}
