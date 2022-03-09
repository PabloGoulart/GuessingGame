#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>

void ShowText();
void InputNotNumber();
void NextTry(int kick, int secretNumber);
void GameOver(int kick, int attempts, int secretNumber, int attemptLimit);

int main()
{
	setlocale(LC_ALL, "Portuguese");

	srand(time(0));
	const int SECRET_NUMBER = rand() % 100;

	int kick = 0;
	int attempts = 0;
	int attemptLimit = 0;

	char option;

	ShowText();

	while (attemptLimit <= 0)
	{
		std::cin >> option;

		option = toupper(option);
		switch (option)
		{
		case 'F':
			attemptLimit = 10;
			break;
		case 'M':
			attemptLimit = 5;
			break;
		case 'D':
			attemptLimit = 3;
			break;
		default:
			std::cout << "Opção não existe" << std::endl;
			break;
		}
	}

	while (kick != SECRET_NUMBER && attempts != attemptLimit)
	{
		std::cout << "Qual seu chute? ";
		std::cin >> kick;

		system("cls");

		if (std::cin.fail())
		{
			InputNotNumber();
		}
		else
		{
			attempts++;
			std::cout << "Tentativa " << attempts << std::endl;
			std::cout << "Seu chute foi: " << kick << std::endl;

			NextTry(kick, SECRET_NUMBER);

			GameOver(kick, attempts, SECRET_NUMBER, attemptLimit);
		}
	}
}

void ShowText()
{
	std::cout << "*************************************" << std::endl;
	std::cout << "* Bem-vindo ao jogo da adibinhação! *" << std::endl;
	std::cout << "*************************************" << std::endl;
	std::cout << "Escolha o se nível de dificuldade:" << std::endl;
	std::cout << "Fácil (F), Médio (M) ou Difícil (D)" << std::endl;
}

void InputNotNumber() {
	std::cout << "Erro! Por-favor digite um número." << std::endl;
	std::cin.clear();
	std::cin.ignore();
}

void NextTry(int kick, int secretNumber)
{
	if (kick > secretNumber)
	{
		std::cout << "O número secreto é menor do que " << kick << std::endl;
	}
	else
	{
		std::cout << "O número secreto é maior do que " << kick << std::endl;
	}
}

void GameOver(int kick, int attempts, int secretNumber, int attemptLimit)
{
	if (attempts == attemptLimit)
	{
		std::cout << "Você perdeu!\nO número secreto era: " << secretNumber << std::endl;
	}	
	else if (kick == secretNumber)
	{
		std::cout << "Parabéns! Você venceu!\nO número secreto era: " << secretNumber << std::endl;
	}
}
