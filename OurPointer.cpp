
#include "VirtualMemory.h"
#include "OurPointer.h"

int& OurPointer::operator*() {
    int* page = _vrtlMem->GetPage(_adr);
    unsigned int offset = ((_adr << 22) >> 22);
    return page[offset];
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
