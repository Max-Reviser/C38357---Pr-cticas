#include "templateClass.cpp"

int main(){
    Caja<int, 3> enteros;
    enteros[0] = 5;
    enteros[1] = 10;
    enteros[2] = 15;
    enteros.mostrar();
    cout << endl;
    Caja<string, 2> textos;
    textos[0] = "Hola";
    textos[1] = "UCR";
    textos.mostrar();
    return 0;
}