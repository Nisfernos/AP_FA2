#pragma once
#include "icontainer.hpp"
#include "pallet.hpp"
#include <array>

class Shelf : public IContainer {
    private:
        std::array<Pallet, 4> pallets;

    public:
        Shelf();
        
        bool swapPallet(int slot, int slot2);

        bool isEmtpy();
        bool isFull();
};