#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void Insertion_Sort(int data[], int len) {
    for (int i = 1; i < len; i++) {
        int tmp = data[i];
        int j = i - 1;

        while (tmp < data[j] && j >= 0) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = tmp;
    }
}

void Print_Array(int data[], int len) {
    for (int i = 0; i < len; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void Insertion_Sort_STL(vector<int>& array) {
    for (int i = 1; i < array.size(); i++) {
        int tmp = array[i];
        int j = i - 1;

        while (tmp < array[j] && j >= 0) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = tmp;
    }
}

void Print_Array_STL(vector<int> array) {
    for (auto itr = array.begin(); itr != array.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
}

int main() {
    int array[10] = {1, 5, 6, 7, 8, 5, 5, 2, 1, 4};
    vector<int> array_v{9, 2, 3, 6, 8, 5, 5, 1, 2, 4, 9};
    cout << "Before" << endl;
    Print_Array(array, 10);
    Insertion_Sort(array, 10);
    cout << "After" << endl;
    Print_Array(array, 10);

    cout << "Before(STL)" << endl;
    Print_Array_STL(array_v);
    Insertion_Sort_STL(array_v);
    cout << "After(STL)" << endl;
    Print_Array_STL(array_v);
}