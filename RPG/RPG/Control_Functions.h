#pragma once
#include <iostream>

using namespace std;

int generate(int a, int b) {
	return rand() % (b - a + 1) + a;
}

template<class T>
void my_swap(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}

void gen_field(int row, int col, char** field) {
	char wall = '#';
	for (int i = 0; i < col; i++) {
		field[i] = new char[row];
	}
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if ((i == 0) || (i == (col - 1)) || (j == 0) || (j == (row - 1))) {
				field[i][j] = '#';
			}
			else {
				field[i][j] = ' ';
			}
		}
	}
}

void show_field(int row, int col, char** field) {
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if ((i == 0) || (i == (col - 1)) || (j == 0) || (j == (row - 1))) {
				cout << field[i][j];
			}
			else {
				cout << field[i][j];
			}
		}
		cout << endl;
	}
}

void del_field(int col, char** field) {
	for (int i = 0; i < col; i++) {
		delete[] field[i];
	}
	delete[] field;
}