#include "Evil.h"
#include <iostream>
#include <string>

using std::string;

Evil::Evil(){
	name = "Moe";
	health = 100;
}
Evil::Evil(string in_name, int in_health) {
	name = in_name;
	health = in_health;
}
string Evil::show_name(){
	return name;
}
int Evil::show_health() {
	return health;
}
void Evil::light_attack(string in_diff, Warrior& hero){
	if (in_diff == "Normal") {
		hero.health = hero.health - 5;
	}
	if (in_diff == "Hard") {
		hero.health = hero.health - 10;
	}
}
void Evil::heavy_attack(string in_diff, Warrior& hero){
	if (in_diff == "Normal") {
		hero.health = hero.health - 15;
	}
	if (in_diff == "Hard") {
		hero.health = hero.health - 20;
	}

}
Evil::~Evil(){

}
