// Home-task-5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

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
	/* 1. Добавить в класс Distance перегруженные операции «-» и «-=». */
	Distance operator- (Distance d2) const
	{
		int f = feet - d2.feet;
		float i = inches - d2.inches;
		if (i < 0) {
			f--;
			i = 12 + i;
		}
		return Distance(f, i);
	}
	Distance operator-= (Distance d2)
	{
		feet -= d2.feet;
		inches -= d2.inches;
		if (inches < 0) {
			feet--;
			inches = 12 + inches;
		}
		return *this;
	}
	Distance operator* (Distance &d2) {
		float dist = feet + inches / 12.f;
		dist *= d2.feet + d2.inches / 12.f;
		int f = (int)dist;
		float i = dist - f;
		i = round(i / (1 / 12.f));
		return Distance(f, i);
	}
};

class Publication {
protected:
	string _title;
	int _price = 0;

public:
	Publication() {}
	Publication(string title, int price) : _title(title), _price(price) {}
	virtual string getdata() = 0;
	virtual void putdata(string title, int price, int) = 0;

protected: 
	string baseGetData() {
		char buf[10];
		_itoa_s(_price, &buf[0], sizeof(buf), 10);
		return
			"Title: \"" + _title
			+ "\" Price: " + string(buf);
	}
};

class book : public Publication {
	int _pages;
	string s;

public:

	virtual string getdata() override {
		char buf[10];
		_itoa_s(_pages, &buf[0], sizeof(buf), 10);
		return baseGetData() + " Pages: " + string(buf);
	}
	virtual void putdata(string title, int price, int pages) override {
		_title = title; _price = price; _pages = pages;
	}
};

class tape : public Publication {
	int _minuts;

public:
	/*tape() {}*/
	virtual string getdata() override {
		char buf[10];
		_itoa_s<sizeof(buf)>(_minuts, buf, 10);
		return baseGetData() + " Minuts: " + string(buf);
	}

	virtual void putdata(string title, int price, int minuts) override {
		_title = title; _price = price; _minuts = minuts;
	}
};

int main()
{
	/*book bk;
	tape tp;
	
	cout << "--------------- Checking -------------------" << endl;
	bk.putdata("Sladers", 70, 500);
	cout << bk.getdata() << endl;

	tp.putdata("Tom Soyer", 30, 120);
	cout << tp.getdata() << endl;
	cout << "---------------------------------------------" << endl;

	const int count = 5;
	Publication* pubs[count];

	for (int i = 0; i < count; i++) {
		char chBorT;
		string title;
		int price;
		cout << "Add book(b) or tape(t): "; cin >> chBorT;
		cout << "Enter title: "; cin >> title;
		cout << "Enter price: "; cin >> price;
		Publication* pub;
		switch (chBorT) {
		case 'b': 
			pub = new book;
			int pages;
			cout << "Enter pages count: "; cin >> pages;
			pub->putdata(title, price, pages);
			break;
		case 't':
			pub = new book;
			int minuts;
			cout << "Enter minuts count: "; cin >> minuts;
			pub->putdata(title, price, minuts);
			break;
		}
		pubs[i] = pub;
	}
	cout << endl << endl;
	
	for (int i = 0; i < count; i++) {
		cout << pubs[i]->getdata() << endl;
	}*/

	Distance d1(5, 3);
	Distance d2(10, 0);
	Distance d3 = d1 * d2;
	d3.showdist();


	_getch();
	return 0;
}

