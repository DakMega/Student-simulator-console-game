#pragma once
#include "class.h"
#include <iostream>
#include <set>
#include <cmath>
class Student : virtual public NPC {
private:
	int strength;
public:
	string weapons[3] = { "studak","zachetka","teoretical mechanics" };
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
		cout << "Your strength = " << strength << endl;
		getWeapon();
	}
	~Student() {
	}
};
class Zaochnik : virtual public NPC {
private:
	int mana;
public:
	string spell[5] = { "fireball","aura boost","thorn hit","ice shield","earthquake" };
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
		cin >> spellNum;
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
