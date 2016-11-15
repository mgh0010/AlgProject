#include <iostream>
#include <vector>
#include "include/algorithms.h"
#include "include/lib.h"



/* Runs program */
int
main()
{
    string_vector input_file_data = readinputfile();
    // check for bad input file or bad filepath
    if (input_file_data[0] == "")
    {
        return -1;
    }
    vec_of_int_vectors size_and_vec = parseinputfiledata(input_file_data);
    // make vector to pass into alg1
    int_vector brute_vec;
    brutewithtwist(size_and_vec[1], size_and_vec[0][0], &brute_vec);
    // make vector to hold all 21 test arrays
    vec_of_int_vectors test_vec;
    // fill vector with random int vectors of correct sizes
    filltestvec(test_vec);

    return 0;
}




// 1. brute force with recursion
// 2. more efficient brute force
// 3. opposite of kadane