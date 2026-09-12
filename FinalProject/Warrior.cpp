#include "Warrior.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

#define Empower 1
#define Heal 2
#define Nuke 3
#define Upgrade 4
#define Max 5

Warrior::Warrior() {
	name = "Jon";
	health = 100;
	weapon = "Longsword";
	balance = 0;
	block = 0;
	num_potion1 = 0;
	num_potion2 = 0;
	num_potion3 = 0;
}
Warrior::Warrior(string in_name, int in_health,string in_weapon, int in_balance,int shield, int pot1, int pot2, int pot3) {
	name = in_name;
	health = in_health;
	weapon = in_weapon;
	balance = in_balance;
	block = shield;
	num_potion1 = pot1;
	num_potion2 = pot2;
	num_potion3 = pot3;
}
Warrior::Warrior(string in_name, int in_health, string in_weapon) {

	name = in_name;
	health = in_health;
	weapon = in_weapon;
	balance = 0;
	num_potion1 = 0;
	num_potion2 = 0;
	num_potion3 = 0;
}

string Warrior::show_name() {
	return name;
}
string Warrior:: show_weapon() {
	return weapon;
}
int Warrior::show_health(){
	return health;
}
int Warrior::show_balance(){
	return balance;
}
int Warrior::show_shield() {
	return block;
}
int Warrior::show_pot1(){
	return num_potion1;
}
int Warrior::show_pot2(){
	return num_potion2;
}
int Warrior::show_pot3(){
	return num_potion3;
}
void Warrior::light_attack(Evil& evil){
	if (weapon == "Shortsword") {
		evil.health = evil.health - 55;
	}
	else if (weapon == "Broadsword") {
		evil.health = evil.health - 85;
	}
	else if (weapon == "Longsword") {
		evil.health = evil.health - 100;
	}
	else {
		evil.health = evil.health - 200;
	}
}
void Warrior::heavy_attack(Evil& evil){
	if (weapon == "Shortsword") {
		evil.health = evil.health - 95;
	}
	else if (weapon == "Boradsword") {
		evil.health = evil.health - 100;
	}
	else if (weapon == "Longsword") {
		evil.health = evil.health - 150;
	}
	else {
		evil.health = evil.health - 400;
	}
}
void Warrior::reinforce() {
	block = block + 150;
}
void Warrior::use_item(Evil& evil){
	int select;
	int pottot = num_potion1 + num_potion2 + num_potion3;
	if (pottot == 0) {
		cout << "You are out of items. You must fight:(1-light)(2-heavy)" << endl;
		cin >> select;
		if (select == 1) {
			light_attack(evil);
		}
		else {
			heavy_attack(evil);
		}
	}
	else {
		cout << "Select an item to use: " << endl;
		cout << "[1] Power Fruit " << endl;
		cout << "[2] Aquaphor" << endl;
		cout << "[3] Bomboclat" << endl;

		cin >> select;

		if (select == Empower) {
			cout << "Empowering Fruit" << endl;
			if (weapon == "Shortsword") {
				evil.health = evil.health - 100;
			}
			else if (weapon == "Broadsword") {
				evil.health = evil.health - 180;
			}
			else if (weapon == "Longsword") {
				evil.health = evil.health - 275;
			}
			else {
				evil.health = evil.health - 400;
			}
			num_potion1 = num_potion1 - 1;
		}
		if (select == Heal) {
			cout << "Healing Ointment" << endl;
			health = health + 100;
			num_potion2 = num_potion2 - 1;
		}
		if (select == Nuke) {
			cout << "Bomboclat" << endl;
			evil.health = evil.health - 700;
			num_potion3 = num_potion3 - 1;
		}
	}
}
void Warrior::purchase() {
	int buy;
	do {
		inventory();
		cout << "Weapon: " << weapon << endl;
		cout << "Total Balance - $" << balance << endl;
		cout << "--- Item Shop ---: " << endl;
		cout << "1 - Power Fruit - $50 " << endl;
		cout << "2 - Aquaphor - $25" << endl;
		cout << "3 - Bomboclat - $500" << endl;
		cout << "4 - Upgrade weapon - $250" << endl;
		cout << "5 - Increase Maximum Health - $10" << endl;
		cout << "Press any number to continue" << endl;
		cin >> buy;
		if (buy == Empower) {
			if (balance < 50) {
				cout << "not enough" << endl;
			}
			else {
				balance = balance - 50;
				num_potion1 = num_potion1 + 1;
			}
		}
		else if (buy == Heal) {
			if (balance < 25) {
				cout << "not enough" << endl;
			}
			else {
				balance = balance - 25;
				num_potion2 = num_potion2 + 1;
			}
		}
		else if (buy == Nuke) {
			if (balance < 500) {
				cout << "not enough" << endl;
			}
			else {
				balance = balance - 500;
				num_potion3 = num_potion3 + 1;
			}
		}
		else if (buy == Upgrade) {
			if (balance < 250) {
				cout << "not enough" << endl;
			}
			if (weapon == "Shortsword") {
				weapon = "Broadsword";
				balance = balance - 250;
			}
			else if (weapon == "Broadsword") {
				weapon = "Longsword";
				balance = balance - 250;
			}
			else {
				weapon = "Champion's Blade";
				balance = balance - 250;
			}
		}
		else if (buy == Max) {
			if (balance < 10) {
				cout << "not enough" << endl;
			}
			else {
				balance = balance - 10;
				health = health + 500;

			}
		}

	} while (buy < 6);
}
void Warrior::rewards() {
	balance = balance + 800;
}
void Warrior::up_health() {
	health = health + 250;
}
void Warrior::inventory() {
	cout << "Power Fruit - " << show_pot1() << endl;
	cout << "Aquaphor - " << show_pot2() << endl;
	cout << "Bomboclat - " << show_pot3() << endl;
}

Warrior::~Warrior(){}




