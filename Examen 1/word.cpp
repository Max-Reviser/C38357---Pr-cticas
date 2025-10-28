#include <iostream>
#include <cctype>

using namespace std;

class Palabra {
    char* word; 
    int worAmou;

    public:
        Palabra(char* w){
            cout << "d\n";
            int leng = 0;
            while(w[leng] != '\0'){
                leng++;
            }

            word = new char[leng + 1];
            for (int i = 0; i < leng; i++){
                word[i] = w[i];
            }

            word[leng] = '\0';

            cout << endl;
            worAmou = 1;
        }

        ~Palabra(){
            delete[] word;
        }

        void addWord(){
            worAmou++;
        }

        char* getWord() const {
            return word;
        }

        int getWorAmou() const {
            return worAmou;
        }

        friend ostream& operator<<(ostream& os, const Palabra& p){
            //for (int i = 0;)
            os << p.word << " -> " << p.worAmou;
            return os << endl;
        }
};