#pragma once
#include "icontainer.hpp"
#include "pallet.hpp"
#include <array>

class Shelf : public IContainer {
    /**
     * @brief This class represents a shelf with 4 pallets on it.
     * @param pallets The 4 pallets that are on the shelf
     * You can swap 2 pallets on the shelf.
     * You can ask if the shelf is completely full or completely empty (i.e. all pallets are empty or full)
     */
    public:
        std::array<Pallet, 4> pallets;

        Shelf();
        
        bool swapPallet(int slot, int slot2);

        bool isEmtpy();
        bool isFull();
};