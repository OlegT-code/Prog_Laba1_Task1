#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <cmath>

using namespace std;

int main()
{
    int processArray(int* array, int length);
    setlocale(LC_CTYPE, "Russian");
    int countMin;

    const size_t N = 20;
    int array[N] = { 0 };

    srand(time(NULL)); // рандомно заполняем массив
    for (int i = 0; i < N; i++) { array[i] = rand() % 5 + 1; }

    printf("Вход: \n");
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    countMin = processArray(array, N);

    printf("Выход: \n");
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    printf("Наименьшее появление числа: %d \n", countMin);

    return 0;
}

int processArray(int* array, int length) {

    for (int i = 0; i < length - 1; i++) { // сортируем массив по возрастанию
        for (int j = i + 1; j < length; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    int frequencyIndex[5] = { 0 };
    int minNum = 20, minElem = 0;

    for (int i = 0; i < length; i++) { // создание массива частоты появления символов
        if (array[i] == 1) frequencyIndex[0] += 1;
        else if (array[i] == 2) frequencyIndex[1] += 1;
        else if (array[i] == 3) frequencyIndex[2] += 1;
        else if (array[i] == 4) frequencyIndex[3] += 1;
        else frequencyIndex[4] += 1;
    }

    for (int i = 0; i < size(frequencyIndex); i++) { // поиск минимального значения в массиве
        if (minNum > frequencyIndex[i]) {
            minNum = frequencyIndex[i];
            minElem = i + 1;
        }
    }
    
    return minElem;
}