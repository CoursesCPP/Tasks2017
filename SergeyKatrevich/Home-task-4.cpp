// Home-task-4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
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
	}
};

#pragma region 2. Изменить перегруженную операцию + на += в классе String.
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
	//String operator+ (String ss) const
	//{
	//	String temp;  // временная переменная
	//	if (strlen(str) + strlen(ss.str) < Size)
	//	{
	//		strcpy(temp.str, str);    // копируем содержимое первой строки
	//		strcat(temp.str, ss.str); // добавляем содержимое второй строки
	//	}
	//	else
	//	{
	//		cout << "\nПереполнение!";
	//		exit(1);
	//	}
	//	return temp;  // возвращаем результат
	//}
	const String& operator+= (String ss) const
	{
		char *pstr = const_cast<char*>(&str[0]);
		if (strlen(str) + strlen(ss.str) < Size)
		{
			strcat(pstr, ss.str); // добавляем содержимое второй строки
		}
		else
		{
			cout << "\nПереполнение!";
			exit(1);
		}
		return *this;  // возвращаем результат
	}
#pragma endregion

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

#pragma region 3. Создать свой класс Int, в котором будут перегруженные операции (+, - ,  /, *).

class Int {
	int num;
	void out(int n1, char sign, int n2, float res) {
		cout << n1 << " " << sign << " " << n2 << " = " << res << endl;
	}
	void out(int n1, char sign, int n2, int res) {
		out(n1, sign, n2, (float)res);
	}

	int operat(char op, Int i) {
		int res;
		switch (op) {
		case '+': res = num + i.num; break;
		case '-': res = num - i.num; break;
		case '*': res = num * i.num; break;
		}
		out(num, op, i.num, res);
		return res;
	}
public:
	Int(int i) : num(i) {}
	friend int getNum(Int i);
	
	Int operator+(const Int& i) {
		return operat('+', i);
	}
	Int operator-(const Int& i) {
		return operat('-', i);
	}
	Int operator*(const Int& i) {
		return operat('*', i);
	}
	float operator/(const Int& i) {
		float res = (float)num / i.num;
		out(num, '/', i.num, res);
		return res;
	}
};
int getNum(Int i) {
	return i.num;
}
ostream& operator<<(ostream& out, Int i) {
	cout << getNum(i);
	return out;
}

#pragma endregion

#pragma region 4. Создать свой класс Рубль, с которым можно будет полноценно работать по вашему мнению.
class Рубль {
	float toSum() {
		return рублей + долг_рублей + (копеек + долг_копеек) / 100.0f;
	}
	float sum;
	void fillDetails() {
		float absSum = abs(sum);
		unsigned rub = (unsigned)absSum;
		unsigned kop = round(100 * (absSum - rub));
		if (sum < 0) {
			рублей = 0;
			копеек = 0;
			долг_рублей = rub;
			долг_копеек = kop;
		}
		else {
			рублей = rub;
			копеек = kop;
			долг_рублей = 0;
			долг_копеек = 0;
		}

	}
public:
	unsigned рублей = 0;
	unsigned копеек = 0;
	unsigned долг_рублей = 0;
	unsigned долг_копеек = 0;

	Рубль(float сумма) : sum(сумма) {
		fillDetails();
	}
	
	Рубль operator+(Рубль rub) {
		return Рубль(sum + rub.sum);
	}
	Рубль operator-(Рубль rub) {
		return Рубль(sum - rub.sum);
	}
	void show() {
		cout << "money = " << рублей << "." << копеек
			<< " credit = " << долг_рублей << "." << долг_копеек
			<< endl;
	}


};
#pragma endregion
int main()
{
	setlocale(LC_ALL, "Russian");
#pragma region (Проверка) 1. Добавить в класс Distance перегруженные операции - и -=. 
	/*Distance dist1(3, 7);
	Distance dist2(4, 5);
	Distance dist3 = dist2 - dist1;
	dist3.showdist();

	dist3 += dist1;
	dist3.showdist();*/
#pragma endregion


	/*String str("1234");
	String str2("5678");
	str += str2;
	cout << str << endl;*/

#pragma region (Проверка) 3. Создать свой класс Int, в котором будут перегруженные операции (+, - ,  /, *).
	//Int i1 = 3;
	//Int i2 = 4;
	//Int i3 = i1 + i2;
	//Int i4 = i1 - i2;
	//Int i5 = i1 * i2;
	//float f = i1 / i2;
	//cout << i3 << endl << i4 << endl << i5 << endl << f;
#pragma endregion


	Рубль rubs1(15.15f);
	Рубль rubs2(20.05f);
	Рубль rubs3(40.50f);
	rubs2 = rubs1 + rubs2;
	cout << "rubs2: ";
	rubs2.show();
	cout << "rubs3: ";
	(rubs2 - rubs3).show();


	_getch();
    return 0;
}

