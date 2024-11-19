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
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
 
Input: [1,2,4,4,2,2,2]
Output: 10
|     | |
|     | |
|   | | | | | |
| | | | | | | |
-----------------
     2 2 2 2 2
 
Input: [8,7,2,1]
Output: 7
| |
| | |
| | |
| | |
| | |
| | |
| | | |
| | | | |
------------------------
*/
int container_with_most_water(const std::vector<int>& input) {
	int output = 0;
  
  int left = 0, right = input.size() - 1;
  while(left < right) {
    auto current_amount = (right - left) * std::min(input[left], input[right]);
    output = std::max(output, current_amount);
    if(input[left] > input[right]) {
      --right;
    } else {
      ++left;
    }
  }
	
	return output;
}
void invoke_container_with_most_water() {
//	std::vector<int> container_height{1,8,6,2,5,4,8,3,7};
  std::vector<int> container_height{8,7,2,1};
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
Input: [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
 
Process:
 sort: [-4,-1,-1,0,1,2]
      C  L     R
 [-4,-1,-1,0,1,2] =
         C L   R
 [-4,-1,-1,0,1,2] =
*/
std::vector<std::vector<int>> find_three_number_sum(std::vector<int>& input_array) {
  std::vector<std::vector<int>> output;
  std::set<std::vector<int>> unique_output;
	// O(nlogn)
	std::sort(input_array.begin(), input_array.end());
  
  // O(n^2)
  for(int current_index = 0; current_index < input_array.size() - 2; ++current_index) {
    int right_index = input_array.size() - 1;
    for(int left_index = current_index + 1; left_index < input_array.size() && left_index != right_index;) {
      auto sum = input_array[current_index] + input_array[left_index] + input_array[right_index];
      if(sum == 0) {
        unique_output.insert({input_array[current_index], input_array[left_index], input_array[right_index]});
        ++left_index;
      } else if(sum > 0) {
        --right_index;
      } else {
        ++left_index;
      }
    }
  }
  
  for(auto& item: unique_output) {
    output.push_back(item);
  }
	
	return output;
}
void invoke_find_three_number_sum() {
	std::vector<int> input{-1,0,1,2,-1,-4};
	auto triplets = find_three_number_sum(input);
  std::cout<<"The triplets are: "<<std::endl;
  std::for_each(triplets.begin(), triplets.end(), [](std::vector<int>& triplet) {
    std::cout<<triplet[0]<<", "<<triplet[1]<<", "<<triplet[2]<<std::endl;
  });
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
  int reverse_number = 0;

  int carry = 0;
  int number = input;

  do {
    // Input: 123
    auto last_number = number % 10;                      //  3 ->  2 -> 1
    number /= 10;                                        // 12 ->  1 -> 0
    
    if (reverse_number > INT_MAX/10 ||
      (reverse_number == INT_MAX / 10 && last_number > 7))
      return 0;
    if (reverse_number < INT_MIN/10 ||
      (reverse_number == INT_MIN / 10 && last_number < -8))
      return 0;
    
    reverse_number = reverse_number * 10 + last_number;  //  3 -> 32 -> 321
  } while(number != 0);

  return reverse_number;
}
void invoke_reverse_integer() {
  std::cout<<reverse_integer(-123);
}

/*
Input: nums1: [1,3], nums2: [2] => Output: 2.0
 
Input: nums1: [1,2], nums2: [3,4] => Output: 2.50000
 
Input: nums1: [1,3,4,5], nums: [2,3,6,7] => Output: 3.50000
Process:
 Total elements: 8 -> even
 mid_index = ((8/2)-1) => [3+1]/2 = 7/2 = 3.5
 
nums1: [4,5,6,7], nums2: [0,1,2,3]
*/
double median_of_two_sorted_arrays(std::vector<int>& nums1, std::vector<int>& nums2) {
  double output = 0.0;
  return output;
}
void invoke_median_of_two_sorted_arrays() {
  std::vector<int> nums1 = {1,2}, nums2 = {3,4};
  std::cout<<"The median of two sorted array is: "<<median_of_two_sorted_arrays(nums1, nums2);
}

/*
prices = [7,1,5,3,6,4]; Output = 5-1 + 6-3 => 7
prices = [1,2,3,4,5]; Output = 5-1 => 4
prices = [7,6,4,3,1]; Output = 0
*/
int best_time_to_buy_and_sell_stock_ii(std::vector<int>& prices) {
  int output = 0;
  for(int index = 1; index < prices.size(); ++index) {
    auto diff = prices[index] - prices[index - 1];
    if(diff > 0) {
      output += diff;
      continue;
    }
  }
  return output;
}
void invoke_best_time_to_buy_and_sell_stock_ii() {
  std::vector<int> prices = {7,1,5,3,6,4};
  std::cout<<"Max profit: "<<best_time_to_buy_and_sell_stock_ii(prices);
}

/*
nums: [3,2,1,0,4] => false
 
nums: [2,3,1,1,4] => true
0 1 2 3 4
2 3 1 1 4 => 1 1$; 2 1 1$
 
nums: [6,5,5,7,4] => true
 
nums: [1 1 1 1 1]
*/
bool jump_game(std::vector<int>& nums) {
  int last_index = nums.size() - 1;
  for(int index = nums.size() - 2; index >= 0; --index) {
    if(index + nums[index] >= last_index) {
      last_index = index;
    }
  }

  return last_index <= 0;
}
void invoke_jump_game() {
  std::vector<int> nums = {2,3,1,1,4};
  std::cout<<std::boolalpha<<jump_game(nums);
}

/*
 1 3     *
[2,3,1,1,4] => 2
 
 0 1 2 3 4 5 6
[2,3,1,2,1,1,4] => 4
 
[1,1,1] => 2

[1,2,1,1] => 2
 
[1,1,1,1,2,4] = 5
 
 * *   * *
[1,2,4,1,5] = 3
 
 0 1 2 3 4 5 6 7
[2,3,1,4,1,1,1,2]
 
[2,3,0,1,4] = 2
Process:
 0 1 2 3 4
 2,3,0,1,4
 
 0 1 2 3 4
[1,2,4,1,5] = 3
 
*/
int jump_game_ii(std::vector<int>& input) {
  int steps = 0, end = 0;
  int max_steps = 0;
  
  // O(n)
  int current_index = 0;
  while(current_index < input.size() - 1) {
    max_steps = std::max(max_steps, current_index + input[current_index]); // 2, 3, 4
    if(max_steps >= input.size() - 1) {
      ++steps;
      break;
    }
    
    if(current_index == end) { // 0 == 0, 1 == 2,
      ++steps; // 1,
      end = max_steps; // 2,
    }
    
    ++current_index; // 0,1,2,3,4,5
  }
  
  return steps;
}
void invoke_jump_game_ii() {
  std::vector<int> nums = {2,2,0,1,4};
  std::cout<<"The minimum number of jumps to reach the end is: "<<jump_game_ii(nums)<<std::endl;
}

/*
Hashmap:
1: I
5: V
10: X
50: L
100: C
500: D
1000: M
 
3749 => MMMDCCXLIX
3000: MMM: 1000 + 1000 + 1000
700:  DCC: 500 + 100 + 100
40:   XL:  50 - 10
9:    IX:  10 - 1
 
3749 % 10 = 9 = IX
3749 % 10 = 374 => 374 % 10 = 4 * 10 = 40 = XL
37   % 10 = 7   => 7 * 100 = 700 = DCC
3    % 10 = 3   => 3 * 1000 = 3000 = MMM
*/
std::string integer_to_roman(int number) {
  std::string output;
  
  std::vector<std::string> symbol = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
  std::vector<int> symbol_value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  
  for(int index = 0; number != 0; ++index) {
    while(number >= symbol_value[index]) {
      number -= symbol_value[index];
      output += symbol[index];
    }
  }
  
  return output;
  
//  static std::unordered_map<int, std::string_view> roman_map = {
//    {1, "I"},
//    {5, "V"},
//    {9,  "IX"},
//    {10, "X"},
//    {40, "XL"},
//    {50, "L"},
//    {100, "C"},
//    {500, "D"},
//    {700, "DCC"},
//    {1000, "M"},
//    {3000, "MMM"},
//  };
//
//  std::vector<std::string_view> temp_output;
//  
//  int multiplicant = 0;
//  
//  do {
//    auto last_number = number % 10;
//    number /= 10;
//    
//    multiplicant *= 10;
//    if(multiplicant == 0) {
//      multiplicant = 1;
//    }
//    
//    std::cout<<last_number * multiplicant<<" => "<<roman_map[last_number * multiplicant]<<std::endl;
//    temp_output.push_back(roman_map[last_number * multiplicant]);
//    
//  } while(number != 0);
//
//  for(int index = temp_output.size() - 1; index >= 0; --index) {
//    output.append(temp_output[index]);
//  }
//  return output;
}
void invoke_integer_to_roman() {
  std::cout<<integer_to_roman(3749)<<std::endl;
}

/*
Input: [1,2,3,4] Output: [24,12,8,6]
LP: [1,   1, 2, 6]
RP: [24, 12, 4, 1]
Op: [24, 12, 8, 6]
 
Prefix product array: [1, 2*1, 3*2*1, 4*3*2*1] = [1,  2,  6,  24]
Suffix product array: [1*2*3*4, 2*3*4, 3*4, 4] = [24, 24, 12, 4]

-1,1,0,-3,3 = [0,0,9,0,0]
*/
std::vector<int> product_of_array_except_itself(std::vector<int>& input) {
  int size = input.size();
  std::vector<int> output(size);
  std::vector<int> left_product(size), right_product(size);
  left_product[0] = 1; right_product[size - 1] = 1;
  for(int index = 1; index < size;  ++index) {
    left_product[index] = left_product[index - 1] * input[index - 1];
  }
  for(int index = size - 2; index >= 0; --index) {
    right_product[index] = right_product[index + 1] * input[index + 1];
  }
  for(int index = 0; index < size; ++index) {
    output[index] = left_product[index] * right_product[index];
  }
  return output;
}
void invoke_product_of_array_except_itself() {
  std::vector<int> input = {1,2,3,4};
  auto output = product_of_array_except_itself(input);
  std::for_each(output.begin(), output.end(), [](const auto& value) {
    std::cout<<value<<", ";
  });
}

/*
Input: [3,2,1,5,6,4], k: 2, Output: 5
Using priority queue:
pq: [1,2,3,4,5,6]
*/
int kth_largest_element_in_an_array(std::vector<int>& nums, int k) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> priority_queue;
  for(auto& num: nums) {
    priority_queue.push(num);
    if(priority_queue.size() > k) {
      priority_queue.pop();
    }
  }

  return priority_queue.top();
}
void invoke_kth_largest_element_in_an_array() {
  std::vector<int> nums = {3,2,1,5,6,4};
  std::cout<<kth_largest_element_in_an_array(nums, 2)<<std::endl;
}

/*
LeetCode
Input: PAYPALISHIRING
Process:
0 1 2 3 4 5 6 7 8 9 0 1 2 3
P A Y P A L I S H I R I N G

Rows: 3
* 0 1 2 3 4 5 6
0 P   A   H   N
1 A P L S I I G
2 Y   I   R
Output: PAHNAPLSIIGYIR

Ex. 2: Rows: 4
* 0 1 2 3 4 5 6
0 P     I     N
1 A   L S   I G
2 Y A   H R
3 P     I
Output: PINALSIGYAHRPI
 
Custom, Rows: 2
* 0 1 2 3 4 5 6
0 P Y A I H R N
1 A P L S I I G
Output: PYAIHRNAPLSIIG
 
Rows / 2 = X => number of diagonal columns
 
*/
std::string zig_zag_conversion_lc(std::string input, int rows) {
  std::string output;
  std::vector<std::vector<char>> data(rows);
  
  if(rows <= 1) {
    return input;
  }
  
  // SC O(n)
  output.reserve(input.size());
  
  int index = 0, direction = 1;
  
  // RC O(n)
  for(auto& character: input) {
    data[index].push_back(character);
    if(index == 0) {
      direction = 1;
    } else if(index == rows - 1) {
      direction = -1;
    }
    index += direction;
  }
  
  // RC O(n)
  for(const auto& row_data: data) {
    for(auto& character: row_data) {
      output += character;
    }
  }
  
  return output;
}

/*
AlgoExpert:
Input:
[1,3,4,10]
[2,5,9,11]   => [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
[6,8,12,15]
[7,13,14,16]
 
    A   A   A   A
    0   1   2   3
B0  00  10  20  30
B1  01  11  21  31
B2  02  12  22  32
B3  03  13  23  33

Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
Index:  [00 01 10 20 11 02 03 12 21 30 31 22 13 23 32 33]
*/
std::string zig_zag_conversion_ae(std::vector<std::vector<int>>& matrix) {
  std::string output;
  auto rows = matrix[0].size();
  auto columns = matrix.size();
  
  for(int row = 0; row < rows; ++row) {
  }
  
  return output;
}
void invoke_zig_zag_conversion() {
  // For AE
//  std::vector<std::vector<int>> matrix = {
//    {1,3,4,10},
//    {2,5,9,11},
//    {6,8,12,15},
//    {7,13,14,16}
//  };
  std::string input = "PAYPALISHIRING";
  std::cout<<zig_zag_conversion_lc(input, 4)<< std::endl;
}

/*
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
|
|             |X|
|     |X|     |X|X| |X|
|_|X| |X|X| |X|X|X|X|X|X|
 
Input: [3,2,1,2,1]
Output: 1
|
|X|
|X|X| |X|
|X|X|X|X|X|
 
Input: [4,2,0,3,2,5]
Output: 9
          |X|
|X|       |X|
|X|   |X| |X|
|X|X| |X|X|X|
|X|X| |X|X|X|
*/
int trapping_rain_water(std::vector<int>& input) {
  int output = 0;
  int left = 0, right= input.size() - 1;
  int max_left = 0, max_right = 0;
  while(left < right) {
    // Left block is smaller than right block
    if(input[left] <= input[right]) {
      if(input[left] >= max_left) {
        max_left = input[left];
      } else {
        output += max_left - input[left];
      }
      ++left;
    } else {
      // Left block is greater than right block
      if(input[right] >= max_right) {
        max_right = input[right];
      } else {
        output += max_right - input[right];
      }
      --right;
    }
  }
  return output;
}
void invoke_trapping_rain_water() {
  std::vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
  std::cout<<trapping_rain_water(input)<<std::endl;
}

/*
Input:       Output:
 {0,1,2,0}    {0,0,0,0}
 {3,1,5,2} => {0,1,5,0}
 {1,3,1,5}    {0,3,1,0}
*/
std::vector<std::vector<int>> set_matrix_zeroes(std::vector<std::vector<int>>& input) {
  // Overall RC: O(m*n) = O(mn(m+n)) = O(m^2n+n^2m)
//  std::vector<std::vector<int>> output = input;
//  for(int row = 0; row < input.size(); ++row) {
//    for(int column = 0; column < input[0].size(); ++column) {
//      if(input[row][column] == 0) {
//        // RC: O(n)
//        // Zero out column
//        int start_column = 0;
//        while(start_column < output[0].size()) {
//          output[row][start_column] = 0;
//          ++start_column;
//        }
//        
//        // O(m)
//        // Zero out row
//        int start_row = 0;
//        while(start_row < output.size()) {
//          output[start_row][column] = 0;
//          ++start_row;
//        }
//      }
//    }
//  }
//  return output;
  
  // Overall RC: O(mn)
  std::unordered_set<int> rows, columns;
  for(int row = 0; row < input.size(); ++row) {
    for(int column = 0; column < input[0].size(); ++column) {
      if(input[row][column] == 0) {
        rows.insert(row);
        columns.insert(column);
      }
    }
  }
  
  // RC: O(mn)
  for(int row = 0; row < input.size(); ++row) {
    for(int column = 0; column < input[0].size(); ++column) {
      if(rows.contains(row) || columns.contains(column)) {
        input[row][column] = 0;
      }
    }
  }
  return input;
}
void invoke_set_matrix_zeroes() {
  std::vector<std::vector<int>> input = {
    {0,1,2,0},
    {3,1,5,2},
    {1,3,1,5},
  };
  auto output = set_matrix_zeroes(input);
  for(auto& row: output) {
    std::for_each(row.begin(), row.end(), [](int& element) {
      std::cout<<element<<", ";
    });
    std::cout<<std::endl;
  }
}

/*
Input: "101"
Output: 1
 
Input: "100"
Output: 2
Process:
 LR      LR      LR
 100 => 010 -> 001
 
Input: "1100"
Output:
 1100 => 1010 -> 0110 -> 0101 -> 0011
 
Input: "11000"
Output: 6
 LR
 11000 => 10100 -> 01100 -> 01010 -> 00110 -> 00101 -> 00011
 
Input: "11010"
Output: 5
Process:
 LR       L R
 11010 => 10110 -> 01110
 
Input: "1101000"
Output: 11
Process:
    L  R                            L  R                                       L  R
 1101000 => 1100100 -> 1100010 -> 1100001 -> 1010001 -> 1001001 -> 1000101 -> 1000011...
*/
int separate_black_and_white_balls(std::string& input) {
  int output = 0, counter = 0;
  for(int index = 0; index < input.size(); ++index) {
    if(input[index] == '1') {
      ++counter;
    } else {
      output += counter;
    }
  }
  return output;
}
void invoke_separate_black_and_white_balls() {
  std::string input = "11000";
  std::cout<<"Min. steps to separate black and white balls: "
    <<separate_black_and_white_balls(input)
    <<std::endl;
}

/*
Input: [2,7,11,15], Target: 22
Output: [1, 3]
*/
std::vector<int> two_sum_ii(std::vector<int>& numbers, int target) {
  int low = 0, high = numbers.size() - 1;
  while(low < high) {
    auto sum = numbers[low] + numbers[high];
    if(sum == target) {
      return {low + 1, high + 1};
    } else if(sum < target) {
      ++low;
    } else {
      --high;
    }
  }
  return {};
}
void invoke_two_sum_ii() {
  std::vector<int> input = {2,7,11,15};
  auto output = two_sum_ii(input, 22);
  std::cout<<"The indices of two sum ii are: ";
  std::for_each(output.begin(), output.end(), [](auto& number) {
    std::cout<<number<<", ";
  });
}

/*
Input: [2,7,11,15]
Output: [1,3]
Solution:
Target = a + b -> a = Target - b
7 == 22 - 15
*/
std::vector<int> two_sum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> hash_map;
  for(int index = 0; index < nums.size(); ++index) {
    auto diff = target - nums[index];
    if(hash_map.count(diff)) {
      return {hash_map[diff], index};
    }
    hash_map[nums[index]] = index;
  }

  return {};
}
void invoke_two_sum() {
  std::vector<int> input = {2,7,11,15};
  auto output = two_sum(input, 22);
  std::cout<<"The indices of two sums are: "<<output[0]<<", "<<output[1]<<std::endl;
}

