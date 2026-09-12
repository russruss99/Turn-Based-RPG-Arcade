#pragma once
#include <iostream>
#include "Warrior.h"
#include <string>

using std::string;

class Evil
{
	friend class Warrior;
protected:
	string name;
	int health;

public:

	Evil();
	Evil(string in_name,int in_health);

	virtual string show_name();
	int show_health();
	void light_attack(string in_diff,Warrior& hero);
	void heavy_attack(string in_diff,Warrior& hero);
	
	~Evil();
};

