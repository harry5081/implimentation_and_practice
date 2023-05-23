#include <vector>
#include <iostream>

int main(){
    //mission 1
    std::vector<int> user_input;
    int tmp = 0;
    while(true){
        std::cin >> tmp;
        user_input.push_back(tmp);
        if(tmp == 0){
            break;
        }
    }

    //mission 2
    std::cout << "how many:" << user_input.size() <<std::endl;
    for(auto it = user_input.begin(); it != user_input.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    //mission 3

    std::vector<std::vector<int>> nine_nine_table;

    for(int i = 0; i<9; i++){
        std::vector<int> v_tmp;
        for(int j = 0; j<9; j++){
            
            v_tmp.push_back((i+1)*(j+1));
        }
        nine_nine_table.push_back(v_tmp);      
    }

    for(auto it = nine_nine_table.begin(); it != nine_nine_table.end(); it++){
        for(auto it2 = (*it).begin(); it2 != (*it).end(); it2++){
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<int>> method_1(9);
    std::vector<int> method_2[9];

    for(int i = 0; i<method_1.size(); i++){
        method_1[i].resize(9);
        method_2[i].resize(9);
    }
    for(int i = 0; i<method_1.size(); i++){
        for(int j = 0; j<method_1[i].size(); j++){
            method_1[i][j]=(i+1)*(j+1);
            method_2[i][j]=(i+1)*(j+1);
        }
    }
    for(int i = 0; i<method_1.size(); i++){
        for(int j = 0; j <method_1[i].size(); j++){
            std::cout << method_1[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}