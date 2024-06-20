//
//  number_algorithm.cpp
//  algorithm
//
//  Created by Asesh Shrestha on 09/09/2021.
//  Copyright © 2021 Asesh Shrestha. All rights reserved.
//

#include "header.h"
#include "linked_list.h"
#include "number.hpp"

// Ref 1: Print the reverse of an array by using recursion
void print_reverse(int input_array[], int index, int max_items) {
	if(index > max_items - 1) {
		return;
	}
	
	print_reverse(input_array, ++index, max_items);
	std::cout<<input_array[--index] << " ";
}


/*
 Ref 2: Merge sort implementation
 5 | 4 | 2 | 7 | 6 | 1 => (0, 2) => (0, 1) => (0, 0) 1st half
 5 | 4   2 | 7   6 | 1 => (3, 5) => (3, 4) => (3, 3) 2nd half
 4 | 5   2 | 7   1 | 6
 2 | 4 | 5 | 7   1 | 6
=> 1 | 2 | 4 | 5 | 6 | 7
 
1 2 3 4
(0, 3)
  -> (0, *1)
    -> (0, *0)
    -> (1, 3)
  ->
*/
void merge_sort(std::array<int, 6> input_array, int lower_index, int higher_index) {
	// Base case
	if(higher_index > input_array.size() - 1 || lower_index == higher_index || lower_index > higher_index) {
		return;
	}
	
	int median = (lower_index + higher_index) / 2;
	merge_sort(input_array, lower_index, median);
  merge_sort(input_array, median + 1, higher_index);
  std::cout<<"Lower index: "<<lower_index<<", median: "<<median<<", higher_index: "<<higher_index<<std::endl;
//	std::cout<< "Median: "<<median<<", value: "<<input_array[median] << std::endl;
}

/*
 Check if the input number is palindrome or not
 input: 121
 */
