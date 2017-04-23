//
//  commander.h
//  CS120B - Project 5
//
//  Header file for the Commander Child Class (of Warrior)
//
//  Created by Mark Kulhowvick on 3/23/17
//  Copyright © 2017 Mark Kulhowvick. All rights reserved.
//

#ifndef commander_h
#define commander_h

// Inclusions
#include <string>
#include "warrior.h"
#include "personal_sword.h"
using namespace std;

// Commander Child Class
class Commander : public Warrior {
public:
	// Default Constructor
	Commander();

	// Non-Default Constructor
	Commander(string name, Personal_Sword mysword, weapon primary, weapon offhand, int hp, int atk, int def, double dodge_chance);

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
	virtual double get_dodge_chance() const;
	virtual Personal_Sword get_mysword() const;
	virtual void set_hp(int in_hp);
	virtual void set_atk(int in_atk);
	virtual void set_def(int in_def);
	virtual void set_dodge_chance(double in_dodge);
	virtual void set_mysword(Personal_Sword in_mysword);

	// Present Sword
	/**
	* Requires: None
	* Modifies: None
	* Effects : None
	*/
	virtual string present_sword(Personal_Sword PS) const;

	// Output [<<] Operator Overload
	friend ostream& operator << (ostream &display, Commander &C);

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
	double dodge_chance;
	Personal_Sword mysword;
};

#endif /* end commander_h*/