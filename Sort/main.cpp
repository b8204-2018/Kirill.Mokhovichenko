#include <iostream>

using  namespace std;

class Sort{
private:

public:
    virtual void sort(int *arr, int n) = 0; //В родительском нет реализации.
    virtual void printArrSort(int *arr, int n) = 0;
};

class Quick : public Sort {
public:
    void sort(int *arr, int n) override {

    }

    void printArrSort(int *arr, int n) override {
        sort(arr, n);
        cout << "Quick sort : " << endl;
        for(size_t i = 0; i < n; i++)
            cout << " " << arr[i] << " ";
        cout << endl;
    }
};

class Bubble : public Sort {
public:
    void sort(int *arr, int n) override {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (arr[j] > arr[j + 1])
                    std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    void printArrSort(int *arr, int n) override {
        sort(arr, n);
        cout << "Bubble sort : " << endl;
        for(size_t i = 0; i < n; i++)
            cout << " " << arr[i] << " ";
        cout << endl;
    }
};

class Shell : public Sort {
public:
    void sort(int *arr, int n) override {
        int i, j, step;
        int tmp;
        for (step = n / 2; step > 0; step /= 2)
            for (i = step; i < n; i++)
            {
                tmp = arr[i];
                for (j = i; j >= step; j -= step)
                {
                    if (tmp < arr[j - step])
                        arr[j] = arr[j - step];
                    else
                        break;
                }
                arr[j] = tmp;
            }
    }

    void printArrSort(int *arr, int n) override {
        sort(arr, n);
        cout << "Shell sort : " << endl;
        for(size_t i = 0; i < n; i++)
            cout << " " << arr[i] << " ";
        cout << endl;
    }
};

void fillArr(int *arr, int *arrFirst, int n){
    for(size_t i = 0; i < n; i++){
        arr[i] = arrFirst[i];
    }
}


int main() {
    Shell shellSort;
    Bubble bubbleSort;
    Quick quickSort;
    int n;
    cout << "Vvedite razmernost' massiva : " << endl;
    cin >> n;
    int *shellArr = new int[n];
    int *bubbleArr = new int[n];
    int *quickArr = new int[n];
    cout << "Nachalnii massiv : " << endl;
    for(size_t i = 0; i < n; i++){
        shellArr[i] = rand() % 100;
        cout << shellArr[i] << " ";
    }
    cout << endl;
    fillArr(bubbleArr, shellArr, n);
    fillArr(quickArr, shellArr, n);
    shellSort.printArrSort(shellArr, n);
    bubbleSort.printArrSort(bubbleArr, n);
    quickSort.printArrSort(quickArr, n);

    return 0;
}