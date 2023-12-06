#include "LocalDataSource.h"
#include <fstream>
#include <iostream>
#include <sstream>

void LocalDataSource::saveDataToFile() {
    std::ofstream outputFile("data.txt");

    if (outputFile.is_open()) {
        for (const auto& emp : FilterRepository::employees) {
            outputFile << "Employee," << emp.name << "," << emp.position << "," << emp.contactNumber << "," << emp.email << "\n";
        }

        for (const auto& car : FilterRepository::cars) {
            outputFile << "Car," << car.manufacturer << "," << car.year << "," << car.model << "," << car.costPrice << "," << car.potentialSellingPrice << "\n";
        }

        for (const auto& sale : FilterRepository::sales) {
            outputFile << "Sale," << sale.employee.name << "," << sale.car.model << "," << sale.saleDate << "," << sale.actualSellingPrice << "\n";
        }

        outputFile.close();
        std::cout << "Дані збережено у файл.\n";
    }
    else {
        std::cerr << "Не вдалося відкрити файл для запису.\n";
    }
}

void LocalDataSource::loadDataFromFile() {
    FilterRepository::employees.clear();
    FilterRepository::cars.clear();
    FilterRepository::sales.clear();

    std::ifstream inputFile("data.txt");

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string type;
            iss >> type;

            if (type == "Employee") {
                Employee emp;
                iss >> emp.name >> emp.position >> emp.contactNumber >> emp.email;
                FilterRepository::employees.push_back(emp);
            }
            else if (type == "Car") {
                Car car;
                iss >> car.manufacturer >> car.year >> car.model >> car.costPrice >> car.potentialSellingPrice;
                FilterRepository::cars.push_back(car);
            }
            else if (type == "Sale") {
                Sale sale;
                iss >> sale.employee.name >> sale.car.model >> sale.saleDate >> sale.actualSellingPrice;
                FilterRepository::sales.push_back(sale);
            }
        }

        inputFile.close();
        std::cout << "Дані завантажено з файлу.\n";
    }
    else {
        std::cerr << "Не вдалося відкрити файл для читання.\n";
    }
}