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
 input: abcabcbb
 characters: abc
 output: 3
 
 input: ababca
 Imp:   **
 Index: 01234
 max: 	2
 */
int longest_substring_without_repeating_characters(const std::string& input_string) {
	// Implementation using sliding window
	std::unordered_set<char> unique_characters;
	int left_pointer = 0;
	int max = 0;
	
	for(int index = 0; index < input_string.length(); ++index) {
		// Check if this character is in the set
		if(unique_characters.find(input_string[index]) == unique_characters.end()) {
			// This character is not in the set
			// So insert the character and update the max count
			unique_characters.insert(input_string[index]);
			max = std::max(max, index - left_pointer + 1);
		} else {
			// This character already exists in the set
			// So remove the characters already in the set, increasing the left pointer
			while(left_pointer != index && input_string[index] != input_string[left_pointer]) {
				unique_characters.erase(input_string[left_pointer++]);
			}
			
			unique_characters.erase(input_string[left_pointer++]);
			unique_characters.insert(input_string[index]);
			max = std::max(max, index - left_pointer + 1);
		}
	}
	
	return max;
}

void invoke_longest_substring_without_repeating_characters() {
	std::string input_string = "pwwkew";
	std::cout << longest_substring_without_repeating_characters(input_string) << std::endl;
}

// https://leetcode.com/discuss/interview-question/351783/
// Given a string, what is the minimum number of adjacent swaps required to convert a string into a palindrome. If not possible, return -1.
/*
 Input: mamad: maamd -> maadm -> madam
 Output: 3
 
 Input: damam:
 Output:
 
 Input: damam: admam -> amdam -> madam
 Output: 3
 
 Input: initn:
 Output:
 
 Input: asflkj
 Output: -1
 
 Input: aabb: abab -> abba
 Output: 2
 */

bool can_string_be_palindromic(const std::string& input_string) {
	bool is_even = input_string.length() % 2 == 0 ? false : true;
	if(is_even) {
	} else {
	}
	
	return true;
}
// Checks if the input string is palindrome
bool is_palindrome(const std::string& input_string) {
	size_t offset = input_string.length() - 1;
	for(size_t index = 0; index  <= (input_string.length() - 1) / 2; index++, offset--) {
		if(input_string[index] == input_string[offset]) {
			continue;
		}
		
		return false;
	}
	
	return true;
}
int min_adjancent_swaps_for_palindromic_string(const std::string& input_string) {
	int total_swaps = 0;
	if(input_string.length() < 1) {
		return -1;
	}
	// Initial validation
	if(input_string.length() == 1) {
		return 1;
	}
	if(is_palindrome(input_string)) {
		return 0;
	}
	
	// The input string is not a palindrome
	
	return -1;
}

/*
 767: Reorganize string
 https://leetcode.com/problems/reorganize-string/
 
 Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
 Return any possible rearrangement of s or return "" if not possible.
 */
std::string reorganize_string(const std::string& input_string) {
	/*
	 Input: aabb -> abab / baba
	 
	 Input: aab -> aba
	 
	 
	 Input: bbacce -> abcbce
	 Input: aaccbb -> acbacb / abacbc
	 Input: aaab -> ""
	 
	 Input: aaabcc -> acbaca -> acbaca
	 Solution: a | 3 | 2 | 1 | 0
	 c | 2 | 1 | 0
	 b | 1 | 0 |
	 
	 Input: aabcc -> abcac
	 */
	std::map<char, int32_t> character_map;
	
	// Insert the characters and their count in a hashmap
	for(const auto& input: input_string) {
		
	}
	return "";
}

/*
 https://leetcode.com/problems/longest-palindromic-substring/
 5. Longest Palindromic Substring
 */
std::string longest_palindromic_substring(const std::string& input_string) {
	/*
	 Input: babad
	 Type:	Odd
	 
	 Input: cbbd
	 
	 Input: caeeeeaz
	 
	 Input:	aleveldefe
	 Index: 0123456789
	 Mid:        |
	 Mid string: aleve ldefe
	 Type:	Even
	 */
	std::string longest_substring;
	
	// Input string is empty
	if(input_string.length() <= 1) {
		return input_string;
	}
	
	// Even case
	if(input_string.length() % 2 != 0) {
	} else {
		// odd case
	}
	
	return longest_substring;
}
void invoke_longest_palindromic_substring() {
	std::string input_string = "baad";
	std::cout << "Longest palidromic substring: " << longest_palindromic_substring(input_string);
}
