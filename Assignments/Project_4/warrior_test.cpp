//
//  warrior_test.cpp
//  CS120B - Project 4
//
//  Contains test cases for the below three classes
//
//	Warrior, which tests:
//	- default Warrior creation
//	- getters
//	- weapon_to_string
//	- setters
//	- custom Warrior creation
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
//	- weapon_to_string
//	- setters
//	- custom Commander creation
//	- [<<] operator override
//	- present_weapon method
//
//  Created by Mark Kulhowvick on 3/2/17
//  Copyright © 2017 Mark Kulhowvick. All rights reserved.
//

// Inclusions
#include "warrior.h"
#include "commander.h"
#include "personal_sword.h"
#include <iostream>
using namespace std;

// Test Functions
bool test_warrior_setters();
bool test_personal_sword_setters();
bool test_commander_setters();

int main() {
	// Buffer
	cout << endl;

	// Create Default Warrior
	cout << "> Creating Default Warrior" << endl;
	Warrior warrior;

	// Testing Getters for Warrior
	cout << "> Testing Getters and weapon_to_string for Default Warrior" << endl;
	cout << "   Name   : " << warrior.get_name() << endl;
	cout << "   Primary: " << warrior.get_primary() << " ---> " << warrior.weapon_to_string(warrior.get_primary()) << endl;
	cout << "   Offhand: " << warrior.get_offhand() << " ---> " << warrior.weapon_to_string(warrior.get_offhand()) << endl;
	cout << "   Health : " << warrior.get_hp() << endl;
	cout << "   Attack : " << warrior.get_atk() << endl;
	cout << "   Defense: " << warrior.get_def() << endl;
	cout << endl;

	// Testing Setters for Warrior
	cout << "> Testing Setters for Warrior" << endl;
	cout << "   The result of testing is: " << boolalpha << test_warrior_setters() << endl << endl;

	// Create Custom Warrior
	cout << "> Creating Custom Warrior" << endl;
	Warrior Samurai("Samurai", Katana, None, 25, 25, 25);

	// Testing [<<] Operator Override for Warrior
	cout << "> Testing [<<] Operator Override for Custom Warrior" << endl;
	cout << Samurai << endl;

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
	cout << endl;

	// Testing Setters for Commander
	cout << "> Testing Setters for Commander" << endl;
	cout << "   The result of testing is: " << boolalpha << test_commander_setters() << endl << endl;

	// Create Custom Warrior
	cout << "> Creating Custom Commander" << endl;
	Commander Napoleon("Napoleon", {Fancy, Basket, Metal, Circular, Thrusting}, Rapier, None, 40, 40, 20, 0.30);

	// Testing [<<] Operator Override for Commander
	cout << "> Testing [<<] Operator Override for Commander" << endl;
	cout << Napoleon << endl;

	// Testing get_sword and present_sword for Commander
	cout << "> Testing get_sword for Commander" << endl;
	cout << Napoleon.get_mysword() << endl;
	cout << "> Testing present_sword for Commander" << endl;
	cout << Napoleon.present_sword(Napoleon.get_mysword()) << endl;

	// Return
	return 0;
}

// Test Warrior Setters
bool test_warrior_setters() {
	bool passed = true;
	Warrior thief;
	// Test set_name
	thief.set_name("thief");
	if (thief.get_name() != "thief") {
		passed = false;
		cout << "   FAILED [NAME = thief] TEST CASE:   " << thief.get_name() << endl;
	}
	// Test set_hp
	thief.set_hp(15);
	if (thief.get_hp() != 15) {
		passed = false;
		cout << "   FAILED [HP = 15] TEST CASE:   " << thief.get_hp() << endl;
	}
	// Test set_atk
	thief.set_atk(25);
	if (thief.get_atk() != 25) {
		passed = false;
		cout << "   FAILED [ATK = 25] TEST CASE:   " << thief.get_atk() << endl;
	}
	// Test set_def
	thief.set_def(10);
	if (thief.get_def() != 10) {
		passed = false;
		cout << "   FAILED [DEF = 10] TEST CASE:   " << thief.get_def() << endl;
	}
	// Test set_primary
	thief.set_primary(Dagger);
	if (thief.get_primary() != Dagger) {
		passed = false;
		cout << "   FAILED [PRIMARY = Dagger] TEST CASE:   " << thief.get_primary() << endl;
	}
	// Test set_offhand
	thief.set_offhand(Dagger);
	if (thief.get_offhand() != Dagger) {
		passed = false;
		cout << "   FAILED [OFFHAND = Dagger] TEST CASE:   " << thief.get_offhand() << endl;
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

