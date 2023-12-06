#include "FilterEntity.h"

void printEmployee(const Employee& emp) {
    std::cout << "Співробітник: " << emp.name << ", Посада: " << emp.position << "\n";
}

void printCar(const Car& car) {
    std::cout << "Автомобіль: " << car.manufacturer << " " << car.model << ", Рік: " << car.year << "\n";
}

void printSale(const Sale& sale) {
    std::cout << "Продаж: " << sale.saleDate << ", Співробітник: " << sale.employee.name << ", Автомобіль: " << sale.car.model << "\n";
}



