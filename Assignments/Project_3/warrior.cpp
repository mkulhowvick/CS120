//
//  warrior.cpp
//  CS120B - Project 3
//
//	Contains two classes, Warrior and Squad
//  
//	Warrior:
//  - Create a default warrior
//  - Create a custom warrior
//  - Set and Get: Name/Armor_Class/Health/Attack/Defense
//  - Boost: Attack and Defense by +5
//  - Overloads: the [<< operator] to print a Warrior "statsheet"
//	
//	Squad:
//  - Create a squad of 4 default warriors
//  - Insert custom warriors into the squad
//  - Set custom warriors as [index i] in a squad
//	- Get custom warriors from [index i] in a squad
//	- Remove custom warriors from [index i] in a squad
//  - Rally: Attack and Defense of all Squad members by +5
//  - Overloads: the [<< operator] to print a Squad "statsheet"
//
//  Created by Mark Kulhowivck on 2/2/20.
//  Copyright © 2017 Mark Kulhowvick, all rights reserved
//

// Inclusions
#include "warrior.h"
#include <iomanip>
#include <iostream>

// Warrior Class
// Default Constructor
Warrior::Warrior() {
	name = "Name";
	armor = "Armor";
	hp = 0;
	atk = 0;
	def = 0;
}

// Constructor
Warrior::Warrior(string name, string armor, int hp, int atk, int def) {
	set_name(name);
	set_armor(armor);
	set_hp(hp);
	set_atk(atk);
	set_def(def);
}

// Deconstructor
Warrior::~Warrior() {
}

// Getters
string Warrior::get_name() const {
	return name;
}
string Warrior::get_armor() const {
	return armor;
}
int Warrior::get_hp() const {
	return hp;
}
int Warrior::get_atk() const {
	return atk;
}
int Warrior::get_def() const {
	return def;
}

// Setters
void Warrior::set_name(string in_name) {
	name = in_name;
}
void Warrior::set_armor(string in_armor) {
	armor = in_armor;
}
void Warrior::set_hp(int in_hp) {
	hp = in_hp;
}
void Warrior::set_atk(int in_atk) {
	atk = in_atk;
}
void Warrior::set_def(int in_def) {
	def = in_def;
}

// Boost Attack/Defense
void Warrior::boost_atk() {
	atk += 5;
}
void Warrior::boost_def() {
	def += 5;
}

// Overloads
ostream& operator << (ostream &display, Warrior &w) {
	display << setw(10) << w.name	<< " | "
			<< setw(5)	<< w.armor << " | HP = " 
			<< setw(2)	<< w.hp		<< " | ATK = " 
			<< setw(2)	<< w.atk	<< " | DEF = "
			<< setw(2)	<< w.def	<< " |" << endl;
	return display;
}

// Squad Class
// Default Constructor
Squad::Squad() {
	for (int i = 0; i < 4; i++) {
		warrior.push_back(Warrior());
	}
}

// Setters
void Squad::set_warrior(Warrior w, int i) {
	warrior[i] = w;
}

// Getters
Warrior Squad::get_warrior(int i) {
	return warrior[i];
}

// Remove Warrior
void Squad::remove_warrior(int i){
	warrior.erase(warrior.begin() + i);
}

// Rally Attack/Defense
void Squad::rally_atk() {
	for (int i = 0; i < warrior.size(); i++) {
		warrior[i].boost_atk();
	}
}
void Squad::rally_def() {
	for (int i = 0; i < warrior.size(); i++) {
		warrior[i].boost_def();
	}
}

// Overloads
ostream& operator << (ostream &display, Squad &s) {
	cout << setw(10) << "Name"	  << " |"
		 << setw(6)  << "Armor"   << " |"
		 << setw(8)  << "Health"  << " |"
		 << setw(9)  << "Attack " << " |"
		 << setw(9)  << "Defense" << " |" << endl;
	cout << " ---------------------------------------------------" << endl;
	for (int i = 0; i < s.warrior.size(); i++) {
		display << s.warrior[i];
	}
	return display;
}