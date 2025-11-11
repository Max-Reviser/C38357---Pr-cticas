#include "inventory.cpp"

int main(){
    int x;
    string name;
    Inventario<int, 5> inters;
    for (int i = 1; i < 5; i++){
        inters.agregar(i * 2);
    }

    Inventario<string, 3> names:
    names[0] = "carlos";
    names[1] = "Mariana";
    names[2] = "Alex";
    cout << "Lista de números:\n";
    inters.mostrar();
    cout << "\nLista de nombres:\n";
    names.mostrar();
    cout << "Ingrese un número a buscar: ";
    cin >> x;
    if (inters.buscar(x)){
        cout << "Se encontró el elemento " << x << endl;
    }

    cout << "Ingrese un nombre a buscar: ";
    cin >> name;
    if (names.buscar(name)){
        cout << "Se encontró el elemento " << name << endl;
    }

    return 0;
}