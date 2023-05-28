#pragma once
#include "employee.hpp"
#include "shelf.hpp"
#include <vector>

class Warehouse {
    /**
     * @brief A class containing Employees and Shelves
     * @param Employees People that can perform tasks in the warehouse
     * @param shelves Entities where tasks can be performed on
     * In warehouse you can add employees and shelves.
     * You can rearrange the pallets on a shelf in ascending order.
     * You can pick items of the pallets on the shelf.
     */
    public:
        std::vector<Employee> Employees;
        std::vector<Shelf> shelves;

        Warehouse();
        void addEmployee(Employee employee);
        void addShelf(Shelf shelf);
        bool rearrangeShelf(Shelf& shelf);
        bool pickItems(std::string itemName, int itemCount);
};
