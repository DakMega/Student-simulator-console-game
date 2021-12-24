#include <iostream>
#include <Windows.h>
#include <set>
#include <cmath>
#include "class.h"
#include <fstream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void death() {
	abort();
}
void Fight( Evil& evil, Player& firstPlayer, Student& classchoice) {
	cout << evil.getName() << " damage you!" << endl;
	int hitDamage = firstPlayer.getHealth(&classchoice) - (evil.getDamage()+(-2+rand()%8));
	firstPlayer.setDynamicHealth(&classchoice,hitDamage);
	cout << firstPlayer.getHealth(&classchoice) << " - your health now" << endl;
	cout << "You fight back " << evil.getName() << endl;
	int outDamage = evil.getHealth() - firstPlayer.getDamage(&classchoice);
	evil.setHealth(outDamage);
	cout << evil.getHealth() << " - health of " << evil.getName() << endl;
	if (firstPlayer.getHealth(&classchoice) <= 0) {
		cout << "\n\n***@!YOU ARE DEAD!@***\n\n";
		death();
	}
}
void Fight( Evil& evil, Player& firstPlayer, Zaochnik& classchoice) {
	cout << evil.getName() << " damage you!" << endl;
	int hitDamage = firstPlayer.getHealth(&classchoice) - (evil.getDamage() + (-2 + rand() % 8));
	firstPlayer.setDynamicHealth(&classchoice, hitDamage);
	cout << firstPlayer.getHealth(&classchoice) << " - your health now" << endl;
	cout << "You fight back " << evil.getName() << endl;
	int outDamage = evil.getHealth() - firstPlayer.getDamage(&classchoice);
	evil.setHealth(outDamage);
	cout << evil.getHealth() << " - health of " << evil.getName() << endl;
	if (firstPlayer.getHealth(&classchoice) <= 0) {
		cout << "\n\n***@!YOU ARE DEAD!@***\n\n";
		death();
	}
}
void Fight( Evil& evil, Player& firstPlayer, ForeignStudent& classchoice) {
	cout << evil.getName() << " damage you!" << endl;
	int hitDamage = firstPlayer.getHealth(&classchoice) - (evil.getDamage() + (-2 + rand() % 8));
	firstPlayer.setDynamicHealth(&classchoice, hitDamage);
	cout << firstPlayer.getHealth(&classchoice) << " - your health now" << endl;
	cout << "You fight back " << evil.getName() << endl;
	int outDamage = evil.getHealth() - firstPlayer.getDamage(&classchoice);
	evil.setHealth(outDamage);
	cout << evil.getHealth() << " - health of " << evil.getName() << endl;
	if (firstPlayer.getHealth(&classchoice) <= 0) {
		cout << "\n\n***@!YOU ARE DEAD!@***\n\n";
		death();
	}
}
void Fight(Evil& evil, Player& firstPlayer,MaxKuprin& classchoice) {
	cout << evil.getName() << " damage you!" << endl;
	int hitDamage = firstPlayer.getHealth(&classchoice) - (evil.getDamage() + (-2 + rand() % 8));
	firstPlayer.setDynamicHealth(&classchoice, hitDamage);
	cout << firstPlayer.getHealth(&classchoice) << " - your health now" << endl;
	cout << "You fight back " << evil.getName() << endl;
	int outDamage = evil.getHealth() - firstPlayer.getDamage(&classchoice);
	evil.setHealth(outDamage);
	cout << evil.getHealth() << " - health of " << evil.getName() << endl;
	if (firstPlayer.getHealth(&classchoice) <= 0) {
		cout << "\n\n***@!YOU ARE DEAD!@***\n\n";
		death();
	}
}

