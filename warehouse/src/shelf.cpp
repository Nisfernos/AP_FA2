#include "include/shelf.hpp"

Shelf::Shelf() {
    this->pallets = {Pallet(), Pallet(), Pallet(), Pallet()};
};

bool Shelf::swapPallet(int slot1, int slot2) {
    if ((slot1 < 0) || (slot1 > 3) || (slot2 < 0) || (slot2 > 3)){
        return 0;
    }
    else {
        this->pallets[slot1], this->pallets[slot2] = this->pallets[slot2], this->pallets[slot1];
        return 1;
    }
};

bool Shelf::isEmtpy() {
    for (Pallet pallet : this->pallets) {
        if (!pallet.Pallet::isEmtpy()){
            return 0;
        }
    }
    return 1;
};

bool Shelf::isFull() {
    for (Pallet pallet : this->pallets) {
        if (!pallet.Pallet::isFull()){
            return 0;
        }
    }
    return 1;
};
