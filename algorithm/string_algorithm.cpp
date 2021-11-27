//
//  string_algorithm.cpp
//  algorithm
//
//  Created by Asesh Shrestha on 09/09/2021.
//  Copyright © 2021 Asesh Shrestha. All rights reserved.
//

#include "header.h"
#include "string_algorithm.hpp"

/*
 ABC
 ABC				BAC					CBA
 ABC ACB			BAC BCA			CBA CAB
 
 012			102				210
 012 021	102 120		210 201
 
 AB -> 2! = 2 * 1 = 2
 AB BA
 
 Source: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
 */
void permutation_of_string(std::string& input_string, int lower_index, int higher_index) {
	
	if(lower_index == higher_index) {
		std::cout<<input_string<<std::endl;
	} else {
		for(int index = lower_index; index <= higher_index; index++) {
			// 1: I: 0 LI: 0 HI: 1 = AB
			// 2: I: 1 LI: 0 HI: 1
			std::swap(input_string[index], input_string[lower_index]);
			permutation_of_string(input_string, lower_index + 1, higher_index);
			std::swap(input_string[index], input_string[lower_index]);
		}
	}
}

/*
 1 2 3 4 5
 1 2 3 | 4 5
 1 | 2
 */
void split_and_print(int32_t input_array[], int32_t lower_index, int32_t higher_index) {
	if(lower_index < higher_index) {
		auto median = (lower_index + higher_index) / 2;
		split_and_print(input_array, lower_index, median);
		//		split_and_print(input_array, median + 1, higher_index);
		std::cout<<input_array[median]<<" ";
	}
}

/*
 3. Longest substring without repeating characters
 https://leetcode.com/problems/longest-substring-without-repeating-characters/
 
 Problem:
 input: pwwkew
 characters: wke
 output: 3
 */
int longest_substring_without_repeating_characters(const std::string& input_string) {
	return 0;
}

void invoke_longest_substring_without_repeating_characters() {
	std::string input_string = "pwwkew";
	std::cout << longest_substring_without_repeating_characters(input_string);
}
