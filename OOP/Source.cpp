#include <iostream>
#include <set>
#include <cmath>
#include "class.h"
#include <fstream>
using namespace std;

void Fight( Evil& evil, Player& firstPlayer, Student& classchoice) {
	int hitDamage = firstPlayer.getHealth(&classchoice) - evil.getDamage();
	firstPlayer.setHealth(&classchoice,hitDamage);
}
void Fight( Evil& evil, Player& firstPlayer, Zaochnik& classchoice) {
	int hitDamage = firstPlayer.getHealth(&classchoice) - evil.getDamage();
	firstPlayer.setHealth(&classchoice, hitDamage);
}
void Fight( Evil& evil, Player& firstPlayer, ForeignStudent& classchoice) {
	int hitDamage = firstPlayer.getHealth(&classchoice) - evil.getDamage();
	firstPlayer.setHealth(&classchoice, hitDamage);
}
void Fight(Evil& evil, Player& firstPlayer,MaxKuprin& classchoice) {
	int hitDamage = firstPlayer.getHealth(&classchoice) - evil.getDamage();
	firstPlayer.setHealth(&classchoice, hitDamage);
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
	Evil evil;
	/*cout << "Hello, student \nGet rest beside the fire\n";
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
	cout << "(1 - Basic Student 2 - Zaochnik 3 - ForeignStudent 4 - MaxKuprin)\n";
	int choice;
	NPC* currClass = nullptr;
	cin >> choice;
	switch (choice) {
		case 1: {
			firstPlayer.create(&student);
			firstPlayer.lvlUP(&student, 4);
			currClass = &student;
			break;
		}
			  
		case 2: {
			firstPlayer.create(&zaochnik);
			firstPlayer.lvlUP(&zaochnik, 4);
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
	firstPlayer.getInfo(currClass);
	cout << "Get ready for first fight!\nIt's incoming control!";
	
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
	firstPlayer.getInfo(currClass);
	return 0;
}