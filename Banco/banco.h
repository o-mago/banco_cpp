#pragma once
#include "conta.h";

class Banco {
public:
	Banco(int, int);
	~Banco();
	void cadastraConta(Conta*);
	Conta* getConta(int);
	bool habilitaFuncionario(int);
	void atendimento();
	int getFuncionario();
private:
	Conta* contas;
	int numeroFuncionario;
	int senhaFuncionario;
	int contasCadastradas;
};