#include "cooling_system.hpp"

int main() {
    CoolingSystem system(22.0); // Задана температура = 22°C[cite: 1]

    // Тестові значення температури
    double test_temperatures[] = { 25.0, 22.0, 19.5, 23.0 };

    for (double temp : test_temperatures) {
        std::cout << "\n----------------------------------------\n";
        system.readTemperatureSensor(temp);[cite: 1]
        system.processStep();[cite: 1]
    }

    return 0;
    }
