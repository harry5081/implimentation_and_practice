#include <manuf_line.h>

MANUF_LINE::MANUF_LINE(std::string s_code, int n_of_station, int material, STORAGE* storage){
    
    this-> s_code = s_code;
    this-> n_of_station = n_of_station;
    this-> material = material;
    this-> storage_ptr = storage;

}

void MANUF_LINE::go(){

    std::string manufacture_line(s_code.begin(), s_code.end());
    std::cout << "Raw material: "<< material  << std::endl;
    std::cout << "Number of stations: "<< n_of_station  << std::endl;

    //   manufacture line set  //
    STATION* station_line_[n_of_station];

    for(int i=0; i<n_of_station;i++){   
        
        STATION* station_ptr_;     
        switch(s_code[i]) {
            case 'A':
                station_ptr_ = new STATION_A('A');
                if (station_ptr_ == nullptr)
                    std::cout << "Error: memory could not be allocated";
                station_line_[i] = station_ptr_;
                break;
            case 'B':
                station_ptr_ = new STATION_B('B');
                if (station_ptr_ == nullptr)
                    std::cout << "Error: memory could not be allocated";
                station_line_[i] = station_ptr_;
                break;
            case 'C':
                station_ptr_ = new STATION_C('C');
                if (station_ptr_ == nullptr)
                    std::cout << "Error: memory could not be allocated";
                station_line_[i] = station_ptr_;
                break;
            case 'D':
               station_ptr_ = new STATION_D('D');
               if (station_ptr_ == nullptr)
                    std::cout << "Error: memory could not be allocated";
                station_line_[i] = station_ptr_;
                break;
            
            default:
                std::cout << "ERROR by manufacturing line processing"  << std::endl;
                break;
        }

    }

    //   manufacture line exe  //
    STATION** who_s_turn_ptr_;
    who_s_turn_ptr_ = station_line_;

    int station_total = n_of_station;
    int station_left = station_total;

    for(int i=0;i<station_total;i++){
       
        std::cout<< "------------------------------"<<std::endl;
        storage_ptr->record_station_exe((*who_s_turn_ptr_)->name, 1);
        (*who_s_turn_ptr_)->exe(&who_s_turn_ptr_, material, &station_left); 

        if((*who_s_turn_ptr_)-> finish_stop == true){
            std::cout<< "................Operation Line Ends..............."<<std::endl;
            break;
        }       
    }
    std::cout<< "Finished Product:" << material <<std::endl;
    storage_ptr->store_material(material);

    // clean memory
    std::cout<<std::endl;
    std::cout<< "------------ clean memory -------------"<<std::endl;
    for(int i=0;i<station_total;i++){        
        
        std::cout<< station_line_[i]->name;
        delete (station_line_[i]);
    }
    s_code.clear();
    std::cout<<std::endl;



}