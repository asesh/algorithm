//
//  string_algorithm.cpp
//  algorithm
//
//  Created by Asesh Shrestha on 09/09/2021.
//  Copyright © 2021 Asesh Shrestha. All rights reserved.
//

#include "header.h"
#include "string.hpp"
#include "trie.hpp"

/*
 1 2 3 4 5
 1 2 3 | 4 5
 1 | 2
 */
void split_and_print(int32_t input_array[], int32_t lower_index, int32_t higher_index) {
	if(lower_index < higher_index) {
		auto median = (lower_index + higher_index) / 2;
		split_and_print(input_array, lower_index, median);
		//		split_and_print(input_array, median + 1, higher_index);
		std::cout<<input_array[median]<<" ";
	}
}

/*
Problem:
input: abcabcbb
characters: abc
output: 3
Solution:
 S
 E
 a b c a b c b b
 
 S-->E
 a b c a b c b b => 3
   S-->E
 a b c a b c b b => 3
     S-->E
 a b c a b c b b => 3
       S-->E
 a b c a b c b b => 3

input: ababca
Index: 01234
max: 	3
 
Input: pwwkew
max: 3
Solution:
 S
 E
 p w w k e w
 S E
 p w w k e w => 2
 S   E
 p w w k e w => 2
 */
int longest_substring_without_repeating_characters(const std::string& input) {
  int max_substring = 0;
  std::unordered_map<char, int> char_map;
  
  // RC: O(n) SC: O(k)
  int start = 0, end = 0;
  while(end < input.size()) {
    char_map[input[end]] += 1;
    while(char_map[input[end]] > 1) {
      char_map[input[start]] -= 1;
      ++start;
    }
    
    max_substring = std::max(max_substring, end - start + 1);
    ++end;
  }
  
  // RC: O(n^2), SC:O(k)
//  for(int index = 0; index < input.size(); ++index) {
//    int length = 0;
//    int window = index;
//    while(window < input.size()) {
//      if(!char_set.contains(input[window])) {
//        ++length;
//        char_set.insert(input[window]);
//        max_substring = std::max(max_substring, length);
//      } else {
//        char_set.clear();
//        length = 0;
//        break;
//      }
//      ++window;
//    }
//  }
	
	return max_substring;
}

void invoke_longest_substring_without_repeating_characters() {
	std::string input_string = "pwwkew";
	std::cout 
    << "Longest substring without repeating characters: "
    <<longest_substring_without_repeating_characters(input_string) << std::endl;
}

// https://leetcode.com/discuss/interview-question/351783/
// Given a string, what is the minimum number of adjacent swaps required to convert a string into a palindrome. If not possible, return -1.
/*
 Input: mamad: maamd -> maadm -> madam
 Output: 3
 
 Input: damam:
 Output:
 
 Input: damam: admam -> amdam -> madam
 Output: 3
 
 Input: initn:
 Output:
 
 Input: asflkj
 Output: -1
 
 Input: aabb: abab -> abba
 Output: 2
 */

bool can_string_be_palindromic(const std::string& input_string) {
	bool is_even = input_string.length() % 2 == 0 ? false : true;
	if(is_even) {
	} else {
	}
	
	return true;
}
// Checks if the input string is palindrome
bool is_palindrome(const std::string& input_string) {
	size_t offset = input_string.length() - 1;
	for(size_t index = 0; index  <= (input_string.length() - 1) / 2; index++, offset--) {
		if(input_string[index] == input_string[offset]) {
			continue;
		}
		
		return false;
	}
	
	return true;
}
int min_adjancent_swaps_for_palindromic_string(const std::string& input_string) {
	int total_swaps = 0;
	if(input_string.length() < 1) {
		return -1;
	}
	// Initial validation
	if(input_string.length() == 1) {
		return 1;
	}
	if(is_palindrome(input_string)) {
		return 0;
	}
	
	// The input string is not a palindrome
	
	return -1;
}

