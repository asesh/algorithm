//
//  string_algorithm.cpp
//  algorithm
//
//  Created by Asesh Shrestha on 09/09/2021.
//  Copyright © 2021 Asesh Shrestha. All rights reserved.
//

#include "header.h"
#include "string.hpp"

/*
 ABC
 ABC				BAC					CBA
 ABC ACB			BAC BCA			CBA CAB
 
 012			102				210
 012 021	102 120		210 201
 
 AB -> 2! = 2 * 1 = 2
 AB BA
 */
void permutation_of_string(std::string& input_string, int lower_index, int higher_index) {
}

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
 3. Longest substring without repeating characters
 https://leetcode.com/problems/longest-substring-without-repeating-characters/
 
 Problem:
 input: abcabcbb
 characters: abc
 output: 3
 
 input: ababca
 Imp:   **
 Index: 01234
 max: 	2
 */
int longest_substring_without_repeating_characters(const std::string& input_string) {
	// Implementation using sliding window
	std::unordered_set<char> unique_characters;
	int left_pointer = 0;
	int max = 0;
	
	for(int index = 0; index < input_string.length(); ++index) {
		// Check if this character is in the set
		if(unique_characters.find(input_string[index]) == unique_characters.end()) {
			// This character is not in the set
			// So insert the character and update the max count
			unique_characters.insert(input_string[index]);
			max = std::max(max, index - left_pointer + 1);
		} else {
			// This character already exists in the set
			// So remove the characters already in the set, increasing the left pointer
			while(left_pointer != index && input_string[index] != input_string[left_pointer]) {
				unique_characters.erase(input_string[left_pointer++]);
			}
			
			unique_characters.erase(input_string[left_pointer++]);
			unique_characters.insert(input_string[index]);
			max = std::max(max, index - left_pointer + 1);
		}
	}
	
	return max;
}

void invoke_longest_substring_without_repeating_characters() {
	std::string input_string = "pwwkew";
	std::cout << longest_substring_without_repeating_characters(input_string) << std::endl;
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
	for(const auto& input: input_string) {
	}
	return "";
}

/*
 https://leetcode.com/problems/longest-palindromic-substring/
 5. Longest Palindromic Substring
 */
std::string longest_palindromic_substring(const std::string& input_string) {
	/*
	 Input: babad
	 Type:	Odd
	 
	 Input: cbbd
	 
	 Input: caeeeeaz
	 
	 Input:	aleveldefe
	 Index: 0123456789
	 Mid:        |
	 Mid string: aleve ldefe
	 Type:	Even
	 */
	std::string longest_substring;
	
	// Input string is empty
	if(input_string.length() <= 1) {
		return input_string;
	}
	
	// Even case
	if(input_string.length() % 2 != 0) {
	} else {
		// odd case
	}
	
	return longest_substring;
}
void invoke_longest_palindromic_substring() {
	std::string input_string = "baad";
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
