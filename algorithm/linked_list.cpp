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
 
 for i in max(item) {
 }
 
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
//  std::cout<< "Diff: " << max_value - min_value << std::endl;
  
  CSingleLinkedList<int>* current_node = nullptr;
  do {
    if(current_node) {
      std::cout<< current_node->get_value() << std::endl;
    }
    current_node = linked_list.next();
  } while(current_node);
}

/*
 H                   T
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

/*ListNode* add_two_linked_list_number(ListNode* l1, ListNode* l2) {
  ListNode* output = nullptr, *new_node = nullptr;
  int total = 0, val1 = 0, val2 = 0;
  int carry_over = 0;
  while(l1 || l2) {
    val1 = val2 = 0;
    if(l1) {
      val1 = l1->val;
      l1 = l1->next;
    }
    if(l2) {
      val2 = l2->val;
      l2 = l2->next;
    }
    auto sum = val1 + val2 + carry_over;
    carry_over = 0;
    if(sum >= 10) {
      carry_over = sum / 10;
      sum %= 10;
    }

    if(new_node) {
      if((!l1 || !l2)) {
        new_node->next = new ListNode(sum);
        if(!l1 && !l2 && carry_over != 0) {
          new_node->next->next = new ListNode(carry_over);
          break;
        }
      } else {
        new_node->next = new ListNode(sum);
      }
      new_node = new_node->next;
    } else {
      new_node = new ListNode(sum);
      if(!l1 && !l2 && carry_over != 0) {
        new_node->next = new ListNode(carry_over);
      }
      output = new_node;
    }
  }

  return output == nullptr ? new ListNode(0) : output;
}*/
void invoke_add_two_linked_list_numbers() {
  // Call the above method which was done on LeetCode.
  // We will have to modify the used linked list to run locally
//  add_two_linked_list_number(...);
}
