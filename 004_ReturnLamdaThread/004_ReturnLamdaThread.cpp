// *************************************************************************************************
// Лямбда выражения и возврат результата выполнения потока | Многопоточное программирование C++ #4
// -------------------------------------------------------------------------------------------------
// Visual Studio 2022
// -------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
// *************************************************************************************************

#include "iostream"
#include <string>
#include <thread>	
#include <chrono>		 

using namespace std;

/*
 *	Многопоточное программирование
 *	Получение результата работы функции из потока
 */

int Sum(int a, int b)
{

	this_thread::sleep_for(chrono::milliseconds(2000));

	cout << "ID потока = " << this_thread::get_id() << "\n\n========== DoWork STARTED ==========\n" << endl;

	this_thread::sleep_for(chrono::milliseconds(5000));

	cout << "ID потока = " << this_thread::get_id() << "\n\n========== DoWork STOPPED ==========\n" << endl;

	return a + b;

}


int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "rus");
	cout << "*********** THREAD LAMBDA RETURN  ***********" << endl;
	cout << endl;
	cout << "\n*** START MAIN ****\n" << endl;

	int result;

	thread t([&result]() { result = Sum(2, 5); });   // Анонимная лабда-функция с возвращаемым результатом по ссылке из потока результата "result"    

	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;	// id текущего потока
		this_thread::sleep_for(chrono::milliseconds(500));							// "усыпить" поток на 0.5 сек. (1000 msec. = 1 sec.)
	}

	cout << "\n*** END MAIN ****" << endl;

	t.join();

	cout << "Sum Result = " << result << endl;

	cout << endl;
	return 0;
}