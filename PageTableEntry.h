#pragma once

class PageTableEntry {
public:
    //Your Constructor (and Destructor if you need one) should go here

    PageTableEntry() : _valid(false), _address(nullptr) {
    }
    int* get_page_address(); //Pointer to beginning of frame
    void set_page_address(int* adr); //Set the pointer to a frame

    bool is_valid(); //Returns whether the entry is valid 

    void set_valid(bool valid);  //Allows to set whether the entry is valid 
private:
    //Fill the class with the necessary member variables
    bool _valid;
    int* _address;
};
