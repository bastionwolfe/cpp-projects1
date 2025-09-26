// convert rpg combat to standerd library containers
//1. Alter attack, Item and character classes to use strings
//2. remove any now unndeed copy constructors destructors and assignment implementations
//3. get character class to take vectors from attack and items instead of raw arrays
//4. Implement the attack and defend functions to use vecotrs and update display functino to use vectors
//5. in main functino implement a queue that holds different character types for the player to fight
//6. fight each monster in queue and display a win string also allow the use of items and a default attack
#include <iostream>
#include <string>
#include <vector>
#include <queue>

class Attack {
public:
    Attack(int stat, const std::string& name)
        : attackStat(stat), attackName(name) {}

    int getStat() const { return attackStat; }
    const std::string& getName() const { return attackName; }

private:
    int attackStat;
    std::string attackName;
};

class Item {
public:
    Item(int heal, const std::string& name)
        : healStat(heal), itemName(name) {}

    int getHeal() const { return healStat; }
    const std::string& getName() const { return itemName; }

private:
    int healStat;
    std::string itemName;
};

class Character {
public:
    Character(const std::string& name, int hp,
              float strength, float defense,
              const std::vector<Attack>& attacks,
              const std::vector<Item>& items)
        : m_name(name), m_health(hp),
          m_strengthMultiplier(strength),
          m_defenseMultiplier(defense),
          m_attacks(attacks), m_items(items) {}

    void attack(Character& target, int attackIndex) const {
        if (attackIndex < 0 || attackIndex >= m_attacks.size()) return;

        int raw = static_cast<int>(m_attacks[attackIndex].getStat() * m_strengthMultiplier);
        int finalDamage = raw - static_cast<int>(target.m_defenseMultiplier * 2);
        if (finalDamage < 0) finalDamage = 0;

        target.m_health -= finalDamage;
        std::cout << m_name << " attacks " << target.m_name
                  << " with " << m_attacks[attackIndex].getName()
                  << " for " << finalDamage << " damage!\n";
    }

    void useItem(int index) {
        if (index < 0 || index >= m_items.size()) return;
        int heal = m_items[index].getHeal();
        m_health += heal;
        std::cout << m_name << " uses " << m_items[index].getName()
                  << " and heals " << heal << " HP!\n";
    }

    void printStats() const {
        std::cout << "Character: " << m_name
                  << " | HP: " << m_health
                  << " | STRx: " << m_strengthMultiplier
                  << " | DEFx: " << m_defenseMultiplier << "\n";
    }

    bool isAlive() const { return m_health > 0; }

    const std::string& getName() const { return m_name; }

private:
    std::string m_name;
    int m_health;
    float m_strengthMultiplier;
    float m_defenseMultiplier;

    std::vector<Attack> m_attacks;
    std::vector<Item> m_items;
};

int main() {
    // Player character
    std::vector<Attack> playerAttacks = {
        {10, "Slash"},
        {15, "Power Strike"}
    };
    std::vector<Item> playerItems = {
        {20, "Potion"},
        {50, "Mega Potion"}
    };
    Character player("Hero", 100, 1.5f, 1.0f, playerAttacks, playerItems);

    // Queue of monsters
    std::queue<Character> monsterQueue;

    // Create monsters
    monsterQueue.emplace("Goblin", 50, 1.2f, 0.8f,
                         std::vector<Attack>{ {8, "Stab"} },
                         std::vector<Item>{});
    monsterQueue.emplace("Orc", 80, 1.4f, 1.0f,
                         std::vector<Attack>{ {12, "Club Smash"} },
                         std::vector<Item>{});
    monsterQueue.emplace("Dragon", 150, 2.0f, 1.5f,
                         std::vector<Attack>{ {20, "Fire Breath"}, {15, "Tail Swipe"} },
                         std::vector<Item>{});

    // Combat loop
    while (!monsterQueue.empty() && player.isAlive()) {
        Character& monster = monsterQueue.front();

        std::cout << "\n--- A wild " << monster.getName() << " appears! ---\n";
        player.printStats();
        monster.printStats();

        // Turn-based combat
        int turn = 0;
        while (player.isAlive() && monster.isAlive()) {
            std::cout << "\nTurn " << ++turn << ":\n";
            player.attack(monster, 0);

            if (monster.isAlive()) {
                monster.attack(player, 0);
            }

            if (player.isAlive() && playerItems.size() > 0 && playerItems[0].getHeal() + 10 < playerItems[0].getHeal()) {
                player.useItem(0);
            }

            player.printStats();
            monster.printStats();
        }

        if (player.isAlive()) {
            std::cout << "\nYou defeated the " << monster.getName() << "!\n";
            monsterQueue.pop();
        } else {
            std::cout << "\nYou were defeated by the " << monster.getName() << "...\n";
        }
    }

    if (player.isAlive()) {
        std::cout << "\nYou defeated all the monsters! You Win!\n";
    } else {
        std::cout << "\n💀 Game Over.\n";
    }

    return 0;
}
