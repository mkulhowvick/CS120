//
//  warrior.h
//  CS120B - Project 3
//
//  Header file for two classes, Warrior and Squad
//
//  Created by Mark Kulhowivck on 2/2/20.
//  Copyright © 2017 Mark Kulhowvick, all rights reserved
//

#ifndef warrior_h
#define warrior_h

// Inclusions
#include <string>
#include <vector>
using namespace std;

// Warrior Class
class Warrior {
public:
	// Default Constructor
	Warrior();

	// Non-Default Constructor
	Warrior(string name, string armor_class, int hp, int atk, int def);

	// Deconstructor
	~Warrior();

	// Getters and Setters
	/**
	 * Requires: Nothing
	 * Modifies: Name, HP, Atk, Def
	 * Effects : Gets or Sets the above
	 */
	string get_name() const;
	string get_armor() const;
	int get_hp() const;
	int get_atk() const;
	int get_def() const;
	void set_name(string in_name);
	void set_armor(string in_armor_class);
	void set_hp(int in_hp);
	void set_atk(int in_atk);
	void set_def(int in_def);

	// Boost Methods
	/**
	* Requires: Nothing
	* Modifies: Defense or Attack
	*  Effects: Boosts the above by +5
	*/
	void boost_atk();
	void boost_def();

	// Overloads
	friend ostream& operator << (ostream &display, Warrior &w);

private:	
	// Fields
	string name;
	string armor;
	int hp;
	int atk;
	int def;
};

// Squad Class
class Squad {
public:
	// Default Constructor
	Squad();

	// Getters and Setters
	/**
	* Requires: Nothing
	* Modifies: Squad Vector
	* Effects : Sets an element of above
	*/
	void set_warrior(Warrior w, int i);
	Warrior get_warrior(int i);

	// Removal from Squad
	/**
	* Requires: Nothing
	* Modifies: Squad Vector
	* Effects : Sets an element of above
	*/
	void remove_warrior(int i);

	// Rally Methods
	/**
	* Requires: Nothing
	* Modifies: Defense or Attack of Squad members
	*  Effects: Boosts the above by +5 for all members
	*/
	void rally_atk();
	void rally_def();

	// Overloads
	friend ostream& operator << (ostream &display, Squad &s);

private:
	// Fields
	vector<Warrior> warrior;
};

#endif /* warrior_h */