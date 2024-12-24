#include <iostream>
#include <windows.h>

#include "Enums.h"
#include "InputValidation.h"
#include "MenuInterface.h"
#include "ProgramFunctions.h"

using namespace std;

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	GreetingFunction();

	MainMenuItems UserChoice = static_cast<MainMenuItems>(0);

	do {
		cout << "[1] - Перейти к вводу" << endl 
			 << "[2] - Выход" << endl;
		cout << "Выберите пункт меню: ";
		UserChoice = GetMainMenuItem();

		switch (UserChoice) {

		case StartProgram:
			cout << "Выполнение программы" << endl;
			GetInformation();
			break;

		case Quit:
			cout << "Завершение работы" << endl;
			break;
		
		default:
			cout << "Введенный пункт отсутствует. Повторите ввод" << endl;
		}
	} while (UserChoice != Quit);

	return EXIT_SUCCESS;
}

