#include <iostream>
#include <conio.h>
#include "conta.h"
#include "banco.h"
using std::cout;
using std::cin;
using std::string;

void getOption();
void getOptionFuncionario();

Banco* banco;
Conta* contaAtual;
double* valor;

bool checkArraysEqual(char* array1, char* array2, int size) {
	for (int cont = 0; cont < size; cont++) {
		if (*(array1 + cont) == '\0') {
			return true;
		}
		//doideira rolando aqui!
		cout << "character" << cont << ": " << (char) * (array1 + cont) << " - ";
		cout << "character" << cont << ": " << (char) * (array2 + cont) << "\n";
		if (!(*(array1 + cont) == *(array2 + cont))) {
			return false;
		}
	}
	return true;
}


void clear_array(char some_array[], int init, int end) {
	for (int i = init; i < end; i++) {
		some_array[i] = '\0';
	}
}

char* getSenha() {
	char senha[20];
	int cont_senha = 0;
	cout << "Senha: ";
	char ch;
	while ((ch = _getch()) != 13) {
		if (ch == 8) {
			if (cont_senha > 0) {
				senha[cont_senha] = '\0';
				cout << '\b';
				cout << ' ';
				cout << '\b';
				cont_senha--;
			}
		}
		else if (ch >= 32 && ch <= 126) {
			senha[cont_senha] = ch;
			cout << '*';
			cont_senha++;
		}
	}
	clear_array(senha, cont_senha, sizeof(senha));
	return senha;
}

void login() {
	int numeroConta;
	int senha;

	cout << "\nBem-vindo!\n\nPara acessar sua conta, por favor insira seu usuario e senha.\n";
	cout << "Numero da conta: ";
	cin >> numeroConta;
	contaAtual = banco->getConta(numeroConta);
	if (banco->getFuncionario() == numeroConta) {
		cout << "Senha: ";
		cin >> senha;
		if (banco->habilitaFuncionario(senha)) {
			getOptionFuncionario();
		}
		else {
			cout << "Credenciais Incorretas\n";
			login();
		}
	}
	else {
		cout << "Senha: ";
		cin >> senha;
		if (contaAtual->habilitaAcesso(senha)) {
			getOption();
		}
		else {
			cout << "Credenciais Incorretas\n";
			login();
		}
	}
}

Conta* novaConta() {
	int numero;
	int senha;
	string titular;
	double saldo;
	cout << "Numero da conta: ";
	cin >> numero;
	cout << "Senha: ";
	cin >> senha;
	cout << "Titular: ";
	cin >> titular;
	cout << "Saldo: ";
	cin >> saldo;
	return new Conta(numero, titular, saldo, senha);
}

void getOptionFuncionario() {
	int opcao;
	cout << "\n\nBem vindo funcionario\n";
	cout << "Selecione uma opcao: \n";
	cout << "1- Criar uma nova conta \n";
	cout << "2- Sair \n";
	cout << "Opcao: ";
	cin >> opcao;
	switch (opcao) {
	case 1:
		banco->cadastraConta(novaConta());
		break;
	case 2:
		login();
		break;
	default:
		cout << "Opcao nao disponivel\n";
	}
	getOptionFuncionario();
}

void saque() {
	cout << "\nValor a ser sacado: R$";
	cin >> *valor;
	contaAtual->saque(*valor);
	cout << "Valor sacado com sucesso\nSeu novo saldo e: R$" << contaAtual->get_saldo() << "\n";
}

void deposito() {
	cout << "\nValor a ser depositado: R$";
	cin >> *valor;
	contaAtual->deposito(*valor);
	cout << "Valor depositado com sucesso\nSeu novo saldo e: R$" << contaAtual->get_saldo() << "\n";
}

void saldo() {
	cout << "Seu saldo e: R$" << contaAtual->get_saldo() << "\n";
}

void transferencia() {
	double valor;
	int numeroRecebedor;
	cout << "\nNumero da conta do recebedor: ";
	cin >> numeroRecebedor;
	Conta* contaRecebedor = banco->getConta(numeroRecebedor);
	cout << "\nValor a ser transferido: R$";
	cin >> valor;
	contaAtual->transferencia(contaRecebedor, valor);
	cout << "Valor transferido com sucesso\nSeu novo saldo e: R$" << saldo << "\n";
}

void getOption() {
	int opcao;
	cout << "\n\nBem vindo " << contaAtual->getTitular() << "\n";
	cout << "Selecione uma opcao: \n";
	cout << "1- Saque \n";
	cout << "2- Deposito \n";
	cout << "3- Saldo \n";
	cout << "4- Transferencia \n";
	cout << "5- Sair \n";
	cout << "Opcao: ";
	cin >> opcao;
	switch (opcao) {
	case 1:
		saque();
		break;
	case 2:
		deposito();
		break;
	case 3:
		saldo();
		break;
	case 4:
		transferencia();
		break;
	case 5:
		login();
		break;
	default:
		cout << "Opcao nao disponivel\n";
	}
	getOption();
}

int main() {
	banco = new Banco(123456,158065);
	login();
}