/*
Input:     Output:
 [1,2,3]          [7,4,1]
 [4,5,6]       => [8,5,2]
 [7,8,9]          [9,6,3]
Process:
 
 Reverse the input => [7, 8, 9]
                      [4, 5, 6]
                      [1, 2, 3]
        R0C1
     [7, 8, 9]R0C2
R1C0 [4, 5, 6]R1C2
R2C0 [1, 2, 3]
        R2C1
 Swap the symmetrical parts
*/
void rotate_image(std::vector<std::vector<int>>& input) {
  std::reverse(input.begin(), input.end());
  for(int row = 0; row < input.size(); ++row) {
    for(int column = row + 1; column < input[row].size(); ++column) {
      std::swap(input[row][column], input[column][row]);
    }
  }
}
void invoke_rotate_image() {
  std::vector<std::vector<int>> input = {
    {1,2,3},
    {4,5,6},
    {7,8,9},
  };
  rotate_image(input);
  std::cout<<"The rotated matrix is: "<<std::endl;
  std::for_each(input.begin(), input.end(), [](std::vector<int> row) {
    std::cout<<row[0]<<", "<<row[1]<<", "<<row[2]<<std::endl;
  });
}

/*
 Input: [1,2,3]
 Output: [[123],[132],[231][213],[312][321]]
 Process:
           123
  123      213       321
123 132  213 231   321 312

           012
     /      |        \
   012     102       210
  /  \    /  \       / \
012 021  102 120   210 201
*/
void permutations(std::vector<int>& input, int index, std::vector<std::vector<int>>& output) {
  if(index == input.size() - 1) {
//    std::cout<<"Answer: "<<input[0]<<" "<<input[1]<<" "<<input[2]<<std::endl;
    output.push_back(input);
  } else {
    for(int count = index; count < input.size(); ++count) {
      std::swap(input[count], input[index]);
//      std::cout<<"Before recursion: "<<input[0]<<" "<<input[1]<<" "<<input[2]<<std::endl;
      permutations(input, index + 1, output);
      std::swap(input[count], input[index]);
//      std::cout<<"After recursion: "<<input[0]<<" "<<input[1]<<" "<<input[2]<<std::endl;
    }
  }
}
void invoke_permutations() {
  std::vector<std::vector<int>> output;
  std::vector<int> input = {1,2,3};
  permutations(input, 0, output);
  std::cout<<"Permutation of the input: ";
  std::for_each(output.begin(), output.end(), [](std::vector<int>& array) {
    std::cout<<array[0]<<array[1]<<array[2]<<" ";
  });
}

