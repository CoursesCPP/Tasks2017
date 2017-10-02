#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h> 
#include <conio.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	
	//double dRes;

	//double PI = M_PI;
	//cout << PI << endl;
	//// Задача 1
	//float fNum;
	//cout << "Введите вещественное число: ";
	//cin >> fNum;
	//dRes = fNum;
	//cout << dRes << " x " << dRes << " = " << dRes * dRes << endl;

	//// Задача 2
	//cout << "Введите длину радиуса окружности: ";
	//float radius;
	//cin >> radius;
	//dRes = radius;
	//cout << "Площать круга: " << PI * (dRes * dRes) << endl;

	///////////////////////// Треугольники ///////////////////////////////////////
	{
		//double evalTriangleSide(float sideA, float sideB, float angle);
		//double evalTrigSquare(float sideA, float sideB, double sideC);

		//float trigSideA, trigSideB, angle;
		//double trigSideC;

		//// Задача 3
		//cout << "Введите длину стороны А: ";
		//cin >> trigSideA;
		//cout << "Введите длину стороны B: ";
		//cin >> trigSideB;
		//cout << "Введите угол между ними: ";
		//cin >> angle;
		//trigSideC = evalTriangleSide(trigSideA, trigSideB, angle);
		//cout << "Длина стороны C: " << trigSideC << endl;

		//{
		//	// Задача 4
		//	double c = trigSideA;
		//	double b = trigSideB;
		//	double a = trigSideC;
		//	//double a = 3, b = 4, c = 5;
		//	double acosParam = (a * a + b * b - c * c) / 2 * a * b;
		//	double res = acos(acosParam);
		//	cout << "Величина угла противолежащего стороне А: " << res << endl;
		//}

	/*	cout << "--------- Задача 5 -------------" << endl;
		cout << "Площадь треугольника: " << evalTrigSquare(trigSideA, trigSideB, trigSideC) << endl;*/
	}
	/////////////////////// end Треугольники ///////////////////////////////////////

	/*{
		cout << "--------- Задача 6 -------------" << endl;
		float startSum;
		cin >> ((cout << "Введите сумму вклада: "), startSum);
		double profit = startSum * 0.03;
		cout << "Сумма вклада превысит 1000000 через: " << floor((1e6 - startSum) / profit) + 1 << endl;;
	}*/

	///////////////////// 2. «Условия if, if-else,?». ///////////////////////
	/*Задача 2.1*/
	/*{
		float a, b, c;
		cin >> ((cout << "SideA: "), a);
		cin >> ((cout << "SideB: "), b);
		cin >> ((cout << "SideC: "), c);
		if ((a + b > c) && (a + c > b) && (b + c > a))
			cout << "да" << endl;
		else cout << "нет" << endl;
	}*/

	/*Задача 2.2*/
	/*{
		float n1, n2, n3;
		cin >> ((cout << "float1: "), n1);
		cin >> ((cout << "float2: "), n2);
		cin >> ((cout << "float3: "), n3);
		cout <<	(n1 < n2 ? (n1 < n3 ? n1 : n3) : (n2 < n1 ? n2 : n3));
		cout << endl;
	}*/

	/*Задача 2.3*/
	/*{
		int letter;
		cout << "Please enter letter order (1..26): ";
		cin >> letter;
		letter += 'A' - 1;
		cout << "Letter: " << (char)letter;
	}*/

	/*Задача 2.4*/
	//{
	//	int rating;
	//	cout << "Please enter rating: ";
	//	cin >> rating;
	//	int rank = (int)(rating / 10);
	//	rank = ('A' + 9) - rank;
	//	cout << "Rank: " << (char)rank;
	//}

	/*Задача 2.5*/
	/*{
		float sum, mul;
		cin >> ((cout << "Enter sum: "), sum);
		cin >> ((cout << "Enter mul: "), mul);
		double D = (-sum) * (-sum) - 4 * 1 * mul;
		double x = (sum + sqrt(D)) / (2 * 1);
		double y = mul / x;
		cout << "Result: ";
		if (x < y)
			cout << x << " " << y;
		else cout << y << " " << x;
		cout << endl;
	}*/

	/*Задача 2.6*/
	/*Если дискриминант D > 0, то уравнение имеет ровно два корня, если дискриминант D = 0, то уравнение имеет ровно один корень, если дискриминант D < 0, то уравнение не имеет корней.*/
	//{
	//	float a;
	//	cin >> ((cout << "Enter a: "), a);
	//	cout << "Decisions: ";
	//	//x2 + 3x + 2 = a => x2 + 3x + (2 - a)
	//	double D = 3 * 3 - 4 * 1 * (2 - a);
	//	cout << ((D > 0) ? 2 : (D == 0) ? 1 : 0);
	//}
	
	/* Задача 2.7 */
	{
		short hours, minuts;
		cin >> ((cout << "Enter hours: "), hours);
		cin >> ((cout << "Enter minuts: "), minuts);
		short start = 9 * 60;
		short end = 18 * 60;
		short pauseStart = 13 * 60 + 30;
		short pauseEnd = 14 * 60 + 30;
		short now = hours * 60 + minuts;
		if (now > start && !(now > pauseStart && now < pauseEnd) && now < end)
			cout << "Открыто";
		else cout << "Закрыто";
		
	}

	_getch();
	return 0;
}

double evalTriangleSide(float sideA, float sideB, float angle) {
	return sqrt(sideA * sideA + sideB * sideB - 2 * sideA * sideB * cos(angle));

}

double evalTrigSquare(float sideA, float sideB, double sideC) {
	// Полупериметр
	double p = sideA;
	p = (p + sideB + sideC) / 2;
	return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

