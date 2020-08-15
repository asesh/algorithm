//
//  main.cpp
//  consoleApp_1
//
//  Created by Asesh Shrestha on 1/4/20.
//  Copyright © 2020 Asesh Shrestha. All rights reserved.
//

#include <iostream>
#include <filesystem>
#include <array>
#include <regex>
#include <list>
#include <type_traits>
#include <memory>
#include <string_view>
#include <map>
#include <set>

#include "binary_tree.hpp"

#include "linked_list.h"

//void sort_array(std::array<int, 7>& integer_array, int number_of_items);
void binary_tree();

// Recursive implementation for binary search
int binary_search(int input_array[], int number_to_search, int lower_index, int higher_index) {
	// index: 0  1  2  3  4  5   6
	// input: 1, 3, 4, 7, 9, 11, 13
	// search: 13
	if(higher_index >= 1) {
		// Calculate median
		int median = (lower_index + higher_index) / 2;
		
		if(input_array[median] == number_to_search) {
			return median;
		}

		// Search lower bound
		if(input_array[median] > number_to_search) {
			return binary_search(input_array, number_to_search, lower_index, median);
		}
		
		// Search higher bound
		return binary_search(input_array, number_to_search, median + 1, higher_index);
	}
	
	return -1;
}

// Given an array: 1, 2, 3, 4, 5, 6
template<typename DataType>
void reverse_array(const std::array<DataType, 7>& input_array, std::array<DataType, 7>& output_array) {
	output_array = input_array; // Assign the values of input array
//	const size_t array_size = input_array.size();
//	static_assert(array_size % 2 == 0, "The input array must be divisible by 2");
	for(size_t index_count = 0; index_count < input_array.size() / 2; index_count++) {
		output_array[index_count] = input_array[input_array.size() - index_count - 1];
		output_array[input_array.size() - index_count - 1] = input_array[index_count];
	}
}

// Incomplete implementation of sliding window
int get_max_sum_of_consecutive_numbers(int array[], int number_of_elements, int number_of_consecutive_elements) {
	// array: 1, 2, 3, 4, 5, 6
	// number_of_elements: 6
	// number_of_consecutive_elements: 3
	int32_t max_sum_of_consecutive_numbers = 0;
	for(uint8_t counter = 0; counter < number_of_elements - number_of_consecutive_elements + 1; counter++) {
//		std::wcout << counter << std::endl;
		int32_t sum_of_consecutive_numbers = 0;
		for(uint8_t sub_counter = counter; sub_counter < counter + number_of_consecutive_elements; sub_counter++) {
			std::wcout << sub_counter << L": " << array[sub_counter] << L" ";
			sum_of_consecutive_numbers += array[sub_counter];
		}
		std::wcout << std::endl;
		
		max_sum_of_consecutive_numbers = std::max(max_sum_of_consecutive_numbers, sum_of_consecutive_numbers);
	}
	
	return max_sum_of_consecutive_numbers;
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
		for(int index = lower_index; index<= higher_index; index++) {
			// 1: I: 0 LI: 0 HI: 1 = AB
			// 2: I: 1 LI: 0 HI: 1
			std::swap(input_string[index], input_string[lower_index]);
			permutation_of_string(input_string, lower_index + 1, higher_index);
			std::swap(input_string[index], input_string[lower_index]);
		}
	}
}

// The sum of two numbers equals target, return the indices of those two numbers
std::pair<int, int> two_sum_equals_specific_target(const int* input_numbers, int number_of_elements, int target) {
	for(int index = 0; index < number_of_elements; index++) {
		for(int sub_index = index + 1; sub_index < number_of_elements; sub_index++) {
			if(input_numbers[index] + input_numbers[sub_index] == target) {
				return std::make_pair(index, sub_index);
			}
		}
	}
	return std::make_pair(0, 0);
}

// Merge sort
// input_array = {38, 27, 43, 3, 9, 82, 10}
// lower_index = 0 = 12
// higher_index = 4 = 8
/*
 1: 7/2 -> 3
 38 27 43 3 | 9 82 10
 */
void merge_sort_implementation(int input_array[], int lower_index, int median_index, int higher_index) {
}

