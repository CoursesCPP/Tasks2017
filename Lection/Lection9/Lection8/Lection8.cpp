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


const int LEN = 80;       // ������������ ����� ���������
const int MAX = 40;

class Stack
{
private:
	char st[MAX];         // ������ ������
	int top;              // ���������� ����������� ������
public:
	Stack()
	{
		top = 0;
	}
	void push(char var)  // ��������� � ����
	{
		st[++top] = var;
	}
	char pop()           // ����� �� �����
	{
		return st[top--];
	}
	int gettop()         // ������ ���������� ���������
	{
		return top;
	}
};

class express
{
private:
	Stack s;                   // ���� ������
	char* pStr;                // ������ ��� �����
	int len;                   // ����� ������
public:
	express(char* ptr)      // �����������
	{
		pStr = ptr;            // ���������� ��������� �� ������
		len = strlen(pStr);    // ������������� �����
	}

	void parse()              // ��������� ������ � ����
	{
		char ch;              // ������ �� ������
		char lastval;         // ��������� ��������
		char lastop;          // ��������� ��������

		for (int j = 0; j < len; j++) // ��� ���� �������� � ������
		{
			ch = pStr[j];    // �������� ������

			if (ch >= '0' && ch <= '9') // ���� ��� �����,
				s.push(ch - '0');        // �� ��������� �� ��������
			else
				if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
				{
					if (s.gettop() == 1)    // ���� ��� ������ ��������,
						s.push(ch);         // �������� ��� � ����
					else // �����
					{
						lastval = s.pop(); // �������� ���������� �����
						lastop = s.pop();  // �������� ���������� ��������
										   // ���� ��� * ��� /, � ���������� ��� + ��� -, ��
						if ((ch == '*' || ch == '/') && (lastop == '+' || lastop == '-'))
						{
							s.push(lastop); // �������� ��������� ��� ������ �� �����
							s.push(lastval);
						}
						else
						{
							// �������� � ���� ��������� ��������
							switch (lastop)
							{
							case '+': s.push(s.pop() + lastval); break;
							case '-': s.push(s.pop() - lastval); break;
							case '*': s.push(s.pop() * lastval); break;
							case '/': s.push(s.pop() / lastval); break;
							default: cout << "\n����������� ��������"; exit(1);
							}
						}
						s.push(ch); // �������� � ���� ������� ��������
					}
				}
				else
				{
					cout << "\n����������� ������";
					exit(1);
				}
		}
	}


	int solve()				 // ������� ������ �� �����
	{
		char lastval;        // ���������� ��������

		while (s.gettop() > 1)
		{
			lastval = s.pop(); // �������� ���������� ��������
			switch (s.pop()) // �������� ���������� ��������
			{
			case '+': s.push(s.pop() + lastval); break;
			case '-': s.push(s.pop() - lastval); break;
			case '*': s.push(s.pop() * lastval); break;
			case '/': s.push(s.pop() / lastval); break;
			default: cout << "\n����������� ��������"; exit(1);
			}
		}
		return int(s.pop()); // ��������� �������� � ����� � ��� ���������
	}
};

#pragma region 1
/*
class Base                //������� �����
{
	public:
	void  show()           //������� �������
	{
		cout << "Base\n";
	}
};

class Derv1 : public Base //����������� ����� 1
{
	public:
	void  show()
	{
		cout << "Derv1\n";
	}
};

class Derv2 : public Base //����������� ����� 2
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
class Base                //������� �����
{
public:
	virtual void  show()    //����������� �������
	{
		cout << "Base\n";
	}
};

class Derv1 : public Base //����������� ����� 1
{
public:
	void  show()
	{
		cout << "Derv1\n";
	}
};

class Derv2 : public Base //����������� ����� 2
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
class Base                   //����������� �����
{
public:
	virtual void show() = 0; //������ ����������� �������
						//�������� ������ �� �������������
};

class Derv1 : public Base    //����������� ����� 1
{
public:
void show()
{
cout << "Derv1\n" ;
}
};

class Derv2 : public Base    //����������� ����� 2
{
public:
void show()
{
cout << "Derv2\n" ;
}
};

*/
#pragma endregion

class person                    //����� person
{
protected:
	char name[40];
public:
	void getName()
	{
		cout << "  ������� ���: "; cin >> name;
	}
	void putName()
	{
		cout << "  Name: " << name << endl;
	}
	virtual void getData() = 0;       //������
	virtual bool isOutstanding() = 0; //�����������
									  //�������
};

class student : public person   //����� student
{
private:
	float gpa;                //������� ����
public:
	void getData()            //��������� ������ �� ������� 
	{
		person::getName();
		cout << "  ������� ���� �������:  "; cin >> gpa;
	}
	bool isOutstanding()
	{
		return (gpa > 3.5) ? true : false;
	}
};

