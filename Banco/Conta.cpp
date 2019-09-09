#include "conta.h"
using std::cout;
using std::cin;

		char usuario[20];
		float saldo = 0;
		char senha[20];

		Conta::Conta() {
		}

		Conta::Conta(const char* usuario, const char* senha) {
			strcpy_s(Conta::usuario, usuario);
			strcpy_s(Conta::senha, senha);
			cout << "Conta::Conta: " << Conta::usuario;
			cout << "Conta::Conta: " << Conta::senha;
			saldo = 0;
		}
		
		float Conta::get_saldo() {
			return saldo;
		}

		float Conta::deposito(float valor) {
			return saldo += valor;
		}

		float Conta::saque(float valor) {
			return saldo -= valor;
		}

		char* Conta::get_usuario() {
			return usuario;
		}