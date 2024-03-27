class Hero {
private:
    std::string name;
    int health;
    int currentHealth;
    int damage;
    std::vector<Item> items;
    int armor;
    int experience;
    int level;
    HealthBar healthBar;

public:
    Hero(const std::string& heroName, int baseHealth, int baseDamage)
        : name(heroName), health(baseHealth), currentHealth(baseHealth),
        damage(baseDamage), armor(0), experience(0), level(1), healthBar(baseHealth) {}

    ~Hero() {
        std::cout << "Hero " << name << " has been defeated!" << std::endl;
    }

    void gainExperience(int exp) {
        experience += exp;
        std::cout << name << " gained " << exp << " experience points." << std::endl;
        levelUp();
    }

    void
        giveD
        ive
        Damage(Hero& enemy) {
        int totalDamage = damage + calculateTotalDamageBoost();
        enemy.takeDamage(totalDamage);
        std::cout << name << " dealt " << totalDamage << " damage to " << enemy.name << "." << std::endl;
    }

    void displayHealthBar() const {
        int healthBarLength = 100;
        int remainingHealthBar = static_cast<int>((static_cast<double>(currentHealth) / health) * healthBarLength);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        for (int i = 0; i < healthBarLength - remainingHealthBar; ++i) {
            std::cout << "#";
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        for (int i = 0; i < remainingHealthBar; ++i) {
            std::cout << "#";
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }

    void takeDamage(int damageTaken) {
        int totalArmor = calculateTotalArmorBoost();
        int damageReceived = std::max(0, damageTaken - totalArmor);
        currentHealth -= damageReceived;
        displayHealthBar();
        checkDeath();
    }

    void heal(int amount) {
        currentHealth = std::min(health, currentHealth + amount);
        healthBar.update(currentHealth, health, 0);
        std::cout << name << " healed for " << amount << " health points." << std::endl;
    }

    void levelUp() {
        int experienceToLevelUp = level * 100;
        if (experience >= experienceToLevelUp) {
            ++level;
            health += 10;
            damage += 5;
            std::cout << name << " leveled up to level " << level << "!" << std::endl;
            experience -= experienceToLevelUp;
            levelUp();
        }
    }

    void equipItem(const Item& newItem) {
        items.push_back(newItem);
        std::cout << name << " equipped " << newItem.name << "." << std::endl;
    }

    int calculateTotalDamageBoost() const {
        int totalBoost = 0;
        for (const auto& item : items) {
            totalBoost += item.damageBoost;
        }
        return totalBoost;
    }
    void equipArmor(Armor& newArmor) {
        armor += newArmor.giveArmor();
    }
    int calculateTotalArmorBoost() const {
        int totalBoost = 0;
        for (const auto& item : items) {
            totalBoost += item.armorBoost;
        }
        return totalBoost + armor;
    }

    void checkDeath() const {
        if (currentHealth <= 0) {
            std::cout << name << " has been defeated!" << std::endl;
        }
    }
    std::string getName() {
        return name;
    }
};

