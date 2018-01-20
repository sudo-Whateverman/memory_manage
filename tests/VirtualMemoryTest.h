/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   VirtualMemoryTest.h
 * Author: nick
 *
 * Created on Jan 20, 2018, 1:50:55 AM
 */

#ifndef VIRTUALMEMORYTEST_H
#define VIRTUALMEMORYTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../VirtualMemory.h"


class VirtualMemoryTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(VirtualMemoryTest);

    CPPUNIT_TEST(testGetFreeFrame);
    CPPUNIT_TEST(testReleaseFrame);

    CPPUNIT_TEST_SUITE_END();

public:
    VirtualMemoryTest();
    virtual ~VirtualMemoryTest();
    void setUp();
    void tearDown();

private:
    void testGetFreeFrame();
    void testReleaseFrame();
    VirtualMemory* virtualMemory;
};

#endif /* VIRTUALMEMORYTEST_H */

