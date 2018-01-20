#pragma once

#include "PageTable.h"

class OurPointer {
public:

    OurPointer(size_t alloc, VirtualMemory* vrtlMem) : _adr(alloc), _vrtlMem(vrtlMem) {
    } //Constructor
    int& operator*(); //Overload operator*
    OurPointer& operator++(); //Overload ++operator
    OurPointer operator++(int); //Overload operator++
    OurPointer& operator--(); //Overload operator‐‐
    OurPointer operator--(int); //Overload ‐‐operator
private:
    unsigned int _adr; //the virtual address
    VirtualMemory* _vrtlMem; //for requesting translations
};
