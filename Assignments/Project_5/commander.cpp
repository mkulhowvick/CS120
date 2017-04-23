//
//  commander.cpp
//  CS120B - Project 5
//
//  Contains a Commander Child Class (of Warrior)
//
//	Commander:
//	- Create a default Commander
//	- Create a custom Commander
//	- Implicit Get: everything from the Warrior Class
//	- Implicit Set: everything from the Warrior Class
//	- New Getters: hp, atk, def, mysword, dodge_chance
//	- New Setters: hp, atk, def, mysword, dodge_chance
//	- calcCombatRatio: calculates ratios based on stats to reflect combat effectiveness
//	- Present Weapon:  displays a description of the components of the Personal_Sword
//	- Overloads: the [<<] operator to print a statsheet
//
//  Created by Mark Kulhowvick on 3/23/17
//  Copyright © 2017 Mark Kulhowvick. All rights reserved.
//

// Inclusions
#include "commander.h"
#include <iomanip>

// Commander Child Class
// Default Constructor
Commander::Commander() {
	name = "Commander";
	mysword = Personal_Sword(Fancy, Basket, Leather, Circular, Thrusting);
	primary = Longsword;
	offhand = Dagger;
	hp = 30;
	atk = 30;
	def = 30;
	dodge_chance = 0.50;
	atkRatio = 1.0;
	defRatio = 2.0;
}

// Non-Default Constructor
Commander::Commander(string name, Personal_Sword mysword, weapon primary, weapon offhand, int hp, int atk, int def, double dodge_chance) {
	set_name(name);
	set_mysword(mysword);
	set_primary(primary);
	set_offhand(offhand);
	set_hp(hp);
	set_atk(atk);
	set_def(def);
	set_dodge_chance(dodge_chance);
}

// Getters
double Commander::get_hp() const {
	return hp;
}
double Commander::get_atk() const {
	return atk;
}
double Commander::get_def() const {
	return def;
}
double Commander::get_dodge_chance() const {
	return dodge_chance;
}
Personal_Sword Commander::get_mysword() const {
	return mysword;
}

// Setters
void Commander::set_hp(int in_hp) {
	hp = in_hp;
	calcCombatRatios(atkRatio, defRatio);
}
void Commander::set_atk(int in_atk) {
	atk = in_atk;
	calcCombatRatios(atkRatio, defRatio);
}
void Commander::set_def(int in_def) {
	def = in_def;
	calcCombatRatios(atkRatio, defRatio);
}
void Commander::set_dodge_chance(double in_dodge) {
	dodge_chance = in_dodge;
}
void Commander::set_mysword(Personal_Sword in_mysword) {
	mysword = in_mysword;
}

// Combat Ratio Method
void Commander::calcCombatRatios(double &atkRatio, double &defRatio) {
	atkRatio = atk / def;
	defRatio = (def + hp) / atk;
}

// Present Weapon
string Commander::present_sword(Personal_Sword PS) const {
	string sword_description;
	// Pommel Description
	if (PS.pommel_to_string(PS.get_sword()) == "Basic") {
		sword_description += "   The pommel is simple, rounded steel with no embelishment. \n";
	} else if (PS.pommel_to_string(PS.get_sword()) == "Fancy") {
		sword_description += "   The pommel holds a gemstone, bounded by silver-inlaid steel. \n";
	}

	// Guard Description	
	if (PS.guard_to_string(PS.get_sword()) == "Cross") {
		sword_description += "   The guard is a straight crossbar, notched and well worn. \n";
	} else if (PS.guard_to_string(PS.get_sword()) == "Basket") {
		sword_description += "   The guard is a woven steel basket, well polished. \n";
	} else if (PS.guard_to_string(PS.get_sword()) == "Cup") {
		sword_description += "   The guard is a simple cup, well polished. \n";
	}

	// Grip Description	
	if (PS.grip_to_string(PS.get_sword()) == "Leather") {
		sword_description += "   The grip is leather, lightly oiled. Indented and fit to the owner's hand. \n";
	} else if (PS.grip_to_string(PS.get_sword()) == "Wood") {
		sword_description += "   The grip is wood, rustic. Smooth and polished to prevent splinters. \n";
	} else if (PS.grip_to_string(PS.get_sword()) == "Metal") {
		sword_description += "   The grip is woven metal wire. Prevents slipping, but hard to get used to. \n";
	}

	// Blade Shape Description	
	if (PS.blade_shape_to_string(PS.get_sword()) == "Straight") {
		sword_description += "   The blade is straight, standard for most soldiers. \n";
	} else if (PS.blade_shape_to_string(PS.get_sword()) == "Curved") {
		sword_description += "   The blade curves slightly in an eastern fashion. \n";
	} else if (PS.blade_shape_to_string(PS.get_sword()) == "Circular") {
		sword_description += "   The blade is rounded, not holding any actual edge on it's sides. \n";
	}

	// Blade Type Description
	if (PS.blade_type_to_string(PS.get_sword()) == "Single Bladed") {
		sword_description += "   It has one side, cutting one way. \n";
	} else if (PS.blade_type_to_string(PS.get_sword()) == "Double Bladed") {
		sword_description += "   It has two sides, providing many approaches to combat. \n";
	} else if (PS.blade_type_to_string(PS.get_sword()) == "Thrusting") {
		sword_description += "   It culminates to a point, meant for thrusting through weak points. \n";
	}

	// Return Description
	return sword_description;
}

// Output [<<] Operator Overload
ostream& operator << (ostream &display, Commander &C) {
	display << left << " | " << setw(15) << C.name
		<< " | PRIMARY = " << setw(10) << C.weapon_to_string(C.primary)
		<< " | OFFHAND = " << setw(11) << C.weapon_to_string(C.offhand) << " | "
		<< endl << " ------------------------------------------------------------------" << endl
		<< " | HP  = "   << setw(4) << C.hp
		<< " | ATK = "   << setw(5) << C.atk
		<< " | DEF = "   << setw(5) << C.def 
		<< " | DODGE CHANCE = " << setw(6) << C.dodge_chance << " |" << endl;
	return display;
}