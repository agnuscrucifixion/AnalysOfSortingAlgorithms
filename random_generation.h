#include <vector>
#include <chrono>
#include <ctime>
#include <cstdlib>


 void sorting(std::vector<int>& v) {    // сортировка, которая помогает в генерации
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v.size() - 1; ++j) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}
// ниже представлены генераторы

std::vector<int> randomGenerator05(std::vector<int>& v, int size) {
    for (int i = 0; i < size; ++i) {
        v.push_back(std::rand() % 6);
    }
    return v;
}
std::vector<int> randomGenerator04000(std::vector<int>& v, int size) {
    for (int i = 0; i < size; ++i) {
        v.push_back(std::rand() % 4001);
    }
    return v;
}
std::vector<int> randomGeneratorHalfSort(std::vector<int>& v, int size) {
    int pos = static_cast<int>(size / 2);
    std::vector<int> newV;
    for (int i = 0; i < size; ++i) {
        v.push_back(std::rand() % 4001);
    }
    for (int i = 0; i < pos; ++i) {
        newV.push_back(v[i]);
    }
    sorting(newV);
    for (int i = 0; i < pos; ++i) {
        v[i] = newV[i];
    }
    return v;
}
std::vector<int> randomGenerationReverse(std::vector<int>& v, int size) {
    for (int i = 0; i < size; ++i) {
        v.push_back( std::rand() % 4001);
    }
    sorting(v);
    std::vector<int> newV;
    for (int i = static_cast<int>(size - 1); i >= 0; --i) {
        newV.push_back(v[i]);
    }
    return newV;
}

