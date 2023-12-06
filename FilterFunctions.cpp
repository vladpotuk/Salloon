#include "FilterFunctions.h"
#include <iostream>
#include <limits>
#include <string>  // Додайте цей рядок

int FilterFunctions::getIntInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            break;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Введено некоректні дані. Спробуйте ще раз.\n";
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

double FilterFunctions::getDoubleInput(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            break;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Введено некоректні дані. Спробуйте ще раз.\n";
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

std::string FilterFunctions::getStringInput(const std::string& prompt) {
    std::string value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, value);
        if (!value.empty()) {
            break;
        }
        else {
            std::cout << "Введено некоректні дані. Спробуйте ще раз.\n";
        }
    }
    return value;
}
