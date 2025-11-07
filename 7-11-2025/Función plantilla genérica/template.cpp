#include <iostream>

using namespace std;

template <typename T>

void exchange(T& a, T& b){
    T c = b;
    b = a;
    a = c;
}

int main(){
    int a = 10, b = 20;
    double c = 2.5, d = 5.3;
    string word1 = "Hola", word2 = "Mundo";
    cout << "A = " << a << " - B = " << b << endl;
    exchange(a, b);
    cout << "A = " << a << " - B = " << b << endl;
    cout << "------------------------------------\n";
    cout << "C = " << c << " - D = " << d << endl;
    exchange(c, d);
    cout << "C = " << c << " - D = " << d << endl;
    cout << "------------------------------------\n";
    cout << "Palabra #1: " << word1 << " - Palabra #2: " << word2 << endl;
    exchange(word1, word2);
    cout << "Palabra #1: " << word1 << " - Palabra #2: " << word2 << endl;
    return 0;
}