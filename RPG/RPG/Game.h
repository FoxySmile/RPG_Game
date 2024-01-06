#pragma once
#include <iostream>
#include <conio.h>
#include "Control_Functions.h"
#include "Info.h"
#include "Game_Functions.h"

using namespace std;

void game() {
	int row = 40;
	int col = 15;

	char** field = new char* [col];

	gen_field(row, col, field);
	spawn(row, col, field);
	items_spawn(row, col, field);

	while (start) {
		show_field(row, col, field);
		cout << "XP:" << xp_1 << "\t\tMP:" << mp_1 << "\t\tVIT:" << vit_1 << endl << endl;
		show_items();
		if (control_exit(row, col, field)) {
			cout << "\n--------------------------------" << endl;
			cout << "Вы нашли выход! Игра окончена!!!" << endl;
			cout << "--------------------------------\n\n" << endl;
			system("pause");
			start = false;
		}
		cout << "\n\nДля окончания игры нажмите \"N/n\"";
		control(row, col, field);
		system("cls");
	}

	del_field(col, field);
}


void menu() {
	char ch;
	while (true) {
		cout << R"(		   Меню

1)		Начать игру

2)		Управление
3)		  Об игре

N)		  Выход

Что желаете выбрать? :))" << endl;
		ch = _getch();
		if (ch == '1') {
			start = true;
			system("cls");
			if (character_selection(ch)) {
				xp_1 = xp;
				mp_1 = mp;
				vit_1 = vit;
				game();
			}
			continue;
		}
		if (ch == '2') {
			system("cls");
			control_info(ch);
			continue;
		}
		if (ch == '3') {
			system("cls");
			game_info(ch);
			continue;
		}
		if ((ch == 'N') || (ch == 'n')) {
			cout << "\nТочно желаете покинуть игру? Y(Да)\\N(Нет)";
			ch = _getch();
			if ((ch == 'Y') || (ch == 'y')) {
				system("cls");
				cout << "\n\t\tГерой, ждём твоего возвращения :)\n\n";
				system("pause");
				return;
			}
		}
		system("cls");
	}
}