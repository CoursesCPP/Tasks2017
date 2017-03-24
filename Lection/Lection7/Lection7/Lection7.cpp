// Lection7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
   


using namespace std;

enum Suit { clubs, diamonds, hearts, spades };
// от 2 до 10 обычные числа
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

const int DISTRICTS = 4;
const int MONTHS = 3;

const int LIMIT = 100;  // размер массива

void display(double funsales[DISTRICTS][MONTHS])
{
	int d, m;

	cout << "\n\n";
	cout << "                        Месяц\n";
	cout << "                1         2         3";

	for (d = 0; d < DISTRICTS; d++)
	{
		cout << "\nОтдел " << d + 1;
		for (m = 0; m < MONTHS; m++)
		{
			cout << setw(10)
				 << setprecision(8)
				 << funsales[d][m];
		}
	}
}

struct part
{
	int modelnumber;
	int partnumber;
	float cost;
};

class Stack
{
private:
	//enum { MAX = 10 };  // немного нестандартный синтаксис
	static const int MAX = 10;
	int st[MAX];        // стек в виде массива
	int top;            // вершина стека
public:
	Stack() : top(0) // конструктор
	{ }

	void push(int var) // поместить в стек
	{
		//указывает на след. элемент, который становится вершиной стека
		st[++top] = var; 
	}
	int pop() // взять из стека
	{
		//сперва возвращается значение, а потом определяет новую вершину стека
		return st[top--];
	}
};

class Distance
{
private:
	int feet;
	float inches;
public:
	// конструктор без параметров
	Distance() : feet(0), inches(0.0)
	{ }
	// конструктор с двумя параметрами
	Distance(int ft, float in) : feet(ft), inches(in)
	{ }
	void getdist() // получение информации
	{
		cout << "\n  Введите футы: "; cin >> feet;
		cout << "  Введите дюймы: "; cin >> inches;
	}
	void showdist() const // показ информации
	{
		cout << feet << "\'-" << inches << '\"';
	}

	Distance operator+ (Distance d2) const
	{
		int f = feet + d2.feet;       // складываем футы
		float i = inches + d2.inches; // складываем дюймы
		if (i >= 12.0)                // если дюймов стало больше 12
		{
			i -= 12.0;                  // то уменьшаем дюймы на 12
			f++;                        // и увеличиваем футы на 1
		}
		return Distance(f, i);     // создаем и возвращаем временную переменную
	}

	bool operator< (Distance qwerty) const
	{
		float bf1 = feet + inches / 12;
		float bf2 = qwerty.feet + qwerty.inches / 12;
		return (bf1 < bf2) ? true : false;
	}

	void operator+= (Distance d2)
	{
		feet += d2.feet;      // складываем футы
		inches += d2.inches;  // складываем дюймы
		if (inches >= 12.0) // если дюймов больше 12
		{
			inches -= 12.0;     // то уменьшаем дюймы на 12
			feet++;             // увеличиваем футы на 1
		}
	}
};

class Counter
{
private:
	unsigned int count;              
public:
	Counter() : count(0)
	{  }

	Counter(int c) : count(c)
	{ }
	
	unsigned int get_count()         
	{
		return count;
	}
	
	Counter operator++ ()
	{
		return Counter(++count);	//недекларированная переменная
	}

	Counter operator++ (int)
	{
		return Counter(count++);
	}

	Counter operator-- ()
	{
		return Counter(--count);	//недекларированная переменная
	}

	Counter operator-- (int)
	{
		return Counter(count--);
	}
	/*
	Counter operator ++ ()
	{
	++count;
	Counter temp;
	temp.count = count;
	return temp;
	}
	*/

};

class card
{
private:
	int number;
	Suit suit;
public:
	void set(int n, Suit s) // установка значения
	{
		suit = s; number = n;
	}
	void display()          // показ карты
	{
		if (number >= 2 && number <= 10)
			cout << number;
		else
		{
			switch (number)
			{
			case jack: cout << 'J'; break;
			case queen: cout << 'Q'; break;
			case king: cout << 'K'; break;
			case ace: cout << 'A'; break;
			}
		}
		switch (suit)
		{
		case clubs: cout << static_cast<char>(5); break;   //Трефы
		case diamonds: cout << static_cast<char>(4); break;//Буби
		case hearts: cout << static_cast<char>(3); break;  //Черви
		case spades: cout << static_cast<char>(6); break;  //Пики
		}
	}
};

