/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   directoryTest.h
 * Author: nick
 *
 * Created on Jan 20, 2018, 1:29:48 AM
 */

#ifndef DIRECTORYTEST_H
#define DIRECTORYTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../PageDirectoryEntry.h"

class directoryTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(directoryTest);

    CPPUNIT_TEST(testGet_table_address);
    CPPUNIT_TEST(testSet_table_address);
    CPPUNIT_TEST(testIs_valid);
    CPPUNIT_TEST(testSet_valid);

    CPPUNIT_TEST_SUITE_END();

public:
    directoryTest();
    virtual ~directoryTest();
    void setUp();
    void tearDown();

private:
    void testGet_table_address();
    void testSet_table_address();
    void testIs_valid();
    void testSet_valid();
    PageDirectoryEntry* pageDirectoryEntry;
    PageTableEntry* _pagetable;
    int dummy_int = 200;
};

#endif /* DIRECTORYTEST_H */

