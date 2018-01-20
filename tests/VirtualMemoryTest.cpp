/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   VirtualMemoryTest.cpp
 * Author: nick
 *
 * Created on Jan 20, 2018, 1:50:55 AM
 */

#include "VirtualMemoryTest.h"
#include "../VirtualMemory.h"


CPPUNIT_TEST_SUITE_REGISTRATION(VirtualMemoryTest);

VirtualMemoryTest::VirtualMemoryTest() {
    virtualMemory = new VirtualMemory();
}

VirtualMemoryTest::~VirtualMemoryTest() {
    delete virtualMemory;
}

void VirtualMemoryTest::setUp() {
}

void VirtualMemoryTest::tearDown() {
}

void VirtualMemoryTest::testGetFreeFrame() {
    VirtualMemory virtualMemory;
    for (int i = 0; i < 64; i++) {
        int* result = virtualMemory.GetFreeFrame();
        if (result == nullptr) {
            CPPUNIT_ASSERT(false);
        }
    }
    try {
        int* result = virtualMemory.GetFreeFrame();
        CPPUNIT_ASSERT(false); // If there is no exception thrown, the test asserts false and fails.
    } catch (...) {
    }
}

void VirtualMemoryTest::testReleaseFrame() {
    int* framePointer;
    VirtualMemory virtualMemory;
    int* result = virtualMemory.GetFreeFrame();
    try {
        virtualMemory.ReleaseFrame(result);
    } catch (...) {
        CPPUNIT_ASSERT(false);
    }
}

