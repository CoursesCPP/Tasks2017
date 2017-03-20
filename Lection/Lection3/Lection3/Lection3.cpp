// Lection3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>



using namespace std;

void faсtorial(int numb) //заголовок функции
{
	int rezult = 1;  //инициализируем переменную rezult значением 1
	for (int i = 1; i <= numb; i++) //цикл вычисления значения n!
		rezult *= i; //накапливаем произведение в переменной rezult
	cout << numb << "! = " << rezult << endl; //печать значения n!
}

int faсtorialint(int numb)// заголовок функции
{
	int rezult = 1; // инициализируем переменную rezult значением 1
	for (int i = 1; i <= numb; i++) // цикл вычисления значения n!
		rezult *= i; // накапливаем произведение в переменной rezult
	return rezult; // передаём значение факториала в главную функцию
}

bool palendrom5(int); //прототип функции нахождения палиндрома пятизначных чисел

void check_pass(string password)
{
	string valid_pass = "q1w2e3";

	if (password == valid_pass) {
		cout << "Доступ разрешен." << endl;
	}
	else {
		cout << "Неверный пароль!" << endl;
	}
}

string check_pass_str(string password)
{
	string valid_pass = "qwerty123";
	string error_message;
	if (password == valid_pass) {
		error_message = "Доступ разрешен.";
	}
	else {
		error_message = "Неверный пароль!";
	}
	return error_message;
}


#pragma region Пароль рекурсия

bool password_is_valid(string password)
{
	string valid_pass = "q1w2e3";
	if (valid_pass == password)
		return true;
	else
		return false;
}

void get_pass()
{
	string user_pass;
	cout << "Введите пароль: ";
	getline(cin, user_pass);
	if (!password_is_valid(user_pass)) {
		cout << "Неверный пароль!" << endl;
		system("cls");
		get_pass(); // Здесь делаем рекурсию
	}
	else {
		cout << "Доступ разрешен." << endl;
	}
}

#pragma endregion

#pragma region Inline функции
	inline void hello()
	{
		cout << "hello\n";
	}
#pragma endregion

double triangle_area(const double a = 5, const double b = 6.5, const double c = 10.7); //параметры функции инициализированы по умолчанию

#pragma region Расчет площади треугольника по умолчанию
double triangle_area(const double a, const double b, const double c) // функция вычисления площади треугольника по формуле Герона
{
	const double p = (a + b + c) / 2;   // полупериметр
	cout << "a = " << a << "\nb = " << b << "\nc = " << c << endl;
	return (sqrt(p * (p - a) * (p - b) * (p - c))); // формула Герона для нахождения площади треугольника
}
#pragma endregion

void counter()
{
	static int first_call = 0;
		first_call ++;
		cout << first_call << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

#pragma region Логические операции
	/*
	bool a1 = true, a2 = false; // объявление логических переменных
	bool a3 = true, a4 = false;
	cout << "Таблица истинности &&" << endl;
	cout << "true  && false: " << (a1 && a2) << endl // логическое И
		 << "false && true: " << (a2 && a1) << endl
		 << "true  && true: " << (a1 && a3) << endl
		 << "false && false: " << (a2 && a4) << endl;
	cout << "Таблица истинности ||" << endl;
	cout << "true  || false: " << (a1 || a2) << endl // логическое ИЛИ
		 << "false || true: " << (a2 || a1) << endl
		 << "true  || true: " << (a1 || a3) << endl
		 << "false || false: " << (a2 || a4) << endl;
	cout << "Таблица истинности !" << endl;
	cout << "!true: " << (!a1) << endl // логическое НЕ
		 << "!false: " << (!a2) << endl;
	*/
#pragma endregion

#pragma region Факториал
	/*
	int digit; //переменная для хранения значения n!
	cout << "Введите число: ";
	cin >> digit;
	faсtorial(digit); //вызов функции нахождения факториала
	*/
#pragma endregion

#pragma region Факториал инт
	/*
	int digit; // переменная для хранения значения n!
	cout << "Введите число: ";
	cin >> digit;
	cout << digit << "! = " << faсtorialint(digit) << endl;// запуск функции нахождения факториала
	*/
#pragma endregion

#pragma region Палиндром 
	/*
	cout << "Введите 5-ти значное число: "; // введите пятизначное число
	int in_number, out_number; // переменные для хранения введённого пятизначного числа
	cin >> in_number;
	out_number = in_number; // в переменную out_number сохраняем введённое число

	if (palendrom5(in_number)) // если функция вернёт true, то условие истинно, иначе функция вернёт false - ложно
		cout << "Число " << out_number << " - палиндром" << endl;
	else
		cout << "Это число не палиндром" << endl;
	*/
#pragma endregion

#pragma region Пароль не функция
	/*
	string valid_pass = "q1w2e3";
	string user_pass;
	cout << "Введите пароль: ";
	getline(cin, user_pass);
	if (user_pass == valid_pass) {
		cout << "Доступ разрешен." << endl;
	}
	else {
		cout << "Неверный пароль!" << endl;
	}
	*/
#pragma endregion

#pragma region Пароль функция
	/*
	string user_pass;
	cout << "Введите пароль: ";
	getline(cin, user_pass);
	check_pass(user_pass);
	*/
#pragma endregion

#pragma region Пароль строка
	/*
	string user_pass;
	cout << "Введите пароль: ";
	getline(cin, user_pass);
	string error_msg = check_pass_str(user_pass);
	cout << error_msg << endl;
	*/
#pragma endregion

#pragma region Пароль рекурсия
	/*
	get_pass();
	*/
#pragma endregion

#pragma region Расчет площади треугольника по умолчанию
	
	cout << "S = " << triangle_area() << endl << endl; // все параметры используются по умолчанию
	cout << "S = " << triangle_area(10, 5) << endl << endl; // только последний параметр используется по умолчанию
	cout << "S = " << triangle_area(7) << endl << endl; // два последних параметра берутся по умолчанию, а первый равен 7
	
#pragma endregion

#pragma region Inline hello
	/*
	hello();
	*/
#pragma endregion

	system("pause");
    return 0;
}

#pragma region Палиндром-ф

bool palendrom5(int number) // функция нахождения палиндрома пятизначных чисел
{
	int balance1, balance2, balance4, balance5; // переменные хранящие промежуточные результаты
	balance1 = number % 10; // переменной balance1 присвоили первый разряд пятизначного числа
	number = number / 10;   // уменьшаем введённое число на один разряд

	balance2 = number % 10; // переменной balance2 присвоили второй разряд
	number = number / 100;  // уменьшаем введённое число на два разряда

	balance4 = number % 10; // переменной balance4 присвоили четвёртый разряд
	number = number / 10;   // уменьшаем введённое число на один разряд

	balance5 = number % 10; // переменной balance5 присвоили пятый разряд
	if ((balance1 == balance5) && (balance2 == balance4))
		return true;  // функция возвращает истинное значение
	else
		return false; // функция возвращает ложное значение
}

#pragma endregion

