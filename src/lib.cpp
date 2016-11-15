//
// Created by michael on 11/14/16.
//

#include <cstdlib>
#include "../include/lib.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>


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
        test_vec.push_back(get_rand_vector(size));
    }
}

/* Returns an array of given size filled with random numbers */
int_vector
get_rand_vector(int size)
{
    int_vector vec;

    for (int index = 0; index < size; ++index)
    {
        // generate rand num between 1-1000
        int rand_num = 1000 - rand() % 2000;
        // add number to back of vector
        vec.push_back(rand_num);
    }

    return vec;
}

/* Returns string vector of input.txt lines */
string_vector
readinputfile()
{
    std::string line;
    std::ifstream file("/home/michael/ClionProjects/AlgProject/input");
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
        return string_vector{""};
    }
}

vec_of_int_vectors
parseinputfiledata(string_vector str_vector)
{
    // make vector to return
    vec_of_int_vectors size_and_vec;
    // Puts vector size into return vector
    int_vector size = int_vector{std::stoi(str_vector[0])};
    size_and_vec.push_back(size);

    int_vector nums;
    std::stringstream ss(str_vector[1]);
    while(ss.good())
    {
        std::string str_num;
        getline(ss, str_num, ',');
        int num = std::stoi(str_num);
        nums.push_back(num);
    }

    // Puts vector size into return vector
    size_and_vec.push_back(nums);

    return size_and_vec;
}
