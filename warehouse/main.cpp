#include <iostream>
#include "src/include/warehouse.hpp"


void print_pallet(Pallet _pallet) {
    std::cout << "This pallet has " << _pallet.getItemCount() << " of product " << _pallet.getItemName() << " and has " 
                << _pallet.getRemainingSpace() << " remaining slots." << std::endl;
}


void print_shelf(Shelf _shelf) {
    std::cout << "This shelf has: " << std::endl;
    for (Pallet _pallet : _shelf.pallets) {
        print_pallet(_pallet);
    }
    std::cout << std::endl;
}


void print_employee(Employee _employee) {
    std::cout << "We have an employee named " << _employee.getName() << " who has ";
        if (_employee.getForkliftCertificate()) {
            std::cout << "a ";
        }
        else {
            std::cout << "no ";
        }
        std::cout << "forkliftcertificate," << std::endl;
        std::cout << "and is currently ";
        if (!_employee.getBusy()) {
            std::cout << "not ";
        }
        std::cout << "busy." << std::endl;
    std::cout << std::endl;
}


int main() {
    // In this file we will show that the the classes and functions are working properly.
    
    // Construct warehouse with 4 different items on 1 shelf
    Warehouse warehouse = Warehouse();
    
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Apple", 100, 20), 
        Pallet("Banana", 100, 30), 
        Pallet("Lemon", 100, 40), 
        Pallet("Pear", 100, 10)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Apple", 100, 100), 
        Pallet("Apple", 100, 100), 
        Pallet("Apple", 100, 100), 
        Pallet("Apple", 100, 100)
    };

    Shelf shelf3 = Shelf();
    shelf3.pallets = {
        Pallet("Apple", 100, 0), 
        Pallet("Banana", 100, 0), 
        Pallet("Pear", 100, 0), 
        Pallet("Lemon", 100, 0)
    };

    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addShelf(shelf3);

    warehouse.addEmployee(Employee("James", false));
    warehouse.addEmployee(Employee("Alice", false));

    // Print everything about the warehouse
    std::cout << "The warehouse has " << warehouse.shelves.size() << " shelves." << std::endl;
    std::cout << "The warehouse has " << warehouse.Employees.size() << " employees." << std::endl << std::endl;

    // Print all shelves
    for (Shelf _shelf : warehouse.shelves) {
        print_shelf(_shelf);
    }

    // Print all employees
    for (Employee _employee : warehouse.Employees) {
        print_employee(_employee);
    }


    // Reallocate a non-empty pallet
    std::cout << "Reallocating a non-empty pallet doesn't work." << std::endl;
    print_pallet(warehouse.shelves[0].pallets[2]);
    warehouse.shelves[0].pallets[2].reallocateEmptyPallet("Toys", 20);
    print_pallet(warehouse.shelves[0].pallets[2]);
    std::cout << std::endl;

    // Reallocate an empty pallet
    std::cout << "Reallocating an empty pallet does work." << std::endl;
    print_pallet(warehouse.shelves[2].pallets[0]);
    warehouse.shelves[2].pallets[0].reallocateEmptyPallet("Toys", 20);
    print_pallet(warehouse.shelves[2].pallets[0]);
    std::cout << std::endl;

    // Take one from an empty pallet
    std::cout << "Take one from an empty pallet does nothing." << std::endl;
    print_pallet(warehouse.shelves[2].pallets[1]);
    warehouse.shelves[2].pallets[1].takeOne();
    print_pallet(warehouse.shelves[2].pallets[1]);
    std::cout << std::endl;

    // Take one from a non-empty pallet
    std::cout << "Take one from a non-empty pallet reduces the stock by one." << std::endl;
    print_pallet(warehouse.shelves[0].pallets[2]);
    warehouse.shelves[0].pallets[2].takeOne();
    print_pallet(warehouse.shelves[0].pallets[2]);
    std::cout << std::endl;

    // Put one on an full pallet
    std::cout << "Put one on a full pallet does nothing." << std::endl;
    print_pallet(warehouse.shelves[1].pallets[2]);
    warehouse.shelves[1].pallets[2].putOne();
    print_pallet(warehouse.shelves[1].pallets[2]);
    std::cout << std::endl;

    // Put one on a non-full pallet
    std::cout << "Put one on a non-full pallet increases it's stock by one." << std::endl;
    print_pallet(warehouse.shelves[0].pallets[2]);
    warehouse.shelves[0].pallets[2].putOne();
    print_pallet(warehouse.shelves[0].pallets[2]);
    std::cout << std::endl;

    // This pallet is full
    std::cout << "Returns true if the pallet is full." << std::endl;
    print_pallet(warehouse.shelves[1].pallets[3]);
    std::cout << warehouse.shelves[1].pallets[3].isFull() << std::endl;
    std::cout << std::endl;

    // This pallet is not full
    std::cout << "Return false if the pallet is not full." << std::endl;
    print_pallet(warehouse.shelves[0].pallets[3]);
    std::cout << warehouse.shelves[0].pallets[3].isFull() << std::endl;
    std::cout << std::endl;

    // This pallet is empty
    std::cout << "Returns true when the pallet is empty." << std::endl;
    print_pallet(warehouse.shelves[2].pallets[3]);
    std::cout << warehouse.shelves[2].pallets[3].isEmtpy() << std::endl;
    std::cout << std::endl;

    // This pallet is not empty
    std::cout << "Return false when the pallet is not empty." << std::endl;
    print_pallet(warehouse.shelves[1].pallets[3]);
    std::cout << warehouse.shelves[1].pallets[3].isEmtpy() << std::endl;
    std::cout << std::endl;

    // Swap pallets 2 and three on a shelf
    std::cout << "Swap pallets two and three on a shelf." << std::endl;
    print_shelf(warehouse.shelves[0]);
    warehouse.shelves[0].swapPallet(1, 2);
    print_shelf(warehouse.shelves[0]);
    std::cout << std::endl;

    // This shelf is empty
    std::cout << "Return true when the shelf is empty." << std::endl;
    print_shelf(warehouse.shelves[2]);
    std::cout << warehouse.shelves[2].isEmtpy() << std::endl;
    std::cout << std::endl;

    // This shelf is not empty
    std::cout << "Return false when the shelf is not empty." << std::endl;
    print_shelf(warehouse.shelves[1]);
    std::cout << warehouse.shelves[1].isEmtpy() << std::endl;
    std::cout << std::endl;

    // This shelf is full
    std::cout << "Return true when the shelf is full." << std::endl;
    print_shelf(warehouse.shelves[1]);
    std::cout << warehouse.shelves[1].isFull() << std::endl;
    std::cout << std::endl;

    // This shelf is not full
    std::cout << "Returns false when the shelf is not full." << std::endl;
    print_shelf(warehouse.shelves[0]);
    std::cout << warehouse.shelves[0].isFull() << std::endl;
    std::cout << std::endl;

    // Set an employee to busy
    std::cout << "Set an employee to busy." << std::endl;
    print_employee(warehouse.Employees[1]);
    warehouse.Employees[1].setBusy(true);
    print_employee(warehouse.Employees[1]);
    std::cout << std::endl;

    // Alter whether an employee has a forkliftcertificate
    std::cout << "Alter whether an employee has a forkliftcertificate." << std::endl;
    print_employee(warehouse.Employees[0]);
    warehouse.Employees[0].setForkliftCertificate(true);
    print_employee(warehouse.Employees[0]);
    std::cout << std::endl;

    // Rearrange a shelf
    std::cout << "Rearrange a shelf in ascending order." << std::endl;
    print_shelf(warehouse.shelves[0]);
    warehouse.rearrangeShelf(warehouse.shelves[0]);
    print_shelf(warehouse.shelves[0]);
    std::cout << std::endl;

    // Pick items with enough stock
    std::cout << "Pick 14 bananas when there is enough stock." << std::endl;
    print_shelf(warehouse.shelves[0]);
    std::cout << warehouse.pickItems("Banana", 14) << std::endl;
    print_shelf(warehouse.shelves[0]);
    std::cout << std::endl;

    // Pick items with not enough stock
    std::cout << "Pick 45 lemons when there is not enough stock." << std::endl;
    print_shelf(warehouse.shelves[0]);
    std::cout << warehouse.pickItems("Lemon", 45) << std::endl;
    print_shelf(warehouse.shelves[0]);
    std::cout << std::endl;

}
