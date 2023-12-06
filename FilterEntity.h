#ifndef FILTERENTITY_H

#define FILTERENTITY_H

#include <string>
#include <iostream>

struct Employee {
    std::string name;
    std::string position;
    std::string contactNumber;
    std::string email;
};

struct Car {
    std::string manufacturer;
    int year;
    std::string model;
    double costPrice;
    double potentialSellingPrice;
};

struct Sale {
    Employee employee;
    Car car;
    std::string saleDate;
    double actualSellingPrice;
};

void printEmployee(const Employee& emp);
void printCar(const Car& car);
void printSale(const Sale& sale);

#endif // FILTERENTITY_H
