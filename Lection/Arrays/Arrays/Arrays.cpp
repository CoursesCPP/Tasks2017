// Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int ABSLIMIT = 100;

#pragma region Функции для одномерного массива

/*
Для использования данных функция для динамического одномерного массива,
небходимо заменить аргументы функций с (int array[], const int SIZE)
на (int *array, int SIZE) во всех функциях.
*/

//Функция генерации случайного числа из диапазона от range_min до range_max включительно
int rrand(int range_min, int range_max) 
{
	return rand() % (range_max - range_min + 1) + range_min;
}

//Функция инициализации массива случайными значениями из диапазона -ABSLIMIT..ABSLIMIT
void set_random_values(int array[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++) 
	{
		array[i] = rrand(-ABSLIMIT, ABSLIMIT);
	}
}

//Функция для инициализации массива вводом из cin с проверками
void cin_array(int array[], const int SIZE)
{
	bool fail = false;
	for (unsigned int i = 0; i < SIZE; i++) {
		do {
			fail = false;
			cout << "Введите значение для элемента массива " << i << ": ";
			cin >> array[i];
			if (cin.fail()) {
				cout << "*** Введено некорректное значение. Повторите ввод." << endl;
				fail = true;
			}
			cin.clear();
			cin.ignore();
		} while (fail);
	}
}

//Функция вывода на консоль значений из массива
void show_array(int array[], const int SIZE)
{
	for (unsigned int i = 0; i < SIZE; i++) 
	{
		cout << "Значение элемента массива [" << i << "] = " << array[i] << endl;
	}
}

//Функция поиска минимального значения в массиве и его индекса
void min_val(int array[], const int SIZE)
{
	// при наличии нескольких минимальных значений находится первое
	int min_val = array[0];
	int min_idx = 0;
	for (int i = 1; i < SIZE; i++) 
	{
		if (min_val > array[i]) 
		{
			min_val = array[i];
			min_idx = i;
		}
	}
	cout << "Минимальное значение " << min_val << ", индекс элемента " << min_idx << endl;
}

//Функция поиска макисмального значения в массиве и его индекса
void max_val(int array[], const int SIZE)
{
	// при наличии нескольких макисмальных значений находится первое
	int max_val = array[0];
	int max_idx = 0;
	for (int i = 1; i < SIZE; i++)
	{
		if (max_val < array[i])
		{
			max_val = array[i];
			max_idx = i;
		}
	}
	cout << "Минимальное значение " << max_val << ", индекс элемента " << max_idx << endl;
}

//Функция поиска в массиве первого вхождения определённого значения
void first_pattern_val(int array[], const int SIZE, int pattern)
{
	int i;
	for (i = 0; i < SIZE; i++) 
	{
		if (array[i] == pattern) 
			break;
	}
	if (i >= SIZE) 
		cout << "Искомый элемент не найден" << endl;
	else 
		cout << "Индекс первого вхождения искомого значения: " << i << endl;
}

//Функция поиска в массиве последнего вхождения определённого значения
void last_pattern_val(int array[], const int SIZE, int pattern)
{
	int i;
	for (i = SIZE - 1; i >= 0; i--) 
	{
		if (array[i] == pattern) 
			break;
	}
	if (i < 0) 
		cout << "Искомый элемент не найден" << endl;
	else 
		cout << "Индекс последнего вхождения искомого значения: " << i << endl;
}

//Функция поиска в массиве всех вхождений определённого значения
void all_pattern_val(int array[], const int SIZE, int pattern)
{
	int i;
	bool found = false;
	for (i = 0; i < SIZE; i++) 
	{
		if (array[i] == pattern) 
		{
			cout << "Индекс найденного элемента: " << i << endl;
			found = true;
		}
	}
	if (!found) 
		cout << "Искомый элемент не найден" << endl;
}

#pragma endregion

#pragma region Функции для многомерного динамического массива

//Функция создания динамического массива
int **array_generator(int size1, int size2)
{
	int **ptrarray = new int *[size1];
	for (int i = 0; i < size1; i++) 
	{
		ptrarray[i] = new int[size2];
	}
	return ptrarray;
}

//Функция удаления динамического массива
void array_destroyer(int **array, int size1) 
{
	for (int i = 0; i < size1; i++) 
	{
		delete[] array[i];
	}
	delete[] array;
}

//Функция заполнения и вывода на консоль динамического массива
void array_fill_and_show(int **array, int size1, int size2)
{
	for (int i = 0; i < size1; i++) 
	{
		for (int j = 0; j < size2; j++) 
		{
			array[i][j] = (i + 1) * 10 + (j + 1);
			cout << setw(4) << array[i][j];
		}
	}
}

#pragma endregion

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	#pragma region Статический одномерный массив
	/*
		const int SIZE = 10;
		int array[SIZE] = {};
	*/
	#pragma endregion

	#pragma region Динамический одномерный массив
	/*
		int arr_size;
		cin >> arr_size;
		int *array = new int[arr_size]; //Выделение памяти под массив
		// Какие- то действия
		delete[] array; //Удаление выделенной памяти
	*/
	#pragma endregion

	#pragma region Статический многомерный массив
		/*
		const int SIZE1 = 3;
		const int SIZE2 = 5;

		int array[SIZE1][SIZE2];
		*/
	#pragma endregion

	#pragma region Динамический многомерный массив
	/*
	int **array;    
	int SIZE1 = 5, SIZE2 = 5;
	
	array = new int *[SIZE1];    // массив указателей 
	for (int i = 0; i < SIZE1; i++) 
	{   
		array[i] = new int[SIZE2];     // инициализация указателей
	}

	// работа с массивом
	for (int i = 0; i < SIZE1; i++) 
	{
		for (int j = 0; j < SIZE2; j++) 
		{
			array[i][j] = (i + 1) * 10 + (j + 1);
		}
	}

	for (int i = 0; i < SIZE1; i++) 
	{
		for (int j = 0; j < SIZE2; j++) 
		{
			cout << setw(4) << array[i][j];
		}
		cout << endl;
	}

	// уничтожение
	for (int i = 0; i < SIZE1; i++) 
	{
		delete[] array[i];
	}
	delete[] array;
	*/
	#pragma endregion

	system("pause");
    return 0;
}

