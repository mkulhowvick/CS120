//
//  warrior_test.cpp
//  CS120B - Project 5
//
//  Contains test cases for the below four classes
//
//	Warrior, which tests:
//	- nothing, abstract class --> implicit tests by the children
//
//	Footsoldier, which tests:
//	- default Footsoldier creation
//	- getters
//	- calcCombatRatio
//	- weapon_to_string
//	- setters
//	- custom Footsoldier creation
//	- [<<] operator override
//
//	Personal_Sword, which tests:
//	- default Personal_Sword creation
//	- getters
//	- all enums *_to_string
//	- setters
//	- custom Personal_Sword creation
//	- [<<] operator override
//
//	Commander, which tests:
//	- default Commander creation
//	- getters
//	- calcCombatRatio
//	- weapon_to_string
//	- setters
//	- custom Commander creation
//	- [<<] operator override
//	- present_weapon method
//
//	Also tests pointers for Warrior/Footsoldier/Commander.
//
//  Created by Mark Kulhowvick on 3/23/17
//  Copyright © 2017 Mark Kulhowvick. All rights reserved.
//

// Inclusions
#include "warrior.h"
#include "footsoldier.h"
#include "commander.h"
#include "personal_sword.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
using namespace std;

// Test Functions
bool test_footsoldier_setters();
bool test_personal_sword_setters();
bool test_commander_setters();

