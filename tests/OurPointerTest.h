/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   OurPointerTest.h
 * Author: nick
 *
 * Created on Jan 20, 2018, 4:27:21 AM
 */

#ifndef OURPOINTERTEST_H
#define OURPOINTERTEST_H
#define CONTINOUS_READ_TEST 10000
#include <cppunit/extensions/HelperMacros.h>
#include "../OurPointer.h"


class OurPointerTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(OurPointerTest);

    CPPUNIT_TEST(continuosRead);
    CPPUNIT_TEST(continuosNonRandomRead);

    CPPUNIT_TEST_SUITE_END();

public:
    OurPointerTest();
    virtual ~OurPointerTest();
    void setUp();
    void tearDown();

private:
    void continuosRead();
    void continuosNonRandomRead();
    void pushToLog(OurPointer vector1, int* vector2, int vector3,const char* filename);

};

#endif /* OURPOINTERTEST_H */

