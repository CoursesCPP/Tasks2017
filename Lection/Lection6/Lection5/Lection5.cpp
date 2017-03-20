// Lection5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "msoftcon.h"

using namespace std;

class Smallobj               // определение класса
{
private:
	int somedata;            // поле класса
public:
	void setdata(int d)      // метод класса, изменяющий значение поля
	{
		somedata = d;
	}
	void getdata()          // метод класса, отображающий значение поля
	{
		cout << "Значение поля равно " << somedata << endl;
	}
};

class Part                  // определение класса
{
private:
	int modelnumber;           // номер изделия
	int partnumber;            // номер детали
	float cost;                // стоимость детали
public:
	// установка данных
	void setpart(int mn, int pn, float c)
	{
		modelnumber = mn;
		partnumber = pn;
		cost = c;
	}
	void showpart()          // вывод данных
	{
		cout << "Модель " << modelnumber;
		cout << ", деталь " << partnumber;
		cout << ", стоимость $" << cost << endl;
	}
};

class Circle                 //графический объект "круг"
{
private:
	int xCo, yCo;             // координаты центра
	int radius;
	color fillcolor;         // цвет
	fstyle fillstyle;        // стиль заполнения
public:                    // установка атрибутов круга
	
	Circle(int x, int y, int r, color fc, fstyle fs) 
		: xCo(x), yCo(y), radius(r), fillcolor(fc), fillstyle(fs)
	{
		cout << "Привет я объект x ="<< x << endl;
	}

	void setX(int x)
	{
		xCo = x;
	}
	void setY(int y)
	{
		yCo = y;
	}
	void draw()                    // рисование круга
	{
		set_color(fillcolor);        // установка цвета и
		set_fill_style(fillstyle);   // стиля заполнения
		draw_circle(xCo, yCo, radius); // рисование круга
	}
};

class Distance                       // длина в английской системе
{
private:
	int feet;
	float inches;
public:
	
	// конструктор без аргументов
	Distance() : feet(0), inches(0.0)
	{ }
	// конструктор с двумя аргументами		
	Distance(int ft, float in) : feet(ft), inches(in)
	{ }
	
	void setdist(int ft, float in)  // установка значений полей
	{
		feet = ft; inches = in;
	}
	void getdist()                   // ввод полей с клавиатуры
	{
		cout << "\nВведите число футов: "; cin >> feet;
		cout << "Введите число дюймов: "; cin >> inches;
	}
	void showdist();                  // вывод полей на экран
	void add_dist(Distance, Distance); // прототип
	Distance add_dist(Distance);       // прототип-сложение
};

void Distance::showdist()                  // вывод полей на экран
{
	cout << feet << "'-" << inches << '"';
}

void Distance::add_dist(Distance d1, Distance d2) //метод класса вне класса
{
	//:: - операция глобального разрешения, Distance::add_dist - функция add_dist, является методом класса Distance

	inches = d1.inches + d2.inches;        // сложение дюймов
	if (inches >= 12.0)                     // если число дюймов больше 12.0,
	{                                      // то уменьшаем число дюймов
		inches -= 12.0;                      // на 12.0 и увеличиваем
		feet = 1;                              // число футов на 1
	}
	feet += d1.feet + d2.feet;             // сложение футов
}

Distance Distance::add_dist(Distance d2)
{
	Distance temp;                    // временная переменная
	temp.inches = inches + d2.inches; // сложение дюймов
	if (temp.inches >= 12.0)           // если сумма больше 12.0,
	{                                 // то уменьшаем ее на 
		temp.inches -= 12.0;            // 12.0 и увеличиваем
		temp.feet = 1;                  // число футов на 1
	}
	temp.feet += feet + d2.feet;      // сложение футов
	return temp;
}

class Counter
{
private:
	unsigned int count;         // значение счетчика
public:
	Counter() : count(0)        // конструктор
	{ /* пустое тело */
	}
	void inc_count()            // инкрементирование счетчика
	{
		count++;
	}
	int get_count()             // получение значения счетчика
	{
		return count;
	}
};

class foo
{
private:
	static int count;        // общее поле для всех объектов
							 // (в смысле "объявления")
public:
	foo()                    // инкрементирование при создании объекта
	{
		count++;
	}
	int getcount()           // возвращает значение count
	{
		return count;
	}
};
int foo::count = 0;          // *определение* count
class ConstDistance                  
{
private:
	int feet;
	float inches;
public:                       // конструктор без аргументов
	ConstDistance() : feet(0), inches(0.0)
	{ }                       // конструктор с двум¤ аргументами
	ConstDistance(int ft, float in) : feet(ft), inches(in)
	{ }
	void getdist()              // ввод длины пользователем
	{
		cout << "\nВведите число футов: "; cin >> feet;
		cout << "Введите число дюймов: "; cin >> inches;
	}
	void showdist()const        // вывод длины
	{
		cout << feet << "\'-" << inches << '\"';
	}
	//ConstDistance add_dist(ConstDistance&) const; // сложение
	ConstDistance add_dist(const ConstDistance &d2)const // сложение данного объекта с d2, возврат суммы
{
	ConstDistance temp;                // временная переменна¤
	//feet = 0;                  // ошибка: нельзя изменить поле
	//d2.feet = 0;               // ошибка: нельзя изменить d2
	temp.inches = inches + d2.inches; // сложение дюймов
	if (temp.inches >= 12.0)     // если сумма превышает 12.0,
	{                             // то уменьшаем ее на 12.0
		temp.inches -= 12.0;        // и увеличиваем число футов
		temp.feet = 1;              // на 1
	}
	temp.feet += feet + d2.feet;  // сложение футов
	return temp;
}
};



