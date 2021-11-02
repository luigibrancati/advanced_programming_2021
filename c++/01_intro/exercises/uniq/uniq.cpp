#include <iostream>
#include <string>
#include <vector>
#include <utility>


int main(){
    std::string input_line;
    std::vector<std::pair<unsigned int, std::string>> output;
    while(std::getline(std::cin, input_line)){
        if(output.size()>0 && input_line==output[output.size()-1].second){
            output[output.size()-1].first += 1;
        }
        else {
            output.push_back(std::pair<unsigned int, std::string>(1, input_line));
        }
    }
    for(auto& o:output){
        std::cout<<o.first<<" "<<o.second<<std::endl;
    }
    return 0;
}