class String          
{
private:
	static const int Size = 80;		//максимальный размер строки
	char str[Size];					//массив для строки
public:
	// конструктор без параметров
	String() : str("")
	{ }
	
	// конструктор с одним параметром
	String(char s[])
	{
		strcpy(str, s);			// копируем s в str
	}

	// показ строки
	void display() const
	{
		cout << str;
	}
	// оператор сложения
	String operator+ (String ss) const
	{
		String temp;  // временная переменная
		if (strlen(str) + strlen(ss.str) < Size)
		{
			strcpy(temp.str, str);    // копируем содержимое первой строки
			strcat(temp.str, ss.str); // добавляем содержимое второй строки
		}
		else
		{
			cout << "\nПереполнение!";
			exit(1);
		}
		return temp;  // возвращаем результат
	}
	// получение строки
	void getstr()
	{
		cin.get(str, Size);
	}

	// оператор сравнения
	bool operator== (String ss) const
	{
		/*
		bool flag;
		if (strcmp(str, ss.str) == 0)
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
		return flag;
		*/
		return (strcmp(str, ss.str) == 0) ? true : false;
	}

	//перевод строки к обычному типу
	operator char* ()
	{
		return str;
	}
};

class safearray
{
	// демонстрация создания безопасного массива, проверяющего
	// свои индексы при использовании
	// используется общая функция для установки и получения значения
private:
	int arr[LIMIT];
public:
	// установка значения элемента массива
	void putelem(int n, int value)
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\nОшибочный индекс!"; exit(1);
		}
		arr[n] = value;
	}
	// получение значения элемента массива
	int getelem(int n) const
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\nОшибочный индекс!"; exit(2);
		}
		return arr[n];
	}

	// обратите внимание, что функция возвращает ссылку!
	int& access(int n)
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\nОшибочный индекс!"; 
			exit(3);
		}
		return arr[n];
	}

	// обратите внимание, что функция возвращает ссылку!
	int& operator[] (int n)
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\nОшибочный индекс!"; exit(1);
		}
		return arr[n];
	}
};

class DistMetr         // класс английских мер длины
{
private:
	const float MTF = 3.280833F;    // коэффициент перевода метров в футы
	int feet;
	float inches;
public:
	// конструктор без параметров
	DistMetr() : feet(0), inches(0.0)
	{ }
	// конструктор с одним параметром,
	// переводящий метры в футы и дюймы
	// или конструктор преобразования
	DistMetr(float meters)
	{
		float fltfeet = MTF * meters;     // переводим в футы
		feet = int(fltfeet);              // берем число полных футов
		inches = 12 * (fltfeet - feet);   // остаток - это дюймы
	}

	// конструктор с двумя параметрами
	DistMetr(int ft, float in) : feet(ft), inches(in)
	{ }
	// получение информации от пользователя
	void getdist()
	{
		cout << "\nВведите футы: "; cin >> feet;
		cout << "Введите дюймы: ";  cin >> inches;
	}
	// показ информации
	void showdist() const
	{
		cout << feet << "\'-" << inches << '\"';
	}

	// оператор перевода для получения метров из футов
	operator float() const
	{
		float fracfeet = inches / 12;           // переводим дюймы в футы
		fracfeet += float(feet);   // добавляем целые футы
		return fracfeet / MTF;                  // переводим в метры
	}
};

class time12
{
private:
	bool pm;
	int hrs;
	int mins;
public:
	time12() : pm(true), hrs(0), mins(0)
	{ }
	time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m)
	{ }
	void display() const
	{
		cout << hrs << ':';
		if (mins < 10)
			cout << '0';
		cout << mins << ' ';
		string am_pm = pm ? "p.m." : "a.m.";
		cout << am_pm;
	}
};

class time24
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	time24() : hours(0), minutes(0), seconds(0)
	{ }
	time24(int h, int m, int s) : hours(h), minutes(m), seconds(s)
	{ }
	void display() const
	{
		if (hours < 10) cout << '0';
		cout << hours << ':';
		if (minutes < 10) cout << '0';
		cout << minutes << ':';
		if (seconds < 10) cout << '0';
		cout << seconds;
	}

	operator time12 () const
	{
		int hrs24 = hours;
		bool pm = hours < 12 ? false : true;

		int roundMins = seconds < 30 ? minutes : minutes + 1;
		if (roundMins >= 60)
		{
			roundMins = 0;
			++hrs24;
			if (hrs24 == 12 || hrs24 == 24)
				pm = (pm == true) ? false : true;
		}
		int hrs12 = (hrs24 < 13) ? hrs24 : (hrs24 - 12);
		if (hrs12 == 0)
		{
			hrs12 = 12;
			pm = false;
		}
		return time12(pm, hrs12, roundMins);
	}
};

