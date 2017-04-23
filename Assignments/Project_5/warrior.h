//
//  warrior.h
//  CS120B - Project 5
//
//  Header file for the Warrior Parent Class
//
//  Created by Mark Kulhowvick on 3/23/17
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

	// Getters and Setters
	/**
	 * Requires: None
	 * Modifies: name, primary, offhand, atkRatio, defRatio
	 * Effects : the above fields
	 */
	virtual string get_name() const;
	virtual weapon get_primary() const;
	virtual weapon get_offhand() const;
	virtual double get_atkRatio() const;
	virtual double get_defRatio() const;
	virtual void set_name(string in_name) ;
	virtual void set_primary(weapon in_primary);
	virtual void set_offhand(weapon in_offhand);

	// Weapon ---> String
	/**
	* Requires: None
	* Modifies: None
	* Effects : None
	*/
	string weapon_to_string(weapon w) const;

protected:
	// Calculates Combat Ratios based on stats
	// Reflects the effectiveness of the unit for Atk/Def
	/**
	* Requires: None
	* Modifies: atkRatio, defRatio
	* Effects : None
	*/
	virtual void calcCombatRatios(double &atkRatio, double &defRatio) = 0;
	// Fields
	string name;
	weapon primary;
	weapon offhand;
	double atkRatio;
	double defRatio;

private:
	// None
};

#endif /* warrior_h*/