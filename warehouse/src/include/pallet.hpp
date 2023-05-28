#pragma once
#include "icontainer.hpp"
#include <string>

class Pallet {
    /**
     * @brief This class represents a pallet with a single item type.
     * @param itemCount : The current amount of items that are on the pallet.
     * @param itenName : The name of the item on the pallet.
     * @param itemCapacity : The maximum amount of items the pallet can contain.
     * You can get the name, current count, and remaining space of the item on the pallet.
     * You can reallocate an empty pallet. I.e. assign it a new product.
     * You can take one item, and put on item on the pallet.
     * You can see if the pallet is full or empty.
     */
    private:
        int itemCount;
        std::string itemName;
        int itemCapacity;
    
    public:
        Pallet();
        Pallet(std::string itemName, int itemCapacity, int itemCount);

        std::string getItemName() const;
        int getItemCount() const;
        int getRemainingSpace() const;
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
        bool takeOne();
        bool putOne();

        bool isEmtpy();
        bool isFull();
};
