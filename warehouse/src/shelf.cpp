#include "include/shelf.hpp"

Shelf::Shelf() {
    /**
     * @brief 
     * @param 
     */
    this->pallets = {Pallet(), Pallet(), Pallet(), Pallet()};
};

bool Shelf::swapPallet(int slot1, int slot2) {
    /**
     * @brief 
     * @param 
     */
    if ((slot1 < 0) || (slot1 > 3) || (slot2 < 0) || (slot2 > 3)){
        return false;
    }
    else {
        // a,b = b,a doesn't work :'(
        std::swap(this->pallets[slot1], this->pallets[slot2]);
        return true;
    }
};

bool Shelf::isEmtpy() {
    /**
     * @brief 
     * @param 
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
     * @brief 
     * @param 
     */
    for (Pallet pallet : this->pallets) {
        if (!pallet.Pallet::isFull()){
            return false;
        }
    }
    return true;
};
