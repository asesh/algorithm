//
//  number_algorithm. 
//  algorithm
//
//  Created by Asesh Shrestha on 09/09/2021.
//  Copyright © 2021 Asesh Shrestha. All rights reserved.
//

#ifndef NUMBER_HPP
#define NUMBER_HPP

void print_reverse(int input_array[], int index, int max_items);
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

/*
912. Sort an Array: https://leetcode.com/problems/sort-an-array
*/
void invoke_merge_sort();

/*
912. Sort an Array: https://leetcode.com/problems/sort-an-array
*/
void invoke_quick_sort();

/*
240. Search a 2D Matrix II: https://leetcode.com/problems/search-a-2d-matrix-ii
*/
void invoke_search_2d_matrix_ii();

/*
373. Find K Pairs with Smallest Sums: https://leetcode.com/problems/find-k-pairs-with-smallest-sums
*/
void invoke_find_k_pairs_with_smallest_sums();

/*
295. Find Median from Data Stream: https://leetcode.com/problems/find-median-from-data-stream
*/
void invoke_find_median_from_data_stream();

/*
560. Subarray Sum Equals K: https://leetcode.com/problems/subarray-sum-equals-k
*/
void invoke_subarray_sum_equals_k();

/*
146. LRU Cache: https://leetcode.com/problems/lru-cache
*/
void invoke_lru_cache();

/*
201. Bitwise AND of Numbers Range: https://leetcode.com/problems/bitwise-and-of-numbers-range
*/
void invoke_bitwise_and_of_numbers_range();

/*
191. Number of 1 Bits: https://leetcode.com/problems/number-of-1-bits
*/
void invoke_number_of_1_bits();

/*
150. Evaluate Reverse Polish Notation: https://leetcode.com/problems/evaluate-reverse-polish-notation
*/
void invoke_evaluate_reverse_polish_notation();

/*
2658. Maximum Number of Fish in a Grid: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid
*/
void invoke_maximum_number_of_fish_in_a_grid();

/*
153. Find Minimum in Rotated Sorted Array: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
*/
void invoke_find_minimum_in_rotated_sorted_array();

/*
130. Surrounded Regions: https://leetcode.com/problems/surrounded-regions
*/
void invoke_sorround_regions();

/*
57. Insert Interval: https://leetcode.com/problems/insert-interval
*/
void invoke_insert_interval();

/*
198. House Robber: https://leetcode.com/problems/house-robber
*/
void invoke_house_robber();

/*
322. Coin Change: https://leetcode.com/problems/coin-change
*/
void invoke_coin_change();

/*
300. Longest Increasing Subsequence: https://leetcode.com/problems/longest-increasing-subsequence/
*/
void invoke_longest_increasing_subsequence();

/*
120. Triangle: https://leetcode.com/problems/triangle
*/
void invoke_triangle();

/*
1749. Maximum Absolute Sum of Any Subarray: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray
*/
void invoke_maximum_absolute_sum_of_any_subarray();

/*
63. Unique Paths II: https://leetcode.com/problems/unique-paths-ii
*/
void invoke_unique_paths_ii();

/*
50. Pow(x, n): https://leetcode.com/problems/powx-n
*/
void invoke_pow_x_n();

/*
149. Max Points on a Line: https://leetcode.com/problems/max-points-on-a-line
*/
void invoke_max_points_on_a_line();

/*
2161. Partition Array According to Given Pivot: https://leetcode.com/problems/partition-array-according-to-given-pivot
*/
void invoke_parition_array_according_to_given_pivot();

/*
221. Maximal Square: https://leetcode.com/problems/maximal-square
*/
void invoke_maximal_square();

/*
70. Climbing Stairs: https://leetcode.com/problems/climbing-stairs
*/
void invoke_climbing_stairs();

/*
123. Best Time to Buy and Sell Stock III: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
*/
void invoke_best_time_to_buy_and_sell_stock_iii();

/*
188. Best Time to Buy and Sell Stock IV: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
*/
void invoke_best_time_to_buy_and_sell_stock_iv();

/*
452. Minimum Number of Arrows to Burst Balloons: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons
*/
void invoke_min_number_of_arrows_to_burst_balloons();

/*
289. Game of Life: https://leetcode.com/problems/game-of-life
*/
void invoke_game_of_life();

/*
746. Min Cost Climbing Stairs: https://leetcode.com/problems/min-cost-climbing-stairs
*/
void invoke_min_cost_climbing_stairs();

/*
2962. Count Subarrays Where Max Element Appears at Least K Times: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times
*/
void invoke_count_subarrays_where_max_element_appears_at_least_k_times();

/*
1137. N-th Tribonacci Number: https://leetcode.com/problems/n-th-tribonacci-number
*/
void invoke_nth_tribonacci_number();

/*
740. Delete and Earn: https://leetcode.com/problems/delete-and-earn
*/
void invoke_delete_and_earn();

/*
207. Course Schedule: https://leetcode.com/problems/course-schedule
*/
void invoke_course_schedule();

/*
210. Course Schedule II: https://leetcode.com/problems/course-schedule-ii
*/
void invoke_course_schedule_ii();

/*
909. Snakes and Ladders: https://leetcode.com/problems/snakes-and-ladders
*/
void invoke_snakes_and_ladders();

/*
2929. Distribute Candies Among Children II: https://leetcode.com/problems/distribute-candies-among-children-ii
*/
void invoke_distribute_candies_among_children_ii();

/*
2016. Maximum Difference Between Increasing Elements: https://leetcode.com/problems/maximum-difference-between-increasing-elements
*/
void invoke_maximium_difference_between_increasing_elements();

/*
9. Palindrome Number: https://leetcode.com/problems/palindrome-number
*/
void invoke_palindrome_number();

/*
66. Plus One: https://leetcode.com/problems/plus-one
*/
void invoke_plus_one();

/*
35. Search Insert Position: https://leetcode.com/problems/search-insert-position
*/
void invoke_search_insert_position();

/*
228. Summary Ranges: https://leetcode.com/problems/summary-ranges
*/
void invoke_summary_ranges();

/*
219. Contains Duplicate II: https://leetcode.com/problems/contains-duplicate-ii
*/
void invoke_contains_duplicate_ii();

/*
69. Sqrt(x): https://leetcode.com/problems/sqrtx
*/
void invoke_sqrt_x();

/*
1353. Maximum Number of Events That Can Be Attended: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended
*/
void invoke_maximium_number_of_events_that_can_be_attended();

/*
1695. Maximum Erasure Value: https://leetcode.com/problems/maximum-erasure-value
*/
void invoke_maximium_erasure_value();

/*
118. Pascal's Triangle: https://leetcode.com/problems/pascals-triangle
*/
void invoke_pascals_triangle();

#endif /* NUMBER_HPP */