/*
Input:
 [1,3,1]
 [1,5,1] => Output: 7
 [4,2,1]
 Process:
 [1,4,5]
 [2,8,6] => Output: 7
 [6,8,7]
 
 [1,2,3] => Output: 12
 [4,5,6]
 Process:
 [1,3,6]
 [5,8,12]
*/
int minimum_path_sum(std::vector<std::vector<int>>& input) {
  for(int row = 0; row < input.size(); ++row) {
    for(int column = 0; column < input[0].size(); ++column) {
      if(row > 0 && column > 0) {
        input[row][column] += std::min(input[row - 1][column], input[row][column - 1]);
      } else if(row > 0) {
        input[row][column] += input[row - 1][column];
      } else if(column > 0) {
        input[row][column] += input[row][column - 1];
      }
    }
  }
  return input[input.size() - 1][input[0].size() - 1];
}
void invoke_minimum_path_sum() {
  std::vector<std::vector<int>> input = {
    {1,2,3},
    {4,5,6},
  };
  std::cout<<"Minimum path sum is: "<<minimum_path_sum(input);
}

/*
Input:
 [1,2,3]
 [4,5,6] => Output: [1,2,3,6,9,8,7,4,5]
 [7,8,9]
Process:
 pattern: right, down, left, up
 rows: number of rows -> 3
 columns: number of columns -> 3
 shifts:
  horizontal: 3,2,1
  vertical: 2,1,0
 
 * C C    00 01 02
 R C R => 10 11 12 => [00 01 02 12 22 21 20 10 11]
 C C R    20 21 22
*/
std::vector<int> spiral_matrix(std::vector<std::vector<int>>& input) {
  std::vector<int> output;
  
  std::vector<std::vector<int>> direction = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
  };
  int rows = input.size(), columns = input[0].size();
  
  int current_row = 0, current_column = -1;
  int direction_index = 0;
  
  std::vector<int> number_of_steps{columns, rows - 1}; // 3,2
  
  while(number_of_steps[direction_index % 2]) { //
    for(int index = 0; index < number_of_steps[direction_index % 2]; ++index) {
      current_row += direction[direction_index][0];
      current_column += direction[direction_index][1];
      output.push_back(input[current_row][current_column]);
    }
    
    number_of_steps[direction_index % 2]--;
    direction_index = (direction_index + 1) % 4;
  }
  
  return output;
}
void invoke_spiral_matrix() {
  std::vector<std::vector<int>> input {
    {1,2,3},
    {4,5,6},
    {7,8,9},
  };
  auto output = spiral_matrix(input);
  std::cout<<"Spiral matrix: ";
  std::for_each(output.begin(), output.end(), [](int& number) {
    std::cout<<number<<", ";
  });
}

