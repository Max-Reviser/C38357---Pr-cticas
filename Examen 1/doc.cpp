#include <iostream>
#include <cctype>

using namespace std;

class Documento {
    

    public:
    char* text;
    long textSiz;
        Documento(char* v, long size){
            text = v;
            textSiz = size;
        }

        ~Documento(){
            delete[] text;
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
                    cout << *currPos << d->text + d->textSiz << endl;
                    // cout << "h\n";
                    
                    while (currPos < (d->text + d->textSiz) && isalnum(char(tolower(*currPos)))){
                        
                        // cout << "i\n";
                        currPos++;
                    }

                    while (currPos < (d->text + d->textSiz) && !isalnum(char(tolower(*currPos)))){
                        // cout << "j\n";
                        currPos++;
                    }

                    return *this;
                }

                char* operator*(){
                    cout << "e\n";
                    char* temp = currPos;
                    int leng = 0;
                    while ((temp < d->text + d->textSiz && isalnum(char(tolower(*currPos))))){
                        cout << "h\n";
                        leng++;
                        temp++;

                        /*
                        if ((char(tolower(*temp)) >= 'a' && char(tolower(*temp)) <= 'z') || (*temp >= '0' && *temp <= '9')){
                            cout << "g\n";
                            reqWord[count] = char(tolower(*temp));
                            cout << reqWord[count] << " " << count << endl;
                            count++;
                            
                        } else {
                            reqWord[count] = '\0';
                        }
                        */
                    }

                    char* reqWord = new char[leng + 1]; 
                    temp = currPos;
                    int count = 0;
                    while (count < leng){
                        cout << "g\n";
                        cout << char(tolower(*temp)) << "\n";
                        reqWord[count] = char(tolower(*temp));
                        cout << reqWord[count] << " " << count << endl;
                        count++;
                        temp++;
                    }

                    reqWord[leng] = '\0';
                    return reqWord;
                }

                bool operator!=(const Iterator& i){
                    cout << "d\n";
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

int main(){
    Documento* doc = new Documento((char*) "!Mira eso! !Es Coraje!  Ese es un perro cobarde muy divertido... !Ahhhh!...! !A mi no me gusta ! A mi me gusta Mafalda :) A mi me da igual porque no me agradan las caricaturas", 171);
    cout << doc->text << endl << doc->textSiz << endl;
    for (Documento::Iterator it = doc->begin(); it != doc->end(); ++it){
        char* word = *it;
        cout << word << " a\n";
        delete[] word;
    }

    delete doc;
    return 0;
}