/*
 767: Reorganize string
 https://leetcode.com/problems/reorganize-string/
 
 Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
 Return any possible rearrangement of s or return "" if not possible.
 */
std::string reorganize_string(const std::string& input_string) {
	/*
	 Input: aabb -> abab / baba
	 
	 Input: aab -> aba
	 
	 
	 Input: bbacce -> abcbce
	 Input: aaccbb -> acbacb / abacbc
	 Input: aaab -> ""
	 
	 Input: aaabcc -> acbaca -> acbaca
	 Solution: a | 3 | 2 | 1 | 0
	 c | 2 | 1 | 0
	 b | 1 | 0 |
	 
	 Input: aabcc -> abcac
	 */
	std::map<char, int32_t> character_map;
	
	// Insert the characters and their count in a hashmap
	return "";
}

/*
Input: babad

Input: cbbd

Input: caeeeeaz

Input: aleveldefe
Index: 0123456789
Mid string: aleve ldefe
Type:  Even
*/
std::string longest_palindromic_substring(std::string& input) {
  std::string output = input.substr(0, 1);
  
  if(input.size() <= 1) {
    return input;
  }
  
  // Technique: Expand around the center
  // RC: O(n^2), SC: O(1)
  auto expand_around_the_center = [&](int low, int high) {
    while(low >= 0 && high < input.size() && input[low] == input[high]) {
      --low;
      ++high;
    }
    return input.substr(low + 1, high - low - 1) ;
  };
  
  for(int index = 0; index < input.size() - 1; ++index) {
    std::string odd_string = expand_around_the_center(index, index);
    std::string even_string = expand_around_the_center(index, index + 1);
    
    if(odd_string.size() > output.size()) {
      output = odd_string;
    }
    if(even_string.size() > output.size()) {
      output = even_string;
    }
  }
  
  // RC: O(n^3), SC: O(1)
//  auto is_palindrome = [&](std::string& input, int low, int high) {
//    while(low < high) {
//      if(input[low] != input[high]) {
//        return false;
//      }
//      ++low;
//      --high;
//    }
//    return true;
//  };
//  int max_length = 1;
//  for(int left = 0; left < input.size() - 1; ++left) {
//    for(int right = left + 1; right < input.size(); ++right) {
//      if((right - left) >= max_length && is_palindrome(input, left, right)) {
//        max_length = std::max(max_length, right - left + 1);
//        output = input.substr(left, right - left + 1);
//      }
//    }
//  }
  
  return output;
}
void invoke_longest_palindromic_substring() {
	std::string input_string = "babad";
	std::cout << "Longest palidromic substring: " << longest_palindromic_substring(input_string);
}

/*
 input one: aaka
 input two: akka
 */
bool is_anagram(const std::string& first_word, const std::string& second_word) {
  std::unordered_map<char, int> char_map;
  for(const auto& character: first_word) {
    char_map[character]++;
  }

  for(const auto& character: second_word) {
    char_map[character]--;
  }

  for(const auto& character: char_map) {
    if(character.second != 0) {
      return false;
    }
  }
  return true;
}
void invoke_is_anagram() {
  std::string first_word = "anagram", second_word = "nagaram";
  std::cout<<std::boolalpha<<is_anagram(first_word, second_word)<<std::endl;
}

