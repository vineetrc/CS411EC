
#Extra Credit Project for CS 411


# CS411ExtraCredit

Commands to run JOINS with Nation and Region Files

*NOTE region.tbl files and nation.tbl files are already provided in the data folder of this repo
1. Clone the Repo
2. Navigate to the directory where main.cpp is located and run the following commands

# Compilation Command: 
    g++ -std=c++11  main.cpp join.cpp

### RUN these commands for SAMPLE CSV FILES (nation.tbl and region.tbl)

# Run NESTED LOOP JOIN (write to file looptest.tbl): 
    ./a.out ./data/region.tbl REGIONKEY  ./data/nation.tbl NESTED_LOOP  looptest.tbl

# Run HASH JOIN (write to file hashtest.tbl): 
    ./a.out ./data/region.tbl REGIONKEY  ./data/nation.tbl HASH  hashtest.tbl

# BENCHMARKING

BENCHMARKS for the joins of LINEITEMS and ORDERS on ORDERKEY
    
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


TAKEAWAYS: The NESTED LOOP JOIN takes significantly more time on average than the HASH Join. This is primarily because the HASH Join takes advantage of the O(1) lookup time of a hashmap while the NESTED_LOOP has 2 loops making it an O(n^2) algorithm generally. 

According to the textbook:

BLOCK-BASED NESTED LOOP JOIN COST: B(R) + B(R)*B(S)


HASH JOIN COST: B(R) + B(S)

DISCLAIMER: Since DATASET was too large, used Dr.Park's recoomendation and used a hash to cut the overall amount of data. Used a hash on ORDERKEY with a threshold of hash(ORDERKEY) < 0.01

Note that in the code implementation, the commented Code contains the hash filtering mechanism. It is commented out since it is not needed for running the smaller tests on Nation and Region Files.