int main()
{
	setlocale(LC_ALL, "Russian");

#pragma region Простой класс
	/*
	Smallobj s1, s2;           // определение двух объектов класса smallobj
	s1.setdata(1066);          // вызовы метода setdata()
	s2.setdata(1776);
	s1.getdata();             // вызовы метода showdata()
	s2.getdata();
	*/
#pragma endregion

#pragma region Класс part
	/*
	Part part1;                // определение объекта класса part
	part1.setpart(6244, 373, 217.55F); // вызов метода
	part1.showpart();                 // вызов метода
	*/
#pragma endregion

#pragma region Круги
	/*
	init_graphics();           // инициализация графики
	Circle c1(15, 7, 5, cBLUE, X_FILL); // создание кругов
	Circle c2(41, 12, 7, cRED, O_FILL);
	Circle c3(65, 18, 4, cGREEN, MEDIUM_FILL);
	// установка атрибутов кругов
	c1.draw();                 // рисование кругов
	c2.draw();
	c3.draw();
	set_cursor_pos(1, 25);      // нижний левый угол
	*/
#pragma endregion

#pragma region Класс - тип данных
	/*
	Distance dist1, dist2;              // две длины
	Distance dist3(111, 6.25);
	dist1.setdist(11, 6.25);            // установка значений дл¤ d1
	dist2.getdist();                    // ввод значений дл¤ dist2
									    // вывод длин на экран
	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
	cout << endl;
	*/
#pragma endregion

#pragma region Счетчик
	/*
	Counter c1, c2;               // определение с инициализацией
	cout << "\nc1=" << c1.get_count(); // вывод
	cout << "\nc2=" << c2.get_count();
	c1.inc_count();               // инкрементирование c1
	c2.inc_count();               // инкрементирование c2
	c2.inc_count();               // инкрементирование c2
	c2.inc_count();
	cout << "\nc1=" << c1.get_count(); // вывод
	cout << "\nc2=" << c2.get_count();
	cout << endl;
	*/
#pragma endregion

#pragma region Круги с конструктором
	/*
	init_graphics();                // инициализация графики
	// создание кругов
	Circle c1(15, 7, 5, cBLUE, X_FILL);
	Circle c2(41, 12, 7, cRED, O_FILL);
	Circle c3(65, 18, 4, cGREEN, MEDIUM_FILL);
	c1.draw();                      // рисование кругов
	c2.draw();
	c3.draw();
	set_cursor_pos(1, 25);          // левый нижний угол
	*/
#pragma endregion

#pragma region Дистанции с конструкторами
	/*
	Distance dist1, dist3;        // две длины
	Distance dist2(11, 6.25);     // определение и инициализация
	dist1.getdist();              // ввод dist1
	dist3.add_dist(dist1, dist2);  // dist3 = dist1 + dist2
								   // вывод всех длин
	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
	cout << endl;
	*/
#pragma endregion

#pragma region Дистанции, копирующий конструктор
	/*
	Distance dist1(11, 6.25);  // конструктор с двум¤ аргументами
	Distance dist2(dist1);     // два конструктора с одним аргументом
	Distance dist3 = dist1;
	// вывод всех длин
	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
	cout << endl;
	*/
#pragma endregion

#pragma region Дистанции, объект, возвращаемый функцией
	/*
	Distance dist1, dist3;            // две длины
	Distance dist2(11, 6.25);         // определение и инициализация dist2
	dist1.getdist();                  // ввод dist1 пользователем
	dist3.add_dist(dist1, dist2);     // dist3 = dist1 + dist2
	dist3 = dist1.add_dist(dist2);    // dist3 = dist1 + dist2

									  // вывод всех длин
	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
	cout << endl;
	*/
#pragma endregion

#pragma region Static или статические поля класса

	// создание трех объектов
	foo f1;
	cout << "Число объектов: " << f1.getcount() << endl;
	foo	f2;
	cout << "Число объектов: " << f2.getcount() << endl;
	foo f3;           					
	cout << "Число объектов: " << f3.getcount() << endl;
	
#pragma endregion

#pragma region Константные методы
	/*
	ConstDistance dist1, dist3;        // две длины
	ConstDistance dist2(11, 6.25);     // определение и инициализаци¤ dist2
	dist1.getdist();              // ввод dist1
	dist3 = dist1.add_dist(dist2);//dist3 = dist1 + dist2
	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
	cout << endl;
	*/
#pragma endregion

#pragma region Константные объекты
    /*
	const ConstDistance football(300, 0);
	//football.getdist();      // ошибка: метод getdist() неконстантный
	cout << " Длина пол¤ равна: ";
	football.showdist();       // корректно
	cout << endl;
	*/
#pragma endregion

	system("pause");
    return 0;
}

