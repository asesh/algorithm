//
//  linked_list.cpp
//  algorithm
//
//  Created by Asesh Shrestha on 31/10/2021.
//  Copyright © 2021 Asesh Shrestha. All rights reserved.
//

#include "header.h"
#include "linked_list.h"

void destroy_linkedlist(SLinkedList* head) {
  while(head) {
    auto* next = head->next;
    delete head;
    head = next;
  }
}

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
    current_node = linked_list.next;
  } while(current_node);
}

/*
 L    C    R
 1 -> 2 -> 3 -> 4 -> 5     =>      1 -> 4 -> 3 -> 2 -> 5
 L         C    R
 1 -> 3 -> 2 -> 4 -> 5
 1 -> 3 -> 4 -> 2 -> 5
 1 -> 4 -> 3 -> 2 -> 5
 
 L    C
 3 -> 5
 5 -> 3
 */
//void reverse_linked_list(ListNode* head, int left, int right) {
//  // Dummy node to handle cases where left = 1
//  ListNode* dummy_node = new ListNode(0);
//  dummy_node->next = head;
//  ListNode* left_node = dummy_node;
//
//  for(int counter = 0; counter < left - 1; ++counter) {
//    left_node = left_node->next;
//  }
//
//  ListNode* current_node = left_node->next;
//
//  for(int counter = 0; counter < right - left; ++counter) {
//    auto right_node = current_node->next; // 3
//    current_node->next = right_node->next; // 2 -> 4
//    right_node->next = left_node->next; // 3 -> 2
//    left_node->next = right_node; // 1 -> 3
//  }
//
//  return dummy_node->next;
//}
void invoke_reverse_linked_list() {
  // Modify the following function to use our own linked list wrapper instead
//  reverse_linked_list(head_node, 2, 4);
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

CSingleLinkedList<int>* sort_linked_list(CSingleLinkedList<int>* linked_list) {
  auto* head = linked_list;
  // Brute force approach
  //
  std::vector<int> list;
  while(head) {
    list.push_back(head->value);
    head = head->next;
  }
  
  std::sort(list.begin(), list.end());
  
  head = linked_list;
  for(auto& value: list) {
    head->value = value;
    head = head->next;
  }
  
  return linked_list;
}
void invoke_sort_linked_list() {
  CSingleLinkedList<int>* head = new CSingleLinkedList<int>({4,2,1,3});
  auto* output = sort_linked_list(head);
  std::cout<<"Sort list: ";
  while(output) {
    std::cout<<output->value<<"->";
    output = output->next;
  }
}

/*
Refer to Freeform: Remove Nth Node From End of List
*/
CSingleLinkedList<int>* remove_nth_node_from_end_of_list(CSingleLinkedList<int>* head, int nth_node) {
  CSingleLinkedList<int>* dummy = new CSingleLinkedList<int>(0);
  CSingleLinkedList<int>* first = dummy;
  CSingleLinkedList<int>* second = dummy;
  
  int counter = 0;
  while(counter++ < nth_node + 1) {
    first = first->next;
  }
  
  while(first) {
    first = first->next;
    second = second->next;
  }
  
  second->next = second->next->next;
  
  return dummy->next;
}
void invoke_remove_nth_node_from_end_of_list() {
  CSingleLinkedList<int>* head = new CSingleLinkedList<int>({1,2,3,4,5});
  auto* output_head = remove_nth_node_from_end_of_list(head, 2);
  std::cout<<"Remove Nth node from end of list: ";
  while(head) {
    std::cout<<head->value<<" -> ";
    head = head->next;
  }
  head->destroy();
}

/*
Refer to Freeform: 82. Remove Duplicates from Sorted List II
*/
CSingleLinkedList<int>* invoke_remove_duplicates_from_sorted_list_ii(CSingleLinkedList<int>* head) {
  CSingleLinkedList<int>* dummy = new CSingleLinkedList<int>(0);
  dummy->next = head;
  CSingleLinkedList<int>* first = dummy;
  first = first->next;
  CSingleLinkedList<int>* second = dummy;

  int current_node_value = INT_MIN;
  while(first && first->next) {
    while((first && first->value == current_node_value) ||
          (first && first->next && first->value == first->next->value)) {
      current_node_value = first->value; // 1
      first = first->next;
    }

    second->next = first;
    second = second->next;

    if(first) {
      current_node_value = first->value;
      first = first->next;
    }
  }

  return dummy->next;
}
void invoke_remove_duplicates_from_sorted_list_ii() {
  CSingleLinkedList<int>* head = new CSingleLinkedList<int>({1,2,2,3});
  auto* output = invoke_remove_duplicates_from_sorted_list_ii(head);
  std::cout<<"Remove duplicates from sorted list ii: ";
  while(output) {
    std::cout<<output->value<<"->";
    output = output->next;
  }
}

/*
Refer to Freeform: 61. Rotate List
*/
CSingleLinkedList<int>* rotate_list(CSingleLinkedList<int>* head, int rotate) {
  CSingleLinkedList<int>* dummy = new CSingleLinkedList<int>(-1);
  dummy->next = head;
  
  int nodes_count = 1;
  CSingleLinkedList<int>* right = head;
  while(right && right->next) {
    ++nodes_count;
    right = right->next;
  }

  int rotation = rotate % nodes_count;
  if(rotation == 0) {
    return head;
  }
  CSingleLinkedList<int>* middle = dummy;
  for(int count = 0; count < nodes_count - rotation; ++count) { // 1 <= 3
    middle = middle->next;
  }

  auto* left = dummy->next;
  dummy->next = middle->next;
  middle->next = nullptr;
  right->next = left;
  
  return dummy->next;
}
void invoke_rotate_list() {
  CSingleLinkedList<int>* head = new CSingleLinkedList<int>({1,2,3,4,5});
  auto* output = rotate_list(head, 2);
  std::cout<<"61. Rotate List: ";
  while(output) {
    std::cout<<output->value<<"->";
    output = output->next;
  }
}

/*
Input: [1,4,4,2,3,5], x: 3, Output: [1,2,4,4,3,5]
                           H
         *   *       *   R
     *           L
 * - 1 - 4 - 4 - 2 - 3 - 5
 x: 3
 Output: 1 - 2 - 4 - 4 - 3 - 5
*/
CSingleLinkedList<int>* partition_list(CSingleLinkedList<int>* head, int x) {
  CSingleLinkedList<int>* dummy_left = new CSingleLinkedList<int>(-1), *dummy_right = new CSingleLinkedList<int>(-1);
  CSingleLinkedList<int>* left = dummy_left, *right = dummy_right;
  
  while(head) {
    if(head->value < x) {
      left = left->next = head;
    } else {
      right = right->next = head;
    }
    
    head = head->next;
  }
  
  left->next = dummy_right->next;
  return dummy_left->next;
}
void invoke_partition_list() {
  CSingleLinkedList<int>* head = new CSingleLinkedList<int>({1,4,4,2,3,5});
  auto* output = partition_list(head, 3);
  std::cout<<"86. Partition List: ";
  while(output) {
    std::cout<<output->value<<" -> ";
    output = output->next;
  }
}

/*
Input: [1,null, 2,4, 3,2, 4,1]
 Process:
 key     value
 1,null  1
 2,4     2
 3,2     3
 4,1     4
*/
SLinkedList* copy_list_with_random_pointer(SLinkedList* head) {
  std::unordered_map<SLinkedList*, SLinkedList*> node_map;
  SLinkedList* node = head;
  while(node) {
    node_map[node] = new SLinkedList(node->value);
    node = node->next;
  }
  node = head;
  while(node) {
    node_map[node]->next = node_map[node->next];
    node_map[node]->random = node_map[node->random];
    node = node->next;
  }
  
  return node_map[head];
}
void invoke_copy_list_with_random_pointer() {
  SLinkedList* head = new SLinkedList(1);
  head->next = new SLinkedList(2);
  head->next->next = new SLinkedList(3);
  head->next->next->next = new SLinkedList(4);
  head->next->random = head->next->next->next;
  head->next->next->random = head->next->next;
  head->next->next->next->random = head->next;
  auto* output_node = copy_list_with_random_pointer(head);
  auto* copy_output_node = output_node;
  std::cout<<"138. Copy List with Random Pointer: ";
  while(output_node) {
    std::cout<<"("<<output_node->value<<",";
    if(output_node->random) {
      std::cout<<output_node->random->value;
    } else {
      std::cout<<"null";
    }
    std::cout<<") -> ";
    output_node = output_node->next;
  }
  while(copy_output_node) {
    auto* temp = copy_output_node;
    copy_output_node = copy_output_node->next;
    delete temp;
  }
}

/*
 first: 1-> 2-> 4, second: 1 -> 3 -> 4 => 1 -> 1 -> 2 -> 3 -> 4 -> 4
   F
 1 2 4
 S
 1 3 4
 => -1 -> 1
*/
SLinkedList* merge_two_sorted_lists(SLinkedList* first, SLinkedList* second) {
  SLinkedList* dummy = new SLinkedList(-1);
  SLinkedList* new_head = dummy;
  while(first || second) {
    if(first && second) {
      if(first->value <= second->value) {
        dummy->next = new SLinkedList(first->value);
        first = first->next;
      } else {
        dummy->next = new SLinkedList(second->value);
        second = second->next;
      }
    } else if(first && !second) {
      dummy->next = first;
      first = nullptr;
    } else {
      dummy->next = second;
      second = nullptr;
    }
    dummy = dummy->next;
  }
  return new_head->next;
}
void invoke_merge_two_sorted_lists() {
  SLinkedList* first = new SLinkedList(1);
  first->next = new SLinkedList(2);
  first->next->next = new SLinkedList(4);
  SLinkedList* second = new SLinkedList(1);
  second->next = new SLinkedList(3);
  second->next->next = new SLinkedList(4);
  std::cout<<"21. Merge Two Sorted Lists: "<<merge_two_sorted_lists(first, second);
}

/*
 3,2,0,-4 -> true
      S          F
 3 -> 2 -> 0 -> -4
      ^---------<|
*/
bool linked_list_cycle(SLinkedList* head) {
  if(!head) {
    return false;
  }

  SLinkedList* slow = head, *fast = head->next;
  while(slow && fast) {
    if(fast == slow) {
      return true;
    }

    slow = slow->next;
    fast = fast->next ? fast->next->next : fast->next;
  }
  return false;
}
void invoke_linked_list_cycle() {
  SLinkedList* head = new SLinkedList(3);
  head->next = new SLinkedList(2);
  head->next->next = new SLinkedList(0);
  head->next->next->next = new SLinkedList(4);
  head->next->next->next->next = head->next;
  std::cout<<std::boolalpha<<"141. Linked List Cycle: "<<linked_list_cycle(head);
  destroy_linkedlist(head);
}

/*
 [1,2,3,4,5], k = 2 => 2 -> 1 -> 4 -> 3 -> 5
 H    N
 1 -> 2 -> 3 -> 4 -> 5
 H    N
 2 -> 1 -> ...
 H                   N
 2 -> 1 -> 4 -> 3 -> 5

 [1,2,3,4,5,6,7,8], k = 4 => 4 -> 3 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5
 H    N
 1 -> 2 -> 3 -> 4
 H    N
 2 -> 1 -> 3 -> 4
 H         N
 3 -> 2 -> 1 -> 4
 H              N
 4 -> 3 -> 2 -> 1...
*/
SLinkedList* reverse_nodes_in_k_group_linkedlist(SLinkedList* head, int target_node_count) {
  auto* dummy = head; // 1
  SLinkedList* new_head = nullptr;
  
  while(target_node_count > 0) {
    /*
     h    n
     1 -> 2
     next = head->next; // 2
     new_head = next
     
     h    n
     1 -> 2 -> 3
     next = head->next;
    */
    auto* next = dummy->next; // 2
    new_head = next; // 2
    next = head; // 1
    new_head->next = next;
    
    --target_node_count;
  }
  
  return new_head;
}
SLinkedList* reverse_nodes_in_k_group(SLinkedList* head, int target_node_count) {
  SLinkedList* dummy = head;
  int node_count = 0;
  
  while(node_count < target_node_count && dummy) {
    dummy = dummy->next;
    ++node_count;
  }
  
  if(node_count == target_node_count) {
    SLinkedList* reversed_head = reverse_nodes_in_k_group_linkedlist(head, target_node_count);
    head->next = reverse_nodes_in_k_group(dummy, target_node_count);
    
    return reversed_head;
  }
  
  return head;
}
void invoke_reverse_nodes_in_k_group() {
  SLinkedList* head = new SLinkedList(1);
  head->next = new SLinkedList(2);
  head->next->next = new SLinkedList(3);
  head->next->next->next = new SLinkedList(4);
  head->next->next->next->next = new SLinkedList(5);
  SLinkedList* output = reverse_nodes_in_k_group(head, 2);
  auto* dummy = output;
  std::cout<<"25. Reverse Nodes in k-Group: ";
  while(dummy) {
    std::cout<<dummy->value<<" -> ";
    dummy = dummy->next;
  }
  destroy_linkedlist(output);
}

void test_linked_list() {
  SLinkedList* dummy = new SLinkedList(-1);
  
  SLinkedList* next = new SLinkedList(0);
  dummy->next = next;
  
  next->next = new SLinkedList(1);
  next->next->next = new SLinkedList(2);
  next->next->next->next = new SLinkedList(3);
  
  auto* node = dummy;
  while(node) {
    std::cout<<node->value;
    auto* temp = node;
    node = node->next;
    
    delete temp;
  }
}

/*
* <-> 1 <-> 2 <-> 3 <-> *
*/
void test_doubly_linked_list() {
  SDoublyLinkedList* dummy_head = new SDoublyLinkedList(-1);
  SDoublyLinkedList* dummy_tail = new SDoublyLinkedList(-1);
  dummy_head->next = dummy_tail;
  dummy_tail->previous = dummy_head;
  
//  SDoublyLinkedList* new_node = new SDoublyLinkedList(1);
//  new_node->previous = dummy_head;
//  dummy_head->next = new_node;
  
  while(dummy_head) {
    auto* head = dummy_head;
    dummy_head = dummy_head->next;
    delete head;
  }
}
