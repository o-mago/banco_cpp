#pragma once
#include <iostream>

class Conta {
	public:
		float saldo;
		char senha[20];
		char usuario[20];
		Conta();
		Conta(const char* usuario, const char* senha);
		float get_saldo();
		float deposito(float valor);
		float saque(float valor);
		char* get_usuario();
};
