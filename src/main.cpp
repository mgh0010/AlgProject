#include <iostream>
#include <vector>
#include <unistd.h>
#include "../include/algorithms.h"
#include "../include/lib.h"


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

    // Test algs with input.txt data
    int_vector brute_res = brute(size_and_vec[1], size_and_vec[0][0]);
    int_vector recursive_res = recursive(size_and_vec[1], size_and_vec[0][0]);
    int_vector iterative_res = iterative(size_and_vec[1], size_and_vec[0][0]);

    // Write results from input.txt to output.txt
    std::cout << "Writing results calculated from input.txt to outputFiles/output.txt..." << std::endl;
    sleep(1);
    loginputresults(brute_res, recursive_res, iterative_res);

    // Make vector to hold all 21 test arrays
    std::cout << "Making test arrays..." << std::endl;
    sleep(1);
    vec_of_int_vectors test_vec;
    // Set rand seed
    srand((unsigned int)time(NULL));
    // Fill vector with random int vectors of correct sizes
    filltestvec(test_vec);

    // Test algs with random generated data
    std::cout << "Running algorithms over test arrays..." << std::endl;
    int test_vec_size = (int)test_vec.size();
    logbrutetimes(brute_res, test_vec, test_vec_size);
    logrecursivetimes(recursive_res, test_vec, test_vec_size);
    logiterativetimes(iterative_res, test_vec, test_vec_size);
    std::cout << "Logging execution times to outputFiles/time.txt" << std::endl;
    sleep(1);

    return 0;
}
