#include<iostream>
#include <fstream>
#include "func.h"

using namespace std;

bool isInt(string data) {
	bool check = true;

	// сравниваем посимвольно с цифрами от 0 до 9
	for (unsigned int i = 0; i < (data.length()); i++) {
		if (!((data[i] >= '0') && (data[i] <= '9')))
			check = false;
	}
	return check;
}

// для сканирования целых чисел в функции create
int cin_int(string name_field)
{
	int stop = 0;
	while (!stop)
	{
		// выводим поле на экран
		cout << name_field << " = ";
		string digit;
		// запрос с клавиатуры
		cin >> digit;

		// проверка является ли числом 
		bool b = isInt(digit);

		// если число
		if (b == true)
		{
			stop = 1;
			// заканчиваем и возвращаем

			return atoi(digit.c_str()); // функ. преобразуем строку в число
		}
		else // иначе если не число
		{
			// ругашка
			cout << "Ошибка ввода > " << name_field << " < " << endl;\
			// запрос ещё раз, не выходим из цикла while
			stop = 0;
		}
	}

	return 0;
}



ostream& operator<<(ostream& out, const Kinopoisk& f) {
	out << f._id << " " << f._title << " " << f._year << " " << f._length << " " << f._country << " " << f._genre << " " << f._director << " " << f._rank << endl;
	return out;
}
istream& operator>>(istream& in, Kinopoisk& f) {
	in >> f._id >> f._title >> f._year >> f._length >> f._country >> f._genre >> f._director >> f._rank;
	return in;
}

void Func::save(Kinopoisk* arr, int n) {
		ofstream f("Kinopoisk.txt");
		if (!f.is_open()) {
			cout << "Ошибка файл не открыт" << endl;
			return;
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i].getId() == -1)
				count++;
		}
		f << n-count << endl;
		int count_no_del = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i].getId() == -1)
				continue;
			count_no_del++;
			arr[i].setId(count_no_del);
			f << arr[i];
		}
		cout << "Сохранено: " << n-count << endl;
		f.close();
}
Kinopoisk* Func::add(Kinopoisk* arr, int& n) {

	Kinopoisk* arr_new = new Kinopoisk;

	cout << " title= ";
	string title;
	cin >> title;
	arr_new->setTitle(title);
	int year;
	year = cin_int("year");
	arr_new->setYear(year);
	int length;
	length = cin_int("length");
	arr_new->setLength(length);
	cout << " country= ";
	string country;
	cin >> country;
	arr_new->setCountry(country);
	cout << " genre= ";
	string genre;
	cin >> genre;
	arr_new->setGenre(genre);
	cout << " director= ";
	string director;
	cin >> director;
	arr_new->setDirector(director);
	int rank;
	rank = cin_int("rank");
	arr_new->setRank(rank);


	n++; // кол-во эл-ов в списке 
	arr_new->setId(n); // n++  свой индекс у каждого добаляемого эл-та 
	Kinopoisk* arr_new_all = new Kinopoisk[n];

	if(arr)
		for (int i = 0; i < n - 1; i++) { 
			arr_new_all[i] = arr[i];
		}

	arr_new_all[n - 1] = arr_new[0]; // добавляем в конец новый добавленный 
	delete arr_new;
	return arr_new_all;
}



Kinopoisk* Func::read(int& n){
		ifstream f("Kinopoisk.txt");
		if (!f.is_open())
			return nullptr;
		f >> n;
		if (n < 1) 
			return nullptr;

		Kinopoisk* arr = new Kinopoisk[n];
		for (int i = 0; i < n; i++) {
			if (arr[i].getId() == -1)
				continue;
			f >> arr[i];
		}
		f.close();
		return arr;
}

void Func::print(Kinopoisk* arr, int n) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (arr[i].getId() == -1)
			continue;
		cout << arr[i];
	}
	cout << endl;
}

