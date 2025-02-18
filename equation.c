#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

void print_arr(long double arr[], int length) {
    printf("[");
    if (length == 0) {
        printf("]");
        return;
    }
    printf("%Lf", arr[0]);
    for (int i = 1; i < length; i++) {
        printf(", %Lf", arr[i]);
    }
    printf("]");
}

int find_x(long double x[2]) {
    long double a, b, c;
    printf("Введи коэффициенты:\n");
    printf("а: ");
    scanf_s("%Lf", &a);
    printf("b: ");
    scanf_s("%Lf", &b);
    printf("c: ");
    scanf_s("%Lf", &c);

    if (a == 0) {
        printf("нельзя посчитать корни уравнения");
        exit(0);
    }

    long double d = b * b - 4 * a * c;

    if (d > 0) {
        x[0] = (-b - sqrt(d)) / (2 * a);
        x[1] = (-b + sqrt(d)) / (2 * a);
        return 2;


    }
    else if (d == 0) {
        x[0] = -b / (2 * a);
        return 1;
    }
    else {
        return 0;
    }
}

int main() {

    char* locale = setlocale(LC_ALL, "");

    long double x[2];

    int len = find_x(x);

    printf("Корни уранения: ");
    print_arr(x, len);

    return 0;
}
