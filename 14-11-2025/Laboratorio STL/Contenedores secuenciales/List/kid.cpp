#include <iostream>

using namespace std;

class Niño {
    string name, sex;
    int age;
    bool isNice;

    public:
        Niño(string name, int age, string sex, string behav){
            this->name = name;
            this->age = age;
            this->sex = sex;
            if (behav == "Good"){
                isNice = true;
            } else if (behav == "Bad"){
                isNice = false;
            }
        }
}