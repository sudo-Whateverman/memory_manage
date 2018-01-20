/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   entryTest.h
 * Author: nick
 *
 * Created on Jan 20, 2018, 12:55:30 AM
 */

#ifndef ENTRYTEST_H
#define ENTRYTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../PageTableEntry.h"

class entryTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(entryTest);

    CPPUNIT_TEST(testGet_page_address);
    CPPUNIT_TEST(testSet_page_address);
    CPPUNIT_TEST(testSet_valid);
    CPPUNIT_TEST(testIs_valid);

    CPPUNIT_TEST_SUITE_END();

public:
    entryTest();
    virtual ~entryTest();
    void setUp();
    void tearDown();

private:
    void testGet_page_address();
    void testSet_page_address();
    void testSet_valid();
    void testIs_valid();
    PageTableEntry* pageTableEntry;
    int dummy_int = 101;
};

#endif /* ENTRYTEST_H */

