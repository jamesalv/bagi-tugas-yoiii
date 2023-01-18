#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Weapon {
    std::string name;
    int damage;
};

bool compareByDamage(const Weapon& a, const Weapon& b) {
    return a.damage < b.damage;
}

int main() {
    int T;
    std::cin >> T;

    std::vector<Weapon> weapons;
    weapons.reserve(T);

    // Input weapons
    for (int i = 0; i < T; i++) {
        std::string name;
        int damage;
        std::cin >> name >> damage;
        weapons.push_back({name, damage});
    }

    // Sort weapons by damage
    std::sort(weapons.begin(), weapons.end(), compareByDamage);

    // Output sorted weapons
    for (const auto& weapon : weapons) {
        std::cout << weapon.name << " " << weapon.damage << std::endl;
    }

    return 0;
}
