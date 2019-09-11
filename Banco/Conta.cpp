#include "conta.h"
using std::cout;
using std::cin;

Conta::Conta(int numero, string titular, double saldo, int senha) {
	this->numero = numero;
	this->titular = titular;
	this->saldo = saldo;
	this->senha = senha;
}
		
double Conta::get_saldo() {
	return saldo;
}

void Conta::set_saldo() {
	this->saldo = saldo;
}

int Conta::get_numero() {
	return this->numero;
}

string Conta::getTitular() {
	return this->titular;
}

float Conta::deposito(double valor) {
	return saldo += valor;
}

float Conta::saque(double valor) {
	return saldo -= valor;
}

bool Conta::habilitaAcesso(int senha) {
	return this->senha == senha;
}
void Conta::transferencia(Conta* recebedor, double valor) {
	this->saldo -= valor;
	recebedor->saldo += valor;
}