#include "FilterRepository.h"
#include <algorithm>
#include <fstream>

std::vector<Employee> FilterRepository::employees;
std::vector<Car> FilterRepository::cars;
std::vector<Sale> FilterRepository::sales;

const std::vector<Employee>& FilterRepository::getEmployees() {
    return employees;
}

const std::vector<Car>& FilterRepository::getCars() {
    return cars;
}

const std::vector<Sale>& FilterRepository::getSales() {
    return sales;
}

void FilterRepository::addEmployee(const Employee& employee) {
    employees.push_back(employee);
}

void FilterRepository::removeEmployee(const std::string& name) {
    employees.erase(std::remove_if(employees.begin(), employees.end(),
        [&name](const Employee& emp) { return emp.name == name; }),
        employees.end());
}

void FilterRepository::addCar(const Car& car) {
    cars.push_back(car);
}

void FilterRepository::removeCar(const std::string& model) {
    cars.erase(std::remove_if(cars.begin(), cars.end(),
        [&model](const Car& c) { return c.model == model; }),
        cars.end());
}

void FilterRepository::addSale(const Sale& sale) {
    sales.push_back(sale);
}

void FilterRepository::removeSale(const std::string& saleDate) {
    sales.erase(std::remove_if(sales.begin(), sales.end(),
        [&saleDate](const Sale& sale) { return sale.saleDate == saleDate; }),
        sales.end());
}

void FilterRepository::saveDataToFile(const std::string& filename) {
    std::ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (const auto& emp : employees) {
            outputFile << "Employee," << emp.name << "," << emp.position << "," << emp.contactNumber << "," << emp.email << "\n";
        }

        for (const auto& car : cars) {
            outputFile << "Car," << car.manufacturer << "," << car.year << "," << car.model << "," << car.costPrice << "," << car.potentialSellingPrice << "\n";
        }

        for (const auto& sale : sales) {
            outputFile << "Sale," << sale.employee.name << "," << sale.car.model << "," << sale.saleDate << "," << sale.actualSellingPrice << "\n";
        }

        outputFile.close();
        std::cout << "Дані збережено у файл " << filename << ".\n";
    }
    else {
        std::cerr << "Не вдалося відкрити файл для запису.\n";
    }
}
