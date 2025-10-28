#include "word.cpp"

class Nodo {
    public:
        Palabra word;
        Nodo* next;
        Nodo(const Palabra& p) : word(p), next(nullptr){}
};