class professor : public person //����� professor
{
private:
	int numPubs;              //����� ����������
public:
	void getData()            //��������� ������ � �������� �
	{                       //������������
		person::getName();
		cout << "  ����� ����������:  "; cin >> numPubs;
	}
	bool isOutstanding()
	{
		return (numPubs > 100) ? true : false;
	}
};


class shape                   //������� �����
{
protected:
	int xCo, yCo;           //���������� ������
	color fillcolor;        //����
	fstyle fillstyle;       //����������
public:                     //����������� ��� ����������
	shape() : xCo(0), yCo(0), fillcolor(cWHITE),
		fillstyle(SOLID_FILL)
	{  }                 //����������� � �������� �����������
	shape(int x, int y, color fc, fstyle fs) :
		xCo(x), yCo(y), fillcolor(fc), fillstyle(fs)
	{  }
	virtual void draw() = 0 //������ ����������� �������
	{
		set_color(fillcolor);
		set_fill_style(fillstyle);
	}
};

class ball : public shape
{
private:
	int radius;          //����� � ������������(xCo, yCo)
public:
	ball() : shape()     //����������� ��� ����������
	{  }
	//����������� � ����� �����������
	ball(int x, int y, int r, color fc, fstyle fs)
		: shape(x, y, fc, fs), radius(r)
	{  }
	void draw()          //���������� �����
	{
		shape::draw();
		draw_circle(xCo, yCo, radius);
	}
};

class rect : public shape
{
private:
	int width, height;   //(xCo, yCo) - ������� ����� ����
public:
	rect() : shape(), height(0), width(0) //����������� ��� ����������
	{  }              //����������� � ������ �����������
	rect(int x, int y, int h, int w, color fc, fstyle fs) :
		shape(x, y, fc, fs), height(h), width(w)
	{  }
	void draw()             //���������� �������������
	{
		shape::draw();
		draw_rectangle(xCo, yCo, xCo + width, yCo + height);
		set_color(cWHITE);   //���������� ���������
		draw_line(xCo, yCo, xCo + width, yCo + height);
	}
};

class tria : public shape
{
private:
	int height;                 //(xCo, yCo) - ������� ��������
public:
	tria() : shape(), height(0) //����������� ��� ����������
	{ }                      //����������� � ����� �����������
	tria(int x, int y, int h, color fc, fstyle fs) :
		shape(x, y, fc, fs), height(h)
	{  }
	void draw()                 //���������� �����������
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
	//~Base()             //������������� ����������
	virtual ~Base()         //����������� ����������
	{
		cout << "Base ������\n";
	}
};

class Derv : public Base
{
public:
	~Derv()
	{
		cout << "Derv ������\n";
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
		//return basedata; //������: ���������������
	}
};

class beta;              //����� ��� ���������� frifunc
class alpha
{
private:
	int data;
public:
	alpha() : data(3) {  }   //����������� ��� ����������
	friend int frifunc(alpha, beta); //������������� �������
};

class beta
{
private:
	int data;
public:
	beta() : data(7) {  }     //����������� ��� ����������
	friend int frifunc(alpha, beta);       //������������� �������
};

int frifunc(alpha a, beta b)           //����������� �������
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
	Distance(float fltfeet)           //��������� float � Distance
	{
		feet = static_cast<int>(fltfeet);
		inches = 12 * (fltfeet - feet);
	}
	Distance(int ft, float in)
	{
		feet = ft; inches = in;
	}
	void showdist()                    //����� �� ����� ����������
	{
		cout << feet << "\'-" << inches << '\"';
	}
	//Distance operator + (Distance);
	//friend Distance operator + (Distance, Distance); //�������������
	/*
	float square()		//���������� �������
	{
		float fltfeet = feet + inches / 12;	 //������� �� float
		float feetsqrd = fltfeet * fltfeet;  //���������� � �������
		return feetsqrd;
	}*/

	friend float square(Distance); //������������� �-���
};
/*
Distance Distance::operator + (Distance d2) //�����
{
	int f = feet + d2.feet;       //�������� ����
	float i = inches + d2.inches; //�������� �����
	if (i >= 12.0)                //���� ����� ��������� 12.0,
		{
			i -= 12.0; f++;
		}
	return Distance(f, i);         //����� Distance � ������
}

Distance operator + (Distance d1, Distance d2) // d1 + d2
{
	int f = d1.feet + d2.feet;       //+ ����
	float i = d1.inches + d2.inches; //+ �����
	if (i >= 12.0)                    //���� ������ 12 ������,
	{
		i -= 12.0; f++;
	}           //��������� �� 12 ������,
				//��������� 1 ���
	return Distance(f, i);            //����� ����� � ������
}

*/

