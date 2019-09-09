#include <iostream>
#include "conta.h"

class Funcionario:public Conta {
public:
	Funcionario();
	//Funcionario(const char* usuario, const char* senha);
	Conta nova_conta(char* usuario, char* senha);
};