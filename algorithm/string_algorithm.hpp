//
//  string_algorithm.hpp
//  algorithm
//
//  Created by Asesh Shrestha on 09/09/2021.
//  Copyright © 2021 Asesh Shrestha. All rights reserved.
//

#ifndef string_algorithm_hpp
#define string_algorithm_hpp

void string_permutation(char input_string[], int lower_index, int higher_index);
void split_and_print(int32_t input_array[], int32_t lower_index, int32_t higher_index);

int longest_substring_without_repeating_characters(const std::string& input_string);
void invoke_longest_substring_without_repeating_characters();

bool is_palindrome(const std::string& input_string);
int min_adjancent_swaps(const std::string& input_string);

std::string reorganize_string(const std::string& input_string);

std::string longest_palindromic_substring(const std::string& input_string);
void invoke_longest_palindromic_substring();

#endif /* string_algorithm_hpp */
