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

#include "binary_tree.hpp"

#include "linked_list.h"

//void sort_array(std::array<int, 7>& integer_array, int number_of_items);

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

template<typename DataType>
class CFoo {
	static_assert(std::is_pointer<DataType>::value, "DataType must be of integral type");
public:
};

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

// Merge sort
// input_array = {2, 1, 5, 4, 8, 9, 6, 3}
// lower_index = 0 = 2
// higher_index = 4 = 8
void merge_sort(int input_array[], int lower_index, int higher_index) {
	if(higher_index > lower_index) {
	}
}

#include <fstream>
#include <unistd.h>
#include <regex>
#include <vector>
/*
 Start (3,3,0)
 Target (185,189,45)
 Obstacle [30,200]x[0,50]
 Obstacle [0,100]x[54,100]
 Obstacle [120,200]x[50,100]
 Obstacle [0,116]x[80,100]
 Obstacle [30,200]x[120,140]
 Obstacle [30,50]x[100,115]
 */
// Will hold the 'Start' and 'Target' positions
struct Position {
	Position() {}
	Position(float x_coord, float y_coord, float z_coord) {
		x = x_coord;
		y = y_coord;
		z = z_coord;
	}
	float x=0.f, y=0.f, z=0.f;
};

// Will hold the points of obstacles
struct Point {
	Point() {}
	Point(float x_coord, float y_coord) {
		x = x_coord;
		y = y_coord;
	}
	float x = 0.f;
	float y = 0.f;
};

struct Obstacle {
	Obstacle() {}
	Obstacle(const Point& min, const Point& max) {
		min_point = min;
		max_point = max;
	}
	Point min_point;
	Point max_point;
};

// Will hold the coordinates given in the coordinates.txt file
struct Coordinates {
	Coordinates() {}
	Position start;
	Position target;
	std::vector<Obstacle> obstacles;
};

void get_vertex(const std::string& vertex_value, Position& position) {
	static std::regex vertex_regex(R"((\d+),(\d+),(\d+)\))");
	std::smatch match;
	if(std::regex_search(vertex_value.begin(), vertex_value.end(), match, vertex_regex)) {
		position = Position(std::stof(match[1]), std::stof(match[2]), std::stof(match[3]));
	}
}

void get_obstacle_bounds(const std::string& obstacle_value, std::vector<Obstacle>& obstacle) {
	static std::regex obstacle_regex(R"(\[(\d+),(\d+)\]x\[(\d+),(\d+)\])");
	std::smatch match;
	if(std::regex_search(obstacle_value.begin(), obstacle_value.end(), match, obstacle_regex)) {
		obstacle.push_back(Obstacle(Point(std::stof(match[1]), std::stof(match[2])), Point(std::stof(match[3]), std::stof(match[4]))));
	}
}

// Populate the coordinates from coordinates.txt file
bool populate_coordinates(Coordinates& coordinates) {
	// The file coordinates.txt should be in the same directory where the executable file of this code exists
	// Parse the file and store the vertices and points of needle and obstacles
	std::ifstream coordinates_text_file("/Users/aseshshrestha/Code/XCode Projects/algorithm/coordinates.txt");
	std::string key, value;
	if(coordinates_text_file.is_open()) {
		while(coordinates_text_file >> key >> value) {
			std::cout << "Key: " << key << ", value: " << value << std::endl;
			if(key == "Start") {
				get_vertex(value, coordinates.start);
			} else if(key == "Target") {
				get_vertex(value, coordinates.target);
			} else if(key == "Obstacle") {
				get_obstacle_bounds(value, coordinates.obstacles);
			}
		}
		coordinates_text_file.close();
	} else {
		std::cout <<"Failed to open coordinates.txt file. Pleaes make sure the file is in the same directory where this executable exists" << std::endl;
		return false;
	}
	return true;
}

int main(int argc, const char* argv[]) {
//	char path[200];
//	::getcwd(path, 200);
//	std::cout << path << std::endl;
	
	Coordinates coord;
	if(populate_coordinates(coord)) {
	}

	
	
	// Merge sort
//	int input_merge_sort_array[] = {2, 1, 5, 7, 6, 10, 8, 4, 3};
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
