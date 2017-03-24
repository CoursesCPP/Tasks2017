// Lection8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "msoftcon.h"
#include <string>

using namespace std;

const int LEN = 80;       // максимальная длина имени
enum posneg { pos, neg };

class Counter                 //базовый класс
{	
protected:
	unsigned int count;       //счетчик
public:
	Counter() : count(0) //конструктор без аргументов
	{
		cout << "Я в конструкторе без аргументов counter\n";
	}

	Counter(int c) : count(c)
	{
		cout << "Я в конструкторе counter\n";
	}
	unsigned int get_count() const
	{
		return count;
	}       
	Counter operator++ ()    
	{
		return Counter(++count);
	}
};

class CountDn : public Counter  //производный класс
{
public:
	CountDn() : Counter()        
	{
		cout << "Я в конструкторе без аргументов counterDn\n";
	}
	CountDn(int c) : Counter(c)
	{
		cout << "Я в конструкторе counterDn\n";
	}
	CountDn operator-- ()           
	{
		return CountDn(--count);
	}
};

class Stack
{
protected:              
	//enum { MAX = 3 };     // размер стека
	static const int MAX = 3;
	int st[MAX];          // данные, хран¤щиес¤ в стеке
	int top;              // индекс последнего элемента в стеке
public:
	Stack()            // конструктор
	{
		top = -1; 
	}
	void push(int var) // помещение числа в стек
	{
		st[++top] = var;
	}
	int pop()           // извлечение числа из стека
	{
		return st[top--];
	}
};

class Stack2 : public Stack
{
public:
	void push(int var)      // помещение числа в стек
	{
		if (top >= MAX - 1)  // если стек полон, то ошибка
		{
			cout << "\nОшибка: стек полон";
			system("pause"); 
			exit(1);
		}
		Stack::push(var);   // вызов функции push класса Stack
	}
	int pop()                // извлечение числа из стека
	{
		if (top < 0)         // если стек пуст, то ошибка
		{
			cout << "\nОшибка: стек пуст\n"; 
			system("pause");
			exit(1);
		}
		return Stack::pop(); // вызов функции pop класса Stack
	}
};

/*
class Distance 
{
protected:   
	int feet;
	float inches;
public:
	Distance() : feet(0), inches(0.0)
	{ }

	Distance(int ft, float in) : feet(ft), inches(in)
	{ }

	void getdist()
	{
		cout << "\nВведите футы: "; cin >> feet;
		cout << "Введите дюймы: "; cin >> inches;
	}

	void showdist()
	{
		cout << feet << "\'" << inches << '\"';
	}
};


class DistSign : public Distance // добавление знака к длине
{
private:
	posneg sign;                 // значение может быть pos или neg
public:

	DistSign() : Distance()
	{
		sign = pos;
	}

	
	DistSign(int ft, float in, posneg sg = pos) : Distance(ft, in) 
	{
		sign = sg;   // начальная установка знака
	}    

	void getdist()           
	{
		Distance::getdist(); 
		char ch;               
		cout << "Введите знак (+ или -): "; cin >> ch;
		sign = (ch == '+') ? pos : neg;
	}

	void showdist()    
	{
		cout << ((sign == pos) ? "(+)" : "(-)");
		Distance::showdist();
	}
};
*/
/*
class employee            
{
private:
	char name[LEN];       
	unsigned long number; 
public:
	void getdata()
	{
		cout << "\n  Введите фамилию: "; cin >> name;
		cout << "  Введите номер: ";     cin >> number;
	}
	void putdata() const
	{
		cout << "\n  Фамилия: " << name;
		cout << "\n  Номер: " << number;
	}
};

class manager : public employee 
{
private:
	char title[LEN];    
	double dues;         //сумма взносов в гольф-клуб
public:
	void getdata()
	{
		employee::getdata();
		cout << "  Введите должность: "; cin >> title;
		cout << "  Введите сумму взносов в гольф-клуб: "; cin >> dues;
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n  Должность: " << title;
		cout << "\n  Сумма взносов в гольф-клуб: " << dues;
	}
};

class scientist : public employee 
{
private:
	int pubs;                     // количество публикаций
public:
	void getdata()
	{
		employee::getdata();
		cout << "  Введите количество публикаций: "; cin >> pubs;
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n  Количество публикаций: " << pubs;
	}
};

class laborer : public employee   // рабочий
{
};

class foreman : public laborer // бригадир
{
private:
	float quotas;               // норма выработки
public:
	void getdata()
	{
		laborer::getdata();
		cout << "  Введите норму выработки: "; cin >> quotas;
	}
	void putdata() const
	{
		laborer::putdata();
		cout << "\n  Норматив: " << quotas;
	}
};
*/

