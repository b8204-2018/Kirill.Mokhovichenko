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
    int gold;
    int experience;
    int lvl;
    int skillPoint;
    int howMuchUpFirstSkill;
    int howMuchUpSecondSkill;
    int howMuchUpThirdSkill;
    int myMoving;
public:
    Hero(short int Damage_Hit, float MaxHealthPoint, float HealthPoint, float HPregeneration, float MaxManaPoint,
        float ManaPoint, float MPregeneration){
        this->Damage_Hit = Damage_Hit;
        this->MaxHealthPoint = MaxHealthPoint;
        this->HealthPoint = HealthPoint;
        this->HPregeneration = HPregeneration;
        this->MaxManaPoint = MaxManaPoint;
        this->ManaPoint = ManaPoint;
        this->MPregeneration = MPregeneration;
        gold = 400;
        experience = 0;
        lvl = 1;
        skillPoint = 1;
        howMuchUpFirstSkill = 0;
        howMuchUpSecondSkill = 0;
        howMuchUpThirdSkill = 0;
        myMoving = 0;
    }

    int getHealthPoint(){
        return HealthPoint;
    }

    int getMaxHealthPoint(){
        return MaxHealthPoint;
    }

    int getManaPoint(){
        return ManaPoint;
    }

    int getMaxManaPoint(){
        return MaxManaPoint;
    }

    int getHitDamage(){
        return Damage_Hit;
    }

    int getExpirience(){
        return experience;
    }

    int getLvl(){
        return lvl;
    };

    int getSkillpoint(){
        return skillPoint;
    }

    int getGold(){
        return gold;
    }

    int getLvlSkill(int How_skill){
        if(How_skill == 1){
            return howMuchUpFirstSkill;
        }
        if(How_skill == 2){
            return howMuchUpSecondSkill;
        }
        if(How_skill == 3){
            return howMuchUpThirdSkill;
        }
    }

    void upLvlSkill(int whatSkill, int skillpoint){
        if (skillpoint > 0){
            if (getSkillpoint() < skillpoint){
                size_t i = getSkillpoint();
                for(i ; i > 0 ; i--){
                    if (whatSkill == 1){
                        howMuchUpFirstSkill++;
                        skillPoint--;
                    }
                    if (whatSkill == 2){
                        howMuchUpSecondSkill++;
                        skillPoint--;
                    }
                    if ((whatSkill == 3)&&(getLvl() > 6)){
                        howMuchUpThirdSkill++;
                        skillPoint--;
                    }
                }
            }
            else{
                size_t i = skillpoint;
                for(i ; i > 0 ; i--){
                    if (whatSkill == 1){
                        howMuchUpFirstSkill++;
                        skillPoint--;
                    }
                    if (whatSkill == 2){
                        howMuchUpSecondSkill++;
                        skillPoint--;
                    }
                    if ((whatSkill == 3)&&(getLvl() > 6)){
                        howMuchUpThirdSkill++;
                        skillPoint--;
                    }
                }
            }
        }
    }

    void lvlUpHero(){
        Damage_Hit += 4;
        MaxHealthPoint += 40;
        HPregeneration += 0.2;
        MaxManaPoint += 38;
        MPregeneration += 0.2;
        lvl++;
        skillPoint++;
    }

    void takeDamage(int damage){
        HealthPoint -= damage;
    }

    void removeMana(int how_much_mana){
        ManaPoint -= how_much_mana;
    }

    void addGold(int goldFromCreep){
        gold += goldFromCreep;
    }

    void addExp(int exp){
        experience += exp;
    }

    int getMyMoving(){
        return myMoving;
    }

    void addMoving(int skip){
        myMoving += skip;
    }


    int heroDead(){
        return (HealthPoint == 0) ? 1 : 0;
    }
};

