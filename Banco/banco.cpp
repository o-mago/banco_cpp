#include "banco.h";
using std::cout;

Banco::Banco(int numeroFuncionario, int senhaFuncionario) {
	this->numeroFuncionario = numeroFuncionario;
	this->senhaFuncionario = senhaFuncionario;
	this->contasCadastradas = 0;
}

Banco::~Banco() {
	delete& this->numeroFuncionario;
	delete &this->senhaFuncionario;
	for (int i = 0; i < this->contasCadastradas; i++) {
		delete (this->contas + i);
	}
	delete &this->contasCadastradas;
}

void Banco::cadastraConta(Conta* conta) {
	for (int i = 0; i < contasCadastradas; i++) {
		if ((this->contas + contasCadastradas)->get_numero() == conta->get_numero()) {
			cout << "Numero de conta ja cadastrado";
		}
		else {
			cout << "Conta nao encontrada";
		}
	}
	conta = this->contas + this->contasCadastradas;
	this->contasCadastradas++;
}

Conta* Banco::getConta(int numero) {
	for (int i = 0; i < contasCadastradas; i++) {
		if ((this->contas + contasCadastradas)->get_numero() == numero) {
			return this->contas + contasCadastradas;
		}
		else {
			cout << "Conta nao encontrada";
		}
	}
}

bool Banco::habilitaFuncionario(int senha) {
	return this->senhaFuncionario == senha;
}

int Banco::getFuncionario() {
	return this->numeroFuncionario;
}