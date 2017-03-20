// Lection5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "msoftcon.h"

using namespace std;

class Smallobj               // ����������� ������
{
private:
	int somedata;            // ���� ������
public:
	void setdata(int d)      // ����� ������, ���������� �������� ����
	{
		somedata = d;
	}
	void getdata()          // ����� ������, ������������ �������� ����
	{
		cout << "�������� ���� ����� " << somedata << endl;
	}
};

class Part                  // ����������� ������
{
private:
	int modelnumber;           // ����� �������
	int partnumber;            // ����� ������
	float cost;                // ��������� ������
public:
	// ��������� ������
	void setpart(int mn, int pn, float c)
	{
		modelnumber = mn;
		partnumber = pn;
		cost = c;
	}
	void showpart()          // ����� ������
	{
		cout << "������ " << modelnumber;
		cout << ", ������ " << partnumber;
		cout << ", ��������� $" << cost << endl;
	}
};

class Circle                 //����������� ������ "����"
{
private:
	int xCo, yCo;             // ���������� ������
	int radius;
	color fillcolor;         // ����
	fstyle fillstyle;        // ����� ����������
public:                    // ��������� ��������� �����
	
	Circle(int x, int y, int r, color fc, fstyle fs) 
		: xCo(x), yCo(y), radius(r), fillcolor(fc), fillstyle(fs)
	{
		cout << "������ � ������ x ="<< x << endl;
	}

	void setX(int x)
	{
		xCo = x;
	}
	void setY(int y)
	{
		yCo = y;
	}
	void draw()                    // ��������� �����
	{
		set_color(fillcolor);        // ��������� ����� �
		set_fill_style(fillstyle);   // ����� ����������
		draw_circle(xCo, yCo, radius); // ��������� �����
	}
};

class Distance                       // ����� � ���������� �������
{
private:
	int feet;
	float inches;
public:
	
	// ����������� ��� ����������
	Distance() : feet(0), inches(0.0)
	{ }
	// ����������� � ����� �����������		
	Distance(int ft, float in) : feet(ft), inches(in)
	{ }
	
	void setdist(int ft, float in)  // ��������� �������� �����
	{
		feet = ft; inches = in;
	}
	void getdist()                   // ���� ����� � ����������
	{
		cout << "\n������� ����� �����: "; cin >> feet;
		cout << "������� ����� ������: "; cin >> inches;
	}
	void showdist();                  // ����� ����� �� �����
	void add_dist(Distance, Distance); // ��������
	Distance add_dist(Distance);       // ��������-��������
};

void Distance::showdist()                  // ����� ����� �� �����
{
	cout << feet << "'-" << inches << '"';
}

void Distance::add_dist(Distance d1, Distance d2) //����� ������ ��� ������
{
	//:: - �������� ����������� ����������, Distance::add_dist - ������� add_dist, �������� ������� ������ Distance

	inches = d1.inches + d2.inches;        // �������� ������
	if (inches >= 12.0)                     // ���� ����� ������ ������ 12.0,
	{                                      // �� ��������� ����� ������
		inches -= 12.0;                      // �� 12.0 � �����������
		feet = 1;                              // ����� ����� �� 1
	}
	feet += d1.feet + d2.feet;             // �������� �����
}

Distance Distance::add_dist(Distance d2)
{
	Distance temp;                    // ��������� ����������
	temp.inches = inches + d2.inches; // �������� ������
	if (temp.inches >= 12.0)           // ���� ����� ������ 12.0,
	{                                 // �� ��������� �� �� 
		temp.inches -= 12.0;            // 12.0 � �����������
		temp.feet = 1;                  // ����� ����� �� 1
	}
	temp.feet += feet + d2.feet;      // �������� �����
	return temp;
}

class Counter
{
private:
	unsigned int count;         // �������� ��������
public:
	Counter() : count(0)        // �����������
	{ /* ������ ���� */
	}
	void inc_count()            // ����������������� ��������
	{
		count++;
	}
	int get_count()             // ��������� �������� ��������
	{
		return count;
	}
};

class foo
{
private:
	static int count;        // ����� ���� ��� ���� ��������
							 // (� ������ "����������")
public:
	foo()                    // ����������������� ��� �������� �������
	{
		count++;
	}
	int getcount()           // ���������� �������� count
	{
		return count;
	}
};
int foo::count = 0;          // *�����������* count
class ConstDistance                  
{
private:
	int feet;
	float inches;
public:                       // ����������� ��� ����������
	ConstDistance() : feet(0), inches(0.0)
	{ }                       // ����������� � ���� �����������
	ConstDistance(int ft, float in) : feet(ft), inches(in)
	{ }
	void getdist()              // ���� ����� �������������
	{
		cout << "\n������� ����� �����: "; cin >> feet;
		cout << "������� ����� ������: "; cin >> inches;
	}
	void showdist()const        // ����� �����
	{
		cout << feet << "\'-" << inches << '\"';
	}
	//ConstDistance add_dist(ConstDistance&) const; // ��������
	ConstDistance add_dist(const ConstDistance &d2)const // �������� ������� ������� � d2, ������� �����
{
	ConstDistance temp;                // ��������� ���������
	//feet = 0;                  // ������: ������ �������� ����
	//d2.feet = 0;               // ������: ������ �������� d2
	temp.inches = inches + d2.inches; // �������� ������
	if (temp.inches >= 12.0)     // ���� ����� ��������� 12.0,
	{                             // �� ��������� �� �� 12.0
		temp.inches -= 12.0;        // � ����������� ����� �����
		temp.feet = 1;              // �� 1
	}
	temp.feet += feet + d2.feet;  // �������� �����
	return temp;
}
};



