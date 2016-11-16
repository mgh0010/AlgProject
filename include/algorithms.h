#ifndef ALGPROJECT_ALGORITHMS_H
#define ALGPROJECT_ALGORITHMS_H

#include <vector>

typedef std::vector<int> int_vector;
typedef std::vector<std::vector<int>> vec_of_int_vectors;

/* Brute force method with a twist
 * This algorithms slowly and surely goes through every possible continuous sub array within the given array.
 * It uses two for loops to accomplish this.*/
int_vector
brute(int_vector &vec, int vec_size);


/* Recursively add sums and find the smallest
 * This algorithms finds the min sub array within the given array starting at the last index.
 * We start at the last index in order to pop the last element off from the array when passing the argument recursively.
 * It then recursively calls itself, passing the same array without the last element */
int_vector
recursive(int_vector &vec, int vec_size);



/* Iterative Algorithm.
 * This algorithm is a spin off of the Kadane algorithm to find the max contiguous subarray given an array
 * I found the Kadane algorithm here: http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
 *
 * It effectively steps through the array once, keeping track of the smallest min subarray at the point where its
 * current index is, and sets the final min sub array whenever this found min sub array is smaller than
 * the current final min sub array. */
int_vector
iterative(int_vector &vec, int vec_size);

#endif //ALGPROJECT_ALGORITHMS_H
