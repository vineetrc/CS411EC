//#pragma once
#include "Join.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>

using namespace std;
Join::Join(std::string input1, std::string input2, std::string join_key){

    this->joinkey = join_key;
    
    std::ifstream my_file;
    my_file.open(input1);
    std::string line;

    int i = 0;
    while(getline(my_file, line)){        
        std::vector<std::string> words{};
        size_t pos = 0;
        std::string delim = "|";
        double num = 0;
        std::hash<std::string> hash_fn;
        bool start = true;
        while ((pos = line.find(delim)) != string::npos) {
            if(i ==0){
                if (line.substr(0, pos).compare(join_key) == 0){
                    join_key_idx1 = cols1.size();
                    std::cout << join_key_idx1 << std::endl;
                }
                cols1.push_back(line.substr(0, pos));
            }
            else if (start && std::abs((((int) hash_fn(line.substr(0, pos)))%10000000)/10000000.0) > 0.01){
                num = std::abs((((int) hash_fn(line.substr(0, pos)))%10000000)/10000000.0); 
                start = false;
                break;
            }
            else{
                words.push_back(line.substr(0, pos));
            }
            line.erase(0, pos + delim.length());
            start = false;
        }
        if (i!=0 && num < 0.01){
            table1.push_back(words);
            std::cout << i << std::endl;
        }
        
        i++;
    }
    std::cout << table1.size() << std::endl;
    my_file.close();

    //std:cout << table1[0].size();

    // for (int i = 0; i < table1.size(); i++){
    //     for (int j = 0; j < table1[0].size(); j++)
    //        std::cout<< table1[i][j];
    //     std::cout << std::endl;
    // }

    cout << "Halwfawy less gooo" << std::endl;

    my_file.open(input2);
    // std::string line;

    i = 0;
    while(getline(my_file, line)){        
        std::vector<std::string> words{};
        size_t pos = 0;
        std::string delim = "|";
        double num = 0;
        std::hash<std::string> hash_fn;
        bool start = true;
        while ((pos = line.find(delim)) != string::npos) {
            if(i ==0){
                if (line.substr(0, pos).compare(join_key) == 0){
                    join_key_idx2 = cols2.size();
                }
                cols2.push_back(line.substr(0, pos));
            }
            else if (start && std::abs((((int) hash_fn(line.substr(0, pos)))%10000000)/10000000.0) > 0.01){
                num = std::abs((((int) hash_fn(line.substr(0, pos)))%10000000)/10000000.0); 
                start = false;
                break;
            }
            else{
                words.push_back(line.substr(0, pos));
            }
            line.erase(0, pos + delim.length());
            start = false;
        }
        if (i!=0 && num < 0.01){
            table2.push_back(words);
            std::cout << i << std::endl;
        }
        
        i++;
    }

    my_file.close();

    //std:cout << "***************************"<<std::endl;

    // for (int i = 0; i < table2.size(); i++){
    //     for (int j = 0; j < table2[0].size(); j++)
    //        std::cout<< table2[i][j];
    //     std::cout << std::endl;
    // }
    
    // std::cout<< join_key_idx1 << "   " << join_key_idx2<< std::endl;
}


void Join::LoopJoin(std::string output){
    ofstream out(output);
    // writing in columns
    for (string w : cols1){
        out << "|" << w;
    }

    for (string w : cols2){
        if (w.compare(joinkey)!=0)
            out << "|" << w;
    }
    out << "|" << endl;


    for (int i = 0; i < table1.size(); i++){
        for (int j = 0; j < table2.size(); j++){
            if (table1[i][join_key_idx1].compare(table2[j][join_key_idx2]) == 0){
                for (string w : table1[i])
                    out << "|" << w;

                for(int k = 0; k < table2[j].size(); k++){
                    if (k!= join_key_idx2)
                        out << "|" << table2[j][k];
                }
                out << "|" << endl;
            }
        }
    }
    out.close();
}

void Join::HashJoin(std::string output){
    // create hashtable
    unordered_map<string, vector<string> > hashtable;

    // creating hashtable
    for (int i = 0; i < table1.size(); i++){
        hashtable[table1[i][join_key_idx1]] = table1[i];
    }

    // creating column headers
    ofstream out(output);
    for (string w : cols1){
        out << "|" << w;
    }

    for (string w : cols2){
        if (w.compare(joinkey)!=0)
            out << "|" << w;
    }
    out << "|" << endl;


    for(int i = 0; i < table2.size(); i++){
        for (string w : hashtable[table2[i][join_key_idx2]])
            out << "|" << w;
        
        for(int k = 0; k < table2[i].size(); k++){
            if (k!= join_key_idx2)
                out << "|" << table2[i][k];
            }
            out << "|" << endl;
    }


}