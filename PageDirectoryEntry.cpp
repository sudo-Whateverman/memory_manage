#include "PageDirectoryEntry.h"


PageTableEntry* PageDirectoryEntry::get_table_address() {
    return _pagetable;
}

void PageDirectoryEntry::set_table_address(PageTableEntry* adr) {
    _pagetable = adr;
}

bool PageDirectoryEntry::is_valid() {
    return _valid;
}

void PageDirectoryEntry::set_valid(bool valid) {
    _valid = valid;
}