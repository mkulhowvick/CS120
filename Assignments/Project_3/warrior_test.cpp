//
//  warrior_test.cpp
//  CS120B - Project 3
//
//  Contains test cases for the Warrior and Squad classes.
// 
//	Tests functionality of the following:
//	- Default Warrior Creation
//	- Warrior Getters
//	- Warrior Setters
//	- Custom Warrior Creation
//	- Custom Warrior Output Override
//	- Boosting Attack of a Warrior by +5
//	- Boosting Defense of a Warrior by +5
//	- Default Squad Creation
//	- Custom Squad Output Override
//	- Insertion of Warriors into a Squad
//	- Getters for a Squad
//	- Rallying Attack of a Squad by +5
//	- Rallying Defense of a Squad by +5
//	- Deletion of Warriors from a Squad
//
//  Created by Mark Kulhowivck on 2/2/20.
//  Copyright © 2017 Mark Kulhowvick, all rights reserved
//

// Inclusions
#include "warrior.h"
#include <iostream>
using namespace std;

// Test Functions
bool test_setters();

// Main
int main() {
	// Buffer
	cout << endl;

	// Test Default Warrior Creation
	cout << "> Creating Default Warrior" << endl;
	Warrior warrior;

	// Testing Getters for Warrior
	cout << "> Testing Getters for Custom Warrior" << endl;
	cout << "   Name: " << warrior.get_name() << endl;
	cout << "   Armor: " << warrior.get_armor() << endl;
	cout << "   Health: " << warrior.get_hp() << endl;
	cout << "   Attack: " << warrior.get_atk() << endl;
	cout << "   Defense: " << warrior.get_def() << endl;
	cout << endl;

	// Testing Setters for Warrior
	cout << "> Testing Setters" << endl;
	cout << "   The result of testing setters is: " << boolalpha << test_setters() << endl << endl;

	// Test Custom Warrior Creation
	cout << "> Creating Custom Warrior" << endl;
	Warrior Samurai("Samurai", "Heavy", 40, 10, 20);

	// Test Operator Override for Warrior
	cout << "> Testing [<< Operator] Override for Custom Warrior" << endl;
	cout << Samurai << endl;

	// Test Boost Attack Method
	cout << "> Testing Attack Boost on Custom Warrior" << endl;
	Samurai.boost_atk();
	cout << Samurai << endl;

	// Test Boost Defense Method
	cout << "> Testing Defense Boost on Custom Warrior" << endl;
	Samurai.boost_def();
	cout << Samurai << endl;

	// Test Default Squad creation
	cout << "> Creating Default Squad" << endl;
	Squad squad;

	// Test Operator Override for Squad
	cout << "> Testing [<< Operator] Override for Squad" << endl;
	cout << squad << endl;

	// Test Insertion of Warriors into Squad
	cout << "> Creating Additional Warriors for Squad" << endl;
	Warrior Berserker("Berserker", "Light", 50, 20, 10);
	Warrior Crusader("Crusader", "Heavy", 40, 15, 15);
	Warrior Assassin("Assassin", "Light", 30, 25, 10);
	cout << "> Inserting Warriors into Squad" << endl;
	squad.set_warrior(Samurai, 0);
	squad.set_warrior(Berserker, 1);
	squad.set_warrior(Crusader, 2);
	squad.set_warrior(Assassin, 3);

	// Test Getters for Squad
	cout << "> Testing Getters for Squad Members" << endl;
	cout << "> Getting First Member" << endl;
	cout << squad.get_warrior(0) << endl;
	cout << "> Getting Second Member" << endl;
	cout << squad.get_warrior(1) << endl;
	cout << "> Getting Third Member" << endl;
	cout << squad.get_warrior(2) << endl;
	cout << "> Getting Fourth Member" << endl;
	cout << squad.get_warrior(3) << endl;

	// Test Rally Attack Method
	cout << "> Testing Rally Attack on Squad" << endl;
	squad.rally_atk();
	cout << squad << endl;

	// Test Rally Defense Method
	cout << "> Testing Rally Defense on Squad" << endl;
	squad.rally_def();
	cout << squad << endl;

	// Test Deletion of Warriors from Squad
	Squad squad_1 = squad;
	cout << "> Removing First Member" << endl;
	squad_1.remove_warrior(0);
	cout << "> Displaying Updated Squad" << endl;
	cout << squad_1 << endl;

	cout << "> Reinitializing Squad" << endl;
	Squad squad_2 = squad;
	cout << "> Removing Second Member" << endl;
	squad_2.remove_warrior(1);
	cout << "> Displaying Updated Squad" << endl;
	cout << squad_2 << endl;

	cout << "> Reinitializing Squad" << endl;
	Squad squad_3 = squad;
	cout << "> Removing Third Member" << endl;
	squad_3.remove_warrior(2);
	cout << "> Displaying Updated Squad" << endl;
	cout << squad_3 << endl;

	cout << "> Reinitializing Squad" << endl;
	Squad squad_4 = squad;
	cout << "> Removing Fourth Member" << endl;
	squad_4.remove_warrior(3);
	cout << "> Displaying Updated Squad" << endl;
	cout << squad_4 << endl;

	// Return
	return 0;
} // END MAIN

// Test Setters
bool test_setters() {
	bool passed = true;
	Warrior Viking;
	Viking.set_name("Viking");
	if (Viking.get_name() != "Viking") {
		passed = false;
		cout << "FAILED [NAME = VIKING] TEST CASE:   " << Viking.get_name() << endl;
	}
	Viking.set_armor("Heavy");
	if (Viking.get_armor() != "Heavy") {
		passed = false;
		cout << "FAILED [ARMOR = HEAVY] TEST CASE:   " << Viking.get_armor() << endl;
	}
	Viking.set_hp(50);
	if (Viking.get_hp() != 50) {
		passed = false;
		cout << "FAILED [HP = 50] TEST CASE:   " << Viking.get_hp() << endl;
	}
	Viking.set_atk(35);
	if (Viking.get_atk() != 35) {
		passed = false;
		cout << "FAILED [ATK = 35] TEST CASE:   " << Viking.get_atk() << endl;
	}
	Viking.set_def(10);
	if (Viking.get_def() != 10) {
		passed = false;
		cout << "FAILED [DEF = 10] TEST CASE:   " << Viking.get_def() << endl;
	}
	// cout << "Done testing setters" << endl;
	return passed;
}