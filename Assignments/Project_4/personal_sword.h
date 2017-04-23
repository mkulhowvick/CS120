//
//  personal_sword.h
//  CS120B - Project 4
//
//  Header File for the Personal_Sword Component Class (of Commander)
//
//  Created by Mark Kulhowvick on 3/2/17
//  Copyright © 2017 Mark Kulhowvick. All rights reserved.
//

#ifndef personal_sword_h
#define personal_sword_h

// Inclusions
#include <string>
using namespace std;

// Custom Sword Enumeration Types
enum pommel {Basic, Fancy};
enum guard {Cross, Basket, Cup};
enum grip {Leather, Wood, Metal};
enum blade_shape {Straight, Curved, Circular};
enum blade_type {Single_Bladed, Double_Bladed, Thrusting};

// Data Structures
struct custom_sword {
	pommel pommel;
	guard guard;
	grip grip;
	blade_shape blade_shape;
	blade_type blade_type;
};

// Personal Sword Component Class
class Personal_Sword {
public:
	// Default Constructor
	Personal_Sword();

	// Non-Default Constructors
	Personal_Sword(pommel pommel, guard guard, grip grip, blade_shape blade_shape, blade_type blade_type);

	// Getters and Setters
	/**
	* Requires: None
	* Modifies: custom_sword pommel/guard/grip/blade_shape/blade_type
	* Effects : the above fields
	*/
	virtual custom_sword get_sword() const;
	virtual pommel get_pommel() const;
	virtual guard get_guard() const;
	virtual grip get_grip() const;
	virtual blade_shape get_blade_shape() const;
	virtual blade_type get_blade_type() const;
	virtual void set_sword(pommel in_pommel, guard in_guard, grip in_grip, blade_shape in_blade_shape, blade_type in_blade_type);

	// Custom Sword Parts ---> String
	/**
	* Requires: None
	* Modifies: None
	* Effects : None
	*/
	string pommel_to_string(custom_sword sw) const;
	string guard_to_string(custom_sword sw) const;
	string grip_to_string(custom_sword sw) const;
	string blade_shape_to_string(custom_sword sw) const;
	string blade_type_to_string(custom_sword sw) const;

	// Output [<<] Operator Overload
	friend ostream& operator << (ostream &display, Personal_Sword &PS);

private:
	// Fields
	custom_sword sword;
};

#endif /* end personal_sword_h*/