class shape // базовый класс
{
protected:
	int xCo, yCo;     // координаты фигуры
	color fillcolor;  // цвет
	fstyle fillstyle; // стиль изображения
public:
	// конструктор без аргументов
	shape() : xCo(0), yCo(0), fillcolor(cWHITE), fillstyle(SOLID_FILL)
	{ }
	// конструктор с пятью аргументами
	shape(int x, int y, color fc, fstyle fs) : xCo(x), yCo(y), fillcolor(fc), fillstyle(fs)
	{ }
	// функция установки цвета и стиля
	void draw() const
	{
		set_color(fillcolor);
		set_fill_style(fillstyle);
	}
};

class circle : public shape
{
private:
	int radius; // радиус, а xCo и yCo будут координатами центра
public:
	// конструктор без параметров
	circle() : shape(), radius(1)
	{ }
	// конструктор с пятью параметрами
	circle(int x, int y, int r, color fc, fstyle fs) : shape(x, y, fc, fs), radius(r)
	{ }
	// функция рисования окружности
	void draw() const
	{
		shape::draw();
		draw_circle(xCo, yCo, radius);
	}
};

class rect : public shape
{
private:
	int width, height; // ширина и высота, а xCo и yCo будут координатами верхнего правого угла
public:
	// конструктор без параметров
	rect() : shape(), height(0), width(0)
	{ }
	// конструктор с шестью параметрами
	rect(int x, int y, int h, int w, color fc, fstyle fs) : shape(x, y, fc, fs), height(h), width(w)
	{ }
	// функция рисования прямоугольника
	void draw() const
	{
		shape::draw();
		draw_rectangle(xCo, yCo, xCo + width, yCo + height);
		// нарисуем диагональ
		set_color(cWHITE);
		draw_line(xCo, yCo, xCo + width, yCo + height);
	}
};

class tria : public shape
{
private:
	int height; // высота пирамиды, а xCo и yCo будут координатами вершины
public:
	// конструктор без параметров
	tria() : shape(), height(0)
	{ }
	// конструктор с пятью параметрами
	tria(int x, int y, int h, color fc, fstyle fs) : shape(x, y, fc, fs), height(h)
	{ }
	// функция рисования пирамиды
	void draw() const
	{
		shape::draw();
		draw_pyramid(xCo, yCo, height);
	}
};

class A                // базовый класс
{
private:             // тип доступа к данным совпадает с типом
	int privdataA;     // доступа к функциям
protected:
	int protdataA;
public:
	int pubdataA;
};

class B : public A     // public наследование
{
public:
	void funct()
	{
		int a;
		//a = privdataA; // ошибка, нет доступа
		a = protdataA; // так можно
		a = pubdataA;  // так можно
	}
};

class C : private A    // private наследование
{
public:
	void funct()
	{
		int a;
		//a = privdataA; // ошибка, нет доступа
		a = protdataA; // так можно
		a = pubdataA;  // так можно
	}
};

/*
#pragma region Множественное наследование

	class student             // сведения об образовании
	{
	private:
		char school[LEN];   // название учебного заведения
		char degree[LEN];   // уровень образования
	public:
		void getedu()
		{
			cout << "  Введите название учебного заведения: ";
			cin >> school;
			cout << "  Введите степень высшего образования\n";
			cout << "  (неполное высшее, бакалавр, магистр, кандидат наук): ";
			cin >> degree;
		}
		void putedu() const
		{
			cout << "\n  Учебное заведение: " << school;
			cout << "\n  Степень: " << degree;
		}
	};
	
	class employee            // некий сотрудник
	{
	private:
		char name[LEN];     // имя сотрудника
		unsigned long number; // номер сотрудника
	public:
		void getdata()
		{
			cout << "\n  Введите фамилию: "; cin >> name;
			cout << "  Введите номер: ";     cin >> number;
		}
		void putdata() const
		{
			cout << "\n  Фамилия: " << name;
			cout << "\n  Номер: " << number;
		}
	};
	
	class manager : private employee, private student // менеджер
	{
	private:
		char title[LEN];    // должность сотрудника
		double dues;          // сумма взносов в гольф-клуб
	public:
		void getdata()
		{
			employee::getdata();
			cout << "  Введите должность: "; cin >> title;
			cout << "  Введите сумму взносов в гольф-клуб: "; cin >> dues;
			student::getedu();
		}
		void putdata() const
		{
			employee::putdata();
			cout << "\n  Должность: " << title;
			cout << "\n  Сумма взносов в гольф-клуб: " << dues;
			student::putedu();
		}
	};
	
	class scientist : private employee, private student // ученый
	{
	private:
		int pubs;             // количество публикаций
	public:
		void getdata()
		{
			employee::getdata();
			cout << "  Введите количество публикаций: "; cin >> pubs;
			student::getedu();
		}
		void putdata() const
		{
			employee::putdata();
			cout << "\n  Количество публикаций: " << pubs;
			student::putedu();
		}
	};
	
	class laborer : public employee // рабочий
	{
	};
	
#pragma endregion
*/
class Type                  // Тип древесины
{
private:
	string dimensions;
	string grade;
public:
	// конструктор без параметров
	Type() : dimensions("N/A"), grade("N/A")
	{ }
	// конструктор с двумя параметрами
	Type(string di, string gr) : dimensions(di), grade(gr)
	{ }
	void gettype()        // запрос информации у пользователя
	{
		cout << "  Введите номинальные размеры (2x4 и т.д.): ";
		cin >> dimensions;
		cout << "  Введите сорт (необработанная, брус и т.д.): ";
		cin >> grade;
	}
	void showtype()       // показ информации
	{
		cout << "\n  Размеры: " << dimensions;
		cout << "\n  Сорт: " << grade;
	}
};

