#include "node.cpp"
#include "doc.cpp"

class Vocabulario {
    Nodo* head;

    public:
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
            cout << p.getWord() << " e\n";
            Nodo* novo = new Nodo(p);
            if (!this->head){
                cout << "f\n";
                head = novo;
                cout << head->word.getWord();
                return;
            } 

            Nodo* currNod = this->head;
            cout << currNod->word.getWord() << endl;
            while (currNod->next){
                // cout << "g\n";
                currNod = currNod->next;
            }

            currNod->next = novo;
            cout << currNod->word.getWord() << endl;
            cout << currNod->next->word.getWord();
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
        // cout << vocab << endl;
        cout << " z\n";
    }

    cout << vocab << endl;
    cout << "Fin del programa.\n";
    delete doc;
    // delete vocab;
    return 0;
}