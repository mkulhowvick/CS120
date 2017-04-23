//
//  warrior.cpp
//  CS120B - Project 5
//
//  Contains a Warrior Parent Class
//
//	Warrior:
//	- Create a default Warrior, doesn't matter since the class is abstract
//	- Get: name, primary weapon from enums, offhand weapon from enums, atkRatio, defRatio
//	- Set: name, primary weapon from enums, offhand weapon from enums
//	- To_String: convert either the primary or offhand weapon from enums to string
//	- calcCombatRatio: calculates ratios based on stats to reflect combat effectiveness
//
//  Created by Mark Kulhowvick on 3/23/17
//  Copyright © 2017 Mark Kulhowvick. All rights reserved.
//

// Inclusions
#include "warrior.h"
#include <iostream>
#include <iomanip>

// Warrior Parent Class
// Default Constructor
Warrior::Warrior() {
	name = "";
	primary = None;
	offhand = None;
	atkRatio = 0.0;
	defRatio = 0.0;
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
double Warrior::get_atkRatio() const {
	return atkRatio;
}
double Warrior::get_defRatio() const {
	return defRatio;
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