#pragma once

class IContainer{
    /**
     * @brief Virtual class
     * This virtual class contains two functions, an isEmpty, and a isFull function.
     */
    virtual bool isEmtpy() = 0;
    virtual bool isFull() = 0;
};