float square(Distance d)                //������� �������
{                                     //����������
	float fltfeet = d.feet + d.inches / 12; //�������������� 
											//� ��� float
	float feetsqrd = fltfeet * fltfeet;   //��������� �������
	return feetsqrd;                      //������� ���������� ����
}


class gamma
{
private:
	int data1;
public:
	gamma() : data1(99) {  }  //�����������
	friend class delta;        //delta - ������������� �����
};

class delta
{     //��� ������ ����� ������ � ������� ������ gamma
public:
	void func1(gamma a) { cout << "\ndata1=" << a.data1; }
	void func2(gamma a) { cout << "\ndata1=" << a.data1; }
};

class tetta
{
private:
	static int total;       //����� �������� ������
	int id;                 //ID �������� �������
public:
	tetta()                 //����������� ��� ����������
	{
		total++;              //�������� ������
		id = total;           //id ����� �������� �������� total
	}
	~tetta()                //����������
	{
		total--;
		cout << "�������� ID " << id << endl;
	}
	static void showtotal() // ����������� �������
	{
		cout << "�����: " << total << endl;
	}
	void showid()           // ������������� �������
	{
		cout << "ID: " << id << endl;
	}
};

int tetta::total = 0;       // ����������� total

class alphaq
{
private:
	int data;
public:
	alphaq()                     //����������� ��� ����������
	{ }
	alphaq(int d)                //����������� � ����� ����������
	{
		data = d;
	}
	void display()              //������� ������
	{
		cout << data;
	}
	alphaq operator = (alphaq& a) //������������� = 
	{
		data = a.data;             //�� ����������� �������������
		cout << "\n������� �������� ������������";
		return alphaq(data);       //���������� ����� alphaq
	}
};


class where
{
private:
	char charray[10];  //������ �� 10 ������
public:
	void reveal()
	{
		cout << "\n��� ����� - " << this;
	}
};

class what
{
private:
	int alpha;
public:
	void tester()
	{
		this->alpha = 11;    //�� ��,��� alpha = 11;
		cout << this->alpha; //�� ��, ��� cout <<
							 //alpha;
	}
};

class alphathis
{
private:
	int data;
public:
	alphathis()                      // ����������� ��� ����������
	{ }
	alphathis(int d)                 // ����������� � ����� ����������
	{
		data = d;
	}
	void display()               // ������� ������
	{
		cout << data;
	}

	alphathis& operator = (alphathis& a) // ������������� �������� =
	{
		data = a.data;             // �� �������� �������������
		cout << "\n������� �������� ������������";
		return *this;              // ������� this alpha
	}
};




