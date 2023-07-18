// Copyright 2022 Zncl2222

#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

template <class T>
void Shell_Sort(T data[], int len) {
    for (int gap = len / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < len; i++) {
            T value = data[i];
            int j;
            for (j = i; j >= gap && data[j - gap] > value; j -= gap) {
                data[j] = data[j - gap];
            }
            data[j] = value;
        }
    }
}

template <class T>
void Print_Array(T data[], int len) {
    for (int i = 0; i < len; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <class T>
void Shell_Sort_STL(vector<T>& array) {  // NOLINT
    for (int gap = array.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < array.size(); i++) {
            T value = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > value; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = value;
        }
    }
}

template <class T>
void Print_Array_STL(vector<T> array) {
    for (auto itr = array.begin(); itr != array.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
}

int main() {
    int array[10] = {1, 5, 6, 7, 8, 5, 5, 2, 1, 4};
    vector<int> array_v{9, 2, 3, 6, 8, 5, 5, 1, 2, 4, 9};
    vector<float> array_v2{1.2, 52.1, 664.33, -556.1, 5, 4, 4.5};
    cout << "Before" << endl;
    Print_Array(array, 10);
    Shell_Sort(array, 10);
    cout << "After" << endl;
    Print_Array(array, 10);

    cout << "Before(STL)" << endl;
    Print_Array_STL(array_v);
    Shell_Sort_STL(array_v);
    cout << "After(STL)" << endl;
    Print_Array_STL(array_v);
}
