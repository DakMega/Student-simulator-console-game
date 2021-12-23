#include <iostream>
#include <set>
#include <cmath>
#include "class.h"
#include <fstream>
using namespace std;

void Fight( Evil& evil, Player& firstPlayer, Warrior& classchoice) {
	int hitDamage = firstPlayer.getHealth(&classchoice) - evil.getDamage();
	firstPlayer.setHealth(&classchoice,hitDamage);
}
void Fight( Evil& evil, Player& firstPlayer, Wizard& classchoice) {
	int hitDamage = firstPlayer.getHealth(&classchoice) - evil.getDamage();
	firstPlayer.setHealth(&classchoice, hitDamage);
}
void Fight( Evil& evil, Player& firstPlayer, Paladin& classchoice) {
	int hitDamage = firstPlayer.getHealth(&classchoice) - evil.getDamage();
	firstPlayer.setHealth(&classchoice, hitDamage);
}

int main() {
	string src = "save.txt";
	ifstream fin;
	ofstream fout;
	Warrior warrior;
	Wizard wizard;
	Paladin paladin;
	Programmer programmer;
	Technic technic;
	Player firstPlayer;
	NPC npc;
	Evil evil;
	/*cout << "Hello, player \nGet rest beside the fire\n";
	cout << "You are one of the heroes, I guess?\n";
	cout << "Do you remember your story?\n";
	int answer;
	cin >> answer;
	if (answer == 1) {
		fin.open(src);
		if (!fin.is_open()) {
			cout << "No save file" << endl;
		}
		else {
			Player PLR;
			
			while (fin.read((char*)&PLR, sizeof(Player))) {

			}
			cout << "Loading succesfully" << endl;
			fin.close();
		}
	}
	*/
	cout << "Who are you?\n";
	cout << "(1 - Warrior 2 - Wizard 3 - Paladin 4 - Programmer 5 - Technic)\n";
	int choice;
	NPC* currClass = nullptr;
	cin >> choice;
	switch (choice) {
		case 1: {
			firstPlayer.create(&warrior);
			firstPlayer.lvlUP(&warrior, 4);
			currClass = &warrior;
			break;
		}
			  
		case 2: {
			firstPlayer.create(&wizard);
			firstPlayer.lvlUP(&wizard, 4);
			currClass = &wizard;
			break;
		}
			/*  
		case 3: {
			firstPlayer.create(&paladin);
			Paladin &currentClass = paladin;
			break;
		}
		case 4: {
			firstPlayer.create(&programmer);
			Programmer &currentClass = programmer;
			break;
		}
		case 5: {
			firstPlayer.create(&technic);
			Technic &currentClass = technic;
			break;
		}


		*/
	}
	//firstPlayer.getInfo(currClass);
	//evil.getInfo();

	firstPlayer.getInfo(&warrior);
	cout << "What guild are you from?\n 1 - Aggressors  2 - Scavengers  3 - Farlanders \t";
	cin >> choice;

	switch (choice) {
		case 1: {
			cout << "30% damage increase" << endl;
			firstPlayer.setDamage(&warrior, (firstPlayer.getDamage(&warrior) * 1.3));
			break;
		}
		case 2: {
			cout << "50% health increase and 20% damage decrease" << endl;
			firstPlayer.setHealth(&warrior, (firstPlayer.getHealth(&warrior) * 1.5));
			firstPlayer.setDamage(&warrior, (firstPlayer.getDamage(&warrior) * 0.8));
			break;
		}
		case 3: {
			cout << "10% health increase and 10% damage increase" << endl;
			firstPlayer.setDamage(&warrior, (firstPlayer.getDamage(&warrior) * 1.1));
			firstPlayer.setHealth(&warrior, (firstPlayer.getHealth(&warrior) * 1.1));
			break;
		}

	}
	firstPlayer.getInfo(&warrior);
	Fight(evil, firstPlayer, warrior);
	/*cout << "Save progress?";
	int save;
	cin >> save;
	if (save == 1) {
		fout.open(src, fstream::app);
		if (!fout.is_open()) {
			cout << "Save error"<<endl;
		}
		else {
			cout << "Saved successfully" << endl;
			fout.write((char*)&firstPlayer,sizeof(Player));
		}
		fout.close();
	}*/
	firstPlayer.getInfo(&warrior);
	return 0;
}