int main()
{
	setlocale(LC_ALL, "Russian");

#pragma region ������� �����
	/*
	Smallobj s1, s2;           // ����������� ���� �������� ������ smallobj
	s1.setdata(1066);          // ������ ������ setdata()
	s2.setdata(1776);
	s1.getdata();             // ������ ������ showdata()
	s2.getdata();
	*/
#pragma endregion

#pragma region ����� part
	/*
	Part part1;                // ����������� ������� ������ part
	part1.setpart(6244, 373, 217.55F); // ����� ������
	part1.showpart();                 // ����� ������
	*/
#pragma endregion

#pragma region �����
	/*
	init_graphics();           // ������������� �������
	Circle c1(15, 7, 5, cBLUE, X_FILL); // �������� ������
	Circle c2(41, 12, 7, cRED, O_FILL);
	Circle c3(65, 18, 4, cGREEN, MEDIUM_FILL);
	// ��������� ��������� ������
	c1.draw();                 // ��������� ������
	c2.draw();
	c3.draw();
	set_cursor_pos(1, 25);      // ������ ����� ����
	*/
#pragma endregion

#pragma region ����� - ��� ������
	/*
	Distance dist1, dist2;              // ��� �����
	Distance dist3(111, 6.25);
	dist1.setdist(11, 6.25);            // ��������� �������� �� d1
	dist2.getdist();                    // ���� �������� �� dist2
									    // ����� ���� �� �����
	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
	cout << endl;
	*/
#pragma endregion

#pragma region �������
	/*
	Counter c1, c2;               // ����������� � ��������������
	cout << "\nc1=" << c1.get_count(); // �����
	cout << "\nc2=" << c2.get_count();
	c1.inc_count();               // ����������������� c1
	c2.inc_count();               // ����������������� c2
	c2.inc_count();               // ����������������� c2
	c2.inc_count();
	cout << "\nc1=" << c1.get_count(); // �����
	cout << "\nc2=" << c2.get_count();
	cout << endl;
	*/
#pragma endregion

#pragma region ����� � �������������
	/*
	init_graphics();                // ������������� �������
	// �������� ������
	Circle c1(15, 7, 5, cBLUE, X_FILL);
	Circle c2(41, 12, 7, cRED, O_FILL);
	Circle c3(65, 18, 4, cGREEN, MEDIUM_FILL);
	c1.draw();                      // ��������� ������
	c2.draw();
	c3.draw();
	set_cursor_pos(1, 25);          // ����� ������ ����
	*/
#pragma endregion

#pragma region ��������� � ��������������
	/*
	Distance dist1, dist3;        // ��� �����
	Distance dist2(11, 6.25);     // ����������� � �������������
	dist1.getdist();              // ���� dist1
	dist3.add_dist(dist1, dist2);  // dist3 = dist1 + dist2
								   // ����� ���� ����
	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
	cout << endl;
	*/
#pragma endregion

#pragma region ���������, ���������� �����������
	/*
	Distance dist1(11, 6.25);  // ����������� � ���� �����������
	Distance dist2(dist1);     // ��� ������������ � ����� ����������
	Distance dist3 = dist1;
	// ����� ���� ����
	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
	cout << endl;
	*/
#pragma endregion

#pragma region ���������, ������, ������������ ��������
	/*
	Distance dist1, dist3;            // ��� �����
	Distance dist2(11, 6.25);         // ����������� � ������������� dist2
	dist1.getdist();                  // ���� dist1 �������������
	dist3.add_dist(dist1, dist2);     // dist3 = dist1 + dist2
	dist3 = dist1.add_dist(dist2);    // dist3 = dist1 + dist2

									  // ����� ���� ����
	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
	cout << endl;
	*/
#pragma endregion

#pragma region Static ��� ����������� ���� ������

	// �������� ���� ��������
	foo f1;
	cout << "����� ��������: " << f1.getcount() << endl;
	foo	f2;
	cout << "����� ��������: " << f2.getcount() << endl;
	foo f3;           					
	cout << "����� ��������: " << f3.getcount() << endl;
	
#pragma endregion

#pragma region ����������� ������
	/*
	ConstDistance dist1, dist3;        // ��� �����
	ConstDistance dist2(11, 6.25);     // ����������� � ������������ dist2
	dist1.getdist();              // ���� dist1
	dist3 = dist1.add_dist(dist2);//dist3 = dist1 + dist2
	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
	cout << endl;
	*/
#pragma endregion

#pragma region ����������� �������
    /*
	const ConstDistance football(300, 0);
	//football.getdist();      // ������: ����� getdist() �������������
	cout << " ����� ��� �����: ";
	football.showdist();       // ���������
	cout << endl;
	*/
#pragma endregion

	system("pause");
    return 0;
}

