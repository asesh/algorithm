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

// Iterative binary serach
bool binary_search(std::vector<int>& input, int target, int low, int high) {
  while(low <= high) {
    int median = (low + high) >> 1;
    if(input[median] == target) {
      return true;
    }
    
    if(input[median] < target) {
      low = median + 1;
    } else {
      high = median - 1;
    }
  }
  
  return false;
}
void invoke_binary_search() {
  std::vector<int> input = {1,3,5,7};
  std::cout<<std::boolalpha<<binary_search(input, 8, 0, input.size() - 1);
}

// Recursive implementation for binary search
//int binary_search(int input_array[], int number_to_search, int lower_index, int higher_index) {
//	// index: 0  1  2  3  4  5   6
//	// input: 1, 3, 4, 7, 9, 11, 13
//	// search: 13
//	if(higher_index >= 1) {
//		// Calculate median
//		int median = (lower_index + higher_index) / 2;
//		
//		if(input_array[median] == number_to_search) {
//			return median;
//		}
//		
//		// Search lower bound
//		if(input_array[median] > number_to_search) {
//			return binary_search(input_array, number_to_search, lower_index, median);
//		}
//		
//		// Search higher bound
//		return binary_search(input_array, number_to_search, median + 1, higher_index);
//	}
//	
//	return -1;
//}

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
//	CSingleLinkedList<int> output;
//	CSingleLinkedList<int> first;
//	first.add_node(2);
//	first.add_node(4);
//	first.add_node(3);
//	CSingleLinkedList<int> second;
//	second.add_node(5);
//	second.add_node(6);
//	second.add_node(4);
//	add_reverse_linked_list(first, second, output);
//	first.clear_nodes();
//	second.clear_nodes();
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

  // O(nlogn)
  std::sort(input_array.begin(), input_array.end());

  for(int index = 0; index < input_array.size() && input_array[index] <= 0; ++index) {
    if(index > 0 && input_array[index - 1] == input_array[index]) {
      continue;
    }

    int left = index + 1;
    int right = input_array.size() - 1;
    while(left < right) {
      auto sum = input_array[index] + input_array[left] + input_array[right];
      if(sum == 0) {
        output.push_back({input_array[index],input_array[left],input_array[right]});
        --right;
        ++left;
        while(left < right && input_array[left] == input_array[left - 1]) {
          ++left;
        }
      } else if(sum > 0) {
        --right;
      } else {
        ++left;
      }
    }
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

// Time: O(wh), Space: O(wh)
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
 2: 10
  0: (10 >> 0) & 1 = 0
  1: (10 >> 1) & 1 = 1
 3: 11
  0: (11 >> 0) & 1 = 1
  1: (11 >> 1) & 1 = 1
 
 sum_bit:
 0: 0 + 0 + 1 + 0 = 0 -> (1 % 3) = (1 << 0) = 01
 1: 1 + 1 + 1 + 1 = 4 -> (4 % 3) = (1 << 1) = 11 <- Output
*/
int single_number_ii(std::vector<int>& input) {
  int output = 0;
  
  for(int shift = 0; shift < 32; ++shift) {
    int bit_sum = 0;
    for(auto& num: input) {
      bit_sum += ((num >> shift) & 1);
    }
    output = output | ((bit_sum % 3) << shift);
  }
  
  return output;
}
void invoke_single_number_ii() {
  std::vector<int> input = {2,2,3,2};
  std::cout<<"137. Single Number II: "<<single_number_ii(input);
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
Input:            Target: 3, Output: true
  {1,3,5,7},
  {10,11,16,20},
  {23,30,34,60},
*/
bool search_a_2d_matrix(std::vector<std::vector<int>>& input, int target) {
  int rows = input.size(), columns = input[0].size();
  int row = 0, column = columns - 1;
  while(row < rows && column >= 0) {
    int current_value = input[row][column];
    if(current_value == target) {
      return true;
    }
    
    if(target > current_value) {
      ++row;
    } else {
      --column;
    }
  }

  return false;
}
void invoke_search_a_2d_matrix() {
  std::vector<std::vector<int>> input = {
    {1,3,5,7},
    {10,11,16,20},
    {23,30,34,60},
  };
  std::cout<<"Search a 2D matrix: "<<std::boolalpha<<search_a_2d_matrix(input, 24);
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

/*
Input: [2,3], Target: 6, Output: [[2,2,2],[3,3]]
Process:
 sort the input
        2       3
  2(+2)      4+3!
 6(+4)*      2+3
            2+3+3!
            3
            3+3*
 
Input: [2,3], Target: 7, Output: [[2,2,2],[3,3]]
Process: sort the input
       2    3
    2+2   ->4+3*  3
   2+4!   2+3     3+3
          5+3!    6+3!
  
 
Input: [2,3,6,7], Target: 7, Output: [[2,2,3],[7]]
     2       3        6       7
   4    /6+3!  6      12!
  6     /4+3   9!
 8!
*/
void combination_sum(std::vector<int>& input, int target, std::vector<int> candidate,
                     int current_index, std::vector<std::vector<int>>& output) {
  if(target == 0) {
    output.push_back(candidate);
    return;
  }
  
  for(int index = current_index; index < input.size(); ++index) {
    int current_number = input[index];
    if(current_number > target) { // 2>7, 2>5, 2>3, 2>1?true
      return;
    }
    
    candidate.push_back(current_number); // 2, 2, 2
    combination_sum(input, target - current_number, candidate, index, output); // target: 7-2=5, 5-2=3, 3-2=1
    candidate.pop_back();
  }
}
void invoke_combination_sum() {
  std::vector<std::vector<int>> output;
  std::vector<int> input = {2,3,6,7};
  combination_sum(input, 7, {}, 0, output);
  std::cout<<"Combination sum: "<<"[";
  std::for_each(output.begin(), output.end(), [](std::vector<int> numbers) {
    std::cout<<"[";
    for(auto& number: numbers) {
      std::cout<<number<<", ";
    }
    std::cout<<"]";
  });
  std::cout<<"]";
}

/*
Input: [  Output: 4
 [1,-1],
 [-1,1]
 ]
Process:
 
Input: [     Output: 16
 [1,2,3],
 [-1,-2,-3],
 [1,2,3]
 ]
*/
int maximium_matrix_sum(std::vector<std::vector<int>>& input) {
  int output = 0;
  
  return output;
}
void invoke_maximium_matrix_sum() {
  std::vector<std::vector<int>> input = {
    {1,-1},
    {-1,1}
    
//    {1,2,3},
//    {-1,-2,-3},
//    {1,2,3}
  };
  std::cout<<"Maximium matrix sum: "<<maximium_matrix_sum(input);
}

/*
push: -2,0,-3
get_min: -3
pop: -3
top: 0
get_min: -2
*/
void MinStack::push(int value) {
  if(value <= m_min_element) { // -2 <= INT_MAX, 0 <= -2, -3 <= -2
    m_stack.push(m_min_element); // INT_MAX,-3,0,-2,
    m_min_element = value; // -2 => -3
  }
  m_stack.push(value); // INT_MAX,-3,0,-2,-3
}
void MinStack::pop() {
  if(m_min_element == m_stack.top()) { //
    m_stack.pop(); //
    m_min_element = m_stack.top();
  }
  m_stack.pop();
}
int MinStack::top() {
  return m_stack.top();
}
int MinStack::get_min() {
  return m_min_element;
}
void invoke_min_stack() {
  MinStack min_stack;
  min_stack.push(-2);
  min_stack.push(0);
  min_stack.push(-3);
  std::cout<<"get_min: "<<min_stack.get_min()<<std::endl;
  std::cout<<"pop"<<std::endl;
  min_stack.pop();
  std::cout<<"top: "<<min_stack.top()<<std::endl;
  std::cout<<"get_min: "<<min_stack.get_min()<<std::endl;
}

/*
Input: [
 [1,3],
 [2,6],
 [8,10],
 [15,18]], Output: [[1,6],[8,10],[15,18]]
Process:
 sort: [1,3],[2,6][8,10][15,18]
 [1,3] 3 < 6 [2,6] true => [1,6]
 [1,6] 6 < 10 [8,10] true => [8, 10]
 [8,10] 10 < 15 [15,18] true => [15, 18]
*/
std::vector<std::vector<int>> merge_intervals(std::vector<std::vector<int>>& input) {
  std::vector<std::vector<int>> output;
  std::sort(input.begin(), input.end(), [](std::vector<int>& interval_one, std::vector<int>& interval_two) {
    return interval_one[0] < interval_two[0];
  });
  output.push_back(input[0]);
  
  for(int index = 1; index < input.size(); ++index) {
    if(output.back()[1] < input[index][0]) {
      output.push_back(input[index]);
    } else {
      output.back()[1] = std::max(output.back()[1], input[index][1]);
    }
  }
  
  return output;
}
void invoke_merge_intervals() {
  std::vector<std::vector<int>> input = {
//    {1,3},{2,6},{8,10},{15,18}
//    {1,4},{5,6}
//    {1,4},{2,3}
    {1,4},{2,3},{5,8}
  };
  auto output = merge_intervals(input);
  std::for_each(output.begin(), output.end(), [](std::vector<int>& interval) {
    std::cout<<"[";
    for(auto& number: interval) {
      std::cout<<number<<", ";
    }
    std::cout<<"], ";
  });
}

/*
Input: [-2,1,-3,4,-1,2,1,-5,4], Output: 6 [4,-1,2,1]
 
Input: [-1,1,2,-2], Output: 3 [1,2]
Process:
 Using DnQ
   0 1 2  3
 [-1,1,2,-2]
*/
// Using divide-and-conquer approach
int maximium_subarray(std::vector<int>& input, int low, int high) {
  if(low > high) {
    return INT_MIN;
  }
  
  int mid = (low + high) / 2;
  
  return INT_MIN;
}
int maximium_subarray(std::vector<int>& input) {
  int output = INT_MIN, current_max = 0;
  for(auto& number: input) {
    current_max = std::max(number, current_max + number); // -1,1,3,1
    output = std::max(output, current_max);
  }
  return output;
}
void invoke_maximium_subarray() {
  std::vector<int> input = {-1,1,2,-2};//{-2,1,-3,4,-1,2,1,-5,4};
//  std::cout<<"Maximium subarray: "<<maximium_subarray(input, 0, input.size() - 1);
  std::cout<<"Maximium subarray using divice and conquer: "<<maximium_subarray(input, 0, input.size() - 1);
}

/*
Input: [1,-2,3,-2], Output: 3
Process:
 1 -2 3 -2
 total_max: 3, current_max: 1
 total_min: -2, current_min: -2
 total_sum: 0
 
Input: [5,-3,5], Output: 10
Process:
 5 -3 5
 total_max: 7
 total_min: -3
*/
int maximum_sum_circular_subarray(std::vector<int>& input) {
  int total_sum = 0;
  int current_max = 0, total_max = INT_MIN;
  int current_min = 0, total_min = INT_MAX;
  
  for(auto& number: input) {
    current_max = std::max(number, current_max + number);
    total_max = std::max(total_max, current_max); // Non-circular
    
    current_min = std::min(number, current_min + number);
    total_min = std::min(total_min, current_min);
    
    total_sum += number; // 7
  }
  
  if(total_sum == total_min) {
    return total_max;
  }
  
  return std::max(total_max, total_sum - total_min);
}
void invoke_maximum_sum_circular_subarray() {
  std::vector<int> input = {1,-2,3,-2};//{5,-3,5};
  std::cout<<"Maximum sum circular subarray: "<<maximum_sum_circular_subarray(input);
}

/*
Input: number: 4, combination: 2, Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
 
Input: number: 4, combination: 3; Output: [[1,2,3],[1,2,4],[1,3,4],[2,3,4]]
*/
// Backtracking
void combinations(int number, int combination, int first_number,
                  std::vector<int>& current,
                  std::vector<std::vector<int>>& output) {
  if(current.size() == combination) {
    output.push_back(current);
    return;
  }
  
  for(int current_number = first_number; current_number <= number; ++current_number) {
    current.push_back(current_number);
    combinations(number, combination, current_number + 1, current, output);
    current.pop_back();
  }
}
void invoke_combinations() {
  std::vector<int> current;
  std::vector<std::vector<int>> output;
  combinations(4, 2, 1, current, output);
  std::cout<<"Combinations: [";
  std::for_each(output.begin(), output.end(), [](std::vector<int>& numbers) {
    std::cout<<"[";
    for(auto& number: numbers) {
      std::cout<<number<<", ";
    }
    std::cout<<"],";
  });
  std::cout<<"],";
}

/*
Input: 4, Output: 2
*/
int n_queens_ii(int number) {
  return 0;
}
void invoke_n_queens_ii() {
  std::cout<<"N-Queens II: "<<n_queens_ii(4);
}

/*
Input: [4,5,6,7,0,1,2], target: 0, Output: 4
Process:
 Find pivot index which is the minimum value
 0 1 2 3 4 5 6
 4,5,6,7,0,1,2
 Pivot index: 4
 Search 0 - pivot index - 1
 Search pivot index to last element
 
Input: [4,5,6,7,0,1,2], target = 3, Output: -1
*/
// Returns the pivot index of the target using binary search
int binary_search_pivot_index(std::vector<int>& input, int target, int left, int right) {
  while(left <= right) {
    int median = (left + right) / 2;
    if(input[median] == target) {
      return median;
    }
    if(input[median] > target) {
      right = median - 1;
    } else {
      left = median + 1;
    }
  }
  
  return -1;
}
int search_in_rotated_sorted_array(std::vector<int>& input, int target) {
  int last_index = input.size() - 1;
  int left = 0, right = last_index;
  while(left <= right) {
    int median = (left + right) / 2;
    
    if(input[median] > input[last_index]) {
      left = median + 1;
    } else {
      right = median - 1;
    }
  }

  // Search the right-half
  int value = binary_search_pivot_index(input, target, left, last_index);
  if(value == -1) {
    // Search the left-half
    return binary_search_pivot_index(input, target, 0, left - 1);
  }

  return value;
}
void invoke_search_in_rotated_sorted_array() {
  std::vector<int> input = {4,5,6,7,0,1,2};
  std::cout<<"Search in rotated sorted array: "<<search_in_rotated_sorted_array(input, 9);
}

/*
Input: [5,7,7,8,8,10], target = 8, Output: [3,4]
Process:
  0 1 2 3 4 5
 [5,7,7,8,8,10]
 calculate mid: mid = (low + high) / 2 = 5/2 = 2
 input[mid] 7 <= 8 false. So the target lies on the right-half.
  l m r
 [8,8,10]
 mid = (0+2)/2 = 1 => 8
 
Input: [7,7,7,7,8,10], target = 7, Output: [0,2]
Process:
  0 1 2 3 4 5
 [7,7,7,7,8,10]
 mid = 5/2 = 2 = 7
 7 <= 7. Search first-half
 [7,7,7] [7,8,10]
*/
int find_first_and_last_position_of_element_in_sorted_array(std::vector<int>& input, int target, int left_index, int right_index, bool first) {
  while(left_index <= right_index) {
    int median_index = (left_index + right_index) / 2;
    if(input[median_index] == target) {
      if(first) {
        if(left_index == median_index || input[median_index - 1] != target) {
          return median_index;
        }
        right_index = median_index - 1;
      } else {
        if(right_index == median_index || input[median_index + 1] != target) {
          return median_index;
        }
        left_index = median_index + 1;
      }
    } else if(input[median_index] > target) {
      right_index = median_index - 1;
    } else {
      left_index = median_index + 1;
    }
  }
  return -1;
}
void invoke_find_first_and_last_position_of_element_in_sorted_array() {
  int target = 8;
  std::vector<int> input = {5,8,8,8,8,10};
  int left = find_first_and_last_position_of_element_in_sorted_array(input, target, 0, input.size() - 1, true);
  int right = find_first_and_last_position_of_element_in_sorted_array(input, target, 0, input.size() - 1, false);
  std::cout<<"34. Find First and Last Position of Element in Sorted Array: ["<<left<<", "<<right<<"]";
}

/*
Refer to Freeform diagram: 912. Sort an Array
*/
void merge(std::vector<int>& input, std::vector<int>& sorted_elements, int left_index, int median_index, int right_index) {
  if(left_index >= right_index) {
    return;
  }
//  std::cout
//    <<"left: "<<left_index<<"->"<<input[left_index]<<std::endl
//    <<"median: "<<median_index<<"->"<<input[median_index]<<std::endl
//    <<"right: "<<right_index<<"->"<<input[right_index]<<std::endl<<std::endl;
  
  int number_of_elements = right_index - left_index + 1;
  
  int left = left_index, right = median_index + 1;
  int current_index = 0;
  
  while(left <= median_index && right <= right_index) {
    sorted_elements[current_index++] = input[left] < input[right] ? input[left++] : input[right++];
  }
  while(left <= median_index) {
    sorted_elements[current_index++] = input[left++];
  }
  while(right <= right_index) {
    sorted_elements[current_index++] = input[right++];
  }
  for(current_index = 0; current_index < number_of_elements; ++current_index) {
    input[current_index + left_index] = sorted_elements[current_index];
  }
}
void merge_sort(std::vector<int>& input, std::vector<int>& sorted_elements, int left_index, int right_index) {
  if(left_index >= right_index) {
    return;
  }
  
  int median_index = (left_index + right_index) / 2;
  merge_sort(input, sorted_elements, left_index, median_index);
  merge_sort(input, sorted_elements, median_index + 1, right_index);
  
  merge(input, sorted_elements, left_index, median_index, right_index);
}
void invoke_merge_sort() {
  std::vector<int> input = {5,4,3,2,1,0};
  std::vector<int> sorted_elements(input.size());
  merge_sort(input, sorted_elements, 0, input.size() - 1);
  std::cout<<"912. Sort an Array -> Merge sort: ";
  for(auto& num: input) {
    std::cout<<num<<", ";
  }
}

/*
Input: [4,2,1,5,3], Output = [1,2,3,4,5]
Process:
 Pick the last element as pivot
 0 1 2 3 4
         pv
         hi
         ci
     cli
 4 2 1 5 3
 2 4 1 5 3
 2 1 4 5 3
 2 1 3 5 4
 
  pv
  hi
  ci
 cli
 2 1
 1 2
 
WARNING: TLE on LeetCode
*/
int quick_sort_partition(std::vector<int>& input, int low_index, int high_index) {
  int pivot_value = input[high_index];
  int current_low_index = low_index;
  for(int current_index = current_low_index; current_index < high_index; ++current_index) {
    if(input[current_index] < pivot_value) {
      std::swap(input[current_index], input[current_low_index]);
      ++current_low_index;
    }
  }
  std::swap(input[current_low_index], input[high_index]);
  return current_low_index;
}
void quick_sort(std::vector<int>& input, int low_index, int high_index) {
  if(low_index >= high_index) {
    return;
  }
  
  int parition_index = quick_sort_partition(input, low_index, high_index);
  quick_sort(input, low_index, parition_index - 1);
  quick_sort(input, parition_index + 1, high_index);
}
void invoke_quick_sort() {
  std::vector<int> input = {4,2,1,5,3};
  quick_sort(input, 0, input.size() - 1);
  std::cout<<"912. Sort an Array -> Quick sort: ";
  for(auto& num: input) {
    std::cout<<num<<", ";
  }
}

// RC: O(nm), SC: O(1)
bool search_2d_matrix_ii(std::vector<std::vector<int>>& matrix, int target) {
  
  // Search space reduction
  int column = 0, row = matrix.size() - 1;
  while(row >= 0 && row < matrix.size() && column >= 0 && column < matrix[0].size()) {
    if(matrix[row][column] > target) {
      --row;
    } else if(matrix[row][column] < target) {
      ++column;
    } else {
      return true;
    }
  }
  return false;
}
void invoke_search_2d_matrix_ii() {
  std::vector<std::vector<int>> matrix = {
    {1,4,7,11,15},
    {2,5,8,12,19},
    {3,6,9,16,22},
    {10,13,14,17,24},
    {18,21,23,26,30}
  };
  std::cout<<std::boolalpha<<"240. Search a 2D Matrix II: "<<search_a_2d_matrix(matrix, 3);
}

/*
Refer to Freeform: 373. Find K Pairs with Smallest Sums

Input: nums1 = [1,2,11], nums2 = [2,4,6], k = 3
 [1,2], [1,4], [1,6], [2,2], [2,4], [2,6]...
   *      *             *

Input: nums1 = [1,2,4,5,6], nums2 = [3,5,7,9], k = 3 Output => [[1,3],[2,3],[1,5]]
 [1,3], [1,5], [1,7], [1,9], [2,3], [2,5], [2,7]...
   *      *                    *
   4      6      8      10     5

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 [1,1], [1,2], [1,3], [1,1], [1,2],  [1,3], [2,1], [2,2], [2,3]
   2      3      4      2      3       4      3      4      5
   *                    *
 
RC: O(min(k*logk, m*n*log(m*n)), SC: O(min(k, m*n))
*/
std::vector<std::vector<int>> find_k_pairs_with_smallest_sums(std::vector<int>& input_one, std::vector<int>& input_two, int k) {
  std::vector<std::vector<int>> output;
  
  int input_one_size = input_one.size(), input_two_size = input_two.size();
  
  std::set<std::pair<int, int>> visited; // Indices of input_one and input_two
  // {sum of index1 and index2, {index1, index2}}
  std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<>> min_heap;
  
  // First the first element from both inputs
  min_heap.push({input_one[0] + input_two[0], {0, 0}});
  visited.insert({0, 0});
  
  while(k-- && !min_heap.empty()) {
    auto top = min_heap.top();
    min_heap.pop();
    
    auto first_index = top.second.first;
    auto second_index = top.second.second;
    output.push_back({input_one[first_index], input_two[second_index]});
    
    if(first_index + 1 < input_one_size &&
       visited.find({first_index + 1, second_index}) == visited.end()) {
      min_heap.push({input_one[first_index + 1] + input_two[second_index], {first_index + 1, second_index}});
    }
    if(second_index + 1 < input_two_size &&
       visited.find({first_index, second_index + 1}) == visited.end()) {
      min_heap.push({input_two[first_index] + input_one[second_index + 1], {first_index, second_index + 1}});
    }
  }
  
  return output;
}
void invoke_find_k_pairs_with_smallest_sums() {
  std::vector<int> input_one = {1,2,4,5,6}, input_two = {3,5,7,9};
  auto k_smallest_sums = find_k_pairs_with_smallest_sums(input_one, input_two, 3);
  std::cout<<"373. Find K Pairs with Smallest Sums: [";
  for(auto& k_pair: k_smallest_sums) {
    std::cout<<"[";
    for(auto& num: k_pair) {
      std::cout<<num<<", ";
    }
    std::cout<<"], ";
  }
  std::cout<<"]";
}

/*
Input: [41, 35, 62, 97, 108] (odd)
 Process: store smaller half in max heap and bigger half in min heap
 Sorted: [35, 41, 62, 97, 108]
 min_heap: 62, 97, 108
 max_heap: 41, 35
 
Input: [41, 35, 62, 5, 97, 108] (even)
 Sorted: [5, 35, 41, 62, 97, 108]
 min_heap: 62, 97, 108
 max_heap: 41, 25, 5
*/
class CMedianFinder {
private:
  std::priority_queue<int> max_heap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
public:
  CMedianFinder() {
  }
  void add_number(int number) {
    min_heap.push(number);
    max_heap.push(min_heap.top());
    min_heap.pop();
    
    if(min_heap.size() < max_heap.size()) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    }
  }
  double find_median() {
    return min_heap.size() > max_heap.size() ? min_heap.top() : (min_heap.top() + max_heap.top()) * 0.5;
  }
};
void invoke_find_median_from_data_stream() {
  CMedianFinder median_finder;
//  median_finder.add_number(5);
  median_finder.add_number(35);
  median_finder.add_number(41);
  median_finder.add_number(62);
  median_finder.add_number(97);
  median_finder.add_number(108);
  std::cout<<"295. Find Median from Data Stream: "<<median_finder.find_median();
}

/*
         0 1 2
Input:  [1,2,3], k = 3
         0 1 2 3
Preifx: [0,1,3,6]

         0 1 2 3 4 5 6
Input:  [1,3,4,6,2,5,8]
             -----
              12
         0 1 2 3  4  5  6  7
Prefix: [0,1,4,8,14,16,21,29]
             ---------
              16 - 4

         0  1  2  3   4  5  6  7
Input:  [3, 4, 7, 2, -3, 1, 4, 2], k: 7, Output: 3
         0  1  2   3   4   5   6   7   8
Prefix: [0, 3, 7, 14, 16, 13, 14, 18, 20]
*/
int subarray_sum_equals_k(std::vector<int>& input, int k) {
  int output = 0, sum = 0;
  std::unordered_map<int, int> prefix_map = {{0, 1}}; // 0:1, 1:1, 3:1,
  for(auto& num: input) { // 1, 2, 3
    sum += num; // 1, 3, 6
    if(prefix_map.contains(sum - k)) { // 1-3, 3-3, 6-3
      output += prefix_map[sum - k]; // 1, 2
    }
    prefix_map[sum] = prefix_map[sum] + 1;
  }
  
  return output;
}
void invoke_subarray_sum_equals_k() {
  std::vector<int> input = {3,4,7,2,-3,1,4,2}; // {1,2,3};
  std::cout<<"560. Subarray Sum Equals K: "<<subarray_sum_equals_k(input, 7);
}

/*
Implementation using doubly linkedlist and hashmap
Input: [(1,1), (2,2)]
 first <-> last
 first <-> (1,1) <-> last
 first <-> (1,1) <-> (2,2) <-> last
 get(1):
  remove(1)
  add(1)
  first <-> (2,2) <-> (1,1) <-> last
*/
class CLRUCache {
private:
  SDoublyLinkedList* first = new SDoublyLinkedList(-1);
  SDoublyLinkedList* last = new SDoublyLinkedList(-1);
  
  std::unordered_map<int, SDoublyLinkedList*> node_map;
  
  int capacity = 0;
public:
  CLRUCache(int capacity) {
    first->next = last;
    last->previous = first;
    
    this->capacity = capacity;
  }
  int get(int key) {
    if(!node_map.contains(key)) {
      return -1;
    }
    
    auto* node = node_map[key];
    remove(node);
    add(node);
    return node->value;
  }
  void put(int key, int value) {
    SDoublyLinkedList* new_node = new SDoublyLinkedList(value);
    if(node_map.contains(key)) {
      auto* node = node_map[key];
      remove(node);
      delete node;
    }
    else if(capacity == node_map.size()) {
      auto* next = first->next;
      remove(next);
      delete next;
    }
    add(new_node);
    node_map[key] = new_node;
  }
  
  void remove(SDoublyLinkedList* node) {
    node->previous->next = node->next;
    node->next->previous = node->previous;
  }
  void add(SDoublyLinkedList* node) {
    auto* previous = last->previous;
    previous->next = node;
    node->previous = previous;
    node->next = last;
    last->previous = node;
  }
  
  void destroy() {
    while(first) {
      auto* next = first->next;
      delete first;
      first = next;
    }
  }
};
void invoke_lru_cache() {
  CLRUCache lru_cache(5);
  std::cout<<"146. LRU Cache: "<<std::endl<<"get(1): "<<lru_cache.get(1)<<std::endl;
  std::cout<<"put(1,1)"<<std::endl;
  lru_cache.put(1, 1);
  std::cout<<"get(1): "<<lru_cache.get(1)<<std::endl;
  std::cout<<"put(2,2)"<<std::endl;
  lru_cache.put(2, 2);
  std::cout<<"get(2): "<<lru_cache.get(2)<<std::endl;
  std::cout<<"put(3,3)"<<std::endl;
  lru_cache.put(3, 3);
  std::cout<<"get(3): "<<lru_cache.get(3)<<std::endl;
  std::cout<<"put(4,4)"<<std::endl;
  lru_cache.put(4, 4);
  std::cout<<"get(4): "<<lru_cache.get(4)<<std::endl;
  std::cout<<"put(5,5)"<<std::endl;
  lru_cache.put(5, 5);
  std::cout<<"get(2): "<<lru_cache.get(2)<<std::endl
    <<"get(3): "<<lru_cache.get(3)<<std::endl;
  
  lru_cache.destroy();
}

/*
Input: left: 5, right: 7, Ouptut: 4
 5: 101 >> 1 => 10 >> 1 => 1 (m)
 7: 111 >> 1 => 11 >> 1 => 1 (n)
 shift count: 2
 output: m << shift count
 
Input: left: 1, right: 10
 1:  0001 >> 1 => 0000 >> 1 => 0000 >> 1 => 0000 >> 1 => 0000 >> 1
 10: 1010 >> 1 => 0101 >> 1 => 0010 >> 1 => 0001 >> 1 => 0000 >> 1
 shft count: 5
 output: m << shift count
*/
int bitwise_and_of_numbers_range(int left, int right) {
  int shift_count = 0;
  
  while(left < right) {
    left >>= 1;
    right >>= 1;
    ++shift_count;
  }
  
  return left << shift_count;
}
void invoke_bitwise_and_of_numbers_range() {
  std::cout<<"201. Bitwise AND of Numbers Range: "<<bitwise_and_of_numbers_range(5, 7);
}

/*
Input: 12
 12: 1100
 1100 >> 1100 >> 0 & 1 => 110 >> 1 & 1 => (11 >> 1) & 1 => (1 >> 1) & 1 & 1
 Output: 2
*/
int number_of_1_bits(int input) {
  int output = 0;
  for(int shift = 0; shift < 32; ++shift) {
    output += (input >> shift) & 1;
  }
  
  return output;
}
void invoke_number_of_1_bits() {
  std::cout<<"191. Number of 1 Bits: "<<number_of_1_bits(21);
}

/*
Input: ["4","13","5","/","+"] => (4 + (13 / 5)) = 6
 stack:
 5  X
 13 X
 2  X
 4  X
 6  X pop => answer
*/
int evaluate_reverse_polish_notation(std::vector<std::string>& tokens) {
  std::stack<int> number_stack;
  std::unordered_set<std::string> operators_list = {"+", "-", "*", "/"};

  for(auto& token: tokens) {
    if(operators_list.contains(token)) {
      auto number_two = number_stack.top();
      number_stack.pop();
      auto number_one = number_stack.top();
      number_stack.pop();
      int sum = 0;
      if(token.compare("+") == 0) {
        sum = number_one + number_two;
      } else if(token.compare("-") == 0) {
        sum = number_one - number_two;
      } else if(token.compare("*") == 0) {
        sum = number_one * number_two;
      } else {
        sum = number_one / number_two;
      }
      number_stack.push(sum);
    } else {
      number_stack.push(std::stoi(token));
    }
  }

  return number_stack.top();
}
void invoke_evaluate_reverse_polish_notation() {
  std::vector<std::string> input = {"4","13","5","/","+"};
  std::cout<<"150. Evaluate Reverse Polish Notation: "<<evaluate_reverse_polish_notation(input);
}

// DFS
void maximum_number_of_fish_in_a_grid(std::vector<std::vector<int>>& grid,
                                     int row, int column, int& output) {
  if(row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size() ||
    grid[row][column] == 0) {
    return;
  }

  output += grid[row][column];
  grid[row][column] = 0;

  maximum_number_of_fish_in_a_grid(grid, row, column + 1, output);
  maximum_number_of_fish_in_a_grid(grid, row + 1, column, output);
  maximum_number_of_fish_in_a_grid(grid, row, column - 1, output);
  maximum_number_of_fish_in_a_grid(grid, row - 1, column, output);
}
void invoke_maximum_number_of_fish_in_a_grid() {
  std::vector<std::vector<int>> grid = {
    {0,2,1,0},
    {4,0,0,3},
    {1,0,0,4},
    {0,3,2,0}
  };
  int output = 0;
  std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
  for(int row = 0; row < grid.size(); ++row) {
    for(int column = 0; column < grid[0].size(); ++column) {
      int num_fishes = 0;
      maximum_number_of_fish_in_a_grid(grid, row, column, num_fishes);
      output = std::max(output, num_fishes);
    }
  }
  
  std::cout<<"2658. Maximum Number of Fish in a Grid: "<<output;
}

/*
 L     M     H
[0,1,2,3,4,5,6]
L     H
0 1 2 3
L H
0 1 2 3

 L     M     H
[4,5,6,0,1,2,3]
L     H
4,5,6,0,1,2,3
  M
4,5,6,0
L H
6,0
0

 L     M     H
[5,6,0,1,2,3,4]
L     H
5,6,0,1
L H
0,1

 L   M   H
[3,4,5,1,2]
L H
1,2
 */
int find_minimum_in_rotated_sorted_array(std::vector<int>& input) {
  int low = 0, high = input.size() - 1;
  while(low < high) {
    int median = (low + high) / 2;
    if(input[median] > input[high]) {
      low = median + 1;
    } else {
      high = median;
    }
  }
  
  return input[low];
}
void invoke_find_minimum_in_rotated_sorted_array() {
  std::vector<int> input = {3,4,5,1,2}; // {5,6,0,1,2,3,4};
  std::cout<<"153. Find Minimum in Rotated Sorted Array: "<<find_minimum_in_rotated_sorted_array(input);
}

// DFS
void sorround_regions(std::vector<std::vector<char>>& grid, int row, int column) {
  if(row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size() || grid[row][column] == 'X' || grid[row][column] == 'N') {
    return;
  }
  
  grid[row][column] = 'N';
  
  sorround_regions(grid, row, column - 1); // Left
  sorround_regions(grid, row - 1, column); // Top
  sorround_regions(grid, row, column + 1); // Right
  sorround_regions(grid, row + 1, column); // Bottom
}
void invoke_sorround_regions() {
  std::vector<std::vector<char>> grid = {
    {'X','X','X','X'},
    {'X','O','O','X'},
    {'X','X','O','X'},
    {'X','O','X','X'}
    
//    {'X','X','X','X'},
//    {'X','X','O','X'},
//    {'X','O','O','X'},
//    {'X','O','X','X'}
  };
  int rows = grid.size(), columns = grid[0].size();
  for(int row = 0; row < rows; ++row) {
    for(int column = 0; column < columns; ++column) {
      if(row == 0 || row == rows - 1 || column == 0 || column == columns - 1) {
        sorround_regions(grid, row, column);
      }
    }
  }
  for(int row = 0; row < rows; ++row) {
    for(int column = 0; column < columns; ++column) {
      if(grid[row][column] == 'N') {
        grid[row][column] = 'O';
      } else if(grid[row][column] == 'O') {
        grid[row][column] = 'X';
      }
    }
  }
  std::cout<<"130. Surrounded Regions: ["<<std::endl;
  for(auto& row: grid) {
    std::cout<<"{";
    for(auto& cell_value: row) {
      std::cout<<cell_value<<", ";
    }
    std::cout<<"}"<<std::endl;
  }
  std::cout<<"]";
}

/*
Input: [{1,2},{3,5},{6,7},{8,10},{12,16}], new_interval: [4,8]
Output: [{1,2},{3,10},{12,16}]
*/
std::vector<std::vector<int>> insert_interval(std::vector<std::vector<int>>& intervals,
                                              std::vector<int>& new_interval) {
  std::vector<std::vector<int>> output;
  int current_index = 0, max_index = intervals.size();
  
  // For non-overlapping intervals
  while(current_index < max_index && intervals[current_index][1] < new_interval[0]) {
    output.push_back(intervals[current_index++]);
  }
  
  // For overlapping intervals
  while(current_index < max_index && intervals[current_index][0] <= new_interval[1]) {
    new_interval[0] = std::min(intervals[1][0], new_interval[0]);
    new_interval[1] = std::max(intervals[1][1], new_interval[1]);
    ++current_index;
  }
  output.push_back(new_interval);
  
  // For the remaining non-overlapping intervals
  while(current_index < max_index) {
    output.push_back(intervals[current_index++]);
  }
  
  return output;
}
void invoke_insert_interval() {
  std::vector<std::vector<int>> intervals = {
    {1,2},{3,5},{6,7},{8,10},{12,16}
  };
  std::vector<int> new_interval = {4,8};
  auto output = insert_interval(intervals, new_interval);
  std::cout<<"57. Insert Interval: [";
  for(auto& interval_range: output) {
    std::cout<<"{";
    for(auto& value: interval_range) {
      std::cout<<value<<", ";
    }
    std::cout<<"}, ";
  }
  std::cout<<"]";
}

/*
Input: [100, 10, 1, 10, 10, 100] => 210
Process:
  *        *      *
 [100, 10, 1, 10, 100]
 
Input: [1, 10, 1, 5, 2, 100, 400] => 415
Process:
  C
     *      *          *
  0  1   2  3  4  5    6
 [1, 10, 1, 5, 2, 100, 400]
Using iterative approach
 value = max(input[index] + cache[index + 2], cache[index + 1])
 cache (DP table):
  0  1  2  3  4  5  6    7
 [0, 0, 0, 0, 0, 0, 400, 0]
 [0, 0, 0, 0, 0, 400, 400, 0]
 [0, 0, 0, 0, 402, 400, 400, 0]
 [0, 0, 0, 405, 402, 400, 400, 0]
 [0, 0, 405, 405, 402, 400, 400, 0]
 [0, 415, 405, 405, 402, 400, 400, 0]
 [415, 415, 405, 405, 402, 400, 400, 0]
   ^answer
 
Using iterative approach and O(1) space:
 rob_next: 400
 rob_alternate_next: 100,
 max: max(C + P, N)
                  C    N     P
               C  N    P
     *      *          *
  0  1   2  3  4  5    6     0
 [1, 10, 1, 5, 2, 100, 400]
*/
// Using recursion
int house_robber(int index, std::vector<int>& houses, std::vector<int>& cache) {
  if(index >= houses.size()) {
    return 0;
  }
  
  if(cache[index] != -1) {
    return cache[index];
  }
  
  int output = std::max(houses[index] + house_robber(index + 2, houses, cache),
                        house_robber(index + 1, houses, cache));
  cache[index] = output;
  
  return output;
}
int house_robber(std::vector<int>& houses) {
  int total_houses = houses.size();
  
  // Using DP
//  std::vector<int> cache(total_houses + 1);
//  cache[total_houses] = 0;
//  cache[total_houses - 1] = houses[total_houses - 1];
//  
//  for(int index = total_houses - 2; index >= 0; --index) {
//    cache[index] = std::max(houses[index] + cache[index + 2], cache[index + 1]);
//  }
//  
//  return cache[0];
  
  // Using constant space
  int rob_next = houses[total_houses - 1], rob_alternate_next = 0;
  
  for(int index = total_houses - 2; index >= 0; --index) {
    auto max_loot = std::max(houses[index] + rob_alternate_next, rob_next); // 402, 405
    rob_alternate_next = rob_next; // 400,
    rob_next = max_loot; // 400 + 2, 405
  }
  
  return rob_next;
}
void invoke_house_robber() {
  std::vector<int> houses = {1, 10, 1, 5, 2, 100, 400};
  
//  std::vector<int> cache(houses.size(), -1);
//  std::cout<<"198. House Robber: "<<house_robber(0, houses, cache);
  
  // Using iterative approach and DP
  std::cout<<"198. House Robber: "<<house_robber(houses);
}

/*
 coins: [1,2,5], amount: 11
 Output: 3 => 5 + 5 + 1

 1 1 1 1 1 1 1 1 1 1  <- 11
 2 2 2 2 2 1 <- 6
 5 5 1 <- 3
*/
// TLE
int coin_change(std::vector<int>& coins, int index,
  int number_of_coins, int64_t sum, int target) {

  if(index >= coins.size() || sum > target) {
    return 0;
  }

  if(sum == target) {
    return number_of_coins;
  }

  int min_coins = INT_MAX;
  for(int current_index = index; current_index < coins.size(); ++current_index) {
    int total_coins = coin_change(coins, current_index, number_of_coins + 1, sum + coins[current_index], target);
    if(total_coins > 0) {
      min_coins = std::min(min_coins, total_coins);
    }
  }

  return min_coins == INT_MAX ? -1 : min_coins;
}
void invoke_coin_change() {
  int amount = 11;
  std::vector<int> coins = {1,2,5};
  
//  std::cout<<"322. Coin Change: "<<coin_change(coins, 0, 0, 0, 11);
  
  /*
  DP BU approach
                 *
  index: 0 1  2  3  4  5  6  7  8  9  10 11
  dp:    0 12 12 12 12 12 12 12 12 12 12 12
  dp:    0 1  12 12 12 12 12 12 12 12 12 12
  dp:    0 1  1  12 12 12 12 12 12 12 12 12
  dp:    0 1  1  2  12 12 12 12 12 12 12 12
   ...
  */
  std::vector<int> table(amount + 1, amount + 1);
  table[0] = 0;
  for(int current_amount = 1; current_amount <= amount; ++current_amount) {
    for(auto& coin: coins) {
      if(coin <= current_amount) {
        table[current_amount] = std::min(table[current_amount], 1 + table[current_amount - coin]);
      }
    }
  }
  
  std::cout<<"322. Coin Change: "<<(table[amount] > amount ? -1 : table[amount]);
}

/*
Input: [10,9,2,5,3,7], Output: 3
            R
          L
 10 9 2 5 3 7
 1  1 1 2 2 3 (DP table)
 L < R: dp[i] = std::max(R, L + 1)
 
 Binary search to reduce RC
  C
 10 9 2 5 3 7 101 18
 0
 [10]
 [9]
 [2]
 [2,5]
 [2,3]
 [2,3,7]
 [2,3,7,101]

 0 1 2 3
 [2,3,7,101]

 [4,10,4,3,8,9]
 0 1  2 3 4 5
 4 10 4 3 8 9
 [4,10]

 [3,5,6,2,5,4,19,5,6,7,12]
 C
 3 5 6 2 5 4 19 5 6 7 12
 L   H
 0 1 2
 [2,5,6]
*/
int binary_search_longest_increasing_subsequence(std::vector<int>& nums, int number) {
  int low = 0, high = nums.size() - 1;
  while(low < high) {
    int median = (low + high) / 2; // 1
    if(nums[median] == number) {
      return median;
    }
    if(number < nums[median]) {
      high = median;
    } else {
      low = median + 1;
    }
  }

  return low;
}
int longest_increasing_subsequence(std::vector<int>& input) {
  // RC: O(n^2)
//  int max_subsequence = 1;
//  std::vector<int> table(input.size(), 1);
//  
//  for(int right = 1; right < input.size(); ++right) {
//    for(int left = 0; left < right; ++left) {
//      if(input[left] < input[right]) {
//        table[right] = std::max(table[left] + 1, table[right]);
//        max_subsequence = table[right];
//      }
//    }
//  }
//  return max_subsequence;
  
  std::vector<int> max_subsequence;
  max_subsequence.push_back(input[0]);

  for(int current = 1; current < input.size(); ++current) {
    int number = input[current];
    if(number > max_subsequence.back()) {
      max_subsequence.push_back(number);
    } else {
      int replace_index = binary_search_longest_increasing_subsequence(max_subsequence, number);
      max_subsequence[replace_index] = number;
    }
  }

  return max_subsequence.size();
}
void invoke_longest_increasing_subsequence() {
  std::vector<int> input = {3,5,6,2,5,4,19,5,6,7,12}; //{10,9,2,5,3,7};
  std::cout<<"300. Longest Increasing Subsequence: "<<longest_increasing_subsequence(input);
}

/*
Input: [[2],[3,4],[6,5,7],[4,1,8,3]]
 BU approach in-place
    2 => 2
   3 4 => 5 6
  6 5 7 => 9 8 12
 4 1 8 3 => 10 6 13 10

 BU approach by flipping triangle
 4 1 8 3 => 4 1 8 3
  6 5 7 => 7 6 10
   3 4 => 9 10
    2 => 11
*/
int triangle(std::vector<std::vector<int>>& triangle) {
  // BU approach by flipping triangle
  for(int row_index = triangle.size() - 2; row_index >= 0; --row_index) {
    for(int column_index = 0; column_index < triangle[row_index].size(); ++column_index) {
      triangle[row_index][column_index] += std::min(triangle[row_index + 1][column_index + 1],
        triangle[row_index + 1][column_index]);
    }
  }
  return triangle[0][0];
  
  // BU approach in-place
//  int output = triangle[0][0];
//  for(int row_index = 1; row_index < triangle.size(); ++row_index) {
//    int row_min_value = INT_MAX;
//    for(int column_index = 0; column_index < triangle[row_index].size(); ++column_index) {
//      // column == 0 first column and row == column last column else middle cells
//      if(column_index == 0) {
//        triangle[row_index][column_index] += triangle[row_index - 1][column_index];
//      } else if(row_index == column_index) {
//        triangle[row_index][column_index] += triangle[row_index - 1][column_index - 1];
//      } else {
//        triangle[row_index][column_index] += std::min(triangle[row_index - 1][column_index],
//          triangle[row_index - 1][column_index - 1]);
//      }
//
//      row_min_value = std::min(row_min_value, triangle[row_index][column_index]);
//    }
//    output = row_min_value;
//  }
//
//  return output;
}
void invoke_triangle() {
  std::vector<std::vector<int>> input = {
    {2},
    {3,4},
    {6,5,7},
    {4,1,8,3}
  };
  std::cout<<"120. Triangle: "<<triangle(input);
}

/*
Input: [2,-5,1,-4,3,-2], Output: abs(-5+1-4) = 8
 compute prefix sum, max prefix sum, min prefix sum
 answer: max prefix sum - min prefix sum
Process:
 
    *
 2 -5 1 -4 3 -2 => prefix: 2, max: , min:
 2 -5 1 -4 3 -2 => prefix: 2, max: , min:
*/
int maximum_absolute_sum_of_any_subarray(std::vector<int>& input) {
  int prefix_sum = 0, max_prefix_sum = 0, min_prefix_sum = 0;
  
  for(auto& number: input) {
    prefix_sum += number;
    
    max_prefix_sum = std::max(max_prefix_sum, prefix_sum);
    min_prefix_sum = std::min(min_prefix_sum, prefix_sum);
  }
  
  return max_prefix_sum - min_prefix_sum;
}
void invoke_maximum_absolute_sum_of_any_subarray() {
  std::vector<int> input = {2,-5,1,-4,3,-2};
  std::cout<<"1749. Maximum Absolute Sum of Any Subarray: "<<maximum_absolute_sum_of_any_subarray(input);
}

/*
Input:
 [0,0,0]
 [0,0,0] => 4
 [0,1,0]
 [0,0,0]*
Process:
            DP table     Final DP table
 [0,0,0]    [0,1,0,0]    [0,1,0,0]
 [0,0,0] => [0,0,0,0] => [0,1,1,1]
 [0,1,0]    [0,0,0,0]    [0,1,2,3]
 [0,0,0]*   [0,0,0,0]    [0,1,0,3]
            [0,0,0,0]    [0,1,1,4]
*/
int unique_paths_ii(std::vector<std::vector<int>>& input) {
  int rows = input.size(), columns = input[0].size();
  std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(columns + 1, 0));
  dp[0][1] = 1;
  
  for(int row = 1; row <= rows; ++row) {
    for(int column = 1; column <= columns; ++column) {
      if(!input[row - 1][column - 1]) {
        dp[row][column] = dp[row - 1][column] + dp[row][column - 1];
      }
    }
  }
  
  return dp[rows][columns];
}
void invoke_unique_paths_ii() {
  std::vector<std::vector<int>> input = {
    {0,0,0},
    {0,0,0},
    {0,1,0},
    {0,0,0}
  };
  std::cout<<"63. Unique Paths II: "<<unique_paths_ii(input);
}

/*
Input: (2,3)
2^3 = 2*2*2 => 8
1   1
2^1 2^0
2   1
2^2 * 2^1 => 8

Input: (2,-3)
2^-2 = 1/2^2 => 1/4 => 0.25

Input: (7,11)
7^11
11: 1011
3 2 1 0
1 0 1 1   1   0   1   1
          2^3 2^2 2^1 2^0
          8   4   2   1
          7^8     7^2 7^1 => 7^8 * 7^2 * 7
*/
double pow_x_n(double base, int power) {
  int output = 1.0;
  
  return output;
}
void invoke_pow_x_n() {
  std::cout<<"50. Pow(x, n): "<<pow_x_n(2, 3);
}

/*
Input: [[1,1],[2,2],[3,3]], Output: 3
 
Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]], Output: 4

Input: [[0,0],[1,-1],[1,1]], Output: 2
*/
int max_points_on_a_line(std::vector<std::vector<int>>& points) {
  int max_points = 0, total_points = points.size();
  if(total_points == 1) {
    return 1;
  }

  for(int first = 0; first < total_points - 1; ++first) {
    std::unordered_map<double, int> slope_count;
    for(int second = 0; second < total_points; ++second) {
      if(first == second) {
        continue;
      }
      auto y = points[second][1] - points[first][1];
      auto x = points[second][0] - points[first][0];
      auto angle = std::atan2(y, x);
      slope_count[angle]++;
      max_points = std::max(max_points, slope_count[angle] + 1);
    }
  }
  
  return max_points;
}
void invoke_max_points_on_a_line() {
  std::vector<std::vector<int>> points = {
//    {1,1},{2,2},{3,3}
    {1,1},{3,2},{5,3},{4,1},{2,3},{1,4}
  };
  std::cout<<"149. Max Points on a Line: "<<max_points_on_a_line(points);
}

/*
Input: [9,12,5,10,14,3,10], pivot = 10 => [9,5,3,10,10,12,14]

Input: [2,3,4,1,2,4,6,1,4,3], pivot: 4 => [2,3,1,2,1,3,4,4,4,6]
                  ri
li
2 3 1 2 0 0 0 0 0 6
0 0 0 0 0 0 0 0 0 0
L
                  R
*/
std::vector<int> parition_array_according_to_given_pivot(std::vector<int>& input) {
  std::vector<int> output(input.size(), 0);
  
  return output;
}
void invoke_parition_array_according_to_given_pivot() {
  std::vector<int> array = {2,3,4,1,2,4,6,1,4,3};
  auto output = parition_array_according_to_given_pivot(array);
}

/*
Input:        Output => 9
*               *
0 0 0 0 0     0 0 0 0 0 0
1 1 1 1 1 =>  0 0 0 0 0 0
1 1 1 1 1     0 1 1 1 1 1
0 1 1 1 1     0 1 2 2 2 2
              0 0 1 2 3 3
*/
int maximal_square(std::vector<std::vector<std::string>>& matrix) {
  int max_square = 0, total_rows = matrix.size(), total_columns = matrix[0].size();
  std::vector<std::vector<int>> dp(matrix.size() + 1, std::vector<int>(matrix[0].size() + 1, 0));
  for(int row = 1; row <= total_rows; ++row) {
    for(int column = 1; column <= total_columns; ++column) {
      if(matrix[row - 1][column - 1] == "1") {
        dp[row][column] = std::min(dp[row - 1][column],
          std::min(dp[row][column - 1], dp[row - 1][column - 1])) + 1;
        max_square = std::max(max_square, dp[row][column]);
      }
    }
  }
  
  return max_square * max_square;
}
void invoke_maximal_square() {
  std::vector<std::vector<std::string>> square = {
    {"0","0","0","0","0"},
    {"1","1","1","1","1"},
    {"1","1","1","1","1"},
    {"0","1","1","1","1"}
  };
  std::cout<<"221. Maximal Square: "<<maximal_square(square);
}

/*
Input: 5
                5
        1                  2
    1      2            1      2
  1   2    1   2       1  2      1
1  2   1   1          1
1
1+1+1+1+1
1+1+1+2
1+1+2+1
1+2+1+1
1+2+2
2+1+1+1
2+1+2
2+2+1

0 1 2 3 4 5
1 1 2 3 5 8*
*/
int climbing_stairs(int total_steps) {
  if(total_steps == 1) {
    return total_steps;
  }
  std::vector<int> dp(total_steps + 1, 0);
  dp[0] = 1, dp[1] = 1;
  for(int index = 2; index <= total_steps; ++index) {
    dp[index] = dp[index - 1] + dp[index - 2];
  }

  return dp[total_steps];
}

void invoke_climbing_stairs() {
  std::cout<<"70. Climbing Stairs: "<<climbing_stairs(5);
}

/*
Input: [3,3,5,0,0,3,1,4] => 6
       B   S B S => 3-0 + 4-1 => 6
 3 3 5 0 0 3 1 4
   0 2 0 0 3 0 3
 
Input: [7,1,5,3,6,4] => 7
   B S B S   => 5-1 + 6-3 => 7
 7 1 5 3 6 4
           <-Right profits
       *
 5 5 3 3 0 0
 0 0 4 4 5 5
     *
Left profits ->
 4+3 = 7
 
Using one-pass simulation:
   *
 3 5
 first_price:   MAX 3 3
 first_profit:  0   0 2
 second_price:  MAX 3 3
 second_profit: 0   0 2*
 
 first_price = MAX, second_price = MAX
 first_profit = 0, second_profit = 0
 
 first_price   = min(first_price, price)
 first_profit  = max(first_profit, price - first_price)
 second_price  = min(second_price, price - first_profit)
 second_profit = max(second_profit, price - second_price)
*/
int best_time_to_buy_and_sell_stock_iii(std::vector<int>& prices) {
  // Using one-pass simulation
  int first_price = INT_MAX, second_price = INT_MAX;
  int first_profit = 0, second_profit = 0;
  
  for(auto& price: prices) {
    first_price = std::min(first_price, price);
    first_profit = std::max(first_profit, price - first_price);
    
    second_price = std::min(second_price, price - first_profit);
    second_profit = std::max(second_profit, price - second_price);
  }
  return second_profit;
  
  // Using BU approach
//  int max_profit = 0;
//  
//  int total_prices = prices.size();
//  std::vector<int> left_profit(total_prices), right_profit(total_prices + 1);
//  int left_min = prices[0], right_max = prices[total_prices - 1];
//  
//  for(int index = 1; index < prices.size(); ++index) {
//    left_profit[index] = std::max(left_profit[index - 1], prices[index] - left_min);
//    left_min = std::min(left_min, prices[index]);
//    
//    auto right_index = total_prices - index - 1;
//    right_profit[right_index] = std::max(right_profit[right_index + 1], right_max - prices[right_index]);
//    right_max = std::max(right_max, prices[right_index]);
//  }
//  
//  for(int index = 1; index < total_prices; ++index) {
//    max_profit = std::max(max_profit, left_profit[index] + right_profit[index + 1]);
//  }
//  
//  return max_profit;
}
void invoke_best_time_to_buy_and_sell_stock_iii() {
  std::vector<int> prices = {7,1,5,3,6,4};// {3,3,5,0,0,3,1,4};
  std::cout<<"123. Best Time to Buy and Sell Stock III: "<<best_time_to_buy_and_sell_stock_iii(prices);
}

/*
Input: [2,3,6,5,0,3], k: 2 => 7
 B   S   B S => 7
 2 3 6 5 0 3
 *
 2 3 6 5 0 3
 cost:   M M M M
 profit: 0 0 0 0
*/
int best_time_to_buy_and_sell_stock_iv(std::vector<int> prices, int k) {
  int max_profit = 0;
  
  return max_profit;
}
void invoke_best_time_to_buy_and_sell_stock_iv() {
  std::vector<int> prices = {3,2,6,5,0,3};
  std::cout<<"123. Best Time to Buy and Sell Stock IV: "<<best_time_to_buy_and_sell_stock_iv(prices, 2);
}

/*
Input: [10,16],[2,8],[1,6],[7,12] => 2
 sort: {1, 6}, {2, 8}, {7, 12}, {10, 16}
 1   6
   2    8
       7   12
         10     16
 
Input: [1,2],[3,4],[5,6],[7,8] => 4
 1  2
      3  4
            5   6
                  7   8

Input: [1,2],[2,3],[3,4],[4,5] => 2
 1   2
     2    3
          3    4
               4    5
               *

Input: [1,6][2,3][4,6] => 2
 --------------------
 1                 6
      2    3
               4   6
 
Input: [1,6][2,3][4,6] => 2
 sort: x2 < y2 => {2, 3}, {1, 6}, {4, 6}
   2   3
 1            6
          4   6
*/
int min_number_of_arrows_to_burst_balloons(std::vector<int>& points) {
  int total_arrows = 1;
  
  return total_arrows;
}
void invoke_min_number_of_arrows_to_burst_balloons() {
}

/*
 live with < 2 live -> dies
 live 2 or 3 live -> lives
 live > 3 live -> dies
 dead with 3 live -> lives

Input: [0,1,0],[0,0,1],[1,1,1],[0,0,0]]
 0 1 0      0 1 0     0 0 0
 0 0 1      2 0 3     1 0 1
 1 1 1  =>  1 3 3 =>  0 1 1
 0 0 0      0 2 0     0 1 0
*/
void game_of_life(std::vector<std::vector<int>>& board) {
  
}
void invoke_game_of_life() {
  
}

/*
Input: [2,3,3,1]
Process: TD
 0 1 2 3
 2 3 3 1
       2     3     0 -> 5
     3         1   1 -> 4
   3               2 -> 3
  1                3 -> 1
 
Process: BU
     *
 0 1 2 3
 2 3 3 1
 single_step_cost: 2, 3
 double_step_cost: 3, 5
 step_cost:
     index
  2: 3 + min(2, 3) = 5
  single_step_cost = double_step_cost
  double_step_cost = step_cost
  3: 1 + min(3, 5) = 4*
*/
int min_cost_climbing_stairs_bu(std::vector<int>& cost) {
  int single_step_cost = cost[0], double_step_cost = cost[1];
  for(int index = 2; index < cost.size(); ++index) {
    int step_cost = cost[index] + std::min(single_step_cost, double_step_cost);
    single_step_cost = double_step_cost;
    double_step_cost = step_cost;
  }
  
  return std::min(single_step_cost, double_step_cost);
}
int min_cost_climbing_stairs_td(std::vector<int>& cost, int index, std::unordered_map<int, int>& cache) {
  if(index >= cost.size()) {
    return 0;
  }
  if(cache.contains(index)) {
    return cache[index];
  }
  
  int step_cost = cost[index] + std::min(min_cost_climbing_stairs_td(cost, index + 1, cache),
                                         min_cost_climbing_stairs_td(cost, index + 2, cache));
  cache[index] = step_cost;
  return step_cost;
}
void invoke_min_cost_climbing_stairs() {
  std::vector<int> prices = {2,3,3,1};
  std::unordered_map<int, int> cache;
//  auto min_cost = std::min(min_cost_climbing_stairs_td(prices, 0, cache),
//                           min_cost_climbing_stairs_td(prices, 1, cache));
  auto min_cost = min_cost_climbing_stairs_bu(prices);
  std::cout<<"746. Min Cost Climbing Stairs: "<<min_cost;
}

/*
Input: 1,3,2,3, k:1 => 8
 *
 0 1 2 3
 1 3 2 3
*/
long long count_subarrays_where_max_element_appears_at_least_k_times(std::vector<int>& input, int k) {
  long long output = 0;
  
  // RC: O(n^2) TLE
  int max_number = *std::max_element(input.begin(), input.end());

  for(int left = 0; left < input.size(); ++left) {
    int count = 0;
    if(input[left] == max_number) {
      ++count;
    }
    for(int right = left; right < input.size(); ++right) {
      if(left != right && input[right] == max_number) {
        ++count;
      }
      if(count >= k) {
        ++output;
      }
    }
  }
  
  return output;
}
void invoke_count_subarrays_where_max_element_appears_at_least_k_times() {
  std::vector<int> input = {1,3,2,3};
  int k = 1;
  std::cout<<"2962. Count Subarrays Where Max Element Appears at Least K Times: "
    <<count_subarrays_where_max_element_appears_at_least_k_times(input, k);
}

int nth_tribonacci_number(int number) {
  std::vector<int> dp(37 + 1);
  dp[0] = 0; dp[1] = 1; dp[2] = 1;
  int current = 3;
  while(current <= number) {
    dp[current] = dp[current - 1] + dp[current - 2] + dp[current - 3];
    ++current;
  }

  return dp[number];
}
void invoke_nth_tribonacci_number() {
  std::cout<<"1137. N-th Tribonacci Number: "<<nth_tribonacci_number(5);
}

/*
Input: [2,2,3,3,3,4] => 9
 2: 4
 3: 9
 4: 4

Input: [13,13,13,10,10,11,11,11,11,12,12,12,12,15] => 98
 10,10,11,11,11,11,12,12,12,12,13,13,13,15
    L  C  R
 10 11 12 13 15
 20 44 48 39 15

Input: [1,1,1,2,4,5,5,5,6]
 1: 3
 2: 2
 4: 4
 5: 15
 6: 6

Input: [3,4,2] => 6
  3: 3
  4: 4
  2: 2
 BU approach:
         *
 0 1 2 3 4 5
 0 0 2 3 6 0
         ^
*/
int delete_and_earn_bu(int max_number, std::unordered_map<int, int>& points) {
  std::vector<int> max_points(max_number + 1);
  max_points[1] = points.contains(1) ? points[1] : 0;
  for(int number = 2; number < max_points.size(); ++number) {
    int sum = points.contains(number) ? points[number] : 0;
    max_points[number] = std::max(max_points[number - 1], max_points[number - 2] + sum);
  }
  
  return max_points[max_number];
}
int delete_and_earn_td(int number, std::unordered_map<int, int>& points, std::unordered_map<int, int>& cache) {
  if(number == 0) {
    return 0;
  }
  if(number == 1) {
    return points.contains(1) ? points[1] : 0;
  }
  if(cache.contains(number)) {
    return cache[number];
  }
  
  int total_points = points.contains(number) ? points[number] : 0;
  cache[number] = std::max(delete_and_earn_td(number - 1, points, cache), delete_and_earn_td(number - 2, points, cache) + total_points);
  
  return cache[number];
}
void invoke_delete_and_earn() {
  std::vector<int> input = {1,1,1,2,4,5,5,5,6};
  std::unordered_map<int, int> points, cache;
  int max_number = 0;
  for(auto& number: input) {
    points[number] += number;
    max_number = std::max(max_number, number);
  }
//  std::cout<<"740. Delete and Earn: "<<delete_and_earn_td(max_number, points, cache);
  std::cout<<"740. Delete and Earn: "<<delete_and_earn_bu(max_number, points);
}

/*
Kahn's algorithm for topological sort:
 Source: https://leetcode.com/explore/learn/card/graph/623/kahns-algorithm-for-topological-sorting/3886/
A----->B
|   /^ |
|  /   |
\/--->\/
C      D
 => [A,C,B,D]
 
 [[1,0]] -> 2 => true
 0: 1

 [1,0],[0,1] -> 2 => false
 0 <-> 1
 0: 1
 1: 0

 [1,4],[2,4],[3,1],[3,2] -> 5 =>
 4 -> 1 -> 2 -> 3 -> 3
 4: 1
 4: 2
 1: 3
 2: 3

 [0,2],[1,2],[2,0]
 2: 0
 2: 1
 0: 2

 [1,0],[0,2],[2,1] -> 3 => false
 2 -> 0 -> 1 <- cycle
 adj   indegree
 0: 1  1
 2: 0  2
 1: 2  3

 [1,0],[2,1] -> 3 => true
 0 -> 1 -> 2
 adj   indegree
 0: 1  0
 1: 2  2 -> 1
       3
*/
bool course_schedule(std::vector<std::vector<int>> &prerequisites, int num_courses) {
  std::vector<int> indegree(num_courses);
  std::vector<std::vector<int>> adjacency_list(num_courses);
  
  int visited_nodes = 0;
  
  return num_courses == visited_nodes;
}
void invoke_course_schedule() {
  std::vector<std::vector<int>> prerequisites = {{1,0},{2,1}}; // {1,0},{0,2},{2,1}
  std::cout<<std::boolalpha<<"207. Course Schedule: "<<course_schedule(prerequisites, 3);
}

/*
 2, [1,0] => [0,1]

 4, [1,0],[2,0],[3,1],[3,2] => [0,2,1,3]
 adj         indegree
 0: 1,2      0
 1: 3        1 -> 0
 2: 3        1
             2

 4, [1,0],[2,1],[3,1],[3,2] => [0,1,2,3]
*/
std::vector<int> course_schedule_ii(int num_courses, std::vector<std::vector<int>>& prerequisites) {
  std::vector<int> output;
  
  return output;
}
void invoke_course_schedule_ii() {
  std::vector<std::vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
  std::cout<<"210. Course Schedule II: ";
  for(auto& value: course_schedule_ii(4, prerequisites)) {
    std::cout<<value<<", ";
  }
}

/*
 0  1  2  3  4  5
0 [-1,-1,-1,-1,-1,-1] <- [36 35 34 33 32 31]
1 [-1,-1,-1,-1,-1,-1] -> [25 26 27 28 29 30]
2 [-1,-1,-1,-1,-1,-1] <- [24 23 22 21 20 19]
3 [-1,35,-1,-1,13,-1] -> [13 14 15 16 17 18]
4 [-1,-1,-1,-1,-1,-1] <- [12 11 10  9  8  7]
5 [-1,15,-1,-1,-1,-1] -> [1  2   3  4  5  6]
*/
int snakes_and_ladders(std::vector<std::vector<int>>& board) {
  int num_rows = board.size();
  int label = 1;
  std::vector<std::pair<int, int>> cells(num_rows * num_rows + 1); // 37 cells
  
  std::vector<int> columns(board.size());
  std::iota(columns.begin(), columns.end(), 0); // 0,1,2,3,4,5
  
  for(int row_index = num_rows - 1; row_index >= 0; --row_index) {
    for(auto& column_index: columns) {
      cells[label++] = {row_index, column_index};
    }
    
    std::reverse(columns.begin(), columns.end());
  }
  
  std::vector<int> distance(num_rows * num_rows + 1, -1);
  distance[1] = 0;
  std::queue<int> queue;
  queue.push(1);
  
  while(!queue.empty()) {
    int current = queue.front();
    queue.pop();
  }
  
  return distance[num_rows * num_rows];
}
void invoke_snakes_and_ladders() {
  std::vector<std::vector<int>> board = {
    {-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,35,-1,-1,13,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,15,-1,-1,-1,-1}
  };
  std::cout<<"909. Snakes and Ladders: "<<snakes_and_ladders(board);
}

int maximium_difference_between_increasing_elements(std::vector<int>& input) {
  int max_diff = -1;

  int minimum = INT_MAX;
  for(int index = 1; index < input.size(); ++index) {
    minimum = std::min(minimum, std::min(input[index], input[index - 1]));
    auto diff = input[index] - minimum;
    if(diff >= 0) {
      max_diff = std::max(max_diff, diff);
    }
  }

  return max_diff == 0 ? -1 : max_diff;
}
void invoke_maximium_difference_between_increasing_elements() {
  std::vector<int> input = {1,5,2,10};
  std::cout<<"2016. Maximum Difference Between Increasing Elements: "<<maximium_difference_between_increasing_elements(input);
}

bool palindrome_number(int input) {
  if(input < 0) {
    return false;
  }

  int64_t new_number = 0, number = input;
  while(number) { // 121
    auto remainder = number % 10; // 1, 2, 1
    new_number = (new_number * 10) + remainder; // 1 => 12 => 121
    number /= 10; // 12, 1, 0
  }
  return new_number == input;
}
void invoke_palindrome_number() {
  std::cout<<std::boolalpha<<"9. Palindrome Number: "<<palindrome_number(121);
}

std::vector<int> plus_one(std::vector<int>& digits) {
  // Won't work on all the test cases when the input is too long because of integer overflow
  // std::vector<int> output;
  // unsigned long long number = 0;
  // for(auto& num: digits) {
  //   number = number * 10 + num;
  // }

  // number++;

  // while(number) {
  //   auto remainder = number % 10; // 4
  //   output.push_back(remainder);
  //   number /= 10;
  // }

  // std::reverse(output.begin(), output.end());
  // return output;

  /*
  1 2 9
    1
  1 2 0

  9 9 9
    1
  9 9 0
  1
  9 0 0
  1 0 0 0
  */
  int num_digits = digits.size();
  for(int index = num_digits - 1; index >= 0; index--) {
    if(digits[index] == 9) {
      digits[index] = 0;
    } else {
      digits[index]++;
      return digits;
    }
  }

  digits.insert(digits.begin(), 1);

  return digits;
}
void invoke_plus_one() {
  std::vector<int> digits = {4,3,2,1};
  std::cout<<"66. Plus One: {";
  for(auto& num: plus_one(digits)) {
    std::cout<<num<<", ";
  }
  std::cout<<"}";
}

/*
 1 3 4 5 6
 0 + 4 / 2 = 2

 1 3 5 6, target: 2
   *
 0 1 2 3
 1 3 5 6
 3 / 2 = 1
 1 / 2 = 0

 1 3 5 6, taraget: 7
 0 1 2 3
 1 3 5 6
 3 / 2 = 1
 (2 + 3) / 2 = 2
 3
*/
int search_insert_position_binary_search(std::vector<int>& nums, int low, int high, int target) {
  int median = (low + high) / 2;
  if(nums[median] == target) {
    return median;
  } else if(low == high) {
    if(nums[low] < target) {
      return low + 1;
    }

    return low;
  }

  if(nums[median] > target) {
    return binary_search(nums, low, median, target);
  }

  return binary_search(nums, median + 1, high, target);
}
void invoke_search_insert_position() {
  std::vector<int> input = {1,3,5,6};
  std::cout<<"35. Search Insert Position: "<<search_insert_position_binary_search(input, 0, input.size() - 1, 2);
}

void invoke_summary_ranges() {
  std::vector<int> input = {0,1,2,4,5,7};
  std::vector<std::string> output;

  for(int current_index = 0; current_index < input.size(); ++current_index) {
    int start = input[current_index];
    while(current_index + 1 < input.size() && input[current_index] + 1 == input[current_index + 1]) {
      ++current_index;
    }

    if(start != input[current_index]) {
      output.push_back(std::to_string(start) + "->" + std::to_string(input[current_index]));
    } else {
      output.push_back(std::to_string(start));
    }
  }

  std::cout<<"228. Summary Ranges: [";
  for(auto& number: output) {
    std::cout<<number<<",";
  }
  std::cout<<"]";
}

bool contains_duplicate_ii(std::vector<int>& input, int k) {
  std::unordered_map<int, int> map;
  for(int index = 0; index < input.size(); ++index) {
    if(map.contains(input[index]) && std::abs(index - map[input[index]]) <= k) {
      return true;
    }
    map[input[index]] = index;
  }
  
  return false;
}
void invoke_contains_duplicate_ii() {
  std::vector<int> input = {1,2,3,1};
  std::cout<<std::boolalpha<<"219. Contains Duplicate II: "<<contains_duplicate_ii(input, 3);
}

int sqrt_x(int x) {
  if(x < 2) {
    return x;
  }

  // Pocket calculator algorithm
  // long left = static_cast<long>(std::exp(0.5 * std::log(x))); // 1.162
  // long right = left + 1; // 2.162

  // return right * right > x ? left : right; // 4.32 > 2 ? 1 : 2

  int left = 2, right = x/2;
  while(left <= right) {
    int pivot = left + (right - left) / 2;
    long number = pivot * pivot;
    if(number > x) {
      right = pivot - 1;
    } else if(number < x) {
      left = pivot + 1;
    } else {
      return pivot;
    }
  }
  return right;
}
void invoke_sqrt_x() {
  std::cout<<"69. Sqrt(x): "<<sqrt_x(2);
}

/*
 [[1,2],[1,3],[3,4]] => 3
 1 -> 2
 1 ->   -> 3
           3 -> 4

 [[1,2],[2,3],[3,4],[1,2]] => 4
 1 -> 2
 1 -> 2
      2 -> 3
           3 -> 4

 [[1,2],[1,2],[1,2]] => 2
 1 -> 2 => +1
 1 -> 2 => +1
 1 -> 2 X

 [[1,2],[2,2],[3,3],[3,4],[3,4]] => 4
 1 -> 2
      2 <=>
        -> 3 -> 3
           3 -> 4
           3 -> 4

 [[1,1],[1,2],[2,3]] => 3
 1 <->
 1 -> 2
      2 -> 3

 [[1,1],[2,3],[8,8],[8,9]] => 4
 1 -> 1
      2 -> 3
           8 <->
           8 -> 9

 [[1,4],[2,4],[3,4],[4,4]] => 4
*/
int maximium_number_of_events_that_can_be_attended(std::vector<std::vector<int>>& events) {
  int max_events = 0, total_events = events.size();
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  
  std::sort(events.begin(), events.end());
  
  int max_day = 0;
  for(auto& event: events) {
    max_day = std::max(max_day, event[1]);
  }
  
  for(int start = 0, end = 0; start <= max_day; ++start) { // start: 2, end: 2
    while(end < total_events && events[end][0] <= start) { //
      min_heap.push(events[end][1]); // 2 => 0 => 2 => 0
      ++end; // 2
    }
    while(!min_heap.empty() && min_heap.top() < start) {
      min_heap.pop();
    }
    if(!min_heap.empty()) {
      ++max_events;
      min_heap.pop();
    }
  }
  
  return max_events;
}
void invoke_maximium_number_of_events_that_can_be_attended() {
  std::vector<std::vector<int>> events = {
    {1,2}, {1,2}, {1,2} // 2
//    {1,1}, {2,3}, {8,8}, {8,8} // 3
//    {1,2},{2,2},{3,3},{3,4},{3,4} // 4
  };
  std::cout<<"1353. Maximum Number of Events That Can Be Attended: "<<maximium_number_of_events_that_can_be_attended(events);
}

/*
4,2,4,5,6 => 17 [2,4,5,6]
 prefix sum: 0 4 6 10 15 21

5,2,1,2,5,2,1,2,5 => 8 [5,2,1 or 1,2,5]
 prefix sum:
 5 2 1 2 5  2  1  2  5
 0 5 7 8 10 15 17 18 20 25
*/
int maximium_erasure_value(std::vector<int>& nums) {
  int max_subarray = 0, start_index = 0;
  std::unordered_map<int, int> seen;
  std::vector<int> prefix_sum(nums.size() + 1);
  
  for(int index = 0; index < nums.size(); ++index) {
    int current_number = nums[index];
    
    prefix_sum[index + 1] = prefix_sum[index] + current_number;
    
    if(seen.contains(current_number)) {
      start_index = std::max(start_index, seen[current_number] + 1);
    }
    
    max_subarray = std::max(max_subarray, prefix_sum[index + 1] - prefix_sum[start_index]);
    seen[current_number] = index;
  }
  
  return max_subarray;
}
void invoke_maximium_erasure_value() {
  std::vector<int> nums = {5,2,1,2,5,2,1,2,5};
  std::cout<<"1695. Maximum Erasure Value:: "<<maximium_erasure_value(nums);
}

std::vector<std::vector<int>> pascals_triangle(int total_rows) {
  std::vector<std::vector<int>> output;

  for(int row = 0; row < total_rows; ++row) {
    int column = 0;
    std::vector<int> columns;
    while(column <= row) {
      // Edges
      if(column == 0 || column == row) {
        columns.push_back(1);
      } else {
        columns.push_back(output[row - 1][column - 1] + output[row - 1][column]);
      }
      ++column;
    }
    output.push_back(columns);
  }

  return output;
}
void invoke_pascals_triangle() {
  auto rows = pascals_triangle(5);
  std::cout<<"118. Pascal's Triangle: [";
  for(auto& row: rows) {
    std::cout<<"[";
    for(auto& column: row) {
      std::cout<<column<<", ";
    }
    std::cout<<"], ";
  }
  std::cout<<"]";
}
