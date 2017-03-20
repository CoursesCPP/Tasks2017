// Lection8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "msoftcon.h"
#include <string>
#include <ctime>
#include <fstream>
#include "Lection8.h"

using namespace std;


const int LEN = 80;       // максимальная длина выражения
const int MAX = 40;

class Stack
{
private:
	char st[MAX];         // массив данных
	int top;              // количество сохраненных данных
public:
	Stack()
	{
		top = 0;
	}
	void push(char var)  // поместить в стек
	{
		st[++top] = var;
	}
	char pop()           // взять из стека
	{
		return st[top--];
	}
	int gettop()         // узнать количество элементов
	{
		return top;
	}
};

class express
{
private:
	Stack s;                   // стек данных
	char* pStr;                // строка для ввода
	int len;                   // длина строки
public:
	express(char* ptr)      // конструктор
	{
		pStr = ptr;            // запоминаем указатель на строку
		len = strlen(pStr);    // устанавливаем длину
	}

	void parse()              // добавляем данные в стек
	{
		char ch;              // символ из строки
		char lastval;         // последнее значение
		char lastop;          // последний оператор

		for (int j = 0; j < len; j++) // для всех символов в строке
		{
			ch = pStr[j];    // получаем символ

			if (ch >= '0' && ch <= '9') // если это цифра,
				s.push(ch - '0');        // то сохраняем ее значение
			else
				if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
				{
					if (s.gettop() == 1)    // если это первый оператор,
						s.push(ch);         // помещаем его в стек
					else // иначе
					{
						lastval = s.pop(); // получаем предыдущее число
						lastop = s.pop();  // получаем предыдущий оператор
										   // если это * или /, а предыдущий был + или -, то
						if ((ch == '*' || ch == '/') && (lastop == '+' || lastop == '-'))
						{
							s.push(lastop); // отменяем последние два взятия из стека
							s.push(lastval);
						}
						else
						{
							// помещаем в стек результат операции
							switch (lastop)
							{
							case '+': s.push(s.pop() + lastval); break;
							case '-': s.push(s.pop() - lastval); break;
							case '*': s.push(s.pop() * lastval); break;
							case '/': s.push(s.pop() / lastval); break;
							default: cout << "\nНеизвестный оператор"; exit(1);
							}
						}
						s.push(ch); // помещаем в стек текущий оператор
					}
				}
				else
				{
					cout << "\nНеизвестный символ";
					exit(1);
				}
		}
	}


	int solve()				 // убираем данные из стека
	{
		char lastval;        // предыдущее значение

		while (s.gettop() > 1)
		{
			lastval = s.pop(); // получаем предыдущее значение
			switch (s.pop()) // получаем предыдущий оператор
			{
			case '+': s.push(s.pop() + lastval); break;
			case '-': s.push(s.pop() - lastval); break;
			case '*': s.push(s.pop() * lastval); break;
			case '/': s.push(s.pop() / lastval); break;
			default: cout << "\nНеизвестный оператор"; exit(1);
			}
		}
		return int(s.pop()); // последний оператор в стеке – это результат
	}
};

#pragma region 1
/*
class Base                //Базовый класс
{
	public:
	void  show()           //Обычная функция
	{
		cout << "Base\n";
	}
};

class Derv1 : public Base //Производный класс 1
{
	public:
	void  show()
	{
		cout << "Derv1\n";
	}
};

class Derv2 : public Base //Производный класс 2
{
	public:
	void  show()
	{
		cout << "Derv2\n";
	}
};
*/

#pragma endregion

#pragma region 2
/*
class Base                //Базовый класс
{
public:
	virtual void  show()    //Виртуальная функция
	{
		cout << "Base\n";
	}
};

class Derv1 : public Base //Производный класс 1
{
public:
	void  show()
	{
		cout << "Derv1\n";
	}
};

class Derv2 : public Base //Производный класс 2
{
public:
	void  show()
	{
		cout << "Derv2\n";
	}
};
*/

#pragma endregion