bool is_number_palindrome(int number) {
	if(number < 0) {
		return false;
	}
	
	int reverse_number = 0;
	
	int assigned_number = number;
	
	while(assigned_number != 0) {
		auto last_number = assigned_number % 10; // 1 -> 2 -> 1
		assigned_number /= 10; // 12 -> 1 -> 0
		
		if(reverse_number > assigned_number) {
			assigned_number = (assigned_number * 10) + last_number;
			break;
		}
		
		reverse_number = (reverse_number * 10) + last_number; // 1 -> 12
	}
	
	return reverse_number == assigned_number;
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

/*
 I N S E R T I O N S O R T
 */

/*
 1 2 3 4 5 6
 6 5 -> 4 3 -> 2 1
 5 -> 3 -> 1
 3 -> 1
 1
 
 2 3 5 1 4 6
 6 4 -> 5 1 -> 3 2
 4 -> 1 -> 2
 1 -> 2
 1
 */
void high_to_low(int input_array[], int lower_index, int higher_index, int smaller_value) {
	if(lower_index >= 0 && lower_index < higher_index) {
		smaller_value = input_array[lower_index] < input_array[higher_index] ? input_array[lower_index] : input_array[higher_index]; // Assign smaller value between the tow
		high_to_low(input_array, lower_index - 2, higher_index - 2, smaller_value);
		std::cout<<"Smaller value: "<<smaller_value<<std::endl;
	}
}

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

/*
 2: Add Two Numbers: https://leetcode.com/problems/add-two-numbers/
 
 Problem:
 2 -> 4 -> 3
 5 -> 6 -> 4
 output: 807
 */
template<typename Data>
void add_reverse_linked_list(const CSingleLinkedList<Data>& first,
														 const CSingleLinkedList<Data>& second,
														 CSingleLinkedList<Data>& output) {
}

void invoke_add_reverse_linked_list() {
	CSingleLinkedList<int> output;
	CSingleLinkedList<int> first;
	first.add_node(2);
	first.add_node(4);
	first.add_node(3);
	CSingleLinkedList<int> second;
	second.add_node(5);
	second.add_node(6);
	second.add_node(4);
	add_reverse_linked_list(first, second, output);
	first.clear_nodes();
	second.clear_nodes();
}

int search_in_rotated_sorted_array(int input_array[]) {
	// array = [0, 1, 2, 4, 5, 6, 7]
	// array = [4, 5, 6, 7, 0, 1, 2]
	return -1;
}

CSingleLinkedList<int> invoke_reverse_linked_list(CSingleLinkedList<int> input_linked_list) {
	CSingleLinkedList<int> reverse_linked_list;
	return reverse_linked_list;
}

/*
 268. Missing Number
 input: [3, 0, 1]
 
 i	v
 3	0 -> 3
 0	3 -> 3
 1	3 -> 01 11 -> 10 = 2
 */
int missing_number() {
	std::vector<int> input_array{9,6,4,2,3,5,7,0,1};
	int missing_number = 0;
	
	for(int index = 0; index <= input_array.size(); index++) {
		missing_number += index;
	}

	return missing_number - std::accumulate(input_array.begin(), input_array.end(), 0);
}

/*
 https://leetcode.com/problems/median-of-two-sorted-arrays/
 Input: nums1 = [1,3], nums2 = [2]
 Output: 2.00000
 */
void median_of_two_sorted_arrays(const std::vector<int>& array_one, const std::vector<int>& array_two) {
	auto array_one_count = array_one.size();
	auto array_two_count = array_two.size();
	
	// Assign an array with the max number of items
	auto max_array = array_one_count >= array_two_count ? array_one : array_two;
	
	std::vector<int> total(max_array.size());
	
	// Iterate through all the elements of the max array
	/*
	 1, 2 -> 3, 4
	 */
	for(int index = 0; index < max_array.size(); index++) {
		
	}
}

void invoke_median_of_two_sorted_arrays() {
	std::vector<int> input_one{1, 3}, input_two{2};
	median_of_two_sorted_arrays(input_one, input_two);
}

/*
 11. Container With Most Water
 https://leetcode.com/problems/container-with-most-water/
 */
int container_with_most_water(const std::vector<int>& container_height) {
	int max_amount_of_water = 0;
	
	for(const auto& height: container_height) {
		
	}
	
	return 0;
}
void invoke_container_with_most_water() {
	std::vector<int> container_height{1,8,6,2,5,4,8,3,7};
	std::cout << "Max amount of water: " << container_with_most_water(container_height) << std::endl;
}

int sliding_window_max_sum_result(const std::vector<int>& input, int sequence_count) {
	if(input.size() <= 0 || input.size() < sequence_count) {
		return 0;
	}
	int max = 0;
	int window_sum = 0;
	
	// Sum 0-(k-1) elements
	for(int index = 0; index < sequence_count; index++) {
		max += input[index];
	}
	
	window_sum = max;
	
	/*
	 1, 4, 2, 10, 2, 3, 1, 0, 20
	 -----------
		max = 17
			-----------
				-------------
										----------
	 */
	// Loop through the k + remaining elements
	for(int index = sequence_count; index < input.size(); index++) {
		window_sum = ((window_sum + input[index]) - input[index - sequence_count]);
		max = std::max(max, window_sum);
	}
	
	return max;
}
void invoke_sliding_window() {
	std::vector<int> input_vector { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
	std::cout<< sliding_window_max_sum_result(input_vector, 4);
}

/*
 724. Find Pivot Index
 https://leetcode.com/problems/find-pivot-index/
 */
int find_pivot_index(const std::vector<int>& input_array) {
	int sum = 0;
	int total_sum = std::accumulate(input_array.begin(), input_array.end(), 0);
	/*
	 ----- 28 - 11 - 6
	 1,7,3,6,5,6
	 Sum: 28
	 */
	for(int index = 0; index < input_array.size(); index++) {
		sum += input_array[index];
		
		if(total_sum - sum == sum - input_array[index]) {
			return index;
		}
	}
	
	return -1;
}
void invoke_find_pivot_index() {
	std::vector<int> array{1,2,3};
	std::cout<<"Pivot index: " << find_pivot_index(array) << std::endl;
}

/*
 Three number sum
 https://www.algoexpert.io/questions/Three%20Number%20Sum
 */
std::vector<std::vector<int>> find_three_number_sum(std::vector<int>& input_array) {
	// O(nlogn)
	std::sort(input_array.begin(), input_array.end());
	
	for(const auto& number: input_array) {
		std::cout<<number<<std::endl;
	}
	
	/*
	 Implementation:
	 Input: 	12, 3, 1, 2, -6, 5, -8, 6
	 Target: 	0
	 Sort:
			Data: -8 -6 1 2 3 5 6 12
			Time: O(nlogn)
	 
	 // Found triplets:
	 1: -8+2+6
	 */
	
	return {};
}
void invoke_find_three_number_sum() {
	std::vector<int> input{12, 3, 1, 2, -6, 5, -8, 6};
	auto triplets = find_three_number_sum(input);
}

void bubble_sort(std::vector<int> array) {
	/*
	 {5 1 4 2 8}
	 index: 		0 1 2 3 4
	 subindex:	0
	 */
	for(int index = 0; index < array.size() - 1; ++index) {
		for(int sub_index = index; sub_index < array.size() - index - 1; ++sub_index) {
			std::cout<<array[sub_index]<<", ";
		}
	}
}

/*
 11 12 13 5 6
 11 12 5  13
 11 5  12 13 6
 5  11 12 13 6
 5  11 12 6 13
 5  11 6 12 13
 5  6  11 12 13
 */
void insertion_sort(std::vector<int>& array) {
	if(array.size() <= 1) {
		return;
	}
	
	for(int current_index = 0; current_index < array.size() - 1; ++current_index) {
		if(array[current_index] > array[current_index + 1]) {
			std::swap(array[current_index], array[current_index + 1]);
		}
		
		int reversal_index = current_index;
		while(reversal_index > 0 && array[reversal_index] < array[reversal_index - 1]) {
			std::swap(array[reversal_index], array[reversal_index - 1]);
			reversal_index--;
		}
	}
}

// https://www.algoexpert.io/questions/missingNumbers
/*
Test case 14:
  Input: 1 2 4 5 7
  Add:   1 2 4 5 7 Max Max
  Index: 0 1 2 3 4  5  6
  Neg:   X X | X X  |  X
  Output: 3 6
*/
std::vector<int> missingNumbers(std::vector<int> nums) {
  nums.push_back(INT_MAX);
  nums.push_back(INT_MAX);
  for(int index = 0; index < nums.size() - 2; ++index) {

    int value = nums[index];
    std::cout<<"Value: "<<value<<", nums: "<<nums[value - 1]<<", index: "<<index<<std::endl;
    nums[value - 1] *= -1;
  }

  std::vector<int> output;
  for(int index = 0; index < nums.size(); ++index) {
    if(nums[index] > 0) {
      output.push_back(index + 1);
    }
  }
  return output;
}

// Anagram
//
bool is_increasing(std::vector<int> input_array) {
  for(int index = 0; index < input_array.size() - 1; index++) {
    if(input_array[index] > input_array[index + 1]) {
      return false;
    }
  }
  return true;
}

bool is_decreasing(std::vector<int> input_array) {
  for(int index = 0; index < input_array.size() - 1; index++) {
    if(input_array[index] < input_array[index + 1]) {
      return false;
    }
  }
  return true;
}

bool isMonotonic(std::vector<int> array) {
  /*
   -1 -5 -10 -1100 -1100 -1101 -1102 -9001
   
   1 2 3 4 5 -> Diff > 0
   
   1 2 4 7 9
   Sum: 23
   I: 1: 23-1 = 22
   I: 2: 23-2 = 21
   I: 4: 23-4 = 19
   I: 7: 23-7 = 16
   I: 9: 23-9 = 14
   
   1 2 4 5 9
   
   -1 -2 -3 -4 -> Diff < 0
   */
  
  return is_increasing(array) || is_decreasing(array);
}

//
// Anagram

void rat_in_a_maze_impl(const std::vector<std::vector<int>>& input, std::vector<std::vector<int>>& output, const std::vector<int>& destination) {
  
}

void rat_in_a_maze() {
  std::vector<std::vector<int>> output;
  std::vector<std::vector<int>> input {
    {1, 1, 1, 1},
    {0, 1, 0, 1},
    {0, 1, 0, 0},
    {1, 1, 1, 1}
  };
  rat_in_a_maze_impl(input, output, {3, 3});
}

int calculate_minimum_coins(int target, const std::vector<int>& denoms, int coins_needed, std::unordered_map<int, int>& computed_targets) {
  if(target < 0) {
    return INT_MAX;
  }
  
  if(computed_targets.contains(target) && computed_targets.at(target) <= coins_needed) {
    std::cout<<"Using pre-computed data: "<<target<<" : "<<computed_targets[target]<<std::endl;
    return computed_targets[target];
  }

  if(target == 0) {
    std::cout<<"Coins needed: "<<coins_needed<<std::endl;
    return coins_needed;
  }
  
  coins_needed++;

  int minimum_coins = INT_MAX;
  for(const auto& denom: denoms) {
//    std::cout<<"Target "<<target<<" - "<<"Denom "<<denom<<" = "<<(target - denom)<<std::endl;
    int possible_min_coins = calculate_minimum_coins(target - denom, denoms, coins_needed, computed_targets);
    minimum_coins = std::min(minimum_coins, possible_min_coins);
  }
  
  computed_targets[target] = minimum_coins;
  std::cout<<"Target key: "<<target<<"-> value: "<<minimum_coins<<std::endl;
  
  return minimum_coins;
}

void invoke_calculate_minimum_coins() {
  std::unordered_map<int, int> computed_targets;
  int minimum_coins = calculate_minimum_coins(11, {1, 2, 5}, 0, computed_targets);
  std::cout<<"Min. coins needed: "<<minimum_coins<<std::endl;
}

int calculate_four_number_sum(int target, const std::vector<int>& array, int sum) {
  if(sum > target) {
    return INT_MAX;
  }
  
  int calculated_sum = 0;
  for(const auto& current_number: array) {
    
  }
  
  return INT_MAX;
}

void invoke_calculate_four_number_sum() {
  std::vector<int> array = {7, 6, 4, -1, 1, 2};
  calculate_four_number_sum(16, array, 0);
}

// Using top-down DP
void calculate_total_number_of_steps(int number_of_steps, int& total_number_of_steps, std::unordered_map<int, int>& computed_values) {
  static std::vector<int> steps = {1, 2};
  
  if(number_of_steps < 0) {
    return;
  }
  if(computed_values.contains(number_of_steps)) {
//    std::cout<<"Returning cached number of steps: "<<number_of_steps<<std::endl;
    total_number_of_steps += computed_values.at(number_of_steps);
    return;
  }
  
  if(number_of_steps == 0) {
//    std::cout<<"Number of steps is 0 when : "<<number_of_steps<<std::endl;
    total_number_of_steps++;
    return;
  }
  
  for(const auto& step: steps) {
    calculate_total_number_of_steps(number_of_steps - step, total_number_of_steps, computed_values);
  }
  
//  std::cout<<"Storing Key: "<<number_of_steps<<", value: "<<total_number_of_steps<<std::endl;
  computed_values[number_of_steps] = total_number_of_steps;
}

void invoke_calculate_total_number_of_steps() {
  int total_number_of_steps = 0;
  std::unordered_map<int, int> computed_values;
  calculate_total_number_of_steps(4, total_number_of_steps, computed_values);
  std::cout<<std::endl<<"Number of steps that can be taken: "<<total_number_of_steps<<std::endl;
}

// https://leetcode.com/problems/climbing-stairs/description/
// Using bottom-up DP
int get_total_number_of_steps(int total_steps) {
  int previous = 1, next = 1;
  int sum = 0;
  total_steps -= 2;
  while(total_steps >= 0) {
    --total_steps;
    
    sum = previous + next;
    previous = next;
    next = sum;
  }
  
  return sum;
}

int calculate_minimum_number_of_steps(int destination_steps, int total_steps = 0) {
  static std::vector<int> steps = {1, 2};
  if(destination_steps < 0) {
    return INT_MAX;
  }
  
  if(destination_steps == 0) {
    return total_steps;
  }

  ++total_steps;
  
  int min_steps = INT_MAX;
  for(const auto& step: steps) {
    int total_possible_steps = calculate_minimum_number_of_steps(destination_steps - step, total_steps);
    min_steps = std::min(min_steps, total_possible_steps);
  }
  
  return min_steps;
}

void invoke_calculate_minimum_number_of_steps() {
  std::cout<<"Minimum number of steps: "<<calculate_minimum_number_of_steps(25)<<std::endl;
}

// https://www.algoexpert.io/questions/number-of-ways-to-traverse-graph
int number_of_ways_to_traverse_graph(int total_width, int total_height) {
  std::vector<int> computed_cells(total_width + 1, 1); // = {1, 1, 1, 1, 0};
  computed_cells[total_width] = 0;
  
  for(int current_row = total_height - 2; current_row >= 0; --current_row) {
    std::vector<int> new_row(total_width + 1, 0);
    for(int current_column = total_width - 1; current_column >= 0; --current_column) {
      new_row[current_column] = new_row[current_column + 1] + computed_cells[current_column];
    }
    
    computed_cells = new_row;
  }
  
  return computed_cells[0];
}

void invoke_number_of_ways_to_traverse_graph() {
  std::cout<<"Number of ways to traverse graph: "<<number_of_ways_to_traverse_graph(4, 3);
}

void river_size_dfs(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& visited, int& river_size, int row, int column) {
  auto column_size = matrix[0].size();
  auto row_size = matrix.size();
  if(row >= 0 && row < row_size && column >= 0 && column < column_size && matrix[row][column] == 1 &&
    !visited[row][column]) {
    ++river_size;
    visited[row][column] = true;
    river_size_dfs(matrix, visited, river_size, row, column - 1); // Move left
    river_size_dfs(matrix, visited, river_size, row - 1, column); // Move to top
    river_size_dfs(matrix, visited, river_size, row, column + 1); // Move to right
    river_size_dfs(matrix, visited, river_size,  row + 1, column); // Move to bottom
  }
}

// Time: O(wh), Space: O(wh)
void invoke_river_size() {
  std::vector<int> output;
  
  std::vector<std::vector<int>> matrix = {
    {1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0}
  };

  // Space: O(wh)
  std::vector<std::vector<int>> visited(matrix.size(), std::vector<int>(matrix[0].size(), false));

  // Time: O(wh)
  for(int row = 0; row < matrix.size(); ++row) {
    for(int column = 0; column < matrix[0].size(); ++column) {

      if(matrix[row][column] == 1 && !visited[row][column]) {
        int river_size = 0;
        river_size_dfs(matrix, visited, river_size, row, column);
        output.push_back(river_size);
      }
    }
  }
  
  std::cout<<"The river sizes are: ";
  for(const auto& size: output) {
    std::cout<<size<<", ";
  }
}

void invoke_valid_starting_city() {
  
}

// https://www.algoexpert.io/questions/valid-starting-city
int valid_starting_city(std::vector<int> distances, std::vector<int> fuel, int mpg) {
  int output_index = 0;
  int min_distance_covered = 0;
  int last_distance_covered = 0;
  for(int index = 1; index < distances.size(); ++index) {
    // Distance covered from the previous city to the current one
    int distance_covered = ((fuel[index - 1] * mpg) + last_distance_covered) - distances[index - 1]; // 5
    if(distance_covered < min_distance_covered) {
      min_distance_covered = distance_covered;
      output_index = index;
    }
    last_distance_covered = distance_covered;
  }
  return output_index;
}

// https://leetcode.com/problems/valid-palindrome-ii/
bool valid_palindrome_2(std::string& input_string) {
  int correction_counter = 0;
  for(int current_index = 0, last_index = input_string.size() - 1;
      current_index < input_string.size() / 2 && current_index < last_index;
      ++current_index, --last_index) {
    if(input_string[current_index] == input_string[last_index]) {
      continue;
    }
    
    if(correction_counter >= 1) {
      return false;
    }
    
    // Discard the current index or last index
    if(input_string[current_index + 1] == input_string[last_index]) {
      ++correction_counter;
      current_index++;
      continue;
    } else if(input_string[current_index] == input_string[last_index - 1]) {
      ++correction_counter;
      last_index--;
      continue;
    }
    
    return false;
  }
  return true;
}

void invoke_valid_palindrome_2() {
  std::string input_string = "caba"; // abac
  std::cout<<std::boolalpha<<valid_palindrome_2(input_string);
}

/* https://leetcode.com/discuss/interview-question/5091692/FacebookMeta-MLSWE-Phone-Screenor-Pass-or-TLV-or-Random-pick-with-weight
 Example 1:
 strawberries: [1, 2, 3]
 n: 1
 Result: true because 1+2 | 3
 
 Example 2:
 strawberries: [1, 2, 3]
 n: 2
 Result: false
 */
void cut_cake_make_strawberries(std::vector<int> starwberries, int number_of_cuts) {
}

/*

Input: [1, 3, 4, 5, 0]
Insert: 2
Index: 1

 temp: 3
        *
 [1, 2, 4, 5, 0]
*/
void insert_and_shift_numbers(std::vector<int>& array, int insert_index, int number) {
  for(int index = 0; index < array.size(); ++index) {
    if(index == insert_index) {
      auto temp = array[index];
      array[index++] = number;
      while(index < array.size()) {
        std::swap(temp, array[index++]);
      }
    }
  }
}
void invoke_insert_and_shift_numbers() {
  std::vector<int> input_array = {1, 3, 4, 5, 0};
  insert_and_shift_numbers(input_array, 1, 2);
  
  for(auto& num: input_array) {
    std::cout<<num<<", ";
  }
}

/*
            F
1, 2, 2, 3, 0, 0
   S
2, 5, 6
*/
void merge_sorted_arrays(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
  for(int second = 0, first = m; second < n; ++first, ++second) {
      nums1[first] = nums2[second];
  }
  std::sort(nums1.begin(), nums1.end());
}
void invoke_merge_sorted_arrays() {
  std::vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
  merge_sorted_arrays(nums1, 3, nums2, 3);
  
  for(auto& num: nums1) {
    std::cout<<num<<", ";
  }
}

int remove_element(std::vector<int>& array, int target) {
  int counter = 0;
  for(int index = 0; index < array.size(); ++index) {
      if(array[index] == target) {
        array[index] = -1;
      }
  }
  std::sort(array.begin(), array.end(), [](int val1, int val2) {
      return val2 < val1;
  });
  while(counter < array.size() && array[counter] != -1) {
      ++counter;
  }
  return counter;
}
void invoke_remove_element() {
  std::vector<int> array = {3,2,2,3};
  auto num_not_equal_val = remove_element(array, 3);
  std::cout<<num_not_equal_val<<std::endl;
  for(auto& num: array) {
    std::cout<<num<<", ";
  }
}

int remove_duplicates_from_sorted_array(std::vector<int>& nums) {
  int unique_elements = 1;
  for(int index = 1; index < nums.size(); ++index) {
      if(nums[index] != nums[index -1]) {
          nums[unique_elements] = nums[index];
          ++unique_elements;
      }
  }

  return unique_elements;
}
void invoke_remove_duplicates_from_sorted_array() {
  std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
  auto num = remove_duplicates_from_sorted_array(nums);
  std::cout<<num<<std::endl;
  for(auto& num: nums) {
    std::cout<<num<<", ";
  }
}

/*

    I
1 1 1 2 2 3
      *
*/
int remove_duplicates_more_than_two(std::vector<int>& nums) {
  int index = 0;
  for(auto& num: nums) {
    if(index == 0 || index == 1 || nums[index - 2] != num) {
      nums[index] = num;
      ++index;
    }
  }

  return index;
}
void invoke_remove_duplicates_more_than_two() {
  std::vector<int> nums = {0,0,1,1,1,1,2,3,3};
  auto answer = remove_duplicates_more_than_two(nums);
  std::cout<<answer<<std::endl;
  for(auto& num: nums) {
    std::cout<<num<<", ";
  }
}

/*
Input: [1, -100, 12, 4, 20, 5, 60, -5, -7] Target: 5
Output: [1, 4, 5, -5], [12, 5, -5, -7]
 *            *      *      *                      *         *       *   *
[1, -100, 12, 4, 20, 5, 60, -5, -7] and [1, -100, 12, 4, 20, 5, 60, -5, -7]
*/
std::vector<std::vector<int>> four_number_sum(std::vector<int>& nums) {
  std::vector<std::vector<int>> output;
  return output;
}
void invoke_four_number_sum() {
  std::vector<int> nums = {1, -100, 12, 4, 20, 5, 60, -5, -7};
  auto output = four_number_sum(nums);
  for(auto& nums_array: output) {
    for(auto& num: nums_array) {
      std::cout<<num<<", ";
    }
    std::cout<<std::endl;
  }
}

void rotate_array(std::vector<int> nums, int k) {
  k = k % nums.size();
  std::reverse(nums.begin(), nums.end()); // Reverse the entire array
  std::reverse(nums.begin(), nums.begin() + k); // Reverse the first k elements
  std::reverse(nums.begin() + k, nums.end()); // Reverse the k+ elements
}
void invoke_rotate_array() {
  std::vector<int> nums = {1,2,3,4,5,6,7};
  rotate_array(nums, 3);
  for(auto& num: nums) {
    std::cout<<num<<", ";
  }
}

/*
123
3*100 + 2*10 + 1*1 = 300+20+1 = 321
 
1234
4*1000 + 3*100 + 2*10 + 1 = 4321
*/
int reverse_integer(int input) {
  int output = 0;
  do {
    auto last_number = input % 10; // 3
    input /= 10;
    output = (output * 10) + last_number;
  } while(input != 0);
  return output;
}
void invoke_reverse_integer() {
  std::cout<<reverse_integer(-123);
}
