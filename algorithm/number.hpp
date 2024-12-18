//
//  number_algorithm.hpp
//  algorithm
//
//  Created by Asesh Shrestha on 09/09/2021.
//  Copyright © 2021 Asesh Shrestha. All rights reserved.
//

#ifndef NUMBER_HPP
#define NUMBER_HPP

void print_reverse(int input_array[], int index, int max_items);
void merge_sort(std::array<int, 6>, int lower_index, int higher_index);
bool is_number_palindrome(int number);
int get_max_sum_of_consecutive_numbers(int array[], int number_of_elements, int number_of_consecutive_elements);
std::pair<int, int> two_sum_equals_specific_target(const int* input_numbers, int number_of_elements, int target);
void high_to_low(int input_array[], int lower_index, int higher_index, int smaller_value = 0);
void binary_tree();

void invoke_binary_search();
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
 11. Container With Most Water: https://leetcode.com/problems/container-with-most-water/
*/
void invoke_container_with_most_water();

int sliding_window_max_sum_result(const std::vector<int>& input);
void invoke_sliding_window();

/*
724. Find Pivot Index: https://leetcode.com/problems/find-pivot-index/
*/
void invoke_find_pivot_index();

/*
15. 3Sum: https://leetcode.com/problems/3sum
*/
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

void calculate_minimum_coins(int target, const std::vector<int>& denoms, int coins_needed, int& min_coins, std::unordered_map<int, int>& computed_targets);
void invoke_calculate_minimum_coins();

int calculate_four_number_sum(int target, const std::vector<int>& array, int sum);
void invoke_calculate_four_number_sum();

void calculate_total_number_of_steps(int number_of_steps, int& total_number_of_steps, std::unordered_map<int, int>& computed_values);
void invoke_calculate_total_number_of_steps();

void invoke_calculate_minimum_number_of_steps();

void invoke_number_of_ways_to_traverse_graph();

void invoke_river_size();

void invoke_valid_palindrome_2();

class MinHeap {
 public:
  std::vector<int> heap;

  MinHeap(std::vector<int> vector) { heap = buildHeap(vector); }

  int get_parent_index(int current_node_index) {
    return (current_node_index - 1) / 2;
  }

  int get_left_child(int current_node_index) {
    return (2 * current_node_index) + 1;
  }

  int get_right_child(int current_node_index) {
    return (2 * current_node_index) + 2;
  }

  std::vector<int> buildHeap(std::vector<int>& vector) {
    for(int index = 0; index < vector.size(); ++index) {
      heap.push_back(vector[index]);	
      siftUp(index, vector);
    }
    return vector;
  }

  bool is_valid(int index) {
    return index < heap.size();
  }

  void siftDown(int currentIdx, int endIdx, std::vector<int>& heap) {
    for(int current_index = currentIdx; current_index < endIdx;) {
      auto left_child_index = get_left_child(current_index);
      auto right_child_index = get_right_child(current_index);

      if(!is_valid(left_child_index) && !is_valid(right_child_index)) {
        break;
      }
      
      if(is_valid(left_child_index) && is_valid(right_child_index)) {
        if(heap[left_child_index] <= heap[right_child_index]) {
          std::swap(heap[left_child_index], heap[current_index]);
          current_index = left_child_index;
        } else {
          std::swap(heap[right_child_index], heap[current_index]);
          current_index = right_child_index;
        }
      } else if(is_valid(left_child_index) &&
        heap[current_index] > heap[left_child_index]) {
        std::swap(heap[left_child_index], heap[current_index]);
        current_index = left_child_index;
      } else if(is_valid(right_child_index) &&
        heap[current_index] > heap[right_child_index]) {
        std::swap(heap[right_child_index], heap[current_index]);
        current_index = right_child_index;
      } else {
        ++current_index;
      }
    }
  }

  void siftUp(int currentIdx, std::vector<int>& heap) {
    for(int current_index = currentIdx; current_index < heap.size(); --current_index) {
      auto parent_index = get_parent_index(current_index);
      if(parent_index < 0) {
        continue;
      }
      
      if(heap[current_index] < heap[parent_index]) {
        std::swap(heap[current_index], heap[parent_index]);
      }
    }
  }

  int peek() {
    return heap[0];
  }

  int remove() {
    std::swap(heap[0], heap[heap.size() - 1]);
    auto last_item = heap.back();
    heap.pop_back();
    siftDown(0, heap.size() - 1, heap);
    for(auto item: heap) {
      std::cout<<item<<", ";
    }
    std::cout<<std::endl;
    return last_item;
  }

  void insert(int value) {
    if(heap.empty()) {
      heap.push_back(value);
    } else {
      heap[heap.size() - 1] = value;
    }
    siftUp(heap.size() - 1, heap);
  }
};

/*
 https://leetcode.com/discuss/interview-question/5091692/FacebookMeta-MLSWE-Phone-Screenor-Pass-or-TLV-or-Random-pick-with-weight
 */
void cut_cake_make_strawberries(std::vector<int> starwberries, int number_of_cuts);

void invoke_insertAndShiftNumbers();

/*
https://leetcode.com/problems/merge-sorted-array
*/
void invoke_merge_sorted_arrays();

/*
27. Remove Element: https://leetcode.com/problems/remove-element
*/
void invoke_remove_element();

