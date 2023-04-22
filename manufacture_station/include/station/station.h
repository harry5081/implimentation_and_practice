#ifndef STATION_H
#define STATION_H

#include <iostream>

class STATION{

public:

    char name;

    int exe_n_time = 0;

    virtual void print(){
        std::cout<< "This is station Abstract" <<std::endl;
    }
    virtual void manufacture(int& material) = 0;
    virtual void give_to(STATION*** my_turn_ptr, int& material, int* station_left) = 0;
    virtual void exe(STATION*** my_turn_ptr, int& material, int* station_left) = 0;

    bool finish_stop = false;
    
    STATION(){
        
        //std::cout<< "This is station ABSTACT constructor" << std::endl;
     }

};

class STATION_A: public STATION{

public:
    STATION_A(char name){
        this->name = name;
        //std::cout<< "This is station "<< name << " constructor" <<std::endl;
    }

    void print(){
        std::cout<< "I am station A" << name <<std::endl;
    }

    void manufacture(int& material){
        
        std::cout<< "STATION A MANUFACTURE"<<std::endl;
        material++;
        std::cout<< "material: "<< material<<std::endl;
    }

    void give_to(STATION*** my_turn_ptr, int& material, int* station_left){
        
        (*station_left)--;
        if(*station_left>0){            
            (*my_turn_ptr)++;            
            std::cout<< "station A gives to "<< ((**my_turn_ptr)->name) << std::endl;
        }
        else{
            std::cout<< "No station after "<< ((**my_turn_ptr)->name) << std::endl;
            finish_stop = true;
        }
        std::cout<< "station left: "<< (*station_left) << std::endl;
        
    }

    void exe(STATION*** my_turn_ptr, int& material, int* station_left){
        std::cout<< "This is "<< ((**my_turn_ptr)->name) << std::endl;
        exe_n_time++;
        manufacture(material);
        give_to(my_turn_ptr, material, station_left);
        
    }

    
};

class STATION_B: public STATION{

public:
    STATION_B(char name){
        this->name = name;
        //std::cout<< "This is station "<< name << " constructor" <<std::endl;
    }

    void print(){
        std::cout<< "I am station B" << name <<std::endl;
    }

    void manufacture(int& material){
        
        std::cout<< "STATION B MANUFACTURE"<<std::endl;
        material--;
        std::cout<< "material: "<< material<<std::endl;
    }

    void give_to(STATION*** my_turn_ptr, int& material, int* station_left){
        
        (*station_left)--;
        if(*station_left>0){            
            (*my_turn_ptr)++;            
            std::cout<< "station B gives to "<< ((**my_turn_ptr)->name) << std::endl;
        }
        else{
            std::cout<< "No station after "<< ((**my_turn_ptr)->name) << std::endl;
            finish_stop = true;
        }
        std::cout<< "station left: "<< (*station_left) << std::endl;
    }
    

    void exe(STATION*** my_turn_ptr, int& material, int* station_left){
        std::cout<< "This is B" << std::endl;
        manufacture(material);
        //manufactureB(material);
        give_to(my_turn_ptr, material, station_left);
        
    }
    
};

class STATION_C: public STATION{

public:
    STATION_C(char name){
        this->name = name;
        //std::cout<< "This is station "<< name << " constructor" <<std::endl;
    }

    void print(){
        std::cout<< "I am station " << name <<std::endl;
    }

    void manufacture(int& material){
        
        std::cout<< "STATION C MANUFACTURE"<<std::endl;
        std::cout<< "material: "<< material<<std::endl;
        
    }

    void give_to(STATION*** my_turn_ptr, int& material, int* station_left){

        int material_tmp = material;
        
        (*station_left)--;

        if(material_tmp % 2 == 0){
            std::cout<< ((**my_turn_ptr)->name) << " gets even value"<< std::endl;

            if(*station_left>1){
                (*my_turn_ptr)++;  
                (*my_turn_ptr)++;  
                (*station_left)--;          
                std::cout<< "station C gives to "<< ((**my_turn_ptr)->name) << std::endl;

            }
            else{
                std::cout<< "Left station after C not enough " << std::endl;
                finish_stop = true;
            }

        } // if even value

        else{
            std::cout<< ((**my_turn_ptr)->name) << " gets odd value"<< std::endl;

            if(*station_left>0){            
            (*my_turn_ptr)++;      
               
            std::cout<< "station C gives to "<< ((**my_turn_ptr)->name) << std::endl;
            }
            else{
                std::cout<< "No station after "<< ((**my_turn_ptr)->name) << std::endl;
                finish_stop = true;
            } // else old value

        }

    std::cout<< "station left: "<< *station_left << std::endl;    
    }

    void exe(STATION*** my_turn_ptr, int& material, int* station_left){
        std::cout<< "This is "<< ((**my_turn_ptr)->name) << std::endl;
        exe_n_time++;
        manufacture(material);
        give_to(my_turn_ptr, material, station_left);
        
    }
    
};

class STATION_D: public STATION{

public:
    STATION_D(char name){
        this->name = name;
        //std::cout<< "This is station "<< name << " constructor" <<std::endl;
    }

    void print(){
        std::cout<< "I am station " << name <<std::endl;
    }

    void manufacture(int& material){
       
        std::cout<< "STATION D MANUFACTURE"<<std::endl;
        
        
    }

    void give_to(STATION*** my_turn_ptr, int& material, int* station_left){

        
        (*station_left)--;
        if(*station_left>0){            
            (*my_turn_ptr)++;            
            std::cout<< "station D gives to "<< ((**my_turn_ptr)->name) << std::endl;
        }
        else{
            std::cout<< "No station after "<< ((**my_turn_ptr)->name) << std::endl;
            finish_stop = true;
        }
        std::cout<< "station left: "<< (*station_left) << std::endl;
    }

    void exe(STATION*** my_turn_ptr, int& material, int* station_left){
        std::cout<< "This is "<< ((**my_turn_ptr)->name) << std::endl;
        exe_n_time++;
        STATION** last_ptr = *(my_turn_ptr);
        last_ptr--;
        (*last_ptr)->manufacture(material);
        give_to(my_turn_ptr, material, station_left);
        
    }
    
};




#endif