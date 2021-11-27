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

    return 0;
}
