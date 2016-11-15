//
// Created by michael on 11/14/16.
//

#include <cstdlib>
#include "../include/lib.h"
#include <fstream>
#include <iostream>


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

/* Fills the test vector with random number vectors */
void
filltestvec(vec_of_int_vectors &test_vec)
{
// make 100 size array
    test_vec.push_back(get_rand_vector(100));
    // make 500 - 10,000 size arrays
    for (int size = 500; size <= 10000; size += 500)
    {
        // put rand vector into test vector
        test_vec.push_back(get_rand_vector(100));
    }
}

/* Returns string vector of input.txt lines */
string_vector
readinputfile()
{
    std::string line;
    std::ifstream file("../input.txt");
    if(file.is_open())
    {
        string_vector file_data;
        while(getline(file, line))
        {
            file_data.push_back(line);
        }
        file.close();

        return file_data;
    } else
    {
        std::cout << "Could not open input.txt" << std::endl;
    }
}

vec_of_int_vectors
parseinputfiledata(string_vector str_vector)
{
    // make vector to return
    vec_of_int_vectors size_and_vec;
    // Puts vector size into return vector
    vec_of_int_vectors.push_back(int_vector{std::stoi(str_vector[0])});

    // 
    return size_and_vec;
}