class Distance              // английские меры длины
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
	void getdist()        // запрос информации у пользователя
	{
		cout << "  Введите футы: "; cin >> feet;
		cout << "  Введите дюймы: "; cin >> inches;
	}
	void showdist() const // показ информации
	{
		cout << feet << "\'-" << inches << '\"';
	}
};

class Lumber : public Type, public Distance
{
private:
	int quantity;           // количество
	double price;           // цена за штуку
public:
	// конструктор без параметров
	Lumber() : Type(), Distance(), quantity(0), price(0.0)
	{ }
	// конструктор с шестью параметрами
	Lumber(string di, string gr, // параметры для Type
		int ft, float in,     // параметры для Distance
		int qu, float prc) : // наши собственные параметры
		Type(di, gr),      // вызов конструктора Type
		Distance(ft, in),  // вызов конструктора Distance
		quantity(qu), price(prc) // вызов наших конструкторов
	{ }
	void getlumber()
	{
		Type::gettype();
		Distance::getdist();
		cout << "  Введите количество: "; cin >> quantity;
		cout << "  Введите цену: "; cin >> price;
	}
	void showlumber()
	{
		Type::showtype();
		cout << "\n  Длина: ";
		Distance::showdist();
		cout << "\n  Стоимость " << quantity << " штук: " << (price * quantity) << " рублей";
	}
};

class D
{
public:
	void show() { cout << " Класс D\n"; }
};
class E
{
public:
	void show() { cout << " Класс E\n"; }
};
class F : public D, public E
{
};

class String
{
private:
	char* str;          // указатель на строку
public:
	String(char* s)  // конструктор с одним параметром
	{
		str = new char[strlen(s) + 1]; // выделяем необходимую пам¤ть
		strcpy(str, s);             // копируем строку
	}
	~String()         // деструктор
	{
		cout << "Удаляем строку\n";
		delete[] str; // освобождаем память
	}
	void display()    // покажем строку на экране
	{
		cout << str << endl;
	}
};

class person // класс человек
{
private:
	char name[40];      // имя человека
public:
	void setName()       // установка имени
	{
		cout << "Введите имя: ";
		cin >> name;
	}
	void printName()     // показ имени
	{
		cout << "\n  Имя: " << name;
	}
	string getName()  // получение имени
	{
		return name;
	}
};

struct link     //элемент списка
{
	int data;   //некоторые данные
	link* next; //указатель на следующую структуру
};

class linklist  //список
{
private:
	link* first;
public:
	linklist()            // конструктор без параметров
	{
		first = NULL;
	}     // первого элемента пока нет

	void additem(int d) // добавление элемента
	{
		link* newlink = new link;      // выделяем память
		newlink->data = d;             // запоминаем данные
		newlink->next = first;         // запоминаем значение first
		first = newlink;               // first теперь указывает на новый элемент
	}

