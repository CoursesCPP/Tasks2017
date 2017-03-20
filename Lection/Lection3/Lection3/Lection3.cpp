// Lection3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>



using namespace std;

void fa�torial(int numb) //��������� �������
{
	int rezult = 1;  //�������������� ���������� rezult ��������� 1
	for (int i = 1; i <= numb; i++) //���� ���������� �������� n!
		rezult *= i; //����������� ������������ � ���������� rezult
	cout << numb << "! = " << rezult << endl; //������ �������� n!
}

int fa�torialint(int numb)// ��������� �������
{
	int rezult = 1; // �������������� ���������� rezult ��������� 1
	for (int i = 1; i <= numb; i++) // ���� ���������� �������� n!
		rezult *= i; // ����������� ������������ � ���������� rezult
	return rezult; // ������� �������� ���������� � ������� �������
}

bool palendrom5(int); //�������� ������� ���������� ���������� ����������� �����

void check_pass(string password)
{
	string valid_pass = "q1w2e3";

	if (password == valid_pass) {
		cout << "������ ��������." << endl;
	}
	else {
		cout << "�������� ������!" << endl;
	}
}

string check_pass_str(string password)
{
	string valid_pass = "qwerty123";
	string error_message;
	if (password == valid_pass) {
		error_message = "������ ��������.";
	}
	else {
		error_message = "�������� ������!";
	}
	return error_message;
}


#pragma region ������ ��������

bool password_is_valid(string password)
{
	string valid_pass = "q1w2e3";
	if (valid_pass == password)
		return true;
	else
		return false;
}

void get_pass()
{
	string user_pass;
	cout << "������� ������: ";
	getline(cin, user_pass);
	if (!password_is_valid(user_pass)) {
		cout << "�������� ������!" << endl;
		system("cls");
		get_pass(); // ����� ������ ��������
	}
	else {
		cout << "������ ��������." << endl;
	}
}

#pragma endregion

#pragma region Inline �������
	inline void hello()
	{
		cout << "hello\n";
	}
#pragma endregion

double triangle_area(const double a = 5, const double b = 6.5, const double c = 10.7); //��������� ������� ���������������� �� ���������

#pragma region ������ ������� ������������ �� ���������
double triangle_area(const double a, const double b, const double c) // ������� ���������� ������� ������������ �� ������� ������
{
	const double p = (a + b + c) / 2;   // ������������
	cout << "a = " << a << "\nb = " << b << "\nc = " << c << endl;
	return (sqrt(p * (p - a) * (p - b) * (p - c))); // ������� ������ ��� ���������� ������� ������������
}
#pragma endregion

void counter()
{
	static int first_call = 0;
		first_call ++;
		cout << first_call << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

#pragma region ���������� ��������
	/*
	bool a1 = true, a2 = false; // ���������� ���������� ����������
	bool a3 = true, a4 = false;
	cout << "������� ���������� &&" << endl;
	cout << "true  && false: " << (a1 && a2) << endl // ���������� �
		 << "false && true: " << (a2 && a1) << endl
		 << "true  && true: " << (a1 && a3) << endl
		 << "false && false: " << (a2 && a4) << endl;
	cout << "������� ���������� ||" << endl;
	cout << "true  || false: " << (a1 || a2) << endl // ���������� ���
		 << "false || true: " << (a2 || a1) << endl
		 << "true  || true: " << (a1 || a3) << endl
		 << "false || false: " << (a2 || a4) << endl;
	cout << "������� ���������� !" << endl;
	cout << "!true: " << (!a1) << endl // ���������� ��
		 << "!false: " << (!a2) << endl;
	*/
#pragma endregion

#pragma region ���������
	/*
	int digit; //���������� ��� �������� �������� n!
	cout << "������� �����: ";
	cin >> digit;
	fa�torial(digit); //����� ������� ���������� ����������
	*/
#pragma endregion

#pragma region ��������� ���
	/*
	int digit; // ���������� ��� �������� �������� n!
	cout << "������� �����: ";
	cin >> digit;
	cout << digit << "! = " << fa�torialint(digit) << endl;// ������ ������� ���������� ����������
	*/
#pragma endregion

#pragma region ��������� 
	/*
	cout << "������� 5-�� ������� �����: "; // ������� ����������� �����
	int in_number, out_number; // ���������� ��� �������� ��������� ������������ �����
	cin >> in_number;
	out_number = in_number; // � ���������� out_number ��������� �������� �����

	if (palendrom5(in_number)) // ���� ������� ����� true, �� ������� �������, ����� ������� ����� false - �����
		cout << "����� " << out_number << " - ���������" << endl;
	else
		cout << "��� ����� �� ���������" << endl;
	*/
#pragma endregion

#pragma region ������ �� �������
	/*
	string valid_pass = "q1w2e3";
	string user_pass;
	cout << "������� ������: ";
	getline(cin, user_pass);
	if (user_pass == valid_pass) {
		cout << "������ ��������." << endl;
	}
	else {
		cout << "�������� ������!" << endl;
	}
	*/
#pragma endregion

#pragma region ������ �������
	/*
	string user_pass;
	cout << "������� ������: ";
	getline(cin, user_pass);
	check_pass(user_pass);
	*/
#pragma endregion

#pragma region ������ ������
	/*
	string user_pass;
	cout << "������� ������: ";
	getline(cin, user_pass);
	string error_msg = check_pass_str(user_pass);
	cout << error_msg << endl;
	*/
#pragma endregion

#pragma region ������ ��������
	/*
	get_pass();
	*/
#pragma endregion

#pragma region ������ ������� ������������ �� ���������
	
	cout << "S = " << triangle_area() << endl << endl; // ��� ��������� ������������ �� ���������
	cout << "S = " << triangle_area(10, 5) << endl << endl; // ������ ��������� �������� ������������ �� ���������
	cout << "S = " << triangle_area(7) << endl << endl; // ��� ��������� ��������� ������� �� ���������, � ������ ����� 7
	
#pragma endregion

#pragma region Inline hello
	/*
	hello();
	*/
#pragma endregion

	system("pause");
    return 0;
}

#pragma region ���������-�

bool palendrom5(int number) // ������� ���������� ���������� ����������� �����
{
	int balance1, balance2, balance4, balance5; // ���������� �������� ������������� ����������
	balance1 = number % 10; // ���������� balance1 ��������� ������ ������ ������������ �����
	number = number / 10;   // ��������� �������� ����� �� ���� ������

	balance2 = number % 10; // ���������� balance2 ��������� ������ ������
	number = number / 100;  // ��������� �������� ����� �� ��� �������

	balance4 = number % 10; // ���������� balance4 ��������� �������� ������
	number = number / 10;   // ��������� �������� ����� �� ���� ������

	balance5 = number % 10; // ���������� balance5 ��������� ����� ������
	if ((balance1 == balance5) && (balance2 == balance4))
		return true;  // ������� ���������� �������� ��������
	else
		return false; // ������� ���������� ������ ��������
}

#pragma endregion

