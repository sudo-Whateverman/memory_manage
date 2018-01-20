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
    if (!freeFramesList.empty()) {
        int* framePtr = freeFramesList.front();
        freeFramesList.pop();
        memset(framePtr, 0, PAGESIZE);
        return framePtr;
    } else {
        throw "The PhysMem is full and cannot pass a free frame";
    }
}

int* VirtualMemory::GetPage(unsigned int adr) {
    // This is the magic sauce.
    return pageTable.GetPage(adr);
}

VirtualMemory::~VirtualMemory() {

}

void VirtualMemory::ReleaseFrame(int* framePointer) {
    // TODO: add code here
    // release memory, pop frame to queue.
    // Will be called when we want to pop a new page and don't have frames
    memset(framePointer, 0, PAGESIZE);
    freeFramesList.push(framePointer);
}
