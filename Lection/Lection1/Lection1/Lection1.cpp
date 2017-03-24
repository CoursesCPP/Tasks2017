// Lection1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>// потоки ввода-вывода
#include <iomanip> // библиотека манипулирования вводом/выводом
#include <cmath>   // заголовочный файл математических функций
#include <climits>   
#define ZERO 0   

using namespace std;

int main()
{
	setlocale(LC_ALL,"Russian");

	#pragma region Char
	/*
	char symbol = 'a'; // объявление переменной типа char и инициализация её символом 'a'
	cout << "В переменной symbol лежит " << symbol << endl; // печать символа, 
										//содержащегося в переменной symbol
	char string[] = "строка"; // объявление символьного массива (строки)
	cout << "string = " << string << endl; // печать строки
	cout << "Первый симол string = " << string[0] << endl;
	*/
	#pragma endregion
	
	#pragma region Bool
	
	bool boolean = true; //false // переменная типа bool с именем boolean

	cout << sizeof(bool);
	/*if (boolean) // условие оператора if
		cout << "true = " << boolean << endl; // выполнится в случае истинности условия
	else
		cout << "false = " << boolean << endl; // выполнится в случае, если условие ложно
	*/
	#pragma endregion

	#pragma region Числовые типы
	/*
	int n_int = INT_MAX;        
	short n_short = SHRT_MAX;   
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	float fvar;
	double dvar;
	
	
	cout << "int is " << sizeof(int) << " bytes." << endl;
	cout << "short is " << sizeof n_short << " bytes." << endl;
	cout << "long is " << sizeof n_long << " bytes." << endl;
	cout << "long long is " << sizeof n_llong << " bytes." << endl;
	cout << endl;

	cout << "Maximum values:" << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;
	cout << "long long: " << n_llong << endl << endl;

	cout << "Minimum int value = " << INT_MIN << endl;
	cout << "Bits per byte = " << CHAR_BIT << endl;

	cout << "Max unsignned long long = " << ULLONG_MAX << endl;
	*/
 	#pragma endregion
	
	#pragma region Литералы
	/*
	3.14 - double
	3.14F - float
	100u или 100U - unsingned int
	122l или 122L - long
	1024UL или 1024LU или 1024Lu - unsingned long

	Виды: 20, 024, 0x14

	Символьные литералы - 'a' '2' ',' ' '
	
	Специальные символы:
		\n (\14) - новая строка
		\t - табуляция
		\r - возврат каретки(enter)
		\a - сигнал
		\b - подчеркивание 
		\062 - '2'				
    Строковый литерал:
	"\n CC \t options \t file.[cC] \n" - последний элемент \0
	'A' "A"

	wchar_t - L"some string"
	*/
	
	//Упражнение

	//'a', L'a', "a", L"a";

	//10, 10u, 10L, 10uL, 012, 0xA;

	//3.14, 3.14f, 3.14L;

	//1024F, 3.14UL;
	#pragma endregion
	
	#pragma region Переполнение 1
	/*
		short sam = SHRT_MAX;     
		unsigned short sue = sam;

		cout << "Sam has " << sam << " dollars and Sue has " << sue;
		cout << " dollars deposited." << endl
			<< "Add $1 to each account." << endl << "Now ";
		sam = sam + 1;
		sue = sue + 1;
		cout << "Sam has " << sam << " dollars and Sue has " << sue;
		cout << " dollars deposited.\nPoor Sam!" << endl;
		sam = ZERO;
		sue = ZERO;
		cout << "Sam has " << sam << " dollars and Sue has " << sue;
		cout << " dollars deposited." << endl;
		cout << "Take $1 from each account." << endl << "Now ";
		sam = sam - 1;
		sue = sue - 1;
		cout << "Sam has " << sam << " dollars and Sue has " << sue;
		cout << " dollars deposited." << endl << "Lucky Sue!" << endl;
	*/	
	#pragma endregion

	#pragma region Переполнение 2
		/*
		char byte_value = 32;
		int ival = 8;
		cout << sizeof(char) << endl;
		byte_value = ival * byte_value; //256 - 9 бит
		cout << "byte_value: " << static_cast<int>(byte_value) << endl;
		*/
	#pragma endregion

	#pragma region Отображение 8,16ричных чисел
		/*
		int val_10 = 42;
		int val_16 = 42;
		int val_8 = 42;
		
		cout << "val_10 = " << val_10 << " (decimal for 42)" << endl;
		cout << hex;      
		cout << "val_16 = " << val_16 << " (hexadecimal for 42)" << endl;
		cout << oct;      
		cout << "val_8 = " << val_8 << " (octal for 42)" << endl;
		*/
	#pragma endregion

	#pragma region Char и Int - ASCII
	/*
	char ch = 'M';       
	int i = ch;          
	cout << "The ASCII code for " << ch << " is " << i << endl;
	cout << "Add one to the character code:" << endl;
	ch = ch + 1;          
	i = ch;               
	cout << "The ASCII code for " << ch << " is " << i << endl;
	cout << "Displaying char ch using cout.put(ch): ";
	cout.put(ch);
	cout.put('!');
	cout << endl << "Done" << endl;
	*/
#pragma endregion

	#pragma region Управляющие (escape) последовательности
	/*
	cout << "\aOperation \"HyperHype\" is now activated!\n";
	cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";
	long code;
	cin >> code;
	cout << "\aYou entered " << code << "...\n";
	cout << "\tCode verified! Proceed with Plan Z3!\n";
	*/
	#pragma endregion

	#pragma region Изменение типа при инициализации
	/*
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tree = 3;     // int to float
	int guess = 3.9832; // double to int
	int debt = 7.2E12;  // не определено в C++
	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl;
	cout << "debt = " << debt << endl;
	*/
	#pragma endregion

	system("pause");
    return 0;
}