/*
Input: [3,0,6,1,5] Output: 3
Process:
 sort: 6,5,3,1,0
 h_index: 1
  6 >= 1 true
 h_index: 2
  5 >= 2 true
 h_index: 3
  3 >= 3 true => Output
 h_index: 1
  1 >= 3 false
 
Input: [1,3,1] Output: 1
Process:
 sort: 1,1,3
*/
int h_index(std::vector<int>& input) {
  int output = 0;
  std::sort(input.begin(), input.end(), std::greater<int>());
  
  int h_index = 1;
  for(int index = 0; index < input.size(); ++index) {
    if(input[index] >= h_index) {
      output = h_index;
      ++h_index;
    }
  }
  
  return output;
}
void invoke_h_index() {
  std::vector<int> input = {3,0,6,1,5};
  std::cout<<"The number of citations needed: "<<h_index(input);
}

/*
Input: [2,2,3,2] => Output: 3
 Total: 9 1001
 2 10 & 1001 => 1
 2
 3 11 & 1001 => 1
 2
 
 10 | 10 = 10
 10 | 11 = 11
 
Input: [0,1,0,1,0,1,99] => Output: 99
*/
int single_number_ii(std::vector<int>& input) {
  int output = 0;
  
  return output;
}
void invoke_single_number_ii() {
  std::vector<int> input = {2,2,3,2};
  std::cout<<"The single ii is: "<<single_number_ii(input);
}

