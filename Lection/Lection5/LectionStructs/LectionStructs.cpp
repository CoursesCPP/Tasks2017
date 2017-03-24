// LectionStructs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>  
#include <string>
using namespace std;

struct part                    // объявление структуры
{
	int modelnumber;           // номер модели изделия
	int partnumber;            // номер детали
	float cost;                // стоимость детали
	string city;
};

struct Distance                // футы и дюймы
{
	int feet;
	float inches;
};

struct Room                  // прямоугольная комната
{
	Distance length;         // длина
	Distance width;          // ширина
};

#pragma region Структура карточной игры
struct card
{
	int number;                     //достоинство
	int suit;                       //масть
};

const int clubs = 0;                //масти
const int diamonds = 1;
const int hearts = 2;
const int spades = 3;
const int jack = 11;                //достоинства карт
const int queen = 12;
const int king = 13;
const int ace = 14;

	#pragma region Карточная игра №2
/*
enum Suit { clubs, diamonds, hearts, spades };

struct card
{
	int number;                     // достоинство карты
	Suit suit;                      // масть
};
*/
#pragma endregion

#pragma endregion

struct time
{
	int hrs;
	int min;
	int sec;
};

// объявление перечисляемого типа
enum days_of_week { Sun, Mon, Tue, Wed, Thu, Fri, Sat };

enum level { parking, supermarket, hardwareStores, boutiques, sportSpa, clubRestaurantBar };
enum itsaWord { NO, YES };     // NO=0, YES=1
//enum itsaAM{ NO, YES };

