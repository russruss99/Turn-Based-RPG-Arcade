#pragma once
#include <iostream>
#include <string>
#include "Evil.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

class Warrior
{
	friend class Evil;
	friend class Warlord;
	string name;
	int health;
	int balance;
	int block;
	int num_potion1;
	int num_potion2;
	int num_potion3;
	string weapon;

public:

	Warrior();
	Warrior(string in_name, int in_health,string in_weapon, int in_balance,int shield, int pot1, int pot2, int pot3 );
	Warrior(string in_name, int in_health,string in_weapon);

	string show_name();
	string show_weapon();
	int show_health();
	int show_balance();
	int show_shield();
	int show_pot1();
	int show_pot2();
	int show_pot3();
	void light_attack(Evil& evil);
	void heavy_attack(Evil& evil);
	void reinforce();
	void use_item(Evil& evil);
	void purchase();
	void rewards();
	void up_health();
	void inventory();

	~Warrior();
};

