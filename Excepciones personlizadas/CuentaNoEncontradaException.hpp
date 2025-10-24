#ifndef CUENTANOENCONTRADAEXCEPTION_HPP
#define CUENTANOENCONTRADAEXCEPTION_HPP

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class CuentaNoEncontradaException : public exception {
    string mess;

    public:
        CuentaNoEncontradaException(string m){
            mess = m;
        }

        const char* what() const noexcept override {
            return mess.c_str();
        }
};

#endif