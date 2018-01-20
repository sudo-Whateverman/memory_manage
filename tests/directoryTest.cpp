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
#include "../PageTableEntry.h"


CPPUNIT_TEST_SUITE_REGISTRATION(directoryTest);

directoryTest::directoryTest() {
    pageDirectoryEntry = new PageDirectoryEntry();
    _pagetable = new PageTableEntry();
    _pagetable->set_page_address(&dummy_int);
}

directoryTest::~directoryTest() {
    delete pageDirectoryEntry;
}

void directoryTest::setUp() {
}

void directoryTest::tearDown() {
}

void directoryTest::testGet_table_address() {
    PageDirectoryEntry pageDirectoryEntry;
    PageTableEntry* result = pageDirectoryEntry.get_table_address();
    if (result != nullptr) {
        CPPUNIT_ASSERT(false);
    }
}

void directoryTest::testSet_table_address() {
    PageTableEntry* adr;
    PageDirectoryEntry pageDirectoryEntry;
    pageDirectoryEntry.set_table_address(_pagetable);
    PageTableEntry* result = pageDirectoryEntry.get_table_address();
    if (result != _pagetable) {
        CPPUNIT_ASSERT(false);
    } else if (result->get_page_address() != &dummy_int) {
        CPPUNIT_ASSERT(false);
    }
}

void directoryTest::testIs_valid() {
    PageDirectoryEntry pageDirectoryEntry;
    bool result = pageDirectoryEntry.is_valid();
    if (result) {
        CPPUNIT_ASSERT(false);
    }
}

void directoryTest::testSet_valid() {
    bool valid;
    PageDirectoryEntry pageDirectoryEntry;
    pageDirectoryEntry.set_valid(true);
    bool result = pageDirectoryEntry.is_valid();
    if (!result) {
        CPPUNIT_ASSERT(false);
    }
    pageDirectoryEntry.set_valid(false);
    result = pageDirectoryEntry.is_valid();
    if (result) {
        CPPUNIT_ASSERT(false);
    }
}

