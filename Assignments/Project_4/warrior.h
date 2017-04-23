//
//  warrior.h
//  CS120B - Project 4
//
//  Header file for the Warrior Parent Class
//
//  Created by Mark Kulhowvick on 3/2/17
//  Copyright © 2017 Mark Kulhowvick. All rights reserved.
//

#ifndef warrior_h
#define warrior_h

// Inclusions
#include <string>
using namespace std;

// Weapon Enumeration Type
enum weapon {None, Dagger, Longsword, Greatsword, Katana, Rapier, Axe, Greataxe, Spear, Halberd, Longbow, Shortbow, Crossbow, Hand_Crossbow, Small_Shield, Tower_Shield};

// Warrior Parent Class
class Warrior {
public:
	// Default Constructor
	Warrior();

	// Non-Default Constructor
	Warrior(string name, weapon primary, weapon offhand, int hp, int atk, int def);

	// Getters and Setters
	/**
	 * Requires: None
	 * Modifies: name, primary, offhand, hp, atk, def
	 * Effects : the above fields
	 */
	virtual string get_name() const;
	virtual weapon get_primary() const;
	virtual weapon get_offhand() const;
	virtual int get_hp() const;
	virtual int get_atk() const;
	virtual int get_def() const;
	virtual void set_name(string in_name) ;
	virtual void set_primary(weapon in_primary);
	virtual void set_offhand(weapon in_offhand);
	virtual void set_hp(int in_hp) ;
	virtual void set_atk(int in_atk) ;
	virtual void set_def(int in_def) ;

	// Weapon ---> String
	/**
	* Requires: None
	* Modifies: None
	* Effects : None
	*/
	string weapon_to_string(weapon w) const;

	// Output [<<] Operator Overload
	friend ostream& operator << (ostream &display, Warrior &W);

protected:
	// Fields
	string name;
	weapon primary;
	weapon offhand;
	int hp;
	int atk;
	int def;

private:
	// None
};

#endif /* warrior_h*/