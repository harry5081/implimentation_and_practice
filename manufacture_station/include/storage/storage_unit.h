#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <map>
#include <iostream>
#include <fstream>

class STORAGE{

public:
    STORAGE(char station_type[], int n_type);
    STORAGE();

    void store_material(int material);
    void record_station_exe(char station, int n_times);

    void set_state(std::map<char,int> state_pre);
    std::map<char,int> get_state();

    void show_material_stock();
    void show_station_record();
    

private:
    std::vector<int> material_done_store;
    std::map<char, int> station_exe_record;

};


#endif