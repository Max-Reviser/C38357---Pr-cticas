#include "node.cpp"
#include "doc.cpp"

class Vocabulario {
    

    public:
    Nodo* head;
        Vocabulario() : head(nullptr){}
        ~Vocabulario(){
            Nodo* currNod = head;
            while (currNod){
                Nodo* tempNod = currNod;
                currNod = currNod->next;
                delete tempNod;
            }
        }

        void addWord(const Palabra& p){
            cout << "e\n";
            Nodo* currNod = head;
            bool worExis = false;
            if (!currNod){
                cout << "f\n";
                Nodo* novo = new Nodo(p);
                this->head = novo;
                cout << head->word.getWord() << " h\n";
            } else {
                cout << "g\n";
                while (currNod){
                    cout << head->word.getWord() << " h\n";
                    bool isEqua = wordComparator(currNod, p.getWord());
                    if (isEqua){
                        cout << "l\n";
                        currNod->word.addWord();
                        worExis = true;
                        break;
                    } else {
                        cout << "m\n";
                        currNod = currNod->next;
                    }
                }
                
                if (!worExis){
                    cout << "n\n";
                    Nodo* novo = new Nodo(p);
                    addNode(novo);
                }
            }
        }

        int indexOf(char* seaWord){
            int index, i = 0;
            bool worExis = false;
            Nodo* currNod = head;
            if (!currNod){
                index = -1; // Indica que la lista está vacía.
            } else {
                while (currNod){
                    bool isEqua = wordComparator(currNod, seaWord);
                    if (isEqua){
                        index = i;
                        worExis = true;
                        break;
                    } else {
                        currNod = currNod->next;
                        i++;
                    }
                }

                if (!worExis){
                    index = -2; // Indica que la palabra no existe en la lista,
                }
            }

            return index;
        }

        bool wordComparator(Nodo* node, char* comWord){
            cout << "i\n";
            char* currWor = node->word.getWord();
            bool isEqua = false;
            int count = 0;
            while (currWor[count] == comWord[count]){
                cout << currWor[count] << " " << comWord[count] << " j\n";
                if (currWor[count] == '\0'){
                    cout << "k\n";
                    isEqua = true;
                    break;
                }

                count++;
            }

            return isEqua;
        }

        void addNode(Nodo* newNode){
            cout << "o\n";
            Nodo* currNod = head;
            Nodo* prevNod = nullptr;
            char *currWor, *compWor = newNode->word.getWord();
            int count, comWoLe = sizeof(compWor) / sizeof(compWor[0]), curWoLe;
            bool gotAdde = false;
            while (currNod || !gotAdde){
                cout << "p\n";
                currWor = currNod->word.getWord();
                curWoLe = sizeof(currWor) / sizeof(currWor[0]);
                count = 0;
                while (count < curWoLe || count < comWoLe){
                    cout << "q\n";
                    if (compWor[count] < currWor[count]){
                        cout << "r\n";
                        newNode->next = currNod;
                        // Se agrega el nodo antes del nodo "currNod".
                        if (!prevNod){
                            cout << "s\n";
                            head = newNode;
                        } else {
                            cout << "t\n";
                            prevNod->next = newNode;
                        }
                        // Debe verificar si "prevNod" es nulo.
                        // Si es nulo, "newNode" pasa a ser "head".
                        gotAdde = true;
                        break;
                    } else if (compWor[count] == currWor[count]){
                        cout << "u\n";
                        count++; // Pasa al siguiente caracter
                    } else {
                        cout << "v\n";
                        break;
                        // Se salta al siguiente nodo.
                    }  
                } 
                // Se sabe que '\0' posee como valor 0, por lo que siempre será menor a cualquier letra.

                if (currNod->next){
                    cout << "x\n";
                    prevNod = currNod;
                    currNod = currNod->next;
                } else if (!currNod->next){
                    cout << "y\n";
                    currNod->next = newNode;
                    gotAdde = true;
                } 
                // Debe verificar si el nodo siguiente es nulo.
                // Si es nulo, se inserta a "newNode" ahí.
            }
        } // Solo puede accederse si la lista posee elementos y si la palabra de "newNode" no se repite.

        friend ostream& operator<<(ostream& os, const Vocabulario& v){
            Nodo* currNod = v.head;
            int i = 0;
            while (currNod){
                os << i << " " << currNod->word;
                currNod = currNod->next;
                i++;
            }

            cout << "z\n";
            return os << endl;
        }
};

int main(){
    Documento* doc = new Documento((char*) "!Mira eso! !Es Coraje!  Ese es un perro cobarde muy divertido... !Ahhhh!...! !A mi no me gusta ! A mi me gusta Mafalda :) A mi me da igual porque no me agradan las caricaturas", 175);
    Vocabulario vocab;
    cout << doc->getText() << endl << doc->getTextSiz() << endl;
    for (Documento::Iterator it = doc->begin(); it != doc->end(); ++it){
        char* word = *it;
        // cout << *vocab << endl << "z\n";
        Palabra newWord(word);
        vocab.addWord(newWord);
        cout << vocab << endl;
        cout << "z\n";
    }

    cout << vocab << endl;
    cout << "Fin del programa.\n";
    delete doc;
    // delete vocab;
    return 0;
}