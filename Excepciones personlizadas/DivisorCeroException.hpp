#ifndef DIVISORCEROEXCEPTION_HPP
#define DIVISORCEROEXCEPTION_HPP

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class DivisorCeroException : public exception {
    string mess;

    public:
        DivisorCeroException(string m){
            mess = m;
        }

        const char* what() const noexcept override {
            return mess.c_str();
        }
};

#endif