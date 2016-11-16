#include "../include/algorithms.h"


/* Brute force method with a twist
 * This algorithms slowly and surely goes through every possible continuous sub array within the given array.
 * It uses two for loops to accomplish this.*/
int_vector
brute(int_vector &vec, int vec_size)
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
 * This algorithms finds the min sub array within the given array starting at the last index.
 * We start at the last index in order to pop the last element off from the array when passing the argument recursively.
 * It then recursively calls itself, passing the same array without the last element */
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



/* Iterative Algorithm.
 * This algorithm is a spin off of the Kadane algorithm to find the max contiguous subarray given an array
 * I found the Kadane algorithm here: http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
 *
 * It effectively steps through the array once, keeping track of the smallest min subarray at the point where its
 * current index is, and sets the final min sub array whenever this found min sub array is smaller than
 * the current final min sub array. */
int_vector
iterative(int_vector &vec, int vec_size)
{
    int_vector min_vec;
    int abs_min = vec[0];
    int local_min = vec[0];
    int left_index = 0, right_index = left_index;

    for (int i = 1; i < vec_size; i++)
    {
        if(vec[i] < local_min + vec[i])
        {
            local_min = vec[i];
            left_index = i;
        }
        else
        {
            local_min = local_min + vec[i];
        }
        if(local_min < abs_min)
        {
            abs_min = local_min;
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
