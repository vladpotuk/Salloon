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
        choice = FilterFunctions::getIntInput("������ �����: ");

        switch (choice) {
        case 1:
            do {
                FilterScreen::showEmployeeMenu();
                choice = FilterFunctions::getIntInput("������ �����: ");

                switch (choice) {
                case 1:
                {
                    Employee emp;
                    emp.name = FilterFunctions::getStringInput("������ ��'� �����������: ");
                    emp.position = FilterFunctions::getStringInput("������ ������ �����������: ");
                    emp.contactNumber = FilterFunctions::getStringInput("������ ���������� ����� �����������: ");
                    emp.email = FilterFunctions::getStringInput("������ ���������� ������ �����������: ");

                    FilterRepository::addEmployee(emp);
                    FilterRepository::saveDataToFile("data.txt");
                }
                break;

                case 2:
                {
                    std::string name = FilterFunctions::getStringInput("������ ��'� �����������, ����� �� ������ ��������: ");
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
                choice = FilterFunctions::getIntInput("������ �����: ");

                switch (choice) {
                case 1:
                {
                    Car car;
                    car.manufacturer = FilterFunctions::getStringInput("������ ��������� ���������: ");
                    car.year = FilterFunctions::getIntInput("������ �� ������� ���������: ");
                    car.model = FilterFunctions::getStringInput("������ ������ ���������: ");
                    car.costPrice = FilterFunctions::getDoubleInput("������ ������� ���������: ");
                    car.potentialSellingPrice = FilterFunctions::getDoubleInput("������ ���������� ���� ������� ���������: ");

                    FilterRepository::addCar(car);
                    FilterRepository::saveDataToFile("data.txt");
                }
                break;

                case 2:
                {
                    std::string model = FilterFunctions::getStringInput("������ ������ ���������, ��� �� ������ ��������: ");
                    FilterRepository::removeCar(model);
                    FilterRepository::saveDataToFile("data.txt");
                }
                break;

                case 0:
                    break;
                }
            } while (choice != 0);
            break;
            // ������ ��� main.cpp, ��� ��������� � ������ �������
        case 3:
            do {
                FilterScreen::showSalesMenu();
                choice = FilterFunctions::getIntInput("������ �����: ");

                switch (choice) {
                case 1:
                    // ������ ������
                {
                    Sale sale;
                    sale.employee.name = FilterFunctions::getStringInput("������ ��'� �����������, ���� ������� ������: ");
                    sale.car.model = FilterFunctions::getStringInput("������ ������ ���������, ���� �������: ");
                    sale.saleDate = FilterFunctions::getStringInput("������ ���� ������� (���������, 2023-12-31): ");
                    sale.actualSellingPrice = FilterFunctions::getDoubleInput("������ �������� ���� �������: ");

                    FilterRepository::addSale(sale);
                    FilterRepository::saveDataToFile("data.txt");
                }
                break;

                case 2:
                    // �������� ������
                {
                    std::string saleDate = FilterFunctions::getStringInput("������ ���� �������, ���� �� ������ �������� (���������, 2023-12-31): ");
                    FilterRepository::removeSale(saleDate);
                    FilterRepository::saveDataToFile("data.txt");
                }
                break;

                case 0:
                    // ����������� �� ��������� ����
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
