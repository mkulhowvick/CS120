//
//  warrior.h
//  CS 120 B - Project 2
//
//	Header file for the Warrior Class
//
//  Created by Mark Kulhowvick on 2/8/2017
//  Copyright © 2017 Mark Kulhowvick. All rights reserved.
//

#ifndef warrior_h
#define warrior_h

// Inclusions
#include <string>
using namespace std;

// Warrior Class
class Warrior {
public:
	// Default Constructor
	Warrior();
	// Default Deconstructor
	~Warrior();

	/**
	* Requires: Nothing
	* Modifies: Attack, Defense, Health
	*  Effects: Gets or sets values for the above
	*/
	string get_name();
	int get_atk();
	int get_def();
	int get_hp();
	void set_name(string in_name);
	void set_atk(int in_atk);
	void set_def(int in_def);
	void set_hp(int in_hp);

	/**
	* Requires: Nothing
	* Modifies: Attack
	*  Effects: Boosts Attack by +5
	*/
	void boost_atk();

	// Operator Overloads
	friend ostream& operator << (ostream &display, Warrior &warrior);
	friend bool operator > (Warrior& lhs, Warrior& rhs);
	friend bool operator < (Warrior& lhs, Warrior& rhs);

private:
	// Fields
	string name;
	int atk;
	int def;
	int hp;
};

#endif // warrior_h