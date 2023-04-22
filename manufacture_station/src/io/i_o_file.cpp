#include <i_o_file.h>

const std::string filename = "station_state.txt";

void splitString(std::vector<std::string> &v_str,const std::string &str,const char ch)
    {
        std::string sub;
        std::string::size_type pos = 0;
        std::string::size_type old_pos = 0;
        bool flag=true;
        
            while(flag)
            {
                pos=str.find_first_of(ch,pos);
                if(pos == std::string::npos)
                {
                    flag = false;
                    pos = str.size();
                }
                sub = str.substr(old_pos,pos-old_pos);  // Disregard the '.'
                v_str.push_back(sub);
                old_pos = ++pos;
            }
    }

bool dump_station_state(std::map<char, int> station_state_record){
    
    std::ofstream ofile;

    ofile.open(filename.c_str());
    
    if(!ofile)  //file can not be read or created.
    {   
        std::cout << "Open File for Dump Fail" << std::endl;
        return false;           
    }

    for(std::map<char, int>::const_iterator iter= station_state_record.begin(); iter!=station_state_record.end(); ++iter)
    {
        ofile<<iter->first<<":"<<iter->second;
        ofile<<"\n";
        
    }
    std::cout << "Station states have been dumped" << std::endl;
    return true;

}

bool read_station_state(std::map<char, int>& station_state_record){

    //station_exe_record.clear();

    std::ifstream ifile;
    ifile.open(filename.c_str());

    if(!ifile){
        std::cout << "Open File for Read Station State Fail" << std::endl;
        return false;   //can not read the file.
    }
        
    std::string line;
    std::string key;
    std::vector<std::string> v_str;

    //while(ifile>>line)
    while(ifile>>line)
    {   
        //std::cout << line << std::endl;
        
        splitString(v_str, line, ':');
        for(std::vector<std::string>::iterator iter = v_str.begin();;++iter) //First vector element is the key.
        {
            if(iter == v_str.begin())
            {
                //stringMapTest[*iter]="wrong";
                //station_exe_record[*iter]="wrong";
                key = *iter;
                
                continue;
            }
            //stringMapTest[key]= *iter;
            
            station_state_record[char(key[0])] = std::stoi(*iter);
            
            //station_exe_record[key]= *iter;
            break;
        }
        line.clear();
        v_str.clear();
    }

    

    return true;
}

