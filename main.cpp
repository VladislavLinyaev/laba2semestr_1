#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "Kinopoisk.h"
using namespace std;
using namespace Func;

int main() {
	setlocale(LC_ALL, "Russian");
	Kinopoisk* kino = nullptr;
	int n = 0;
	int l = 10;
	string k = "";
	int stop = 0; 
	while (stop != 1) {
		char key;
		string input;
		bool valid_input = false;
		while(!valid_input) {
			cout << "1-add, 2-save, 3-read, 4-search, 5-edit, 6-deleted, 7-print, 8-exit" << endl;
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
				kino = add(kino, n);
				l = 0;
			break;
		case '2':
			l = 10;
			if (kino != nullptr) {
				save(kino, n);
			}
			else
				cout << "Ошибка сохранения! Нет доступных полей!" << endl;
			break;
		case '3':
			kino = read(n);
			if (!kino)
				cout << "Ошибка чтения! Нет доступных полей!" << endl;
			else {
				l = 0;
				cout << "Загружено: " << n << endl;
			}
			break;
		case '4':
			if (kino != nullptr)
				search(kino, n);
			else
				cout << "Ошибка поиска! Нет доступных полей!" << endl;
			break; 
		case '5':
			if (kino != nullptr) {
				kino = edit(kino, n);
				l = 0;
			}
			else
				cout << "Ошибка! Нет доступных полей!" << endl;
			break;
		case '6':
			if (kino != nullptr) {
				deleted(kino, n);
				l = 0;
			}
			else
				cout << "Ошибка! Нет доступных полей!" << endl;
			break;
			
		case '7':
			if (kino != nullptr)
				print(kino, n);
			else
				cout << "Ошибка! Нет доступных полей!" << endl;
			break;
		case '8':
			if (l == 10) {
				stop = 1;
			}
			else {
				cout << "Сохранить все изменения?" << endl;
				cout << "Введите y или n: ";
				cin >> k;
				if (k == "y") {
					if (kino != nullptr) {
						save(kino, n);
						stop = 1;
					}
					else {
						cout << "Ошибка сохранения! Нет доступных полей!" << endl;

					}

				}
				else {
					if (k == "n") {
						stop = 1;
					}
					else {
						cout << "Ошибка! Введите y или n!" << endl;
					}

				}
	
			}
			break;
		}
	}
	return 0;
}