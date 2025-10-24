#ifndef CUENTAINACTIVAEXCEPTION_HPP
#define CUENTAINACTIVAEXCEPTION_HPP

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class CuentaInactivaException : public exception {
    string mess;

    public:
        CuentaInactivaException(string m){
            mess = m;
        }

        const char* what() const noexcept override {
            return mess.c_str();
        }
};

#endif