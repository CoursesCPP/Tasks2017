// Lection7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
   


using namespace std;

enum Suit { clubs, diamonds, hearts, spades };
// �� 2 �� 10 ������� �����
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

const int DISTRICTS = 4;
const int MONTHS = 3;

const int LIMIT = 100;  // ������ �������

void display(double funsales[DISTRICTS][MONTHS])
{
	int d, m;

	cout << "\n\n";
	cout << "                        �����\n";
	cout << "                1         2         3";

	for (d = 0; d < DISTRICTS; d++)
	{
		cout << "\n����� " << d + 1;
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
	//enum { MAX = 10 };  // ������� ������������� ���������
	static const int MAX = 10;
	int st[MAX];        // ���� � ���� �������
	int top;            // ������� �����
public:
	Stack() : top(0) // �����������
	{ }

	void push(int var) // ��������� � ����
	{
		//��������� �� ����. �������, ������� ���������� �������� �����
		st[++top] = var; 
	}
	int pop() // ����� �� �����
	{
		//������ ������������ ��������, � ����� ���������� ����� ������� �����
		return st[top--];
	}
};

class Distance
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
	void getdist() // ��������� ����������
	{
		cout << "\n  ������� ����: "; cin >> feet;
		cout << "  ������� �����: "; cin >> inches;
	}
	void showdist() const // ����� ����������
	{
		cout << feet << "\'-" << inches << '\"';
	}

	Distance operator+ (Distance d2) const
	{
		int f = feet + d2.feet;       // ���������� ����
		float i = inches + d2.inches; // ���������� �����
		if (i >= 12.0)                // ���� ������ ����� ������ 12
		{
			i -= 12.0;                  // �� ��������� ����� �� 12
			f++;                        // � ����������� ���� �� 1
		}
		return Distance(f, i);     // ������� � ���������� ��������� ����������
	}

	bool operator< (Distance qwerty) const
	{
		float bf1 = feet + inches / 12;
		float bf2 = qwerty.feet + qwerty.inches / 12;
		return (bf1 < bf2) ? true : false;
	}

	void operator+= (Distance d2)
	{
		feet += d2.feet;      // ���������� ����
		inches += d2.inches;  // ���������� �����
		if (inches >= 12.0) // ���� ������ ������ 12
		{
			inches -= 12.0;     // �� ��������� ����� �� 12
			feet++;             // ����������� ���� �� 1
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
		return Counter(++count);	//����������������� ����������
	}

	Counter operator++ (int)
	{
		return Counter(count++);
	}

	Counter operator-- ()
	{
		return Counter(--count);	//����������������� ����������
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
	void set(int n, Suit s) // ��������� ��������
	{
		suit = s; number = n;
	}
	void display()          // ����� �����
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
		case clubs: cout << static_cast<char>(5); break;   //�����
		case diamonds: cout << static_cast<char>(4); break;//����
		case hearts: cout << static_cast<char>(3); break;  //�����
		case spades: cout << static_cast<char>(6); break;  //����
		}
	}
};

class String          
{
private:
	static const int Size = 80;		//������������ ������ ������
	char str[Size];					//������ ��� ������
public:
	// ����������� ��� ����������
	String() : str("")
	{ }
	
	// ����������� � ����� ����������
	String(char s[])
	{
		strcpy(str, s);			// �������� s � str
	}

	// ����� ������
	void display() const
	{
		cout << str;
	}
	// �������� ��������
	String operator+ (String ss) const
	{
		String temp;  // ��������� ����������
		if (strlen(str) + strlen(ss.str) < Size)
		{
			strcpy(temp.str, str);    // �������� ���������� ������ ������
			strcat(temp.str, ss.str); // ��������� ���������� ������ ������
		}
		else
		{
			cout << "\n������������!";
			exit(1);
		}
		return temp;  // ���������� ���������
	}
	// ��������� ������
	void getstr()
	{
		cin.get(str, Size);
	}

	// �������� ���������
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

	//������� ������ � �������� ����
	operator char* ()
	{
		return str;
	}
};

