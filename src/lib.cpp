#include <cstdlib>
#include "../include/lib.h"
#include "../include/algorithms.h"
#include <fstream>
#include <iostream>
#include <sstream>

#define NUM_OF_ALG_CALLS 10

std::string output_filename = "/home/michael/ClionProjects/AlgProject/outputFiles/output";
std::string time_filename = "/home/michael/ClionProjects/AlgProject/outputFiles/time";
std::string input_filename = "/home/michael/ClionProjects/AlgProject/input";
std::ofstream time_file(time_filename);
std::ofstream output_file(output_filename);

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
    std::ifstream file(input_filename);
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


void
logbrutetimes(int_vector &brute_res, vec_of_int_vectors &test_vec, int test_vec_size)
{
    clock_t t;
    for (int i = 0; i < test_vec_size; ++i)
    {
        t = clock();
        for(int j = 0; j < NUM_OF_ALG_CALLS; ++j)
        {
            brute(test_vec[i], (int) test_vec[i].size());
        }
        t = clock() - t;
        if(time_file.is_open())
        {
            time_file << (float)t / CLOCKS_PER_SEC / NUM_OF_ALG_CALLS * 1000;
            if(i < test_vec_size - 1)
            {
            time_file << ",";
            }
        } else
        {
            std::cout << "Could not open time.txt" << std::endl;
            return;
        }
    }
    time_file << std::endl;
}

void
logrecursivetimes(int_vector &recursive_res, vec_of_int_vectors &test_vec, int test_vec_size)
{
    clock_t t;
    for (int i = 0; i < test_vec_size; ++i)
    {
        t = clock();
        for(int j = 0; j < NUM_OF_ALG_CALLS; ++j)
        {
            recursive(test_vec[i], (int) test_vec[i].size());
        }
        t = clock() - t;
        if(time_file.is_open())
        {
            time_file << (float)t / CLOCKS_PER_SEC / NUM_OF_ALG_CALLS * 1000;
            if(i < test_vec_size - 1)
            {
            time_file << ",";
            }
        } else
        {
            std::cout << "Could not open time.txt" << std::endl;
            return;
        }
    }
    time_file << std::endl;
}

void
logiterativetimes(int_vector &iterative_res, vec_of_int_vectors &test_vec, int test_vec_size)
{
    clock_t t;
    for (int i = 0; i < test_vec_size; ++i)
    {
        t = clock();
        for(int j = 0; j < NUM_OF_ALG_CALLS; ++j)
        {
            iterative(test_vec[i], (int) test_vec[i].size());
        }
        t = clock() - t;
        if(time_file.is_open())
        {
            time_file << (float)t / CLOCKS_PER_SEC / NUM_OF_ALG_CALLS * 1000;
            if(i < test_vec_size - 1)
            {
            time_file << ",";
            }
        } else
        {
            std::cout << "Could not open time.txt" << std::endl;
            return;
        }

    }
    time_file << std::endl;
}

void
loginputresults(const int_vector &brute_res, const int_vector &recursive_res, const int_vector &iterative_res)
{
    if(output_file.is_open())
    {
        output_file << brute_res[0] << "," << brute_res[1] << "," << brute_res[2] << std::endl;
        output_file << recursive_res[0] << "," << recursive_res[1] << "," << recursive_res[2] << std::endl;
        output_file << iterative_res[0] << "," << iterative_res[1] << "," << iterative_res[2] << std::endl;
    } else
    {
        std::cout << "Could not open output.txt" << std::endl;
    }
}