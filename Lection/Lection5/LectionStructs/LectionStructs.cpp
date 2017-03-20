// LectionStructs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>  
#include <string>
using namespace std;

struct part                    // ���������� ���������
{
	int modelnumber;           // ����� ������ �������
	int partnumber;            // ����� ������
	float cost;                // ��������� ������
	string city;
};

struct Distance                // ���� � �����
{
	int feet;
	float inches;
};

struct Room                  // ������������� �������
{
	Distance length;         // �����
	Distance width;          // ������
};

#pragma region ��������� ��������� ����
struct card
{
	int number;                     //�����������
	int suit;                       //�����
};

const int clubs = 0;                //�����
const int diamonds = 1;
const int hearts = 2;
const int spades = 3;
const int jack = 11;                //����������� ����
const int queen = 12;
const int king = 13;
const int ace = 14;

	#pragma region ��������� ���� �2
/*
enum Suit { clubs, diamonds, hearts, spades };

struct card
{
	int number;                     // ����������� �����
	Suit suit;                      // �����
};
*/
#pragma endregion

#pragma endregion

struct time
{
	int hrs;
	int min;
	int sec;
};

// ���������� �������������� ����
enum days_of_week { Sun, Mon, Tue, Wed, Thu, Fri, Sat };

enum level { parking, supermarket, hardwareStores, boutiques, sportSpa, clubRestaurantBar };
enum itsaWord { NO, YES };     // NO=0, YES=1
//enum itsaAM{ NO, YES };

