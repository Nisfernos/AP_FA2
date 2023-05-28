#include "include/catch.hpp"

#include "../src/include/warehouse.hpp"
#include <iostream>

///////////////////////////////////////////////////////////////
//                                                           //
//                    Warehouse unittests                    //
//                                                           //
///////////////////////////////////////////////////////////////
//                                                           //
// This file contains all testcases for the Warehouse class. //
// Currently it only contains tests for the rearranging of   //
// shelves. All other Warehouse functions will also need to  //
// be tested. You will have to do this yourself.             //
//                                                           //
// For information on how to write testcases with catch2,    //
// see https://github.com/catchorg/Catch2.                   //
//                                                           //
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
//                Functions used in testcases                //
///////////////////////////////////////////////////////////////

/// \brief 
/// Creates a mock Warehouse.
/// \return Warehouse with shelf of books.
/// \details
/// Creates a Warehouse with 3 unsorted shelves with a total of 100 Books, 60 Boxes, and 60 Toy Bears.
/// \n Adds forklift certified employee Bob.
/// \n This function can be used in testcases to avoid the repeated construction of Warehouse objects.
Warehouse createMockWarehouse(){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Boxes", 100, 10), 
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 20)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 15), 
        Pallet("Boxes", 100, 20), 
        Pallet("Books", 100, 5), 
        Pallet("Boxes", 100, 30)
    };

    Shelf shelf3 = Shelf();
    shelf3.pallets = {
        Pallet("Toy Bears", 100, 20), 
        Pallet("Toy Bears", 100, 10), 
        Pallet(), 
        Pallet("Toy Bears", 100, 30)
    };
    
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addShelf(shelf3);

    warehouse.addEmployee(Employee("Bob", true));

    return warehouse;
}


///////////////////////////////////////////////////////////////
//           Warehouse::rearrangeShelf test cases            //
///////////////////////////////////////////////////////////////

TEST_CASE("Rearrange empty shelf", "Warehouse::rearrangeShelf"){
    // Construct empty warehouse and add empty shelf and forklift certified Employee.
    Warehouse warehouse = Warehouse();
    warehouse.addShelf(Shelf());
    warehouse.addEmployee(Employee("Bob", true));

    // Check if shelf is already arranged.
    // Empty shelf should already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 0);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Empty shelf should still be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 0);
}

TEST_CASE("Rearrange full shelf", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };

    warehouse.addEmployee(Employee("Bob", true));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 40);
}

TEST_CASE("Rearrange half filled shelf", "Warehouse::rearrangeShelf"){
    // Construct empty warehouse and unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 20), 
        Pallet(), 
        Pallet()
    };
    
    warehouse.addEmployee(Employee("Bob", true));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 0);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 40);
}

TEST_CASE("Rearrange shelf without qualified employee", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };
    
    warehouse.addEmployee(Employee("Bert", false));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should fail
    REQUIRE(!successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now still not be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 10);
}

TEST_CASE("Rearrange shelf with quallified, but busy, employee", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };
    
    Employee bert = Employee("Bert", true);
    bert.setBusy(true);

    warehouse.addEmployee(bert);
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should fail
    REQUIRE(!successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now still not be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 10);
}

TEST_CASE("Pick items from warehouse with items on 1 pallet, Warehouse::PickItems") {
    // Construct warehouse with 4 different items on 1 shelf
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Apple", 100, 10), 
        Pallet("Banana", 100, 20), 
        Pallet("Lemon", 100, 30), 
        Pallet("Pear", 100, 40)
    };
    warehouse.addShelf(shelf1);

    //Check if the pallets are implemented correctly
    //This shelf should be implemented correctly
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 40);

    // Take 9 apples from the warehouse
    bool succesfull_apple = warehouse.pickItems("Apple", 9);
    // Should succeed
    REQUIRE(succesfull_apple);

    // Take 20 bananas from the warehouse
    bool succesfull_banana = warehouse.pickItems("Banana", 20);
    // Should succeed
    REQUIRE(succesfull_banana);

    // Take 31 lemons from the warehouse
    bool succesfull_lemon = warehouse.pickItems("Lemon", 31);
    //Should fail
    REQUIRE(!succesfull_lemon);

    // Check if the shelf has the correct stock
    // Shelf should have 1 apple, 0 bananas, 30 lemons and 40 pears
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 1);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 40);
}

TEST_CASE("Pick items from warehouse with items on multiple pallets on multiple shelves, Warehouse::PickItems") {
    // Construct warehouse with 2 shelves with at least one common product
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Apple", 100, 10), 
        Pallet("Banana", 100, 20), 
        Pallet("Lemon", 100, 30), 
        Pallet("Pear", 100, 40)
    };
    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Apple", 100, 10), 
        Pallet("Banana", 100, 20), 
        Pallet("Apple", 100, 30), 
        Pallet("Pear", 100, 40)
    };

    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);

    //Check if the shelves and pallets are implemented correctly
    //They should be implemented correctly
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 40);

    REQUIRE(warehouse.shelves[1].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.shelves[1].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[1].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[1].pallets[3].getItemCount() == 40);

    // Take 55 apples from the warehouse
    bool succesfull = warehouse.pickItems("Apple", 40);
    // Should succeed
    REQUIRE(succesfull);

    // Check if the warehouse is updated correctly
    int applestock = warehouse.shelves[0].pallets[0].getItemCount();
    applestock += warehouse.shelves[1].pallets[0].getItemCount();
    applestock += warehouse.shelves[1].pallets[2].getItemCount();
    REQUIRE(applestock == 10);

}

TEST_CASE("Pick non-existent item, Warehouse::PickItems") {
     // Construct warehouse with 4 different items on 1 shelf
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Apple", 100, 10), 
        Pallet("Banana", 100, 20), 
        Pallet("Lemon", 100, 30), 
        Pallet("Pear", 100, 40)
    };
    warehouse.addShelf(shelf1);

    //Check if the pallets are implemented correctly
    //This shelf should be implemented correctly
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 40);

    // Take 10 peaches from the warehouse
    bool succesfull = warehouse.pickItems("Peach", 10);
    // Should fail
    REQUIRE(!succesfull);

    //Check if shelf is unchanged
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 40);

}

TEST_CASE("Pick item when there is not enough stock, Warehouse::PickItems") {
     // Construct warehouse with 4 different items on 1 shelf
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Apple", 100, 10), 
        Pallet("Banana", 100, 20), 
        Pallet("Lemon", 100, 30), 
        Pallet("Pear", 100, 40)
    };
    warehouse.addShelf(shelf1);

    //Check if the pallets are implemented correctly
    //This shelf should be implemented correctly
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 40);

    // Take 10 peaches from the warehouse
    bool succesfull = warehouse.pickItems("Apple", 11);
    // Should fail
    REQUIRE(!succesfull);

    //Check if shelf is unchanged
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 40);
}
