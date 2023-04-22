#include <station.h>

#include <mmi.h>
#include <storage_unit.h>
#include <i_o_file.h>
#include <manuf_line.h>

int main(){
    
    char station_type[4] = {'A','B','C','D'};    
    STORAGE storage(station_type, 4);
    

    /////////////////////     MMI     /////////////////////////////
    std::cout << "*********************  MMI  *********************"  << std::endl;
    std::cout << std::endl;

    MMI mmi;
    mmi.welcome_go();  

    // MMI to Storage
    std::map<char,int> state_tmp = mmi.get_previous_state();
    storage.set_state(state_tmp);

    do{      
        // MMI to Manufacture Line
        int material = mmi.get_material();
        int n_of_station = mmi.get_n_station();
        std::string s_code = mmi.get_s_code();

    
        //////////////////////   Manufacture Line   ///////////////////////////////
        std::cout << "*****************  Manufacture Line  *****************"  << std::endl;
        std::cout << std::endl;    
        
        MANUF_LINE manuf_(s_code, n_of_station, material, &storage);
        manuf_.go();
        storage.show_station_record();
    
    }while(mmi.go());
    
    /////////////////////     STORAGE     /////////////////////////////
    storage.show_material_stock();
    storage.show_station_record();

    dump_station_state(storage.get_state());    



}//int main()