int main() {
	// Buffer
	cout << endl;

	// Divider Block
	cout << "******************************************************************************" << endl << endl;

	// Testing Default Footsoldier
	cout << "> Creating Default Footsoldier" << endl;
	Footsoldier footsoldier;

	// Testing Standard Getters for Footsoldier
	cout << "> Testing Getters and weapon_to_string for Default Footsoldier" << endl;
	cout << "   Name   : " << footsoldier.get_name() << endl;
	cout << "   Primary: " << footsoldier.get_primary() << " ---> " << footsoldier.weapon_to_string(footsoldier.get_primary()) << endl;
	cout << "   Offhand: " << footsoldier.get_offhand() << " ---> " << footsoldier.weapon_to_string(footsoldier.get_offhand()) << endl;
	cout << "   Health : " << footsoldier.get_hp() << endl;
	cout << "   Attack : " << footsoldier.get_atk() << endl;
	cout << "   Defense: " << footsoldier.get_def() << endl;
	cout << "   atkRatio: " << footsoldier.get_atkRatio() << endl;
	cout << "   defRatio: " << footsoldier.get_defRatio() << endl;
	cout << endl;

	// Testing Setters for Footsoldier
	cout << "> Testing Setters for Footsoldier" << endl;
	cout << "   The result of testing is: " << boolalpha << test_footsoldier_setters() << endl << endl;

	// Testing getAtkRatio and getDefRatio for Footsoldier
	cout << "> Testing getAtkRatio and getDefRatio for Footsoldier" << endl;
	cout << "> Changing hp, atk, and def values to --> 15/25/15" << endl;
	footsoldier.set_hp(15);
	footsoldier.set_atk(25);
	footsoldier.set_def(15);
	cout << "> Displaying new atkRatio and defRatio" << endl;
	cout << "   atkRatio: " << footsoldier.get_atkRatio() << endl;
	cout << "   defRatio: " << footsoldier.get_defRatio() << endl;
	cout << endl;
	
	// Create Custom Footsoldier
	cout << "> Creating Custom Footsoldier" << endl;
	Footsoldier longbowman("Longbowman", Longbow, None, 20, 30, 10);

	// Testing [<<] Operator Override for Custom Commander
	cout << "> Testing [<<] Operator Override for Custom Footsoldier" << endl;
	cout << longbowman << endl;

	// Divider Block
	cout << "******************************************************************************" << endl << endl;

	// Create Default Personal Sword
	cout << "> Creating Default Personal Sword" << endl;
	Personal_Sword sword;

	// Testing Getters for Personal Sword
	cout << "> Testing Getters and all enums *_to_string for Personal_Sword" << endl;
	cout << "   Pommel: " << sword.get_pommel() << " ---> "  << sword.pommel_to_string(sword.get_sword()) << endl;
	cout << "   Guard : " << sword.get_guard() << " ---> " << sword.guard_to_string(sword.get_sword()) << endl;
	cout << "   Grip  : " << sword.get_grip() << " ---> " << sword.grip_to_string(sword.get_sword()) << endl;
	cout << "   Blade Shape : " << sword.get_blade_shape() << " ---> " << sword.blade_shape_to_string(sword.get_sword()) << endl;
	cout << "   Blade Type  : " << sword.get_blade_type() << " ---> " << sword.blade_type_to_string(sword.get_sword()) << endl;
	cout << endl;

	// Testing Setters for Personal Sword
	cout << "> Testing Setters for Personal Sword" << endl;
	cout << "   The result of testing is: " << boolalpha << test_personal_sword_setters() << endl << endl;

	// Create Custom Personal Sword
	cout << "> Creating Custom Personal Sword" << endl;
	Personal_Sword scimitar(Fancy, Basket, Wood, Curved, Single_Bladed);

	// Testing [<<] Operator Override for Personal Sword
	cout << "> Testing [<<] Operator Override for Personal Sword" << endl;
	cout << scimitar << endl;

	// Divider Block
	cout << "******************************************************************************" << endl << endl;

	// Testing Default Commander
	cout << "> Creating Default Commander" << endl;
	Commander commander;

	// Testing Standard Getters for Commander
	cout << "> Testing Getters and weapon_to_string for Default Commander" << endl;
	cout << "   Name   : " << commander.get_name() << endl;
	cout << "   Primary: " << commander.get_primary() << " ---> " << commander.weapon_to_string(commander.get_primary()) << endl;
	cout << "   Offhand: " << commander.get_offhand() << " ---> " << commander.weapon_to_string(commander.get_offhand()) << endl;
	cout << "   Health : " << commander.get_hp() << endl;
	cout << "   Attack : " << commander.get_atk() << endl;
	cout << "   Defense: " << commander.get_def() << endl;
	cout << "   Dodge  : " << commander.get_dodge_chance() << endl;
	cout << "   atkRatio: " << commander.get_atkRatio() << endl;
	cout << "   defRatio: " << commander.get_defRatio() << endl;
	cout << endl;

	// Testing Setters for Commander
	cout << "> Testing Setters for Commander" << endl;
	cout << "   The result of testing is: " << boolalpha << test_commander_setters() << endl << endl;

	// Testing getAtkRatio and getDefRatio for Commander
	cout << "> Testing getAtkRatio and getDefRatio for Commander" << endl;
	cout << "> Changing hp, atk, and def values to --> 40/20/40" << endl;
	commander.set_hp(40);
	commander.set_atk(20);
	commander.set_def(40);
	cout << "> Displaying new atkRatio and defRatio" << endl;
	cout << "   atkRatio: " << commander.get_atkRatio() << endl;
	cout << "   defRatio: " << commander.get_defRatio() << endl;
	cout << endl;

	// Create Custom Commander
	cout << "> Creating Custom Commander" << endl;
	Commander Napoleon("Napoleon", {Fancy, Basket, Metal, Circular, Thrusting}, Rapier, None, 40, 40, 20, 0.30);

	// Testing [<<] Operator Override for Custom Commander
	cout << "> Testing [<<] Operator Override for Custom Commander" << endl;
	cout << Napoleon << endl;

	// Testing get_sword and present_sword for Custom Commander
	cout << "> Testing get_sword for Custom Commander" << endl;
	cout << Napoleon.get_mysword() << endl;
	cout << "> Testing present_sword for Custom Commander" << endl;
	cout << Napoleon.present_sword(Napoleon.get_mysword()) << endl;

	// Divider Block
	cout << "******************************************************************************" << endl << endl;

	// Testing vector of pointers for Warrior, Footsoldier and Commander
	cout << "> Testing vector of pointers for Warrior, Footsoldier and Commander" << endl;
	cout << "> Creating vector of Warrior Pointers" << endl;
	vector<unique_ptr<Warrior>> myWarriors;
	cout << "> Pushing back Footsoldier and Commander onto the vector" << endl;
	myWarriors.push_back(make_unique<Footsoldier>());
	myWarriors.push_back(make_unique<Commander>());
	cout << "> Iterating through accessing the weapons for the vector" << endl;
	for (int i = 0; i < myWarriors.size(); ++i) {
		cout << "   Primary for " << setw(14) << myWarriors[i]->get_name() << ": " << setw(2) << myWarriors[i]->get_primary() << " ---> " << myWarriors[i]->weapon_to_string(myWarriors[i]->get_primary()) << endl;
		cout << "   Offhand for " << setw(14) << myWarriors[i]->get_name() << ": " << setw(2) << myWarriors[i]->get_offhand() << " ---> " << myWarriors[i]->weapon_to_string(myWarriors[i]->get_offhand()) << endl;
	}
	cout << endl;

	// Divider Block
	cout << "******************************************************************************" << endl;

	// Buffer
	cout << endl;

	// Return
	return 0;
}

