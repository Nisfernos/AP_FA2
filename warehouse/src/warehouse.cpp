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
    for (Employee _employee : this->Employees) {
        if (_employee.getForkliftCertificate() && !_employee.getBusy()) {
            bool changes = true;
            while (changes) {
                changes = false;
                for (int i=0; i < shelf.pallets.size()-1; i++) {
                    if (shelf.pallets[i].getItemCount() > shelf.pallets[i+1].getItemCount()) {
                        shelf.swapPallet(i, i+1);
                        changes = true;
                    }
                }
            }
            return true;
        }
    }
};

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    int itemStock = 0;
    for (Shelf _shelf : this->Shelves) {
        for (Pallet _pallet : _shelf.pallets) {
            if (itemName == _pallet.getItemName()) {
                itemStock += _pallet.getItemCount();
            }
        }
    }

    if (itemStock < itemCount) {
        return false;
    }

    for (Shelf _shelf : this->Shelves) {
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
};
