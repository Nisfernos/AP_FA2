#include "include/warehouse.hpp"

Warehouse::Warehouse() {
    this->Employees = {};
    this->Shelves = {};
};

void Warehouse::addEmployee(Employee employee) {
    this->Employees.push_back(employee);
};

void Warehouse::addShelf(Shelf shelf) {
    this->Shelves.push_back(shelf);
};

bool Warehouse::rearrangeShelf(Shelf& shelf) {

};

bool Warehouse::pickItems(std::string itemName, int itemCount) {

};
