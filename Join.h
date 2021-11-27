#pragma once
#include <cmath>
#include <string>
#include <vector>

class Join {
    public:
        Join(std::string input1, std::string input2, std::string joinkey);

        void LoopJoin(std::string output);

        void HashJoin(std::string output);


    private:
        std::vector< std::vector<std::string> > table1;
        std::vector< std::vector<std::string> > table2;

        std::vector<std::string> cols1;
        std::vector<std::string> cols2;

        int join_key_idx1;
        int join_key_idx2;

        std::string joinkey;
};