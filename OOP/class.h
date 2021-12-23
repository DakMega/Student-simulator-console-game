#pragma once
#include <Windows.h>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

class NPC{
protected:
	bool student;
	bool zaochnik;
	bool maxKuprin;
	bool foreignStudent;
	bool evil;
	bool player;
	int health;
	int dynamicHealth;
	int damage;
	int lvl;
	string name;
public:
	NPC() {
		student = false;
		zaochnik = false;
		foreignStudent = false;
		maxKuprin = false;
		evil = false;
		health = 100;
		damage = 1;
		lvl = 1;
		dynamicHealth = health;
	}
	virtual void getInfo() {
		Sleep(500);
		cout << "\n**************************" << endl;
		cout << "Hello " << name << endl;
		cout << " Your damage = " << damage << endl;
		cout << " Your health now = " << dynamicHealth << endl;
		cout << " your full health = " << health << endl;
		cout << " Your social credits = " << lvl << endl;
		cout << "**************************\n" << endl;
		Sleep(500);
	}
	int getHealth() {
		return dynamicHealth;
	}
	int getDamage() {
		return damage;
	}
	void setHealth(int DeltaHealth) {
		this->health = DeltaHealth;
	}
	void setDynamicHealth(int DeltaHealth) {
		this->dynamicHealth = DeltaHealth;
	}
	void setDamage(int DeltaDamage) {
		this->damage = DeltaDamage;
	}
	void healthUpdate() {
		cout << "\n**************************" << endl;
		bool doHill;
		cout << "\n Do you want to get rest on your favourite sofa? 0 - no 1 - yes."<<endl;
		cin >> doHill;
		if (doHill) {
			while (this->dynamicHealth < this->health) {
				Sleep(500);
				this->dynamicHealth += 0.1 * (this->health);
				if (this->dynamicHealth > this->health) {
					this->dynamicHealth = this->health;
				}
				cout << "Hilling, please wait..." << "\nCurrent health is " << this->dynamicHealth << endl;
				Sleep(500);
			}
		}
	}
	void lvlUP(int value) {
		Sleep(500);
		cout << "\n**************************"<<endl;
		lvl += value;
		cout << "Congratulations! LVL UP to " << lvl << " !" << endl;
		this->health = health * (log(lvl) + 1);
		this->damage = damage * (log(lvl) + 1);
		cout << "**************************" << endl;
	}
	void sayDynamicHealth() {
		cout << name << " running health is " << dynamicHealth << endl;
	}
	virtual void create() {}
	~NPC() {}
};
class Student : virtual public NPC {
public:
	string tools[4] = { "studak","zachetka","teoretical mechanics","solderer"};
	Student() {
		student = true;
		zaochnik = false;
		foreignStudent = false;
		maxKuprin = false;

		health = 150;
		damage = 30;
		name = "Student_NULL";
	}
	void getTool() {
		cout << "Choose the tool for fight! " << endl;
		Sleep(500);
		cout << "Tools list: " << endl;
		Sleep(500);
		int i = 0;
		for (; i < lvl; i++) {
			cout << i << " - " << tools[i] << endl;
		}
		cout << "Select your tool \t";
		cin >> i;
		while (i >= lvl) {
			cout << " This tool is unavailiable" << endl;
			cout << "Select other one" << endl;
			cin >> i;
		}
		cout << name << " get " << tools[i] << endl;
		this->damage = (log(i+1)+1) * damage;
	}
	void create() override {
		cout << "You are created Student" << endl;
		cout << "What is your name? " << endl;
		cin >> name;
		getInfo();
		getTool();
	}
	~Student() {
	}
};
class Zaochnik : virtual public NPC {
private:
	int weakness;
public:
	string trick[4] = { "buy work","copy someone's work","good sleep tonight","energos"};
	Zaochnik() {
		student = false;
		zaochnik = true;
		foreignStudent = false;
		maxKuprin = false;

		health = 100;
		damage = 40;
		weakness = 50;
		name = "Zaochnik_NULL";
	}
	void useTrick() {
		cout << "Choose the trick for fight! " << endl;
		Sleep(500);
		cout << "Tricks list: " << endl;
		Sleep(500);
		int i = 0;
		for (; i < lvl; i++) {
			cout << i << " - " << trick[i] << endl;
		}
		cout << "Select your trick \t";
		cin >> i;
		while (i >= lvl) {
			cout << " This tool is unavailiable" << endl;
			cout << "Select other one" << endl;
			cin >> i;
		}
		cout << name << " get " << trick[i] << endl;
		this->damage = (log(i + 1) + 1) * damage;
	}
	void create() override {
		cout << "You are created Zaochnik" << endl;
		cout << "What is your name? " << endl;
		cin >> name;
		getInfo();
		useTrick();
		cout << "Your weakness = " << weakness << endl;
	}
	int getWeakness() {
		return weakness;
	}
	~Zaochnik() {
	}
};
class ForeignStudent : virtual public NPC {
private:
	string trick[4] = { "work of another variant","say <<Sorry, dont speak English/Russian>>","say <<I'm from Egypt>>","<<Please, give me second chance>>"};
	int distanceFromHome;
public:
	string Lang;
	ForeignStudent() {
		student = false;
		zaochnik = false;
		foreignStudent = true;
		maxKuprin = false;

		health = 200;
		damage = 40;
		distanceFromHome = 3000;
		name = "ForeignStudent_NULL";
	}
	void useTrick() {
		cout << "Choose the trick for fight! " << endl;
		Sleep(500);
		cout << "Tricks list: " << endl;
		Sleep(500);
		int i = 0;
		for (; i < lvl; i++) {
			cout << i << " - " << trick[i] << endl;
		}
		cout << "Select your trick \t";
		cin >> i;
		while (i >= lvl) {
			cout << " This tool is unavailiable" << endl;
			cout << "Select other one" << endl;
			cin >> i;
		}
		cout << name << " get " << trick[i] << endl;
		this->damage = (log(i + 1) + 1) * damage;
	}
	void create() override {
		cout << "You created Foreign Student" << endl;
		cout << "What is your name? " << endl;
		cin >> name;
		getInfo();
		useTrick();
	}
	~ForeignStudent() {
	}
};
class MaxKuprin : public Student, public Zaochnik {
public:
	MaxKuprin() {
		student = false;
		zaochnik = false;
		foreignStudent = false;
		maxKuprin = true;

	}
	void create() override {
		cout << "You've created Max Kuprin" << endl;
		cout << "What is your name? " << endl;
		cin >> name;
		getInfo();
		getTool();
		useTrick();
	}
	~MaxKuprin() {
	}
};