#pragma region 3
/*
class Base                   //абстрактный класс
{
public:
	virtual void show() = 0; //чистая виртуальная функция
						//значение ничему не присваивается
};

class Derv1 : public Base    //порожденный класс 1
{
public:
void show()
{
cout << "Derv1\n" ;
}
};

class Derv2 : public Base    //порожденный класс 2
{
public:
void show()
{
cout << "Derv2\n" ;
}
};

*/
#pragma endregion

class person                    //класс person
{
protected:
	char name[40];
public:
	void getName()
	{
		cout << "  Введите имя: "; cin >> name;
	}
	void putName()
	{
		cout << "  Name: " << name << endl;
	}
	virtual void getData() = 0;       //чистые
	virtual bool isOutstanding() = 0; //виртуальные
									  //функции
};

class student : public person   //класс student
{
private:
	float gpa;                //средний балл
public:
	void getData()            //запросить данные об ученике 
	{
		person::getName();
		cout << "  Средний балл ученика:  "; cin >> gpa;
	}
	bool isOutstanding()
	{
		return (gpa > 3.5) ? true : false;
	}
};

class professor : public person //класс professor
{
private:
	int numPubs;              //число публикаций
public:
	void getData()            //запросить данные о педагоге у
	{                       //пользователя
		person::getName();
		cout << "  Число публикаций:  "; cin >> numPubs;
	}
	bool isOutstanding()
	{
		return (numPubs > 100) ? true : false;
	}
};


class shape                   //базовый класс
{
protected:
	int xCo, yCo;           //координаты центра
	color fillcolor;        //цвет
	fstyle fillstyle;       //заполнение
public:                     //конструктор без аргументов
	shape() : xCo(0), yCo(0), fillcolor(cWHITE),
		fillstyle(SOLID_FILL)
	{  }                 //конструктор с четырьмя аргументами
	shape(int x, int y, color fc, fstyle fs) :
		xCo(x), yCo(y), fillcolor(fc), fillstyle(fs)
	{  }
	virtual void draw() = 0 //чистая виртуальная функция
	{
		set_color(fillcolor);
		set_fill_style(fillstyle);
	}
};

class ball : public shape
{
private:
	int radius;          //центр с координатами(xCo, yCo)
public:
	ball() : shape()     //конструктор без аргументов
	{  }
	//конструктор с пятью аргументами
	ball(int x, int y, int r, color fc, fstyle fs)
		: shape(x, y, fc, fs), radius(r)
	{  }
	void draw()          //нарисовать шарик
	{
		shape::draw();
		draw_circle(xCo, yCo, radius);
	}
};

class rect : public shape
{
private:
	int width, height;   //(xCo, yCo) - верхний левый угол
public:
	rect() : shape(), height(0), width(0) //конструктор без аргументов
	{  }              //конструктор с шестью аргументами
	rect(int x, int y, int h, int w, color fc, fstyle fs) :
		shape(x, y, fc, fs), height(h), width(w)
	{  }
	void draw()             //нарисовать прямоугольник
	{
		shape::draw();
		draw_rectangle(xCo, yCo, xCo + width, yCo + height);
		set_color(cWHITE);   //нарисовать диагональ
		draw_line(xCo, yCo, xCo + width, yCo + height);
	}
};

class tria : public shape
{
private:
	int height;                 //(xCo, yCo) - вершина пирамиды
public:
	tria() : shape(), height(0) //конструктор без аргументов
	{ }                      //конструктор с пятью аргументами
	tria(int x, int y, int h, color fc, fstyle fs) :
		shape(x, y, fc, fs), height(h)
	{  }
	void draw()                 //нарисовать треугольник
	{
		shape::draw();
		draw_pyramid(xCo, yCo, height);
	}
};

#pragma region 4
/*
class Base
{
public:
	//~Base()             //невиртуальный деструктор
	virtual ~Base()         //виртуальный деструктор
	{
		cout << "Base удален\n";
	}
};

class Derv : public Base
{
public:
	~Derv()
	{
		cout << "Derv удален\n";
	}
};

*/
#pragma endregion

