// Copyright 2022 Zncl2222
#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

template <class T>
void array_swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void Selection_Sort(T data[], int len) {
    int min_index;
    for (int i = 0; i < len - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < len; j++) {
            if (data[j] < data[min_index]) {
                min_index = j;
            }
        }
        array_swap(data[i], data[min_index]);
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
void Selection_Sort_STL(vector<T>& array) {  // NOLINT
    int min_index;
    for (int i = 0; i < array.size() - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        array_swap(array[i], array[min_index]);
    }
}

template <class T>
void Print_Array(const vector<T> array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[10] = {1, 5, 6, 7, 8, 5, 5, 2, 1, 4};
    vector<int> array_v{9, 2, 3, 6, 8, 5, 5, 1, 2, 4, 9};
    vector<float> array_v2{1.2, 52.1, 664.33, -556.1, 5, 4, 4.5};
    cout << "Before" << endl;
    Print_Array(array, 10);
    Selection_Sort(array, 10);
    cout << "After" << endl;
    Print_Array(array, 10);

    cout << "Before" << endl;
    Print_Array(array_v);
    Selection_Sort_STL(array_v);
    cout << "After" << endl;
    Print_Array(array_v);
}
