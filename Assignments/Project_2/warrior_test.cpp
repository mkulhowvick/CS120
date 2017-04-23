//
//  warrior_test.cpp
//  CS 120 B - Project 2
//
//	Test file for the Warrior Class
//
//  Created by Mark Kulhowvick on 2/8/2017
//  Copyright © 2017 Mark Kulhowvick. All rights reserved.
//

// Inclusions
#include "warrior.h"
#include <iostream>

// Test Functions
bool test_setters();
bool test_boost_atk();

int main(){
	// Setup First Warrior, Test Getters
	Warrior Ronin;
	cout << "   Name: " << Ronin.get_name() << endl;
	cout << "   Attack: " << Ronin.get_atk() << endl;
	cout << "   Defense: " << Ronin.get_def() << endl;
	cout << "   Health: " << Ronin.get_hp() << endl;
	cout << endl;

	// Test Setters
	cout << "   The result of testing setters is: " << boolalpha << test_setters() << endl << endl;

	// Test Boost Attack
	cout << "   The result of testing boost_attack is: " << boolalpha << test_boost_atk() << endl << endl;

	// Setup Second Warrior
	Warrior Viking;
	Viking.set_name("Viking");
	Viking.set_atk(15);
	Viking.set_def(5);
	Viking.set_hp(20);

	// Test Operator Override <<
	cout << Ronin;
	cout << Viking;
	cout << endl;

	// Test Operator Override >
	cout << "   Is Ronin's Attack greater than Viking's Attack? ";
	cout << (Ronin.get_atk() > Viking.get_atk()) << endl;
	cout << "   Is Viking's Attack greater than Ronin's Attack? ";
	cout << (Viking.get_atk() > Ronin.get_atk()) << endl;

	// Test Operator Override <
	cout << "   Is Ronin's Attack less than Viking's Attack? ";
	cout << (Ronin.get_atk() < Viking.get_atk()) << endl;
	cout << "   Is Viking's Attack less than Ronin's Attack? ";
	cout << (Viking.get_atk() < Ronin.get_atk()) << endl;

	// Line Break
	cout << endl;

	// End Program
	return 0;
}

// Test Setters
bool test_setters() {
	bool passed = true;
	// cout << "Testing setters" << endl;
	Warrior Viking;
	Viking.set_name("Viking");
	if (Viking.get_name() != "Viking") {
		passed = false;
		cout << "FAILED [NAME = VIKING] TEST CASE:   " << Viking.get_name() << endl;
	}
	Viking.set_atk(15);
	if (Viking.get_atk() != 15) {
		passed = false;
		cout << "FAILED [ATK = 15] TEST CASE:   " << Viking.get_atk() << endl;
	}
	Viking.set_def(5);
	if (Viking.get_def() != 5) {
		passed = false;
		cout << "FAILED [DEF = 5] TEST CASE:   " << Viking.get_def() << endl;
	}
	Viking.set_hp(20);
	if (Viking.get_hp() != 20) {
		passed = false;
		cout << "FAILED [HP = 20] TEST CASE:   " << Viking.get_hp() << endl;
	}
	// cout << "Done testing setters" << endl;
	return passed;
}

// Test Boost Attack
bool test_boost_atk() {
	bool passed = true;
	// cout << "Testing boost_atk" << endl;
	Warrior Ronin;
	Ronin.boost_atk();
	if (Ronin.get_atk() != 15) {
		passed = false;
		cout << "FAILED [BOOST ATK = ATK + 5] TEST CASE:   " << Ronin.get_atk() << endl;
	}
	// cout << "Done testing boost_atk" << endl;
	return passed;
}