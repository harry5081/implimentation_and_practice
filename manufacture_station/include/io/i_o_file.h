#ifndef I_O_FILE_H
#define I_O_FILE_H

#include <vector>
#include <map>
#include <iostream>
#include <fstream>


//const std::string filename = "station_state.txt";

void splitString(std::vector<std::string> &v_str,const std::string &str,const char ch);

bool dump_station_state(std::map<char, int> station_state_record);

bool read_station_state(std::map<char, int>& station_state_record);

std::map<char, int> read_station_state();


#endif