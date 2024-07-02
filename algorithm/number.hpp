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

void calculate_minimum_coins(int target, const std::vector<int>& denoms, int coins_needed, int& min_coins, std::unordered_map<int, int>& computed_targets);
void invoke_calculate_minimum_coins();

int calculate_four_number_sum(int target, const std::vector<int>& array, int sum);
void invoke_calculate_four_number_sum();

void calculate_total_number_of_steps(int number_of_steps, int& total_number_of_steps, std::unordered_map<int, int>& computed_values);
void invoke_calculate_total_number_of_steps();

void invoke_calculate_minimum_number_of_steps();

void invoke_number_of_ways_to_traverse_graph();

void invoke_river_size();

void invoke_valid_starting_city();

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

/* https://leetcode.com/discuss/interview-question/5091692/FacebookMeta-MLSWE-Phone-Screenor-Pass-or-TLV-or-Random-pick-with-weight
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

void invoke_jump_game_ii();

/*
12. Integer to Roman https://leetcode.com/problems/integer-to-roman
*/
void invoke_integer_to_roman();

#endif /* NUMBER_HPP */
