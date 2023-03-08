#include <iostream>
#include <vector>
#include "random_generation.h"
#include "sorts.h"
#include "help.h"



int main() {
    help(); // функция для открытия таблицы и написания "столбцов"
    std::vector<std::function<std::vector<int>(std::vector<int>&, int)>> generators {randomGenerator05, randomGenerator04000,
                                                                                     randomGeneratorHalfSort,
                                                                                     randomGenerationReverse}; // вектор генераторов рандомных чисел
    std::srand(time(nullptr));
    std::vector<int> v;
    std::vector<int> newV;
    int k = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 50; j < 350; j += 50) {
            start(v, newV, j, generators[i], k);
        }
        k += 1;                                                                     // циклы, которые выполняют полную работу программы.
    }
    k = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 400; j < 4200; j+= 100) {
            start(v, newV, j, generators[i], k);
        }
        k += 1;
    }



}
