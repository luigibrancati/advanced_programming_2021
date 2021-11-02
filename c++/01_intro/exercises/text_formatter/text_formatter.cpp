#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>

size_t avoid_word(std::string line, size_t pos){
    try{
        while(line.at(pos-1)!=' '){
            pos-=1;
        }
    }
    catch (const std::out_of_range& e) {
        return line.length();
    }
    return pos-1;
}

std::vector<std::string> formatter(std::ifstream& file, size_t tresh){
    if(!file)
    {
        std::cerr << "Cannot open the file"<<std::endl;
        return std::vector<std::string>(1, "");
    }
    // Read file
    std::vector<std::string> lines;
    std::string line;
    while(std::getline(file, line)){
        if(line.length()>0){
            lines.push_back(line);
        }
    }
    // Split lines
    for(int i=0; i<lines.size(); i++){
        if(lines[i].size()>tresh){
            size_t split = avoid_word(lines[i], tresh);
            if(split==lines[i].length()){
                continue;
            }
            else if(i<lines.size()-1){
                lines[i+1] = lines[i].substr(split+1, lines[i].length()) + lines[i+1];
            }
            else {
                lines.push_back(lines[i].substr(split+1, lines[i].length()));
            }
            lines[i] = lines[i].substr(0, split);
        }
    }
    return lines;
}

std::string formatter(std::string text, size_t tresh){
    std::string output = "";
    size_t pos = text.find("\\n");
    while(pos<text.size()){
        if(pos>tresh){
            output += text.substr(0, tresh)+"\\n";
            text.replace(pos,pos+2," ");
            text.erase(0, tresh);
        }
        else {
            output += text.substr(0, pos+2);
            text.erase(0, pos+2);
        }
        pos = text.find("\\n");
    }
    if(text.size()>0){
        output += text+"\\n";
    }
    return output;
}

int main(){
    std::ifstream file("./test_file.txt");
    std::vector<std::string> lines = formatter(file, 20);
    for(auto& l:lines){
        std::cout<<l<<std::endl;
    }
}