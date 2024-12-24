#include <iostream>
#include <windows.h>

#include "Enums.h"
#include "InputValidation.h"
#include "MenuInterface.h"

using namespace std;

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	GreetingFunction();

	MainMenuItems UserChoice = static_cast<MainMenuItems>(0);

	do {

		cout << "Выберите пункт меню: ";
		UserChoice = GetMainMenuItem();

		switch (UserChoice) {

		case StartProgram:

			break;

		case Quit:
			cout << "Завершение работы" << endl;
			break;
		}
	} while (UserChoice != Quit);


	return EXIT_SUCCESS;
}

