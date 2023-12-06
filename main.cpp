#include "FilterScreen.h"
#include "FilterFunctions.h"
#include "FilterEntity.h"
#include "FilterRepository.h"
#include "LocalDataSource.h"

int main() {
    system("chcp 1251");
    system("cls");

    LocalDataSource::loadDataFromFile();

    int choice;
    do {
        FilterScreen::showMainMenu();
        choice = FilterFunctions::getIntInput("Оберіть опцію: ");

        switch (choice) {
        case 1:
            do {
                FilterScreen::showEmployeeMenu();
                choice = FilterFunctions::getIntInput("Оберіть опцію: ");

                switch (choice) {
                case 1:
                {
                    Employee emp;
                    emp.name = FilterFunctions::getStringInput("Введіть ім'я співробітника: ");
                    emp.position = FilterFunctions::getStringInput("Введіть посаду співробітника: ");
                    emp.contactNumber = FilterFunctions::getStringInput("Введіть контактний номер співробітника: ");
                    emp.email = FilterFunctions::getStringInput("Введіть електронну адресу співробітника: ");

                    FilterRepository::addEmployee(emp);
                    FilterRepository::saveDataToFile("data.txt");
                }
                break;

                case 2:
                {
                    std::string name = FilterFunctions::getStringInput("Введіть ім'я співробітника, якого ви хочете видалити: ");
                    FilterRepository::removeEmployee(name);
                    FilterRepository::saveDataToFile("data.txt");
                }
                break;

                case 0:
                    break;
                }
            } while (choice != 0);
            break;

        case 2:
            do {
                FilterScreen::showCarMenu();
                choice = FilterFunctions::getIntInput("Оберіть опцію: ");

                switch (choice) {
                case 1:
                {
                    Car car;
                    car.manufacturer = FilterFunctions::getStringInput("Введіть виробника автомобіля: ");
                    car.year = FilterFunctions::getIntInput("Введіть рік випуску автомобіля: ");
                    car.model = FilterFunctions::getStringInput("Введіть модель автомобіля: ");
                    car.costPrice = FilterFunctions::getDoubleInput("Введіть вартість автомобіля: ");
                    car.potentialSellingPrice = FilterFunctions::getDoubleInput("Введіть потенційну ціну продажу автомобіля: ");

                    FilterRepository::addCar(car);
                    FilterRepository::saveDataToFile("data.txt");
                }
                break;

                case 2:
                {
                    std::string model = FilterFunctions::getStringInput("Введіть модель автомобіля, яку ви хочете видалити: ");
                    FilterRepository::removeCar(model);
                    FilterRepository::saveDataToFile("data.txt");
                }
                break;

                case 0:
                    break;
                }
            } while (choice != 0);
            break;
            // Оновіть ваш main.cpp, щоб взаємодіяти з опцією продажу
        case 3:
            do {
                FilterScreen::showSalesMenu();
                choice = FilterFunctions::getIntInput("Оберіть опцію: ");

                switch (choice) {
                case 1:
                    // Додати продаж
                {
                    Sale sale;
                    sale.employee.name = FilterFunctions::getStringInput("Введіть ім'я співробітника, який здійснює продаж: ");
                    sale.car.model = FilterFunctions::getStringInput("Введіть модель автомобіля, який продано: ");
                    sale.saleDate = FilterFunctions::getStringInput("Введіть дату продажу (наприклад, 2023-12-31): ");
                    sale.actualSellingPrice = FilterFunctions::getDoubleInput("Введіть фактичну ціну продажу: ");

                    FilterRepository::addSale(sale);
                    FilterRepository::saveDataToFile("data.txt");
                }
                break;

                case 2:
                    // Видалити продаж
                {
                    std::string saleDate = FilterFunctions::getStringInput("Введіть дату продажу, який ви хочете видалити (наприклад, 2023-12-31): ");
                    FilterRepository::removeSale(saleDate);
                    FilterRepository::saveDataToFile("data.txt");
                }
                break;

                case 0:
                    // Повернутися до головного меню
                    break;
                }
            } while (choice != 0);
            break;


        case 0:

            break;
        }
    } while (choice != 0);

    return 0;
}
