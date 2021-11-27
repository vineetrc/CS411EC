
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
    
    NESTEDLOOPJOIN (AVG): 144185374 microseconds (around 2.4 minutes)
    HASHJOIN (AVG): 30 seconds AVG

    DISCLAIMER: Since DATASET was too large, used Dr.Park's recoomendation and used a hash to cut the overall amount of data. Used a hash on ORDERKEY with a threshold of hash(ORDERKEY) < 0.1

    Note that in the code implementation, the commented Code contains the hash filtering mechanism. It is commented out since it is not needed for running the smaller tests on Nation and Region Files Verifying for Correctness.