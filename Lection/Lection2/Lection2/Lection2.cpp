// Lection2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip> //директива манипуляторов строк
#include <cmath>   //директива математических функций
#include <conio.h> //директива консольного ввода-вывода

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

#pragma region Преобразование типов
	/*
	//объявляем две переменные типа int
	int int_value15 = 15, int_value2 = 2;	

	//объявляем две переменные типа float
	float float_value15 = 15, float_value2 = 2;		
	
	//определяем, при выводе чисел с плавающей точкой, два знака после запятой
	cout << fixed << setprecision(2)							
		 //неявное преобразование типов данных
		 << "15 / 2 = " << int_value15 / int_value2 << endl	
		 //неявное преобразование типов данных
		 << "15 / 2 = " << int_value15 / float_value2 << endl
 		 //неявное преобразование типов данных
		 << "15 / 2 = " << float_value15 / int_value2 << endl		
		 //неявное преобразование типов данных
		 << "15 / 2 = " << float_value15 / float_value2 << endl;		
	
	//явное преобразование типа данных, число 15.0 - число с плавающей точкой
	cout << "15.0 / 2   = " << 15.0 / 2 << endl				
	//явное преобразование типа данных, число 2.0  - число с плавающей точкой
		 << "15   / 2.0 = " << 15 / 2.0 << endl;

	//явное преобразование типа данных
	cout << "float(int_value15) / int_value2 = " 
		<< float(int_value15) / int_value2 << endl
		 //используя приводимый тип как функцию
		 << "15 / double(2) = " << 15 / double(2) << endl;
	//операция приведения типа
	cout << "static_cast<float>(15) / 2 = " 
		<< static_cast<float>(15) / 2 << endl 
		 //можно печатать различные символы из таблицы ASCII,
		 << "static_cast<char>(15) = " 
		<< static_cast<char>(15) << endl
		 //в скобочках прописываем код символа, который находим в таблице ASCII
		 << "static_cast<char>(20) = " 
		<< static_cast<char>(20) << endl; 
	*/
	
#pragma endregion


#pragma region Оператор Switch
	
/*
	int count;	 //переменная для выбора в switch
	double a, b; //переменные для хранения операндов
	cout << "Введите первое число: \n";
	cin >> a;
	cout << "Введите второе число: \n";
	cin >> b;
	cout << "Выберите действие: 1-сложение; 2-вычитание; 3-yмножение; 4-деление: \n";
	cin >> count;
	switch (count) //начало оператора switch
	{
		case 1: //если count = 1
		{
			cout << a << " + " << b << " = " << a + b << endl; 
			//выполнить сложение
			break;
		}
		case 2: //если count = 2
		{
			cout << a << " - " << b << " = " << a - b << endl; 
			//выполнить вычитание
			break;
		}
		case 3: //если count = 3
		{
			cout << a << " * " << b << " = " << a * b << endl; 
			//выполнить умножение
			break;
		}
		case 4: // если count = 4
		{
			cout << a << " / " << b << " = " << a / b << endl; //выполнить деление
			break;
		}
		default: // если count равно любому другому значению
			cout << "Неправильный ввод" << endl;
	}
	*/
#pragma endregion
    

#pragma region Цикл While
	
	#pragma region Скорость автомобиля
	    /*
		int speed = 5,   //начальная скорость автомобиля
			count = 1;   // скорость
		while (speed < 60)
		{
			speed += 10; //приращение скорости
			cout << count << "- скорость = " << speed << endl;
			count++;	 //подсчёт повторений цикла
		}
		*/
	#pragma endregion

	#pragma region Угадай число
		/*
		srand(time(0));		//генератор случайных чисел
		int unknown_number = 1 + rand() % 10; //загадываемое число
		int enter_number; //переменная для хранения введённого числа
		cout << "Введите число в интервале [1:10] : "; //начинаем отгадывать
		cin >> enter_number;
		while (enter_number != unknown_number)
		{
			cout << "Введите число в интервале [1:10] : ";
			cin >> enter_number; //продолжаем отгадывать
		}
		cout << "Вы угадали!\n";
		
		*/
	#pragma endregion

	#pragma region Сумма чисел
	/*
		int i = 0;   //счетчик цикла
		int sum = 0; //сумма
		while (i < 1000)
		{
			sum += ++i;
		}
		cout << "Сумма чисел от 1 до 1000 = " << sum << endl;
	*/
	#pragma endregion

