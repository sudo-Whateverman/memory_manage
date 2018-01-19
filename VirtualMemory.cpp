#include "VirtualMemory.h"

VirtualMemory::VirtualMemory() {
    allocated = 0;
    pageTable.Init(this);
    for (int iter = 0; iter < 64; iter++) {
        freeFramesList.push(PhysMem::Access().GetFrame(iter));
    }
    std::ofstream filewriter("log.csv", std::ofstream::out);
    filewriter << "Page Number,Virtual Address,Physical Address,Page Fault,Swap,Evicted,Allocated Page Table Entries" << std::endl;
    filewriter.close();
}

int* VirtualMemory::GetFreeFrame() {
    int* framePtr = freeFramesList.front();
    freeFramesList.pop();
    memset(framePtr, 0, PAGESIZE);
    return framePtr;
}

VirtualMemory::~VirtualMemory() {

}

void VirtualMemory::ReleaseFrame(int* framePointer) {
    // TODO: add code here
}
