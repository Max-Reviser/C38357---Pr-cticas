#include <iostream>

using namespace std;

template <typename T, int N>

class Caja {
    T array[N];

    public:
        void mostrar(){
            for (int i = 0; i < N; i++){
                cout << i << "° elemento: " << array[i] << endl;
            }
        }

        T& operator[](int i){
            return array[i];
        }
};