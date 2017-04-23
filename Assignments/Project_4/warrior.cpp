//
//  warrior.cpp
//  CS120B - Project 4
//
//  Contains a Warrior Parent Class
//
//	Warrior:
//	- Create a default Warrior
//	- Create a custom Warrior
//	- Get: name, primary weapon from enums, offhand weapon from enums, HP, ATK, DEF
//	- Set: name, primary weapon from enums, offhand weapon from enums, HP, ATK, DEF
//	- To_String: convert either the primary or offhand weapon from enums to string
//	- Overloads: the [<<] operator to print a Warrior "infosheet"
//
//  Created by Mark Kulhowvick on 3/2/17
//  Copyright © 2017 Mark Kulhowvick. All rights reserved.
//

// Inclusions
#include "warrior.h"
#include <iostream>
#include <iomanip>

// Warrior Parent Class
// Default Constructor
Warrior::Warrior() {
	name = "Warrior";
	primary = Longsword;
	offhand = Small_Shield;
	hp = 20;
	atk = 20;
	def = 15;
}

// Constructor
Warrior::Warrior(string name, weapon primary, weapon offhand, int hp, int atk, int def) {
	set_name(name);
	set_primary(primary);
	set_offhand(offhand);
	set_hp(hp);
	set_atk(atk);
	set_def(def);
}

// Getters
string Warrior::get_name() const {
	return name;
}
weapon Warrior::get_primary() const{
	return primary;
}
weapon Warrior::get_offhand() const {
	return offhand;
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
void Warrior::set_primary(weapon in_primary) {
	primary = in_primary;
}
void Warrior::set_offhand(weapon in_offhand) {
	offhand = in_offhand;
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

// Weapon ---> String
string Warrior::weapon_to_string(weapon w) const {
	switch (w) {
		case None: return "None";
		case Dagger: return "Dagger";
		case Longsword: return "Longsword";
		case Greatsword: return "Greatsword";
		case Katana: return "Katana";
		case Rapier: return "Rapier";
		case Axe: return "Axe";
		case Greataxe: return "Greataxe";
		case Spear: return "Spear";
		case Halberd: return "Halberd";
		case Longbow: return "Longbow";
		case Shortbow: return "Shortbow";
		case Crossbow: return "Crossbow";
		case Hand_Crossbow: return "Hand_Crossbow";
		case Small_Shield: return "Small Shield";
		case Tower_Shield: return "Tower Shield";
	}
}

// Output [<<] Operator Overload
ostream& operator << (ostream &display, Warrior &W) {
	display << left << " | " << setw(15) << W.name 
			<< " | PRIMARY = " << setw(10) << W.weapon_to_string(W.primary)
			<< " | OFFHAND = " << setw(11) << W.weapon_to_string(W.offhand) << " | " 
			<< endl	<< " ------------------------------------------------------------------"  << endl
			<< " | HP  = " << setw(9)  << W.hp 
			<< " | ATK = " << setw(14) << W.atk  
			<< " | DEF = " << setw(15) << W.def  << " |" << endl;
	return display;
}