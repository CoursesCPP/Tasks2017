// Lection8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>      // ��� �������� �������
#include <typeinfo>     // ��� typeid()
#include <iostream>
#include <string>
#include "verylong.h"
 

using namespace std;

const int MAX = 100;       // ������ ������
int buff[MAX];             // ����� ��� ����� �����

const int LEN = 32;     // ������������ ����� �������
const int MAXEM = 100;  // ������������ ����� ����������

class person              // ����� person
{
protected:
	char name[80];        // ��� ��������
	short age;            // �������
public:
	void getData()        // �������� ������ � ��������
	{
		cout << "������� ���: "; cin >> name;
		cout << "������� �������: "; cin >> age;
	}

	void showData()     // ������� ������
	{
		cout << "���: " << name << endl;
		cout << "�������: " << age << endl;
	}

	void diskIn(int pn)  // ������ ������ � �����								 
	{
		ifstream infile;           // ������� �����
		infile.open("PERSFILE.DAT", ios::binary);  // ������� ���
		infile.seekg(pn * sizeof(person));         // ����� ��������� ���������
		infile.read((char*)this, sizeof(*this)); // ������ ������
		infile.close();										 // �� ����� ��������
	}
	
	void diskOut()       // ������ � ����� ����� 
	{
		ofstream outfile;          // ������� �����
		outfile.open("PERSFILE.DAT", ios::app | ios::binary);// ������� ���
		outfile.write((char*)this, sizeof(*this)); //�������� � ����
		outfile.close();
	}

	static int diskCount()      // ����� ����� � �����
	{
		ifstream infile;
		infile.open("PERSFILE.DAT", ios::binary);
		infile.seekg(0, ios::end); // ������� �� ������� �0 ���� �� ����� �����
								   // ��������� ���������� �����
		return (int)infile.tellg() / sizeof(person);
	}

	//� ��������� �������� ����� ������� ����� ����� *this,
	//� ��� ������ sizeof(*this)
};

enum employee_type { tmanager, tscientist, tlaborer };

class employee                // ����� employee 
{
private:
	char name[LEN];           // ������� ���������
	unsigned long number;     // ����� ���������
	static int n;             // ������� ����� ����������
	static employee* arrap[]; //������ ���������� �� ����� ����������
public:
	virtual void getdata()
	{
		cout << "  ������� �������: "; cin >> name;
		cout << "  ������� �����: ";    cin >> number;
	}
	virtual void putdata()
	{
		cout << "\n  �������: " << name;
		cout << "\n  �����: " << number;
	}
	virtual employee_type get_type(); // �������� ���
	static void add();                // �������� ���������
	static void display();            // ������� ������ ��� ����
	static void read();               // ������ �� �����
	static void write();              // ������ � ����
};

//����������� ����������
int employee::n = 0;              // ������� ����� ����������
employee* employee::arrap[MAXEM]; // ������ ���������� ��
								  // ����� ����������

//����� manager (���������)
class manager : public employee
{
private:
	char title[LEN];  // ����� 
	double dues;      // ������ �����-�����
public:
	void getdata()
	{
		employee::getdata();
		cout << "  ������� �����: ";       cin >> title;
		cout << "  ������� ������: "; cin >> dues;
	}
	void putdata()
	{
		employee::putdata();
		cout << "\n  �����: " << title;
		cout << "\n  ������ �����-�����: " << dues;
	}
};

//����� scientist (������)
class scientist : public employee
{
private:
	int pubs;              // ����� ����������
public:
	void getdata()
	{
		employee::getdata();
		cout << "  ������� ����� ����������: "; cin >> pubs;
	}
	void putdata()
	{
		employee::putdata();
		cout << "\n  ����� ����������: " << pubs;
	}
};

//����� laborer (�������)
class laborer : public employee
{
};

//�������� ��������� � ������ (�������� � ��)
void employee::add()
{
	char ch;
	cout << "'m' ��� ���������� ���������"
			"\n's' ��� ���������� �������"
			"\n'l' ��� ���������� ��������"
			"\n��� �����: ";
	cin >> ch;
	switch (ch)
	{ //������� ������ ���������� ����
	case 'm': arrap[n] = new manager;  break;
	case 's': arrap[n] = new scientist; break;
	case 'l': arrap[n] = new laborer;  break;
	default: cout << "\n����������� ��� ���������\n"; return;
	}
	arrap[n++]->getdata();  //�������� ������ �� ������������
}