// R: O(nm) S: O(min(n,m))
int levenshtein_distance(const std::string &first_word, const std::string& second_word) {
  // Space: O(mn)
  std::vector<std::vector<int>> edit_distance_table(first_word.size() + 1);

  // Runtime: O(mn)
  // Pre-populate the first-row and first-column of our table
  std::for_each(edit_distance_table.begin(), edit_distance_table.end(), 
                [number = 1, current_row = 0, second_word](std::vector<int> &row) mutable {
   if(current_row == 0) {
     // Construct first row
     for(int row_value = 0; row_value <= second_word.size(); ++row_value) {
       row.push_back(row_value);
     }
   } else {
     // Construct the first column
     row.reserve(second_word.size());
     for(int row_value = 0; row_value <= second_word.size(); ++row_value) {
       row.push_back(0);
     }
     row[0] = number++;
   }
   ++current_row;
  });

  // Runtime: O(mn)
  int row = 1, column = 1;
  for(const auto& from_char: first_word) {
   for(const auto& to_char: second_word) {
     if(from_char == to_char) {
       // Take the value of upper-left cell
       edit_distance_table[row][column] = edit_distance_table[row - 1][column - 1];
     } else {
       // Take the min. of three neighbors and add 1 to it
       edit_distance_table[row][column] = 1 + std::min(std::min(edit_distance_table[row - 1][column - 1],
         edit_distance_table[row - 1][column]), edit_distance_table[row][column - 1]);
     }
     ++column;
   }
   ++row;
   column = 1;
  }

  return edit_distance_table[first_word.size()][second_word.size()];
}
void invoke_levenshtein_distance() {
  std::cout<<"The number of edit operations required: "<<levenshtein_distance("abcdefghij", "1234567890")<<std::endl;
}

// T: O(wh), S(wh)
int river_sizes(std::vector<std::vector<int>>& input_matrix) {
  return 0;
}
void invoke_river_sizes() {
  // Output: 2, 2, 5, 1, 2
  std::vector<std::vector<int>> matrix = {
    {1, 0, 0, 1, 0},
    {1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 1, 1, 0}
  };
  
  std::cout<<"The river size is: "<<river_sizes(matrix)<<std::endl;
}

/*
Input: "1921680"
Output: ["1.9.216.80", "1.92.16.80", "1.92.168.0", "19.2.16.80", "19.2.168.0", "19.21.6.80", "19.21.68.0", "19.216.8.0", "192.1.6.80", "192.1.68.0", "192.16.8.0"]
*/
bool is_ip_valid(const std::string& ip) {
  if(ip.size() > 1 && ip[0] == '0') {
    return false;
  }
  
  auto ip_number = std::stoi(ip);
  if(ip_number > 255) {
    return false;
  }

  return true;
}

std::string get_merged_ips(const std::vector<std::string>& ip_parts) {
  std::string output;
  for(int index = 0; index < ip_parts.size(); ++index) {
    output.append(ip_parts[index]);
    if(index != ip_parts.size() - 1) {
      output.append(".");
    }
  }
  return output;
}
std::vector<std::string> valid_ip_address(const std::string& ip_addresses) {
  std::vector<std::string> output;

  int input_size = ip_addresses.size() - 1;

  for(int first = 0; first < input_size - 2; ++first) {
    auto first_ip = ip_addresses.substr(0, first + 1);
    if(!is_ip_valid(first_ip)) {
      continue;
    }
    // std::cout<<"First IP: "<<first_ip<<std::endl;
    
    for(int second = first + 1; second < input_size - 1; ++second) {
      auto second_ip = ip_addresses.substr(first + 1, second - first);
      if(!is_ip_valid(second_ip)) {
        continue;
      }
      // std::cout<<first_ip<<"."<<second_ip<<std::endl;

      for(int third = second + 1; third < input_size; ++third) {
        auto third_ip = ip_addresses.substr(second + 1, third - second);
        if(!is_ip_valid(third_ip)) {
          continue;
        }
        // std::cout<<first_ip<<"."<<second_ip<<"."<<third_ip<<std::endl;

        auto fourth_ip = ip_addresses.substr(third + 1, input_size - third);
        if(!is_ip_valid(fourth_ip)) {
          continue;
        }

        std::vector<std::string> ip = {first_ip, second_ip, third_ip, fourth_ip};
        output.push_back(get_merged_ips(ip));
        // std::cout<<first_ip<<"."<<second_ip<<"."<<third_ip<<"."<<fourth_ip<<std::endl;
      }
    }
  }

  return output;
}

// R: O(1) S: O(1)
void invoke_valid_ip_address() {
  auto valid_ip_addresses = valid_ip_address("1921680");
  std::cout<<"Valid IP addresses are: ";
  std::for_each(valid_ip_addresses.begin(), valid_ip_addresses.end(), [](std::string& valid_ip) {
    std::cout<<valid_ip<<", ";
  });
}

