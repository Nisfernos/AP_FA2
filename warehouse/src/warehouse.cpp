#include "include/warehouse.hpp"

Warehouse::Warehouse() {
    /**
     * @brief Empty constructor for warehouse. It has no shelves or employees.
     */
    this->Employees = {};
    this->shelves = {};
};

void Warehouse::addEmployee(Employee employee) {
    /**
     * @brief This function adds an employee to the warehouse.
     * @param employee This is an employee of class Employee
     */
    this->Employees.push_back(employee);
};

void Warehouse::addShelf(Shelf shelf) {
    /**
     * @brief This function adds a shelf (of 4 pallets) to the warehouse.
     * @param shelf This is a shelf of class Shelf
     */
    this->shelves.push_back(shelf);
};

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    /**
     * @brief This rearragnes the pallets on the shelf in ascending item count order.
     * @param shelf This is the shelf of class Shelf that wants to be altered.
     */
    // First we check if there is an employee that is available and has a forkliftcertificate
    for (Employee _employee : this->Employees) {
        if (_employee.getForkliftCertificate() && !_employee.getBusy()) {
            // We loop through the shelf until no more swaps have been made
            bool changes = true;
            while (changes) {
                changes = false;
                // Here we loop through the shelf
                for (int i=0; i < (shelf.pallets.size()-1); i++) {
                    // If the two adjacent pallets on the shelf are not in ascending order, swap them
                    if (shelf.pallets[i].getItemCount() > shelf.pallets[i+1].getItemCount()) {
                        shelf.swapPallet(i, i+1);
                        // A change has been made
                        changes = true;
                    }
                }
            }
            // When we have swapped sorted the shelf in ascending item count order return true.
            return true;
        }
    }
    // If there was no available employee with a forkliftcertificate the shelf is not sorted and we return false.
    return false;
};

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    /**
     * @brief This function will pick a certain amount of items from the warehouse if there is enough stock.
     * @param itemName The name of the item that needs to be removed from the warehouse.
     * @param itemCount The amount of items that will be removed from the warehouse if the stock allows for it.
     */
    // First we check to see if there are enough items to fullfill the order
    int itemStock = 0;
    // We loop through all the shelves in the warehouse, and the pallets on those shelves
    for (Shelf _shelf : this->shelves) {
        for (Pallet _pallet : _shelf.pallets) {
            if (itemName == _pallet.getItemName()) {
                itemStock += _pallet.getItemCount();
            }
        }
    }

    // If there are less items in the warehouse than requested, we return false
    if (itemStock < itemCount) {
        return false;
    }

    // We loop again through all the pallets on the shelves in the warehouse
    for (Shelf _shelf : this->shelves) {
        for (Pallet _pallet : _shelf.pallets) {
            // If the pallet has the item we want, we take one from it, until it is empty, or we have gathered enough items
            if (itemName == _pallet.getItemName()) {
                while (!(_pallet.isEmtpy()) && itemCount > 0) {
                    _pallet.takeOne();
                    itemCount--;
                }
                // If we have gathered all the items we need, we return true
                if (itemCount == 0) {
                    return true;
                }
            }
        }
    }
    // The function should never end up here, but just in case.
    return false;
};
