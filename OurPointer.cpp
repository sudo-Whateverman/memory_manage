
#include "VirtualMemory.h"
#include "OurPointer.h"

int& OurPointer::operator*() {
    int* page = _vrtlMem->GetPage(_adr);
    // Very important - this is the offset divided by 4, since page is an int pointer, it will
    // multiply by 4
    unsigned int offsetInInt = (_adr << 20) >> 22;
    return page[offsetInInt];
}

OurPointer& OurPointer::operator++() {
    _adr = _adr + sizeof (int);
    return *this;
}

OurPointer OurPointer::operator++(int) {
    OurPointer temporary(_adr, _vrtlMem);
    _adr = _adr + sizeof (int);
    return temporary;
}

OurPointer& OurPointer::operator--() {
    _adr = _adr - sizeof (int);
    return *this;
}

OurPointer OurPointer::operator--(int) {
    OurPointer temporary(_adr, _vrtlMem);
    _adr = _adr - sizeof (int);
    return temporary;
}


// TODO: can virtual memory lie in 2 separate frames ? Would frame boundaries trigger a overflow?