bool valid_palindrome(std::string s) {
  int backward_index = s.size() - 1;
  for(int forward_index = 0; forward_index < backward_index;) {
    if(!isalnum(s[forward_index])) {
      ++forward_index;
      continue;
    }
    if(!isalnum(s[backward_index])) {
      --backward_index;
      continue;
    }

    if(std::tolower(s[forward_index]) != std::tolower(s[backward_index])) {
      return false;
    }
    --backward_index;
    ++forward_index;
  }
  return true;
}
void invoke_valid_palindrome() {
  std::cout<<std::boolalpha<<valid_palindrome("A man, a plan, a canal: Panama")<<std::endl;
}

/*
a: abc
b: ahbgdc
 
a: axc
b: ahbgdc
*/
bool is_subsequence(std::string str1, std::string str2) {
  int first_index = 0;
  for(int second_index = 0; second_index < str2.size() && first_index < str1.size(); ++second_index) {
    if(str1[first_index] == str2[second_index]) {
      ++first_index;
      if(first_index == str1.size()) {
        return true;
      }
    }
  }
  return false;
}
void invoke_is_subsequence() {
  std::cout<<std::boolalpha<<is_subsequence("axc", "ahbgdc");
}

/*
012345678901234
the sky is blue
eulb si yks eht
blue is sky the
q
0         1         2
0123456789012345678901234567
  hello        world
    dlrow        olleh
dlrow olleh
world hello
*/
std::string reverse_words_in_a_string(std::string& input) {
  // Using stringstream
  //
//  std::string output, word;
//  std::vector<std::string> words;
//  std::stringstream stream(input);
//  while(stream >> word) {
//    words.push_back(word);
//  }
//  int current_index = words.size() - 1;
//  while(current_index >= 0) {
//    if(current_index != words.size() - 1) {
//      output += " ";
//    }
//    output += words[current_index];
//    --current_index;
//  }
  
  size_t first_offset = 0;
  std::string output = input;
  std::reverse(output.begin(), output.end()); // O(n)
  
  // O(n)
  for(int index = 0; index < input.size(); ++index) {
  }
  
  return output;
}
void invoke_reverse_words_in_a_string() {
  std::string input = "       hello    world   test!!    ";
  std::cout<<reverse_words_in_a_string(input)<<std::endl;
}

/*
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
cc -> c = 5
a -> a = 0
cc -> c = 3
b -> b = 0
cc

Input: a = 7, b = 7, c = 7
Output: "abcabcabcabcabcabcabc"

Pseudocode:
output = ""
max1, max2, max3
while(max1 >= 0) {
 
}
 
Input: a = 7, b = 1, c = 0
Output: "aabaa"
*/
std::string longest_happy_string(int a, int b, int c) {
  return "";
}
void invoke_longest_happy_string() {
  std::cout<<"Longest happy string: "<<longest_happy_string(1, 2, 3)<<std::endl;
}

/*
Input: "lee(t(c)o)de)"
Output: lee(t(c)o)de", "lee(t(co)de)", "lee(t(c)ode)"
 
Input: "a)b(c)d"
Output: "ab(c)d"
 
Input: "))(("
Output: ""
 
Input: "(a(b(c)d)"
Output: "a(b(c)d)"
 
Input: "())()((("
Output: "()()"
 
Input: ")i()()((fm(((()"
Output: "i()((fm)"
 
Overall RC: O(n) SC: O(n)
*/
std::string minimum_remove_to_make_valid_parenthesses(std::string& input) {
  std::string output;
  std::stack<int> stack_output; //
  std::vector<bool> exists(input.size()); //
  
  for(int index = 0; index < input.size(); ++index) {
    if(input[index] == '(') {
      stack_output.push(index);
    } else if(input[index] == ')') {
      if(!stack_output.empty()) {
        exists[index] = true;
        exists[stack_output.top()] = true;
        stack_output.pop();
      }
    } else {
      exists[index] = true;
    }
  }
  
  for(int index = 0; index < input.size(); ++index) {
    if(exists[index]) {
      output += input[index];
    }
  }
  
  return output;
}
void invoke_minimum_remove_to_make_valid_parenthesses() {
  std::string input = "(a(b(c)d)";
  std::cout<<"Minimum remove to make valid parentheses: "<<minimum_remove_to_make_valid_parenthesses(input)<<std::endl;
}

