#ifndef MMI_H
#define MMI_H

#include <iostream>
#include <vector>
#include <map>
#include <i_o_file.h>

class MMI{
    private:
        enum class MODE {RESET, CONTINUE};
        MODE mode;
        
        bool process_line_unvalid = false;
        int material_out;
        int n_of_station;

        std::map<char,int> previous_state;
        std::string filter_string_out;
        

    public:
        // execute
        void welcome_go();
        bool go();


        // get user input
        void user_reset_or_continue();
        void user_in_material();
        void user_in_manufacture_line();
        bool user_Y_N();


        // output the data from MMI
        int get_material();
        int get_n_station();
        std::string get_s_code();
        std::map<char,int> get_previous_state();        

};


#endif