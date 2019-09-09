#include <iostream>
#include "funcionario.h"
using std::cout;
using std::cin;

Funcionario::Funcionario() {
}

//Funcionario::Funcionario(const char* usuario, const char* senha) {
//	strcpy_s(Conta::usuario, usuario);
//	strcpy_s(Conta::senha, senha);
//}

	Conta Funcionario::nova_conta(char* usuario, char* senha) {
		return Conta::Conta(usuario, senha);
	}