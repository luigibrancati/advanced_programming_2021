#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <iomanip>
#include <algorithm>

using decimal = double;

std::map<std::string, std::pair<decimal, std::string>> converter {
    //Lunghezza
    {"inches", std::pair<decimal, std::string>(0.0254,"m")},
    {"feet", std::pair<decimal, std::string>(0.3048,"m")},
    {"yard", std::pair<decimal, std::string>(0.9144,"m")},
    {"mm", std::pair<decimal, std::string>(0.001,"m")},
    {"cm", std::pair<decimal, std::string>(0.01,"m")},
    {"dm", std::pair<decimal, std::string>(0.1,"m")},
    {"km", std::pair<decimal, std::string>(1000,"m")},
    {"miles", std::pair<decimal, std::string>(1609.34,"m")},
    {"mile", std::pair<decimal, std::string>(1609.34,"m")},
    //Peso
    {"mg", std::pair<decimal, std::string>(0.001,"g")},
    {"cg", std::pair<decimal, std::string>(0.01,"g")},
    {"dg", std::pair<decimal, std::string>(0.1,"g")},
    {"kg", std::pair<decimal, std::string>(1000,"g")},
    {"ton", std::pair<decimal, std::string>(1000000,"g")},
    {"stone", std::pair<decimal, std::string>(6350.29,"g")},
    {"stones", std::pair<decimal, std::string>(6350.29,"g")},
    {"lib", std::pair<decimal, std::string>(453.592,"g")},
    {"libs", std::pair<decimal, std::string>(453.592,"g")},
    {"oz", std::pair<decimal, std::string>(28.3495,"g")}
};

// trim from start (copying)
static inline std::string ltrim(std::string s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    return s;
}

// trim from end (copying)
static inline std::string rtrim(std::string s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    return s;
}

// trim from both ends (copying)
static inline std::string trim(std::string s) {
    return rtrim(ltrim(s));
}

std::pair<decimal, std::string> split_string(std::string line, std::string sep){
    std::pair<decimal, std::string> output;
    size_t pos = std::min(line.find(sep), line.size());
    output.first = std::stof(line.substr(0, pos));
    output.second = line.substr(pos+1, line.size());
    return output;
}

std::string convert_measure(std::pair<decimal, std::string> measure, int precision=3){
    std::pair<decimal, std::string> conversion = converter[measure.second];
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision)<< measure.first*conversion.first;
    return stream.str() + " " + conversion.second;
}

int main(){
    std::string measure;
    std::cout<<"Enter a measure to be converted: ";
    std::getline(std::cin, measure);
    measure = trim(measure);
    std::cout<<"Converted: "<<convert_measure(split_string(measure, " "))<<std::endl;
    return 0;
}