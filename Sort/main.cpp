#include <iostream>
#include "string.h"


using  namespace std;

class Sort{
public:
    virtual void nameSort(string name) = 0;
    virtual void sort(int *arr, int n) = 0;
    virtual string howNameSort() = 0;
};

class Quick : public Sort {
private:
    string name;
public:

    void nameSort(string name) override {
        this->name = name;
    }

    void sort(int *arr, int n) override {

    }

    string howNameSort(){
        return name;
    }
};

class Bubble : public Sort {
private:
    string name;
public:

    void nameSort(string name) override {
        this->name = name;
    }

    void sort(int *arr, int n) override {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (arr[j] > arr[j + 1])
                    std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    string howNameSort(){
        return name;
    }
};

class Shell : public Sort {
private:
    string name;
public:

    void nameSort(string name) override {
        this->name = name;
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

    string howNameSort(){
        return name;
    }
};

void printSortedArray(Sort &sort, int *arr, int n){
    int *res = new int[n];
    memcpy(res, arr, n * sizeof(int));
    cout << "Using " << sort.howNameSort() << " sort :" << endl;
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
    shellSort.nameSort("Shell");
    bubbleSort.nameSort("Bubble");
    quickSort.nameSort("Quick");

    printSortedArray(shellSort, userArray, n);
    printSortedArray(bubbleSort, userArray, n);
    printSortedArray(quickSort, userArray, n);
    return 0;
}