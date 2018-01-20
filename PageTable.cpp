#include "PageTable.h"
#include "VirtualMemory.h"
#include "PhysMem.h"
#include <fstream>

PageDirectoryEntry PageTable::_cr3 [DIRENTRIES];

void PageTable::writeOutCsv(unsigned int adr, unsigned int pagenum, int allocpgtbl, int pgfault, long int physadr){
    std::ofstream filewriter("log.csv", std::ofstream::out | std::ofstream::app);
    filewriter << pagenum << "," << adr << "," << physadr << "," << pgfault << ",0,0," << allocpgtbl << std::endl; //TODO: Fix (Swap, Evicted)
    filewriter.close();
}

int* PageTable::GetPage(unsigned int adr) {
    unsigned int dir = (adr >> 22);
    unsigned int table = ((adr << 10) >> 22);
    unsigned int offset = ((adr << 22) >> 22);

    unsigned int pagenum = (adr) >> 12;
    int allocpgtbl = 0;
    int pgfault = 0;


    if (!_cr3[dir].is_valid()) {
        _cr3[dir].set_table_address((PageTableEntry*) malloc(1024 * sizeof (PageTableEntry)));  // TODO: refactor - move to PageDir ?!
        _cr3[dir].set_valid(true);
        allocpgtbl = 1;
    }

    PageTableEntry* tmpPgTbl = _cr3[dir].get_table_address();
    if (!tmpPgTbl[table].is_valid()) {
        pgfault = 1;
        tmpPgTbl[table].set_page_address(_vrtlMem->GetFreeFrame());
        tmpPgTbl[table].set_valid(true);
    }
    
    // Add swapingIn and Out.
    long int physadr = (long int) tmpPgTbl[table].get_page_address() + (long int) offset - (long int) PhysMem::Access().GetFrame(0);


    writeOutCsv(adr, pagenum, allocpgtbl, pgfault, physadr);
    return tmpPgTbl[table].get_page_address();

}

void PageTable::Init(VirtualMemory* vrtlMem) {
    for (int iter = 0; iter < DIRENTRIES; iter++) {
        _cr3[iter].set_valid(false);
    }
    _vrtlMem = vrtlMem;
}

// TODO : add release on PageFault (try catch)
