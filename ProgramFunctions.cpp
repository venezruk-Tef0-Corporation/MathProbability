#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#include "InputValidation.h"

using namespace std;

void GetInformation(void) {

	int PlayersCounter = 0;

	cout << "Введите количество участников: ";
	PlayersCounter = GetInt();

	vector<int> PlayersList;

	for (int i = 0; i < PlayersCounter; i++) {

		cout << "Участник " << i + 1 << endl;

		int PlayerImmersion = 0;

		do {
			cout << "Введите степень погруженности участника по 10-балльной шкале: ";

			PlayerImmersion = GetInt();

			if (PlayerImmersion < 0 or PlayerImmersion > 10) {

				cout << "Ошибка ввода. Повторите ввод" << endl;
			}

		} while (PlayerImmersion < 0 or PlayerImmersion > 10);

		PlayersList.push_back(PlayerImmersion);
	}

	vector<int> ListOfDegrees;

	for (int i = 0; i < PlayersList.size(); i++) {

		double DegreeOfOutcome = PlayersList[i] / 10.0;
		if (DegreeOfOutcome < 0.75) DegreeOfOutcome += (rand() % 30) / 100.0;

		if (DegreeOfOutcome >= 0.75) {

			ListOfDegrees.push_back(1);
		}
		else ListOfDegrees.push_back(0);
	}

	for (int i = 0; i < ListOfDegrees.size(); i++) {

		if (ListOfDegrees[i] == 1) PlayersList[i] = rand() % 12 + 1;
		else PlayersList[i] = rand() % 12 + 13;
	}

	for (int i = 0; i < PlayersList.size(); i++) cout << "Участнику " << i + 1 << endl << "Достался билет №" << PlayersList[i] << endl;
}