/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   directoryTest.cpp
 * Author: nick
 *
 * Created on Jan 20, 2018, 1:29:48 AM
 */

#include "directoryTest.h"
#include "../PageDirectoryEntry.h"


CPPUNIT_TEST_SUITE_REGISTRATION(directoryTest);

directoryTest::directoryTest() {
}

directoryTest::~directoryTest() {
}

void directoryTest::setUp() {
}

void directoryTest::tearDown() {
}

void directoryTest::testGet_table_address() {
    PageDirectoryEntry pageDirectoryEntry;
    PageTableEntry* result = pageDirectoryEntry.get_table_address();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void directoryTest::testSet_table_address() {
    PageTableEntry* adr;
    PageDirectoryEntry pageDirectoryEntry;
    pageDirectoryEntry.set_table_address(adr);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void directoryTest::testIs_valid() {
    PageDirectoryEntry pageDirectoryEntry;
    bool result = pageDirectoryEntry.is_valid();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void directoryTest::testSet_valid() {
    bool valid;
    PageDirectoryEntry pageDirectoryEntry;
    pageDirectoryEntry.set_valid(valid);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

