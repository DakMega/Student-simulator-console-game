#include <iostream>
#include <Windows.h>
#include <set>
#include <cmath>
#include "class.h"
#include <fstream>
using namespace std;

void Fight( Evil& evil, Player& firstPlayer, Student& classchoice) {
	cout << evil.getName() << " damage you!" << endl;
	int hitDamage = firstPlayer.getHealth(&classchoice) - evil.getDamage();
	firstPlayer.setDynamicHealth(&classchoice,hitDamage);
	cout << firstPlayer.getHealth(&classchoice) << " - your health now" << endl;
	cout << "You fight back " << evil.getName() << endl;
	int outDamage = evil.getHealth() - firstPlayer.getDamage(&classchoice);
	evil.setHealth(outDamage);
	cout << evil.getHealth() << " - health of " << evil.getName() << endl;
}
void Fight( Evil& evil, Player& firstPlayer, Zaochnik& classchoice) {
	cout << evil.getName() << " damage you!" << endl;
	int hitDamage = firstPlayer.getHealth(&classchoice) - evil.getDamage();
	firstPlayer.setDynamicHealth(&classchoice, hitDamage);
	cout << firstPlayer.getHealth(&classchoice) << " - your health now" << endl;
	cout << "You fight back " << evil.getName() << endl;
	int outDamage = evil.getHealth() - firstPlayer.getDamage(&classchoice);
	evil.setHealth(outDamage);
	cout << evil.getHealth() << " - health of " << evil.getName() << endl;
}
void Fight( Evil& evil, Player& firstPlayer, ForeignStudent& classchoice) {
	cout << evil.getName() << " damage you!" << endl;
	int hitDamage = firstPlayer.getHealth(&classchoice) - evil.getDamage();
	firstPlayer.setDynamicHealth(&classchoice, hitDamage);
	cout << firstPlayer.getHealth(&classchoice) << " - your health now" << endl;
	cout << "You fight back " << evil.getName() << endl;
	int outDamage = evil.getHealth() - firstPlayer.getDamage(&classchoice);
	evil.setHealth(outDamage);
	cout << evil.getHealth() << " - health of " << evil.getName() << endl;
}
void Fight(Evil& evil, Player& firstPlayer,MaxKuprin& classchoice) {
	cout << evil.getName() << " damage you!" << endl;
	int hitDamage = firstPlayer.getHealth(&classchoice) - evil.getDamage();
	firstPlayer.setDynamicHealth(&classchoice, hitDamage);
	cout << firstPlayer.getHealth(&classchoice) << " - your health now" << endl;
	cout << "You fight back " << evil.getName() << endl;
	int outDamage = evil.getHealth() - firstPlayer.getDamage(&classchoice);
	evil.setHealth(outDamage);
	cout << evil.getHealth() << " - health of " << evil.getName() << endl;
}

int main() {
	string src = "save.txt";
	ifstream fin;
	ofstream fout;
	Student student;
	Zaochnik zaochnik;
	ForeignStudent foreignStudent;
	MaxKuprin maxKuprin;
	Player firstPlayer;
	NPC npc;
	Evil evil("Input control", 100, 5);

	cout << "Welcome, dear player. Let's get started!";
	Sleep(500);
	cout << "Who are you?\n";
	cout << "(1 - Basic Student 2 - Zaochnik 3 - ForeignStudent 4 - MaxKuprin)\n";
	Sleep(500);
	int choice;
	NPC* currClass = nullptr;
	cin >> choice;
	switch (choice) {
	case 1: {
		firstPlayer.create(&student);
		currClass = &student;
		break;
	}

	case 2: {
		firstPlayer.create(&zaochnik);
		currClass = &zaochnik;
		break;
	}

	case 3: {
		firstPlayer.create(&foreignStudent);
		currClass = &foreignStudent;
		break;
	}
	case 4: {
		firstPlayer.create(&maxKuprin);
		currClass = &maxKuprin;
		break;
	}



	}
	//firstPlayer.getInfo(currClass);
	//evil.getInfo();

	firstPlayer.getInfo(currClass);
	cout << "What guild are you from?\n 1 - StudClub  2 - ProfCom  3 - ActiveGroup \t";
	Sleep(1000);
	int group;
	cin >> group;

	switch (group) {
	case 1: {
		cout << "30% damage increase" << endl;
		firstPlayer.setDamage(currClass, (firstPlayer.getDamage(currClass) * 1.3));
		break;
	}
	case 2: {
		cout << "50% health increase and 20% damage decrease" << endl;
		firstPlayer.setHealth(currClass, (firstPlayer.getHealth(currClass) * 1.5));
		firstPlayer.setDamage(currClass, (firstPlayer.getDamage(currClass) * 0.8));
		break;
	}
	case 3: {
		cout << "10% health increase and 10% damage increase" << endl;
		firstPlayer.setDamage(currClass, (firstPlayer.getDamage(currClass) * 1.1));
		firstPlayer.setHealth(currClass, (firstPlayer.getHealth(currClass) * 1.1));
		break;
	}

	}
	//firstPlayer.healthUpdate();
	firstPlayer.getInfo(currClass);
	evil.getInfo();
	cout << "Get ready for first fight!\nIt's input control!";
	while (evil.getHealth() > 0) {
		if (choice == 1) {
			Fight(evil, firstPlayer, student);
		}
		if (choice == 2) {
			Fight(evil, firstPlayer, zaochnik);
		}
		if (choice == 3) {
			Fight(evil, firstPlayer, foreignStudent);
		}if (choice == 4) {
			Fight(evil, firstPlayer, maxKuprin);
		}
		if (evil.getHealth() == 0) {
			firstPlayer.lvlUP(currClass, 1);
		}
		Sleep(1000);
	}
	firstPlayer.healthUpdate(currClass);
	cout << "Now, fight against the Session!" << endl;
	Sleep(1000);
	
	Evil evil2("Session", 500, 10);
	
	while (evil2.getHealth() > 0) {
		if (choice == 1) {
			Fight(evil2, firstPlayer, student);
		}
		if (choice == 2) {
			Fight(evil2, firstPlayer, zaochnik);
		}
		if (choice == 3) {
			Fight(evil2, firstPlayer, foreignStudent);
		}if (choice == 4) {
			Fight(evil2, firstPlayer, maxKuprin);
		}
		if (evil2.getHealth() == 0) {
			firstPlayer.lvlUP(currClass, 1);
		}
		Sleep(1000);
		
	}
	
	firstPlayer.healthUpdate(currClass);
	firstPlayer.getInfo(currClass);
	return 0;
}