/*
Input: "1337c0d3"
Output: 1337
 
Input: "  -042"
Output: -42
*/
int string_to_integer(std::string& input) {
  int output = 0, sign = 1;
  int low = 0, high = input.size();
  
  while(low < high) {
    int element = input[low];
    if(element >= 0 && element <= 9) {
      if(low == high - 1) {
        output += element;
      } else {
        output += element * 10;
      }
    } else if(input[low] == '-') {
      sign *= -1;
    }
    ++low;
  }
  return output;
}
void invoke_string_to_integer() {
  std::string input = "42";
  std::cout<<"Converted string to integer: "<<string_to_integer(input)<<std::endl;
}

/*
Input: [2,3,1,2,4,3], Target: 7
Output: 2 => 4 + 3
Process:
 sort: 1 2 2 3 3 4
 L         R
 1 2 2 3 3 4

Input: [1,4,4], Target: 4
Output: 1
 
Input: [1,2,3,4,5], Target: 11
Output: 3
Process:
LR
 1 2 3 4 5
 L R
 1 2 3 4 5
 L   R
 1 2 3 4 5
 L     R
 1 2 3 4 5
 L       R
 1 2 3 4 5 ...
     L   R
 1 2 3 4 5
*/
int minimum_size_subarray_sum(std::vector<int>& input, int target) {
  int output = INT_MAX, sliding_sum = 0;
  int left = 0, right = 0;
  while(right < input.size()) {
    sliding_sum += input[right];
    while(sliding_sum > target) {
      if(sliding_sum >= target) {
        output = std::min(output, right - left + 1);
      }
      sliding_sum -= input[left];
      ++left;
    }
    if(sliding_sum >= target) {
      output = std::min(output, right - left + 1);
    }
    ++right;
  }
  
  return output == INT_MAX ? 0 : output;
}
void invoke_minimum_size_subarray_sum() {
  std::vector<int> input = {2,3,1,2,4,3};
  std::cout<<"Minimum size subarray sum: "<<minimum_size_subarray_sum(input, 7);
}

/*
Input: ["eat","tea","tan","ate","nat","bat"] Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Process: sort all the words: ["aet","aet","ant","aet","ant","abt"]
 map[string]string
 for word in input:
  current_word = word
  sort(word)
  map[word] = current_word
*/
std::vector<std::vector<std::string>> group_anagrams(std::vector<std::string>& input) {
  std::vector<std::vector<std::string>> output;
  
  std::unordered_map<std::string, std::vector<std::string>> key_value;
  for(auto& word: input) {
    auto current_word = word;
    std::sort(word.begin(), word.end());
    key_value[word].push_back(current_word);
  }
  
  for(auto& key: key_value) {
    output.push_back(key.second);
  }
  
  return output;
}
void invoke_group_anagrams() {
  std::vector<std::string> input = {
    "eat","tea","tan","ate","nat","bat"
  };
  auto output = group_anagrams(input);
  std::cout<<"The grouped anagrams are: ";
  std::for_each(output.begin(), output.end(), [](std::vector<std::string>& words) {
    std::cout<<"[";
    for(auto& word: words) {
      std::cout<<word<<", ";
    }
    std::cout<<"], ";
  });
}

