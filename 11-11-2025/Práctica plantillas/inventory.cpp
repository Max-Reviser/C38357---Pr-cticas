#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

template <typename T>

class Inventario {
    vector<T> objs;
    int maxCapa;
    
    public:
        Inventario(int maxCapa){
            this.maxCapa = maxCapa;
        }

        void agregar(const T& item){
            if (objs.size() < maxCapa){
                objs.push_back(item);
            } else {
                cout << "El inventario está lleno.\n";
            }
        }

        void mostrar() const {
            if (objs.size() == 0){
                cout << "La lista está vacía.\n";
                return;
            }

            cout << "[ ";
            for (int i = 0; i < objs.size(); i++){
                cout << objs.at(i) << " ";
            }
            cout << " ]\n";
        }

        template <>
        void mostrar<string>() const {
            if (objs.size() == 0){
                cout << "La lista está vacía.\n";
                return;
            }

            cout << "[ ";
            for (int i = 0; i < objs.size(); i++){
                cout << "\"" << objs.at(i) << "\"";
            }
            cout << " ]\n";
        }

        bool buscar(const T& item) const {
            for (int i = 0; i < objs.size(); i++){
                if (objs.at(i) == item){
                    return true;
                }
            }

            return false;
        }

        template <>
        bool buscar<string>(const T& item) const {
            for (int i = 0; i < objs.size(); i++){
                if (tolower(objs.at(i)) == tolower(item)){
                    return true;
                }
            }

            return false;
        }
};