//������� ������ ��� ���� ����������
void employee::display()
{
	for (int j = 0; j<n; j++)
	{
		cout << (j + 1);                // ������� �����
		switch (arrap[j]->get_type()) //������� ��� 
		{
		case tmanager:  cout << ". ���: ��������";  break;
		case tscientist: cout << ". ���: ������"; break;
		case tlaborer:   cout << ". ���: �������";  break;
		default: cout << ". ����������� ���";
		}
		arrap[j]->putdata();           // ����� ������
		cout << endl;
	}
}

//������� ���� �������
employee_type employee::get_type()
{
	if (typeid(*this) == typeid(manager))
		return tmanager;
	else if (typeid(*this) == typeid(scientist))
		return tscientist;
	else if (typeid(*this) == typeid(laborer))
		return tlaborer;
	else
	{
		cerr << "\n������������ ��� ���������"; exit(1);
	}
	return tmanager;
}

//�������� ��� �������, ���������� � ������, � ����
void employee::write()
{
	int size;
	cout << "���� ������ " << n << " ����������.\n";
	ofstream ouf;           // ������� ofstream � �������� ����
	employee_type etype;   // ��� ������� ������� employee

	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		cout << "\n���������� ������� ����\n"; return;
	}
	for (int j = 0; j<n; j++)  // ��� ������� �������
	{                     // �������� ��� ���
		etype = arrap[j]->get_type();
		// �������� ������ � ����
		ouf.write((char*)&etype, sizeof(etype));
		switch (etype)         // find its size
		{
		case tmanager:  size = sizeof(manager); break;
		case tscientist: size = sizeof(scientist); break;
		case tlaborer:  size = sizeof(laborer); break;
		}      //������ ������� employee � ����    
		ouf.write( (char*)(arrap[j]), size );
		if (!ouf)
		{
			cout << "\n������ � ���� ����������\n"; return;
		}
	}
}

//������ ���� ������ �� ����� � ������
void employee::read()
{
	int size;               // ������ ������� employee 
	employee_type etype;    // ��� ���������
	ifstream inf;           // ������� ifstream � �������� ����
	inf.open("EMPLOY.DAT", ios::binary);
	if (!inf)
	{
		cout << "\n���������� ������� ����\n"; return;
	}
	n = 0;                  // � ������ ���������� ���
	while (true)
	{                     // ������ ���� ���������� ���������
		inf.read((char*)&etype, sizeof(etype));
		if (inf.eof())       // ����� �� ����� �� EOF
			break;
		if (!inf)              // ������ ������ ����
		{
			cout << "\n���������� ������ ����\n"; return;
		}
		switch (etype)
		{                   // ������� ������ ���������
		case tmanager:      // ����������� ����
			arrap[n] = new manager;
			size = sizeof(manager);
			break;
		case tscientist:
			arrap[n] = new scientist;
			size = sizeof(scientist);
			break;
		case tlaborer:
			arrap[n] = new laborer;
			size = sizeof(laborer);
			break;
		default: cout << "\n����������� ��� � �����\n"; return;
		}                   // ������ ������ �� �����
		inf.read((char*)arrap[n], size);
		if (!inf)              // ������, �� �� EOF
		{
			cout << "\n������ ������ �� ����� ����������\n"; return;
		}
		n++;                  // ������� ���������� ���������
	}  
	cout << "���� ������ " << n << " ����������\n";
}

class Distance
{
private:
	int feet;
	float inches;
public:
	Distance() :feet(0),inches(0.0)
	{  }
	Distance(int ft, float in) : feet(ft), inches(in)
	{  }
	friend istream& operator >> (istream& s, Distance& d);
	friend ostream& operator << (ostream& s, Distance& d);
};

istream& operator >> (istream& s, Distance& d) //�������� ��������
{
	cout << "\n������� ����: ";  s >> d.feet;  
	cout << "������� �����: ";  s >> d.inches; 
	return s;                                  
}
ostream& operator << (ostream& s, Distance& d) // �������
{                                         
	s << d.feet << "\'-" << d.inches << '\"'; 
	return s;                                 
}

