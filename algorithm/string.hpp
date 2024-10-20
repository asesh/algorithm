//
//  string_algorithm.hpp
//  algorithm
//
//  Created by Asesh Shrestha on 09/09/2021.
//  Copyright © 2021 Asesh Shrestha. All rights reserved.
//

#ifndef string_hpp
#define string_hpp

void string_permutation(char input_string[], int lower_index, int higher_index);
void split_and_print(int32_t input_array[], int32_t lower_index, int32_t higher_index);

int longest_substring_without_repeating_characters(const std::string& input_string);
void invoke_longest_substring_without_repeating_characters();

bool is_palindrome(const std::string& input_string);
int min_adjancent_swaps(const std::string& input_string);

std::string reorganize_string(const std::string& input_string);

std::string longest_palindromic_substring(const std::string& input_string);
void invoke_longest_palindromic_substring();

bool is_anagram(const std::string& first_word, const std::string& second_word);
void invoke_is_anagram();

void invoke_levenshtein_distance();

/*
Valid IP Addresses: https://www.algoexpert.io/questions/valid-ip-addresses
*/
void invoke_valid_ip_address();

void invoke_valid_palindrome();

void invoke_is_subsequence();

/*
151. Reverse Words in a String: https://leetcode.com/problems/reverse-words-in-a-string
*/
void invoke_reverse_words_in_a_string();

/*
1405. Longest Happy String: https://leetcode.com/problems/longest-happy-string
*/
void invoke_longest_happy_string();

/*
1249. Minimum Remove to Make Valid Parentheses: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses
*/
void invoke_minimum_remove_to_make_valid_parenthesses();

#endif /* string_hpp */
