#define _CRT_SECURE_NO_WARNINGS
#define MIN_INCOME 400000
#define MAX_INCOME 600000
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

void full_array(int* ptr_array);
double income_calculation(int* ptr_array, int store_num);

int main(void) {

	setlocale(LC_CTYPE, "RUS");

	int array[10][12];
	int store_num;

	full_array((int*)array);

	do {
		printf("Выберите магазин (0 - завершить программу): ");
		scanf("%d", &store_num);
		printf("\n");

		if (store_num == 0) return 0;
		else if (store_num > 10 || store_num < 0) printf("Такого магазина нет\n\n");
		else printf("Среднемесячный доход %d магазина: %.2f\n\n", store_num, income_calculation((int*)array, store_num));
	} 
	while (store_num != 0);

	return 0;
}

void full_array(int* ptr_array) {

	int stime;
	long ltime;

	ltime = time(NULL);
	stime = (unsigned)ltime / 2;
	srand(stime);

	for (int r = 0; r < 10; r++) {

		for (int c = 0; c < 12; c++) {

			*(ptr_array + r * 12 + c) = MIN_INCOME + (long long)(MAX_INCOME - MIN_INCOME)  * rand() / RAND_MAX;
		}
	}
}

double income_calculation(int* ptr_array, int store_num) {

	double average = 0;

	for (int c = 0; c < 12; c++) {
		average += *(ptr_array + (store_num - 1) * 12 + c);
	}

	return average / 12;
}