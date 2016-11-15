#include <iostream>
#include <vector>
#include "algorithms.h"



/* Returns an array of given size filled with random numbers */
int_vector
get_rand_vector(int size)
{
    int_vector vec;

    for (int index = 0; index < size; ++index)
    {
        // generate rand num between 1-1000
        int rand_num = rand() % 1000 + 1;
        // binary random decision to make it negative
        if(rand() % 2 == 1)
        {
            rand_num *= -1;
        }
        // add number to back of vector
        vec.push_back(rand_num);
    }

    return vec;
}


/* Runs program */
int
main()
{
    // make vector to hold all 21 test arrays
    vec_of_int_vectors test_vec;

    // make 100 size array
    test_vec.push_back(get_rand_vector(100));
    // make 500 - 10,000 size arrays
    for (int size = 500; size <= 10000; size += 500)
    {
        // put rand vector into test vector
        test_vec.push_back(get_rand_vector(100));
    }

    return 0;
}

// 1. brute force with recursion
// 2. more efficient brute force
// 3. opposite of kadane