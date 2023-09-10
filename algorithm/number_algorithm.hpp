//
//  number_algorithm.hpp
//  algorithm
//
//  Created by Asesh Shrestha on 09/09/2021.
//  Copyright © 2021 Asesh Shrestha. All rights reserved.
//

#ifndef number_algorithm_hpp
#define number_algorithm_hpp

void print_reverse(int input_array[], int index, int max_items);
void merge_sort(int array[], int lower_index, int higher_index);
bool is_number_palindrome(int number);
int get_max_sum_of_consecutive_numbers(int array[], int number_of_elements, int number_of_consecutive_elements);
std::pair<int, int> two_sum_equals_specific_target(const int* input_numbers, int number_of_elements, int target);
void high_to_low(int input_array[], int lower_index, int higher_index, int smaller_value = 0);
void binary_tree();
int binary_search(int input_array[], int number_to_search, int lower_index, int higher_index);

template<typename DataType>
void reverse_array(const std::array<DataType, 7>& input_array, std::array<DataType, 7>& output_array);

template<typename Data>
void add_reverse_linked_list(const CSingleLinkedList<Data>& first,
														 const CSingleLinkedList<Data>& second,
														 CSingleLinkedList<Data>& output);
void invoke_add_reverse_linked_list();

int search_in_rotated_sorted_array(int input_array[]);

CSingleLinkedList<int> invoke_reverse_linked_list(CSingleLinkedList<int> input_linked_list);

int missing_number();

/*
 */
void median_of_two_sorted_arrays(const std::vector<int>& array_one, const std::vector<int>& array_two);
void invoke_median_of_two_sorted_arrays();

int container_with_most_water(const std::vector<int>& container_height);
void invoke_container_with_most_water();

int sliding_window_max_sum_result(const std::vector<int>& input);
void invoke_sliding_window();

int find_pivot_index(const std::vector<int>& input_array);
void invoke_find_pivot_index();

std::vector<std::vector<int>> find_three_number_sum(std::vector<int>& input_array);
void invoke_find_three_number_sum();

void bubble_sort(std::vector<int> array);

void insertion_sort(std::vector<int>& array);

void missing_numbers(std::vector<int>& array);

// Anagram
bool isMonotonic(std::vector<int> array);
bool is_increasing(std::vector<int> input_array);
bool is_decreasing(std::vector<int> input_array);

void rat_in_a_maze_impl(const std::vector<std::vector<int>>& input, std::vector<std::vector<int>>& output, const std::vector<int>& destination);
void rat_in_a_maze();

#endif /* number_algorithm_hpp */