int main()
{
	setlocale(LC_ALL, "Russian");

#pragma region ������ �������������� ���������
	/*
	char ans;            // 'y' ��� 'n'
	char string[LEN]; // ������ ��� �������

	cout << "\n������� �������������� ��������� � ���� 2+3*4/3-2"
		    "\n����� ������ ���� �� ����� �����"
		    "\n�� ����������� ������� � ������";
	do
	{
		cout << "\n���������: ";
		cin >> string;                          // ������ ������
		express* eptr = new express(string);    // ������� ������ ��� �������
		eptr->parse();                          // ���������
		cout << "\n���������: "
			<< eptr->solve();                   // ������
		delete eptr;                            // ������� ������
		cout << "\n��� ���� ��������� (y/n)? ";
		cin >> ans;
	} while (ans == 'y');
	*/
#pragma endregion

#pragma region ������ � ������� ����� ��������� (1)
	/*
	Derv1 dv1;          //������ ������������ ������ 1
	Derv2 dv2;          //������ ������������ ������ 2
	Base* ptr;          //��������� �� ������� �����

	ptr = &dv1;         //����� dv1 ������� � ���������
	ptr->show();        //��������� show()
	ptr = &dv2;         //����� dv2 ������� � ���������
	ptr->show();        //��������� show()
	*/
	//����� - ���������� �� ������� �� ����������, � �������� �����
	//������� ������������� ���� ���������.
	
#pragma endregion

#pragma region ������ � ����������� ������� ����� ��������� (2)
	/*
	Derv1 dv1;            //������ ������������ ������ 1
	Derv2 dv2;            //������ ������������ ������ 2
	Base* ptr;            //��������� �� ������� �����

	ptr = &dv1;            //����� dv1 ������� � ���������
	ptr->show();           //��������� show()
	ptr = &dv2;            //����� dv2 ������� � ���������
	ptr->show();           //��������� show()
	*/
#pragma endregion

#pragma region ������ ����������� ������� (3)
	/*
	//Base bad;                 //���������� ������� ������
	//�� ������������ ������
	Base* arr[2];              //������ ���������� ��
							   //������� �����
	Derv1 dv1;                 //������ ������������ ������ 1
	Derv2 dv2;                 //������ ������������ ������ 2

	arr[0] = &dv1;             //������� ����� dv1 � ������
	arr[1] = &dv2;             //������� ����� dv2 � ������

	arr[0]->show();            //��������� ������� show()
	arr[1]->show();            //��� ������ ���������
	*/
#pragma endregion

#pragma region ����������� �������
	
	person* persPtr[100];  //������ ���������� �� person
	int n = 0;            //����� �����, ��������� � ������ char choice;
	char choice;
	do {
		cout << " �������� (s) ��� ������� (p): ";
		cin >> choice;
		if (choice == 's')               //������� ������ ������� � ������
			persPtr[n] = new student;   
		else                          //������� ������ �������� � ������
			persPtr[n] = new professor; 
		persPtr[n++]->getData();       //������ ������ � �������
		cout << " ������ ��� ������� (y/n)? "; 
		cin >> choice;
	} while (choice == 'y');       //����, ���� ����� 'y'
	for (int j = 0; j<n; j++)
	{
		persPtr[j]->putName();        //������� ��� �����,
		if (persPtr[j]->isOutstanding())        
			cout << "  ��� ���������� �������!\n"; //�������� � ����������
	}
	
#pragma endregion

#pragma region ����������� ������� � ��������
	/*
	init_graphics();             //������������� �������
	shape* pShapes[3];           //������ ���������� �� ������
								 //���������� ��� ������
	pShapes[0] = new ball(40, 12, 5, cBLUE, X_FILL);
	pShapes[1] = new rect(12, 7, 10, 15, cRED, SOLID_FILL);
	pShapes[2] = new tria(60, 7, 11, cGREEN, MEDIUM_FILL);

	for (int j = 0; j<3; j++)           //���������� ��� ������
		pShapes[j]->draw();

	for (int j = 0; j<3; j++)           //������� ��� ������
		delete pShapes[j];
	set_cursor_pos(1, 25);
	*/
#pragma endregion

#pragma region ����������� �����������
	/*
	Base* pBase = new Derv;
	delete pBase;
	*/
	//����� ���� ���������, ��� ������� ����������� ������� ��������� 
	//��� �����, ������� ������ ����������� � ������� ������� ������������
	
#pragma endregion

#pragma region ������������� �������
	/*	
	alpha aa;
	beta bb;
	
	cout << frifunc(aa, bb) << endl;   //����� �������
	*/
#pragma endregion

#pragma region ����������� ����������
	/*
	Distance d1 = 2.5;         //����������� ���������
	Distance d2 = 1.25;        //float-feet � Distance
	Distance d3;
	cout << "\nd1 = "; d1.showdist();
	cout << "\nd2 = "; d2.showdist();
	
	d3 = d1 + 10.0;            //distance + float: OK
	cout << "\nd3 = "; d3.showdist();
	d3 = 10.0 + d1;            //float + Distance: ��OK
	cout << "\nd3 = "; d3.showdist();
	cout << endl;
	*/
#pragma endregion

#pragma region ��� ���� ������������� �������
	/*
	Distance dist(3, 6.0);	
	float sqft;
	
	//sqft = dist.square();	//��������� ������� ����������
	sqft = square(dist);   //������� ������� dist
	cout << "\n���������� = "; dist.showdist();
	cout << "\n������� ���������� = " << sqft << " ��. �����\n";
	*/
#pragma endregion

#pragma region ������������� ������
	/*
	gamma a;
	delta b;
	
	b.func1(a);
	b.func2(a);
	cout << endl;
	*/
#pragma endregion

#pragma region ����������� ������� � ID ��������
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

#pragma region ���������� ��������� ������������
	/*
	alphaq a1(37);
	alphaq a2;
	
	a2 = a1;                       //������ �������������� =
	cout << "\na2="; a2.display(); //������� a2
	
	alphaq a3 = a2;                 //�� ����������� - ��� �������������
	cout << "\na3="; a3.display(); //������� a3
	cout << endl;
	*/
#pragma endregion

#pragma region ��������� this
	/*
	where w1, w2, w3;    //������� ��� �������
	w1.reveal();         //����������, ��� ��� ���������
	w2.reveal();
	w3.reveal();
	cout << endl;
	*/
#pragma endregion

#pragma region ������ this �� ������
	/*
	what w;
	w.tester();
	cout << endl;
	*/
#pragma endregion

#pragma region ������� ����������� ��������� this
	/*
	alphathis a1(37);
	alphathis a2, a3;
	
	a3 = a2 = a1;                  // ������������� =, ������
	cout << "\na2="; a2.display(); // ������� a2
	cout << "\na3="; a3.display(); // ������� a3
	cout << endl;
	*/
#pragma endregion

	system("pause");
    return 0;
}