/*
Input: one: "11", two: "1" => Output: "100"
 11
 01
 ---
 100
*/
std::string add_binary(std::string& one, std::string& two) {
  std::string output;
  int first_index = one.size() - 1, second_index = two.size() - 1;
  int carry = 0, sum = 0;
  
  while(first_index >= 0 || second_index >= 0) {
    sum = carry;
    
    if(first_index >= 0) {
      sum += one[first_index--] - '0';
    }
    if(second_index >= 0) {
      sum += one[second_index--] - '0';
    }
    carry = sum > 1 ? 1 : 0;
    output += std::to_string(sum % 2);
  }
  if(carry) {
    output += std::to_string(carry);
  }
  std::reverse(output.begin(), output.end());
  
  return output;
}
void invoke_add_binary() {
  std::string one = "11", two = "1";
  std::cout<<"The sum of binary is: "<<add_binary(one, two);
}

/*
Input: gas: [1,2,3,4,5], cost: [3,4,5,1,2] => Output: 3
Process:
       0 1 2 3 4          0 1 2 3 4
 gas: [1,2,3,4,5], cost: [3,4,5,1,2]
 Start at gas[3]: 0 + 4
 gas[4]: 4 - 1 + 5 = 8
 gas[0]: 8 - 2 + 1 = 7
 gas[1]: 7 - 3 + 2 = 6
 gas[2]: 6 - 4 + 3 = 5
 gas[3]: 5
 
Input: gas: [2,3,4], cost: [3,4,3] => Output: -1
Process:
 Start at gas[2]: 0 + 4
 gas[0]: 4 - 3 + 2 = 3
 gas[1]: 3 - 3 + 3 = 3
 gas[2]: 3 < 4 => Output: -1
 
Input: gas: [5,1,2,3,4], cost: [4,4,1,5,1] => Output: 4
Process:
 index
 0 = 5 - 4 1, current_gas = 1
 1 = 1 + 1 - 4, current_gas = -2, current_index = 1 + 1 = 2
 2 = 2 - 1, current_gas = 1
 3 = 1 + 3 - 5, current_gas = -1, current_index = 3 + 1 = 4
 4 = 4 - 1, current_gas = 3
*/
int gas_station(std::vector<int>& gas, std::vector<int>& cost) {
  int output = 0, current_gas = 0;
  int total_gas = 0, total_cost = 0;
  
  for(int index = 0; index < gas.size(); ++index) {
    total_gas += gas[index];
    total_cost += cost[index];
    
    current_gas += gas[index] - cost[index]; // 1
    if(current_gas < 0) {
      output = index + 1;
      current_gas = 0;
    }
  }
  
  return total_gas < total_cost ? -1 : output;
}
void invoke_gas_station() {
  std::vector<int> gas = {5,1,2,3,4};
  std::vector<int> cost = {4,4,1,5,1};
  std::cout<<"The starting gas station's index: "<<gas_station(gas, cost);
}

