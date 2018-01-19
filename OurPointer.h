#pragma once

#include "PageTable.h"

class OurPointer {
public:

    OurPointer(int adr, VirtualMemory* vrtlMem) : _adr(adr), _vrtlMem(vrtlMem) {
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