int main()
{

	setlocale(LC_ALL, "Russian");

	#pragma region ��������� �����
	/*
	long tl1, tl2, tlf;
	time t1, t2, tf;
	char ch;
	cout << "������� ������ �������� �������\n";
	cin >> t1.hrs >> t1.min >> t1.sec;
	cout << "������� ������ �������� �������\n";
	cin >> t2.hrs >> t2.min >> t2.sec;
	tl1 = t1.hrs * 3600 + t1.min * 60 + t1.sec;
	tl2 = t2.hrs * 3600 + t2.min * 60 + t2.sec;
	tlf = tl1 + tl2;
	tf.hrs = tlf / 3600;
	tf.min = (tlf - tf.hrs * 3600) / 60;
	tf.sec = tlf - tf.hrs * 3600 - tf.min * 60;
	cout << "�����: " << tf.hrs << ":" << tf.min << ":" << tf.sec << endl;
	*/
	#pragma endregion

	#pragma region ��������� �� void
	/*
	int intvar;           
	float flovar;         

	int *ptrint;          
	float *ptrflo;
	void *ptrvoid;        

	ptrint = &intvar;     // ��� �����: int* = int*
    //ptrint = &flovar;     // ��� ������: int* = float*
    //ptrflo = &intvar;     // ��� ������: float* = int*
	ptrflo = &flovar;     // ��� �����: float* = float*

	ptrvoid = &intvar;    // ��� �����: void* = int*
	ptrvoid = &flovar;    // ��� �����: void* = float*
	*/
	#pragma endregion

	#pragma region ������ � ������� ����� ���������
	/*
	int intarray[5] = { 31, 54, 77, 52, 93 }; 
	int *ptrint;                     
	ptrint = intarray;              

	for (int j = 0; j < 5; j++)      
		cout << *(ptrint--) << endl; 
	*/
	#pragma endregion

	#pragma region ��������� �� �������
		
		#pragma region ����������
	/*
	void centimize ( double* );

	double var = 10.0;
	cout << "var = " << var << "������" << endl;
	centimize ( &var );
	cout << "var= " << var << "�����������" << endl;
	*/
		#pragma endregion

		#pragma region ������
	/*
	void centimize(double*);

	double varray[5] = { 10.0, 43.1, 95.9, 58.7, 87.3 };

	centimize(varray);        // ��������� ��� �������� ������� � ����������

							  // �������, ��� � ��� ����������
	for (int j = 0; j < 5; j++)
		cout << "varray [ " << j << " ] = " << varray[j] << " �����������" << endl;
	*/
#pragma endregion

		#pragma region ����������
	/*
	void order(int*, int*);     

	int n1 = 99, n2 = 11;
	int n3 = 22, n4 = 88;

	order(&n1, &n2);
	order(&n3, &n4);
	order(&n2, &n3);
	order(&n3, &n4);
	cout << "n1 = " << n1 << endl; 
	cout << "n2 = " << n2 << endl; 
	cout << "n3 = " << n3 << endl;
	cout << "n4 = " << n4 << endl;
	*/
#pragma endregion
		
		#pragma region ���������� ���������
	/*
	void bsort(int*, int); // �������� �������
	const int N = 10;      // ������ �������
	int arr[N] = { 37, 84, 62, 91, 11, 65, 57, 28, 19, 49 }; // ������ ��� ����������

	bsort(arr, N);

	for (int j = 0; j < N; j++)
		cout << arr[j] << " ";
	cout << endl;
	*/
	#pragma endregion

#pragma endregion

	#pragma region ������ ���������
	
	part part1;                // ����������� ����������� ����������

	part1.modelnumber = 6244;  // ������������� �����
	part1.partnumber = 373;    // ���������� part1
	part1.cost = 217.55F;
	cout << "������ " << part1.modelnumber;
	cout << ", ������ " << part1.partnumber;
	cout << ", ��������� " << part1.cost << endl;
	
	#pragma endregion

	#pragma region ������������� �����
	/*
	part part1 = { 6244,373,217.55F, "������" };
	part part2;             // ���������� ����������
							// ����� ����� ������ ����������	
	cout << "������ " << part1.modelnumber;
	cout << ", ������ " << part1.partnumber;
	cout << ", ��������� $" << part1.cost;
	cout << ", ������������� " << part1.city << endl;
	part2 = part1;          // ������������ ����������� ����������
							// ����� ����� ������ ����������
	cout << "������ " << part2.modelnumber;
	cout << ", ������ " << part2.partnumber;
	cout << ", ��������� $" << part2.cost;
	cout << ", ������������� " << part2.city << endl;
	*/
	#pragma endregion

	#pragma region ������ �������� ����� � ������
	/*
	Distance d1, d3;            
	Distance d2 = { 11, 6.25 }; // ����������� � ��������������								
	cout << "\n������� ����� �����: "; 
	cin >> d1.feet;
	cout << "������� ����� ������: "; 
	cin >> d1.inches;
	// �������� ���� d1 � d2 � ���������� ���������� d3
	d3.inches = d1.inches + d2.inches; // �������� ������
	d3.feet = 0;                       
	if (d3.inches >= 12.0)            // ���� ����� ������ 12.0,
	{                                  // �� ��������� 
		d3.inches -= 12.0;                 // ����� ������ �� 12.0 �
		d3.feet++;                         // ����������� ����� ����� �� 1
	}
	d3.feet += d1.feet + d2.feet;      // �������� �����
									   // ����� ���� ���� �� �����
	cout << d1.feet << "\'-" << d1.inches << "\" + ";
	cout << d2.feet << "\'-" << d2.inches << "\" = ";
	cout << d3.feet << "\'-" << d3.inches << "\"\n";
	*/
	#pragma endregion

	#pragma region ��������� ���������
	/*
	Room dining;           
	//��������� �������
	dining.length.feet = 13; 
	dining.width.feet = 10;
	cin >> dining.width.inches;
	cin >> dining.length.inches;
	//Room dining1 = { {13, 6.5} , {10, 0.0} };
	// �������������� ����� � ������ � ������������ ������
	float l = dining.length.feet + dining.length.inches / 12;
	float w = dining.width.feet + dining.width.inches / 12;
	// ���������� ������� ������� � ����� �� �����
	cout << "������� ������� ����� " << l * w
		<< " ���������� �����\n";
	*/
	#pragma endregion

	#pragma region ��������� ����
/*
	card temp, chosen, prize;       // ��� �����: ��� ����� ����, ��� ������, ���������� �����
	int position;
	card card1 = { 7, clubs };      // ������������� ����� 1
	cout << "����� 1: 7 ����\n";
	card card2 = { jack, hearts };  // ������������� ����� 2
	cout << "����� 2: ����� ������\n";
	card card3 = { ace, spades };   // ������������� ����� 3
	cout << "����� 3: ��� ���\n";
	prize = card3;                  // ����������� ����� 3
	cout << "������ ������� ����� 1 � ����� 3...\n";
	temp = card3; card3 = card1; card1 = temp;
	cout << "������ ������� ����� 2 � ����� 3...\n";
	temp = card3; card3 = card2; card2 = temp;
	cout << "������ ������� ����� 1 � ����� 2...\n";
	temp = card2; card2 = card1; card1 = temp;
	cout << "�� ����� ������� (1,2 ��� 3) ������ ��� ���?\n";
	cin >> position;
	switch (position)
	{
	case 1: chosen = card1; break;
	case 2: chosen = card2; break;
	case 3: chosen = card3; break;
	}
	if (chosen.number == prize.number && // ��������� ����
		chosen.suit == prize.suit)
		cout << "���������! �� ��������!\n";
	else
		cout << "�������. �� ���������.\n";
	*/
	#pragma endregion

	#pragma region ������������
	/*
	days_of_week day1, day2;     // ����������� ����������,
								 // �������� ��� ������
	day1 = Mon;                  // ������������� ����������
	day2 = Thu;
	int diff = day2 - day1;      // �������������� ��������
	cout << "������� � ����: " << diff << endl;
	if (day1 < day2)             // ���������
		cout << day1 << " �������� ������, ��� day2\n";
	*/
	#pragma endregion

	#pragma region ����
	/*
	level floor = parking;//���������� ���� ������������ level
						  //level floor = 0; �� ��������������
	int fl = floor;  //����� ����� ������������� 
	bool exit = true;//����� ������������ - ����� � ����������
	
	cout << "\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
	cout << "\t����� ���������� � ��� �������-��������������� ����� MALL!!!\n";
	cout << "\t���������� ��� ���������� � ����� � �������� ��� �����!\n\n";
	cout << "\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
	
	while (exit)//���� exit ����� true
	{
		cout << "\n������� ������ � ������� ����� (�� 0 �� 5): ";
		cin >> fl;
	
		switch (fl)
		{
		case(parking):
			cout << "\a�� ���������� � �������!!!" << endl;
			break;
	
		case(supermarket):
			cout << "\a�� �� ������ �����!";
			cout << "\n����� �� ������ �������� ��� ����������� � ������ �������� � ������ ��� ����.\n\n";
			break;
	
		case(hardwareStores):
			cout << "\a�� �� ������ �����!";
			cout << "\n����� ������������� �������� ������� �������, IT  � ��������� ���������.\n\n";
			break;
	
		case(boutiques):
			cout << "\a�� �� ������� �����!";
			cout << "\n����� ��� ���� ������������ ������! ������, �����, �������� ���������.\n\n";
			break;
	
		case(sportSpa):
			cout << "\a�� �� ��������� �����!";
			cout << "\n����� �� ������ �������� �������, �����, ���������, spa-�����!\n\n";
			break;
	
		case(clubRestaurantBar):
			cout << "\a�� �� ����� �����!";
			cout << "\n��� �� ������ �������� ������ ����, ��� � ��������!\n\n";
			break;
	
		default: cout << "\a\a\a������! � ��� ������ 5 ������!\n\n";
		}
	
		cout << "���� ������ ����� �� ���� �����, ������� 0.\n";
		cout << "���������� ������������� ������� - ������� 1: ";
		cin >> exit;
	}
	*/
	#pragma endregion

	#pragma region ������� ����
	/*
	itsaWord isWord = NO;        // isWord ����� YES, �����
								 // �������� �����, � NO, ����� �������� �������
	char ch;                     // ���������� ������� � ����������
	int wordcount = 0;           // ����� ����
	cout << "������� �����������: \n";
	do {
		ch = getche();             // ���� �������
		if (ch == ' ' || ch == '\r')  // ���� ������ ������,
		{
			if (isWord == YES)      // � �� ����� ��������� �����,
			{                        // ������, ����� �����������
				wordcount++;           // ���� �����
				isWord = NO;           // ����� �����
			}
		}                          // � ��������� ������
		else                       // ���� ����� ������������
			if (isWord == NO)        // ���� ������� ���� �����,
				isWord = YES;              // �� ������������� ����
	} while (ch != '\r');     // ����� �� ������� Enter
	cout << "\n����� ����: " << wordcount << endl;
	*/
	#pragma endregion

	#pragma region ��������� ���� �2
	/*
	card temp, chosen, prize;       // ����������� ����
	int position;
	card card1 = { 7, clubs };      // ������������� card1
	cout << "����� 1: 7 ����\n";
	card card2 = { jack, hearts };  // ������������� card2
	cout << "����� 2: ����� ������\n";
	card card3 = { ace, spades };   // ������������� card3
	cout << "����� 3: ��� ���\n";
	prize = card3;                  // ���������� ����� 3
	cout << "������ ������� ����� 1 � ����� 3\n";
	temp = card3; card3 = card1; card1 = temp;
	cout << "������ ������� ����� 2 � ����� 3\n";
	temp = card3; card3 = card2; card2 = temp;
	cout << "������ ������� ����� 1 � ����� 2\n";
	temp = card2; card2 = card1; card1 = temp;
	cout << "�� ����� ������� (1,2 ��� 3) ������ ��� ���?\n";
	cin >> position;
	switch (position)
	{
	case 1: chosen = card1; break;
	case 2: chosen = card2; break;
	case 3: chosen = card3; break;
	}
	if (chosen.number == prize.number && // ��������� ����
		chosen.suit == prize.suit)
		cout << "���������! �� ��������!\n";
	else
	cout << "�������. �� ���������.\n ";
	*/
	#pragma endregion
	
	system("pause");
	return 0;
}
/*
void centimize(double *ptrd[])
{
	for (int j = 0; j < 5; j++)
		*ptrd[j] *= 2.54;
}

void centimize(double *ptrd)
{
	*ptrd *= 2.54;              
}
*/


void order(int *numb1, int *numb2)
{
	if (*numb1 > *numb2)   // ���� ������ ����� ������, �� ������ �� �������
	{
		int temp = *numb1;
		*numb1 = *numb2;
		*numb2 = temp;
	}
}
void bsort(int* ptr, int n)
{
	int j, k;                           // ������� � ����� �������
	for (int j = 0; j < n - 1; j++)     // ������� ����
		for (int k = j + 1; k < n; k++) // ���������� ����
			order(ptr + j, ptr + k);    // ��������� ��������
}