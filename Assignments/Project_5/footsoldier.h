//
//  footsoldier.h
//  CS120B - Project 5
//
//  Header file for the Footsoldier Child Class (of Warrior)
//
//  Created by Mark Kulhowvick on 3/23/17
//  Copyright © 2017 Mark Kulhowvick. All rights reserved.
//

#ifndef footsoldier_h
#define footsoldier_h

// Inclusions
#include <string>
#include "warrior.h"
using namespace std;

// Footsoldier Child Class
class Footsoldier : public Warrior {
public:
	// Default Constructor
	Footsoldier();

	// Non-Default Constructor
	Footsoldier(string name, weapon primary, weapon offhand, int hp, int atk, int def);

	// Getters and Setters
	// Setters implicitly modify name, primary, offhand, hp, atk, def
	/**
	* Requires: None
	* Modifies: dodge_chance, mysword
	* Effects : the above fields
	*/
	virtual double get_hp() const;
	virtual double get_atk() const;
	virtual double get_def() const;
	virtual void set_hp(int in_hp);
	virtual void set_atk(int in_atk);
	virtual void set_def(int in_def);

	// Output [<<] Operator Overload
	friend ostream& operator << (ostream &display, Footsoldier &F);

protected:
	// Override to calculate Combat Ratios based on stats
	// Reflects the effectiveness of the unit for Atk/Def
	/**
	* Requires: None
	* Modifies: atkRatio, defRatio
	* Effects : None
	*/
	virtual void calcCombatRatios(double &atkRatio, double &defRatio) override;
private:
	// Fields
	double hp;
	double atk;
	double def;
};

#endif /* end footsoldier_h*/