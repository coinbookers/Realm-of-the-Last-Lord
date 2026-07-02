#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int randomEvent() {
    return std::rand() % 3;
}

void status(int power, int stability) {
    std::cout << "\n--- Kingdom Status ---\n";
    std::cout << "Royal Power: " << power << "\n";
    std::cout << "World Stability: " << stability << "\n";
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int royalPower = 10;
    int stability = 10;
    int turns = 8;

    std::cout << "=== Realm of the Last Lord ===\n";

    for (int i = 1; i <= turns; i++) {
        std::cout << "\nTurn " << i << "\n";
        std::cout << "Choose action: (1) Rule (2) Observe (3) Restore -> ";

        int choice;
        std::cin >> choice;

        int event = randomEvent();

        if (choice == 1) {
            std::cout << "You issue commands across the land.\n";
            royalPower += 2;
            stability -= event;
        } else if (choice == 2) {
            std::cout << "You observe movements of humans.\n";
            stability += 1;
        } else {
            std::cout << "You attempt to restore balance.\n";
            stability += 2;
            royalPower -= 1;
        }

        if (event == 0)
            std::cout << "Ancient forces remain silent.\n";
        else if (event == 1)
            std::cout << "Disturbance spreads across regions.\n";
        else
            std::cout << "A calm wave stabilizes the land.\n";

        status(royalPower, stability);

        if (royalPower <= 0 || stability <= 0) {
            std::cout << "\nThe realm collapses...\n";
            return 0;
        }
    }

    std::cout << "\nFinal Outcome Reached\n";

    if (royalPower > stability)
        std::cout << "The lord's influence dominates the world.\n";
    else
        std::cout << "Balance is restored among all beings.\n";

    return 0;
}
