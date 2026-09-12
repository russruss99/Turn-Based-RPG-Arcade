#include <iostream>
#include <string>
#include "Warrior.h"
#include "Evil.h"
#include "Warlord.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

#define NORMAL 0
#define HARD 1

int main() {
	int difficulty;
	int wave1 = 0;
	int wave2 = 0;
	int wave3 = 0;
	int wave4 = 0;
	int user_select;
	int hard_health1 = 0;
	int hard_health2 = 0;
	int hard_health3 = 0;
	int hard_health = 0;
	int sel_bad;
	int ally_sel = rand() % 2 + 1;
	int random = rand() % 2;
	int boss_attack = rand() % 4;
	int rand_opp1 = rand() % 4 ;
	int rand_opp2 = rand() % 3 ;
	int rand_opp3 = rand() % 2 ;
	int rand_ally = rand() % 1 ;
	int enemy_sel = rand() % 2 + 1;
	string diff;
	string diff_wep;
	///// SELECT GAME DIFFICULTY ////////////////
	cout << "Please select your diffculty: " << endl;
	cout << "[0] Normal" << endl;
	cout << "[1] Hard" << endl;
	cin >> difficulty;
	if (difficulty == NORMAL) {
		cout << "Prepare to fight!" << endl;
		diff = "Normal";
		diff_wep = "Shortsword";
	}
	else {
		cout << "May God bless your soul.." << endl;
		diff = "Hard";
		hard_health1 = 100;
		hard_health2 = 250;
		hard_health3 = 500;
		hard_health = 1500;
		diff_wep = "Broadsword";

	}
	///////// OBJECTS /////////////////
	Warrior Hero("Russ", 100, diff_wep, 0,0, 0, 0, 0);
	Warrior* ptr_allies[2] = {
	new Warrior("Reed", 400, "Battle Axe"),
	new Warrior("Royce", 400, "Glaive"),
	};
	Evil* ptr_baddie1[5] = {

		new Evil("Goombah",100 + hard_health1),
		new Evil("Goombah",100 + hard_health1),
		new Evil("Ezz",100 + hard_health1),
		new Evil("Posey",100 + hard_health1),
		new Evil("Billiam",100 + hard_health1),

	};
	Evil* ptr_baddie2[4] = {

		new Evil("Rudy",200 + hard_health2),
		new Evil("Zeer",200 + hard_health2),
		new Evil("Manson",200 + hard_health2),
		new Evil("Brute",200 + hard_health2),

	};
	Evil* ptr_baddie3[3] = {

		new Evil("Mgee",500 + hard_health3),
		new Evil("Bomber",500 + hard_health3),
		new Evil("Jester",500 + hard_health3),

	};
	Warlord* Boss = new Warlord("Emperor Tchanka",2000, 1000);
	///////A/POLYMORPHISM///////
	Evil* ptr_baddie4[2] = {
		Boss,
		new Evil("Zolomaan",900 + hard_health3),
	};


	//// Shortcut?
	//for (int i = 0; i <= 4; i++) {
	//	cout << "Wave " << i << endl;
	//	for (int j = 0; j < 6;j++) {
	//		
	//	}

	//}
	
	/////////////////////////////////////////////////////// STARTING WAVE I
	do {
		cout << "[" << Hero.show_name() << ", " << Hero.show_health() << ", " << Hero.show_weapon() << "]" << endl;
		for (int i = 0; i < 2; i++) {
			cout << "[" << ptr_allies[i]->show_name() << ", " << ptr_allies[i]->show_health() << ", " << ptr_allies[i]->show_weapon() << "]" << endl;
		}
		cout << "------ Wave I, Entrance ------" << endl;
		cout << "Select your opponent:" << endl;
		for (int i = 0; i < 5; i++) {
			cout << "[" << i + 1 << "] " << ptr_baddie1[i]->show_name() << ", " <<
				ptr_baddie1[i]->show_health() << endl;
		}
		cin >> sel_bad;
		while (sel_bad > 5) {
			cout << "Invalid input, try again" << endl;
			cin>> sel_bad;
		}
		cout << "Select your options:" << endl;
		cout << "[1] Light Attack" << endl;
		cout << "[2] Heavy Attack" << endl;
		cout << "[3] Use Item" << endl;
		cout << "[4] Reinforce" << endl;
		cin >> user_select;
		while (user_select > 4) {
			cout << "Invalid input, try again" << endl;
			cin >> user_select;
		}
			if (user_select == 1) {
				Hero.light_attack(*ptr_baddie1[sel_bad - 1]);
			}
			else if (user_select == 2) {
				Hero.heavy_attack(*ptr_baddie1[sel_bad - 1]);
			}
			else if (user_select == 3) {
				Hero.use_item(*ptr_baddie1[sel_bad - 1]);
			}
			else if (user_select == 4 ){
				Hero.reinforce();
				cout << "Shield strength increased by " << Hero.show_shield() << endl;
			}
		cout << "Allies Attack" << endl;
		cout << ptr_allies[0]->show_name() << "'s turn" << endl;
		int sel1;
		if (ally_sel == 1) {
			cout << "Select enemy:" << endl;
			for (int i = 0; i < 5; i++) {
				cout << "[" << i + 1 << "] " << ptr_baddie1[i]->show_name() << endl;
			}
			cin >> sel1;
			while (sel1 > 5) {
				cout << "Invalid input, try again" << endl;
				cin >> sel1;
			}
			ptr_allies[0]->light_attack(*ptr_baddie1[sel1 - 1]);
		}
		else if (ally_sel == 2) {
			cout << "Select enemy:" << endl;
			for (int i = 0; i < 5; i++) {
				cout << "[" << i + 1 << "] " << ptr_baddie1[i]->show_name() << endl;
			}
			cin >> sel1;
			while (sel1 > 5) {
				cout << "Invalid input, try again" << endl;
				cin >> sel1;
			}
			ptr_allies[0]->heavy_attack(*ptr_baddie1[sel1 - 1]);
		}
		cout << ptr_allies[1]->show_name() << "'s turn" << endl;
		int sel2;
		if (ally_sel == 1) {
			cout << "Select enemy:" << endl;
			for (int i = 0; i < 5; i++) {
				cout << "[" << i + 1 << "] " << ptr_baddie1[i]->show_name() << endl;
			}
			cin >> sel2;
			while (sel2 > 5) {
				cout << "Invalid input, try again" << endl;
				cin >> sel2;
			}
			ptr_allies[1]->light_attack(*ptr_baddie1[sel2 - 1]);
		}
		else if (ally_sel == 2) {
			cout << "Select enemy:" << endl;
			for (int i = 0; i < 5; i++) {
				cout << "[" << i + 1 << "] " << ptr_baddie1[i]->show_name() << endl;
			}
			cin >> sel2;
			while (sel2 > 5) {
				cout << "Invalid input, try again" << endl;
				cin >> sel2;
			}
			ptr_allies[1]->heavy_attack(*ptr_baddie1[sel2 - 1]);
		}
		cout << "Enemies Attack" << endl;
		if (ally_sel == 1) {
			for (int i = 0; i < 5; i++) {
				ptr_baddie1[i]->light_attack(diff, *ptr_allies[rand_ally]);
			}
		}
		if (ally_sel == 2)
		{
			for (int i = 0; i < 5; i++) {
				ptr_baddie1[i]->heavy_attack(diff, *ptr_allies[rand_ally]);
			}
		}
		for (int i = 0; i < 5; i++) {
			if (ptr_baddie1[i]->show_health() <= 0) {
				ptr_baddie1[i]->~Evil();
				wave1 = wave1 + 1;
			}
		}
	} while (wave1 < 6);
	//////////////////////////////////////////// END OF WAVE I
	Hero.rewards();
	Hero.purchase();
	for (int i = 0; i < 2; i++) {
		ptr_allies[i]->up_health();
	}
	/////////////////////////////////////////// STARTING WAVE II
	do {
		cout << "[" << Hero.show_name() << ", " << Hero.show_health() << ", " << Hero.show_weapon() << "]" << endl;
		for (int i = 0; i < 2; i++) {
			cout << "[" << ptr_allies[i]->show_name() << ", " << ptr_allies[i]->show_health() << ", " << ptr_allies[i]->show_weapon() << "]" << endl;
		}

		cout << "------ Wave II, Main Corridor ------" << endl;
		cout << "Select your opponent:" << endl;
		for (int i = 0; i < 4; i++) {

			cout << "[" << i + 1 << "] " << ptr_baddie2[i]->show_name() << ", " <<
				ptr_baddie2[i]->show_health() << endl;
		}
		cin >> sel_bad;
		while (sel_bad > 4) {
			cout << "Invalid input, try again" << endl;
			cin >> sel_bad;
		}
		cout << "Select your options:" << endl;
		cout << "[1] Light Attack" << endl;
		cout << "[2] Heavy Attack" << endl;
		cout << "[3] Use Item" << endl;
		cin >> user_select;
		while (user_select > 3) {
			cout << "Invalid input, try again" << endl;
			cin >> user_select;
		}
		if (user_select == 1) {
			Hero.light_attack(*ptr_baddie2[sel_bad - 1]);
		}
		else if (user_select == 2) {
			Hero.heavy_attack(*ptr_baddie2[sel_bad - 1]);
		}
		else if (user_select == 3) {
			Hero.use_item(*ptr_baddie2[sel_bad - 1]);
		}

		cout << "Allies Attack" << endl;
		cout << ptr_allies[0]->show_name() << "'s turn" << endl;
		int sel1;


		if (ally_sel == 1) {
			cout << "Select enemy:" << endl;
			for (int i = 0; i < 4; i++) {

				cout << "[" << i + 1 << "] " << ptr_baddie2[i]->show_name() << endl;
			}
			cin >> sel1;
			while (sel1 > 4) {
				cout << "Invalid input, try again" << endl;
				cin >> sel1;
			}
			ptr_allies[0]->light_attack(*ptr_baddie2[sel1 - 1]);
		}
		else if (ally_sel == 2) {
			cout << "Select enemy:" << endl;
			for (int i = 0; i < 4; i++) {

				cout << "[" << i + 1 << "] " << ptr_baddie2[i]->show_name() << endl;
			}
			cin >> sel1;
			while (sel1 > 4) {
				cout << "Invalid input, try again" << endl;
				cin >> sel1;
			}
			ptr_allies[0]->heavy_attack(*ptr_baddie2[sel1 - 1]);
		}
		cout << ptr_allies[1]->show_name() << "'s turn" << endl;
		int sel2;
		if (ally_sel == 1) {
			cout << "Select enemy:" << endl;
			for (int i = 0; i < 4; i++) {

				cout << "[" << i + 1 << "] " << ptr_baddie2[i]->show_name() << endl;
			}
			cin >> sel2;
			while (sel2 > 4) {
				cout << "Invalid input, try again" << endl;
				cin >> sel2;
			}
			ptr_allies[1]->light_attack(*ptr_baddie2[sel2 - 1]);
		}
		else if (ally_sel == 2) {
			cout << "Select enemy:" << endl;
			for (int i = 0; i < 4; i++) {

				cout << "[" << i + 1 << "] " << ptr_baddie2[i]->show_name() << endl;
			}
			cin >> sel2;
			while (sel2 > 4) {
				cout << "Invalid input, try again" << endl;
				cin >> sel2;
			}
			ptr_allies[1]->heavy_attack(*ptr_baddie2[sel2 - 1]);
		}

		cout << "Enemies Attack" << endl;
		if (ally_sel == 1) {
			for (int i = 0; i < 4; i++) {
				if (random == 0) {

					ptr_baddie2[i]->light_attack(diff, Hero);
				}
				else {
					ptr_baddie2[i]->light_attack(diff, *ptr_allies[rand_ally]);
				}
			}
		}
		if (ally_sel == 2) {

			for (int i = 0; i < 4; i++) {
				if (random == 0) {
					ptr_baddie2[i]->light_attack(diff, Hero);
				}
				else{
				ptr_baddie2[i]->heavy_attack(diff, *ptr_allies[rand_ally]);
			}
			}

		}
		for (int i = 0; i < 4; i++) {
			if (ptr_baddie2[i]->show_health() <= 0) {
				ptr_baddie2[i]->~Evil();
				wave2 = wave2 + 1;
			}
		}

	} while (wave2 < 4);
	//////////////////////////////// END OF WAVE II
	Hero.rewards();
	Hero.purchase();
	for (int i = 0; i < 2; i++) {
		ptr_allies[i]->up_health();
	}
	//////////////////////////////// STARTING WAVE III
	do {
		cout << "[" << Hero.show_name() << ", " << Hero.show_health() << ", " << Hero.show_weapon() << "]" << endl;
		for (int i = 0; i < 2; i++) {
			cout << "[" << ptr_allies[i]->show_name() << ", " << ptr_allies[i]->show_health() << ", " << ptr_allies[i]->show_weapon() << "]" << endl;
		}

		cout << "------ Wave III, Dining Hall ------" << endl;
		cout << "Select your opponent:" << endl;
		for (int i = 0; i < 3; i++) {

			cout << "[" << i + 1 << "] " << ptr_baddie3[i]->show_name() << ", " <<
				ptr_baddie3[i]->show_health() << endl;
		}
		cin >> sel_bad;
		while (sel_bad > 3) {
			cout << "Invalid input, try again" << endl;
			cin >> sel_bad;
		}

		cout << "Select your options:" << endl;
		cout << "[1] Light Attack" << endl;
		cout << "[2] Heavy Attack" << endl;
		cout << "[3] Use Item" << endl;
		cin >> user_select;
		while (user_select > 3) {
			cout << "Invalid input, try again" << endl;
			cin >> user_select;
		}
		if (user_select == 1) {
			Hero.light_attack(*ptr_baddie3[sel_bad - 1]);
		}
		else if (user_select == 2) {
			Hero.heavy_attack(*ptr_baddie3[sel_bad - 1]);
		}
		else if (user_select == 3) {
			Hero.use_item(*ptr_baddie3[sel_bad - 1]);
		}
		cout << "Allies Attack" << endl;
		cout << ptr_allies[0]->show_name() << "'s turn" << endl;
		int sel1;

		if (ally_sel == 1) {
			cout << "Select enemy:" << endl;
			for (int i = 0; i < 3; i++) {

				cout << "[" << i + 1 << "] " << ptr_baddie3[i]->show_name() << endl;
			}
			cin >> sel1;
			while (sel1 > 3) {
				cout << "Invalid input, try again" << endl;
				cin >> sel1;
			}
			ptr_allies[0]->light_attack(*ptr_baddie3[sel1 - 1]);
		}
		else if (ally_sel == 2) {
			cout << "Select enemy:" << endl;
			for (int i = 0; i < 3; i++) {

				cout << "[" << i + 1 << "] " << ptr_baddie3[i]->show_name() << endl;
			}
			cin >> sel1;
			ptr_allies[0]->heavy_attack(*ptr_baddie3[sel1 - 1]);
		}
		cout << ptr_allies[1]->show_name() << "'s turn" << endl;
		int sel2;
		if (ally_sel == 1) {
			cout << "Select enemy:" << endl;
			for (int i = 0; i < 3; i++) {

				cout << "[" << i + 1 << "] " << ptr_baddie3[i]->show_name() << endl;
			}
			cin >> sel2;
			while (sel2 > 3) {
				cout << "Invalid input, try again" << endl;
				cin >> sel2;
			}
			ptr_allies[1]->light_attack(*ptr_baddie3[sel2 - 1]);
		}
		else if (ally_sel == 2) {
			cout << "Select enemy:" << endl;
			for (int i = 0; i < 3; i++) {

				cout << "[" << i + 1 << "] " << ptr_baddie3[i]->show_name() << endl;
			}
			cin >> sel2;
			while (sel2 > 4) {
				cout << "Invalid input, try again" << endl;
				cin >> sel2;
			}
			ptr_allies[1]->heavy_attack(*ptr_baddie3[sel2 - 1]);
		}

		cout << "Enemies Attack" << endl;
		if (ally_sel == 1) {
			for (int i = 0; i < 3; i++) {
				if (random == 0) {

					ptr_baddie3[i]->light_attack(diff,Hero);

				}
				else {
					ptr_baddie3[i]->light_attack(diff, *ptr_allies[rand_ally]);
				}
			}
		}
		if (ally_sel == 2) {

			for (int i = 0; i < 3; i++) {
				if (random == 0) {

					ptr_baddie3[i]->light_attack(diff,Hero);

				}
				else {
				ptr_baddie3[i]->heavy_attack(diff, *ptr_allies[rand_ally]);
			}
			}

		}
		for (int i = 0; i < 3; i++) {
			if (ptr_baddie3[i]->show_health() <= 0) {
				ptr_baddie3[i]->~Evil();
				wave3 = wave3 + 1;
			}
		}

	} while (wave3 < 3);
	//////////////////////////////// END OF WAVE III
	Hero.rewards();
	Hero.purchase();
	for (int i = 0; i < 2; i++) {
		ptr_allies[i]->up_health();
	}
	//////////////////////////////// FINAL BOSS
	do {
		cout << "------------ Final Boss ------------" << endl;
		cout << "[" << Hero.show_name() << ", " << Hero.show_health() << ", " << Hero.show_weapon() << "]" << endl;
		for (int i = 0; i < 2; i++) {
			cout << "[" << ptr_allies[i]->show_name() << ", " << ptr_allies[i]->show_health() << ", " << ptr_allies[i]->show_weapon() << "]" << endl;
		}
		cout << "Select opponent:" << endl;
		for (int i = 0; i < 2; i++) {
			cout << "[" << i + 1 << "] " << ptr_baddie4[i]->show_name() << ", " <<
				ptr_baddie4[i]->show_health() << endl;
		}
		cin >> sel_bad;
		while (sel_bad > 3) {
			cout << "Invalid input, try again" << endl;
			cin >> sel_bad;
		}
		cout << "Select your options:" << endl;
		cout << "[1] Light Attack" << endl;
		cout << "[2] Heavy Attack" << endl;
		cout << "[3] Use Item" << endl;
		cin >> user_select;

		if (user_select == 1) {
			Hero.light_attack(*ptr_baddie4[user_select - 1]);
		}
		else if (user_select == 2) {
			Hero.heavy_attack(*ptr_baddie4[user_select - 1]);
		}
		else if (user_select == 3) {
			Hero.use_item(*ptr_baddie4[user_select - 1]);
		}
		cout << "Allies Attack" << endl;
		cout << ptr_allies[0]->show_name() << "'s turn" << endl;
		int ally1_choose;
		cout << "Select opponent:" << endl;
		for (int i = 0; i < 2; i++) {
			cout << "[" << i + 1 << "] " << ptr_baddie4[i]->show_name() << ", " <<
				ptr_baddie4[i]->show_health() << endl;
		}
		cin >> ally1_choose;
		if (ally_sel == 1) {
			
			ptr_allies[0]->light_attack(*ptr_baddie4[ally1_choose-1]);
		}
		else if (ally_sel == 2) {
			
				ptr_allies[0]->heavy_attack(*ptr_baddie4[ally1_choose-1]);
		}

		cout << ptr_allies[1]->show_name() << "'s turn" << endl;
		cout << "Select opponent:" << endl;
		for (int i = 0; i < 2; i++) {
			cout << "[" << i + 1 << "] " << ptr_baddie4[i]->show_name() << ", " <<
				ptr_baddie4[i]->show_health() << endl;
		}
		int ally2_choose;
		cin >> ally2_choose;
		if (ally_sel == 1) {
			
		ptr_allies[1]->light_attack(*ptr_baddie4[ally2_choose -1]);
			
		}
		else if (ally_sel == 2) {
			ptr_allies[1]->heavy_attack(*ptr_baddie4[ally2_choose - 1]);
		}
		cout << Boss->show_name() << "'s turn" << endl;
		for (int i = 0; i < 3; i++) {
			if (boss_attack == 0) {
				if (random == 0) {
				Boss->light_attack(diff, Hero);
				}
				else {
					Boss->light_attack(diff, *ptr_allies[rand_ally]);
				}
			}
			else if (boss_attack == 1) {
				if (random == 0) {
					Boss->heavy_attack(diff, Hero);
				}
				else {
					Boss->heavy_attack(diff, *ptr_allies[rand_ally]);
				}
			}
			else if (boss_attack == 2) {
				if (random == 0) {
					Boss->barrage_attack(diff, Hero);
				}
				else {
					Boss->barrage_attack(diff, *ptr_allies[rand_ally]);
				}
			}
			else if (boss_attack == 3) {
					Boss->heal();
			}
			else{
				Boss->kill_all();
			}
			
		}
		
		if (ptr_baddie4[1]->show_health() <= 0) {
			ptr_baddie4[1]->~Evil();
		}
		if (Boss->show_health() <= 0) {
			Boss->~Warlord();
			wave4 = wave4 + 1;
			cout << "You have slain the tyrant, congratulations you win!" << endl;
		}

	} while (wave4 < 1);
	cout << "Thanks for playing!!! :)" << endl;

	return 0;
}