/*
Input: Given below Output: true
Process:
 5 3 . . 7 . . . .
 6 . . 1 9 5 . . .
 . 9 8 . . . . 6 .
 8 . . . 6 . . . 3
*/
bool valid_sudoku(std::vector<std::vector<char>>& input) {
  int checkRow[9][9] = {}, checkColumn[9][9] = {}, checkSubBoxes[9][9] = {};
  for(int row = 0; row < 9; ++row) {
    for(int column = 0; column < 9; ++column) {
      if(input[row][column] != '.') {
        int targetColumn = input[row][column] - '0' - 1;
        int subBox = (row / 3) * 3 + (column / 3); // Index of sub-boxes
//        std::cout<<"Row: ("<<row<<", "<<number<<")\tColumn: ("<<column<<", "<<number<<")\tSubbox: ("<<subBox<<", "<<number<<")"<<std::endl;
        if(checkRow[row][targetColumn] || checkColumn[column][targetColumn] || checkSubBoxes[subBox][targetColumn]) {
          return false;
        }
        
        checkRow[row][targetColumn] = checkColumn[column][targetColumn] = checkSubBoxes[subBox][targetColumn] = 1;
//        std::cout<<"Row: "<<row<<", column: "<<column<<", number: "<<number<<", subBox: "<<subBox<<std::endl;
      }
    }
  }
  return true;
}
void invoke_valid_sudoku() {
  std::vector<std::vector<char>> input = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };
  std::cout<<"The validity of Sudoku: "<< std::boolalpha << valid_sudoku(input);
}

/*
Input: ["flower", "flow", "flight"], Output: "fl"
Process:
 sort: flight, flow, flower
 compare flight[i...] with flower[i...] until and unless they are equal
*/
std::string longest_common_prefx(std::vector<std::string>& input) {
  std::string output;
  std::sort(input.begin(), input.end());
  
  std::string first = input[0], last = input[input.size() - 1];
  for(int index = 0; index < std::min(first.size(), last.size()); ++index) {
    if(first[index] != last[index]) {
      return output;
    }
    
    output += first[index];
  }
  
  return output;
}
void invoke_longest_common_prefx() {
  std::vector<std::string> input = {"flower", "flow", "flight"}; // {"dog","racecar","car"}
  std::cout<<"The longest common prefix is: "<<longest_common_prefx(input);
}

/*
Input: 1, Output: ["()"]
Process:
       *
     /   \
    (     )
 base case: 2 * n return
 open < n:
  append('(')
  open++
 close < open:
  append(')')
  close++
 
Input: 2, Output: ["()()", "(())"]
Process:
       *
      (
   ((  ()
  (()   ()(
(())     ()()
*/
void generate_parentheses(std::vector<std::string>& output, std::string word, int number, int open, int close) {
  if(word.size() >= 2 * number) {
    output.push_back(word);
    return;
  }
  
  if(open < number) { // 0 < 2, 1 < 2,
    generate_parentheses(output, word + "(", number, open + 1, close); // (, 1, 0 /
  }
  if(close < open) { //
    generate_parentheses(output, word + ")", number, open, close + 1);
  }
}
void invoke_generate_parentheses() {
  std::vector<std::string> output;
  std::cout<<"Well-formed parentheses: ";
  generate_parentheses(output, "", 2, 0, 0);
  std::for_each(output.begin(), output.end(), [](std::string& word) {
    std::cout<<word<<", ";
  });
}