void fancyDistMetr(DistMetr d)
{
	cout << "(в футах и дюймах) = ";
	d.showdist();
	cout << endl;
}

class scrollbar
{
private:
	int size;
	mutable string owner;
public:
	scrollbar(int sz, string own) : size(sz), owner(own)
	{ }

	void setSize(int sz)
	{
		size = sz;
	}

	void setOwner(string own) const
	{
		owner = own;
	}

	int getSize() const
	{
		return size;
	}

	string getOwner() const
	{
		return owner;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

#pragma region Среднее арифметическое элементов массива
	/*
	const int SIZE = 6;
	double num[SIZE];
	double total = 0;

	cout << "Введите вещественные числа:\n";
	for (int i = 0; i < SIZE; i++)
	{
		cin >> num[i];
		total += num[i];
	}
	double mean = total / SIZE;
	cout << "Среднее арифметическое: " << mean << endl;
	*/
#pragma endregion

#pragma region Дни и месяцы
	/*
	int month, day, total_days;
	int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cout << "\nВведите месяц (от 1 до 12): ";
	cin >> month;
	cout << "\nВведите день (от 1 до " << days_per_month[month-1] << "): ";
	cin >> day;
	total_days = day;
	for (int j = 0; j < (month - 1); j++)
	{
		total_days += days_per_month[j];
	}
	cout << "Общее число дней с начала года: " << total_days << endl;
	*/
#pragma endregion

#pragma region Многомерные массивы
	/*
	int d, m;
	double sales[DISTRICTS][MONTHS];

	cout << endl;
	for (d = 0; d < DISTRICTS; d++)
	for (m = 0; m < MONTHS; m++)
	{
			cout << "Введите объем продаж для отдела " << d + 1;
			cout << ", за месяц " << m + 1 << ": ";
			cin >> sales[d][m];
	}
	
	
	cout << "\n\n";
	cout << "                        Месяц\n";
	cout << "                1         2         3";
	for (d = 0; d < DISTRICTS; d++)
	{
		cout << "\nОтдел " << d + 1;
		for (m = 0; m < MONTHS; m++)
		{
			cout  << setprecision(8)  //8 знаков 
			<< setw(10)			//ширина вывода по 10 символов
			<< sales[d][m];
		}
	}
	cout << endl;
	*/
#pragma endregion

#pragma region Передача в функцию
	/*
	double sales[DISTRICTS][MONTHS] =
	{
	{ 1432.07,   234.50,   654.01 },
	{ 322.00, 13838.32, 17589.88 },
	{ 9328.34,   934.00,  4492.30 },
	{ 12838.29,  2332.63,    32.93 }
	};

	display(sales);
	cout << endl;
	*/
#pragma endregion

#pragma region Массив со структурами
	/*
	const int SIZE = 4;
	int n;
	part apart[SIZE];

	for (n = 0; n < SIZE; n++)
	{
		cout << endl;
		cout << "Введите номер модели: ";
		cin >> apart[n].modelnumber;
		cout << "Введите номер части: ";
		cin >> apart[n].partnumber;
		cout << "Введите стоимость: ";
		cin >> apart[n].cost;
	}
	cout << endl;
	for (n = 0; n < SIZE; n++)
	{
		cout << "Модель " << apart[n].modelnumber;
		cout << "  Часть  " << apart[n].partnumber;
		cout << "  Стоимость  " << apart[n].cost << endl;
	}
	*/
#pragma endregion

#pragma region Массив как член класса
	/*
	Stack s1;
	s1.push(11);
	s1.push(22);
	s1.push(33);
	s1.push(44);
	s1.push(55);
	s1.push(66);
	cout << "1: " << s1.pop() << endl;
	cout << "2: " << s1.pop() << endl;
	cout << "3: " << s1.pop() << endl;
	cout << "4: " << s1.pop() << endl;
	cout << "5: " << s1.pop() << endl;
	cout << "6: " << s1.pop() << endl;
	*/
#pragma endregion
	
#pragma region Массив объектов
	/*
	Distance dist[100]; // массив переменных
	int n = 0;             // счетчик данных
	char ans;              // ответ пользователя (y/n)
	cout << endl;
	do
	{
		cout << "Введите длину номер " << n + 1;
		dist[n++].getdist();      // получаем и сохраняем длину
		cout << "Продолжить ввод (y/n)?: ";
		cin >> ans;
	} while (ans != 'n');            // продолжать, пока не будет введено 'н'
	
	// показываем все введенное
	for (int j = 0; j < n; j++)
	{
		cout << "\nДлина номер " << j + 1 << " : ";
		dist[j].showdist();
	}
	cout << endl;
	*/
#pragma endregion

#pragma region Карты
	/*
	card deck[52];
	int j;
	
	cout << endl;
	for (j = 0; j < 52; j++)   // создаем упорядоченную колоду карт
	{
		int num = (j % 13) + 2;
		Suit su = Suit(j / 13);
		deck[j].set(num, su);
	}
	// показываем исходную колоду
	cout << "Исходная колода:\n";
	for (j = 0; j < 52; j++)
	{
		deck[j].display();
		cout << "  ";
		if (!((j + 1) % 13)) // начинаем новую строку после каждой 13-й карты
			cout << endl;
	}
	srand(time(NULL));     // инициализируем генератор случайных чисел
	for (j = 0; j < 52; j++)
	{
		int k = rand() % 52;     // выбираем случайную карту
		card temp = deck[j];     // и меняем ее с текущей
		deck[j] = deck[k];
		deck[k] = temp;
	}
	// показываем перемешанную колоду
	cout << "\nПеремешанная колода:\n";
	for (j = 0; j < 52; j++)
	{
		deck[j].display();
		cout << "  ";
		if (!((j + 1) % 13)) // начинаем новую строку после каждой 13-й карты
			cout << endl;
	}
	*/
#pragma endregion

#pragma region Строки
	/*
	const int MAX = 2000; // максимальная длина строки
	char str[MAX];        // сама строка
	cout << "\nВведите строку:\n";
	cin.get(str, MAX, '$');
	cout << "Вы ввели:\n" << str << endl;
	*/
#pragma endregion

#pragma region String
	/*
	string s1("Рыба");
	string s2 = "Мясо";
	string s3;
	
	s3 = s1;
	cout << "s3 = " << s3 << endl;
	
	s3 = "Ни " + s1 + " ни ";
	s3 += s2;	// s3 = s3 + s2
	cout << "s3 = " << s3 << endl;
	
	s1.swap(s2);
	cout << s1 << " не " << s2 << endl;
	*/
#pragma endregion

#pragma region String2
	/*
	string full_name, nickname, address;
	string greeting("Здравствуйте, ");
	
	cout << "Введите Ваше имя: ";
	getline(cin, full_name);
	cout << "Ваше имя: " << full_name << endl;
	
	cout << "Введите Ваш псевдоним: ";
	cin >> nickname;
	
	greeting += nickname;
	cout << greeting << endl;
	
	cout << "Введите Ваш адрес в несколько строк\n";
	cout << "Окончание ввода символ '$'\n";
	getline(cin, address, '$');
	cout << "Ваш адрес: " << address << endl;
	*/
#pragma endregion

#pragma region Поиск в строках
	/*
	string s1 = "В лесу родилась елочка, в лесу она росла.";
	int n;
	n = s1.find("елочка");
	cout << "елочка найдена: " << n << endl;
	
	n = s1.find_first_of("у");
	cout << "Первый из у: " << n << endl;
	
	n = s1.find_first_not_of("абвгдАБВГД");
	cout << "Первый не из : " << n << endl;
	*/
#pragma endregion

#pragma region Изменение частей
	/*
	string s1("Все хорошо, прекрасная маркиза.");
	string s2("принцесса");
	string s3("Приветствую ");
	
	s1.erase(0, 12);              // убираем "Все хорошо, "
	s1.replace(11, 7, s2);        // заменяем "маркиза" на "принцесса"
	s1.insert(0, s3);             // вставляем "Приветствую, "
	s1.erase((s1.size()-1), 1);   // убираем '.'
	s1.append(3, '!');            // добавляем '!!!'
	
	int x = s1.find(' ');         // ищем пробелы
	while (x < s1.size())         // цикл по всем пробелам
	{
		s1.replace(x, 1, "/");      // заменяем пробел на '/'
		x = s1.find(' ');           // ищем следующий пробел
	}	
	cout << "s1: " << s1 << endl;
	*/
#pragma endregion

#pragma region Доступ к символам string
	/*
	char charray[80];
	string word;
	
	cout << "Введите слово: ";
	cin >> word;
	int wlen = word.length();     // длина строки
	cout << "По одному символу: ";
	for (int j = 0; j < wlen; j++)
		cout << word.at(j);       // тут будет проверка на выход за пределы строки
		//cout << word[ j ];    // а тут проверки не будет
	word.copy(charray, wlen); // копируем строку в массив
	charray[wlen] = 0;
	cout << "\nМассив содержит: " << charray << endl;
	*/
#pragma endregion

#pragma region Перегрузка унарной операции
	/*
	Counter c1, c2;                     
	
	cout << "\nc1=" << c1.get_count();  
	cout << "\nc2=" << c2.get_count();
	
	++c1;			       
	++c2;			       
	++c2;			       
	
	cout << "\nc1=" << c1.get_count();  
	cout << "\nc2=" << c2.get_count() << endl;

	c1++;
	c2++;
	cout << "\nc1=" << c1.get_count();
	cout << "\nc2=" << c2.get_count() << endl;

	c1--;
	c2--;

	cout << "\nc1=" << c1.get_count();
	cout << "\nc2=" << c2.get_count() << endl;

	--c1;
	--c2;
	cout << "\nc1=" << c1.get_count();  
	cout << "\nc2=" << c2.get_count() << endl;
	*/
	/*

	cout << "\nc1=" << c1.get_count();
	cout << "\nc2=" << c2.get_count();

	++c1;                                 //c1=1
	c2 = ++c1;                            //c1=2, c2=2

	cout << "\nc1=" << c1.get_count();
	cout << "\nc2=" << c2.get_count() << endl;
	
	*/
	/*
	Counter c1, c2;                        // определяем переменные
	
	cout << "\nc1 = " << c1.get_count(); // выводим на экран
	cout << "\nc2 = " << c2.get_count();
	
	++c1;                                  // увеличиваем c1
	c2 = ++c1;                             // c1=2, c2=2
	
	cout << "\nc1 = " << c1.get_count(); // снова показываем значения
	cout << "\nc2 = " << c2.get_count();
	
	c2 = c1++;
	
	cout << "\nc1 = " << c1.get_count(); // и снова
	cout << "\nc2 = " << c2.get_count() << endl;
	*/
#pragma endregion

#pragma region Дистанции перегрузка арифметических операций
	
	Distance dist1, dist3, dist4;  // определяем переменные
	dist1.getdist();               // получаем информацию
	
	Distance dist2(11, 6.25);      // определяем переменную с конкретным значением
	
	dist3 = dist1 + dist2;         // складываем две переменные
	
	dist4 = dist1 + dist2 + dist3; // складываем несколько переменных
	
								   // показываем, что же у нас получилось
	cout << "dist1 = "; dist1.showdist(); cout << endl;
	cout << "dist2 = "; dist2.showdist(); cout << endl;
	cout << "dist3 = "; dist3.showdist(); cout << endl;
	cout << "dist4 = "; dist4.showdist(); cout << endl;
	
#pragma endregion

#pragma region Объединение строк
    /*
	String s1 = "С Рождеством!фывфывфывфывфывфывфывффывфыв\n"; // используем конструктор с параметром
	String s2 = "С Новым годом!фывфывфывфывфывфывфывфывф\n";   // используем конструктор с параметром
	String s3;                      // используем конструктор без параметров
	
	s1.display();
	s2.display();
	s3.display();
	
	cout << endl;
	s3 = s1 + s2;     // присваиваем строке s3 результат сложени¤ строк s1 и s2
	
	s3.display();     // показываем результат
	cout << endl;
	*/
#pragma endregion

#pragma region Дистанции перегрузка <
    /*
	Distance dist1;            // определ¤ем переменную
	dist1.getdist();         // получаем длину от пользовател¤
	
	Distance dist2(6, 2.5); // определ¤ем и инициализируем переменную
	
							// показываем длины
	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	
	// используем наш оператор
	if (dist1 < dist2)
		cout << "\ndist1 меньше чем dist2";
	else
	cout << "\ndist1 больше или равно чем dist2";
	cout << endl;
	*/
#pragma endregion

#pragma region Строки перегрузка ==
	/*
	String s1 = "yes";
	String s2 = "no";
	String s3;
	
	cout << "\nВведите 'yes' или 'no': ";
	s3.getstr();        // получаем строку от пользователя
	
	if (s3 == s1)       // сравниваем со строкой 'yes'
	cout << "Вы ввели 'yes'\n";
	else
	{
		if (s3 == s2)       // сравниваем со строкой 'no'
			cout << "Вы ввели 'no'\n";
		else
			cout << "Следуйте инструкциям!\n";
	}
	*/
#pragma endregion

#pragma region Дистанции перегрузка +=
	
	Distance dist1;              // определяем переменную
	dist1.getdist();           // и вводим информацию
	cout << "\ndist1 = "; dist1.showdist();
	
	Distance dist2(11, 6.25); // описываем и инициализируем другую переменную
	cout << "\ndist2 = "; dist2.showdist();
	
	dist1 += dist2;              // dist1 = dist1 + dist2
	cout << "\nПосле добавления:";
	
	cout << "\ndist1 = "; dist1.showdist();
	cout << endl;
	
#pragma endregion

#pragma region Безопасный массив
	/*
	safearray sa1;
	
	// задаем значения элементов
	for (int j = 0; j < LIMIT; j++)
		sa1.putelem(j, j * 10);
	
	// показываем элементы
	for (int j =0; j<LIMIT; j++)
	{
		int temp = sa1.getelem(j);
		cout << "Элемент " << j << " равен " << temp << endl;
	}
	
	
	// задаем значения элементов
	for (int j = 0; j < LIMIT; j++)
		sa1.access(j) = j * 7; // используем функцию слева от знака =

								// показываем элементы
	for (int j = 0; j < LIMIT; j++)
	{
		int temp = sa1.access(j); // используем функцию справа от знака =
		cout << "Элемент " << j << " равен " << temp << endl;
	}
	
	
	// задаем значения элементов
	for (int j = 0; j < LIMIT; j++)
		sa1[j] = j * 5;    // используем функцию слева от знака =

							// показываем элементы
	for (int j = 0; j < LIMIT; j++)
	{
		int temp = sa1[j]; // используем функцию справа от знака =
		cout << "Элемент " << j << " равен " << temp << endl;
	}
	*/
#pragma endregion

#pragma region Преобразования объектов в основные типы
	/*
	float mtrs;
	DistMetr dist1 = 2.35F; // используется конструктор, переводящий метры в футы и дюймы
	cout << "\ndist1 = "; 
	dist1.showdist();
	mtrs = static_cast<float>(dist1); // используем оператор перевода в метры
	cout << "\ndist1 = " << mtrs << " meters\n";
	DistMetr dist2(5, 10.25); // используем конструктор с двумя параметрами
	mtrs = dist2;	// неявно используем перевод типа
	cout << "\ndist2 = " << mtrs << " meters\n";
	//dist2 = mtrs;  //а вот это ошибка - так делать нельзя
	*/
#pragma endregion

#pragma region Преобразование строк в объекты String
	/*
	String s1;                 // используем конструктор без параметров
	char xstr[] = "Ура, товарищи! "; // создаем обычную строку
	s1 = xstr;                 // неявно используем конструктор с одним параметром
	s1.display();            // показываем строку
	String s2 = "Мы победим!"; // снова используем конструктор с параметром
	cout << static_cast<char*>(s2); // используем оператор перевода типа
	cout << endl;
	*/
#pragma endregion

#pragma region Преобразованиея объектов одного класса в другие
	/*
	int h, m, s;
	
	while (true)
	{
		cout << "Введите время в 24-часовом формате: \n";
		cout << "  Часы (от 0 до 23): "; 
		cin >> h;
		if (h > 23)
			exit (1);
		cout << "  Минуты: "; cin >> m;
		cout << "  Секунды: "; cin >> s;
	
		time24 t24(h, m, s);
		cout << "Исходное время: ";
		t24.display();
	
		time12 t12 = t24;
	
		cout << "\nВ 12-часовом формате: ";
		t12.display();
		cout << "\n\n";
	}
	*/
#pragma endregion

#pragma region Explicit
	/*
	DistMetr dist1(2.35F);
	DistMetr dist1 = 2.35F;
	cout << "\ndist1 = "; 
	dist1.showdist();
	float mtrs = 3.0F;
	cout << "\nDist1 ";
	fancyDistMetr(mtrs);
	*/
#pragma endregion

#pragma region Mutable
	/*
	const scrollbar sbar(60, "Приложение 1");
	//sbar.setSize ( 100 );
	sbar.setOwner("Приложение 2");
	cout << sbar.getSize() << ", " << sbar.getOwner() << endl;
	*/
#pragma endregion

	system("pause");
    return 0;
}

