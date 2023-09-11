// *****************************************************************************************
// Возврат результата из потока по ссылке | Многопоточное программирование | Уроки C++ #3
// -----------------------------------------------------------------------------------------
// Visual Studio 2022
// -----------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
// *****************************************************************************************

#include "iostream"
#include <string>
#include <thread>	
#include <chrono>		 

using namespace std;

/*
 *	Многопоточное программирование
 *	Получение результата работы функции из потока
 */

void DoWork(int& a)			// Передача паметров по ссылке
{

	this_thread::sleep_for(chrono::milliseconds(2000));

	cout << "\n========== DoWork STARTED ==========" << endl;

	this_thread::sleep_for(chrono::milliseconds(5000));

	a = a * 2;

	cout << "ID потока = " << this_thread::get_id() << "\n========== DoWork STOPPED ==========\n" << endl;

}


int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "rus");
	cout << "*********** THREAD RETURN ***********" << endl;
	cout << endl;

	cout << "\n*** START MAIN ****\n" << endl;

	int q = 5;

	thread t(DoWork, std::ref(q));

	cout << endl;

	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;	// id текущего потока
		this_thread::sleep_for(chrono::milliseconds(500));	// "усыпить" поток на 0.5 сек. (1000 msec. = 1 sec.)
	}

	cout << "\n*** END MAIN ****" << endl;

	t.join();
	cout << "Q = " << q << endl;

	cout << endl;
	return 0;
}