	void display()
	{
		link* current = first;           // начинаем с первого элемента
		while (current)                 // пока есть данные
		{
			cout << current->data << endl; // печатаем данные
			current = current->next;       // двигаемся к следующему элементу
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

#pragma region Counter наследование
	/*
	CountDn c1;                           // объект с1
	cout << "\n c1=" << c1.get_count() << endl;   //вывод на печать
	++c1; ++c1; ++c1;                     //увеличиваем c1 три раза
	cout << "\n c1=" << c1.get_count() << endl;   //вывод на печать
	--c1; --c1; //уменьшаем c1 два раза
	cout << "\n c1=" << c1.get_count() << endl;
	*/
#pragma endregion

#pragma region Вызов конструктора базового класса
	/*
	CountDn c1;                            
	CountDn c2(100);

	cout << "\nc1 = " << c1.get_count(); 
	cout << "\nc2 = " << c2.get_count() << endl;

	++c1; ++c1; ++c1;                      
	cout << "\nc1 = " << c1.get_count() << endl; 

	--c2; --c2;                            
	cout << "c2 = " << c2.get_count() << endl;   

	CountDn c3 = --c2;                   // создаем переменную c3 на основе c2
	cout << "\nc3 = " << c3.get_count() << endl;
	*/
#pragma endregion

#pragma region Стек перегруженные методы
	/*
	Stack2 s1;

	s1.push(11); // поместим в стек несколько чисел
	s1.push(22);
	s1.push(33);
	s1.push(44);

	cout << endl << s1.pop(); // заберем числа из стека
	cout << endl << s1.pop();
	cout << endl << s1.pop();
	system("pause");
	cout << endl << s1.pop() << endl;
	*/
#pragma endregion

#pragma region Дистанции со знаками
	/*
	DistSign alpha;                   // используем конструктор по умолчанию
	alpha.getdist();                // получаем данные от пользователя

	DistSign beta(11, 6.25);       // конструктор с двумя аргументами

	DistSign gamma(100, 5.5, neg); // конструктор с тремя аргументами

								   // выводим данные для всех переменных
	cout << "\nA = "; alpha.showdist();
	cout << "\nB = "; beta.showdist();
	cout << "\nC = "; gamma.showdist();
	cout << endl;
	*/
#pragma endregion

#pragma region Employee
	/*
	manager m1, m2;
	scientist s1;
	laborer l1;
	// введем информацию о нескольких сотрудниках
	cout << endl;
	cout << "\nВвод информации о первом менеджере";
	m1.getdata();
	cout << "\nВвод информации о втором менеджере";
	m2.getdata();
	cout << "\nВвод информации о первом ученом";
	s1.getdata();
	cout << "\nВвод информации о первом рабочем";
	l1.getdata();
	// выведем полученную информацию на экран
	cout << "\nИнформация о первом менеджере";
	m1.putdata();
	cout << "\nИнформация о втором менеджере";
	m2.putdata();
	cout << "\nИнформация о первом ученом";
	s1.putdata();
	cout << "\nИнформация о первом рабочем";
	l1.putdata();
	cout << endl;
	*/
#pragma endregion

#pragma region Геометрические фигуры
	/*
	init_graphics(); // инициализируем систему отображения графики

	circle cir(40, 12, 5, cBLUE, X_FILL);      // создаем круг
	rect rec(12, 7, 10, 15, cRED, SOLID_FILL); // создаем прямоугольник
	tria tri(60, 7, 11, cGREEN, MEDIUM_FILL);  // создаем пирамиду

											   // рисуем все наши фигуры
	cir.draw();
	rec.draw();
	tri.draw();

	set_cursor_pos(1, 25); // переводим курсор в самый низ экрана
	*/
#pragma endregion

#pragma region Комбинации прав доступа
	/*
	int a;
	B objB;
	a = objB.privdataA;  // ошибка, нет доступа
	a = objB.protdataA;  // ошибка, нет доступа
	a = objB.pubdataA;   // так можно
	
	C objC;
	a = objC.privdataA;  // ошибка, нет доступа
	a = objC.protdataA;  // ошибка, нет доступа
	a = objC.pubdataA;   // ошибка, нет доступа
	*/
#pragma endregion

#pragma region Employee уровни наследования
	/*
	laborer l1;
	foreman f1;
	
	// введем информацию о нескольких сотрудниках
	cout << endl;
	cout << "\nВвод информации о первом рабочем";
	l1.getdata();
	cout << "\nВвод информации о первом бригадире";
	f1.getdata();
	
	// выведем полученную информацию на экран
	cout << endl;
	cout << "\nИнформация о первом рабочем";
	l1.putdata();
	cout << "\nИнформация о первом бригадире";
	f1.putdata();
	cout << endl;
	*/
#pragma endregion

#pragma region Employee множественное наследование
	/*
	manager m1;
	scientist s1, s2;
	laborer l1;
	// введем информацию о нескольких сотрудниках
	cout << endl;
	cout << "\nВвод информации о первом менеджере";
	m1.getdata();
	cout << "\nВвод информации о первом ученом";
	s1.getdata();
	cout << "\nВвод информации о втором ученом";
	s2.getdata();
	cout << "\nВвод информации о первом рабочем";
	l1.getdata();
	// выведем полученную информацию на экран
	cout << "\nИнформация о первом менеджере";
	m1.putdata();
	cout << "\nИнформация о первом ученом";
	s1.putdata();
	cout << "\nИнформация о втором ученом";
	s2.putdata();
	cout << "\nИнформация о первом рабочем";
	l1.putdata();
	cout << endl;
	*/
#pragma endregion

#pragma region Множественное наследование 2
	/*
	Lumber siding;            // используем конструктор без параметров
	
	cout << "\n  Информация об обшивке:\n";
	siding.getlumber();     // получаем данные от пользователя
	
							// используем конструктор с шестью параметрами
	Lumber studs("2x4", "const", 8, 0.0, 200, 4.45F);
	
	// показываем информацию
	cout << "\nОбшивка"; siding.showlumber();
	cout << "\nБрус";    studs.showlumber();
	
	cout << endl;
	*/
#pragma endregion

#pragma region Проблема неопределенности
/*
F objF;           // объект класса F
//objF.show(); // так делать нельзя программа не скомпилируетс¤
objF.D::show(); // так можно
objF.E::show(); // так можно
*/
#pragma endregion

#pragma region Ромбовидное наследование

class Q
{
public:
	void func();
};
class W : public Q
{ };
class R : public Q
{ };
class T : public W, public R
{};
T objT;
//objT.func(); // неоднозначность: программа не скомпилируется

#pragma endregion

#pragma region Операторы new delete
	/*
	char* str = "Напишем что-нибудь в этой строке";
	int len = strlen(str);        // вычислим длину нашей строки
	
	char* ptr;                       // определим переменную
	ptr = new char[len + 1];       // выделим память
	
	strcpy(ptr, str);             // скопируем строку str в ptr
	
	cout << "ptr = " << ptr << endl; // покажем что содержится в ptr
	
	delete[] ptr;                   // освободим выделенную память
	*/
#pragma endregion

#pragma region Динамический String
	/*
	String s1 = "Напишем что-нибудь в этой строке";
	cout << "s1 = ";
	s1.display();
	*/
#pragma endregion

#pragma region Массив указателей на объекты
  /*
	person* persPtr[100]; // массив указателей
	int n = 0;            // количество элементов в массиве
	char choice;
	do
	{
		persPtr[n] = new person;       // создаем новый объект
		persPtr[n]->setName();         // вводим имя
		n++;                              // увеличиваем количество
		cout << "Продолжаем ввод (y/n)?"; // спрашиваем, закончен ли ввод
		cin >> choice;
	} while (choice == 'y');
	for (int j = 0; j < n; j++)
	{
		cout << "\nИнформация о номере " << j + 1;
		persPtr[j]->printName(); // *(persPtr+j)
	}
	cout << endl;
	*/
#pragma endregion

#pragma region Связные списки
	/*
	linklist li;       // создаем переменную-список
	
	li.additem(25); // добавляем туда несколько чисел
	li.additem(36);
	li.additem(49);
	li.additem(64);
	
	li.display();    // показываем список
	*/
#pragma endregion

#pragma region Сортировка объектов через массив указателей
    /*
	void bsort(person**, int); // прототип функции
	person* persPtr[100];      // массив указателей на person
	int n = 0;                    // количество элементов в массиве
	char choice;                  // переменная для ввода символа
	
	do
	{
		persPtr[n] = new person;       // создаем новый объект
		persPtr[n]->setName();       // вводим имя
		n++;                              // увеличиваем количество
		cout << "Продолжаем ввод (y/n)?"; // спрашиваем, закончен ли ввод
		cin >> choice;
	} while (choice == 'y');
	
	cout << "\nНеотсортированный список:";
	for (int j = 0; j < n; j++) // покажем неотсортированный список
		persPtr[j]->printName();
	
	bsort(persPtr, n);         // отсортируем указатели
	
	cout << "\nОтсортированный список:";
	for (int j = 0; j < n; j++)     // покажем отсортированный список
		persPtr[j]->printName();
	cout << endl;
	*/
#pragma endregion


	system("pause");
    return 0;
}

void bsort(person** pp, int n)
{
	void order(person**, person**); // прототип функции
	                          // переменные для циклов
	for (int j = 0; j < n - 1; j++)      // внешний цикл
		for (int k = j + 1; k < n; k++)    // внутренний цикл
			order(pp + j, pp + k);      // сортируем два элемента
}

void order(person** pp1, person** pp2)
{
	if ((*pp1)->getName() >(*pp2)->getName()) // если первая строка больше второй,
	{
		person* tempptr = *pp1; // меняем их местами
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}