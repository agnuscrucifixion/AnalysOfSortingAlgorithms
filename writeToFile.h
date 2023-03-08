#include <iostream>
#include <fstream>
#include <vector>



class WriteToFile { // класс-помощник для того, чтобы юыло удобнее записывать и так далее
public:
    static void clear() { //функция которая создаёт(пересоздаёт) и закрывает текстовые файлы и таблицу
        std::ofstream out("../txtSorts/bubbleSort.txt");
        out.close();
        out.open("../txtSorts/selectionSort.txt");
        out.close();
        out.open("../txtSorts/countingSort.txt");
        out.close();
        out.open("../txtSorts/heapSort.txt");
        out.close();
        out.open("../txtSorts/insertionSort.txt");
        out.close();
        out.open("../txtSorts/mergeSort.txt");
        out.close();
        out.open("../txtSorts/quickSort.txt");
        out.close();
        out.open("../txtSorts/radixSort.txt");
        out.close();
        out.open("../txtSorts/shellSort.txt");
        out.close();
        out.open("../csvTables/table.csv");
        out.close();


    }


    static void outVector(const std::string& path, const std::string& str, const std::vector<int>& v) { // функция для записи вектора в файл
        std::ofstream out(path, std::ios::app);
        out << str;
        for (int i = 0; i < v.size(); ++i) {
            out << v[i] << " ";
        }
        out << "\n";
        out.close();
    }


};