#include <iostream>
#include <vector>

using namespace std;

int main(){
    int summ = 0, currInt;
    double avera;
    vector<int> inters;
    for (int i = 0; i < 10; i++){
        cout << "Ingrese un valor entero: ";
        cin >> currInt;
        inters.push_back(currInt);
        summ += inters[i];
    }

    avera = summ / 10;
    cout << "\nMedia: " << avera << endl;
    return 0;
}

