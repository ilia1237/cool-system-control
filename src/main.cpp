#ifndef COOLING_SYSTEM_HPP
#define COOLING_SYSTEM_HPP

#include <iostream>
#include <thread>
#include <chrono>

class CoolingSystem {
private:
    double t_B = 22.0; // Задана температура (°C)[cite: 1]
    double t_C = 0.0;  // Поточна температура (°C)[cite: 1]
    int T_D = 0;       // Час затримки (секунди)[cite: 1]

public:
    CoolingSystem(double target_temp = 22.0) : t_B(target_temp) {}

    // Симуляція датчика температури[cite: 1]
    void readTemperatureSensor(double current_temp) {
        t_C = current_temp;
        std::cout << "[Sensor] Поточна температура (t_C): " << t_C << "°C\n";
    }

    // Перевірка стану системи Echeck()[cite: 1]
    void Echeck() {
        std::cout << "[Echeck] Перевірка системних параметрів та цілісності...\n";
    }

    // Керування охолодженням Kiri.ttCooling()[cite: 1]
    void Kiri_ttCooling() {
        std::cout << "[Kiri.ttCooling] Застосування затримки T_D = " << T_D << " c...\n";
        std::this_thread::sleep_for(std::chrono::seconds(T_D));
    }

    // Основний цикл алгоритму[cite: 1]
    void processStep() {
        // Умова t_C >= t_B[cite: 1]
        if (t_C >= t_B) {
            T_D = 2; // Вимкнути затримку / базовий режим (2 с)[cite: 1]
            std::cout << "[Logic] t_C >= t_B -> Так (T_D = 2 c, Вимкнути)\n";[cite: 1]
        } else {
            T_D = 4; // Ввімкнути активне охолодження / затримка (4 с)[cite: 1]
            std::cout << "[Logic] t_C >= t_B -> Ні (T_D = 4 c, Ввімкнути)\n";[cite: 1]
        }

        Echeck();[cite: 1]
        Kiri_ttCooling();[cite: 1]
    }
};

#endif
