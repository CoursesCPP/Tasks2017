// Lection8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>      // для файловых функций
#include <typeinfo>     // для typeid()
#include <iostream>
#include <string>
#include "verylong.h"
 

using namespace std;

const int MAX = 100;       // размер буфера
int buff[MAX];             // буфер для целых чисел

const int LEN = 32;     // Максимальная длина фамилий
const int MAXEM = 100;  // максимальное число работников

class person              // класс person
{
protected:
	char name[80];        // имя человека
	short age;            // возраст
public:
	void getData()        // получить данные о человеке
	{
		cout << "Введите имя: "; cin >> name;
		cout << "Введите возраст: "; cin >> age;
	}

	void showData()     // вывести данные
	{
		cout << "Имя: " << name << endl;
		cout << "Возраст: " << age << endl;
	}

	void diskIn(int pn)  // Чтение данных о числе								 
	{
		ifstream infile;           // создать поток
		infile.open("PERSFILE.DAT", ios::binary);  // открыть его
		infile.seekg(pn * sizeof(person));         // сдвиг файлового указателя
		infile.read((char*)this, sizeof(*this)); // чтение данных
		infile.close();										 // об одном человеке
	}
	
	void diskOut()       // запись в конец файла 
	{
		ofstream outfile;          // создать поток
		outfile.open("PERSFILE.DAT", ios::app | ios::binary);// открыть его
		outfile.write((char*)this, sizeof(*this)); //записать в него
		outfile.close();
	}

	static int diskCount()      // число людей в файле
	{
		ifstream infile;
		infile.open("PERSFILE.DAT", ios::binary);
		infile.seekg(0, ios::end); // перейти на позицию «0 байт от конца файла»
								   // вычислить количество людей
		return (int)infile.tellg() / sizeof(person);
	}

	//В потоковых функциях адрес объекта будет равен *this,
	//а его размер sizeof(*this)
};

enum employee_type { tmanager, tscientist, tlaborer };

class employee                // класс employee 
{
private:
	char name[LEN];           // фамилия работника
	unsigned long number;     // номер работника
	static int n;             // текущее число работников
	static employee* arrap[]; //массив указателей на класс работников
public:
	virtual void getdata()
	{
		cout << "  Введите фамилию: "; cin >> name;
		cout << "  Введите номер: ";    cin >> number;
	}
	virtual void putdata()
	{
		cout << "\n  Фамилия: " << name;
		cout << "\n  Номер: " << number;
	}
	virtual employee_type get_type(); // получить тип
	static void add();                // добавить работника
	static void display();            // вывести данные обо всех
	static void read();               // чтение из файла
	static void write();              // запись в файл
};

//статические переменные
int employee::n = 0;              // текущее число работников
employee* employee::arrap[MAXEM]; // массив указателей на
								  // класс работников

//класс manager (менеджеры)
class manager : public employee
{
private:
	char title[LEN];  // титул 
	double dues;      // Налоги гольф-клуба
public:
	void getdata()
	{
		employee::getdata();
		cout << "  Введите титул: ";       cin >> title;
		cout << "  Введите налоги: "; cin >> dues;
	}
	void putdata()
	{
		employee::putdata();
		cout << "\n  Титул: " << title;
		cout << "\n  Налоги гольф-клуба: " << dues;
	}
};

//класс scientist (ученые)
class scientist : public employee
{
private:
	int pubs;              // число публикаций
public:
	void getdata()
	{
		employee::getdata();
		cout << "  Введите число публикаций: "; cin >> pubs;
	}
	void putdata()
	{
		employee::putdata();
		cout << "\n  Число публикаций: " << pubs;
	}
};

//класс laborer (рабочие)
class laborer : public employee
{
};

