#pragma once
#include "class.h"
#include <iostream>
#include <set>
#include <cmath>
class Evil : public NPC {
public:
	Evil() {
		name = "Zloday";
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
		cout << "You're meet " << name << endl;
		cout << "Damage of enemy = " << damage << endl;
		cout << "Health of enemy = " << health << endl;
	}
	int getDamage() {
		return damage;
	}
	void setHealth(int DeltaHealth) {
		this->health = DeltaHealth;
	}
	~Evil() {
	}
};
