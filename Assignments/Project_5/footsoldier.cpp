//
//  footsoldier.cpp
//  CS120B - Project 5
//
//  Contains a Footsoldier Child Class (of Warrior)
//
//	Footsoldier:
//	- Create a default Footsoldier
//	- Create a custom Footsoldier
//	- Implicit Get: everything from the Warrior Class
//	- Implicit Set: everything from the Warrior Class
//	- New Getters: hp, atk, def
//	- New Setters: hp, atk, def
//	- calcCombatRatio: calculates ratios based on stats to reflect combat effectiveness
//	- Present Weapon:  displays a description of the components of the Personal_Sword
//	- Overloads: the [<<] operator to print a statsheet
//
//  Created by Mark Kulhowvick on 3/23/17
//  Copyright © 2017 Mark Kulhowvick. All rights reserved.
//

// Inclusions
#include "footsoldier.h"
#include <iomanip>

// Footsoldier Child Class
// Default Constructor
Footsoldier::Footsoldier() {
	name = "Footsoldier";
	primary = Spear;
	offhand = Small_Shield;
	hp = 25;
	atk = 10;
	def = 15;
	atkRatio = 0.66667;
	defRatio = 4.0;
}

// Non-Default Constructor
Footsoldier::Footsoldier(string name, weapon primary, weapon offhand, int hp, int atk, int def) {
	set_name(name);
	set_primary(primary);
	set_offhand(offhand);
	set_hp(hp);
	set_atk(atk);
	set_def(def);
}

// Getters
double Footsoldier::get_hp() const {
	return hp;
}
double Footsoldier::get_atk() const {
	return atk;
}
double Footsoldier::get_def() const {
	return def;
}

// Setters
void Footsoldier::set_hp(int in_hp) {
	hp = in_hp;
	calcCombatRatios(atkRatio, defRatio);
}
void Footsoldier::set_atk(int in_atk) {
	atk = in_atk;
	calcCombatRatios(atkRatio, defRatio);
}
void Footsoldier::set_def(int in_def) {
	def = in_def;
	calcCombatRatios(atkRatio, defRatio);
}

// Combat Ratio Method
void Footsoldier::calcCombatRatios(double &atkRatio, double &defRatio) {
	atkRatio = atk / def;
	defRatio = (def + hp) / atk;
}

// Output [<<] Operator Overload
ostream& operator << (ostream &display, Footsoldier &F) {
	display << left << " | " << setw(20) << F.name << " | HP  = " << setw(3) << F.hp << " |"
		<< endl << " ------------------------------------" << endl
		<< " | PRIMARY = " << setw(10) << F.weapon_to_string(F.primary) << " | ATK = " << setw(3) << F.atk << " |"
		<< endl << " ------------------------------------" << endl
		<< " | OFFHAND = " << setw(10) << F.weapon_to_string(F.offhand) << " | DEF = " << setw(3) << F.def << " |"
		<< endl;
	return display;
}