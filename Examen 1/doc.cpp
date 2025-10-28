#include <iostream>
#include <cctype>

using namespace std;

class Documento {
    char* text;
    long textSiz;

    public:
        Documento(char* v, long size){
            text = v;
            textSiz = size;
        }

        ~Documento(){
            delete[] text;
        }

        char* getText() const {
            return text;
        }

        long getTextSiz () const {
            return textSiz;
        }

        friend ostream& operator<<(ostream& os, const Documento d){
            for (int i = 0; i < d.textSiz; i++){
                os << d.text[i];
            }

            return os << endl;
        }

        class Iterator {
            char* currPos;
            Documento* d;

            public:
                Iterator (char* pos, Documento* d){
                    currPos = pos;
                    this->d = d;
                }

                Iterator& operator++(){
                    // cout << *currPos << " " << endl;
                    // cout << "i\n";
                    
                    while (currPos < (d->text + d->textSiz) && isalnum(char(tolower(*currPos)))){
                        // cout << "j\n";
                        currPos++;
                    }

                    while (currPos < (d->text + d->textSiz) && !isalnum(char(tolower(*currPos)))){
                        // cout << "k\n";
                        currPos++;
                    }

                    return *this;
                }

                char* operator*(){
                    // cout << "e\n";
                    int leng = 0, count = 0;
                    while (!isalnum(char(tolower(*currPos)))){
                        // cout << "f " << *currPos << endl << endl;
                        currPos++;
                    }

                    char* temp = currPos;
                    while ((temp < d->text + d->textSiz && isalnum(char(tolower(*temp))))){
                        // cout << "g " << *temp << endl << endl;
                        leng++;
                        temp++;
                    }

                    char* reqWord = new char[leng + 1]; 
                    temp = currPos;
                    while (count < leng){
                        // cout << "h " << char(tolower(*temp)) << endl;
                        reqWord[count] = char(tolower(*temp));
                        // cout << reqWord[count] << " " << count << endl << endl;
                        count++;
                        temp++;
                    }

                    reqWord[leng] = '\0';
                    // cout << reqWord << endl;
                    return reqWord;
                }

                bool operator!=(const Iterator& i){
                    // cout << "d\n";
                    return this->currPos != i.currPos;
                } 
        };

        Iterator begin(){
            cout << "b\n";
            return Iterator(text, this);
        }

        Iterator end(){
            cout << "c\n";
            return Iterator(text + textSiz, this);
        }
};
/*
int main(){
    Documento* doc = new Documento((char*) "!Mira eso! !Es Coraje!  Ese es un perro cobarde muy divertido... !Ahhhh!...! !A mi no me gusta ! A mi me gusta Mafalda :) A mi me da igual porque no me agradan las caricaturas", 175);
    cout << doc->getText() << endl << doc->getTextSiz() << endl;
    int count = 0;
    for (Documento::Iterator it = doc->begin(); it != doc->end(); ++it){
        char* word = *it;
        cout << word << " ";
        delete[] word;
        count++;
        // cout << count << endl << endl;
    }

    cout << "Fin del programa.\n";
    delete doc;
    return 0;
}
*/