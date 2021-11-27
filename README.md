
#Extra Credit Project for CS 411


# CS411ExtraCredit

Commands to run with provided (Nation and Region Files). Run these commands to verify correctness from the direcotry where main.cpp is located


# Compilation Command: 
    g++ -std=c++11  main.cpp join.cpp

# Run NESTED LOOP JOIN (write to file looptest.tbl): 
    ./a.out ./data/region.tbl REGIONKEY  ./data/nation.tbl NESTED_LOOP  looptest.tbl

# Run HASH JOIN (write to file hashtest.tbl): 
    ./a.out ./data/region.tbl REGIONKEY  ./data/nation.tbl HASH  hashtest.tbl

# BENCHMARKING

BENCHMARKS Given for the JOIN of LINEITEMS and ORDERS on ORDERKEY
    ALL MARKS of the AVERAGE of 10 runs:
    
    NESTED LOOP JOIN STATISTICS:
        Iteration 0 took: 130488240 microseconds
        Iteration 1 took: 139611762 microseconds
        Iteration 2 took: 236482821 microseconds
        Iteration 3 took: 143621481 microseconds
        Iteration 4 took: 121202169 microseconds
        Iteration 5 took: 125653486 microseconds
        Iteration 6 took: 132158750 microseconds
        Iteration 7 took: 125003932 microseconds
        Iteration 8 took: 177286295 microseconds
        Iteration 9 took: 127883006 microseconds
        AVG TIME per join is 145939194 microseconds
    
    HASH JOIN STATISTICS Program Output:
        Iteration 0 took: 508560 microseconds
        Iteration 1 took: 483130 microseconds
        Iteration 2 took: 455785 microseconds
        Iteration 3 took: 461192 microseconds
        Iteration 4 took: 453712 microseconds
        Iteration 5 took: 454724 microseconds
        Iteration 6 took: 460034 microseconds
        Iteration 7 took: 456801 microseconds
        Iteration 8 took: 471699 microseconds
        Iteration 9 took: 474220 microseconds
        AVG TIME per join is 467985 microseconds


DISCLAIMER: Since DATASET was too large, used Dr.Park's recoomendation and used a hash to cut the overall amount of data. Used a hash on ORDERKEY with a threshold of hash(ORDERKEY) < 0.01

Note that in the code implementation, the commented Code contains the hash filtering mechanism. It is commented out since it is not needed for running the smaller tests on Nation and Region Files Verifying for Correctness.