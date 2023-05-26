#include "include/warehouse.hpp"

Warehouse::Warehouse() {
    /**
     * @brief 
     * @param 
     */
    this->Employees = {};
    this->shelves = {};
};

void Warehouse::addEmployee(Employee employee) {
    /**
     * @brief 
     * @param 
     */
    this->Employees.push_back(employee);
};

void Warehouse::addShelf(Shelf shelf) {
    /**
     * @brief 
     * @param 
     */
    this->shelves.push_back(shelf);
};

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    /**
     * @brief 
     * @param 
     */
    for (Employee _employee : this->Employees) {
        if (_employee.getForkliftCertificate() && !_employee.getBusy()) {
            bool changes = true;
            while (changes) {
                changes = false;
                for (int i=0; i < (shelf.pallets.size()-1); i++) {
                    if (shelf.pallets[i].getItemCount() > shelf.pallets[i+1].getItemCount()) {
                        shelf.swapPallet(i, i+1);
                        changes = true;
                    }
                }
            }
            return true;
        }
    }
    return false;
};

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    /**
     * @brief 
     * @param 
     */
    int itemStock = 0;
    for (Shelf _shelf : this->shelves) {
        for (Pallet _pallet : _shelf.pallets) {
            if (itemName == _pallet.getItemName()) {
                itemStock += _pallet.getItemCount();
            }
        }
    }

    if (itemStock < itemCount) {
        return false;
    }

    for (Shelf _shelf : this->shelves) {
        for (Pallet _pallet : _shelf.pallets) {
            if (itemName == _pallet.getItemName()) {
                while (!(_pallet.isEmtpy()) && itemCount > 0) {
                    _pallet.takeOne();
                    itemCount--;
                }
                if (itemCount == 0) {
                    return true;
                }
            }
        }
    }
    return false;
};
