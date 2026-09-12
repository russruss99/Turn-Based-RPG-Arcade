#include "Warlord.h"

Warlord::Warlord(){

	name = "Tchanka";
	health = 2000;
	power_level = 100;

}
Warlord::Warlord(string in_name,int in_health ,int in_pow){

	name = in_name;
	health = in_health;
	power_level = in_pow;

}
string Warlord::show_name(){
	return "Warlord " + name;
}
int Warlord::show_power() {
	return power_level;
}

void Warlord::barrage_attack(string in_diff, Warrior& hero){
	power_level = power_level - 25;
	if (in_diff == "Normal") {
		hero.health = hero.health - 150;
	}
	if (in_diff == "Hard") {
		hero.health = hero.health - 250;
	}
}
void Warlord::heal() {
	health = health + 200;
	power_level = power_level - 50;
}

void Warlord::kill_all() {
	cout << "Everyone dies, Game over" << endl;
	exit;
}
