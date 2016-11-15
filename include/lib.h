//
// Created by michael on 11/14/16.
//

#ifndef ALGPROJECT_LIB_H
#define ALGPROJECT_LIB_H

#include <vector>
#include <string>

typedef std::vector<int> int_vector;
typedef std::vector<std::vector<int>> vec_of_int_vectors;
typedef std::vector<std::string> string_vector;

/* Returns an array of given size filled with random numbers */
int_vector get_rand_vector(int size);

/* Fills the test vector with random number vectors */
void filltestvec(vec_of_int_vectors &test_vec);

/* Returns string vector of input.txt lines */
string_vector readinputfile();

/* Returns vector with size and input file test vector */
vec_of_int_vectors parseinputfiledata(string_vector str_vector);

void logbrutetimes(int_vector &brute_res, vec_of_int_vectors &test_vec, int test_vec_size);

void logrecursivetimes(int_vector &recursive_res, vec_of_int_vectors &test_vec, int test_vec_size);

void logiterativetimes(int_vector &iterative_res, vec_of_int_vectors &test_vec, int test_vec_size);

void loginputresults(const int_vector &brute_res, const int_vector &recursive_res, const int_vector &iterative_res);




#endif //ALGPROJECT_LIB_H