/*
istream& operator >> (istream& s, Distance& d) 
{  
	char dummy;       // ��� ('), (-) � (")
	s >> d.feet >> dummy >> dummy >> d.inches >> dummy;
	return s;
}
ostream& operator << (ostream& s, Distance& d) 											   
{   
	s << d.feet << "\'-" << d.inches << '\"';   
	return s;   
}*/

int main()
{
	setlocale(LC_ALL, "Russian");

	#pragma region �������� ���� ����� � ���������
		/*
		ofstream outfile("TES.TXT"); // ������� �������� ���� 
									  // ��������� ����� � ����
		outfile << "������ ������.\n";
		outfile << "������ ������.\n";
		outfile << "������ ������.\n";
		outfile << "��������� ������.\n";

		outfile.close();
		*/
		
	#pragma endregion

	#pragma region �������� ����� ����� � ���������
		/*
		const int MAX = 80;          // ������ ������
		char buffer[MAX];            // ����� �������� 
		ifstream infile("TEST.TXT"); // �������� �������� �����
		while (!infile.eof())        // ���� �� EOF
		{
			infile.getline(buffer, MAX); // ������ ������ ������
			cout << buffer << endl;      // � ������� ��
		}
		*/
	#pragma endregion

	#pragma region ������������ �������� ����
		/*
		string str = "����� � ������� �������, ��, ���, "
			"��� ������� ����� ��������.  �������";

		ofstream outfile("TEST.TXT");   // ����������� � ������ ofstream �������� ����
		for (int j = 0; j < str.size(); j++) // ������ ������
			//outfile.put(str[j]);        // ���������� � ����
			outfile << str[j];
		cout << "���� �������\n";
		*/
	#pragma endregion

	#pragma region ������������ �������� �����
		/*
		char ch;                     // ������ ��� ����������
		ifstream infile("TEST.TXT"); // ������� ����
		while (infile)              // ������ �� EOF ��� ������
		{
			infile.get(ch);            // ������� ������
			cout << ch;                // � ������� ���
		}
		cout << endl;
		*/

		/*
		ifstream infile("TEST.TXT"); // ������� ������� ����

		cout << infile.rdbuf();      // �������� ��� ����� � cout
		cout << endl;
		*/
	#pragma endregion

	#pragma region �������� ����/����� ������������� ������
		/*
		for (int j = 0; j< MAX; j++) // ��������� ����� �������
			buff[j] = j;           // (0, 1, 2, ...)
								   // ������� �������� �����
		ofstream os("edata.dat", ios::binary);
		// �������� � ����
		os.write(reinterpret_cast<char*>(buff), MAX * sizeof(int));
		os.close();              // ������ ������� ���

		for (int j = 0; j<MAX; j++)     // ������� �����
			buff[j] = 0;
		// ������� ������� �����
		ifstream is("edata.dat", ios::binary);
		// ������ �� ����
		is.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));

		for (int j = 0; j<MAX; j++)     // �������� ������
			if (buff[j] != j)
			{
				cerr << "������������ ������!\n"; return 1;
			}
		cout << "������ ���������\n";
		*/
		//reinterpret_cast - �������� ��� ������ � ������� ������,
		//���������� �� ����������� ����� �� ��� �����
		//����� ��� ����, ����� ����� ������ ���� int,
		//�������� ��� ������� read() � write(), ��� ����� ���� char
		/*
		���� ������:
		in - �������� ��� ������(ifstream)
		out - �������� ��� ������(ofstream)
		ate - ������ � ����� �����
		app - ������ � ����� �����
		trunc - �������� ���� �� ������� �����, ���� �� ����������
		nocreate - �� ��������� �������������� ����
		noreplace - �� ��������� ��� ������ ������������ ����, ���� �� ����������� ate � app
		binary - ������� � �������� ������
		*/
		
	#pragma endregion

	#pragma region ���������� �������� � �����
		/*
		person pers;            // ������� ������
		pers.getData();         // �������� ������
								// ������� ������ ofstream
		ofstream os("PERSON.DAT", ios::binary);
		// �������� � ����
		os.write(reinterpret_cast<char*>(&pers), sizeof(person));
		os.close();
		*/
	#pragma endregion

	#pragma region ������ ������� �� �����
		/*
		person pers;          // ���������� ���� person
		ifstream is("PERSON.DAT", ios::binary);// ������� �����
												   // ������ ������
		is.read(reinterpret_cast<char*>(&pers), sizeof(pers));
		pers.showData();      // ������� ������
		is.close();
		*/
	#pragma endregion

	#pragma region ������ �� ����� � ������ ���������� ��������
		/*
		char ch;
		person pers;          // ������� ������ person
		fstream file;         // ������� �������/�������� ����
							  // ������� ��� ��������
		file.open("GROUP.DAT", ios::app | ios::out | ios::in | ios::binary);

		do                    // ������ �� ������������ � � ����
		{
			cout << "\n������� ������ � ��������:\n";
			pers.getData();     // �������� ������
								// �������� �� � ����
			file.write(reinterpret_cast<char*>(&pers), sizeof(pers));
			cout << "���������� ���� (y/n)? ";
			cin >> ch;
		} while (ch == 'y');       // ����� �� 'n'
		file.seekg(0);        // ��������� ��������� �� ������ �����
							  // ������� ������ � ������ ��������
		file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
		while (!file.eof())  // ����� �� EOF
		{
			cout << "\n�������:\n"; //������� ������
			pers.showData();      //������� ������ � ���������
			file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
		}
		cout << endl;
		*/
	#pragma endregion

	#pragma region ����� ����������� ������� � �����
		/*
		person pers;                  // ������� ������ person 
		ifstream is;				// ������� ������� ����
		is.open("GROUP.DAT", ios::in | ios::binary); // ������� ����
		is.seekg(0, ios::end);    // ���������� ��������� �� 0 ���� �� ����� �����
		int endposition = is.tellg();      // ����� ������� (tellg - ������� ������� ������� ���������)
		int n = endposition / sizeof(person);  // ����� �������
		cout << "\n� ����� " << n << " �������(�)";
		
		cout << "\n������� ����� �������: ";
		cin >> n;
		int position = (n - 1) * sizeof(person); // �������� ������
												 // ������ ��� ������� �� ����� ������
		is.seekg(position);               // ����� ���� �� ������
											  // ��������� ���� �������
		is.read(reinterpret_cast<char*>(&pers), sizeof(pers));
		pers.showData();                      //������� ���� �������
		cout << endl;
		*/
	#pragma endregion

	#pragma region ��������� ������ �����/������
		/*
		for (int j = 0; j<MAX; j++)    // ��������� ����� �������
			buff[j] = j;
		ofstream os;                // ������� �������� �����
									// ������� ���
		os.open("edata.dat", ios::trunc | ios::binary);
		if (!os)
		{
			cout << "���������� ������� �������� ����\n"; 
			system("pause");
			exit(1);
		}
		
		cout << "���� ������...\n"; // �������� � ���� ����������
									// ������
		os.write(reinterpret_cast<char*>(buff), MAX * sizeof(int));
		if (!os)
		{
			cout << "������ � ���� ����������\n";
			system("pause");
			exit(2);
		}
		os.close();                 // ���� ������� �����
		
		for (int j = 0; j<MAX; j++)        // �������� �����
			buff[j] = 0;
		
		ifstream is;                // ������� ������� �����
		is.open("edata.dat", ios::binary);
		if (!is)
		{
			cerr << "���������� ������� ������� ����\n"; exit(1);
		}
		
		cout << "���� ������...\n"; // ������ �����
		is.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));
		if (!is)
		{
			cerr << "���������� ������ �����\n"; exit(1);
		}
		
		for (int j = 0; j<MAX; j++)        // ��������� ������
			if (buff[j] != j)
			{
				cerr << "\n������ �����������\n"; exit(1);
			}
		cout << "������ � �������\n";
		*/
	#pragma endregion

	#pragma region �������� ������ �������� �����
		/*
		ifstream file;
		file.open("edata.dat");
		
		if (!file)
		cout << "\n���������� ������� GROUP.DAT";
		else
		cout << "\n���� ������ ��� ������.";
		cout << "\n��� ������ = " << file.rdstate();
		cout << "\ngood() = " << file.good();
		cout << "\neof() = " << file.eof();
		cout << "\nfail() = " << file.fail();
		cout << "\nbad() = " << file.bad() << endl;
		file.close();
		*/
	#pragma endregion

	#pragma region �������� ����/����� �������� person
		/*
		person p;                  // ������� ������ ������
		char ch;
		
		do {                       // ���������� ������ �� ����
			cout << "������� ������ � ��������: ";
			p.getData();             // �������� ������
			p.diskOut();             // �������� �� ����
			cout << "���������� (y/n)? ";
			cin >> ch;
		} while (ch == 'y');       // ���� �� 'n'
		
		int n = person::diskCount(); // ������� ����� � �����?
		cout << "� ����� " << n << " �������(�)\n";
		for (int j = 0; j<n; j++)       // ��� �������
		{
			cout << "\n������� " << j;
			p.diskIn(j);               // ������� � �����
			p.showData();              // ������� ������
		}
		cout << endl;
		*/
	#pragma endregion

	#pragma region �������� ����/����� �������� employee | ��������� �������� ������������ ��������
		/*
		char ch;
		while (true)
		{
			cout << "'a' � ���������� �������� � ���������"
					"\n'd' - ������� �������� ��� ���� ����������"
					"\n'w' � �������� ��� ������ � ����"
					"\n'r' � ��������� ��� ������ �� �����"
					"\n'x' - �����"
					"\n��� �����: ";
			cin >> ch;
			switch (ch)
			{
			case 'a':           // �������� ���������
				employee::add(); break;
			case 'd':           // ������� ��� ��������
				employee::display(); break;
			case 'w':           // ������ � ����
				employee::write(); break;
			case 'r':           // ������ ���� ������ �� �����
				employee::read(); break;
			case 'x': exit(0);  // �����
			default: cout << "\n����������� �������";
			}  
		}  
		*/
	#pragma endregion

	#pragma region ���������� << >>
		/*
		Distance dist1, dist2;     
		Distance dist3(11, 6.25);  
		cout << "\n������� ��� �������� ����������:";
		cin >> dist1 >> dist2;    
		cout << "\ndist1 = " << dist1 << "\ndist2 = " << dist2;
		cout << "\ndist3 = " << dist3 << endl;
		*/
	#pragma endregion

	#pragma region ���������� �������� << � >> � �������
		/*
		char ch;
		Distance dist1;
		ofstream ofile;         // ������� � �������
		ofile.open("DIST.DAT"); // �������� �����
		
		do {
			cout << "\n������� ����������: ";
			cin >> dist1;         // �������� ������ �� ������������
			ofile << dist1;       // �������� �� � �������� �����
			cout << "���������� (y/n)? ";
			cin >> ch;
		} while (ch != 'n');
		ofile.close();          // ������� �������� �����
		
		ifstream ifile;         // ������� � ������� 
		ifile.open("DIST.DAT"); // ������� �����
		
		cout << "\n���������� �����:\n";
		while (true)
		{
			ifile >> dist1;       // ������ ������ �� ������
			if (ifile.eof())     // ����� �� EOF
				break;
			cout << "���������� = " << dist1 << endl; //�����
													  // ����������
		}
		*/
	#pragma endregion

	#pragma region Verylong
		/*
		unsigned long numb, j;
		verylong fact = 1;       //���������������� verylong
		
		cout << "\n\n������� �����: ";
		cin >> numb;           //���� ����� ���� long int
		
		for (j = numb; j>0; j--)  
		fact = fact * j;     
		cout << "���������= "; 
		fact.putvl();          //������� �������� ����������
		cout << endl;
		*/
	#pragma endregion

	#pragma region �����
		/*
		building theBuilding;
		while (true)
		{
			theBuilding.master_tick(); //������� ��������� �����
									   //���� ������
			wait(1000);                //�����
									   //�������� ������� ������ �� �������������
			theBuilding.record_floor_reqs();
		}
		*/
	#pragma endregion

	system("pause");
    return 0;
}