class safearray
{
	// ������������ �������� ����������� �������, ������������
	// ���� ������� ��� �������������
	// ������������ ����� ������� ��� ��������� � ��������� ��������
private:
	int arr[LIMIT];
public:
	// ��������� �������� �������� �������
	void putelem(int n, int value)
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\n��������� ������!"; exit(1);
		}
		arr[n] = value;
	}
	// ��������� �������� �������� �������
	int getelem(int n) const
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\n��������� ������!"; exit(2);
		}
		return arr[n];
	}

	// �������� ��������, ��� ������� ���������� ������!
	int& access(int n)
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\n��������� ������!"; 
			exit(3);
		}
		return arr[n];
	}

	// �������� ��������, ��� ������� ���������� ������!
	int& operator[] (int n)
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\n��������� ������!"; exit(1);
		}
		return arr[n];
	}
};

class DistMetr         // ����� ���������� ��� �����
{
private:
	const float MTF = 3.280833F;    // ����������� �������� ������ � ����
	int feet;
	float inches;
public:
	// ����������� ��� ����������
	DistMetr() : feet(0), inches(0.0)
	{ }
	// ����������� � ����� ����������,
	// ����������� ����� � ���� � �����
	// ��� ����������� ��������������
	DistMetr(float meters)
	{
		float fltfeet = MTF * meters;     // ��������� � ����
		feet = int(fltfeet);              // ����� ����� ������ �����
		inches = 12 * (fltfeet - feet);   // ������� - ��� �����
	}

	// ����������� � ����� �����������
	DistMetr(int ft, float in) : feet(ft), inches(in)
	{ }
	// ��������� ���������� �� ������������
	void getdist()
	{
		cout << "\n������� ����: "; cin >> feet;
		cout << "������� �����: ";  cin >> inches;
	}
	// ����� ����������
	void showdist() const
	{
		cout << feet << "\'-" << inches << '\"';
	}