/*
26. Remove Duplicates from Sorted Array https://leetcode.com/problems/remove-duplicates-from-sorted-array
*/
void invoke_remove_duplicates_from_sorted_array();


/*
80. Remove Duplicates from Sorted Array II: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
*/
void invoke_remove_duplicates_more_than_two();


/*
https://www.algoexpert.io/questions/four-number-sum
*/
void invoke_four_number_sum();

/*
189. https://leetcode.com/problems/rotate-array
*/
void invoke_rotate_array();

/*
7. Reverse Integer https://leetcode.com/problems/reverse-integer/description/
*/
void invoke_reverse_integer();

/*
4. Median of Two Sorted Arrays: https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 https://www.algoexpert.io/questions/median-of-two-sorted-arrays
*/
void invoke_median_of_two_sorted_arrays();

/*
122. Best Time to Buy and Sell Stock II https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
*/
void invoke_best_time_to_buy_and_sell_stock_ii();

/*
55. Jump Game https://leetcode.com/problems/jump-game
*/
void invoke_jump_game();

/*
45. Jump Game II https://leetcode.com/problems/jump-game-ii
*/
void invoke_jump_game_ii();

/*
12. Integer to Roman https://leetcode.com/problems/integer-to-roman
*/
void invoke_integer_to_roman();

/*
238. Product of Array Except Self https://leetcode.com/problems/product-of-array-except-self
*/
void invoke_product_of_array_except_itself();

/*
 215. Kth Largest Element in an Array https://leetcode.com/problems/kth-largest-element-in-an-array
*/
void invoke_kth_largest_element_in_an_array();

/*
6. Zigzag Conversion: https://leetcode.com/problems/zigzag-conversion/
*/
void invoke_zig_zag_conversion();

/*
42. Trapping Rain Water: https://leetcode.com/problems/trapping-rain-water
*/
void invoke_trapping_rain_water();

/*
73. invoke_set_matrix_zeroes: https://leetcode.com/problems/set-matrix-zeroes
*/
void invoke_set_matrix_zeroes();

/*
2938. Separate Black and White Balls: https://leetcode.com/problems/separate-black-and-white-balls
*/
void invoke_separate_black_and_white_balls();

/*
167. Two Sum II - Input Array Is Sorted
*/
void invoke_two_sum_ii();

/*
1. Two Sum: https://leetcode.com/problems/two-sum/
*/
void invoke_two_sum();

/*
48. Rotate Image: https://leetcode.com/problems/rotate-image
*/
void invoke_rotate_image();

/*
46. Permutations: https://leetcode.com/problems/permutations
*/
void invoke_permutations();

/*
64. Minimum Path Sum: https://leetcode.com/problems/minimum-path-sum
*/
void invoke_minimum_path_sum();

/*
54. Spiral Matrix: https://leetcode.com/problems/spiral-matrix
*/
void invoke_spiral_matrix();

/*
274. H-Index: https://leetcode.com/problems/h-index
*/
void invoke_h_index();

/*
137. Single Number II: https://leetcode.com/problems/single-number-ii
*/
void invoke_single_number_ii();

/*
67. Add Binary: https://leetcode.com/problems/add-binary
*/
void invoke_add_binary();

/*
134. Gas Station: https://leetcode.com/problems/gas-station
*/
void invoke_gas_station();

/*
135. Candy: https://leetcode.com/problems/candy
*/
void invoke_candy();

/*
128. Longest Consecutive Sequence: https://leetcode.com/problems/longest-consecutive-sequence
*/
void invoke_longest_consecutive_sequence();

/*
74. Search a 2D Matrix: https://leetcode.com/problems/search-a-2d-matrix
*/
void invoke_search_a_2d_matrix();

/*
162. Find Peak Element: https://leetcode.com/problems/find-peak-element
*/
void invoke_find_peak_element();

/*
39. Combination Sum: https://leetcode.com/problems/combination-sum
*/
void invoke_combination_sum();

/*
1975. Maximum Matrix Sum: https://leetcode.com/problems/maximum-matrix-sum
*/
void invoke_maximium_matrix_sum();

/*
155. Min Stack: https://leetcode.com/problems/min-stack
 */
class MinStack {
private:
  std::stack<int> m_stack;
  int m_min_element = INT_MAX;
public:
  void push(int value);
  void pop();
  int top();
  int get_min();
};
void invoke_min_stack();

/*
56. Merge Intervals: https://leetcode.com/problems/merge-intervals
*/
void invoke_merge_intervals();

/*
53. Maximum Subarray: https://leetcode.com/problems/maximum-subarray
*/
void invoke_maximium_subarray();

/*
918. Maximum Sum Circular Subarray: https://leetcode.com/problems/maximum-sum-circular-subarray
*/
void invoke_maximum_sum_circular_subarray();

/*
77. Combinations: https://leetcode.com/problems/combinations
*/
void invoke_combinations();

/*
52. N-Queens II: https://leetcode.com/problems/n-queens-ii
*/
void invoke_n_queens_ii();

/*
33. Search in Rotated Sorted Array: https://leetcode.com/problems/search-in-rotated-sorted-array
*/
void invoke_search_in_rotated_sorted_array();

/*
34. Find First and Last Position of Element in Sorted Array: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
*/
void invoke_find_first_and_last_position_of_element_in_sorted_array();

#endif /* NUMBER_HPP */