/*
Input: [1,0,2], Output: 5 => [2,1,2]
 
Input: [1,2,2], Output: 4 => [1,2,1]
 
Input: [2,2,2], Output: => [1,2,1]
 
Input: [0,0,0], Output: => [1,2,1]
*/
int candy(std::vector<int>& input) {
  return 0;
}
void invoke_candy() {
  std::vector<int> input = {1,0,2};
  std::cout<<"The minimum number of candies required to distribute the candies to the children: "<< candy(input);
}

/*
Input: [100,4,200,1,3,2], Output: 4 => [1,2,3,4]
Process:
 Store all the elements in a hash table: [100,4,200,1,3,2]
 Psuedocode:
 longest = 0
 for num in hash_table: // 100,4,200,1
  if !hash_table contains(num - 1): // 100 - 1 is not there
    current_number = num // 100,200,1
    while(hash_table contains(curret_number)):
      current_number ++ // 101,201,1,2,3,4,5
 
    longest = max(longest, current_number - num) // 101-100: 1, 201-200: 1, 5-1: 4

Input: [0,3,7,2,5,8,4,6,0,1], Output: 9 => [0,1,2,3,4,5,6,7,8]
*/
int longest_consecutive_sequence(std::vector<int>& input) {
  int output = 0;
  std::unordered_set<int> number_hash;
  
  // RC: O(n), SC: O(n)
  for(auto& number: input) {
    number_hash.insert(number);
  }
  
  // RC: O(n)
  for(auto& number: input) {
    if(!number_hash.contains(number - 1)) {
      int increasing_sequence = number;
      while(number_hash.contains(increasing_sequence)) {
        ++increasing_sequence;
      }
      
      output = std::max(output, increasing_sequence - number);
    }
  }
  
  return output;
}
void invoke_longest_consecutive_sequence() {
  std::vector<int> input = {100,4,200,1,3,2};
  std::cout<<"The longest consecutive sequence is: "<<longest_consecutive_sequence(input);
}

