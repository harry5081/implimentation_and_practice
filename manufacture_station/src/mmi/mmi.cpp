#include <mmi.h>

void MMI::user_reset_or_continue(){

    
    std::cout << "Welcom to Station Line "<< std::endl;
    std::cout << "You like to restart(Y) or continue the maunfacture line(N)? ";
    
    bool restart = user_Y_N();
    
    if(restart){
        mode = MODE::RESET;
        std::cout << "RESET" << std::endl;
    }
    else{
        mode =  MODE::CONTINUE;
        std::cout << "CONTINUE" << std::endl;
    }

}

void MMI::user_in_material(){

    int number;
    bool material_unvalid = false;

    do{
        material_unvalid = false;
        
        std::cout << "Please enter a material(an Integer) "<< std::endl;
                
        std::cin >> number;


        if(!std::cin.good()) // not an integer as material
        {   
            material_unvalid = true;
        }

        

        if(material_unvalid == true){
            std::cout  << std::endl;
            std::cout << "Your material is not valid" << std::endl;
        }
        
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        
        std::cout << "We set material to be: " << number << "   Do you agree? ";
  
    }//do
    while (!user_Y_N());

    material_out = number;

}

void MMI::user_in_manufacture_line(){

    std::string filter_string;
    std::vector<char> filter_char_v;

    do{
        
        filter_string.clear();
        filter_char_v.clear();

        std::string str;
        bool process_line_unvalid = false;
        std::cout << "The current stations we have are A, B, C, D. "<< std::endl;
        std::cout << "Enter a Manufacturing Line(e.g. AABDC): ";
        
        std::cin >> str;

        std::cout << "You entered: " << str << std::endl;

        
        for(int i=0; i<str.size();i++){        
            switch(str[i]) {
                case 'A':
                    filter_char_v.push_back('A');
                    break;
                case 'B':
                    filter_char_v.push_back('B');
                    break;
                case 'C':
                    filter_char_v.push_back('C');
                    break;
                case 'D':
                    filter_char_v.push_back('D');
                    break;
                case ' ':
                    break;

                default:
                    process_line_unvalid = true;
                    break;
            }

        }

        if(*(filter_char_v.begin()) == 'D'){
            process_line_unvalid = true;
            std::cout << "D station is not allowed to be the first one. " << std::endl;
            filter_char_v.erase(filter_char_v.begin());
        }

        if(process_line_unvalid == true){
            std::cout  << std::endl;
            std::cout << "Your Manufacturing Line is not valid" << std::endl;
        }

        std::string string_tmp(filter_char_v.begin(), filter_char_v.end());
        std::copy(string_tmp.begin(), string_tmp.end(), back_inserter(filter_string));
        std::cout << "We set it to be: " << string_tmp << "  Do you agree? ";
       
        

    }//do
    while (!user_Y_N());

        
    std::copy(filter_string.begin(), filter_string.end(), back_inserter(filter_string_out));

    n_of_station = filter_string_out.size();
    

    

}

bool MMI::user_Y_N(){

    std::cout << "Please enter (Y/N) "  << std::endl;
    char type;

    std::cin>>type;

    switch(type){

        case 'Y':
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << std::endl;
            return true;
            
        case 'N':
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << std::endl;
            return false;
            
        default:
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            user_Y_N();
            break;


    }


    
}

int MMI::get_material(){
    return material_out;
}

std::map<char,int> MMI::get_previous_state(){
    return previous_state;
}

int MMI::get_n_station(){
    return n_of_station;
}
std::string MMI::get_s_code(){
    return filter_string_out;
}
        

void MMI::welcome_go(){
    
    filter_string_out.clear();

    char station_type[4] = {'A','B','C','D'};
    int n_type = 4;

    user_reset_or_continue();
    if(mode == MODE::CONTINUE){
        std::cout << "Reading file to get previous station states...." << std::endl;
        read_station_state(previous_state);
    }
    else{
        std::cout << "Reset states of all stations" << std::endl;
        for(int i=0;i<n_type;i++){
            previous_state.insert({station_type[i], 0});
        }
    }

    // print all elements
    std::map<char,int>::iterator pos;
    for (pos = previous_state.begin(); pos != previous_state.end(); ++pos) {
        std::cout <<  pos->first << ':'<< pos->second << std::endl;
    }
    std::cout << std::endl;

    user_in_manufacture_line();
    user_in_material();
    

}

bool MMI::go(){
    
    
    filter_string_out.clear();
    
    std::cout << "Keep working....?";
    if(user_Y_N()){
        user_in_manufacture_line();
        user_in_material();

        return true;

    }
    else{
        return false;
    }    

}
