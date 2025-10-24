#ifndef SALDOINSUFICIENTEEXCEPTION_HPP
#define SALDOINSUFICIENTEEXCEPTION_HPP

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class SaldoInsuficienteException : public exception {
    string mess;

    public:
        SaldoInsuficienteException(string m){
            mess = m;
        }

        const char* what() const noexcept override {
            return mess.c_str();
        }
};

#endif