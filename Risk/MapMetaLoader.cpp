#include "MapMetaLoader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

//std::vector<std::string> split(const std::string& s, char delimiter)
//{
//    std::vector<std::string> tokens;
//    std::string token;
//    std::istringstream tokenStream(s);
//    while (std::getline(tokenStream, token, delimiter))
//    {
//        tokens.push_back(token);
//    }
//    return tokens;
//}
//
//int MapMetaLoader::load(std::string filename)
//{
//    std::ifstream fin(filename);
//    if (fin.is_open()) {
//        std::string line;
//        std::vector<std::string> parts;
//        while (fin.good()) {
//            std::getline(fin, line);
//            parts = split(line, ' ');
//
//            for (auto i = parts.begin(); i != parts.end(); i++) {
//                std::cout << *i << " | ";
//            }
//            std::cout << std::endl;
//        }
//    }
//    return 0;
//}