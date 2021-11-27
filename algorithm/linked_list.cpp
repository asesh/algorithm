//
//  linked_list.cpp
//  algorithm
//
//  Created by Asesh Shrestha on 31/10/2021.
//  Copyright © 2021 Asesh Shrestha. All rights reserved.
//

#include "header.h"
#include "linked_list.h"

/*
 1 -> 2 -> 3 -> 4 -> 5
 
 Pseudocode:
 // Run time: O(n)
 // Space: O(n)
 for node in node_list {
	stack.push(node);
 }
 for stack_item in stack {
	final_linked_list.add(stack.pop());
 }
 
 */
void invoke_reverse_linked_list() {
	CSingleLinkedList<int> input_linked_list;
	input_linked_list.add_node(1);
	input_linked_list.add_node(2);
	input_linked_list.add_node(3);
	input_linked_list.add_node(4);
	input_linked_list.add_node(5);
	auto reversed_linked_list = reverse_linked_list(input_linked_list);
	reversed_linked_list.clear_nodes();
	input_linked_list.clear_nodes();
}
CSingleLinkedList<int>&& reverse_linked_list(const CSingleLinkedList<int>& input_linked_list) {
	CSingleLinkedList<int> final_linked_list;
	final_linked_list.add_node(100);
	return std::move(final_linked_list);
}