void merge_sort(int input_array[], int lower_index, int higher_index) {
	if(lower_index < higher_index) {
		int median = (lower_index + higher_index) / 2;
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


// Recursive way to print braces (((( ))))
void recursive_print_braces(int number_of_braces) {
	if(number_of_braces < 1) {
		return;
	} else {
		std::cout<<"(";
		recursive_print_braces(--number_of_braces);
	}
}

int recursiveFun1(int n)
{
	if (n <= 0)
		return 1;
	else
		return 1 + recursiveFun1(n-1);
}

int recursive_sum(int input_number) {
	if(input_number <= 1) {
		return 1;
	} else {
		return input_number + recursive_sum(--input_number);
	}
}

int main(int argc, const char* argv[]) {
//	std::cout<< "The longest is: " << longest_substring_without_repeating_characters("pwwkew") << std::endl;
	
	binary_tree();
	
	
//	std::cout<<recursive_sum(5)<<std::endl;
	
//	recursive_print_braces(5);
	
	//
//	const int input_array[] = {1, 2, 3, 4, 6, 2, 11, 7, 15};
//	auto indices_pair = two_sum_equals_specific_target(input_array, sizeof(input_array)/sizeof(input_array[0]), 9);
//	std::cout<<"First index: " << indices_pair.first << ", 2nd index: " << indices_pair.second << std::endl;
	
	
	// Permutation of string
//	std::string input_string = "ABC";
//	permutation_of_string(input_string, 0, input_string.length() - 1);
	
	
	
	// Merge sort
//	int input_merge_sort_array[] = {38, 27, 43, 3, 9, 82, 10};
//	int number_of_elements = sizeof(input_merge_sort_array) / sizeof(input_merge_sort_array[0]);
//	merge_sort(input_merge_sort_array, 0, number_of_elements / 2);
	
	
	
	
	
	// Sum of consecutive numbers using sliding window technique
//	int array[] = {5, 2, 7, 1, 3, 8};
//	auto max_sum = get_max_sum_of_consecutive_numbers(array, sizeof(array) / sizeof(array[0]), 3);
//	std::wcout << std::endl << "The max sum is: " << max_sum << std::endl;
	
	
	
	
	
	

//	// Swap array items
//	std::array<int, 7> input_array = {1, 2, 3, 4, 5, 6, 7};
//	std::array<int, 7> output_array;
//	reverse_array(input_array, output_array);
//	for(const auto& array_item: output_array) {
//		std::cout<< array_item << std::endl;
//	}
	
	
	// Binary search
//	int number_array[] = {1, 3, 4, 7, 9, 11, 13};
//	int higher_index = (sizeof(number_array) / sizeof(number_array[0])) - 1;
//	auto number_index = binary_search(number_array, 11, 0, higher_index);
//	std::cout << "The index of the number is: " << number_index << std::endl;
	// End of "Invocation of binary_search"
	
	
	
	// Doubly linked list
//	auto doubly_linked_list = std::make_unique<CDoubleLinkedList<int>>(12);
//	doubly_linked_list->add_previous_node(11);
//	doubly_linked_list->add_previous_node(10);
//	doubly_linked_list->add_previous_node(9);
//	doubly_linked_list->add_previous_node(8);
//	doubly_linked_list->add_previous_node(7);
//	doubly_linked_list->add_next_node(13);
//	doubly_linked_list->add_next_node(14);
//	doubly_linked_list->add_next_node(15);
//	doubly_linked_list->add_next_node(16);
//	doubly_linked_list->add_next_node(17);
//	doubly_linked_list->print_all();
	
	
	
	// Single linked list
//	auto single_linked_list = std::make_unique<CSingleLinkedList<int>>();
//	single_linked_list->add_data(2);
//	single_linked_list->add_data(3);
//	single_linked_list->add_data(4);
//
//	single_linked_list->print_all();
//
//	single_linked_list->destroy();
	
	// End of "Single linked list"
	
	
//	std::unique_ptr<CDoubleLinkedList<int>> double_linked_list;
  
//  std::filesystem::path current_path("");
//  auto path_exists = std::filesystem::exists(current_path);
//  std::wcout << path_exists << std::endl;
  
//  std::wcout<< std::filesystem::current_path() << std::endl;
  
//  std::array<uint8_t, 5> binary_tree_items = {1, 2, 3, 4, 5};
//  CBinaryTree<uint8_t, binary_tree_items.size()> binary_tree = {binary_tree_items};
  
//  std::array<int, 7> integer_array = {5, 4, 8, 9, 2, 0, 3};
//  sort_array(integer_array, integer_array.size());
//
//  std::cout << "Partially sorted array: ";
//  for(auto array_item : integer_array) {
//    std::cout<< array_item << " ";
//  }
//
//  return 0;
//}
//
//void sort_array(std::array<int, 7>& integer_array, int number_of_items) {
//  int counter = 0;
//  for(const auto& array_item : integer_array) {
////    std::cout<< array_item << std::endl;
//    if(array_item > integer_array[counter + 1]) {
//      auto value = integer_array[counter + 1];
//      integer_array[counter + 1] = array_item;
//      integer_array[counter] = value;
//    }
//    counter++;
//    if(counter + 1 == integer_array.size()) {
//      break;
//    }
//  }
}

void binary_tree() {
	CBinaryTree<int32_t> binary_tree(1);
	// Fill left-subtree
	binary_tree.m_left_node = new CBinaryTree<int32_t>(2);
	binary_tree.m_left_node->m_left_node = new CBinaryTree<int32_t>(4);
	binary_tree.m_left_node->m_right_node = new CBinaryTree<int32_t>(5);
	binary_tree.m_left_node->m_left_node->m_left_node = new CBinaryTree<int32_t>(8);
	binary_tree.m_left_node->m_left_node->m_right_node = new CBinaryTree<int32_t>(9);
	binary_tree.m_left_node->m_right_node->m_left_node = new CBinaryTree<int32_t>(10);
	binary_tree.m_left_node->m_right_node->m_right_node = new CBinaryTree<int32_t>(11);
	
	// Fill right-subtree
	binary_tree.m_right_node = new CBinaryTree<int32_t>(3);
	binary_tree.m_right_node->m_left_node = new CBinaryTree<int32_t>(6);
	binary_tree.m_right_node->m_right_node = new CBinaryTree<int32_t>(7);
	binary_tree.m_right_node->m_left_node->m_left_node = new CBinaryTree<int32_t>(12);
	binary_tree.m_right_node->m_left_node->m_right_node = new CBinaryTree<int32_t>(13);
	binary_tree.m_right_node->m_right_node->m_left_node = new CBinaryTree<int32_t>(14);
	binary_tree.m_right_node->m_right_node->m_right_node = new CBinaryTree<int32_t>(15);
	binary_tree.m_right_node->m_right_node->m_right_node->m_right_node = new CBinaryTree<int32_t>(16);
	binary_tree.m_right_node->m_right_node->m_right_node->m_right_node->m_left_node = new CBinaryTree<int32_t>(17);
	
	//	binary_tree.traverse_bfs(&binary_tree);
	
	std::cout<<std::endl<<"Height of the tree: "<<binary_tree.get_height(&binary_tree)<<std::endl;
	
	std::cout<<"Traversing in BFS:"<<std::endl;
	binary_tree.traverse_bfs();
	
	std::cout<<std::endl<<"Traversing in pre-order: "<<std::endl;
	binary_tree.traverse_preorder(&binary_tree);
	
	std::cout<<std::endl<<std::endl<<"Traversing in in-order: "<<std::endl;
	binary_tree.traverse_inorder(&binary_tree);
	
	std::cout<<std::endl<<std::endl<<"Traversing in post-order: "<<std::endl;
	binary_tree.traverse_postorder(&binary_tree);
	
	std::cout<<std::endl<<std::endl<<"Removing all the nodes"<<std::endl;
	// Remove the left and right subtrees
	binary_tree.remove_subtree(binary_tree.m_left_node);
	binary_tree.remove_subtree(binary_tree.m_right_node);
	
	std::cout<<std::endl;
}
