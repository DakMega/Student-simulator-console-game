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
class Student : virtual public NPC {
private:
	int strength;
public:
	string weapons[3] = { "studak","zachetka","teoretical mechanics"};
	Student() {
		student = true;
		zaochnik = false;
		foreignStudent = false;
		maxKuprin = false;

		health = 150;
		damage = 30;
		strength = 50;
		name = "Student_NULL";
	}
	void getWeapon() {
		cout << "Weapons list: " << endl;
		int i = 0;
		for (; i < lvl; i++) {
			cout << i << " - " << weapons[i] << endl;
		}
		cout << "Select your weapon \t";
		cin >> i;
		while (i >= lvl) {
			cout << " This weapon is unavailiable" << endl;
			cout << "Select other one" << endl;
			cin >> i;
		}
		cout << name << " get " << weapons[i] << endl;
	}
	void create() override {
		cout << "You are created Student" << endl;
		cout << "What is your name? " << endl;
		cin >> name;
		getInfo();
		cout << "Your strength = "<< strength << endl;
		getWeapon();
	}
	~Student() {
	}
};
class Zaochnik : virtual public NPC {
private:
	int mana;
public:
	string spell[5] = { "fireball","aura boost","thorn hit","ice shield","earthquake"};
	Zaochnik() {
		student = false;
		zaochnik = true;
		foreignStudent = false;
		maxKuprin = false;

		health = 100;
		damage = 40;
		mana = 50;
		name = "Zaochnik_NULL";
	}
	void castSpell() {
		cout << "Select spell " << endl;
		int spellNum;
		cin >> spellNum ;
		cout << name << " uses " << spell[spellNum] << endl;
	}
	void learn() {
		cout << "What spell you want to learn? " << endl;
		cout << "Spells list: " << endl;
		int i = 0;
		for (; i < lvl; i++) {
			cout << i << " - " << spell[i] << endl;
		}
		cout << "Select spell \t";
		cin >> i;
		while (i >= lvl) {
			cout << " This spell is unavailiable" << endl;
			cout << "Select other one" << endl;
			cin >> i;
		}
		cout << name << " get " << spell[i] << endl;
		cout << name << " learned " << spell[i] << endl;
	}
	void create() override {
		cout << "You are created Zaochnik" << endl;
		cout << "What is your name? " << endl;
		cin >> name;
		getInfo();
		cout << "Your mana = " << mana << endl;
	}
	int getMana() {
		return mana;
	}
	~Zaochnik() {
	}
};
class ForeignStudent : virtual public NPC {
private:
	int skill;
	int age;
	bool zaochnik;
public:
	bool senior;
	string codeLang;
	ForeignStudent() {
		student = false;
		zaochnik = false;
		foreignStudent = true;
		maxKuprin = false;

		health = 100;
		damage = 40;
		skill = 1000;
		age = 32;
		senior = true;
		zaochnik = ((age > 29) && (senior)) ? true : false;
		name = "ForeignStudent_NULL";
	}
	void useCode() {
		cout << "Select coding language to use " << endl;
		cin >> codeLang;
		cout << name << " uses " << codeLang << endl;
	}
	void create() override {
		cout << "You created Foreign Student" << endl;
		cout << "What is your name? " << endl;
		cin >> name;
		getInfo();
	}
	int getSkill() {
		return(skill);
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
		getWeapon();
		castSpell();
	}
	~MaxKuprin() {
	}
};

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
	int getDamage(){
		return damage;
	}
	void setHealth(int DeltaHealth) {
		this->health = DeltaHealth;
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