class Lina : public Hero{
private:
    int *Dragon_slave_damage;
    int *Dragon_slave_mana;
    int Dragon_slave_reloading;
    int Dragon_slave_cant_use;
    int *Light_strike_array_damage;
    int *Light_strike_array_mana;
    int *Light_strike_array_stun;
    int Light_strike_array_reloading;
    int Light_strike_array_cant_use;
    int *Laguna_blade_damage;
    int *Laguna_blade_mana;
    int *Laguna_blade_reloading;
    int Laguna_blade_cant_use;
public:
    Lina(short int Damage_Hit, float MaxHealthPoint, float HealthPoint, float HPregeneration, float MaxManaPoint,
         float ManaPoint, float MPregeneration)
    : Hero(Damage_Hit, MaxHealthPoint, HealthPoint, HPregeneration, MaxManaPoint, ManaPoint, MPregeneration){
        Dragon_slave_damage = new int [5] {0,85,160,235,310};
        Dragon_slave_mana = new int [5] {0,100,115,130,145};
        Dragon_slave_reloading = 8;
        Dragon_slave_cant_use = 0;
        Light_strike_array_damage = new int [5] {0,80,120,160,200};
        Light_strike_array_mana = new int [5] {0,100,110,120,130};
        Light_strike_array_stun = new int [5] {0,1,2,2,3};
        Light_strike_array_reloading = 7;
        Light_strike_array_cant_use = 0;
        Laguna_blade_damage = new int [4] {0,450,650,850};
        Laguna_blade_mana = new int [4] {0,280,420,680};
        Laguna_blade_reloading = new int [4] {0,70,60,50};
        Laguna_blade_cant_use = 0;
    }



    int damageSkillLina(int ability){
        if (ability == 1){
            if (getManaPoint() >= Dragon_slave_mana[getLvlSkill(1)]) {
                removeMana(Dragon_slave_mana[getLvlSkill(1)]);

                return Dragon_slave_damage[getLvlSkill(1)];
            }
        }
        if (ability == 2) {
            if (getManaPoint() >= Light_strike_array_mana[getLvlSkill(2)]) {
                removeMana(Light_strike_array_mana[getLvlSkill(2)]);
                return Light_strike_array_damage[getLvlSkill(2)];
            }
        }
        if (ability == 3){
            if ((getManaPoint() >= Laguna_blade_mana[getLvlSkill(3)])&&(getLvl() >= 6)) {
                removeMana(Laguna_blade_mana[getLvlSkill(3)]);

                return Laguna_blade_damage[getLvlSkill(3)];
            }
        }
    }

    int getSkipLight_strike(){
        return Light_strike_array_stun[getLvlSkill(2)];
    }


};

class Lion : public Hero{
private:
    int *Earth_spike_damage;
    int *Earth_spike_mana;
    int *Earth_spike_stun;
    int  Earth_spike__reloading;
    int *Hex_mana;
    int *Hex_stun;
    int *Hex_reloading;
    int *Finger_death_damage;
    int *Finger_death_mana;
    int *Finger_death_reloading;
public:
    Lion(short int Damage_Hit, float MaxHealthPoint, float HealthPoint, float HPregeneration, float MaxManaPoint,
    float ManaPoint, float MPregeneration)
    : Hero(Damage_Hit, MaxHealthPoint, HealthPoint, HPregeneration, MaxManaPoint, ManaPoint, MPregeneration){
        Earth_spike_damage = new int [5] {0,80,140,200,260};
        Earth_spike_mana = new int [5] {0,70,100,130,160};
        Earth_spike_stun = new int [5]{0, 1,2,2,3};
        Earth_spike__reloading = 12;
        Hex_mana = new int [5] {0,120,150,175,200};
        Hex_stun = new int [5] {0,2,3,4,5};
        Hex_reloading = new int [5] {0,30,24,18,12};
        Finger_death_damage = new int [4] {0,600,725,850};
        Finger_death_mana = new int [4] {0,200,420,650};
        Finger_death_reloading = new int [4] {0,160,100,40};
    }

    int damageSkillLion(int ability){
        if (ability == 1){
            if (getManaPoint() >= Earth_spike_mana[getLvlSkill(1)]) {
                removeMana(Earth_spike_mana[getLvlSkill(1)]);

                return Earth_spike_damage[getLvlSkill(1)];
            }
        }
        if (ability == 2) {
            if (getManaPoint() >= Hex_mana[getLvlSkill(2)]) {
                removeMana(Hex_mana[getLvlSkill(2)]);
                return 0;
            }
        }
        if (ability == 3){
            if ((getManaPoint() >= Finger_death_mana[getLvlSkill(3)])&&(getLvl() >= 6)) {
                removeMana(Finger_death_mana[getLvlSkill(3)]);

                return Finger_death_damage[getLvlSkill(3)];
            }
        }
    }