class Parent
{
protected:
	int basedata;
};
class Child1 : public Parent
{ };
class Child2 : public Parent
{ };
class Grandchild : public Child1, public Child2
{
public:
	int getdata()
	{
		//return basedata; //ОШИБКА: неоднозначность
	}
};

class beta;              //нужно для объявления frifunc
class alpha
{
private:
	int data;
public:
	alpha() : data(3) {  }   //конструктор без аргументов
	friend int frifunc(alpha, beta); //дружественная функция
};

class beta
{
private:
	int data;
public:
	beta() : data(7) {  }     //конструктор без аргументов
	friend int frifunc(alpha, beta);       //дружественная функция
};

int frifunc(alpha a, beta b)           //определение функции
{
	return(a.data + b.data);
}

class Distance
{
private:
	int feet;
	float inches;
public:
	Distance() : feet(0), inches(0.0)
	{  }
	Distance(float fltfeet)           //переводит float в Distance
	{
		feet = static_cast<int>(fltfeet);
		inches = 12 * (fltfeet - feet);
	}
	Distance(int ft, float in)
	{
		feet = ft; inches = in;
	}
	void showdist()                    //вывод на экран расстояния
	{
		cout << feet << "\'-" << inches << '\"';
	}
	//Distance operator + (Distance);
	//friend Distance operator + (Distance, Distance); //дружественный
	/*
	float square()		//возвращает квадрат
	{
		float fltfeet = feet + inches / 12;	 //перевод во float
		float feetsqrd = fltfeet * fltfeet;  //возведение в квадрат
		return feetsqrd;
	}*/

	friend float square(Distance); //дружественная ф-ция
};
/*
Distance Distance::operator + (Distance d2) //сумма
{
	int f = feet + d2.feet;       //добавить футы
	float i = inches + d2.inches; //добавить дюймы
	if (i >= 12.0)                //если сумма превышает 12.0,
		{
			i -= 12.0; f++;
		}
	return Distance(f, i);         //Новый Distance с суммой
}

Distance operator + (Distance d1, Distance d2) // d1 + d2
{
	int f = d1.feet + d2.feet;       //+ футы
	float i = d1.inches + d2.inches; //+ дюймы
	if (i >= 12.0)                    //если больше 12 дюймов,
	{
		i -= 12.0; f++;
	}           //уменьшить на 12 дюймов,
				//прибавить 1 фут
	return Distance(f, i);            //Новая длина с суммой
}

*/

float square(Distance d)                //вернуть квадрат
{                                     //расстояния
	float fltfeet = d.feet + d.inches / 12; //конвертировать 
											//в тип float
	float feetsqrd = fltfeet * fltfeet;   //вычислить квадрат
	return feetsqrd;                      //вернуть квадратные футы
}


class gamma
{
private:
	int data1;
public:
	gamma() : data1(99) {  }  //конструктор
	friend class delta;        //delta - дружественный класс
};

class delta
{     //все методы имеют доступ к скрытым данным gamma
public:
	void func1(gamma a) { cout << "\ndata1=" << a.data1; }
	void func2(gamma a) { cout << "\ndata1=" << a.data1; }
};

class tetta
{
private:
	static int total;       //всего объектов класса
	int id;                 //ID текущего объекта
public:
	tetta()                 //конструктор без аргументов
	{
		total++;              //добавить объект
		id = total;           //id равен текущему значению total
	}
	~tetta()                //деструктор
	{
		total--;
		cout << "Удаление ID " << id << endl;
	}
	static void showtotal() // статическая функция
	{
		cout << "Всего: " << total << endl;
	}
	void showid()           // Нестатическая функция
	{
		cout << "ID: " << id << endl;
	}
};

int tetta::total = 0;       // определение total

class alphaq
{
private:
	int data;
public:
	alphaq()                     //конструктор без аргументов
	{ }
	alphaq(int d)                //конструктор с одним аргументом
	{
		data = d;
	}
	void display()              //вывести данные
	{
		cout << data;
	}
	alphaq operator = (alphaq& a) //перегружаемый = 
	{
		data = a.data;             //не выполняется автоматически
		cout << "\nЗапущен оператор присваивания";
		return alphaq(data);       //возвращает копию alphaq
	}
};


