#include <stdio.h>
#include <time.h>
#include <random>
#include "ctime"
#include<iostream>
#include <windows.h>
#include <stdlib.h>
struct top {
	double x;
	double y;
	double tg;
};
void func_MonteKarlo();
void square_random();
void analit_math();
int main()
{



	int a = -1;
	while (a != 0) {
		printf("what do u want?\n");
		printf("S mnogoygolnika po tochkam-1\n");
		printf("S randomnogo mnogoygolnika-2\n");
		printf("S nekotorih figur, zadannih analiticheski-3\n");
		printf("exit-0\n");

		scanf_s("%i", &a);
		switch (a) {
		case 1:
			func_MonteKarlo();

			break;
		case 2:
			square_random();
			break;
		case 3:
			analit_math();
			break;
		}

	}

	return 0;
}
void krug() {
	printf("vvedite  R\n");
	double r;
	scanf_s("%lf", &r);
	double min_x, max_x, min_y, max_y, squire_rectangle;
	int  number_inner_points = 0;
	srand(time(NULL));
	min_x = -r * 2;
	max_x = r * 2;
	min_y = -r * 2;
	max_y = r * 2;
	squire_rectangle = 16 * r * r;
	int number_points;
	printf("\nEnter number of points: ");
	scanf_s("%i", &number_points);
	top point;
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	for (int l = 0; l < number_points; l++) {
		point.x = rand() * 1.0 / (RAND_MAX) * (max_x - min_x) + min_x;
		point.y = rand() * 1.0 / (RAND_MAX) * (max_y - min_y) + min_y;
		COLORREF color;
		if (point.x * point.x + point.y * point.y < r * r) {

			number_inner_points++;
			color = RGB(255, 0, 0);
		}
		else {
			color = RGB(0, 255, 0);
		}
		SetPixel(hDC, point.x * 5 + 500, 100 + (100 - point.y) * 5, color);
	}
	srand(time(NULL));
	double squire;
	squire = squire_rectangle * 1.0 * number_inner_points / number_points;
	printf("\nSquire of poligon:\t%g", squire);
}
void kolco() {
	printf("vvedite  R\n");
	double R;
	scanf_s("%lf", &R);
	double min_x, max_x, min_y, max_y, squire_rectangle;
	int  number_inner_points = 0;
	srand(time(0));
	min_x = -R * 2;
	max_x = R * 2;
	min_y = -R * 2;
	max_y = R * 2;
	squire_rectangle = 16 * R * R;
	printf("vvedite  r\n");
	double r;
	scanf_s("%lf", &r);
	int number_points;
	printf("\nEnter number of points: ");
	scanf_s("%i", &number_points);
	top point;
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	for (int l = 0; l < number_points; l++) {
		point.x = rand() * 1.0 / (RAND_MAX) * (max_x - min_x) + min_x;
		point.y = rand() * 1.0 / (RAND_MAX) * (max_y - min_y) + min_y;

		COLORREF color;
		if ((point.x * point.x + point.y * point.y > r * r) && (point.x * point.x + point.y * point.y < R * R)) {
			number_inner_points++;
			color = RGB(255, 0, 0);

		}
		else {

			color = RGB(0, 255, 0);
		}
		SetPixel(hDC, point.x * 5 + 500, 100 + (100 - point.y) * 5, color);
	}
	srand(time(NULL));
	double squire;
	squire = squire_rectangle * 1.0 * number_inner_points / number_points;
	printf("\nSquire of poligon:\t%g", squire);
}
void lemniskata() {
	srand(time(NULL));
	printf("vvedite fokus\n");
	double focus;
	scanf_s("%lf", &focus);
	double min_x, max_x, min_y, max_y, squire_rectangle;
	int number_inner_points = 0;
	min_x = -focus * 2;
	max_x = focus * 2;
	min_y = -focus;
	max_y = focus;
	squire_rectangle = 4 * focus * focus;
	int number_points;
	printf("\nEnter number of points: ");
	scanf_s("%i", &number_points);
	top point;
	top focus_top;
	focus_top.x = focus;
	focus_top.y = 0;
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	for (int l = 0; l < number_points; l++) {
		point.x = rand() * 1.0 / (RAND_MAX) * (max_x - min_x) + min_x;
		point.y = rand() * 1.0 / (RAND_MAX) * (max_y - min_y) + min_y;
		COLORREF color;
		if (sqrt((point.x - focus_top.x) * (point.x - focus_top.x) + (point.y - focus_top.y) * (point.y - focus_top.y)) * sqrt((point.x + focus_top.x) * (point.x + focus_top.x) + (point.y - focus_top.y) * (point.y - focus_top.y)) <= focus * focus) {
			number_inner_points++;
			color = RGB(255, 0, 0);
		}
		else {
			color = RGB(0, 255, 0);
		}
		SetPixel(hDC, point.x * 5 + 500, 100 + (100 - point.y) * 5, color);
	}
	double squire;
	squire = squire_rectangle * 1.0 * number_inner_points / number_points;
	printf("\nSquire of poligon:\t%g", squire);
}
void astroida() {
	printf("vvedite  R\n");
	double r;
	scanf_s("%lf", &r);
	double min_x, max_x, min_y, max_y, squire_rectangle;
	int  number_inner_points = 0;
	srand(time(NULL));
	min_x = -r;
	max_x = r;
	min_y = -r;
	max_y = r;
	squire_rectangle = 4 * r * r;

	int number_points;
	printf("\nEnter number of points: ");
	scanf_s("%i", &number_points);
	top point;

	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	for (int l = 0; l < number_points; l++) {
		point.x = rand() * 1.0 / (RAND_MAX) * (max_x - min_x) + min_x;
		point.y = rand() * 1.0 / (RAND_MAX) * (max_y - min_y) + min_y;
		COLORREF color;
		if (pow(point.x, 2 * 1.0 / 3) + pow(point.y, 2 * 1.0 / 3) <= pow(r, 2 * 1.0 / 3)) {
			number_inner_points++;
			color = RGB(255, 0, 0);
		}
		else if (pow(-point.x, 2 * 1.0 / 3) + pow(-point.y, 2 * 1.0 / 3) <= pow(r, 2 * 1.0 / 3)) {
			number_inner_points++;
			color = RGB(255, 0, 0);
		}
		else if (pow(-point.x, 2 * 1.0 / 3) + pow(point.y, 2 * 1.0 / 3) <= pow(r, 2 * 1.0 / 3)) {
			number_inner_points++;
			color = RGB(255, 0, 0);
		}
		else if (pow(point.x, 2 * 1.0 / 3) + pow(-point.y, 2 * 1.0 / 3) <= pow(r, 2 * 1.0 / 3)) {
			number_inner_points++;
			color = RGB(255, 0, 0);
		}
		else {
			color = RGB(0, 255, 0);
		}
		SetPixel(hDC, point.x * 5 + 500, 100 + (100 - point.y) * 5, color);
	}
	srand(time(NULL));
	double squire;
	squire = squire_rectangle * 1.0 * number_inner_points / number_points;
	printf("\nSquire of poligon:\t%g", squire);
}
void square_random() {
	int number_tops, number_points;

	srand(time(0));
	printf("Enter number of tops: ");
	scanf_s("%i", &number_tops);
	top* array_tops = new top[number_tops];
	for (int i = 0; i < number_tops - 1; i++) {
		array_tops[i].x = rand() % 100 + 1;
		array_tops[i].y = rand() % 100;

		array_tops[i].tg = array_tops[i].y / array_tops[i].x * 1.0;
	}
	for (int i = 0; i < number_tops - 2; i++) {
		for (int j = 0; j < number_tops - i - 2; j++) {
			if (array_tops[j + 1].tg > array_tops[j].tg) {
				std::swap(array_tops[j + 1], array_tops[j]);
			}
			if (array_tops[j + 1].tg == array_tops[j].tg && array_tops[j + 1].x > array_tops[j].x) {
				std::swap(array_tops[j + 1], array_tops[j]);
			}
		}
	}
	array_tops[number_tops - 1].x = 0;
	array_tops[number_tops - 1].y = 0;


	printf("\nTops of polygon:\n");
	for (int i = 0; i < number_tops; i++) {
		printf("%i %f %f\n", i + 1, array_tops[i].x, array_tops[i].y);
	}

	printf("\nEnter number of points: ");
	scanf_s("%i", &number_points);
	double min_x, max_x, min_y, max_y, k, b, squire_rectangle;
	int number_crossings = 0, number_inner_points = 0;
	bool is_inner_point = false;

	min_x = array_tops[0].x;
	max_x = array_tops[0].x;
	min_y = array_tops[0].y;
	max_y = array_tops[0].y;

	//НАХОДИМ КРАЙНИЕ ТОЧКИ ДЛЯ "ОГРАНИЧИВАЮЩЕГО" ПРЯМОУГОЛЬНИКА
	for (int i = 0; i < number_tops; i++) {
		if (array_tops[i].x > max_x) max_x = array_tops[i].x;
		if (array_tops[i].x < min_x) min_x = array_tops[i].x;
		if (array_tops[i].y > max_y) max_y = array_tops[i].y;
		if (array_tops[i].y < min_y) min_y = array_tops[i].y;
	}

	squire_rectangle = 1.0 * (max_x - min_x) * (max_y - min_y);

	top point;
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	for (int l = 0; l < number_points; l++) {
		point.x = rand() * 1.0 / (RAND_MAX) * (max_x - min_x) + min_x;
		point.y = rand() * 1.0 / (RAND_MAX) * (max_y - min_y) + min_y;
		for (int i = 0; i < number_tops; i++) {
			if (i != number_tops - 1) {
				k = 1.0 * (array_tops[i].y - array_tops[i + 1].y) / (array_tops[i].x - array_tops[i + 1].x);
				b = array_tops[i].y - 1.0 * k * array_tops[i].x;

				if (k > 0 && k != INFINITY && point.y >= (1.0 * k * point.x + b) && ((point.y >= array_tops[i].y && point.y <= array_tops[i + 1].y) || (point.y <= array_tops[i].y && point.y >= array_tops[i + 1].y))) {
					number_crossings++;
				}
				if (k < 0 && k != -INFINITY && point.y <= (1.0 * k * point.x + b) && ((point.y >= array_tops[i].y && point.y <= array_tops[i + 1].y) || (point.y <= array_tops[i].y && point.y >= array_tops[i + 1].y))) {
					number_crossings++;
				}
				if ((k == INFINITY || k == -INFINITY) && point.x <= array_tops[i].x && ((point.y >= array_tops[i].y && point.y <= array_tops[i + 1].y) || (point.y <= array_tops[i].y && point.y >= array_tops[i + 1].y))) {
					number_crossings++;
				}
			}
			else {
				k = 1.0 * (array_tops[i].y - array_tops[0].y) / (array_tops[i].x - array_tops[0].x);
				b = array_tops[i].y - 1.0 * k * array_tops[i].x;

				if (k > 0 && k != INFINITY && point.y >= (1.0 * k * point.x + b) && ((point.y >= array_tops[i].y && point.y <= array_tops[0].y) || (point.y <= array_tops[i].y && point.y >= array_tops[0].y))) {
					number_crossings++;
				}
				if (k < 0 && k != -INFINITY && point.y <= (1.0 * k * point.x + b) && ((point.y >= array_tops[i].y && point.y <= array_tops[0].y) || (point.y <= array_tops[i].y && point.y >= array_tops[0].y))) {
					number_crossings++;
				}
				if ((k == INFINITY || k == -INFINITY) && point.x <= array_tops[i].x && ((point.y >= array_tops[i].y && point.y <= array_tops[0].y) || (point.y <= array_tops[i].y && point.y >= array_tops[0].y))) {
					number_crossings++;
				}
			}
		}
		COLORREF color;
		if (number_crossings % 2 != 0) is_inner_point = true;
		if (is_inner_point) {
			number_inner_points++;
			color = RGB(255, 0, 0);


		}
		else {
			color = RGB(0, 255, 0);
		}
		SetPixel(hDC, point.x * 5 + 500, 100 + (100 - point.y) * 5, color);
		is_inner_point = false;
		number_crossings = 0;
	}

	HPEN cP = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	POINT p;
	SelectObject(hDC, cP);
	for (int i = 0; i < number_tops - 1; i++) {
		MoveToEx(hDC, array_tops[i].x * 5 + 500, 100 + (100 - array_tops[i].y) * 5, &p);
		LineTo(hDC, array_tops[i + 1].x * 5 + 500, 100 + (100 - array_tops[i + 1].y) * 5);
	}
	MoveToEx(hDC, array_tops[0].x * 5 + 500, 100 + (100 - array_tops[0].y) * 5, &p);
	LineTo(hDC, array_tops[number_tops - 1].x * 5 + 500, 100 + (100 - array_tops[number_tops - 1].y) * 5);
	printf("Number of inner points: %i\n", number_inner_points);
	printf("Squire of rectangle: %f\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", squire_rectangle);
	srand(time(NULL));
	double squire;
	squire = squire_rectangle * 1.0 * number_inner_points / number_points;
	printf("\nSquire of poligon:\t%g", squire);
	srand(time(NULL));
}
void func_MonteKarlo() {

	int number_tops, number_points;
	printf("Enter number of tops: ");
	scanf_s("%i", &number_tops);
	printf("Enter tops of polygon:\n");
	top* array_tops = new top[number_tops];
	for (int i = 0; i < number_tops; i++) {
		printf("%i top:\t", i + 1);
		scanf_s("%lf", &(array_tops[i].x));
		scanf_s("%lf", &(array_tops[i].y));
	}
	printf("\nTops of polygon:\n");
	for (int i = 0; i < number_tops; i++) {
		printf("%i %f %f\n", i + 1, array_tops[i].x, array_tops[i].y);
	}

	printf("\nEnter number of points: ");
	scanf_s("%i", &number_points);
	double min_x, max_x, min_y, max_y, k, b, squire_rectangle;
	int number_crossings = 0, number_inner_points = 0;
	bool is_inner_point = false;

	min_x = array_tops[0].x;
	max_x = array_tops[0].x;
	min_y = array_tops[0].y;
	max_y = array_tops[0].y;
	for (int i = 0; i < number_tops; i++) {
		if (array_tops[i].x > max_x) max_x = array_tops[i].x;
		if (array_tops[i].x < min_x) min_x = array_tops[i].x;
		if (array_tops[i].y > max_y) max_y = array_tops[i].y;
		if (array_tops[i].y < min_y) min_y = array_tops[i].y;
	}

	squire_rectangle = 1.0 * (max_x - min_x) * (max_y - min_y);

	top point;
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	for (int l = 0; l < number_points; l++) {
		point.x = rand() * 1.0 / (RAND_MAX) * (max_x - min_x) + min_x;
		point.y = rand() * 1.0 / (RAND_MAX) * (max_y - min_y) + min_y;

		for (int i = 0; i < number_tops; i++) {
			if (i != number_tops - 1) {

				k = 1.0 * (array_tops[i].y - array_tops[i + 1].y) / (array_tops[i].x - array_tops[i + 1].x);
				b = array_tops[i].y - 1.0 * k * array_tops[i].x;

				if (k > 0 && k != INFINITY && point.y >= (1.0 * k * point.x + b) && ((point.y >= array_tops[i].y && point.y <= array_tops[i + 1].y) || (point.y <= array_tops[i].y && point.y >= array_tops[i + 1].y))) {
					number_crossings++;
				}
				if (k < 0 && k != -INFINITY && point.y <= (1.0 * k * point.x + b) && ((point.y >= array_tops[i].y && point.y <= array_tops[i + 1].y) || (point.y <= array_tops[i].y && point.y >= array_tops[i + 1].y))) {
					number_crossings++;
				}
				if ((k == INFINITY || k == -INFINITY) && point.x <= array_tops[i].x && ((point.y >= array_tops[i].y && point.y <= array_tops[i + 1].y) || (point.y <= array_tops[i].y && point.y >= array_tops[i + 1].y))) {
					number_crossings++;
				}
			}
			else {
				k = 1.0 * (array_tops[i].y - array_tops[0].y) / (array_tops[i].x - array_tops[0].x);
				b = array_tops[i].y - 1.0 * k * array_tops[i].x;

				if (k > 0 && k != INFINITY && point.y >= (1.0 * k * point.x + b) && ((point.y >= array_tops[i].y && point.y <= array_tops[0].y) || (point.y <= array_tops[i].y && point.y >= array_tops[0].y))) {
					number_crossings++;
				}
				if (k < 0 && k != -INFINITY && point.y <= (1.0 * k * point.x + b) && ((point.y >= array_tops[i].y && point.y <= array_tops[0].y) || (point.y <= array_tops[i].y && point.y >= array_tops[0].y))) {
					number_crossings++;
				}
				if ((k == INFINITY || k == -INFINITY) && point.x <= array_tops[i].x && ((point.y >= array_tops[i].y && point.y <= array_tops[0].y) || (point.y <= array_tops[i].y && point.y >= array_tops[0].y))) {
					number_crossings++;
				}
			}
		}
		COLORREF color;
		if (number_crossings % 2 != 0) is_inner_point = true;
		if (is_inner_point) {
			number_inner_points++;
			color = RGB(255, 0, 0);

		}
		else {
			color = RGB(0, 255, 0);
		}
		SetPixel(hDC, point.x * 5 + 500, 100 + (100 - point.y) * 5, color);
		is_inner_point = false;
		number_crossings = 0;
	}
	HPEN cP = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	POINT p;
	SelectObject(hDC, cP);
	for (int i = 0; i < number_tops - 1; i++) {
		MoveToEx(hDC, array_tops[i].x * 5 + 500, 100 + (100 - array_tops[i].y) * 5, &p);
		LineTo(hDC, array_tops[i + 1].x * 5 + 500, 100 + (100 - array_tops[i + 1].y) * 5);
	}
	MoveToEx(hDC, array_tops[0].x * 5 + 500, 100 + (100 - array_tops[0].y) * 5, &p);
	LineTo(hDC, array_tops[number_tops - 1].x * 5 + 500, 100 + (100 - array_tops[number_tops - 1].y) * 5);
	printf("Number of inner points: %i\n", number_inner_points);
	printf("Squire of rectangle: %f\n\n\n\n\n\n\n\n", squire_rectangle);
	srand(time(NULL));
	double squire;
	squire = squire_rectangle * 1.0 * number_inner_points / number_points;
	printf("\nSquire of poligon:\t%g", squire);
	srand(time(NULL));

}
void analit_math() {
	printf("S kakoi figuri hotite naiti?\n");
	printf("krug-1\n");
	printf("kolco-2\n");
	printf("lemniskata-3\n");
	printf("astroida-4\n");
	int p;
	scanf_s("%i", &p);
	switch (p) {
	case 1:
		krug();
		break;
	case 2:
		kolco();
		break;
	case 3:
		lemniskata();
		break;
	case 4:
		astroida();
	}
}
