#include <iostream>

using namespace std;

class Hero{
private:
    short int Damage_Hit;
    float MaxHealthPoint;
    float HealthPoint;
    float HPregeneration;
    float MaxManaPoint;
    float ManaPoint;
    float MPregeneration;
    short int gold;
    short int experience;
    short int lvl;
    short int skillPoint;
    short int howMuchUpFirstSkill;
    short int howMuchUpSecondSkill;
    short int howMuchUpThirdSkill;
public:
    Hero(short int Damage_Hit, float MaxHealthPoint, float HealthPoint, float HPregeneration, float MaxManaPoint,
        float ManaPoint, float MPregeneration, short int gold, short int experience, short int lvl, short int skillPoint,
        short int howMuchUpFirstSkill, short int howMuchUpSecondSkill, short int howMuchUpThirdSkill){
        this->Damage_Hit = Damage_Hit;
        this->MaxHealthPoint = MaxHealthPoint;
        this->HealthPoint = HealthPoint;
        this->HPregeneration = HPregeneration;
        this->MaxManaPoint = MaxManaPoint;
        this->ManaPoint = ManaPoint;
        this->MPregeneration = MPregeneration;
        this->gold = gold;
        this->experience = experience;
        this->lvl = lvl;
        this->skillPoint = skillPoint;
        this->howMuchUpFirstSkill = howMuchUpFirstSkill;
        this->howMuchUpSecondSkill = howMuchUpSecondSkill;
        this->howMuchUpThirdSkill = howMuchUpThirdSkill;
    }


};

class Lina : public Hero{
private:
    short int *Dragon_slave_damage;
    short int *Dragon_slave_mana;
    short int Dragon_slave_reloading;
    short int Dragon_slave_cant_use;
    short int *Light_strike_array_damage;
    short int *Light_strike_array_mana;
    short int *Light_strike_array_stun;
    short int Light_strike_array_reloading;
    short int Light_strike_array_cant_use;
    short int *Laguna_blade_damage;
    short int *Laguna_blade_mana;
    short int *Laguna_blade_reloading;
    short int Laguna_blade_cant_use;
public:
    Lina(short int Damage_Hit, float MaxHealthPoint, float HealthPoint, float HPregeneration, float MaxManaPoint,
         float ManaPoint, float MPregeneration, short int gold, short int experience, short int lvl, short int skillPoint,
         short int howMuchUpFirstSkill, short int howMuchUpSecondSkill, short int howMuchUpThirdSkill)
    : Hero(Damage_Hit, MaxHealthPoint, HealthPoint, HPregeneration, MaxManaPoint, ManaPoint, MPregeneration, gold,
        experience, lvl, skillPoint, howMuchUpFirstSkill, howMuchUpSecondSkill, howMuchUpThirdSkill){
        Dragon_slave_damage = new short int [5] {0,85,160,235,310};
        Dragon_slave_mana = new short int [5] {0,100,115,130,145};
        Dragon_slave_reloading = 8;
        Dragon_slave_cant_use = 0;
        Light_strike_array_damage = new short int [5] {0,80,120,160,200};
        Light_strike_array_mana = new short int [5] {0,100,110,120,130};
        Light_strike_array_stun = new short int [5] {0,1,2,2,3};
        Light_strike_array_reloading = 7;
        Light_strike_array_cant_use = 0;
        Laguna_blade_damage = new short int [4] {0,450,650,850};
        Laguna_blade_mana = new short int [4] {0,280,420,680};
        Laguna_blade_reloading = new short int [4] {0,70,60,50};
        Laguna_blade_cant_use = 0;
    }


};

class Lion : public Hero{
private:
    short int *Earth_spike_damage;
    short int *Earth_spike_mana;
    short int *Earth_spike_stun;
    short int  Earth_spike__reloading;
    short int *Hex_mana;
    short int *Hex_stun;
    short int *Hex_reloading;
    short int *Finger_death_damage;
    short int *Finger_death_mana;
    short int *Finger_death_reloading;
public:
    Lion(short int Damage_Hit, float MaxHealthPoint, float HealthPoint, float HPregeneration, float MaxManaPoint,
    float ManaPoint, float MPregeneration, short int gold, short int experience, short int lvl, short int skillPoint,
    short int howMuchUpFirstSkill, short int howMuchUpSecondSkill, short int howMuchUpThirdSkill)
    : Hero(Damage_Hit, MaxHealthPoint, HealthPoint, HPregeneration, MaxManaPoint, ManaPoint, MPregeneration, gold,
            experience, lvl, skillPoint, howMuchUpFirstSkill, howMuchUpSecondSkill, howMuchUpThirdSkill){
        Earth_spike_damage = new short int [5] {0,80,140,200,260};
        Earth_spike_mana = new short int [5] {0,70,100,130,160};
        Earth_spike_stun = new short int [5]{0, 1,2,2,3};
        Earth_spike__reloading = 12;
        Hex_mana = new short int [5] {0,120,150,175,200};
        Hex_stun = new short int [5] {0,2,3,4,5};
        Hex_reloading = new short int [5] {0,30,24,18,12};
        Finger_death_damage = new short int [4] {0,600,725,850};
        Finger_death_mana = new short int [4] {0,200,420,650};
        Finger_death_reloading = new short int [4] {0,160,100,40};
    }


};

int main(){
    cout << "First player choose a hero: \nChoose a hero number : " << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "\"1\" - Lina: 600(+2.0)HP 435(+1.5)MP" << endl;
    cout << "First ability : \"Dragon slave\" : " << endl;
    cout << "                                  85/160/235/310 damage" << endl;
    cout << "                                  100/115/130/145 mana" << endl;
    cout << "                                  8 sec reloading" << endl;
    cout << "Second ability : \"Light strike array\" : " << endl;
    cout << "                                  80/120/160/200 damage" << endl;
    cout << "                                  100/110/120/130 mana" << endl;
    cout << "                                  1/2/2/3 sec stun" << endl;
    cout << "                                  7 sec reloading" << endl;
    cout << "Third ability : \"Laguna blade\" : " << endl;
    cout << "                                  450/650/850 damage" << endl;
    cout << "                                  280/420/680 mana" << endl;
    cout << "                                  70/60/50 sec reloading" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "\"2\" - Lion: 560(+1.8)HP 291(+0.9)MP" << endl;
    cout << "First ability : \"Earth spike\" : " << endl;
    cout << "                                  80/140/200/260 damage" << endl;
    cout << "                                  70/100/130/160 mana" << endl;
    cout << "                                  1/2/2/3 sec stun" << endl;
    cout << "                                  12 sec reloading" << endl;
    cout << "Second ability : \"Hex\" : " << endl;
    cout << "                                  120/150/175/200 mana" << endl;
    cout << "                                  2/3/4/5 sec stun" << endl;
    cout << "                                  30/24/18/12 sec reloading" << endl;
    cout << "Third ability : \"Finger death\" : " << endl;
    cout << "                                  600/725/850 damage" << endl;
    cout << "                                  200/420/650 mana" << endl;
    cout << "                                  160/100/40 sec reloading" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    Lina MyHero(57,);
    Lion EnemyHero();

    return 0;
}