#pragma once
#include <iostream>
using std::string;

class Conta {
private:
	double saldo;
	int senha;
public:
	int numero;
	string titular;

	Conta();
	Conta(int, string, double, int);

	double get_saldo();
	void set_saldo();
	int get_numero();
	string getTitular();
	float deposito(double);
	float saque(double);
	bool habilitaAcesso(int);
	void transferencia(Conta*,double);
};
