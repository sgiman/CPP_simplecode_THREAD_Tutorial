// ***********************************************************************************************
// С++ потоки и методы класса. С++ метод класса в потоке | Многопоточное программирование C++ #5
// -----------------------------------------------------------------------------------------------
// Visual Studio 2022
// -----------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
// ***********************************************************************************************

#include "iostream"
#include <string>
#include <thread>	
#include <chrono>		 

using namespace std;

/*
*	многопоточное программирование
*	запуск класса в отдельном потоке
*
*/

class MyClass
{

public:

	int DoWork()
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ID потока = " << this_thread::get_id() << "\n\n========== DoWork STARTED ==========\n" << endl;
		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "ID потока = " << this_thread::get_id() << "\n\n========== DoWork STOPPED ==========\n" << endl;
		return 0;
	}

	int DoWork2(int a)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ID потока = " << this_thread::get_id() << "\n\n========== DoWork2 STARTED ==========\n" << endl;

		cout << " --- DoWork2 значение параметра A = " << a << " ---" << endl;

		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "ID потока = " << this_thread::get_id() << "\n\n========== DoWork2 STOPPED ==========\n" << endl;
		return a;
	}

	int Sum(int a, int b)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ID потока = " << this_thread::get_id() << "\n\n========== Sum STARTED ==========\n" << endl;
		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "ID потока = " << this_thread::get_id() << "\n\n========== Sum STOPPED ==========\n" << endl;
		return a + b;
	}

};


int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "rus");
	cout << "*********** METHOD CLASS THREAD ***********" << endl;
	cout << endl;
	cout << "\n*** START MAIN ****\n" << endl;


	MyClass m;

	//thread t(&MyClass::DoWork, m);
	//thread t(&MyClass::DoWork2, m, 5);
	thread t([&]() { m.DoWork2(5); });			// with LAMBDA

	/*
	int result;
	thread t([&]() { result = m.Sum(2, 5); });	// with LAMBDA
	*/

	for (size_t i = 1; i < 10; i++)
	{
		cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;		// id текущего потока
		this_thread::sleep_for(chrono::milliseconds(500));								// "усыпить" поток на 0.5 сек. (1000 msec. = 1 sec.)
	}

	cout << "\n*** END MAIN ****" << endl;

	t.join();	// дождатьсЯ завершения потока

	//cout << "\nRESULT SUM = " << result << endl;


	cout << endl;
	return 0;
}