//добавить работника в список (хранится в ОП)
void employee::add()
{
	char ch;
	cout << "'m' для добавления менеджера"
			"\n's' для добавления ученого"
			"\n'l' для добавления рабочего"
			"\nВаш выбор: ";
	cin >> ch;
	switch (ch)
	{ //создать объект указанного типа
	case 'm': arrap[n] = new manager;  break;
	case 's': arrap[n] = new scientist; break;
	case 'l': arrap[n] = new laborer;  break;
	default: cout << "\nНеизвестный тип работника\n"; return;
	}
	arrap[n++]->getdata();  //Получить данные от пользователя
}

//Вывести данные обо всех работниках
void employee::display()
{
	for (int j = 0; j<n; j++)
	{
		cout << (j + 1);                // вывести номер
		switch (arrap[j]->get_type()) //вывести тип 
		{
		case tmanager:  cout << ". Тип: Менеджер";  break;
		case tscientist: cout << ". Тип: Ученый"; break;
		case tlaborer:   cout << ". Тип: Рабочий";  break;
		default: cout << ". Неизвестный тип";
		}
		arrap[j]->putdata();           // Вывод данных
		cout << endl;
	}
}

//Возврат типа объекта
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
		cerr << "\nНеправильный тип работника"; exit(1);
	}
	return tmanager;
}

//Записать все объекты, хранящиеся в памяти, в файл
void employee::write()
{
	int size;
	cout << "Идет запись " << n << " работников.\n";
	ofstream ouf;           // открыть ofstream в двоичном виде
	employee_type etype;   // тип каждого объекта employee

	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		cout << "\nНевозможно открыть файл\n"; return;
	}
	for (int j = 0; j<n; j++)  // Для каждого объекта
	{                     // получить его тип
		etype = arrap[j]->get_type();
		// записать данные в файл
		ouf.write((char*)&etype, sizeof(etype));
		switch (etype)         // find its size
		{
		case tmanager:  size = sizeof(manager); break;
		case tscientist: size = sizeof(scientist); break;
		case tlaborer:  size = sizeof(laborer); break;
		}      //запись объекта employee в файл    
		ouf.write( (char*)(arrap[j]), size );
		if (!ouf)
		{
			cout << "\nЗапись в файл невозможна\n"; return;
		}
	}
}