/*
 
*/
bool search_a_2d_matrix(std::vector<std::vector<int>>& input) {
  return true;
}
void invoke_search_a_2d_matrix() {
  std::vector<std::vector<int>> input = {
    {1,3,5,7},
    {10,11,16,20},
    {23,30,34,60},
  };
  std::cout<<"Search a 2D matrix: "<<std::boolalpha<<search_a_2d_matrix(input);
}

/*
Input: [1,2,3,1], Output: 2
Process:
 0 1 2 3 (index)
 1,2,3,1
 median = 0+3/2 = 1
 2<3? true low = median + 1 = 2
 median = 2+3/2 = 2
 3<1? false high = median
 
Input: [1,2,1,3,5,6,4], Output: 5
Process:
 0 1 2 3 4 5 6 (index)
 1,2,1,3,5,6,4
 median = 0+6/2 = 3
 3>5? false else low = 4
 median = 4+6/2 = 5
 6>4? true high = median
*/
int find_peak_element(std::vector<int>& input) {
  int low = 0, high = input.size() - 1;
  while(low < high) {
    int median = (low + high) / 2; // 3
    if(input[median] > input[median + 1]) { // 3>5
      high = median;
    } else {
      low = median + 1; // 4
    }
  }
  
  return low;
}
void invoke_find_peak_element() {
  std::vector<int> input = {1,2,3,1};
  std::cout<<"The peak element is: "<<find_peak_element(input);
}