class Evil : public NPC {
public:
	Evil() {
		name = "EvilEvent";
		damage = 30;
		health = 30;
	}
	Evil(string name) : Evil() {
		this->name = name;
	}

	Evil(string name, int health) : Evil(name) {
		this->health = health;
	}
	Evil(string name, int health, int damage) : Evil(name, health) {
		this->damage = damage;
	}
	void getInfo() {
		Sleep(500);
		cout << "\n**************************" << endl;
		cout << "You're meet " << name << endl;
		cout << "Damage of enemy = " << damage << endl;
		cout << "Health of enemy = " << health << endl;
		cout << "\n**************************" << endl;
		Sleep(500);
	}
	int getDamage(){
		return damage;
	}
	int getHealth() {
		return health;
	}
	void setHealth(int DeltaHealth) {
		if (DeltaHealth < 0) {
			this->health = 0;
		}
		else {
			this->health = DeltaHealth;
		}
	}
	string getName() {
		return name;
	}
	~Evil(){
	}
};
class Player : public NPC {
public:
	void create(NPC* player) {
		player->create();
	}
	void lvlUP(NPC* player, int value) {
		player->lvlUP(value);
	}
	void setHealth(NPC* player, int value) {
		player->setHealth(value);
	}
	void setDynamicHealth(NPC* player, int value) {
		player->setDynamicHealth(value);
	}
	void setDamage(NPC* player, int value) {
		player->setDamage(value);
	}
	void getInfo(NPC* player) {
		player->getInfo();
	}
	int getDamage(NPC* player) {
		return player->getDamage();
	}
	int getHealth(NPC* player) {
		return player->getHealth();
	}
	void healthUpdate(NPC* player) {
		player->healthUpdate();
	}
	void getTool(Student* player) {
		player->getTool();
	}
	void useTrick(Zaochnik* player) {
		player->useTrick();
	}
	void useTrick(ForeignStudent* player) {
		player->useTrick();
	}
};
