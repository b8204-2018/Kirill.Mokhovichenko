#include <iostream>
#include "string.h"


using  namespace std;

class Sort{
private:

public:
    virtual string nameSort() = 0;
    virtual void sort(int *arr, int n) = 0; //В родительском нет реализации.
};

class Quick : public Sort {
public:

    string nameSort() override {
        cout << "Sort Quick : "  << endl;
    }

    void sort(int *arr, int n) override {

    }
};

class Bubble : public Sort {
public:

    string nameSort() override {
        cout << "Sort Bubble : "  << endl;
    }

    void sort(int *arr, int n) override {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (arr[j] > arr[j + 1])
                    std::swap(arr[j], arr[j + 1]);
            }
        }
    }
};

class Shell : public Sort {
public:

    string nameSort() override {
        cout << "Sort Shell : "  << endl;
    }

    void sort(int *arr, int n) override {
        int i, j, step;
        int tmp;
        for (step = n / 2; step > 0; step /= 2)
            for (i = step; i < n; i++) {
                tmp = arr[i];
                for (j = i; j >= step; j -= step) {
                    if (tmp < arr[j - step])
                        arr[j] = arr[j - step];
                    else
                        break;
                }
                arr[j] = tmp;
            }
    }
};

void printSortedArray(Sort &sort, int *arr, int n){
    int *res = new int[n];
    memcpy(res, arr, n * sizeof(int));
    sort.nameSort();
    sort.sort(res, n);
    for (int i = 0; i < n; i++)
        cout << " " << res[i];
    cout << endl;
}


int main() {
    Shell shellSort;
    Bubble bubbleSort;
    Quick quickSort;

    int n;
    cout << "Vvedite razmernost' massiva : " << endl;
    cin >> n;
    cout << "Nachalnii massiv : " << endl;
    int *userArray = new int[n];
    for(size_t i = 0; i < n; i++){
        userArray[i] = rand() % 100;
        cout << userArray[i] << " ";
    }

    cout << endl;

    printSortedArray(shellSort, userArray, n);
    printSortedArray(bubbleSort, userArray, n);
    printSortedArray(quickSort, userArray, n);
    return 0;
}