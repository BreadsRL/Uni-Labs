#ifndef LAB6_H
#define LAB6_H

#include <iostream>
#include<vector>

// Exercise 1
// You can assume that the input vector "numbers" contains exactly one element that appears only once. Every other element is duplicated. Find the element that appears only once and have your function return it.

// Example:
// Input: [1,2,3,1,3], Output: 2
// Input: [1], Output: 1
int singleton(std::vector<int> numbers){

    for (int i = 0; i < numbers.size(); i++){

        int place;
        for(place=0; place < numbers.size(); place++){

            if (numbers[i] == numbers[place] && place != i){

                break;

            }
        }

        if (place == numbers.size()){

            return numbers[i];

        }
    }

    return 0;
}

// Exercise 2
// The input vector is supposed to contain all integers from 0 to n, but one is missing. Find the missing one and have your function return it.

// Example:
// Input: [1,2,3], Output: 0
// Input: [0,1,3], Output: 2
int missing(std::vector<int> numbers){

    int j;

    for (j=0; j < numbers.size(); j++){

        if (j != numbers[j]){

            return j;
        }
    }
    return j;
}

// Exercise 3
// The following function should return true if the input vector contains duplicates and false otherwise.

// Example:
// Input: [1,2,3,4,5], Output: false
// Input: [1,2,1,3,4], Output: true
bool containsDuplicate(std::vector<int> numbers){

    for (int j = 0; j < numbers.size(); j++){

        for (int k = 1 +j; k < numbers.size(); k++){

            if (numbers[k] == numbers[j]){

                return true;
            }
        }
    }
    return false;
}

// Exercise 4
// The following function is to compress a list of integers into a smaller list of integers, without losing any information.
// Compress the list by replacing all consecutive integers by the endpoints of the range they fall into.
// Example 1:
// Input: [1,2,3,4,5,6], Output: [1,6]
// The entire list is made up of a sequence of consecutive integers, so we just return the endpoints in a list

// Example 2:
// Input: [1,2,3,5,6,7], Output: [1,3,5,7]
// In this example the list is made up of two disjoint sequences, 1-3, and 5-7, so our output is [1,3,5,7]
// The output list should always contain an even number of values

// Example 3:
// Input: [1,2,3,5,7,8], Output: [1,3,5,5,7,8]
// This example has 3 disjoint sequences, 1-3, 5-5 (a sequence with only one element), and 7-8
std::vector<int> compress(std::vector<int> numbers){
    std::vector<int> result;

    int j = 0;
    
    while (j < numbers.size()){

    if (numbers[j] == numbers[j-1] + 1 && numbers[j] == numbers[j+1]-1){

        // Not add to the outcome vector
    }

    if (numbers[j] == numbers[j-1] + 1 && numbers[j] != numbers[j+1]-1){

        result.push_back(numbers[j]);
    }

    if ((numbers[j] != numbers[j-1] + 1 || j == 0) && numbers[j] == numbers[j+1]-1){

        result.push_back(numbers[j]);
    }

    if (numbers[j] != numbers[j-1] + 1 && numbers[j] != numbers[j+1]-1){

        result.push_back(numbers[j]);
        result.push_back(numbers[j]);
    }

    j++;

    }

    return result;
}

// Exercise 5
// This is the inverse of exercise 4. Namely, given a compressed list as per the scheme described in exercise 4, your function should restore it to the original.

// Example:
// Input: [1,3,5,7], Output: [1,2,3,5,6,7]
std::vector<int> decompress(std::vector<int> numbers){
    std::vector<int> result;

    for (int j = 0; j < numbers.size(); j += 2){

        for (int k = numbers[j]; k <= numbers[j + 1]; k++){

            result.push_back(k);
        }
    }

    return result;
}

// Exercise 6
// The input is a set of n elements, and the values should be all integers from 1 to n. However, for some unknown reason one of the values was overwritten with another value from the set. This means that one value is duplicated and one is missing. Find the missing value, and have your function return it.
// Example: 
// Input: [1,2,5,4,5,6] Output: 3
// You can see that there are two 5s, and there is no 3, therefore the output is 3
int detectError(std::vector<int> numbers){
    

    numbers.insert(numbers.begin(), 0);

    return missing(numbers);
}


#endif
