#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Join.h"
#include <functional>
#include <cmath>
#include <chrono>
 
using namespace std;
using namespace std::chrono;

// ./a.out ./data/region.tbl REGIONKEY  ./data/nation.tbl NESTED_LOOP  hashtest.tbl
// ./a.out ./data/region.tbl REGIONKEY  ./data/nation.tbl HASH  hashtest.tbl

int main(int argc, char *argv[]) {
    int max = 100;

    std::string str = "vineet";
    std::hash<std::string> hash_fn;

    double num = std::abs((((int) hash_fn(str))%10000000)/10000000.0);

    std::cout << num << std::endl;
    
    std::string input_file_one = argv[1];
    std::string join_col_one = argv[2];
    std::string input_file_two = argv[3];
    std::string join_type = argv[4];
    std::string output_file = argv[5];
    std::cout << "initializing" << endl;
    Join algo(input_file_one, input_file_two, join_col_one);
    std::cout << "initializing Done" << endl;

    if (join_type.compare("HASH") == 0){
        int tot = 0;
        std::cout << "HASH JOIN STATISTICS" << std::endl;
        for (int i = 0; i < 10; i++){
            auto start = high_resolution_clock::now();
            algo.HashJoin(output_file);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Iteration " << i << " took: " << duration.count() << " microseconds" << endl;
            tot+= duration.count();
        }
        cout << "AVG TIME per join is " << tot/10 << " microseconds"<< std::endl;
            
    }
    else if (join_type.compare("NESTED_LOOP") == 0){
        int tot = 0;
        std::cout << "NESTED LOOP JOIN STATISTICS" << std::endl;
        for (int i = 0; i < 10; i++){
            auto start = high_resolution_clock::now();
            algo.LoopJoin(output_file);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Iteration " << i << " took: " << duration.count() << " microseconds" << endl;
            tot+= duration.count();
        }
        cout << "AVG TIME per join is " << tot/10 << " microseconds"<< std::endl;
    }
    else
        std::cout << "error, Join Algorithm Not Recognized" << std::endl;






    // ifstream my_file;
    // my_file.open("./data/region.tbl");
    // std::string line;
    // vector<string> keys{};
    // int key_idx1 = 0;
    // int i = 0;
    // while(getline(my_file, line)){
    //     //std::cout << line << std::endl;
        
    //     vector<string> words{};
    //     size_t pos = 0;
    //     std::string delim = "|";
    //     while ((pos = line.find(delim)) != string::npos) {
    //         if(i ==0){
    //             if (line.substr(0, pos).compare("REGIONKEY") == 0){
    //                 key_idx1 = keys.size();
    //             }
    //             keys.push_back(line.substr(0, pos));
    //         }
    //         else{
    //             words.push_back(line.substr(0, pos));
    //         }
    //         line.erase(0, pos + delim.length());
    //     }
    //     i++;
    // }

    // for (int i = 0; i < keys.size(); i++){
    //        std::cout<<keys[i]<<"---";
    // }
    
    // std::cout << key_idx1 << "da one" <<std::endl;
    
    
    
    
    //java -cp "*.jar" edu.illinois.netid.Main input1.csv left_col_name1 input2.csv join_col_name2 NESTED_LOOP output.csv
    //std::cout << "md5 of 'grape': " << md5("grape") << std::endl;

    // long long num1 = 98745636214564698;
    // long long num2 = 7459874565236544789;
    // cout << "Product of "<< num1 << " * "<< num2 << " = " << large_product(num1,num2) <<std::endl;
    //long long number = std::stoi(md5("grape"), 0, 16);
    // int128_t x;   
    // std::stringstream ss;
    // ss << std::hex << "fffefffe";
    // ss >> x;
    //std::cout << boost::md5("message").hex_str_value();

    //std::cout << number << std::endl;
    

    

    
    // std::cout << argv[1] << std::endl;
    



    return 0;
}
