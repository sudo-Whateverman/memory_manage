#pragma once

#include "PageDirectoryEntry.h"
#include "PageTableEntry.h"

#define DIRENTRIES 1024

class VirtualMemory; //You will probably want to include this in PageTable.cpp

class PageTable {
public:
    //Your Constructor (and Destructor if you need one) should go here
    int* GetPage(unsigned int adr);
    void Init(VirtualMemory* _vrtlMem);
private:
    //Fill the class with the necessary member variables
    static PageDirectoryEntry _cr3 [DIRENTRIES];
    VirtualMemory* _vrtlMem;
};
