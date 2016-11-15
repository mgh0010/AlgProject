//
// Created by michael on 11/14/16.
//

#include "../include/algorithms.h"


/* Brute force method with a twist
 * Explain this alg*/
int_vector
brutewithtwist(int_vector &vec, int vec_size)
{
    int_vector min_vec;
    int left_index = 0, right_index = 0;
    int local_min, abs_min = vec[0];

    for (int i= 0; i < vec_size; ++i)
    {
        local_min = 0;
        for (int j = i; j < vec_size; ++j)
        {
            local_min += vec[j];
            if(local_min < abs_min)
            {
                abs_min = local_min;
                left_index = i;
                right_index = j;
            }
        }
    }

    // push min value
    min_vec.push_back(abs_min);
    // push indexes
    min_vec.push_back(left_index);
    min_vec.push_back(right_index);

    return min_vec;
}


/* Recursively add sums and find the smallest
 * Explain this alg*/
int_vector
recursive(int_vector &vec, int vec_size)
{
    int_vector min_vec;

    int local_min = 0, right_index = vec_size - 1, left_index = right_index;
    // absolute min = last thing in vector
    int abs_min = vec[right_index];
    for (int index = right_index; index >= 0; --index)
    {
        local_min += vec[index];
        if (local_min < abs_min)
        {
            abs_min = local_min;
            left_index = index;
        }
    }
    // push min value
    min_vec.push_back(abs_min);
    // push indexes
    min_vec.push_back(left_index);
    min_vec.push_back(right_index);

    // Recursion if not base case
    if(vec_size > 1)
    {
        // Remove last element from vector and recurse
        vec.pop_back();
        int_vector recursed_result_vec = recursive(vec, right_index);
        // If recursion finds smaller min, set it as the new minimum
        if (recursed_result_vec[0] < abs_min)
        {
            min_vec = recursed_result_vec;
        }
    }

    return min_vec;
}



/* Brute force method with a twist
 * Explain this alg*/
int_vector
efficientiterative(int_vector &vec, int vec_size)
{
    int_vector min_vec;
    int abs_min = vec[0];
    int curr_min = vec[0];
    int left_index = 0, right_index = left_index;

    for (int i = 1; i < vec_size; i++)
    {
        if(vec[i] < curr_min + vec[i])
        {
            curr_min = vec[i];
            left_index = i;
        }
        else
        {
            curr_min = curr_min + vec[i];
        }
        if(curr_min < abs_min)
        {
            abs_min = curr_min;
            right_index = i;
        }
    }

    // push min value
    min_vec.push_back(abs_min);
    // push indexes
    min_vec.push_back(left_index);
    min_vec.push_back(right_index);

    return min_vec;
}
