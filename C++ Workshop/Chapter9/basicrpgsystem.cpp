//    --Basice RPG Combat System--
//1. Create Classes for characters, attacks, and items with a name variable in each class that can be set to a constructor.
//2. Give attacks an attack statistic (attackStat) variable and items a heal statistic (healStat) variable. Add appropriate getters and setters and constructor additions.
//3. Let the characters accept an array of attacks and items in their constructor and store them to be looked up by name when they need to be used.
//4. Create functions to attack other characters, use items, and react to attacks.
//5. Create member variables called strengthMultiplier and defenseMultiplier. These should affect characters attacking and defense stats.
//6. Create a function to print a characters name and other statistics to the console.
//7. Test everything in a main function with a few different characters.
// Finally, Must be made from scracth
#include <iostream>
#include <memory>
#include <cstring>

class Characters{
    public:
    
    float getStrength() const {
        return m_strengthMultiplier;
    }
    float getDefense() const {
        return m_defenseMultiplier;
    }
    int getHealth() const {
        return m_health;
    }
    const char* getName() const {
        return m_name;
    }
    
    Attacks* getAttacks() const {
        return m_attacks;
    }
    
    int getAttackCount() const {
        return m_attackCount;
    }
    
    Items* getItems() const {
        return m_items;
    }
    
    
    Characters(const char* name, int health, float strengthMultiplier, float defenseMultiplier) {
        m_health = health;
        m_strengthMultiplier = strengthMultiplier;
        m_defenseMultiplier = defenseMultiplier;
        
        m_name = new char[strlen(name) +1];
        strcpy(m_name, name);
    }
        
    ~Characters() {
        delete[] m_name;
        delete[] m_attacks;
        delete[] m_items;
    }
    
    Characters(const Characters& characters) {
        m_health = characters.m_health;
        m_strengthMultiplier = characters.m_strengthMultiplier;
        m_defenseMultiplier = characters.m_defenseMultiplier;
        
        m_name = new char[strlen(characters.m_name) +1];
        strcpy(m_name, characters.m_name);
    }
    
    Characters& operator=(const Characters& characters) {
        if(this != &characters) {
            m_health = characters.m_health;
            m_strengthMultiplier = characters.m_strengthMultiplier;
            m_defenseMultiplier = characters.m_defenseMultiplier;
        
            delete[] m_name;
            m_name = new char[strlen(characters.m_name) +1];
            strcpy(m_name, characters.m_name);
        }
        return *this;
    }
    
    private:
    int m_health;
    char* m_name;
    float m_strengthMultiplier;
    float m_defenseMultiplier;
    
    Attacks* m_attacks;
    int m_attackCount;
    Items* m_items;
    int itemsCount;
    
    
};

class Attacks{
    public:
    
    int getAttackStat() const {
        return a_attackStat;
    }
    const char* getAttackName() const{
        return a_attackName;
    }
    
    Attacks(int attack, char* attackName){
        a_attackStat = attack;
        
        a_attackName = new char[strlen(attackName) +1];
        strcpy(a_attackName, attackName);
        
    }
    
    ~Attacks(){
        delete[] a_attackName;
    }
    
    Attacks(const Attacks& attacks) {
        a_attackStat = attacks.a_attackStat;
        
        a_attackName = new char[strlen(attacks.a_attackName) +1];
        strcpy(a_attackName, attacks.a_attackName);
    }
    
    Attacks& operator=(const Attacks& attacks) {
        if (this != &attacks) {
          a_attackStat =  attacks.a_attackStat;
          
          delete[] a_attackName;
          a_attackName = new char[strlen(attacks.a_attackName) +1];
          strcpy(a_attackName, attacks.a_attackName);
        }
        return *this;
    }
    
    private:
    int a_attackStat;
    char* a_attackName;
    
};

class Items{
    public:
    
    int getHealStat() {
        return i_healStat;
    }
    
    const char* getItemName() {
        return i_item_name;
    }
    
    Items(int heal, char* name) {
        i_healStat = heal;
        
        i_item_name = new char[strlen(name) +1];
        strcpy(i_item_name, name);
    }
    
    ~Items() {
        delete[] i_item_name;
    }
    
    Items(const Items& items) {
        i_healStat = items.i_healStat;
        
        i_item_name = new char[strlen(items.i_item_name) +1];
        strcpy(i_item_name, items.i_item_name);
    }
    
    Items& operator =(const Items& items) {
        if (this != &items) {
            i_healStat = items.i_healStat;
            
            delete[] i_item_name;
            i_item_name = new char[strlen(items.i_item_name) +1];
            strcpy(i_item_name, items.i_item_name);
        }
        return *this;
    }
    
    private:
    int i_healStat;
    char* i_item_name;
    
};

void combatLog(){
}

void attack(Character &target){
}

void printStats(){
}

int main(){
    
    return 0;
}
