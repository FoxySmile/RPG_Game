#pragma once
#include <iostream>
#include <conio.h>
#include "Control_Functions.h"

using namespace std;

bool start;
char marker;
int xp, mp, vit;
int min_dam_1, max_dam_1;
int min_dam_2, max_dam_2;
int min_dam_3, max_dam_3;
int xp_1, mp_1, vit_1;
int lever = 0;
int num_items = 60;

struct skill {
	int min_damage;
	int max_damage;
};

struct info_player {
	int xp;
	int mp;
	int vit;
	skill skill_player[3];
};

void gen_items() {
	int items = generate(1, 20);

	if (items == 1 || items == 2 || items == 3) {
		if (mp_1 + 50 > mp) {
			mp_1 = mp;
		}
		else {
			mp_1 = mp_1 + 50;
		}
		lever = 1;
	}
	if (items == 4 || items == 5 || items == 6) {
		if (xp_1 + 50 > xp) {
			xp_1 = xp;
		}
		else {
			xp_1 = xp_1 + 50;
		}
		lever = 2;
	}
	if (items == 7 || items == 8 || items == 9) {
		vit_1 = 100;
		lever = 3;
	}
	if (items == 10 || items == 11 || items == 12 || items == 13 || items == 14 || items == 15) {
		lever = 4;
	}
	if (items == 16) {
		lever = 5;
	}
}

void control(int row, int col, char** field) {
	int button;
	lever = 0;

	button = _getch();
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (field[i][j] == marker) {
				if ((button == 'F') || (button) == 'f') {
					if ((field[i - 1][j]) == 'O') {
						gen_items();
						field[i - 1][j] = ' ';
						return;
					}
					if (field[i + 1][j] == 'O') {
						gen_items();
						field[i + 1][j] = ' ';
						return;
					}
					if ((field[i][j - 1]) == 'O') {
						gen_items();
						field[i][j - 1] = ' ';
						return;
					}
					if (field[i][j + 1] == 'O') {
						gen_items();
						field[i][j + 1] = ' ';
						return;
					}
				}
				if ((button == '8') || (button == 'W') || (button == 'w')) {
					if (i - 1 < 1 || field[i - 1][j] == 'O') {
						break;
					}
					my_swap(field[i][j], field[i - 1][j]);
					return;
				}
				if ((button == '5') || (button == 'S') || (button == 's')) {
					if (i + 1 > col - 2 || field[i + 1][j] == 'O') {
						break;
					}
					my_swap(field[i][j], field[i + 1][j]);
					return;
				}
				if ((button == '4') || (button == 'A') || (button == 'a')) {
					if (j - 1 < 1 || field[i][j - 1] == 'O') {
						break;
					}
					my_swap(field[i][j], field[i][j - 1]);
					return;
				}
				if ((button == '6') || (button == 'D') || (button == 'd')) {
					if (j + 1 > row - 2 || field[i][j + 1] == 'O') {
						break;
					}
					my_swap(field[i][j], field[i][j + 1]);
					return;
				}
				if ((button == 'N') || (button == 'n')) {
					cout << "\nТочно желаете покинуть игру? Y(Да)\\N(Нет)";
					button = _getch();
					if ((button == 'Y') || (button == 'y')) {
						start = false;
						return;
					}
				}
			}
		}
	}
}

void spawn(int row, int col, char** field) {
	int i = generate(1, col - 2);
	int j = generate(1, row - 2);
	field[i][j] = marker;
}

bool character_selection(char ch) {
	info_player players[3];

	players[0].skill_player[0].min_damage = 3;
	players[0].skill_player[0].max_damage = 6;

	players[0].skill_player[1].min_damage = 6;
	players[0].skill_player[1].max_damage = 9;

	players[0].skill_player[2].min_damage = 10;
	players[0].skill_player[2].max_damage = 20;

	players[0].xp = 150;
	players[0].mp = 75;
	players[0].vit = 100;


	players[1].skill_player[0].min_damage = 3;
	players[1].skill_player[0].max_damage = 5;

	players[1].skill_player[1].min_damage = 5;
	players[1].skill_player[1].max_damage = 8;

	players[1].skill_player[2].min_damage = 10;
	players[1].skill_player[2].max_damage = 20;

	players[1].xp = 75;
	players[1].mp = 100;
	players[1].vit = 100;


	players[2].skill_player[0].min_damage = 2;
	players[2].skill_player[0].max_damage = 5;

	players[2].skill_player[1].min_damage = 5;
	players[2].skill_player[1].max_damage = 7;

	players[2].skill_player[2].min_damage = 10;
	players[2].skill_player[2].max_damage = 20;

	players[2].xp = 100;
	players[2].mp = 150;
	players[2].vit = 100;

	while (true) {
		cout << R"(	     Необходимо выбрать героя

	Описание каждого героя в главном меню,
	  не будь ленивым, прочти заранее

	1)	Рыцарь (*)
	2)	Охотник ($)
	3)	Друид (@)

	N)	Назад

	Каким будет твоё решение?)";
		ch = _getch();

		if (ch == '1') {
			marker = '*';

			min_dam_1 = players[0].skill_player[0].min_damage;
			max_dam_1 = players[0].skill_player[0].max_damage;

			min_dam_2 = players[0].skill_player[1].min_damage;
			max_dam_2 = players[0].skill_player[1].max_damage;

			min_dam_3 = players[0].skill_player[2].min_damage;
			max_dam_3 = players[0].skill_player[2].max_damage;

			xp = players[0].xp;
			mp = players[0].mp;
			vit = players[0].vit;
			system("cls");
			return true;
		}

		if (ch == '2') {
			marker = '$';
			min_dam_1 = players[1].skill_player[0].min_damage;
			max_dam_1 = players[1].skill_player[0].max_damage;

			min_dam_2 = players[1].skill_player[1].min_damage;
			max_dam_2 = players[1].skill_player[1].max_damage;

			min_dam_3 = players[1].skill_player[2].min_damage;
			max_dam_3 = players[1].skill_player[2].max_damage;

			xp = players[1].xp;
			mp = players[1].mp;
			vit = players[1].vit;
			system("cls");
			return true;
		}

		if (ch == '3') {
			marker = '@';
			min_dam_1 = players[2].skill_player[0].min_damage;
			max_dam_1 = players[2].skill_player[0].max_damage;

			min_dam_2 = players[2].skill_player[1].min_damage;
			max_dam_2 = players[2].skill_player[1].max_damage;

			min_dam_3 = players[2].skill_player[2].min_damage;
			max_dam_3 = players[2].skill_player[2].max_damage;

			xp = players[2].xp;
			mp = players[2].mp;
			vit = players[2].vit;
			system("cls");
			return true;
		}

		if ((ch == 'N') || (ch == 'n')) {
			system("cls");
			return false;
		}
		system("cls");
	}
}