/*
Input: [              word: ["oath","pea","eat","rain"], Output: ["eat","oath"]
   ["o","a","a","n"],
   ["e","t","a","e"],
   ["i","h","k","r"],
   ["i","f","l","v"]
 ]
 
Input: [      words: ["abcb"], Output: []
   ["a","b"],
   ["c","d"]
 ]
*/
// Times out on leetcode
//bool word_search_ii(std::vector<std::vector<char>>&input, std::vector<std::vector<int>>& visited,
//                    std::string current_word, int current_index,
//                    int row, int column) {
//  while(row >= 0 && row < input.size() && column >= 0 && column < input[0].size()
//        && !visited[row][column]
//        && current_index < current_word.size()
//        && input[row][column] == current_word[current_index]) {
//    if(current_index == current_word.size() -1) {
//      return true;
//    }
//   
//    bool found = false;
//    visited[row][column] = true;
//    
//    if(word_search_ii(input, visited, current_word, current_index + 1, row, column - 1) // Left
//       || word_search_ii(input, visited, current_word, current_index + 1, row - 1, column) // Top
//       || word_search_ii(input, visited, current_word, current_index + 1, row, column + 1) // Right
//       || word_search_ii(input, visited, current_word, current_index + 1, row + 1, column)) { // Bottom
//      found = true;
//    }
//    
//    visited[row][column] = false;
//    return found;
//  }
//  
//  return false;
//}
void invoke_word_search_ii_trie(std::vector<std::vector<char>>& input, std::vector<std::string>& output,
                                CTrie* node, int row, int column) {
  if(row < 0 || row >= input.size() || column < 0 || column >= input[0].size() ||
     input[row][column] == '#' || !node->m_child[input[row][column] - 'a']) {
    return;
  }
  
  auto current_character = input[row][column];
  
  node = node->m_child[current_character - 'a']; // Next character node
  
  if(node->m_end) {
    output.push_back(node->m_current_word);
    node->m_end = false;
  }
  
  input[row][column]  = '#';
  
  invoke_word_search_ii_trie(input, output, node, row, column - 1); // Left
  invoke_word_search_ii_trie(input, output, node, row - 1, column); // Top
  invoke_word_search_ii_trie(input, output, node, row, column + 1); // Right
  invoke_word_search_ii_trie(input, output, node, row + 1, column); // Bottom
  
  input[row][column]  = current_character;
}
void invoke_word_search_ii() {
  std::vector<std::string> output;
  std::vector<std::string> words = {"a", "oath","pea","eat","rain","oeiifhtaaakl"};
  std::vector<std::vector<char>> input = {
//    {'a', 'a'}
    {'o','a','a','n'},
    {'e','t','a','e'},
    {'i','h','k','r'},
    {'i','f','l','v'}
  };
  
  // Times out on leetcode
//  std::vector<std::vector<int>> visited(input.size(), std::vector<int>(input[0].size(), false));
//  
//  for(auto& current_word: words) {
//    bool found = false;
//    for(int row = 0; row < input.size() && !found; ++row) {
//      for(int column = 0; column < input[0].size() && !found; ++column) {
//        if(input[row][column] == current_word[0]) {
//          found = word_search_ii(input, visited, current_word, 0, row, column);
//          if(found) {
//            output.push_back(current_word);
//          }
//        }
//      }
//    }
//  }
  
  CTrie* root = new CTrie();
  
  // Implementation using Trie
  //
  for(auto& word: words) {
    auto* node = root;
    node->insert(word);
  }
  auto* node = root;
  for(int row = 0; row < input.size(); ++row) {
    for(int column = 0; column < input[0].size(); ++column) {
      invoke_word_search_ii_trie(input, output, node, row, column);
    }
  }
  
  std::cout<<"Word search ii: ";
  std::for_each(output.begin(), output.end(), [](std::string word) {
    std::cout<<word<<", ";
  });
}

/*
Input: "(()", Output: 2
Process:
 0 1 2
 ( ( )
 
 0 1
 ( )
 
 0 1 2 3 4
 ( ) ( ( )
 stack: -1
 for(index in input): // 0,1,2,3,4
  top = stack.top() // -1,2,3
  if top != -1 and input[index] = ')' and input[top] = '(':
    stack.pop() // -1,2
    output = std::max(output, index - stack.top()) // 1-(-1)=2, 4-
  else:
    stack.push(index) // 0,2,3
 
Input: ")()())", Output: 4

Input: "()(()", Output: 2
*/
int longest_valid_parentheses(std::string& input) {
  int output = 0;
  std::stack<int> stack;
  stack.push(-1); // -1
  
  for(int index = 0; index < input.size(); ++index) { // 0,1,2
    int stack_top = stack.top(); // -1,0,1
    if(stack_top != -1 && input[index] == ')' && input[stack_top] == '(') { //
      stack.pop(); // -1,0
      output = std::max(output, index - stack.top()); // 2-0=2
    } else {
      stack.push(index); // 0,1,
    }
  }
  
  return output;
}
void invoke_longest_valid_parentheses() {
  std::string input = "()(()";
  std::cout<<"Longest valid parentheses: "<<longest_valid_parentheses(input);
}

