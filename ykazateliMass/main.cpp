#include <iostream>

using namespace std;

int main() {
    int *array, n;
    cout << "Vvedite razmernoct massava.";
    cin >> n;
    array = new int[n];
    int num;
    for (int i = 0; i < n; i++) {
        cout << "Vvedite znachenie echeiki massava " << (i + 1) << ": ";
        cin >> array[i];
    }
    for (int i = 0; i < n;i++){
        cout << array[i] << " " ;
    }
    int sum = 0;
    for (int i = 0; i < n;i++){
        sum = sum + array[i];
    }
    cout << endl;
    cout << "Summa vseh elementov massiva ravna = " << sum;
    cout << endl;
    return 0;
}