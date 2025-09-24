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
#include <cstring>

class Attacks {
public:
    Attacks() : a_attackStat(0), a_attackName(nullptr) {}  // default

    Attacks(int attack, const char* attackName) {
        a_attackStat = attack;
        a_attackName = new char[strlen(attackName) + 1];
        strcpy(a_attackName, attackName);
    }
    
    ~Attacks() { delete[] a_attackName; }

    Attacks(const Attacks& other) {
        a_attackStat = other.a_attackStat;
        a_attackName = new char[strlen(other.a_attackName) + 1];
        strcpy(a_attackName, other.a_attackName);
    }
    Attacks& operator=(const Attacks& other) {
        if (this != &other) {
            delete[] a_attackName;
            a_attackStat = other.a_attackStat;
            a_attackName = new char[strlen(other.a_attackName) + 1];
            strcpy(a_attackName, other.a_attackName);
        }
        return *this;
    }

    int getAttackStat() const { return a_attackStat; }
    const char* getAttackName() const { return a_attackName; }

private:
    int a_attackStat;
    char* a_attackName;
};

class Items {
public:
    Items() : i_healStat(0), i_item_name(nullptr) {}  // default

    Items(int heal, const char* name) {
        i_healStat = heal;
        i_item_name = new char[strlen(name) + 1];
        strcpy(i_item_name, name);
    }
    ~Items() { delete[] i_item_name; }

    Items(const Items& other) {
        i_healStat = other.i_healStat;
        i_item_name = new char[strlen(other.i_item_name) + 1];
        strcpy(i_item_name, other.i_item_name);
    }
    Items& operator=(const Items& other) {
        if (this != &other) {
            delete[] i_item_name;
            i_healStat = other.i_healStat;
            i_item_name = new char[strlen(other.i_item_name) + 1];
            strcpy(i_item_name, other.i_item_name);
        }
        return *this;
    }

    int getHealStat() const { return i_healStat; }
    const char* getItemName() const { return i_item_name; }

private:
    int i_healStat;
    char* i_item_name;
};

class Characters {
public:
    Characters(const char* name, int health,
               float strengthMultiplier, float defenseMultiplier,
               Attacks* attacks, int attackCount,
               Items* items, int itemCount)
    {
        m_health = health;
        m_strengthMultiplier = strengthMultiplier;
        m_defenseMultiplier = defenseMultiplier;

        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);

        m_attackCount = attackCount;
        m_attacks = new Attacks[attackCount];
        for (int i = 0; i < attackCount; i++) {
            m_attacks[i] = attacks[i];
        }

        m_itemCount = itemCount;
        m_items = new Items[itemCount];
        for (int i = 0; i < itemCount; i++) {
            m_items[i] = items[i];
        }
    }

    ~Characters() {
        delete[] m_name;
        delete[] m_attacks;
        delete[] m_items;
    }

    void attack(Characters& target, int attackIndex) {
        if (attackIndex < 0 || attackIndex >= m_attackCount) return;
        int rawDamage = m_attacks[attackIndex].getAttackStat() * m_strengthMultiplier;
        int finalDamage = rawDamage - (target.m_defenseMultiplier * 2); // simple formula
        if (finalDamage < 0) finalDamage = 0;
        target.m_health -= finalDamage;
        std::cout << m_name << " attacks " << target.m_name
                  << " with " << m_attacks[attackIndex].getAttackName()
                  << " for " << finalDamage << " damage!\n";
    }

    void useItem(int itemIndex) {
        if (itemIndex < 0 || itemIndex >= m_itemCount) return;
        int heal = m_items[itemIndex].getHealStat();
        m_health += heal;
        std::cout << m_name << " uses " << m_items[itemIndex].getItemName()
                  << " and heals " << heal << " HP!\n";
    }

    void printStats() const {
        std::cout << "Character: " << m_name
                  << " | HP: " << m_health
                  << " | STRx: " << m_strengthMultiplier
                  << " | DEFx: " << m_defenseMultiplier << "\n";
    }

private:
    int m_health;
    char* m_name;
    float m_strengthMultiplier;
    float m_defenseMultiplier;

    Attacks* m_attacks;
    int m_attackCount;
    Items* m_items;
    int m_itemCount;
};

int main() {
    Attacks warriorAttacks[] = { Attacks(10, "Slash"), Attacks(15, "Power Strike") };
    Items warriorItems[] = { Items(20, "Potion"), Items(50, "Mega Potion") };

    Attacks mageAttacks[] = { Attacks(12, "Fireball"), Attacks(20, "Lightning") };
    Items mageItems[] = { Items(30, "Herb") };

    Characters warrior("Warrior", 100, 1.5f, 1.0f, warriorAttacks, 2, warriorItems, 2);
    Characters mage("Mage", 80, 1.2f, 0.8f, mageAttacks, 2, mageItems, 1);

    warrior.printStats();
    mage.printStats();

    warrior.attack(mage, 0);
    mage.attack(warrior, 1);

    warrior.useItem(0);

    warrior.printStats();
    mage.printStats();
}
