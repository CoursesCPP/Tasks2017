// Hometask3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "conio.h"
#include <string>

using namespace std;

void order(double* p1, double*p2) {
	double temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void bubbleSort(double ar[], int size, bool(*fnCompare)(double left, double right)) {
	int high = size - 1;
	while (high > 0) {
		int j;
		for (j = 0; j < high; j++) {
			if (!fnCompare(ar[j], ar[j + 1])) {
				order(&ar[j], &ar[j + 1]);
			}
		}
		high--;
	}
}

bool fnMin(double left, double right) {
	return left < right;
}
double dnums[2][3];
double* getArMinMax(double* d1, double* d2, double* d3) {
	const int size = 3;
	double nums[size] = { *d1, *d2, *d3 };
	bubbleSort(nums, size, &fnMin);
	for (int i = 0; i < size; i++) {
		dnums[0][i] = nums[i];
		dnums[1][i] = nums[size - 1 - i];
	}
	return &(dnums[0][0]);
}

//struct Rates {
//	unsigned* rates;
//	unsigned count = 0;
//	void add(unsigned rate) {
//		unsigned* newRates = new unsigned[++count];
//		memcpy(newRates, rates, count * sizeof(unsigned));
//		delete[] rates;
//		rates = newRates;
//	}
//	void clear() {
//		delete[] rates;
//	}
//};

struct Student {
	string lastName;
	unsigned finalTasks;
	unsigned* rates;
};

float qualityLearning(Student* students, unsigned size) {
	unsigned successStudents = 0;
	for (unsigned i = 0; i < size; i++) {
		bool isSuccess = true;
		for (unsigned j = 0; j < students[i].finalTasks; j++) {
			if (students[i].rates[j] < 4) {
				isSuccess = false;
				break;
			}
		}
		if (isSuccess) successStudents++;
	}
	return (float)successStudents / size;
}

typedef unsigned char byte;

int main()
{
	/*Написать функцию, принимающую 3 указателя на вещественные переменные и выводящую значения переменных, на которые они указывают в порядке возрастания и убывания. (3 2 1) -> (1 2 3), (3 2 1).*/
	/*double d1 = 3, d2 = 2, d3 = 1;
	double* resAr = getArMinMax(&d1, &d2, &d3);
	for (int i = 0; i < 2*3; i++)
		cout << resAr[i];*/

	/*Определите структуру для представления записи информации о сданных студентом экзаменах (фамилия студента, число экзаменов, массив полученных оценок). 
		В результате обработки требуется вычислить характеристику качественной успеваемости студентов, то есть отношение числа студентов, 
		сдавших экзамены на 4 и 5, к общему числу студентов, в %. */
	//students[5];
	/*Student st1, st2, st3;
	unsigned rates1[3] = { 4, 5, 4 };
	unsigned rates2[2] = { 4, 4 };
	unsigned rates3[3] = { 5, 5, 3 };
	st1.lastName = "Петров";
	st1.finalTasks = sizeof(rates1);
	st1.rates = rates1;

	st2.lastName = "Иванов";
	st2.finalTasks = sizeof(rates2);
	st2.rates = rates2;

	st3.lastName = "Сидоров";
	st3.finalTasks = sizeof(rates3);
	st3.rates = rates3;

	const byte stCount = 3;
	Student students[stCount] = { st1, st2, st3 };
	cout << qualityLearning(students, stCount);*/

	/* Написать программу, в которой необходимо создать структуру, элементами которой являются фамилия автора книги и ее название. 
	Объявить массив данных типа структуры и ввести значения его элементов. Предусмотреть вывод содержимого массива. */
	/*struct Book {
		string author;
		string title;
		void output() {
			cout << "----------" << endl << author << endl << title << "\n\n";
		}
	} books[3] = { {"Petrov", "book-title1"},{ "Ivanov", "book-title2" },{ "Sidorov", "book-title3" } };

	for(int i = 0; i < sizeof(books) / sizeof(Book); i++)
		books[i].output();*/

	/*Создайте структуру с именем employee, содержащую два поля: номер сотрудника типа int и величину его зарплаты типа float. Запросите с клавиатуры данные о трех сотрудниках, 
		сохраните их в трех структурных переменных и выведите информацию о каждом сотруднике. */
	/*struct employee {
		int id;
		float salary;
	} employees[3];
	for (int i = 0; i < sizeof(employees) / sizeof(employee); i++) {
		cout << "------------" << endl;
		cin >> ((cout << "Please enter employee id: "), employees[i].id);
		cin >> ((cout << "Please enter employee salary: "), employees[i].salary);
	}
	for (int i = 0; i < sizeof(employees) / sizeof(employee); i++) {
		cout << employees[i].id << " - " << employees[i].salary << endl;
	}*/

	////////// Utils //////////
	struct utils {
		static int toNum(char* digits, unsigned count) {
			unsigned res = 0;
			for (unsigned i = 0; i < count; i++) {
				unsigned tens = (unsigned)pow(10, count - 1 - i);
				res += (digits[i] - (byte)'0') * tens;
			}
			return res;
		}
	};
	//////////////////////////

	/* Создайте структуру date, содержащую три поля типа int: день, месяц, год. Пользователь вводит дату в формате 31/12/1999, 
	сохраните введенное значение в структурной переменной, затем извлеките данные и выведите их на экран в том же формате, как они вводились. */
	/*struct date {
		int day, month, year;
	} dt;
	string dateInput;
	cin >> ((cout << "Enter date (format: dd/mm/yyyy): "), dateInput);
	char dayDigits[2] = { dateInput[0], dateInput[1] };
	char monthDigits[2] = { dateInput[3], dateInput[4] };
	char yearDigits[4] = { dateInput[6], dateInput[7], dateInput[8], dateInput[9] };
	dt.day = utils::toNum(dayDigits, 2);
	dt.month = utils::toNum(monthDigits, 2);
	dt.year = utils::toNum(yearDigits, 4);
	cout << dt.day << "/" << dt.month << "/" << dt.year;*/

	/* Напишите программу, используя структуру time(hours, minutes, seconds). 
	Программа получает от пользователя 2 значения времени в формате 12:59:59, сохраняет их в переменных типа структуры time, 
	затем переводит оба значения в секунды, складывает их, и переводит сумму в формат структуры и выводит на экран. */
	struct time {
		byte hours;
		byte minuts;
		byte seconds;
	} tms[2];
	for (int i = 0; i < 2; i++) {
		string timeStr;
		cin >> ((cout << "Please enter time: "), timeStr);
		char dOurs[2] = { timeStr[0], timeStr[1] };
		char dMins[2] = { timeStr[3], timeStr[4] };
		char dSecs[2] = { timeStr[6], timeStr[7] };
		tms[i].hours = (byte)utils::toNum(dOurs, 2);
		tms[i].minuts = (byte)utils::toNum(dMins, 2);
		tms[i].seconds = (byte)utils::toNum(dSecs, 2);
	}
	{
		unsigned short res = 0;
		for (int i = 0; i < 2; i++) {
			res += ((unsigned short)tms[i].hours * 60 * 60) + (tms[i].minuts * 60) + tms[i].seconds;
		}
		cout << "Secons number = " << res;
	}
	

	_getch();
    return 0;
}