int main()
{

	setlocale(LC_ALL, "Russian");

	#pragma region Структура время
	/*
	long tl1, tl2, tlf;
	time t1, t2, tf;
	char ch;
	cout << "Введите первое значение времени\n";
	cin >> t1.hrs >> t1.min >> t1.sec;
	cout << "Введите второе значение времени\n";
	cin >> t2.hrs >> t2.min >> t2.sec;
	tl1 = t1.hrs * 3600 + t1.min * 60 + t1.sec;
	tl2 = t2.hrs * 3600 + t2.min * 60 + t2.sec;
	tlf = tl1 + tl2;
	tf.hrs = tlf / 3600;
	tf.min = (tlf - tf.hrs * 3600) / 60;
	tf.sec = tlf - tf.hrs * 3600 - tf.min * 60;
	cout << "Время: " << tf.hrs << ":" << tf.min << ":" << tf.sec << endl;
	*/
	#pragma endregion

	#pragma region Указатель на void
	/*
	int intvar;           
	float flovar;         

	int *ptrint;          
	float *ptrflo;
	void *ptrvoid;        

	ptrint = &intvar;     // так можно: int* = int*
    //ptrint = &flovar;     // так нельзя: int* = float*
    //ptrflo = &intvar;     // так нельзя: float* = int*
	ptrflo = &flovar;     // так можно: float* = float*

	ptrvoid = &intvar;    // так можно: void* = int*
	ptrvoid = &flovar;    // так можно: void* = float*
	*/
	#pragma endregion

	#pragma region Доступ к массиву через указатель
	/*
	int intarray[5] = { 31, 54, 77, 52, 93 }; 
	int *ptrint;                     
	ptrint = intarray;              

	for (int j = 0; j < 5; j++)      
		cout << *(ptrint--) << endl; 
	*/
	#pragma endregion

	#pragma region Указатель на функцию
		
		#pragma region Переменная
	/*
	void centimize ( double* );

	double var = 10.0;
	cout << "var = " << var << "дюймов" << endl;
	centimize ( &var );
	cout << "var= " << var << "сантиметров" << endl;
	*/
		#pragma endregion

		#pragma region Массив
	/*
	void centimize(double*);

	double varray[5] = { 10.0, 43.1, 95.9, 58.7, 87.3 };

	centimize(varray);        // переводим все элементы массива в сантиметры

							  // покажем, что у нас получилось
	for (int j = 0; j < 5; j++)
		cout << "varray [ " << j << " ] = " << varray[j] << " сантиметров" << endl;
	*/
#pragma endregion

		#pragma region Сортировка
	/*
	void order(int*, int*);     

	int n1 = 99, n2 = 11;
	int n3 = 22, n4 = 88;

	order(&n1, &n2);
	order(&n3, &n4);
	order(&n2, &n3);
	order(&n3, &n4);
	cout << "n1 = " << n1 << endl; 
	cout << "n2 = " << n2 << endl; 
	cout << "n3 = " << n3 << endl;
	cout << "n4 = " << n4 << endl;
	*/
#pragma endregion
		
		#pragma region Сортировка пузырьком
	/*
	void bsort(int*, int); // прототип функции
	const int N = 10;      // размер массива
	int arr[N] = { 37, 84, 62, 91, 11, 65, 57, 28, 19, 49 }; // массив для сортировки

	bsort(arr, N);

	for (int j = 0; j < N; j++)
		cout << arr[j] << " ";
	cout << endl;
	*/
	#pragma endregion

#pragma endregion

	#pragma region Первая структура
	
	part part1;                // определение структурной переменной

	part1.modelnumber = 6244;  // инициализация полей
	part1.partnumber = 373;    // переменной part1
	part1.cost = 217.55F;
	cout << "Модель " << part1.modelnumber;
	cout << ", деталь " << part1.partnumber;
	cout << ", стоимость " << part1.cost << endl;
	
	#pragma endregion

	#pragma region Инициализация полей
	/*
	part part1 = { 6244,373,217.55F, "Москва" };
	part part2;             // объявление переменной
							// вывод полей первой переменной	
	cout << "Модель " << part1.modelnumber;
	cout << ", деталь " << part1.partnumber;
	cout << ", стоимость $" << part1.cost;
	cout << ", производитель " << part1.city << endl;
	part2 = part1;          // присваивание структурных переменных
							// вывод полей второй переменной
	cout << "Модель " << part2.modelnumber;
	cout << ", деталь " << part2.partnumber;
	cout << ", стоимость $" << part2.cost;
	cout << ", производитель " << part2.city << endl;
	*/
	#pragma endregion

	#pragma region Пример сложения футов и дюймов
	/*
	Distance d1, d3;            
	Distance d2 = { 11, 6.25 }; // определение с инициализацией								
	cout << "\nВведите число футов: "; 
	cin >> d1.feet;
	cout << "Введите число дюймов: "; 
	cin >> d1.inches;
	// сложение длин d1 и d2 и присвоение результата d3
	d3.inches = d1.inches + d2.inches; // сложение дюймов
	d3.feet = 0;                       
	if (d3.inches >= 12.0)            // если сумма больше 12.0,
	{                                  // то уменьшаем 
		d3.inches -= 12.0;                 // число дюймов на 12.0 и
		d3.feet++;                         // увеличиваем число футов на 1
	}
	d3.feet += d1.feet + d2.feet;      // сложение футов
									   // вывод всех длин на экран
	cout << d1.feet << "\'-" << d1.inches << "\" + ";
	cout << d2.feet << "\'-" << d2.inches << "\" = ";
	cout << d3.feet << "\'-" << d3.inches << "\"\n";
	*/
	#pragma endregion

	#pragma region Вложенные структуры
	/*
	Room dining;           
	//параметры комнаты
	dining.length.feet = 13; 
	dining.width.feet = 10;
	cin >> dining.width.inches;
	cin >> dining.length.inches;
	//Room dining1 = { {13, 6.5} , {10, 0.0} };
	// преобразование длины и ширины в вещественный формат
	float l = dining.length.feet + dining.length.inches / 12;
	float w = dining.width.feet + dining.width.inches / 12;
	// вычисление площади комнаты и вывод на экран
	cout << "Площадь комнаты равна " << l * w
		<< " квадратных футов\n";
	*/
	#pragma endregion

	#pragma region Карточная игра
/*
	card temp, chosen, prize;       // три карты: для смены мест, для выбора, загаданная карта
	int position;
	card card1 = { 7, clubs };      // инициализация карты 1
	cout << "Карта 1: 7 треф\n";
	card card2 = { jack, hearts };  // инициализация карты 2
	cout << "Карта 2: валет червей\n";
	card card3 = { ace, spades };   // инициализация карты 3
	cout << "Карта 3: туз пик\n";
	prize = card3;                  // запоминание карты 3
	cout << "Меняем местами карту 1 и карту 3...\n";
	temp = card3; card3 = card1; card1 = temp;
	cout << "Меняем местами карту 2 и карту 3...\n";
	temp = card3; card3 = card2; card2 = temp;
	cout << "Меняем местами карту 1 и карту 2...\n";
	temp = card2; card2 = card1; card1 = temp;
	cout << "На какой позиции (1,2 или 3) теперь туз пик?\n";
	cin >> position;
	switch (position)
	{
	case 1: chosen = card1; break;
	case 2: chosen = card2; break;
	case 3: chosen = card3; break;
	}
	if (chosen.number == prize.number && // сравнение карт
		chosen.suit == prize.suit)
		cout << "Правильно! Вы выиграли!\n";
	else
		cout << "Неверно. Вы проиграли.\n";
	*/
	#pragma endregion

	#pragma region Перечисления
	/*
	days_of_week day1, day2;     // определения переменных,
								 // хранящих дни недели
	day1 = Mon;                  // инициализация переменных
	day2 = Thu;
	int diff = day2 - day1;      // арифметическая операция
	cout << "Разница в днях: " << diff << endl;
	if (day1 < day2)             // сравнение
		cout << day1 << " наступит раньше, чем day2\n";
	*/
	#pragma endregion

	#pragma region Лифт
	/*
	level floor = parking;//переменная типа перечисления level
						  //level floor = 0; не скомпилируется
	int fl = floor;  //выбор этажа пользователем 
	bool exit = true;//выбор пользователя - выйти и продолжить
	
	cout << "\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
	cout << "\tДобро пожаловать в наш торгово-развлекательный центр MALL!!!\n";
	cout << "\tПредлагаем Вам проехаться в лифте и посетить все этажи!\n\n";
	cout << "\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
	
	while (exit)//пока exit равен true
	{
		cout << "\nНажмите кнопку с номером этажа (от 0 до 5): ";
		cin >> fl;
	
		switch (fl)
		{
		case(parking):
			cout << "\aВы спустились в паркинг!!!" << endl;
			break;
	
		case(supermarket):
			cout << "\aВы на первом этаже!";
			cout << "\nЗдесь вы можете посетить наш супермаркет и купить продукты и товары для дома.\n\n";
			break;
	
		case(hardwareStores):
			cout << "\aВы на втором этаже!";
			cout << "\nЗдесь расположились магазины бытовой техники, IT  и мобильных телефонов.\n\n";
			break;
	
		case(boutiques):
			cout << "\aВы на третьем этаже!";
			cout << "\nЗдесь вас ждет незабываемый шопинг! Одежда, обувь, магазины косметики.\n\n";
			break;
	
		case(sportSpa):
			cout << "\aВы на четвертом этаже!";
			cout << "\nЗдесь вы можете посетить бассейн, каток, спортзалы, spa-салон!\n\n";
			break;
	
		case(clubRestaurantBar):
			cout << "\aВы на пятом этаже!";
			cout << "\nТут вы можете посетить ночной клуб, бар и ресторан!\n\n";
			break;
	
		default: cout << "\a\a\aОшибка! У нас только 5 этажей!\n\n";
		}
	
		cout << "Если хотите выйти на этом этаже, нажмите 0.\n";
		cout << "Продолжить увлекательную поездку - нажмите 1: ";
		cin >> exit;
	}
	*/
	#pragma endregion

	#pragma region Подсчет слов
	/*
	itsaWord isWord = NO;        // isWord равно YES, когда
								 // вводится слово, и NO, когда вводятся пробелы
	char ch;                     // считывание символа с клавиатуры
	int wordcount = 0;           // число слов
	cout << "Введите предложение: \n";
	do {
		ch = getche();             // ввод символа
		if (ch == ' ' || ch == '\r')  // если введен пробел,
		{
			if (isWord == YES)      // а до этого вводилось слово,
			{                        // значит, слово закончилось
				wordcount++;           // учет слова
				isWord = NO;           // сброс флага
			}
		}                          // в противном случае
		else                       // ввод слова продолжается
			if (isWord == NO)        // если начался ввод слова,
				isWord = YES;              // то устанавливаем флаг
	} while (ch != '\r');     // выход по нажатию Enter
	cout << "\nЧисло слов: " << wordcount << endl;
	*/
	#pragma endregion

	#pragma region Карточная игра №2
	/*
	card temp, chosen, prize;       // определение карт
	int position;
	card card1 = { 7, clubs };      // инициализация card1
	cout << "Карта 1: 7 треф\n";
	card card2 = { jack, hearts };  // инициализация card2
	cout << "Карта 2: валет червей\n";
	card card3 = { ace, spades };   // инициализация card3
	cout << "Карта 3: туз пик\n";
	prize = card3;                  // запоминаем карту 3
	cout << "Меняем местами карту 1 и карту 3\n";
	temp = card3; card3 = card1; card1 = temp;
	cout << "Меняем местами карту 2 и карту 3\n";
	temp = card3; card3 = card2; card2 = temp;
	cout << "Меняем местами карту 1 и карту 2\n";
	temp = card2; card2 = card1; card1 = temp;
	cout << "На какой позиции (1,2 или 3) теперь туз пик?\n";
	cin >> position;
	switch (position)
	{
	case 1: chosen = card1; break;
	case 2: chosen = card2; break;
	case 3: chosen = card3; break;
	}
	if (chosen.number == prize.number && // сравнение карт
		chosen.suit == prize.suit)
		cout << "Правильно! Вы выиграли!\n";
	else
	cout << "Неверно. Вы проиграли.\n ";
	*/
	#pragma endregion
	
	system("pause");
	return 0;
}
/*
void centimize(double *ptrd[])
{
	for (int j = 0; j < 5; j++)
		*ptrd[j] *= 2.54;
}

void centimize(double *ptrd)
{
	*ptrd *= 2.54;              
}
*/


void order(int *numb1, int *numb2)
{
	if (*numb1 > *numb2)   // если первое число больше, то меняем их местами
	{
		int temp = *numb1;
		*numb1 = *numb2;
		*numb2 = temp;
	}
}
void bsort(int* ptr, int n)
{
	int j, k;                           // индексы в нашем массиве
	for (int j = 0; j < n - 1; j++)     // внешний цикл
		for (int k = j + 1; k < n; k++) // внутренний цикл
			order(ptr + j, ptr + k);    // сортируем элементы
}