    int getSkipHex(){
        return Hex_stun[getLvlSkill(2)];
    }

    int getSkipEarth_spike(){
        return Earth_spike_stun[getLvlSkill(1)];
    }
};

int main(){
    cout << "First player choose a hero: \nChoose a hero number : " << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "\"1\" - Lina: 600(+2)HP 435(+2)MP 57 damage hit" << endl;
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
    cout << "\"2\" - Lion: 560(+2)HP 291(+1)MP " << endl;
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
    Lina MyHero(57, 600, 600, 2, 435, 435, 2);
    Lion EnemyHero(57, 560, 560, 2, 291, 291, 1);

    while((MyHero.heroDead() == 0)||(EnemyHero.heroDead() == 0)){
        cout << "##################################...TURN LINA...##################################" << endl;
        cout << "LINA STATS : " << endl;
        cout << "Lina : HealthPointMax : \"" << MyHero.getMaxHealthPoint() << "\"  " << "\"" << MyHero.getHealthPoint() << "\"." << endl;
        cout << "Lina : ManaPointMax : \"" << MyHero.getMaxManaPoint() << "\"  " << "\"" << MyHero.getManaPoint() << "\"." << endl;
        cout << "Lina : lvl : \"" << MyHero.getLvl() << "\"." << endl;
        cout << "Lina : skillpoint : \"" << MyHero.getSkillpoint() << "\"." << endl;
        cout << "Lina : gold : \"" << MyHero.getGold() << "\"." << endl;
        cout << "Lina : expirience \"" << MyHero.getExpirience() << "\". (200 experience required to level up)" << endl;
        int moving;
        if (MyHero.getMyMoving() == 0){
            cout << "*********************Choose an option*********************" << endl;
            cout << "\"1\" use \"Dragon slave\" in Lion. Damage : " << MyHero.damageSkillLina(1) << endl;
            cout << "\"2\" use \"Light strike array\" in Lion. Damage : " << MyHero.damageSkillLina(2) << endl;
            cout << "\"3\" use \"Laguna blade\" in Lion. Damage : " << MyHero.damageSkillLina(3) << endl;
            cout << "\"4\" attack with hands hit in Lion" << endl;
            cout << "\"5\" kill creep and get gold(40) and expirience(100)" << endl;
            cout << "\"6\" improve the \"Dragon slave\". Your skillpoint: " << MyHero.getSkillpoint() << endl;
            cout << "\"7\" improve the \"Light strike array\". Your skillpoint: " << MyHero.getSkillpoint() << endl;
            cout << "\"8\" improve the \"Laguna blade\". Your skillpoint: " << MyHero.getSkillpoint() << endl;
            cin >> moving;
            switch (moving){
                case 1:
                    EnemyHero.takeDamage(MyHero.damageSkillLina(1));
                    break;
                case 2:
                    EnemyHero.takeDamage(MyHero.damageSkillLina(2));
                    EnemyHero.addMoving(MyHero.getSkipLight_strike());
                    break;
                case 3:
                    EnemyHero.takeDamage(MyHero.damageSkillLina(3));
                    break;
                case 4:
                    EnemyHero.takeDamage(MyHero.getHitDamage());
                    break;
                case 5:
                    MyHero.addGold(40);
                    MyHero.addExp(100);
                    break;
                case 6:
                    int howSkillPoing1;
                    cout << "How many time improve the \"Dragon slave\". You have \"" << MyHero.getSkillpoint() << "\" points." << endl;
                    cin >> howSkillPoing1;
                    MyHero.upLvlSkill(1,howSkillPoing1);
                    break;
                case 7:
                    int howSkillPoing2;
                    cout << "How many time improve the \"Dragon slave\"." << MyHero.getSkillpoint() << "\" points." << endl;
                    cin >> howSkillPoing2;
                    MyHero.upLvlSkill(2,howSkillPoing2);
                    break;
                case 8:
                    int howSkillPoing3;
                    cout << "How many time improve the \"Dragon slave\"." << MyHero.getSkillpoint() << "\" points." << endl;
                    cin >> howSkillPoing3;
                    MyHero.upLvlSkill(3,howSkillPoing3);
                    break;
                default:
                    break;
            }
            if (EnemyHero.getExpirience() >= 100){
                EnemyHero.lvlUpHero();
            }
        }
        else{
            cout << "Lina : skip move. Still skip move : \"" << MyHero.getMyMoving() << "\""<< endl;
            if (EnemyHero.getMyMoving() != 0){
                EnemyHero.addMoving(-1);
            }
        }
        cout << "##################################...TURN LION...##################################" << endl;
        cout << "LION STATS : " << endl;
        cout << "Lion : HealthPointMax : \"" << EnemyHero.getMaxHealthPoint() << "\". HealthPoint : " << "\" " << EnemyHero.getHealthPoint() << "\"." << endl;
        cout << "Lion : ManaPointMax : \"" << EnemyHero.getMaxManaPoint() << "\". ManaPoint : " << "\"" << EnemyHero.getManaPoint() << "\"." << endl;
        cout << "Lion : lvl : \"" << EnemyHero.getLvl() << "\"." << endl;
        cout << "Lion : skillpoint : \"" << EnemyHero.getSkillpoint() << "\"." << endl;
        cout << "Lion : gold : \"" << EnemyHero.getGold() << "\"." << endl;
        cout << "Lion : expirience \"" << EnemyHero.getExpirience() << "\". (200 experience required to level up)" << endl;
        if (EnemyHero.getMyMoving() == 0){
            cout << "\"1\" use \"Earth spike\" in Lion. Damage : " << EnemyHero.damageSkillLion(1) << " and stun : " << "\"" << EnemyHero.getSkipEarth_spike() << "\"" << endl;
            cout << "\"2\" use \"Hex\" in Lion. Stun : " << EnemyHero.getSkipEarth_spike() << endl;
            cout << "\"3\" use \"Finger death\" in Lion. Damage : " << EnemyHero.damageSkillLion(3) << endl;
            cout << "\"4\" attack with hands hit in Lion" << endl;
            cout << "\"5\" kill creep and get gold(40) and expirience(100)" << endl;
            cout << "\"6\" improve the \"Earth spike\". Your skillpoint: " << EnemyHero.getSkillpoint() << endl;
            cout << "\"7\" improve the \"Hex\". Your skillpoint: " << EnemyHero.getSkillpoint() <<   endl;
            cout << "\"8\" improve the \"Finger death\". Your skillpoint: " << EnemyHero.getSkillpoint() << endl;
            cin >> moving;
            switch (moving){
                case 1:
                    MyHero.takeDamage(EnemyHero.damageSkillLion(1));
                    MyHero.addMoving(EnemyHero.getSkipEarth_spike());
                    break;
                case 2:
                    MyHero.addMoving(EnemyHero.getSkipHex());
                    break;
                case 3:
                    MyHero.takeDamage(EnemyHero.damageSkillLion(3));
                    break;
                case 4:
                    MyHero.takeDamage(EnemyHero.getHitDamage());
                    break;
                case 5:
                    EnemyHero.addGold(40);
                    EnemyHero.addExp(100);
                    break;
                case 6:
                    int howSkillPoing1;
                    cout << "How many time improve the \"Earth spike\"." << EnemyHero.getSkillpoint() << "\" points." << endl;
                    cin >> howSkillPoing1;
                    EnemyHero.upLvlSkill(1,howSkillPoing1);
                    break;
                case 7:
                    int howSkillPoing2;
                    cout << "How many time improve the \"Hex\"." << EnemyHero.getSkillpoint() << "\" points." << endl;
                    cin >> howSkillPoing2;
                    EnemyHero.upLvlSkill(2,howSkillPoing2);
                    break;
                case 8:
                    int howSkillPoing3;
                    cout << "How many time improve the \"Finger death\"." << EnemyHero.getSkillpoint() << "\" points." << endl;
                    cin >> howSkillPoing3;
                    EnemyHero.upLvlSkill(3,howSkillPoing3);
                    break;
                default:
                    break;
            }
            if (EnemyHero.getExpirience() >= 100){
                EnemyHero.lvlUpHero();
            }
        }
        else{
            cout << "Lion : skip move. Still skip move : \"" << EnemyHero.getMyMoving() << "\""<< endl;
            if (EnemyHero.getMyMoving() != 0){
                EnemyHero.addMoving(-1);
            }
        }
    }
    return 0;
}