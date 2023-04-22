#ifndef MANUF_LINE_H
#define MANUF_LINE_H

#include <iostream>
#include <storage_unit.h>
#include <station.h>

class MANUF_LINE{

private:
    std::string s_code;
    int n_of_station;
    int material;
    STORAGE* storage_ptr;

public:
    MANUF_LINE(std::string s_code, int n_of_station, int material, STORAGE* storage);
    void go();


};

#endif