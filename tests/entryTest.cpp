/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   entryTest.cpp
 * Author: nick
 *
 * Created on Jan 20, 2018, 12:55:30 AM
 */

#include "entryTest.h"
#include "../PageTableEntry.h"


CPPUNIT_TEST_SUITE_REGISTRATION(entryTest);

entryTest::entryTest() {
    pageTableEntry = new PageTableEntry();
}

entryTest::~entryTest() {
    delete pageTableEntry;
}

void entryTest::setUp() {
    pageTableEntry->set_page_address(&dummy_int);
}

void entryTest::tearDown() {
}

void entryTest::testGet_page_address() {
    PageTableEntry pageTableEntry;
    int* result = pageTableEntry.get_page_address();
    if (result != nullptr) {
        CPPUNIT_ASSERT(false);
    }
}

void entryTest::testSet_page_address() {
    int* adr;
    PageTableEntry pageTableEntry;
    pageTableEntry.set_page_address(&dummy_int);
    int* result = pageTableEntry.get_page_address();
    if (result != &dummy_int) {
        CPPUNIT_ASSERT(false);
    } else if (*result != dummy_int) {
        CPPUNIT_ASSERT(false);
    }
}

void entryTest::testIs_valid() {
    PageTableEntry pageTableEntry;
    bool result = pageTableEntry.is_valid();
    if (result) {
        CPPUNIT_ASSERT(false);
    }
}

void entryTest::testSet_valid() {
    bool valid;
    PageTableEntry pageTableEntry;
    pageTableEntry.set_valid(true);
    bool result = pageTableEntry.is_valid();
    if (!result) {
        CPPUNIT_ASSERT(false);
    }
}



