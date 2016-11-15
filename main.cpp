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
    // Run brutewithtwist method
    int_vector brute_res = brutewithtwist(size_and_vec[1], size_and_vec[0][0]);
    // Run recursive method
    int_vector recursive_res = recursive(size_and_vec[1], size_and_vec[0][0]);
    // Run efficientiterative method
    int_vector iterative = efficientiterative(size_and_vec[1], size_and_vec[0][0]);
    
    // make vector to hold all 21 test arrays
    vec_of_int_vectors test_vec;
    // set rand seed
    srand(time(NULL));
    // fill vector with random int vectors of correct sizes
    filltestvec(test_vec);

    // test recursive alg
    int_vector result;
    int test_vec_size = (int)test_vec.size();
    for (int i = 0; i < test_vec_size; ++i) {
        result = recursive(test_vec[i], (int)test_vec[i].size());
        std::cout << result[0] << std::endl;
    }

    return 0;
}




// 1. brute force with recursion
// 2. more efficient brute force
// 3. opposite of kadane