#pragma once
#include "Evil.h"
class Warlord :
    public Evil
{

protected:
    int power_level;

public:

    Warlord();
    Warlord(string in_name,int in_health,int in_pow);
    
    string show_name();
    int show_power();
    void barrage_attack(string in_diff, Warrior& hero);
    void heal();
    void kill_all();


};

