//
//  linked_list_algorithm.cpp
//  algorithm
//
//  Created by Asesh Shrestha on 22/01/2022.
//  Copyright © 2022 Asesh Shrestha. All rights reserved.
//

#include "header.h"
#include "linked_list_algorithm.h"

/*
 61. Rotate List
 https://leetcode.com/problems/rotate-list/
 Example:
 1 -> 2 -> 3 -> 4 -> 5
 n = 5
 k = 2
 rotation = k % n = 2
 head_index = n - k = 3
 
 New index: [3 4 0 1 2]
 4 -> 5 -> 1 -> 2 -> 3
 
 k = 7
 rotation = k % n = 2
 4 -> 5 -> 1 -> 2 -> 3
 
 Naive approach:
 1: Iterate through all the nodes and insert them in a container -> O(n)
 2: We have a container holding all the nodes in a container which can be indexed
 
 */
void rotate_linked_list() {
	CSingleLinkedList<int> linked_list{1, 2, 3, 4, 5};
	int n = 5, k = 2;
	auto max_value = std::max(n, k);
	auto min_value = std::min(n, k);
//	std::cout<< "Diff: " << max_value - min_value << std::endl;
	
	CSingleLinkedList<int>* current_node = nullptr;
	do {
		if(current_node) {
			std::cout<< current_node->get_value() << std::endl;
		}
		current_node = linked_list.next();
	} while(current_node);
}

/*
 Head									Tail
 1 -> 2 -> 3 -> 4 -> 5
 
 5 -> 4 -> 3 -> 2 -> 1
 
 head_node = null
 current_node = root_node
 while(current_node) {
	next_node = current_node->next
	curent_node->head = head_node
	next_node->next = current_node
	current_node = next_node
 }
 */
void reverse_linked_list() {
	
}

/*
 2. Add Two Numbers
 https://leetcode.com/problems/add-two-numbers/
 
 2 -> 4 -> 3
 5 -> 6 -> 4
 Sum:
 7 -> 0 -> 8
 
 */
void add_two_numbers() {
	CLinkedList<int> head_linked_list{1, 2, 3, 4, 5};
	CLinkedList<int>* current_node = &head_linked_list;
//	CSingleLinkedList<int> final_linked_list{1, 2, 3, 4, 5};
//	CSingleLinkedList<int>* current_node = nullptr;
//	do {
//		current_node = final_linked_list.next();
//		std::cout<<current_node->m_data<< ", ";
//	} while(current_node);
}
