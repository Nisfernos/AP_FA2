#pragma once
#include "icontainer.hpp"
#include "pallet.hpp"
#include <array>

class Shelf : public IContainer {
    /**
     * @brief 
     * @param 
     */
    public:
        std::array<Pallet, 4> pallets;

        Shelf();
        
        bool swapPallet(int slot, int slot2);

        bool isEmtpy();
        bool isFull();
};