// Test Commander Setters
bool test_footsoldier_setters() {
	bool passed = true;
	Footsoldier hoplite;
	// Test set_name
	hoplite.set_name("Hoplite");
	if (hoplite.get_name() != "Hoplite") {
		passed = false;
		cout << "   FAILED [NAME = Hoplite] TEST CASE:   " << hoplite.get_name() << endl;
	}
	// Test set_hp
	hoplite.set_hp(30);
	if (hoplite.get_hp() != 30) {
		passed = false;
		cout << "   FAILED [HP = 30] TEST CASE:   " << hoplite.get_hp() << endl;
	}
	// Test set_atk
	hoplite.set_atk(10);
	if (hoplite.get_atk() != 10) {
		passed = false;
		cout << "   FAILED [ATK = 10] TEST CASE:   " << hoplite.get_atk() << endl;
	}
	// Test set_def
	hoplite.set_def(20);
	if (hoplite.get_def() != 20) {
		passed = false;
		cout << "   FAILED [DEF = 20] TEST CASE:   " << hoplite.get_def() << endl;
	}
	// Test set_primary
	hoplite.set_primary(Longsword);
	if (hoplite.get_primary() != Longsword) {
		passed = false;
		cout << "   FAILED [PRIMARY = Longsword] TEST CASE:   " << hoplite.get_primary() << endl;
	}
	// Test set_offhand
	hoplite.set_offhand(Small_Shield);
	if (hoplite.get_offhand() != Small_Shield) {
		passed = false;
		cout << "   FAILED [OFFHAND = Small_Shield] TEST CASE:   " << hoplite.get_offhand() << endl;
	}
	return passed;
}

// Test Personal_Sword Setters
bool test_personal_sword_setters() {
	bool passed = true;
	Personal_Sword epee;
	// Test set_sword
	epee.set_sword(Basic, Cup, Metal, Circular, Thrusting);
	if (epee.get_pommel() != Basic) {
		passed = false;
		cout << "   FAILED [POMMEL = Basic] TEST CASE:   " << epee.get_pommel() << endl;
	}
	if (epee.get_guard() != Cup) {
		passed = false;
		cout << "   FAILED [GUARD = Cup] TEST CASE:   " << epee.get_guard() << endl;
	}
	if (epee.get_grip() != Metal) {
		passed = false;
		cout << "   FAILED [GRIP = Metal] TEST CASE:   " << epee.get_grip() << endl;
	}
	if (epee.get_blade_shape() != Circular) {
		passed = false;
		cout << "   FAILED [BLADE_SHAPE = Circular] TEST CASE:   " << epee.get_blade_shape() << endl;
	}
	if (epee.get_blade_type() != Thrusting) {
		passed = false;
		cout << "   FAILED [BLADE_TYPE = Thrusting] TEST CASE:   " << epee.get_blade_type() << endl;
	}
	return passed;
}

// Test Commander Setters
bool test_commander_setters() {
	bool passed = true;
	Commander captain;
	// Test set_dodge
	captain.set_dodge_chance(0.75);
	if (captain.get_dodge_chance() != 0.75) {
		passed = false;
		cout << "   FAILED [BLOCK = 0.75] TEST CASE:   " << captain.get_dodge_chance() << endl;
	}
	// Test set_mysword
	captain.set_mysword({Fancy, Basket, Wood, Curved, Double_Bladed});
	if (captain.get_mysword().get_pommel() != Fancy) {
		passed = false;
		cout << "   FAILED [MYSWORD POMMEL = {Fancy}] TEST CASE:   " << endl;
	} else if (captain.get_mysword().get_guard() != Basket) {
		passed = false;
		cout << "   FAILED [MYSWORD GUARD = {Basket}] TEST CASE:   " << endl;
	} else if (captain.get_mysword().get_grip() != Wood) {
		passed = false;
		cout << "   FAILED [MYSWORD GRIP= {Wood}] TEST CASE:   " << endl;
	} else if (captain.get_mysword().get_blade_shape() != Curved) {
		passed = false;
		cout << "   FAILED [MYSWORD BLADE_SHAPE= {Curved}] TEST CASE:   " << endl;
	} else if (captain.get_mysword().get_blade_type() != Double_Bladed) {
		passed = false;
		cout << "   FAILED [MYSWORD BLADE_TYPE= {Double_Bladed}] TEST CASE:   " << endl;
	}
	return passed;
}