#pragma endregion	


#pragma region Цикл DoWhile

	#pragma region Счет в банке
		/*
		srand(time(0));
		int balance = 8; // баланс
		int removal = 0;
		do // начало цикла do while
		{
			cout << "Баланс = " << balance << endl; // показать баланс
			removal = (rand() % 3) + 1; // переменная, для хранения вычитаемого значения
			cout << "Снятие = " << removal << endl; // показать вычитаемое значение
			balance -= removal; // управление условием
		} while (balance > 0); // конец цикла do while
		cout << "Деньги закончились!" << endl;
		*/
	#pragma endregion

	#pragma region Угадай число
		/*
		srand(time(0));
		int unknown_number = 1 + rand() % 10; //загадываемое число
		int enter_number; //переменная для хранения введённого числа
		do
		{
			cout << "Введите число в интервале [1:10] : ";
			cin >> enter_number; // отгадываем
		} while (enter_number != unknown_number);
		cout << "Вы угадали!\n";
		*/
	#pragma endregion

	#pragma region Сумма чисел
		/*
		int i = 0;   //счетчик цикла
		int sum = 0; //счетчик суммы
		do 
		{ 
			sum += ++i;
		} while (i < 1000); // пока выполняется условие.
		cout << "Сумма чисел от 1 до 1000 = " << sum << endl;
		*/
	#pragma endregion

	#pragma region Cумма в интервале
		/*
		cout << "Введите начало интервала: "; //начальное значение из интервала
		int first_limit;
		cin >> first_limit;
		cout << "Введите конец интервала: ";  //конечное значение из интервала
		int second_limit;
		cin >> second_limit;
		int sum = 0, count = first_limit;
		do
		{
			sum += count++; //наращивание суммы
			//count++;	  //инкремент начального значения из задаваемого интервала
		} while (count <= second_limit); // конец цикла do while
		cout << "Сумма чисел = " << sum << endl;
		*/
	#pragma endregion

#pragma endregion


#pragma region Цикл For
	
	#pragma region Кол-во четных чисел в интервале
		/*
		int counter_even = 0; //счетчик четных чисел
		int end_interval = 0; //конец интервала
		cout << "Введите конец интервала" << endl;
		cin >> end_interval;
		for (int count = 2; count <= end_interval; count += 2) //заголовок цикла
		{
			counter_even++; //подсчёт чётных чисел
		}			
		cout << "Количество четных чисел = " << counter_even << endl;
		*/
	#pragma endregion

	#pragma region Сумма чисел
		/*
		int sum = 0; //счетчик суммы
		for (int i = 0; i <= 1000; i++) // задаем начальное значение 1, конечное 1000 и задаем шаг цикла - 1.
		{    
			sum += i;
		}
		cout << "Сумма чисел от 1 до 1000 = " << sum << endl;
		*/
	#pragma endregion

#pragma endregion


#pragma region Break в циклах
	    /*
		for (int count = 0; count <= 100; count++) // начало цикла for
		{
			if (count == 95)
				break; // выход из цикла for
			else
			cout << "2^" << count << " = " << pow(2.0, count) << endl; // печать степени двойки
		}
		*/
#pragma endregion


#pragma region Условия с присваиванием
		/*
		int chcount = 0;
		int wdcount = 1;
		char ch;
		while ( (ch = getche()) != '\r') 
		{
			if (ch == ' ')
				wdcount++;
			else
				chcount++;
		}
		cout << "\nВведено слов: " << wdcount << "\nВведено букв: " << chcount << endl;
		*/
#pragma endregion


		int a = 456789123;
		do
		{
			cout << a % 10;
			a /= 10;
		}while (a >= 10);
		cout << a;


	system("pause");
	return 0;
}