//чтение всех данных из файла в память
void employee::read()
{
	int size;               // размер объекта employee 
	employee_type etype;    // тип работника
	ifstream inf;           // открыть ifstream в двоичном виде
	inf.open("EMPLOY.DAT", ios::binary);
	if (!inf)
	{
		cout << "\nНевозможно открыть файл\n"; return;
	}
	n = 0;                  // В памяти работников нет
	while (true)
	{                     // чтение типа следующего работника
		inf.read((char*)&etype, sizeof(etype));
		if (inf.eof())       // выход из цикла по EOF
			break;
		if (!inf)              // ошибка чтения типа
		{
			cout << "\nНевозможно чтение типа\n"; return;
		}
		switch (etype)
		{                   // создать нового работника
		case tmanager:      // корректного типа
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
		default: cout << "\nНеизвестный тип в файле\n"; return;
		}                   // чтение данных из файла
		inf.read((char*)arrap[n], size);
		if (!inf)              // ошибка, но не EOF
		{
			cout << "\nЧтение данных из файла невозможно\n"; return;
		}
		n++;                  // счетчик работников увеличить
	}  
	cout << "Идет чтение " << n << " работников\n";
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

istream& operator >> (istream& s, Distance& d) //получить значение
{
	cout << "\nВведите футы: ";  s >> d.feet;  
	cout << "Введите дюймы: ";  s >> d.inches; 
	return s;                                  
}
ostream& operator << (ostream& s, Distance& d) // вывести
{                                         
	s << d.feet << "\'-" << d.inches << '\"'; 
	return s;                                 
}

/*
istream& operator >> (istream& s, Distance& d) 
{  
	char dummy;       // для ('), (-) и (")
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

	#pragma region Файловый ввод строк с пробелами
		/*
		ofstream outfile("TES.TXT"); // создать выходной файл 
									  // отправить текст в файл
		outfile << "Первая строка.\n";
		outfile << "Вторая строка.\n";
		outfile << "Третья строка.\n";
		outfile << "Четвертая строка.\n";

		outfile.close();
		*/
		
	#pragma endregion

	#pragma region Файловый вывод строк с пробелами
		/*
		const int MAX = 80;          // размер буфера
		char buffer[MAX];            // буфер символов 
		ifstream infile("TEST.TXT"); // открытие входного файла
		while (!infile.eof())        // цикл до EOF
		{
			infile.getline(buffer, MAX); // читает строку текста
			cout << buffer << endl;      // и выводит ее
		}
		*/
	#pragma endregion

	#pragma region Посимвольный файловый ввод
		/*
		string str = "Время – великий учитель, но, увы, "
			"оно убивает своих учеников.  Берлиоз";

		ofstream outfile("TEST.TXT");   // Привязываем к потоку ofstream выходной файл
		for (int j = 0; j < str.size(); j++) // каждый символ
			//outfile.put(str[j]);        // записывать в файл
			outfile << str[j];
		cout << "Файл записан\n";
		*/
	#pragma endregion

	#pragma region Посимвольный файловый вывод
		/*
		char ch;                     // символ для считывания
		ifstream infile("TEST.TXT"); // входной файл
		while (infile)              // читать до EOF или ошибки
		{
			infile.get(ch);            // считать символ
			cout << ch;                // и вывести его
		}
		cout << endl;
		*/

		/*
		ifstream infile("TEST.TXT"); // создать входной файл

		cout << infile.rdbuf();      // передать его буфер в cout
		cout << endl;
		*/
	#pragma endregion

	#pragma region Двоичный ввод/вывод целочисленных данных
		/*
		for (int j = 0; j< MAX; j++) // заполнить буфер данными
			buff[j] = j;           // (0, 1, 2, ...)
								   // создать выходной поток
		ofstream os("edata.dat", ios::binary);
		// записать в него
		os.write(reinterpret_cast<char*>(buff), MAX * sizeof(int));
		os.close();              // должен закрыть его

		for (int j = 0; j<MAX; j++)     // стереть буфер
			buff[j] = 0;
		// создать входной поток
		ifstream is("edata.dat", ios::binary);
		// читать из него
		is.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));

		for (int j = 0; j<MAX; j++)     // проверка данных
			if (buff[j] != j)
			{
				cerr << "Некорректные данные!\n"; return 1;
			}
		cout << "Данные корректны\n";
		*/
		//reinterpret_cast - изменяет тип данных в области памяти,
		//совершенно не задумываясь имеет ли это смысл
		//Нужно для того, чтобы буфер данных типа int,
		//выглядел для функций read() и write(), как буфер типа char
		/*
		Биты режима:
		in - открытие для чтения(ifstream)
		out - открытие для записи(ofstream)
		ate - чтение с конца файла
		app - запись с конца файла
		trunc - обрезать файл до нулевой длины, если он существует
		nocreate - не открывать несуществующий файл
		noreplace - не открывать для вывода существующий файл, если не установлены ate и app
		binary - открыть в бинарном режиме
		*/
		
	#pragma endregion

	#pragma region Сохранение объектов в файле
		/*
		person pers;            // создать объект
		pers.getData();         // получить данные
								// создать объект ofstream
		ofstream os("PERSON.DAT", ios::binary);
		// записать в него
		os.write(reinterpret_cast<char*>(&pers), sizeof(person));
		os.close();
		*/
	#pragma endregion

	#pragma region Чтение объекта из файла
		/*
		person pers;          // переменная типа person
		ifstream is("PERSON.DAT", ios::binary);// создать поток
												   // чтение потока
		is.read(reinterpret_cast<char*>(&pers), sizeof(pers));
		pers.showData();      // вывести данные
		is.close();
		*/
	#pragma endregion

	#pragma region Чтение из файла и запись нескольких объектов
		/*
		char ch;
		person pers;          // создать объект person
		fstream file;         // создать входной/выходной файл
							  // открыть для дозаписи
		file.open("GROUP.DAT", ios::app | ios::out | ios::in | ios::binary);

		do                    // данные от пользователя – в файл
		{
			cout << "\nВведите данные о человеке:\n";
			pers.getData();     // получить данные
								// записать их в файл
			file.write(reinterpret_cast<char*>(&pers), sizeof(pers));
			cout << "Продолжить ввод (y/n)? ";
			cin >> ch;
		} while (ch == 'y');       // выход по 'n'
		file.seekg(0);        // поставить указатель на начало файла
							  // считать данные о первом человеке
		file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
		while (!file.eof())  // Выход по EOF
		{
			cout << "\nПерсона:\n"; //вывести данные
			pers.showData();      //считать данные о следующем
			file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
		}
		cout << endl;
		*/
	#pragma endregion

	#pragma region Поиск конкретного объекта в файле
		/*
		person pers;                  // создать объект person 
		ifstream is;				// создать входной файл
		is.open("GROUP.DAT", ios::in | ios::binary); // открыть файл
		is.seekg(0, ios::end);    // установить указатель на 0 байт от конца файла
		int endposition = is.tellg();      // найти позицию (tellg - возврат текущей позиции указателя)
		int n = endposition / sizeof(person);  // число человек
		cout << "\nВ файле " << n << " человек(а)";
		
		cout << "\nВведите номер персоны: ";
		cin >> n;
		int position = (n - 1) * sizeof(person); // умножить размер
												 // данных под персону на число персон
		is.seekg(position);               // число байт от начала
											  // прочитать одну персону
		is.read(reinterpret_cast<char*>(&pers), sizeof(pers));
		pers.showData();                      //вывести одну персону
		cout << endl;
		*/
	#pragma endregion

	#pragma region Обработка ошибок ввода/вывода
		/*
		for (int j = 0; j<MAX; j++)    // заполнить буфер данными
			buff[j] = j;
		ofstream os;                // создать выходной поток
									// открыть его
		os.open("edata.dat", ios::trunc | ios::binary);
		if (!os)
		{
			cout << "Невозможно открыть выходной файл\n"; 
			system("pause");
			exit(1);
		}
		
		cout << "Идет запись...\n"; // записать в него содержимое
									// буфера
		os.write(reinterpret_cast<char*>(buff), MAX * sizeof(int));
		if (!os)
		{
			cout << "Запись в файл невозможна\n";
			system("pause");
			exit(2);
		}
		os.close();                 // надо закрыть поток
		
		for (int j = 0; j<MAX; j++)        // очистить буфер
			buff[j] = 0;
		
		ifstream is;                // создать входной поток
		is.open("edata.dat", ios::binary);
		if (!is)
		{
			cerr << "Невозможно открыть входной файл\n"; exit(1);
		}
		
		cout << "Идет чтение...\n"; // чтение файла
		is.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));
		if (!is)
		{
			cerr << "Невозможно чтение файла\n"; exit(1);
		}
		
		for (int j = 0; j<MAX; j++)        // проверять данные
			if (buff[j] != j)
			{
				cerr << "\nДанные некорректны\n"; exit(1);
			}
		cout << "Данные в порядке\n";
		*/
	#pragma endregion

	#pragma region Проверка ошибок открытия файла
		/*
		ifstream file;
		file.open("edata.dat");
		
		if (!file)
		cout << "\nНевозможно открыть GROUP.DAT";
		else
		cout << "\nФайл открыт без ошибок.";
		cout << "\nКод ошибки = " << file.rdstate();
		cout << "\ngood() = " << file.good();
		cout << "\neof() = " << file.eof();
		cout << "\nfail() = " << file.fail();
		cout << "\nbad() = " << file.bad() << endl;
		file.close();
		*/
	#pragma endregion

	#pragma region Файловый ввод/вывод объектов person
		/*
		person p;                  // создать пустую запись
		char ch;
		
		do {                       // сохранение данных на диск
			cout << "Введите данные о человеке: ";
			p.getData();             // Получить данные
			p.diskOut();             // записать на диск
			cout << "Продолжить (y/n)? ";
			cin >> ch;
		} while (ch == 'y');       // цикл до 'n'
		
		int n = person::diskCount(); // сколько людей в файле?
		cout << "В файле " << n << " человек(а)\n";
		for (int j = 0; j<n; j++)       // для каждого
		{
			cout << "\nПерсона " << j;
			p.diskIn(j);               // считать с диска
			p.showData();              // вывести данные
		}
		cout << endl;
		*/
	#pragma endregion

	#pragma region Файловый ввод/вывод объектов employee | Поддержка объектов неодинаковых размеров
		/*
		char ch;
		while (true)
		{
			cout << "'a' – добавление сведений о работнике"
					"\n'd' - вывести сведения обо всех работниках"
					"\n'w' – записать все данные в файл"
					"\n'r' – прочитать все данные из файла"
					"\n'x' - выход"
					"\nВаш выбор: ";
			cin >> ch;
			switch (ch)
			{
			case 'a':           // добавить работника
				employee::add(); break;
			case 'd':           // вывести все сведения
				employee::display(); break;
			case 'w':           // запись в файл
				employee::write(); break;
			case 'r':           // чтение всех данных из файла
				employee::read(); break;
			case 'x': exit(0);  // выход
			default: cout << "\nНеизвестная команда";
			}  
		}  
		*/
	#pragma endregion

	#pragma region Перегрузка << >>
		/*
		Distance dist1, dist2;     
		Distance dist3(11, 6.25);  
		cout << "\nВведите два значения расстояний:";
		cin >> dist1 >> dist2;    
		cout << "\ndist1 = " << dist1 << "\ndist2 = " << dist2;
		cout << "\ndist3 = " << dist3 << endl;
		*/
	#pragma endregion

	#pragma region Перегрузка операции << и >> с файлами
		/*
		char ch;
		Distance dist1;
		ofstream ofile;         // создать и открыть
		ofile.open("DIST.DAT"); // выходной поток
		
		do {
			cout << "\nВведите расстояние: ";
			cin >> dist1;         // получить данные от пользователя
			ofile << dist1;       // записать их в выходной поток
			cout << "Продолжать (y/n)? ";
			cin >> ch;
		} while (ch != 'n');
		ofile.close();          // закрыть выходной поток
		
		ifstream ifile;         // создать и открыть 
		ifile.open("DIST.DAT"); // входной поток
		
		cout << "\nСодержимое файла:\n";
		while (true)
		{
			ifile >> dist1;       // чтение данных из потока
			if (ifile.eof())     // выход по EOF
				break;
			cout << "Расстояние = " << dist1 << endl; //вывод
													  // расстояний
		}
		*/
	#pragma endregion

	#pragma region Verylong
		/*
		unsigned long numb, j;
		verylong fact = 1;       //инициализировать verylong
		
		cout << "\n\nВведите число: ";
		cin >> numb;           //ввод числа типа long int
		
		for (j = numb; j>0; j--)  
		fact = fact * j;     
		cout << "Факториал= "; 
		fact.putvl();          //вывести значение факториала
		cout << endl;
		*/
	#pragma endregion

	#pragma region Лифты
		/*
		building theBuilding;
		while (true)
		{
			theBuilding.master_tick(); //послать временные метки
									   //всем лифтам
			wait(1000);                //пауза
									   //получить запросы этажей от пользователей
			theBuilding.record_floor_reqs();
		}
		*/
	#pragma endregion

	system("pause");
    return 0;
}