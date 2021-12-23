#pragma once
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

class NPC{// полиморфизм дублирует понятие перегрузки
	//индефикатор доступа public (- общедоступный ) protected pvivate
	//делигирование
protected:
	bool warrior;
	bool wizard;
	bool paladin;
	bool programmer;
	bool technic;
	bool evil;
	bool player;
	int health;
	int dynamicHealth;
	int damage;
	int lvl;
	string name;
public:
	NPC() {
		warrior = false;
		wizard = false;
		programmer = false;
		paladin = false;
		technic = false;
		evil = false;
		cout << "NPC created" << endl;
		health = 100;
		damage = 1;
		lvl = 1;
		dynamicHealth = 100;
	}
	virtual void getInfo() {
		/*cout << "**************************" << endl;
		cout << "Hello " << name << endl;
		cout << " Your damage = " << damage << endl;
		cout << " Your health = " << health << endl;
		cout << "**************************" << endl;*/
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
class Warrior : virtual public Player {
private:
	int strength;
public:
	string weapons[5] = { "fists","knife","sword","pistol","rifle" };
	Warrior() {
		warrior = true;
		wizard = false;
		programmer = false;
		paladin = false;
		technic = false;
		health = 150;
		damage = 30;
		strength = 50;
		name = "Warrior_NULL";
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
		cout << "You are created Warrior" << endl;
		cout << "What is your name? " << endl;
		cin >> name;
		getInfo();
		cout << "Your strength = "<< strength << endl;
		getWeapon();
	}
	~Warrior() {
	}
};
class Wizard : virtual public Player {
private:
	int mana;
public:
	string spell[5] = { "fireball","aura boost","thorn hit","ice shield","earthquake"};
	Wizard() {
		warrior = false;
		wizard = true;
		programmer = false;
		paladin = false;
		technic = false;
		health = 100;
		damage = 40;
		mana = 50;
		name = "Wizard_NULL";
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
		cout << "You are created Wizard" << endl;
		cout << "What is your name? " << endl;
		cin >> name;
		getInfo();
		cout << "Your mana = " << mana << endl;
	}
	int getMana() {
		return mana;
	}
	~Wizard() {
	}
};
class Programmer : virtual public Player {
private:
	int skill;
	int age;
	bool wizardry;
public:
	bool senior;
	string codeLang;
	Programmer() {
		warrior = false;
		wizard = false;
		programmer = true;
		paladin = false;
		technic = false;
		health = 100;
		damage = 40;
		skill = 1000;
		age = 32;
		senior = true;
		wizardry = ((age > 29) && (senior)) ? true : false;
		name = "Programmer_NULL";
	}
	void useCode() {
		cout << "Select coding language to use " << endl;
		cin >> codeLang;
		cout << name << " uses " << codeLang << endl;
	}
	void create() override {
		cout << "You created Programmer" << endl;
		cout << "What is your name? " << endl;
		cin >> name;
		getInfo();
	}
	int getSkill() {
		return(skill);
	}
	~Programmer() {
	}
};
class Paladin : public Warrior, public Wizard {
public:
	Paladin() {
		warrior = false;
		wizard = false;
		programmer = false;
		paladin = true;
		technic = false;
	}
	void create() override {
		cout << "You've created Paladin" << endl;
		cout << "What is your name? " << endl;
		cin >> name;
		getInfo();
		getWeapon();
		castSpell();
	}
	~Paladin() {
	}
};
class Technic : public Paladin, Programmer {
public:
	Technic() {
		warrior = false;
		wizard = false;
		programmer = false;
		paladin = false;
		technic = true;
	}
	void create() override {
		cout << "You've created Technic" << endl;
		cout << "What is your name? " << endl;
		cin >> name;
		getInfo();
		getWeapon();
		castSpell();
		useCode();
	}
	~Technic() {
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
	/*void getInfo(NPC* player) {
		player->getInfo();
	}*/
	int getDamage(NPC* player) {
		return player->getDamage();
	}
	int getHealth(NPC* player) {
		return player->getHealth();
	}
	virtual void getInfo() {
		cout << "**************************" << endl;
		cout << "Hello " << name << endl;
		cout << " Your damage = " << damage << endl;
		cout << " Your health = " << health << endl;
		cout << "**************************" << endl;
	}
};