#pragma once

#include "PageTableEntry.h"

class PageDirectoryEntry {
public:

    PageDirectoryEntry() : _valid(false), _pagetable(nullptr) {
    }

    PageTableEntry* get_table_address();

    void set_table_address(PageTableEntry* adr);

    bool is_valid();
    void set_valid(bool valid);

private:
    bool _valid;
    PageTableEntry* _pagetable;

};
