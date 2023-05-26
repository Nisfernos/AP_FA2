#include "include/pallet.hpp"

Pallet::Pallet() {
    /**
     * @brief This constructor makes an empty pallet.
     */
    this->itemName = "";
    this->itemCapacity = 0;
    this->itemCount = 0;
};

Pallet::Pallet(std::string itemName_, int itemCapacity_, int itemCount_) {
    /**
     * @brief This constructor makes a non-empty pallet.
     * @param itemName_ :  The name of the product on the pallet.
     * @param itemCapacity_ : The amount of items this pallet can contain of this item type.
     * @param itemCount_ : The amount of items currently on this pallet.
     */
    this->itemName = itemName_;
    this->itemCapacity = itemCapacity_;
    this->itemCount = itemCount_;
};

std::string Pallet::getItemName() const {
    /**
     * @brief This function will return the name of the product on the pallet.
     */
    return this->itemName;
};

int Pallet::getItemCount() const {
    /**
     * @brief This function will return the current amount of items on the pallet.
     */
    return this->itemCount;
};

int Pallet::getRemainingSpace() const {
    /**
     * @brief This function will return the remaining space on the pallet for its item.
     */
    return this->itemCapacity-getItemCount();
};

bool Pallet::reallocateEmptyPallet(std::string itemName_, int itemCapacity_) {
    /**
     * @brief This function will assign a new item to the pallet. It will not put items on the pallet.
     * @param itemName_ : This is the name of the item you want the pallet to hold
     * @param itemCapacity_ This is the maximum amount of items the pallet can hold of the new item.
     */
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
    /**
     * @brief This will reduce the itemCount of the pallet by 1, if possible.
     */
    if (!isEmtpy()) {
        this->itemCount--;
        return 1;
    }
    else {
        return 0;
    }

};

bool Pallet::putOne() {
    /**
     * @brief This will increase the itemCount of the pallet by 1, if possible.
     */
    if (!isFull()) {
        this->itemCount++;
        return 1;
    }
    else {
        return 0;
    }
};

bool Pallet::isEmtpy() {
    /**
     * @brief This will return true, if the pallet is empty (itemCount == 0).
     */
    if (getItemCount () == 0) {
        return 1;
    }
    else {
        return 0;
    }
};

bool Pallet::isFull() {
    /**
     * @brief This will return true, if the pallet is full (itemCount == itemCapacity).
     */
    if (getRemainingSpace() == 0) {
        return 1;
    }
    else {
        return 0;
    }
};