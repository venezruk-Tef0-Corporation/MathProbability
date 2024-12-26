#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#include "InputValidation.h"

using namespace std;

void GetInformation(void) {

	int PlayersCounter = 0;

	cout << "������� ���������� ����������: ";
	PlayersCounter = GetInt();

	vector<int> PlayersList;

	for (int i = 0; i < PlayersCounter; i++) {

		cout << "�������� " << i + 1 << endl;

		int PlayerImmersion = 0;

		do {
			cout << "������� ������� ������������� ��������� �� 10-�������� �����: ";

			PlayerImmersion = GetInt();

			if (PlayerImmersion < 0 or PlayerImmersion > 10) {

				cout << "������ �����. ��������� ����" << endl;
			}

		} while (PlayerImmersion < 0 or PlayerImmersion > 10);

		PlayersList.push_back(PlayerImmersion);
	}

	vector<double> ListOfDegrees;

	for (int i = 0; i < PlayersList.size(); i++) {

		double DegreeOfOutcome = PlayersList[i] / 10.0;
		DegreeOfOutcome = 0.1 + (DegreeOfOutcome - 0.1) * (0.2 + ((rand() % 100) / 100.0) * 0.8);
	
		ListOfDegrees.push_back(DegreeOfOutcome*100);
	}

	for (int i = 0; i < PlayersList.size(); i++) cout << "��������� " << i + 1 << endl << "����������� ����� � ������� " << ListOfDegrees[i] << "%" << endl;
}