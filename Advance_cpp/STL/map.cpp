#include <iostream>
#include <vector>
#include <map>

int main(){

    std::map<int, int> sparseArray;
    sparseArray[3] = 7;
    sparseArray[5] = 9;

    std::cout << sparseArray[3] << std::endl;
    std::cout << sparseArray.size() << std::endl;

    std::map<std::string, int> sparseArray2;
    sparseArray2["John"] = 6;
    sparseArray2["Mary"] = 9;

    std::cout << sparseArray2["Mary"] << std::endl;
    std::cout << sparseArray.size() << std::endl;

    std::vector<int> nums = {3, 7, 5, 1, 9};
    std::map<int, int> dict_pos;

    for(size_t i = 0; i< nums.size(); i++){
        dict_pos[nums[i]] = i;
    }

    for(auto kvp: dict_pos){
        std::cout << kvp.first << ":" << kvp.second << std::endl;
    }
    std::cout << dict_pos.count(5) << std::endl;
    
    return 0;
}