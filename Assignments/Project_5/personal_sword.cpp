//
//  personal_sword.cpp
//  CS120B - Project 4
//
//  Contains a Personal_Sword Component Class for the Commander Class
//
//	Personal_Sword:
//	- Create a default Personal_Sword using the custom_sword structure and enums for the parts
//  - Create a a custom Personal_Sword using the custom_sword structure and enums for the parts
//	- Get: Sword, and all the enum parts (pommel, guard, grip, blade_shape, blade_type)
//	- Set: Sword (implicitly sets all the parts)
//	- To_String: all the enum parts (pommel, guard, grip, blade_shape, blade_type)
//	- Overloads: the [<<] operator to print all parts straight from enum to string
//
//  Created by Mark Kulhowvick on 3/2/17
//  Copyright © 2017 Mark Kulhowvick. All rights reserved.
//

// Inclusions
#include "personal_sword.h"
#include <iomanip>

// Personal Sword Component Class
// Default Constructor
Personal_Sword::Personal_Sword() {
	sword = {Basic, Cross, Leather, Straight, Double_Bladed};
}

// Non-Default Constructors
Personal_Sword::Personal_Sword(pommel pommel, guard guard, grip grip, blade_shape blade_shape, blade_type blade_type) {
	sword = {pommel, guard, grip, blade_shape, blade_type};
}

// Getters
custom_sword Personal_Sword::get_sword() const {
	return sword;
}
pommel Personal_Sword::get_pommel() const {
	return sword.pommel;
}
guard Personal_Sword::get_guard() const {
	return sword.guard;
}
grip Personal_Sword::get_grip() const {
	return sword.grip;
}
blade_shape Personal_Sword::get_blade_shape() const {
	return sword.blade_shape;
}
blade_type Personal_Sword::get_blade_type() const {
	return sword.blade_type;
}

// Setters
void Personal_Sword::set_sword(pommel in_pommel, guard in_guard, grip in_grip, blade_shape in_blade_shape, blade_type in_blade_type) {
	sword = { in_pommel, in_guard, in_grip, in_blade_shape, in_blade_type };
}

// Custom Sword ---> String
string Personal_Sword::pommel_to_string(custom_sword sw) const {
	switch (sw.pommel) {
		case Basic: return "Basic";
		case Fancy: return "Fancy";
	}
}

// Custom Sword ---> String
string Personal_Sword::guard_to_string(custom_sword sw) const {
	switch (sw.guard) {
		case Cross: return "Cross";
		case Basket: return "Basket";
		case Cup: return "Cup";
	}
}

// Custom Sword ---> String
string Personal_Sword::grip_to_string(custom_sword sw) const {
	switch (sw.grip) {
		case Leather: return "Leather";
		case Wood: return "Wood";
		case Metal: return "Metal";
	}
}

// Custom Sword ---> String
string Personal_Sword::blade_shape_to_string(custom_sword sw) const {
	switch (sw.blade_shape) {
		case Straight: return "Straight";
		case Curved: return "Curved";
		case Circular: return "Circular";
	}
}

// Custom Sword ---> String
string Personal_Sword::blade_type_to_string(custom_sword sw) const {
	switch (sw.blade_type) {
		case Single_Bladed: return "Single Bladed";
		case Double_Bladed: return "Double Bladed";
		case Thrusting: return "Thrusting";
	}
}

// Output [<<] Operator Overload
ostream& operator << (ostream &display, Personal_Sword &PS) {
	display << "   Pommel: " << PS.pommel_to_string(PS.get_sword()) << endl
		<< "   Guard : " << PS.guard_to_string(PS.get_sword()) << endl
		<< "   Grip  : " << PS.grip_to_string(PS.get_sword()) << endl
		<< "   Blade Shape: " << PS.blade_shape_to_string(PS.get_sword()) << endl
		<< "   Blade Type : " << PS.blade_type_to_string(PS.get_sword()) << endl;
	return display;
}