int main() {
	srand(time(nullptr));

	Student student;
	Zaochnik zaochnik;
	ForeignStudent foreignStudent;
	MaxKuprin maxKuprin;
	Player firstPlayer;
	NPC npc;
	Evil evil("Input control", 100, 5);
	int *choice = new int;
	NPC* currClass = nullptr;
	
	string path = "save.txt";
	


	cout << "Student life simulator. ver beta 0.3.0.\n*******************\nWelcome, dear player. Let's get started!\n*******************\n"<< endl;
	Sleep(500);
	cout << "Now you can feel all sides of student life at every event!\n You can use tools or tricks - that depend on type of your student" << endl;
	Sleep(500);
	cout << "Tools and tricks can upgrade your ability to fight with every event. You will find new feachures with every lvl-up.\nJoining to every association can give you peculiarities." << endl;
	Sleep(500);
	cout << "Who are you?\n";
	cout << "[1 - Basic Student 2 - Zaochnik 3 - ForeignStudent 4 - MaxKuprin]\n"<<endl;
	cout << "\n@ Basic student - usual dweller of university. \n\n@ Zaochnik - appearing in evenings.\n\n@ Foreighn sudent - student, which came to us from far. \n\n@ Kuprin - Just unical one\nSo, choose wisely\n" << endl;;
	Sleep(500);
		
	cin >> *choice;
	switch (*choice) {
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

	firstPlayer.getInfo(currClass);
	cout << "What association are you from?\n 1 - StudClub  2 - ProfCom  3 - ActiveGroup \t";
	Sleep(1000);
	int *group = new int;
	cin >> *group;

	switch (*group) {
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
	delete group;
	group = nullptr;
	//fstream fs;
	//fs.open(path, fstream::in | fstream::out | fstream::app);
	//if (!fs.is_open()) {
	//	cout << "reading error!" << endl;
	//}
	//else {
	//	string message;
	//	int swtch;
	//	cout << "file opened" << endl;
	//	cout << "Input 0 to store, 1 to read" << endl;
	//	cin >> swtch;
	//	if (swtch == 0) {
	//		cout << "input message" << endl;;
	//		fs << firstPlayer.getName(currClass) << "\n";
	//	}
	//	if (swtch == 1) {
	//		while (!fs.eof()) {
	//			message = "";
	//			fs >> message;
	//			cout << message << endl;
	//		}
	//	}
	//}



	firstPlayer.getInfo(currClass);
	evil.getInfo();

	Sleep(100);

	cout << "\n****\nGet ready for first fight!\nIt's input control!\n****\n";

	Sleep(1000);

	while (evil.getHealth() > 0) {
		if (*choice == 1) {
			Fight(evil, firstPlayer, student);
		}
		if (*choice == 2) {
			Fight(evil, firstPlayer, zaochnik);
		}
		if (*choice == 3) {
			Fight(evil, firstPlayer, foreignStudent);
		}
		if (*choice == 4) {
			Fight(evil, firstPlayer, maxKuprin);
		}
		if (evil.getHealth() == 0) {
			firstPlayer.lvlUP(currClass, 1);
		}
		Sleep(1000);
	}

	firstPlayer.healthUpdate(currClass);

	Sleep(100);



	cout << "****\nNow, the time is come... \nfight against the Attestation!\n****" << endl;
	Sleep(100);
	Evil evil2("Attestation", 500, 10);

	firstPlayer.getInfo(currClass);
	evil2.getInfo();

	if (*choice == 1) {
		firstPlayer.getTool(&student);
	}
	if (*choice == 2) {
		firstPlayer.useTrick(&zaochnik);
	}
	if (*choice == 3) {
		firstPlayer.useTrick(&foreignStudent);
	}
	if (*choice == 4) {
		bool rndSelect = rand() % 1;
		if (rndSelect = 0) {
			firstPlayer.useTrick(&maxKuprin);
		}
		else {
			firstPlayer.getTool(&maxKuprin);
		}
		
	}

	Sleep(1000);

	while (evil2.getHealth() > 0) {
		if (*choice == 1) {
			Fight(evil2, firstPlayer, student);
		}
		if (*choice == 2) {
			Fight(evil2, firstPlayer, zaochnik);
		}
		if (*choice == 3) {
			Fight(evil2, firstPlayer, foreignStudent);
		}
		if (*choice == 4) {
			Fight(evil2, firstPlayer, maxKuprin);
		}
		if (evil2.getHealth() == 0) {
			firstPlayer.lvlUP(currClass, 1);
		}
		Sleep(1000);	
	}
	firstPlayer.healthUpdate(currClass);
	Sleep(100);
	cout << "****\nTime has been gone... Danger! \nThe big Zachet is coming with scary AMOGUS sounds!\n****" << endl;
	Evil evil3("Zachet", 700, 25);
	firstPlayer.getInfo(currClass);
	evil3.getInfo();

	if (*choice == 1) {
		firstPlayer.getTool(&student);
	}
	if (*choice == 2) {
		firstPlayer.useTrick(&zaochnik);
	}
	if (*choice == 3) {
		firstPlayer.useTrick(&foreignStudent);
	}
	if (*choice == 4) {
		bool rndSelect = rand() % 1;
		if (rndSelect = 0) {
			firstPlayer.useTrick(&maxKuprin);
		}
		else {
			firstPlayer.getTool(&maxKuprin);
		}

	}

	Sleep(1000);

	while (evil3.getHealth() > 0) {
		if (*choice == 1) {
			Fight(evil3, firstPlayer, student);
		}
		if (*choice == 2) {
			Fight(evil3, firstPlayer, zaochnik);
		}
		if (*choice == 3) {
			Fight(evil3, firstPlayer, foreignStudent);
		}
		if (*choice == 4) {
			Fight(evil3, firstPlayer, maxKuprin);
		}
		if (evil3.getHealth() == 0) {
			firstPlayer.lvlUP(currClass, 1);
		}
		Sleep(1000);
	}

	firstPlayer.healthUpdate(currClass);

	Sleep(100);

	cout << "\nOH NO! The very large SUETA is coming - its SESSION! \nJust try to stay alive!!!";
	Evil evil4("SESSION", 1500, 100);
	firstPlayer.getInfo(currClass);
	evil4.getInfo();

	if (*choice == 1) {
		firstPlayer.getTool(&student);
	}
	if (*choice == 2) {
		firstPlayer.useTrick(&zaochnik);
	}
	if (*choice == 3) {
		firstPlayer.useTrick(&foreignStudent);
	}
	if (*choice == 4) {
		bool *rndSelect = new bool;
		*rndSelect = rand() % 1;
		if (rndSelect = 0) {
			firstPlayer.useTrick(&maxKuprin);
		}
		else {
			firstPlayer.getTool(&maxKuprin);
		}
		delete rndSelect;
		rndSelect = nullptr;

	}

	Sleep(1000);

	while (evil4.getHealth() > 0) {
		if (*choice == 1) {
			Fight(evil4, firstPlayer, student);
		}
		if (*choice == 2) {
			Fight(evil4, firstPlayer, zaochnik);
		}
		if (*choice == 3) {
			Fight(evil4, firstPlayer, foreignStudent);
		}
		if (*choice == 4) {
			Fight(evil4, firstPlayer, maxKuprin);
		}
		if (evil4.getHealth() == 0) {
			firstPlayer.lvlUP(currClass, 1);
		}
		Sleep(1000);
	}
	
	delete choice;
	choice = nullptr;

	firstPlayer.getInfo(currClass);
	cout << "Wow! Congratulations! You still alive! You won!\n" << endl;;

	return 0;
}