Kinopoisk* Func::edit(Kinopoisk* arr, int n) {
	if (arr) {
		int index;
		cout << "Введите нужный id" << endl;
		index = cin_int("id");
		if (index <= 0) {
			cout << "Ошибка! Индекс не должен быть отрицательным!" << endl;
			return arr;
		}
		if (index > n) {
			cout << "Ошибка! Такого индекса нет в списке!" << endl;
			return arr;
		}
		int i = 0;
		for (i = 0; i < n; i++) {
			if (arr[i].getId() == index) {
				cout << arr[i];
				break;
			}
		}
			string title, country, genre, director;
			int year = 0;
			int length = 0;
			int rank = 0;
			char key;
		bool valid_input = false;
		string input;
		while(!valid_input) {
			cout << "Введите редактируемое поле" << endl;
			cout << "1-title, 2-year, 3-length, 4-country, 5-genre, 6-director, 7-rank, 8-ALL edit field" << endl;
			cin >> input;
			if (input.length() == 1 && isdigit(input[0]) && input[0] >= '1' && input[0] <= '8') {
				valid_input = true ;
			}
			else {
				cout << "Ошибка! Введите число от 1 до 8" << endl;
			}
		}
		key = input[0];
			switch (key) {
			case '1':
				cout << "NEW title = ";
				cin >> title;
				arr[i].setTitle(title);
				break;
			case '2':
				year = cin_int("NEW year");
				arr[i].setYear(year);
				break;
			case '3':
				length = cin_int("NEW length");
				arr[i].setLength(length);
				break;
			case '4':
				cout << "NEW country = ";
				cin >> country;
				arr[i].setCountry(country);
				break;
			case '5':
				cout << "NEW genre = ";
				cin >> genre;
				arr[i].setGenre(genre);
				break;
			case '6':
				cout << "NEW director = ";
				cin >> director;
				arr[i].setDirector(director);
				break;
			case '7':
				rank = cin_int("NEW rank");
				arr[i].setRank(rank);
				break;
			case '8':
				cout << "NEW title = ";
				cin >> title;
				arr[i].setTitle(title);
				year = cin_int("NEW year");
				arr[i].setYear(year);
				length = cin_int("NEW length");
				arr[i].setLength(length);
				cout << "NEW country = ";
				cin >> country;
				arr[i].setCountry(country);
				cout << "NEW genre = ";
				cin >> genre;
				arr[i].setGenre(genre);
				cout << "NEW director = ";
				cin >> director;
				arr[i].setDirector(director);
				rank = cin_int("NEW rank");
				arr[i].setRank(rank);
				break;
			}
			return arr;
		}

	}


			

void Func::search(Kinopoisk* arr, int n) {
	if (arr) {
		int index;
		cout << "Введите нужный id" << endl;
		index = cin_int("id");
		if (index <= 0) {
			cout << "Ошибка! Индекс не должен быть отрицательным!" << endl;
			return;
		}
		if (index > n) {
			cout << "Ошибка! Такого индекса нет в списке!" << endl;
			return;
		}

		for (int i = 0; i < n; i++) {
			if (arr[i].getId() == index) {
				cout << arr[i];
			}
		}
	}
}


void Func::deleted(Kinopoisk* arr, int n) {
	if (arr) {
		int index;
		cout << "Введите нужный id" << endl;
		index = cin_int("id");
		if (index <= 0) {
			cout << "Ошибка! Индекс не должен быть отрицательным!" << endl;
			return;
		}
		if (index > n) {
			cout << "Ошибка! Такого индекса нет в списке!" << endl;
			return;
		}
	
		for (int i = 0; i < n; i++) {
			if (arr[i].getId() == index) {
				cout << arr[i];
				arr[i].setId(-1);
				break;
			}

		}

		int count_no_del = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i].getId() == -1)
				continue;
			count_no_del++;
			arr[i].setId(count_no_del);
		}
		
	}
}