void items_spawn(int row, int col, char** field) {
	for (int n = 0; n < num_items; n++) {
		int i = generate(1, col - 2);
		int j = generate(1, row - 2);
		while (field[i][j] != ' ') {
			i = generate(1, col - 2);
			j = generate(1, row - 2);
		}
		field[i][j] = 'O';
	}
}

void battle() {
	int xp_gob = 30;
	char ch;
	int damage = 0;
	int gob_damage = 0;
	cout << R"(Перед вами появляется Гоблин

Нанесите удар одной из способностью!

1)	1-я способность
2)	2-я способность
3)	3-я способность

N)	Сбежать(-20 XP)

Что желаете выбрать?)" << endl;
	while (true) {
		cout << "----------------------------------------" << endl;
		cout << "\tГоблин XP:" << xp_gob << endl;
		ch = _getch();
		if (ch == '1') {
			if (vit_1 <= 9) {
				cout << "\n-------------------------------" << endl;
				cout << "У вас закончилась выносливость!" << endl;
				cout << "-------------------------------" << endl;
			}
			else {
				damage = generate(min_dam_1, max_dam_1);
				vit_1 -= 10;
				xp_gob -= damage;
				gob_damage = generate(4, 10);
				xp_1 -= gob_damage;
			}
		}
		if (ch == '2') {
			if (vit_1 <= 24) {
				cout << "\n-------------------------------" << endl;
				cout << "У вас закончилась выносливость!" << endl;
				cout << "-------------------------------" << endl;
			}
			else {
				damage = generate(min_dam_2, max_dam_2);
				vit_1 -= 25;
				xp_gob -= damage;
				gob_damage = generate(4, 10);
				xp_1 -= gob_damage;
			}
		}
		if (ch == '3') {
			if (mp_1 <= 24) {
				cout << "\n-----------------------" << endl;
				cout << "У вас закончилась мана!" << endl;
				cout << "-----------------------" << endl;

			}
			else {
				damage = generate(min_dam_3, max_dam_3);
				mp_1 -= 25;
				xp_gob -= damage;
				gob_damage = generate(4, 10);
				xp_1 -= gob_damage;
			}
		}
		if (ch == 'N' || ch == 'n') {
			xp_1 -= 20;
			cout << "\n\nВы решили прибегнуть к бегству(Потеряно 20 единиц здоровья)\n\n" << endl;
			if (xp_1 <= 0) {
				cout << "---------------------------------" << endl;
				cout << "Вы мертвы!!! Начните игру заново!" << endl;
				cout << "---------------------------------\n\n" << endl;
				start = false;
				return;
			}
			break;
		}
		cout << "\nВы нанесли " << damage << " единиц урона" << endl;
		cout << "Гоблин нанёс " << gob_damage << " единиц урона" << endl;
		cout << "\nXP:" << xp_1 << "\t\tMP:" << mp_1 << "\t\tVIT:" << vit_1 << endl;

		if (xp_1 <= 0) {
			cout << "---------------------------------" << endl;
			cout << "Вы мертвы!!! Начните игру заново!" << endl;
			cout << "---------------------------------\n\n" << endl;
			start = false;
			return;
		}
		if (xp_gob <= 0) {
			cout << "\n-------------------" << endl;
			cout << "Гоблин повержен!!!" << endl;
			cout << "-------------------\n\n" << endl;
			return;
		}
	}
}

void show_items() {
	if (lever == 1) {
		cout << "----------------------------------------------" << endl;
		cout << "Вы нашли зелье маны, восстановленно 50 единиц!" << endl;
		cout << "----------------------------------------------\n\n" << endl;
		system("pause");
	}
	if (lever == 2) {
		cout << "-----------------------------------------------------" << endl;
		cout << "Вы нашли зелье регенирации, восстановленно 50 единиц!" << endl;
		cout << "-----------------------------------------------------\n\n" << endl;
		system("pause");
	}
	if (lever == 3) {
		cout << "------------------------------------------------------" << endl;
		cout << "Вы нашли зелье запаса сил, восстановленно 100 единиц!" << endl;
		cout << "------------------------------------------------------\n\n" << endl;
		system("pause");
	}
	if (lever == 4) {
		battle();
		system("pause");
	}
	if (lever == 5) {
		cout << "--------------------------------" << endl;
		cout << "Вы нашли выход! Игра окончена!!!" << endl;
		cout << "--------------------------------\n\n" << endl;
		system("pause");
		start = false;
	}
}

bool control_exit(int row, int col, char** field) {
	int n = 0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (field[i][j] == 'O') {
				n++;
			}
		}
	}
	if (n == 0) {
		return true;
	}
	return false;
}