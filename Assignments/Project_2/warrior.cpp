//
//  warrior.cpp
//  CS 120 B - Project 2
//
//	Contains a class for Warriors with Name, Attack, Defense, and Health
//  Contains capabilities to Boost Attack by 5, and compare Attack, Defense, or Health
//
//  Created by Mark Kulhowvick on 2/8/2017
//  Copyright © 2017 Mark Kulhowvick. All rights reserved.
//

// Inclusions
#include "warrior.h"
#include <iomanip>

// Constructor
Warrior::Warrior() {
	name = "Ronin";
	atk = 10;
	def = 10;
	hp = 15;
}

// Deconstructor
Warrior::~Warrior() {
}

// Get Name
string Warrior::get_name() {
	return name;
}

// Get Attack
int Warrior::get_atk() {
	return atk;
}

// Get Defense
int Warrior::get_def() {
	return def;
}

// Get Health Points
int Warrior::get_hp() {
	return hp;
}

// Set Name
void Warrior::set_name(string in_name) {
	name = in_name;
}

// Set Attack
void Warrior::set_atk(int in_atk) {
	atk = in_atk;
}

// Set Defense
void Warrior::set_def(int in_def) {
	def = in_def;
}

// Set Health Points
void Warrior::set_hp(int in_hp) {
	hp = in_hp;
}

// Boost Attack
void Warrior::boost_atk() {
	atk += 5;
}

// Overload Operator <<
ostream& operator << (ostream &display, Warrior &warrior) {
	display << setw(10) << warrior.name << " | ATK = " << setw(2) << warrior.atk << " | DEF = " << setw(2) << warrior.def << " | HP = " << setw(2) << warrior.hp << endl;
	return display;
}

// Overload Operator >
bool operator > (Warrior &lhs, Warrior &rhs) {
	if (lhs > rhs) {
		return true;
	} else {
		return false;
	}
}

// Overload Operator <
bool operator < (Warrior &lhs, Warrior &rhs) {
	if (lhs < rhs) {
		return true;
	} else {
		return false;
	}
}