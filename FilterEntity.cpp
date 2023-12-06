#include "FilterEntity.h"

void printEmployee(const Employee& emp) {
    std::cout << "����������: " << emp.name << ", ������: " << emp.position << "\n";
}

void printCar(const Car& car) {
    std::cout << "���������: " << car.manufacturer << " " << car.model << ", г�: " << car.year << "\n";
}

void printSale(const Sale& sale) {
    std::cout << "������: " << sale.saleDate << ", ����������: " << sale.employee.name << ", ���������: " << sale.car.model << "\n";
}



