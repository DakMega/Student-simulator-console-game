#pragma once
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

class NPC{// полиморфизм дублирует понятие перегрузки
	//индефикатор доступа public (- общедоступный ) protected pvivate
	//делигирование
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
		cout << "NPC created" << endl;
		health = 100;
		damage = 1;
		lvl = 1;
		dynamicHealth = 100;
	}
	virtual void getInfo() {
		cout << "**************************" << endl;
		cout << "Hello " << name << endl;
		cout << " Your damage = " << damage << endl;
		cout << " Your health = " << health << endl;
		cout << "**************************" << endl;
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
	void setDamage(int DeltaDamage) {
		this->damage = DeltaDamage;
	}
	void healthUpdate() {
		this->dynamicHealth = health;
	} // внимательно!
	void lvlUP(int value) {
		lvl += value;
		cout << "LVL UP to " << lvl << " !" << endl;
		this->health = health * (log(lvl) + 1);
		this->damage = damage * (log(lvl) + 1);
		this->dynamicHealth = health;
	}
	void sayDynamicHealth() {
		cout << name << " running health is " << dynamicHealth << endl;
	}
	virtual void create() {} //прототипная функция
	~NPC() {}
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
};