class where
{
private:
	char charray[10];  //массив из 10 байтов
public:
	void reveal()
	{
		cout << "\nМой адрес - " << this;
	}
};

class what
{
private:
	int alpha;
public:
	void tester()
	{
		this->alpha = 11;    //то же,что alpha = 11;
		cout << this->alpha; //то же, что cout <<
							 //alpha;
	}
};

class alphathis
{
private:
	int data;
public:
	alphathis()                      // конструктор без аргументов
	{ }
	alphathis(int d)                 // конструктор с одним аргументом
	{
		data = d;
	}
	void display()               // вывести данные
	{
		cout << data;
	}

	alphathis& operator = (alphathis& a) // перегружаемая операция =
	{
		data = a.data;             // не делается автоматически
		cout << "\nЗапущен оператор присваивания";
		return *this;              // вернуть this alpha
	}
};




int main()
{
	setlocale(LC_ALL, "Russian");

#pragma region Разбор арифметических выражений
	/*
	char ans;            // 'y' или 'n'
	char string[LEN]; // строка для разбора

	cout << "\nВведите арифметическое выражение в виде 2+3*4/3-2"
		    "\nЧисла должны быть из одной цифры"
		    "\nНе используйте пробелы и скобки";
	do
	{
		cout << "\nВыражение: ";
		cin >> string;                          // вводим строку
		express* eptr = new express(string);    // создаем объект для разбора
		eptr->parse();                          // разбираем
		cout << "\nРезультат: "
			<< eptr->solve();                   // решаем
		delete eptr;                            // удаляем объект
		cout << "\nЕще одно выражение (y/n)? ";
		cin >> ans;
	} while (ans == 'y');
	*/
#pragma endregion

#pragma region Доступ к методам через указатели (1)
	/*
	Derv1 dv1;          //Объект производного класса 1
	Derv2 dv2;          //Объект производного класса 2
	Base* ptr;          //Указатель на базовый класс

	ptr = &dv1;         //Адрес dv1 занести в указатель
	ptr->show();        //Выполнить show()
	ptr = &dv2;         //Адрес dv2 занести в указатель
	ptr->show();        //Выполнить show()
	*/
	//Вывод - компилятор не смотрит на содержимое, а выбирает метод
	//который удовлетворяет типу указателя.
	
#pragma endregion

#pragma region Доступ к виртуальным методам через указатели (2)
	/*
	Derv1 dv1;            //Объект производного класса 1
	Derv2 dv2;            //Объект производного класса 2
	Base* ptr;            //Указатель на базовый класс

	ptr = &dv1;            //Адрес dv1 занести в указатель
	ptr->show();           //Выполнить show()
	ptr = &dv2;            //Адрес dv2 занести в указатель
	ptr->show();           //Выполнить show()
	*/
#pragma endregion

#pragma region Чистая виртуальная функция (3)
	/*
	//Base bad;                 //невозможно создать объект
	//из абстрактного класса
	Base* arr[2];              //массив указателей на
							   //базовый класс
	Derv1 dv1;                 //Объект производного класса 1
	Derv2 dv2;                 //Объект производного класса 2

	arr[0] = &dv1;             //Занести адрес dv1 в массив
	arr[1] = &dv2;             //Занести адрес dv2 в массив

	arr[0]->show();            //Выполнить функцию show()
	arr[1]->show();            //над обоими объектами
	*/
#pragma endregion

#pragma region Виртуальные функции
	
	person* persPtr[100];  //массив указателей на person
	int n = 0;            //число людей, внесенных в список char choice;
	char choice;
	do {
		cout << " Учащийся (s) или педагог (p): ";
		cin >> choice;
		if (choice == 's')               //Занести нового ученика в массив
			persPtr[n] = new student;   
		else                          //Занести нового педагога в массив
			persPtr[n] = new professor; 
		persPtr[n++]->getData();       //Запрос данных о персоне
		cout << " Ввести еще персону (y/n)? "; 
		cin >> choice;
	} while (choice == 'y');       //цикл, пока ответ 'y'
	for (int j = 0; j<n; j++)
	{
		persPtr[j]->putName();        //Вывести все имена,
		if (persPtr[j]->isOutstanding())        
			cout << "  Это выдающийся человек!\n"; //сообщать о выдающихся
	}
	
#pragma endregion

#pragma region Виртуальные функции с графикой
	/*
	init_graphics();             //инициализация графики
	shape* pShapes[3];           //массив указателей на фигуры
								 //определить три фигуры
	pShapes[0] = new ball(40, 12, 5, cBLUE, X_FILL);
	pShapes[1] = new rect(12, 7, 10, 15, cRED, SOLID_FILL);
	pShapes[2] = new tria(60, 7, 11, cGREEN, MEDIUM_FILL);

	for (int j = 0; j<3; j++)           //нарисовать все фигуры
		pShapes[j]->draw();

	for (int j = 0; j<3; j++)           //удалить все фигуры
		delete pShapes[j];
	set_cursor_pos(1, 25);
	*/
#pragma endregion

#pragma region Виртуальные деструкторы
	/*
	Base* pBase = new Derv;
	delete pBase;
	*/
	//Чтобы быть уверенным, что объекты порожденных классов удаляются 
	//как нужно, следует делать деструкторы в базовых классах виртуальными
	
#pragma endregion

#pragma region Дружественные функции
	/*	
	alpha aa;
	beta bb;
	
	cout << frifunc(aa, bb) << endl;   //вызов функции
	*/
#pragma endregion

#pragma region Ограничение перегрузки
	/*
	Distance d1 = 2.5;         //конструктор переводит
	Distance d2 = 1.25;        //float-feet в Distance
	Distance d3;
	cout << "\nd1 = "; d1.showdist();
	cout << "\nd2 = "; d2.showdist();
	
	d3 = d1 + 10.0;            //distance + float: OK
	cout << "\nd3 = "; d3.showdist();
	d3 = 10.0 + d1;            //float + Distance: неOK
	cout << "\nd3 = "; d3.showdist();
	cout << endl;
	*/
#pragma endregion

#pragma region Еще одна дружественная функция
	/*
	Distance dist(3, 6.0);	
	float sqft;
	
	//sqft = dist.square();	//вычислить квадрат расстояния
	sqft = square(dist);   //вернуть квадрат dist
	cout << "\nРасстояние = "; dist.showdist();
	cout << "\nКвадрат расстояния = " << sqft << " кв. футов\n";
	*/
#pragma endregion

#pragma region Дружественные классы
	/*
	gamma a;
	delta b;
	
	b.func1(a);
	b.func2(a);
	cout << endl;
	*/
#pragma endregion

#pragma region Статические функции и ID объектов
	/*
	tetta g1;
	tetta::showtotal();
		
	tetta g2, g3;
	tetta::showtotal();
	
	g1.showid();
	g2.showid();
	g3.showid();
	*/
#pragma endregion

#pragma region Перегрузка оператора присваивания
	/*
	alphaq a1(37);
	alphaq a2;
	
	a2 = a1;                       //запуск перегружаемого =
	cout << "\na2="; a2.display(); //вывести a2
	
	alphaq a3 = a2;                 //НЕ запускается - это инициализация
	cout << "\na3="; a3.display(); //вывести a3
	cout << endl;
	*/
#pragma endregion

#pragma region Указатель this
	/*
	where w1, w2, w3;    //создать три объекта
	w1.reveal();         //посмотреть, где они находятся
	w2.reveal();
	w3.reveal();
	cout << endl;
	*/
#pragma endregion

#pragma region Ссылка this на данные
	/*
	what w;
	w.tester();
	cout << endl;
	*/
#pragma endregion

#pragma region Возврат содержимого указателя this
	/*
	alphathis a1(37);
	alphathis a2, a3;
	
	a3 = a2 = a1;                  // перегружаемый =, дважды
	cout << "\na2="; a2.display(); // вывести a2
	cout << "\na3="; a3.display(); // вывести a3
	cout << endl;
	*/
#pragma endregion

	system("pause");
    return 0;
}

