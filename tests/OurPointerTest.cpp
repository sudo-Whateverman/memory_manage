/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   OurPointerTest.cpp
 * Author: nick
 *
 * Created on Jan 20, 2018, 4:27:22 AM
 */

#include "OurPointerTest.h"
#include <bitset>
#include "../OurPointer.h"
#include "../VirtualMemory.h"

CPPUNIT_TEST_SUITE_REGISTRATION(OurPointerTest);

OurPointerTest::OurPointerTest() {
    // Clean the logs. Since its a pain in the ass to do it manually
    const char* filename1 = "TestRandomReadWrite.csv";
    std::ofstream filewriter1(filename1, std::ofstream::out);   
    filewriter1.close();
    
    const char* filename2 = "TestContinuosReadWrite.csv";
    std::ofstream filewriter2(filename2, std::ofstream::out);   
    filewriter2.close();
}

OurPointerTest::~OurPointerTest() {
}

void OurPointerTest::setUp() {
    
    
}

string isOkPrint(bool value){
    if (value){
        return "OK";
    }
    else{
        return "FAIL";
    }
}

void OurPointerTest::tearDown() {
}

void OurPointerTest::pushToLog(OurPointer vector1, int* vector2, int vector3,const char* filename){
    std::ofstream filewriter(filename, std::ofstream::out | std::ofstream::app);   
    int vector1_value = *(vector1);
    bitset<32> a(vector1_value);  // it seems that the 9,10 bits of the OurPointer return value are always on for some reason.
    bitset<32> b(*(vector2));
    bool isOk = (vector1_value==*(vector2));
    
    filewriter << a << " : " << b << " : " << vector3 << " ... " << isOkPrint(isOk) << endl;
    filewriter.close();
}

void OurPointerTest::continuosRead() {
    VirtualMemory vrtlMem;
    
    OurPointer vector1base = vrtlMem.OurMalloc(CONTINOUS_READ_TEST);
    OurPointer vector1= vector1base;
    
    int* vector2base = (int*)malloc(CONTINOUS_READ_TEST*sizeof(int));
    int* vector2 = vector2base;
    
    int vector3[CONTINOUS_READ_TEST];
    
    srand(1);
    
    for (int i = 0; i < CONTINOUS_READ_TEST; ++i) {
        int temp = rand() % 100;
        *(vector1++) = temp;
        *(vector2++) = temp;
        vector3[i] = temp;
    }
    vector1 = vector1base;
    vector2 = vector2base;
    const char* filename = "TestRandomReadWrite.csv";
    
    for (int i = 0; i < CONTINOUS_READ_TEST; ++i) {
        pushToLog(vector1, vector2, vector3[i], filename);
        if (*(vector1++)!=*(vector2++)){
            //            CPPUNIT_ASSERT(false); 
            //            remove comment from prev line to run it
        }
    }
}

void OurPointerTest::continuosNonRandomRead() {
    VirtualMemory vrtlMem;
    
    OurPointer vector1base = vrtlMem.OurMalloc(CONTINOUS_READ_TEST);
    OurPointer vector1= vector1base;
    
    int* vector2base = (int*)malloc(CONTINOUS_READ_TEST*sizeof(int));
    int* vector2 = vector2base;
    
    int vector3[CONTINOUS_READ_TEST];
    
    
    for (int i = 0; i < CONTINOUS_READ_TEST; ++i) {
        *(vector1++) = i;
        *(vector2++) = i;
        vector3[i] = i;
    }
    vector1 = vector1base;
    vector2 = vector2base;
    const char* filename = "TestContinuosReadWrite.csv";
    
    for (int i = 0; i < CONTINOUS_READ_TEST; ++i) {
        pushToLog(vector1, vector2, vector3[i], filename);
        if (*(vector1++)!=*(vector2++)){
            //            CPPUNIT_ASSERT(false);
            //            remove comment from prev line to run it
        }
    }
}
