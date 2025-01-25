#include <iostream>
#include <string>
#include <algorithm> // std::min

class Chef {
public:
    Chef(std::string name) : chefName(name) {
        std::cout << "Chef " << chefName << " is created!" << std::endl;
    }

    ~Chef() {
        std::cout << "Chef " << chefName << " is destroyed!" << std::endl;
    }

    std::string getName() {
        return chefName;
    }

    int makeSalad(int servings) {
        int ingredientsNeeded = servings * 5;
        std::cout << "Chef " << chefName << " can make salad " << servings << " portions." << std::endl;
        return ingredientsNeeded;
    }

    int makeSoup(int servings) {
        int ingredientsNeeded = servings * 3;
        std::cout << "Chef " << chefName << " can make soup " << servings << " portions." << std::endl;
        return ingredientsNeeded;
    }

private:
    std::string chefName;
};

class ItalianChef : public Chef {
public:
    ItalianChef(std::string name) : Chef(name), password("pizza"), flour(0), water(0) {}

    bool askSecret(std::string pass, int flourAmount, int waterAmount) {
        if (pass.compare(password) == 0) {
            flour = flourAmount;
            water = waterAmount;
            makePizza();
            return true;
        }
        return false;
    }

private:
    std::string password;
    int flour;
    int water;

    void makePizza() {
        int pizzasCanMake = std::min(flour / 5, water / 5);
        if (pizzasCanMake > 0) {
            std::cout << "Making " << pizzasCanMake << " pizza(s). Ingredients used: "
                      << pizzasCanMake * 5 << " flour, " << pizzasCanMake * 5 << " water." << std::endl;
            flour -= pizzasCanMake * 5;
            water -= pizzasCanMake * 5;
        } else {
            std::cout << "Not enough ingredients to make pizza." << std::endl;
        }
    }
};

int main() {
    Chef chef("Gordon");
    std::cout << "Chef " << chef.getName() << " with " << chef.makeSalad(2) << " items can make salad." << std::endl;
    std::cout << "Chef " << chef.getName() << " with " << chef.makeSoup(4) << " items can make soup." << std::endl;

    ItalianChef italianChef("Mario");
    std::cout << "ItalianChef " << italianChef.getName() << " can make salad " << italianChef.makeSalad(1) << " portions." << std::endl;

    if (italianChef.askSecret("pizza", 12, 12)) {
        std::cout << "Password ok!" << std::endl;
    } else {
        std::cout << "Wrong password!" << std::endl;
    }

    return 0;
}
