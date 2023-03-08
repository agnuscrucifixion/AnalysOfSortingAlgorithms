#include <vector>
#include <iostream>
#include <functional>
#include <fstream>
#include "writeToFile.h"

    WriteToFile::clear();
    std::ofstream table("../csvTables/table.csv");
    table << "Type;Sort;Size;Time(ns)" << "\n";
    table.close();
}
void print(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
}
void copyFirst(std::vector<int>& v, std::vector<int>& newV) {
    for (int i = 0; i < v.size(); ++i) {
        newV.push_back(v[i]);
    }
}                                                                                  // функции копирований
void copy(std::vector<int>& v, std::vector<int>& newV) {
    for (int i = 0; i < v.size(); ++i) {
        newV[i] = v[i];
    }
}
 int64_t allSort(std::vector<int>& v, const std::function<int64_t(std::vector<int>&)>& algo) {
    std::vector<int> newV;
     copyFirst(v, newV);
     int64_t hm = 0;
     int64_t t;
     for (int i = 0; i < 10; ++i) {
         t = algo(newV);                                                                        //функция тестирования 10 раз
         hm += t;
         newV.clear();
         copyFirst(v, newV);
     }
     t = algo(v);
     hm -= t;
     int64_t average = hm / 10;
     return average;
}
std::string message(int k) {              // функция для написания определ  нного типа массива в результаты
    std::string str;
    if (k == 0) {
        str = "basic mass";
    }
    if (k == 1) {
        str = "large mass";
    }
    if (k == 2) {
        str = "half sort mass";
    }
    if (k == 3) {
        str = "reverse mass";
    }
    return str;
}
void start(std::vector<int>& v, std::vector<int>& newV, int size, const std::function<std::vector<int>(std::vector<int>&, int)>& generator, int k) { // функция где происходит тестировка и запись в таблицу
    std::string path = "../txtSorts/bubbleSort.txt";
    int64_t t;
    std::string str = "Mass before bubble sort: \n";
    std::ofstream table("../csvTables/table.csv", std::ios::app);
    v.clear();
    newV.clear();
    v = generator(v, size);
    copyFirst(v, newV);
    WriteToFile::outVector(path, str, newV);
    t = allSort(newV, bubbleSort);
    str = "Mass after bubble sort: \n";
    WriteToFile::outVector(path, str, newV);
    table << message(k) << ";" << "bubble sort" << ";" << v.size() << ";" << t << "\n";
    copy(v, newV);
    str = "Mass before bubble sort(Ayverson1): \n";
    WriteToFile::outVector(path, str, newV);
    t = allSort(newV, bubbleSortWithAiverson1);
    str = "Mass after bubble sort: \n";
    WriteToFile::outVector(path, str, newV);
    table << message(k) << ";" << "bubble(Ayverson1) sort" << ";" << v.size() << ";" << t << "\n";
    copy(v, newV);
    str = "Mass before bubble sort(Ayverson2): \n";
    WriteToFile::outVector(path, str, newV);
    t = allSort(newV, bubbleSortWithAiverson2);
    str = "Mass after bubble sort: \n";
    WriteToFile::outVector(path, str, newV);
    table << message(k) << ";" << "bubble(Ayverson2) sort" << ";" << v.size() << ";" << t << "\n";
    path = "../txtSorts/selectionSort.txt";
    copy(v, newV);
    str = "Mass before selection sort: \n";
    WriteToFile::outVector(path, str, newV);
    t = allSort(newV, selectSort);
    str = "Mass after selection sort: \n";
    WriteToFile::outVector(path, str, newV);
    table << message(k) << ";" << "selection sort" << ";" << v.size() << ";" << t << "\n";
    path = "../txtSorts/insertionSort.txt";
    copy(v, newV);
    str = "Mass before insertion sort: \n";
    WriteToFile::outVector(path, str, newV);
    t = allSort(newV, insertionSort);
    str = "Mass after insertion sort: \n";
    WriteToFile::outVector(path, str, newV);
    table << message(k) << ";" << "insertion sort" << ";" << v.size() << ";" << t << "\n";
    copy(v, newV);
    str = "Mass before binary insertion sort: \n";
    WriteToFile::outVector(path, str, newV);
    t = allSort(newV, binaryInsertionSort);
    str = "Mass after binary insertion sort: \n";
    WriteToFile::outVector(path, str, newV);
    table << message(k) << ";" << "binary insertion sort" << ";" << v.size() << ";" << t << "\n";
    path = "../txtSorts/countingSort.txt";
    copy(v, newV);
    str = "Mass before counting sort: \n";
    WriteToFile::outVector(path, str, newV);
    t = allSort(newV, countingSort);
    str = "Mass after counting sort: \n";
    WriteToFile::outVector(path, str, newV);
    table << message(k) << ";" << "counting sort" << ";" << v.size() << ";" << t << "\n";
    path = "../txtSorts/radixSort.txt";
    copy(v, newV);
    str = "Mass before radix sort: \n";
    WriteToFile::outVector(path, str, newV);
    t = allSort(newV, radix);
    str = "Mass after radix sort: \n";
    WriteToFile::outVector(path, str, newV);
    table << message(k) << ";" << "radix sort" << ";" << v.size() << ";" << t << "\n";
    path = "../txtSorts/quickSort.txt";
    copy(v, newV);
    str = "Mass before quick sort: \n";
    WriteToFile::outVector(path, str, newV);
    t = allSort(newV, quicksort);
    str = "Mass after quick sort: \n";
    WriteToFile::outVector(path, str, newV);
    table << message(k) << ";" << "quick sort" << ";" << v.size() << ";" << t << "\n";
    path = "../txtSorts/mergeSort.txt";
    copy(v, newV);
    str = "Mass before merge sort: \n";
    WriteToFile::outVector(path, str, newV);
    t = allSort(newV, mergeSort);
    str = "Mass after merge sort: \n";
    WriteToFile::outVector(path, str, newV);
    table << message(k) << ";" << "merge sort" << ";" << v.size() << ";" << t << "\n";
    path = "../txtSorts/heapSort.txt";
    copy(v, newV);
    str = "Mass before heap sort: \n";
    WriteToFile::outVector(path, str, newV);
    t = allSort(newV, heapSort);
    str = "Mass after heap sort: \n";
    WriteToFile::outVector(path, str, newV);
    table << message(k) << ";" << "heap sort" << ";" << v.size() << ";" << t << "\n";
    path = "../txtSorts/shellSort.txt";
    copy(v, newV);
    str = "Mass before shell(Ciur) sort: \n";
    WriteToFile::outVector(path, str, newV);
    t = allSort(newV, shellSortCiur);
    str = "Mass after shell(Ciur) sort: \n";
    WriteToFile::outVector(path, str, newV);
    table << message(k) << ";" << "shell(Ciur) sort" << ";" << v.size() << ";" << t << "\n";
    copy(v, newV);
    str = "Mass before shell sort: \n";
    WriteToFile::outVector(path, str, newV);
    t = allSort(newV, shellSort);
    str = "Mass after shell sort: \n";
    WriteToFile::outVector(path, str, newV);
    table << message(k) << ";" << "shell sort" << ";" << v.size() << ";" << t << "\n";
}
