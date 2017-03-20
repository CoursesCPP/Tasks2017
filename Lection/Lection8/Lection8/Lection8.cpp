// Lection8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "msoftcon.h"
#include <string>

using namespace std;

const int LEN = 80;       // ������������ ����� �����
enum posneg { pos, neg };

class Counter                 //������� �����
{	
protected:
	unsigned int count;       //�������
public:
	Counter() : count(0) //����������� ��� ����������
	{
		cout << "� � ������������ ��� ���������� counter\n";
	}

	Counter(int c) : count(c)
	{
		cout << "� � ������������ counter\n";
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

class CountDn : public Counter  //����������� �����
{
public:
	CountDn() : Counter()        
	{
		cout << "� � ������������ ��� ���������� counterDn\n";
	}
	CountDn(int c) : Counter(c)
	{
		cout << "� � ������������ counterDn\n";
	}
	CountDn operator-- ()           
	{
		return CountDn(--count);
	}
};

class Stack
{
protected:              
	//enum { MAX = 3 };     // ������ �����
	static const int MAX = 3;
	int st[MAX];          // ������, �������� � �����
	int top;              // ������ ���������� �������� � �����
public:
	Stack()            // �����������
	{
		top = -1; 
	}
	void push(int var) // ��������� ����� � ����
	{
		st[++top] = var;
	}
	int pop()           // ���������� ����� �� �����
	{
		return st[top--];
	}
};

class Stack2 : public Stack
{
public:
	void push(int var)      // ��������� ����� � ����
	{
		if (top >= MAX - 1)  // ���� ���� �����, �� ������
		{
			cout << "\n������: ���� �����";
			system("pause"); 
			exit(1);
		}
		Stack::push(var);   // ����� ������� push ������ Stack
	}
	int pop()                // ���������� ����� �� �����
	{
		if (top < 0)         // ���� ���� ����, �� ������
		{
			cout << "\n������: ���� ����\n"; 
			system("pause");
			exit(1);
		}
		return Stack::pop(); // ����� ������� pop ������ Stack
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
		cout << "\n������� ����: "; cin >> feet;
		cout << "������� �����: "; cin >> inches;
	}

	void showdist()
	{
		cout << feet << "\'" << inches << '\"';
	}
};


class DistSign : public Distance // ���������� ����� � �����
{
private:
	posneg sign;                 // �������� ����� ���� pos ��� neg
public:

	DistSign() : Distance()
	{
		sign = pos;
	}

	
	DistSign(int ft, float in, posneg sg = pos) : Distance(ft, in) 
	{
		sign = sg;   // ��������� ��������� �����
	}    

	void getdist()           
	{
		Distance::getdist(); 
		char ch;               
		cout << "������� ���� (+ ��� -): "; cin >> ch;
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
		cout << "\n  ������� �������: "; cin >> name;
		cout << "  ������� �����: ";     cin >> number;
	}
	void putdata() const
	{
		cout << "\n  �������: " << name;
		cout << "\n  �����: " << number;
	}
};

class manager : public employee 
{
private:
	char title[LEN];    
	double dues;         //����� ������� � �����-����
public:
	void getdata()
	{
		employee::getdata();
		cout << "  ������� ���������: "; cin >> title;
		cout << "  ������� ����� ������� � �����-����: "; cin >> dues;
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n  ���������: " << title;
		cout << "\n  ����� ������� � �����-����: " << dues;
	}
};

class scientist : public employee 
{
private:
	int pubs;                     // ���������� ����������
public:
	void getdata()
	{
		employee::getdata();
		cout << "  ������� ���������� ����������: "; cin >> pubs;
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n  ���������� ����������: " << pubs;
	}
};

class laborer : public employee   // �������
{
};

class foreman : public laborer // ��������
{
private:
	float quotas;               // ����� ���������
public:
	void getdata()
	{
		laborer::getdata();
		cout << "  ������� ����� ���������: "; cin >> quotas;
	}
	void putdata() const
	{
		laborer::putdata();
		cout << "\n  ��������: " << quotas;
	}
};
*/

class shape // ������� �����
{
protected:
	int xCo, yCo;     // ���������� ������
	color fillcolor;  // ����
	fstyle fillstyle; // ����� �����������
public:
	// ����������� ��� ����������
	shape() : xCo(0), yCo(0), fillcolor(cWHITE), fillstyle(SOLID_FILL)
	{ }
	// ����������� � ����� �����������
	shape(int x, int y, color fc, fstyle fs) : xCo(x), yCo(y), fillcolor(fc), fillstyle(fs)
	{ }
	// ������� ��������� ����� � �����
	void draw() const
	{
		set_color(fillcolor);
		set_fill_style(fillstyle);
	}
};

class circle : public shape
{
private:
	int radius; // ������, � xCo � yCo ����� ������������ ������
public:
	// ����������� ��� ����������
	circle() : shape(), radius(1)
	{ }
	// ����������� � ����� �����������
	circle(int x, int y, int r, color fc, fstyle fs) : shape(x, y, fc, fs), radius(r)
	{ }
	// ������� ��������� ����������
	void draw() const
	{
		shape::draw();
		draw_circle(xCo, yCo, radius);
	}
};

class rect : public shape
{
private:
	int width, height; // ������ � ������, � xCo � yCo ����� ������������ �������� ������� ����
public:
	// ����������� ��� ����������
	rect() : shape(), height(0), width(0)
	{ }
	// ����������� � ������ �����������
	rect(int x, int y, int h, int w, color fc, fstyle fs) : shape(x, y, fc, fs), height(h), width(w)
	{ }
	// ������� ��������� ��������������
	void draw() const
	{
		shape::draw();
		draw_rectangle(xCo, yCo, xCo + width, yCo + height);
		// �������� ���������
		set_color(cWHITE);
		draw_line(xCo, yCo, xCo + width, yCo + height);
	}
};

class tria : public shape
{
private:
	int height; // ������ ��������, � xCo � yCo ����� ������������ �������
public:
	// ����������� ��� ����������
	tria() : shape(), height(0)
	{ }
	// ����������� � ����� �����������
	tria(int x, int y, int h, color fc, fstyle fs) : shape(x, y, fc, fs), height(h)
	{ }
	// ������� ��������� ��������
	void draw() const
	{
		shape::draw();
		draw_pyramid(xCo, yCo, height);
	}
};

class A                // ������� �����
{
private:             // ��� ������� � ������ ��������� � �����
	int privdataA;     // ������� � ��������
protected:
	int protdataA;
public:
	int pubdataA;
};

class B : public A     // public ������������
{
public:
	void funct()
	{
		int a;
		//a = privdataA; // ������, ��� �������
		a = protdataA; // ��� �����
		a = pubdataA;  // ��� �����
	}
};

class C : private A    // private ������������
{
public:
	void funct()
	{
		int a;
		//a = privdataA; // ������, ��� �������
		a = protdataA; // ��� �����
		a = pubdataA;  // ��� �����
	}
};

/*
#pragma region ������������� ������������

	class student             // �������� �� �����������
	{
	private:
		char school[LEN];   // �������� �������� ���������
		char degree[LEN];   // ������� �����������
	public:
		void getedu()
		{
			cout << "  ������� �������� �������� ���������: ";
			cin >> school;
			cout << "  ������� ������� ������� �����������\n";
			cout << "  (�������� ������, ��������, �������, �������� ����): ";
			cin >> degree;
		}
		void putedu() const
		{
			cout << "\n  ������� ���������: " << school;
			cout << "\n  �������: " << degree;
		}
	};
	
	class employee            // ����� ���������
	{
	private:
		char name[LEN];     // ��� ����������
		unsigned long number; // ����� ����������
	public:
		void getdata()
		{
			cout << "\n  ������� �������: "; cin >> name;
			cout << "  ������� �����: ";     cin >> number;
		}
		void putdata() const
		{
			cout << "\n  �������: " << name;
			cout << "\n  �����: " << number;
		}
	};
	
	class manager : private employee, private student // ��������
	{
	private:
		char title[LEN];    // ��������� ����������
		double dues;          // ����� ������� � �����-����
	public:
		void getdata()
		{
			employee::getdata();
			cout << "  ������� ���������: "; cin >> title;
			cout << "  ������� ����� ������� � �����-����: "; cin >> dues;
			student::getedu();
		}
		void putdata() const
		{
			employee::putdata();
			cout << "\n  ���������: " << title;
			cout << "\n  ����� ������� � �����-����: " << dues;
			student::putedu();
		}
	};
	
	class scientist : private employee, private student // ������
	{
	private:
		int pubs;             // ���������� ����������
	public:
		void getdata()
		{
			employee::getdata();
			cout << "  ������� ���������� ����������: "; cin >> pubs;
			student::getedu();
		}
		void putdata() const
		{
			employee::putdata();
			cout << "\n  ���������� ����������: " << pubs;
			student::putedu();
		}
	};
	
	class laborer : public employee // �������
	{
	};
	
#pragma endregion
*/
class Type                  // ��� ���������
{
private:
	string dimensions;
	string grade;
public:
	// ����������� ��� ����������
	Type() : dimensions("N/A"), grade("N/A")
	{ }
	// ����������� � ����� �����������
	Type(string di, string gr) : dimensions(di), grade(gr)
	{ }
	void gettype()        // ������ ���������� � ������������
	{
		cout << "  ������� ����������� ������� (2x4 � �.�.): ";
		cin >> dimensions;
		cout << "  ������� ���� (��������������, ���� � �.�.): ";
		cin >> grade;
	}
	void showtype()       // ����� ����������
	{
		cout << "\n  �������: " << dimensions;
		cout << "\n  ����: " << grade;
	}
};

class Distance              // ���������� ���� �����
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
	void getdist()        // ������ ���������� � ������������
	{
		cout << "  ������� ����: "; cin >> feet;
		cout << "  ������� �����: "; cin >> inches;
	}
	void showdist() const // ����� ����������
	{
		cout << feet << "\'-" << inches << '\"';
	}
};

class Lumber : public Type, public Distance
{
private:
	int quantity;           // ����������
	double price;           // ���� �� �����
public:
	// ����������� ��� ����������
	Lumber() : Type(), Distance(), quantity(0), price(0.0)
	{ }
	// ����������� � ������ �����������
	Lumber(string di, string gr, // ��������� ��� Type
		int ft, float in,     // ��������� ��� Distance
		int qu, float prc) : // ���� ����������� ���������
		Type(di, gr),      // ����� ������������ Type
		Distance(ft, in),  // ����� ������������ Distance
		quantity(qu), price(prc) // ����� ����� �������������
	{ }
	void getlumber()
	{
		Type::gettype();
		Distance::getdist();
		cout << "  ������� ����������: "; cin >> quantity;
		cout << "  ������� ����: "; cin >> price;
	}
	void showlumber()
	{
		Type::showtype();
		cout << "\n  �����: ";
		Distance::showdist();
		cout << "\n  ��������� " << quantity << " ����: " << (price * quantity) << " ������";
	}
};

class D
{
public:
	void show() { cout << "������ D\n"; }
};
class E
{
public:
	void show() { cout << "������ E\n"; }
};
class F : public D, public E
{
};

class String
{
private:
	char* str;          // ��������� �� ������
public:
	String(char* s)  // ����������� � ����� ����������
	{
		str = new char[strlen(s) + 1]; // �������� ����������� �����
		strcpy(str, s);             // �������� ������
	}
	~String()         // ����������
	{
		cout << "������� ������\n";
		delete[] str; // ����������� ������
	}
	void display()    // ������� ������ �� ������
	{
		cout << str << endl;
	}
};

class person // ����� �������
{
private:
	char name[40];      // ��� ��������
public:
	void setName()       // ��������� �����
	{
		cout << "������� ���: ";
		cin >> name;
	}
	void printName()     // ����� �����
	{
		cout << "\n  ���: " << name;
	}
	string getName()  // ��������� �����
	{
		return name;
	}
};

struct link     //������� ������
{
	int data;   //��������� ������
	link* next; //��������� �� ��������� ���������
};

class linklist  //������
{
private:
	link* first;
public:
	linklist()            // ����������� ��� ����������
	{
		first = NULL;
	}     // ������� �������� ���� ���

	void additem(int d) // ���������� ��������
	{
		link* newlink = new link;      // �������� ������
		newlink->data = d;             // ���������� ������
		newlink->next = first;         // ���������� �������� first
		first = newlink;               // first ������ ��������� �� ����� �������
	}

	void display()
	{
		link* current = first;           // �������� � ������� ��������
		while (current)                 // ���� ���� ������
		{
			cout << current->data << endl; // �������� ������
			current = current->next;       // ��������� � ���������� ��������
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

#pragma region Counter ������������
	/*
	CountDn c1;                           // ������ �1
	cout << "\n c1=" << c1.get_count() << endl;   //����� �� ������
	++c1; ++c1; ++c1;                     //����������� c1 ��� ����
	cout << "\n c1=" << c1.get_count() << endl;   //����� �� ������
	--c1; --c1; //��������� c1 ��� ����
	cout << "\n c1=" << c1.get_count() << endl;
	*/
#pragma endregion

#pragma region ����� ������������ �������� ������
	/*
	CountDn c1;                            
	CountDn c2(100);

	cout << "\nc1 = " << c1.get_count(); 
	cout << "\nc2 = " << c2.get_count() << endl;

	++c1; ++c1; ++c1;                      
	cout << "\nc1 = " << c1.get_count() << endl; 

	--c2; --c2;                            
	cout << "c2 = " << c2.get_count() << endl;   

	CountDn c3 = --c2;                   // ������� ���������� c3 �� ������ c2
	cout << "\nc3 = " << c3.get_count() << endl;
	*/
#pragma endregion

#pragma region ���� ������������� ������
	/*
	Stack2 s1;

	s1.push(11); // �������� � ���� ��������� �����
	s1.push(22);
	s1.push(33);
	s1.push(44);

	cout << endl << s1.pop(); // ������� ����� �� �����
	cout << endl << s1.pop();
	cout << endl << s1.pop();
	system("pause");
	cout << endl << s1.pop() << endl;
	*/
#pragma endregion

#pragma region ��������� �� �������
	/*
	DistSign alpha;                   // ���������� ����������� �� ���������
	alpha.getdist();                // �������� ������ �� ������������

	DistSign beta(11, 6.25);       // ����������� � ����� �����������

	DistSign gamma(100, 5.5, neg); // ����������� � ����� �����������

								   // ������� ������ ��� ���� ����������
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
	// ������ ���������� � ���������� �����������
	cout << endl;
	cout << "\n���� ���������� � ������ ���������";
	m1.getdata();
	cout << "\n���� ���������� � ������ ���������";
	m2.getdata();
	cout << "\n���� ���������� � ������ ������";
	s1.getdata();
	cout << "\n���� ���������� � ������ �������";
	l1.getdata();
	// ������� ���������� ���������� �� �����
	cout << "\n���������� � ������ ���������";
	m1.putdata();
	cout << "\n���������� � ������ ���������";
	m2.putdata();
	cout << "\n���������� � ������ ������";
	s1.putdata();
	cout << "\n���������� � ������ �������";
	l1.putdata();
	cout << endl;
	*/
#pragma endregion

#pragma region �������������� ������
	/*
	init_graphics(); // �������������� ������� ����������� �������

	circle cir(40, 12, 5, cBLUE, X_FILL);      // ������� ����
	rect rec(12, 7, 10, 15, cRED, SOLID_FILL); // ������� �������������
	tria tri(60, 7, 11, cGREEN, MEDIUM_FILL);  // ������� ��������

											   // ������ ��� ���� ������
	cir.draw();
	rec.draw();
	tri.draw();

	set_cursor_pos(1, 25); // ��������� ������ � ����� ��� ������
	*/
#pragma endregion

#pragma region ���������� ���� �������
	/*
	int a;
	B objB;
	a = objB.privdataA;  // ������, ��� �������
	a = objB.protdataA;  // ������, ��� �������
	a = objB.pubdataA;   // ��� �����
	
	C objC;
	a = objC.privdataA;  // ������, ��� �������
	a = objC.protdataA;  // ������, ��� �������
	a = objC.pubdataA;   // ������, ��� �������
	*/
#pragma endregion

#pragma region Employee ������ ������������
	/*
	laborer l1;
	foreman f1;
	
	// ������ ���������� � ���������� �����������
	cout << endl;
	cout << "\n���� ���������� � ������ �������";
	l1.getdata();
	cout << "\n���� ���������� � ������ ���������";
	f1.getdata();
	
	// ������� ���������� ���������� �� �����
	cout << endl;
	cout << "\n���������� � ������ �������";
	l1.putdata();
	cout << "\n���������� � ������ ���������";
	f1.putdata();
	cout << endl;
	*/
#pragma endregion

#pragma region Employee ������������� ������������
	/*
	manager m1;
	scientist s1, s2;
	laborer l1;
	// ������ ���������� � ���������� �����������
	cout << endl;
	cout << "\n���� ���������� � ������ ���������";
	m1.getdata();
	cout << "\n���� ���������� � ������ ������";
	s1.getdata();
	cout << "\n���� ���������� � ������ ������";
	s2.getdata();
	cout << "\n���� ���������� � ������ �������";
	l1.getdata();
	// ������� ���������� ���������� �� �����
	cout << "\n���������� � ������ ���������";
	m1.putdata();
	cout << "\n���������� � ������ ������";
	s1.putdata();
	cout << "\n���������� � ������ ������";
	s2.putdata();
	cout << "\n���������� � ������ �������";
	l1.putdata();
	cout << endl;
	*/
#pragma endregion

#pragma region ������������� ������������ 2
	/*
	Lumber siding;            // ���������� ����������� ��� ����������
	
	cout << "\n  ���������� �� �������:\n";
	siding.getlumber();     // �������� ������ �� ������������
	
							// ���������� ����������� � ������ �����������
	Lumber studs("2x4", "const", 8, 0.0, 200, 4.45F);
	
	// ���������� ����������
	cout << "\n�������"; siding.showlumber();
	cout << "\n����";    studs.showlumber();
	
	cout << endl;
	*/
#pragma endregion

#pragma region �������� ����������������
/*
F objF;           // ������ ������ F
//objF.show(); // ��� ������ ������ ��������� �� �������������
objF.D::show(); // ��� �����
objF.E::show(); // ��� �����
*/
#pragma endregion

#pragma region ����������� ������������

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
//objT.func(); // ���������������: ��������� �� ��������������

#pragma endregion

#pragma region ��������� new delete
	/*
	char* str = "������� ���-������ � ���� ������";
	int len = strlen(str);        // �������� ����� ����� ������
	
	char* ptr;                       // ��������� ����������
	ptr = new char[len + 1];       // ������� ������
	
	strcpy(ptr, str);             // ��������� ������ str � ptr
	
	cout << "ptr = " << ptr << endl; // ������� ��� ���������� � ptr
	
	delete[] ptr;                   // ��������� ���������� ������
	*/
#pragma endregion

#pragma region ������������ String
	/*
	String s1 = "������� ���-������ � ���� ������";
	cout << "s1 = ";
	s1.display();
	*/
#pragma endregion

#pragma region ������ ���������� �� �������
  /*
	person* persPtr[100]; // ������ ����������
	int n = 0;            // ���������� ��������� � �������
	char choice;
	do
	{
		persPtr[n] = new person;       // ������� ����� ������
		persPtr[n]->setName();         // ������ ���
		n++;                              // ����������� ����������
		cout << "���������� ���� (y/n)?"; // ����������, �������� �� ����
		cin >> choice;
	} while (choice == 'y');
	for (int j = 0; j < n; j++)
	{
		cout << "\n���������� � ������ " << j + 1;
		persPtr[j]->printName(); // *(persPtr+j)
	}
	cout << endl;
	*/
#pragma endregion

#pragma region ������� ������
	/*
	linklist li;       // ������� ����������-������
	
	li.additem(25); // ��������� ���� ��������� �����
	li.additem(36);
	li.additem(49);
	li.additem(64);
	
	li.display();    // ���������� ������
	*/
#pragma endregion

#pragma region ���������� �������� ����� ������ ����������
    /*
	void bsort(person**, int); // �������� �������
	person* persPtr[100];      // ������ ���������� �� person
	int n = 0;                    // ���������� ��������� � �������
	char choice;                  // ���������� ��� ����� �������
	
	do
	{
		persPtr[n] = new person;       // ������� ����� ������
		persPtr[n]->setName();       // ������ ���
		n++;                              // ����������� ����������
		cout << "���������� ���� (y/n)?"; // ����������, �������� �� ����
		cin >> choice;
	} while (choice == 'y');
	
	cout << "\n����������������� ������:";
	for (int j = 0; j < n; j++) // ������� ����������������� ������
		persPtr[j]->printName();
	
	bsort(persPtr, n);         // ����������� ���������
	
	cout << "\n��������������� ������:";
	for (int j = 0; j < n; j++)     // ������� ��������������� ������
		persPtr[j]->printName();
	cout << endl;
	*/
#pragma endregion


	system("pause");
    return 0;
}

void bsort(person** pp, int n)
{
	void order(person**, person**); // �������� �������
	                          // ���������� ��� ������
	for (int j = 0; j < n - 1; j++)      // ������� ����
		for (int k = j + 1; k < n; k++)    // ���������� ����
			order(pp + j, pp + k);      // ��������� ��� ��������
}

void order(person** pp1, person** pp2)
{
	if ((*pp1)->getName() >(*pp2)->getName()) // ���� ������ ������ ������ ������,
	{
		person* tempptr = *pp1; // ������ �� �������
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}