/*
Input: "23", Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/
std::vector<std::string> letter_combination_of_a_phone_number(std::string& digits,
                                                              std::vector<std::string>& map) {
  if(digits.empty()) {
    return {};
  }
  
  std::vector<std::string> output = {""};
  
  for(auto& number: digits) { // 23
    std::vector<std::string> temp;
    for(auto& character: map[number - '0']) { // abc and def
      for(auto& another_character: output) {
        temp.push_back(another_character + character); // a b c => ad ae af...
      }
    }
    output.swap(temp); // a b c => ad ae af...
  }
  
  return output;
}
void invoke_letter_combination_of_a_phone_number() {
  std::string input = "23";
  std::vector<std::string> map = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
  };
  auto output = letter_combination_of_a_phone_number(input, map);
  std::cout<<"Letter combinations of a phone number: ";
  std::cout<<"[";
  for(auto& word: output) {
    std::cout<<word<<", ";
  }
  std::cout<<"]";
}

/*
Input: "/home/user/Documents/../Pictures"
Process:
 /
  home
    user
      Documents
        ..
          Pictures
 
Input: "/.../a/../b/c/../d/./"
Process:
  /
    ...
        a
          ..
            b
              c
                ..
                  d
                    .
*/
std::string simplify_path(std::string& input) {
  std::string output;
  std::vector<std::string> path_candidate;
  std::stringstream path_stream(input);
  std::string current_word;
  while(std::getline(path_stream, current_word, '/')) {
//    std::cout<<current_word<<std::endl;

    if(current_word.compare("..") == 0) {
      if(!path_candidate.empty()) {
        path_candidate.pop_back();
      }
    } else if(current_word.compare(".") != 0 && !current_word.empty()) {
      path_candidate.push_back(current_word);
    }
  }
  
  for(auto& word: path_candidate) {
//    std::cout<<word<<std::endl;
    output += "/" + word;
  }
  
  if(output.empty()) {
    return "/";
  }
  
  return output;
}
void invoke_simplify_path() {
  std::string input = /*"/home//foo/";*/ "/home/user/Documents/../Pictures";
  std::cout<<"Simplify path: "<<simplify_path(input);
}

/*
Input: [           , word: "ABCCED", Output: true
 ["A","B","C","E"],
 ["S","F","C","S"],
 ["A","D","E","E"]
 ]
*/
// Using DFS
bool word_search(std::vector<std::vector<char>>& input, std::string& word_to_search,
                 int row, int column, int search_offset) {
  if(word_to_search.size() == search_offset) {
    return true;
  }
  
  if(row < 0 || row >= input.size() || column < 0 ||
     column >= input[0].size() || input[row][column] == '#' ||
     input[row][column] != word_to_search[search_offset]) {
    return false;
  }
  
  auto current_char = input[row][column];
  
  input[row][column] = '#';
  bool found =
    word_search(input, word_to_search, row, column - 1, search_offset + 1) ||
    word_search(input, word_to_search, row - 1, column, search_offset + 1) ||
    word_search(input, word_to_search, row, column + 1, search_offset + 1) ||
    word_search(input, word_to_search, row + 1, column, search_offset + 1);
  
  input[row][column] = current_char;
  
  return found;
}
void invoke_word_search() {
  std::vector<std::vector<char>> input = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
//    {'A','B'},
//    {'C','D'},
  };
  std::string word_to_search = "ABCCEDF"; // "ABCCED";
  for(int row = 0; row < input.size(); ++row) {
    for(int column = 0; column < input[0].size(); ++column) {
      if(word_search(input, word_to_search, row, column, 0)) {
        std::cout<<std::boolalpha<<"Word search: "<<true;
      }
    }
  }
}
