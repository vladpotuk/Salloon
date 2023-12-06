#ifndef FILTERFUNCTIONS_H
#define FILTERFUNCTIONS_H

#include <iostream>
#include <limits>

struct FilterFunctions {
    static int getIntInput(const std::string& prompt);
    static double getDoubleInput(const std::string& prompt);
    static std::string getStringInput(const std::string& prompt);
};

#endif // FILTERFUNCTIONS_H

