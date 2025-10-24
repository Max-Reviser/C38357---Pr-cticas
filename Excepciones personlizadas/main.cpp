#include <iostream>
#include "Excepciones.hpp"
using namespace std;

// Funciones que lanzan excepciones

void retirarDinero(double saldo, double monto) {
    if (monto > saldo)
        throw SaldoInsuficienteException("Saldo insuficiente para el retiro.");
    cout << "Retiro exitoso: " << saldo - monto << endl;
}

void buscarCuenta(bool existe) {
    if (!existe)
        throw CuentaNoEncontradaException("Cuenta no encontrada.");
    cout << "Cuenta encontrada." << endl;
}

void verificarCuentaActiva(bool activa) {
    if (!activa)
        throw CuentaInactivaException("La cuenta está inactiva.");
    cout << "Cuenta activa." << endl;
}

double calcularInteres(double saldo, double tasa, double divisor) {
    if (divisor == 0)
        throw DivisorCeroException("Error: División por cero al calcular interés.");
    return (saldo * tasa) / divisor;
}


int main() {
    double saldo = 500;
    double monto = 800;

    // Usted debe:
    // Rodear cada función con try-catch para que el programa no se caiga
    // Mostrar un mensaje apropiado si ocurre una excepción
    // Intentar continuar la ejecución después de cada error

    try {
        retirarDinero(saldo, monto);
    } catch(const SaldoInsuficienteException& s){
        cout << "Error: " << s.what() << endl;
    }

    try {
        buscarCuenta(false);
    } catch(const CuentaNoEncontradaException& c){
        cout << "Error: " << c.what() << endl;
    }

    try {
        verificarCuentaActiva(false);
    } catch(const CuentaInactivaException& c){
        cout << "Error: " << c.what() << endl;
    }

    try {
        double interes = calcularInteres(saldo, 0.05, 0);
        cout << "Interés calculado: " << interes << endl;
    } catch(const DivisorCeroException& d){
        cout << d.what() << endl;
    }
    
    cout << "Programa finalizado." << endl;
    return 0;
}