	// �������� �������� ��� ��������� ������ �� �����
	operator float() const
	{
		float fracfeet = inches / 12;           // ��������� ����� � ����
		fracfeet += float(feet);   // ��������� ����� ����
		return fracfeet / MTF;                  // ��������� � �����
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
	cout << "(� ����� � ������) = ";
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

#pragma region ������� �������������� ��������� �������
	/*
	const int SIZE = 6;
	double num[SIZE];
	double total = 0;

	cout << "������� ������������ �����:\n";
	for (int i = 0; i < SIZE; i++)
	{
		cin >> num[i];
		total += num[i];
	}
	double mean = total / SIZE;
	cout << "������� ��������������: " << mean << endl;
	*/
#pragma endregion

#pragma region ��� � ������
	/*
	int month, day, total_days;
	int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cout << "\n������� ����� (�� 1 �� 12): ";
	cin >> month;
	cout << "\n������� ���� (�� 1 �� " << days_per_month[month-1] << "): ";
	cin >> day;
	total_days = day;
	for (int j = 0; j < (month - 1); j++)
	{
		total_days += days_per_month[j];
	}
	cout << "����� ����� ���� � ������ ����: " << total_days << endl;
	*/
#pragma endregion

#pragma region ����������� �������
	/*
	int d, m;
	double sales[DISTRICTS][MONTHS];

	cout << endl;
	for (d = 0; d < DISTRICTS; d++)
	for (m = 0; m < MONTHS; m++)
	{
			cout << "������� ����� ������ ��� ������ " << d + 1;
			cout << ", �� ����� " << m + 1 << ": ";
			cin >> sales[d][m];
	}
	
	
	cout << "\n\n";
	cout << "                        �����\n";
	cout << "                1         2         3";
	for (d = 0; d < DISTRICTS; d++)
	{
		cout << "\n����� " << d + 1;
		for (m = 0; m < MONTHS; m++)
		{
			cout  << setprecision(8)  //8 ������ 
			<< setw(10)			//������ ������ �� 10 ��������
			<< sales[d][m];
		}
	}
	cout << endl;
	*/
#pragma endregion

#pragma region �������� � �������
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

#pragma region ������ �� �����������
	/*
	const int SIZE = 4;
	int n;
	part apart[SIZE];

	for (n = 0; n < SIZE; n++)
	{
		cout << endl;
		cout << "������� ����� ������: ";
		cin >> apart[n].modelnumber;
		cout << "������� ����� �����: ";
		cin >> apart[n].partnumber;
		cout << "������� ���������: ";
		cin >> apart[n].cost;
	}
	cout << endl;
	for (n = 0; n < SIZE; n++)
	{
		cout << "������ " << apart[n].modelnumber;
		cout << "  �����  " << apart[n].partnumber;
		cout << "  ���������  " << apart[n].cost << endl;
	}
	*/
#pragma endregion

#pragma region ������ ��� ���� ������
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
	
#pragma region ������ ��������
	/*
	Distance dist[100]; // ������ ����������
	int n = 0;             // ������� ������
	char ans;              // ����� ������������ (y/n)
	cout << endl;
	do
	{
		cout << "������� ����� ����� " << n + 1;
		dist[n++].getdist();      // �������� � ��������� �����
		cout << "���������� ���� (y/n)?: ";
		cin >> ans;
	} while (ans != 'n');            // ����������, ���� �� ����� ������� '�'
	
	// ���������� ��� ���������
	for (int j = 0; j < n; j++)
	{
		cout << "\n����� ����� " << j + 1 << " : ";
		dist[j].showdist();
	}
	cout << endl;
	*/
#pragma endregion

#pragma region �����
	/*
	card deck[52];
	int j;
	
	cout << endl;
	for (j = 0; j < 52; j++)   // ������� ������������� ������ ����
	{
		int num = (j % 13) + 2;
		Suit su = Suit(j / 13);
		deck[j].set(num, su);
	}
	// ���������� �������� ������
	cout << "�������� ������:\n";
	for (j = 0; j < 52; j++)
	{
		deck[j].display();
		cout << "  ";
		if (!((j + 1) % 13)) // �������� ����� ������ ����� ������ 13-� �����
			cout << endl;
	}
	srand(time(NULL));     // �������������� ��������� ��������� �����
	for (j = 0; j < 52; j++)
	{
		int k = rand() % 52;     // �������� ��������� �����
		card temp = deck[j];     // � ������ �� � �������
		deck[j] = deck[k];
		deck[k] = temp;
	}
	// ���������� ������������ ������
	cout << "\n������������ ������:\n";
	for (j = 0; j < 52; j++)
	{
		deck[j].display();
		cout << "  ";
		if (!((j + 1) % 13)) // �������� ����� ������ ����� ������ 13-� �����
			cout << endl;
	}
	*/
#pragma endregion

#pragma region ������
	/*
	const int MAX = 2000; // ������������ ����� ������
	char str[MAX];        // ���� ������
	cout << "\n������� ������:\n";
	cin.get(str, MAX, '$');
	cout << "�� �����:\n" << str << endl;
	*/
#pragma endregion

#pragma region String
	/*
	string s1("����");
	string s2 = "����";
	string s3;
	
	s3 = s1;
	cout << "s3 = " << s3 << endl;
	
	s3 = "�� " + s1 + " �� ";
	s3 += s2;	// s3 = s3 + s2
	cout << "s3 = " << s3 << endl;
	
	s1.swap(s2);
	cout << s1 << " �� " << s2 << endl;
	*/
#pragma endregion

#pragma region String2
	/*
	string full_name, nickname, address;
	string greeting("������������, ");
	
	cout << "������� ���� ���: ";
	getline(cin, full_name);
	cout << "���� ���: " << full_name << endl;
	
	cout << "������� ��� ���������: ";
	cin >> nickname;
	
	greeting += nickname;
	cout << greeting << endl;
	
	cout << "������� ��� ����� � ��������� �����\n";
	cout << "��������� ����� ������ '$'\n";
	getline(cin, address, '$');
	cout << "��� �����: " << address << endl;
	*/
#pragma endregion

#pragma region ����� � �������
	/*
	string s1 = "� ���� �������� ������, � ���� ��� �����.";
	int n;
	n = s1.find("������");
	cout << "������ �������: " << n << endl;
	
	n = s1.find_first_of("�");
	cout << "������ �� �: " << n << endl;
	
	n = s1.find_first_not_of("����������");
	cout << "������ �� �� : " << n << endl;
	*/
#pragma endregion

#pragma region ��������� ������
	/*
	string s1("��� ������, ���������� �������.");
	string s2("���������");
	string s3("����������� ");
	
	s1.erase(0, 12);              // ������� "��� ������, "
	s1.replace(11, 7, s2);        // �������� "�������" �� "���������"
	s1.insert(0, s3);             // ��������� "�����������, "
	s1.erase((s1.size()-1), 1);   // ������� '.'
	s1.append(3, '!');            // ��������� '!!!'
	
	int x = s1.find(' ');         // ���� �������
	while (x < s1.size())         // ���� �� ���� ��������
	{
		s1.replace(x, 1, "/");      // �������� ������ �� '/'
		x = s1.find(' ');           // ���� ��������� ������
	}	
	cout << "s1: " << s1 << endl;
	*/
#pragma endregion

#pragma region ������ � �������� string
	/*
	char charray[80];
	string word;
	
	cout << "������� �����: ";
	cin >> word;
	int wlen = word.length();     // ����� ������
	cout << "�� ������ �������: ";
	for (int j = 0; j < wlen; j++)
		cout << word.at(j);       // ��� ����� �������� �� ����� �� ������� ������
		//cout << word[ j ];    // � ��� �������� �� �����
	word.copy(charray, wlen); // �������� ������ � ������
	charray[wlen] = 0;
	cout << "\n������ ��������: " << charray << endl;
	*/
#pragma endregion

#pragma region ���������� ������� ��������
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
	Counter c1, c2;                        // ���������� ����������
	
	cout << "\nc1 = " << c1.get_count(); // ������� �� �����
	cout << "\nc2 = " << c2.get_count();
	
	++c1;                                  // ����������� c1
	c2 = ++c1;                             // c1=2, c2=2
	
	cout << "\nc1 = " << c1.get_count(); // ����� ���������� ��������
	cout << "\nc2 = " << c2.get_count();
	
	c2 = c1++;
	
	cout << "\nc1 = " << c1.get_count(); // � �����
	cout << "\nc2 = " << c2.get_count() << endl;
	*/
#pragma endregion

#pragma region ��������� ���������� �������������� ��������
	
	Distance dist1, dist3, dist4;  // ���������� ����������
	dist1.getdist();               // �������� ����������
	
	Distance dist2(11, 6.25);      // ���������� ���������� � ���������� ���������
	
	dist3 = dist1 + dist2;         // ���������� ��� ����������
	
	dist4 = dist1 + dist2 + dist3; // ���������� ��������� ����������
	
								   // ����������, ��� �� � ��� ����������
	cout << "dist1 = "; dist1.showdist(); cout << endl;
	cout << "dist2 = "; dist2.showdist(); cout << endl;
	cout << "dist3 = "; dist3.showdist(); cout << endl;
	cout << "dist4 = "; dist4.showdist(); cout << endl;
	
#pragma endregion

#pragma region ����������� �����
    /*
	String s1 = "� ����������!����������������������������\n"; // ���������� ����������� � ����������
	String s2 = "� ����� �����!�������������������������\n";   // ���������� ����������� � ����������
	String s3;                      // ���������� ����������� ��� ����������
	
	s1.display();
	s2.display();
	s3.display();
	
	cout << endl;
	s3 = s1 + s2;     // ����������� ������ s3 ��������� ������� ����� s1 � s2
	
	s3.display();     // ���������� ���������
	cout << endl;
	*/
#pragma endregion

#pragma region ��������� ���������� <
    /*
	Distance dist1;            // ��������� ����������
	dist1.getdist();         // �������� ����� �� �����������
	
	Distance dist2(6, 2.5); // ��������� � �������������� ����������
	
							// ���������� �����
	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	
	// ���������� ��� ��������
	if (dist1 < dist2)
		cout << "\ndist1 ������ ��� dist2";
	else
	cout << "\ndist1 ������ ��� ����� ��� dist2";
	cout << endl;
	*/
#pragma endregion

#pragma region ������ ���������� ==
	/*
	String s1 = "yes";
	String s2 = "no";
	String s3;
	
	cout << "\n������� 'yes' ��� 'no': ";
	s3.getstr();        // �������� ������ �� ������������
	
	if (s3 == s1)       // ���������� �� ������� 'yes'
	cout << "�� ����� 'yes'\n";
	else
	{
		if (s3 == s2)       // ���������� �� ������� 'no'
			cout << "�� ����� 'no'\n";
		else
			cout << "�������� �����������!\n";
	}
	*/
#pragma endregion

#pragma region ��������� ���������� +=
	
	Distance dist1;              // ���������� ����������
	dist1.getdist();           // � ������ ����������
	cout << "\ndist1 = "; dist1.showdist();
	
	Distance dist2(11, 6.25); // ��������� � �������������� ������ ����������
	cout << "\ndist2 = "; dist2.showdist();
	
	dist1 += dist2;              // dist1 = dist1 + dist2
	cout << "\n����� ����������:";
	
	cout << "\ndist1 = "; dist1.showdist();
	cout << endl;
	
#pragma endregion

#pragma region ���������� ������
	/*
	safearray sa1;
	
	// ������ �������� ���������
	for (int j = 0; j < LIMIT; j++)
		sa1.putelem(j, j * 10);
	
	// ���������� ��������
	for (int j =0; j<LIMIT; j++)
	{
		int temp = sa1.getelem(j);
		cout << "������� " << j << " ����� " << temp << endl;
	}
	
	
	// ������ �������� ���������
	for (int j = 0; j < LIMIT; j++)
		sa1.access(j) = j * 7; // ���������� ������� ����� �� ����� =

								// ���������� ��������
	for (int j = 0; j < LIMIT; j++)
	{
		int temp = sa1.access(j); // ���������� ������� ������ �� ����� =
		cout << "������� " << j << " ����� " << temp << endl;
	}
	
	
	// ������ �������� ���������
	for (int j = 0; j < LIMIT; j++)
		sa1[j] = j * 5;    // ���������� ������� ����� �� ����� =

							// ���������� ��������
	for (int j = 0; j < LIMIT; j++)
	{
		int temp = sa1[j]; // ���������� ������� ������ �� ����� =
		cout << "������� " << j << " ����� " << temp << endl;
	}
	*/
#pragma endregion

#pragma region �������������� �������� � �������� ����
	/*
	float mtrs;
	DistMetr dist1 = 2.35F; // ������������ �����������, ����������� ����� � ���� � �����
	cout << "\ndist1 = "; 
	dist1.showdist();
	mtrs = static_cast<float>(dist1); // ���������� �������� �������� � �����
	cout << "\ndist1 = " << mtrs << " meters\n";
	DistMetr dist2(5, 10.25); // ���������� ����������� � ����� �����������
	mtrs = dist2;	// ������ ���������� ������� ����
	cout << "\ndist2 = " << mtrs << " meters\n";
	//dist2 = mtrs;  //� ��� ��� ������ - ��� ������ ������
	*/
#pragma endregion

#pragma region �������������� ����� � ������� String
	/*
	String s1;                 // ���������� ����������� ��� ����������
	char xstr[] = "���, ��������! "; // ������� ������� ������
	s1 = xstr;                 // ������ ���������� ����������� � ����� ����������
	s1.display();            // ���������� ������
	String s2 = "�� �������!"; // ����� ���������� ����������� � ����������
	cout << static_cast<char*>(s2); // ���������� �������� �������� ����
	cout << endl;
	*/
#pragma endregion

#pragma region ��������������� �������� ������ ������ � ������
	/*
	int h, m, s;
	
	while (true)
	{
		cout << "������� ����� � 24-������� �������: \n";
		cout << "  ���� (�� 0 �� 23): "; 
		cin >> h;
		if (h > 23)
			exit (1);
		cout << "  ������: "; cin >> m;
		cout << "  �������: "; cin >> s;
	
		time24 t24(h, m, s);
		cout << "�������� �����: ";
		t24.display();
	
		time12 t12 = t24;
	
		cout << "\n� 12-������� �������: ";
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
	const scrollbar sbar(60, "���������� 1");
	//sbar.setSize ( 100 );
	sbar.setOwner("���������� 2");
	cout << sbar.getSize() << ", " << sbar.getOwner() << endl;
	*/
#pragma endregion

	system("pause");
    return 0;
}

