#include "include/shelf.hpp"

Shelf::Shelf() {
    /**
     * @brief Constructor of class Shelf, makes a shelf with 4 empty pallet of class Pallet.
     */
    this->pallets = {Pallet(), Pallet(), Pallet(), Pallet()};
};

bool Shelf::swapPallet(int slot1, int slot2) {
    /**
     * @brief This function swaps two pallets
     * @param slot1 The place of the first pallet(0-3)
     * @param slot2 The place of the second pallet(0-3)
     */
    // If the slots are valid: 0 t/m 3
    if ((slot1 < 0) || (slot1 > 3) || (slot2 < 0) || (slot2 > 3)){
        return false;
    }
    else {
        // a,b = b,a doesn't work :'(
        // Tristan suggested swap
        std::swap(this->pallets[slot1], this->pallets[slot2]);
        return true;
    }
};

bool Shelf::isEmtpy() {
    /**
     * @brief Returns whether the shelf is empty. i.e. all pallets are empty.
     */
    for (Pallet pallet : this->pallets) {
        if (!pallet.Pallet::isEmtpy()){
            return false;
        }
    }
    return true;
};

bool Shelf::isFull() {
    /**
     * @brief Returns whether the shelf is full. i.e. all pallets are full.
     */
    for (Pallet pallet : this->pallets) {
        if (!pallet.Pallet::isFull()){
            return false;
        }
    }
    return true;
};
