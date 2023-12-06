#ifndef FILTERREPOSITORY_H
#define FILTERREPOSITORY_H

#include "FilterEntity.h"
#include <vector>

struct FilterRepository {
    static std::vector<Employee> employees;
    static std::vector<Car> cars;
    static std::vector<Sale> sales;

    static void addEmployee(const Employee& employee);
    static void removeEmployee(const std::string& name);

    static void addCar(const Car& car);
    static void removeCar(const std::string& model);

    static void addSale(const Sale& sale);
    static void removeSale(const std::string& saleDate);

    static const std::vector<Employee>& getEmployees();
    static const std::vector<Car>& getCars();
    static const std::vector<Sale>& getSales();

    static void saveDataToFile(const std::string& filename);
};

#endif // FILTERREPOSITORY_H

