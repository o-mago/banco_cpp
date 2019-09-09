#include <iostream>
#include <conio.h>
#include "conta.h"
#include "funcionario.h"
using std::cout;
using std::cin;
using std::string;
using charArray = char[20];


void try_login();
void getOption();

charArray usuarios[100];
Conta contas[100];
char n_contas = 0;
Conta conta_atual;
Funcionario conta_funcionario;

bool checkArraysEqual(char* array1, char* array2, int size) {
	for (int cont = 0; cont < size; cont++) {
		if (*(array1 + cont) == '\0') {
			return true;
		}
		//doideira rolando aqui!
		cout << "character" << cont << ": " << (char)*(array1+cont) << " - ";
		cout << "character" << cont << ": " << (char)*(array2+cont) << "\n";
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

bool login() {
	char usuario[20];
	clear_array(usuario, 0, 20);
	
	cout << "\nBem-vindo!\n\nPara acessar sua conta, por favor insira seu usuario e senha.\n";
	cout << "Usuario: ";
	cin >> usuario;
	for (char cont_usuario = 0; cont_usuario < n_contas; cont_usuario++) {
		if (checkArraysEqual(&usuario[0], &usuarios[cont_usuario][0], sizeof(usuario))){
			char* senha_pointer = getSenha();
			char senha[20];
			for (int i = 0; i < 20; i++) {
				senha[i] = *(senha_pointer+i);
			}
			if (checkArraysEqual(&contas[cont_usuario].senha[0], &senha[0], sizeof(usuario))) {
				//cout << "foi";
				conta_atual = contas[cont_usuario];
				return true;
			}
			else {
				cout << "\nsenha inserida: " << senha << "\n";
				cout << "senha esperada: " << contas[cont_usuario].senha << "\n";
				cout << "num foi senha";
				return false;
			}
		}
	}
	cout << "num foi";
	return false;
}

//void copy_array(char* origin, char* destination) {
//	for (int i = 0; i < sizeof(origin); i++) {
//		destination[i] = origin[i];
//	}
//}

void createNewUser() {
	char usuario[20];
	cout << "Usuario: ";
	cin >> usuario;
	for (char cont_usuario = 0; cont_usuario < n_contas; cont_usuario++) {
		if (checkArraysEqual(usuario, usuarios[cont_usuario], sizeof(usuario))) {
			cout << "\nUsuario ja existente\n";
			getOption();
		}
	}
	char* senha_pointer = getSenha();
	char nova_senha[20];
	for (int i = 0; i < 20; i++) {
		nova_senha[i] = *(senha_pointer + i);
	}
	contas[n_contas] = conta_funcionario.nova_conta(usuario, nova_senha);
	strcpy_s(usuarios[n_contas], usuario);
	n_contas++;
	cout << "\nUsuario criado com sucesso!\n";
}

void getOption() {
	cout << "\n\nBem vindo " << conta_atual.get_usuario() << "\n";
	cout << "Selecione uma opcao: \n";
	int opcao = 0;
	char funcionario_array[20] = "admin";
	if (checkArraysEqual(conta_atual.get_usuario(), funcionario_array, sizeof(funcionario_array))) {
		cout << "1- Criar uma nova conta \n";
		cout << "2- Sair \n";
		cout << "Opcao: ";
		cin >> opcao;
		switch (opcao) {
		case 1:
			createNewUser();
			break;
		case 2:
			try_login();
			break;
		default:
			cout << "Opcao nao disponivel";
		}
	}
	else {
		cout << "1- Saque \n";
		cout << "2- Deposito \n";
		cout << "3- Saldo \n";
		cout << "4- Transferencia \n";
		cout << "5- Sair \n";
		cout << "Opcao: ";
		cin >> opcao;
		float valor = 0;
		float saldo;
		switch (opcao) {
		case 1:
			cout << "\nValor a ser sacado: R$";
			cin >> valor;
			saldo = conta_atual.saque(valor);
			cout << "Valor sacado com sucesso\nSeu novo saldo e: R$" << saldo << "\n";
			break;
		case 2:
			cout << "\nValor a ser depositado: R$";
			cin >> valor;
			saldo = conta_atual.deposito(valor);
			cout << "Valor depositado com sucesso\nSeu novo saldo e: R$" << saldo << "\n";
			break;
		case 3:
			saldo = conta_atual.get_saldo();
			cout << "Seu saldo e: R$" << saldo << "\n";
			break;
		case 4:
			char usuario[20];
			cout << "\nConta do recebedor: ";
			cin >> usuario;
			for (char cont_usuario = 0; cont_usuario < n_contas; cont_usuario++) {
				if (checkArraysEqual(usuario, usuarios[cont_usuario], sizeof(usuario))) {
					cout << "\nValor a ser transferido: R$";
					cin >> valor;
					saldo = conta_atual.saque(valor);
					contas[cont_usuario].deposito(valor);
					cout << "Valor transferido com sucesso\nSeu novo saldo e: R$" << saldo << "\n";
					system("pause");
					getOption();
				}
			}
			cout << "Usuario incorreto\n";
			break;
		case 5:
			try_login();
			break;
		default:
			cout << "Opcao nao disponivel";
		}
	}
	system("pause");
	getOption();
}

void try_login() {
	if (login()) {
		getOption();
	}
	else {
		cout << "\nCredenciais incorretas!\n";
		try_login();
	}
}

int main() {
	char user[20] = "alex";
	char password[20] = "admin";
	strcpy_s(usuarios[n_contas], user);
	contas[n_contas] = Conta::Conta(user, password);
	n_contas++;
	char user2[20] = "xela";
	char password2[20] = "admin";
	strcpy_s(usuarios[n_contas], user2);
	contas[n_contas] = Conta::Conta(user2, password2);
	n_contas++;
	char user3[20] = "admin";
	char password3[20] = "158065";
	conta_funcionario = Funcionario::Funcionario();
	strcpy_s(usuarios[n_contas], user3);
	contas[n_contas] = Funcionario::Conta(user3, password3);
	n_contas++;
	try_login();
	

	// 

	//cout << "O seu saldo é: R$" << saldo << "\n";

	//char usuario[20];
	//char senha[20];
	//cout << "Digite o usuário: ";
	//cin >> usuario;
	//cout << "Digite a senha: ";
	//cin >> senha;
}