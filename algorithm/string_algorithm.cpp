//
//  string_algorithm.cpp
//  algorithm
//
//  Created by Asesh Shrestha on 09/09/2021.
//  Copyright © 2021 Asesh Shrestha. All rights reserved.
//

#include "header.h"
#include "string_algorithm.hpp"

void string_permutation(char input_string[], int lower_index, int higher_index) {
	// A B C
	// 0 1 2
	// 0 1 2 -> 0 2 1
	// 1 0 2 -> 1 2 0
	// 2 1 0 -> 2 0 1
	
	//	if(lower_index == higher_index) {
	//		std::cout<<input_string<<std::endl;
	//	}
	// 1: 0 2 ->
	for(int index = lower_index; index <= higher_index; index++) {
		std::swap(input_string[index], input_string[lower_index]);
		std::cout<<input_string<<std::endl;
	}
}

/*
 ABC
 ABC				BAC					CBA
 ABC ACB			BAC BCA			CBA CAB
 
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

// Longest substring without repeating characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
/*
 input: pwwkew
 characters: wke
 output: 3
 */
// Naive approach
int32_t longest_substring_without_repeating_characters(const std::string& input_string) {
	int32_t max_length = 0, counter = 0;
	std::set<char> char_set;
	for(const auto& character: input_string) {
		if(char_set.find(character) == char_set.end()) {
			char_set.insert(character);
		} else {
			counter = 0;
			char_set.clear();
			char_set.insert(character);
		}
		counter++;
		if(counter > max_length) {
			max_length = counter;
		}
	}
	return max_length;
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
