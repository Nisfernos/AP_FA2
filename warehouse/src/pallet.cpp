#include "include/pallet.hpp"

Pallet::Pallet() {
    this->itemName = "";
    this->itemCapacity = 0;
    this->itemCount = 0;
};

Pallet::Pallet(std::string itemName_, int itemCapacity_, int itemCount_) {
    this->itemName = itemName_;
    this->itemCapacity = itemCapacity_;
    this->itemCount = itemCount_;
};

std::string Pallet::getItemName() const {
    return this->itemName;
};

int Pallet::getItemCount() const {
    return this->itemCount;
};

int Pallet::getRemainingSpace() const {
    return this->itemCapacity-getItemCount();
};

bool Pallet::reallocateEmptyPallet(std::string itemName_, int itemCapacity_) {
    if (getItemCount() == 0) {
        this->itemName = itemName;
        this->itemCapacity = itemCapacity;
        return 1;
    }
    else {
        return 0;
    }
};

bool Pallet::takeOne() {
    if (!isEmtpy()) {
        this->itemCount--;
        return 1;
    }
    else {
        return 0;
    }

};

bool Pallet::putOne() {
    if (!isFull()) {
        this->itemCount++;
        return 1;
    }
    else {
        return 0;
    }
};

bool Pallet::isEmtpy() {
    if (getItemCount () == 0) {
        return 1;
    }
    else {
        return 0;
    }
};

bool Pallet::isFull() {
    if (getRemainingSpace() == 0) {
        return 1;
    }
    else {
        return 0;
    }
};