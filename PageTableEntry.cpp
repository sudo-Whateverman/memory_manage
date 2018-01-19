#include "PageTableEntry.h"

int* PageTableEntry::get_page_address() {
    return _address;
}

void PageTableEntry::set_page_address(int* adr) {
    _address = adr;
}

void PageTableEntry::set_valid(bool valid) {
    _valid = valid;
}

bool PageTableEntry::is_valid() {
    return _valid;
}
