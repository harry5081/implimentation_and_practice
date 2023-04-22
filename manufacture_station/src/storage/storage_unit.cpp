#include <storage_unit.h>
#include <i_o_file.h>


void STORAGE::store_material(int material){
    
    material_done_store.push_back(material);

}

void STORAGE::record_station_exe(char station, int n_times){
    
    station_exe_record[station]=station_exe_record[station]+1;

}

STORAGE::STORAGE(){

}

STORAGE::STORAGE(char station_type[], int n_type){
    
    for(int i=0;i<n_type;i++){
        station_exe_record.insert({station_type[i], 0});
    }


}

void STORAGE::show_material_stock(){

    for (int i = 0; i < material_done_store.size(); i++) {

        std::cout << "The finished product ["<< i+1 << "] is: " <<  material_done_store[i] << std::endl;

    }


}

void STORAGE::show_station_record(){

    // print all elements
    std::map<char,int>::iterator pos;
    for (pos = station_exe_record.begin(); pos != station_exe_record.end(); ++pos) {
        std::cout << "type: " << pos->first << "\t"
             << ", exe_times: " << pos->second << std::endl;
    }
    std::cout << std::endl;
}

void STORAGE::set_state(std::map<char,int> state_pre){
    station_exe_record.clear();
    station_exe_record = state_pre;

}


std::map<char,int> STORAGE::get_state(){

    return station_exe_record;

}