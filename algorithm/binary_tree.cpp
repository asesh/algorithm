////
////  binary_tree.cpp
////  consoleApp_1
////
////  Created by Asesh Shrestha on 1/25/20.
////  Copyright © 2020 Asesh Shrestha. All rights reserved.
////
//

#include "header.h"
//#include <array>
#include "binary_tree.hpp"
//
//

void invoke_binary_search_tree() {
	CBinarySearchTree<int> binary_search_tree(5);
//	binary_search_tree.insert({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
}

void invoke_binary_tree() {
  CBinaryTree<int32_t>* binary_tree = new CBinaryTree<int32_t>(1);
	// Fill left-subtree
	binary_tree->left = new CBinaryTree<int32_t>(2);
	binary_tree->left->left = new CBinaryTree<int32_t>(4);
	binary_tree->left->right = new CBinaryTree<int32_t>(5);
	binary_tree->left->left->left = new CBinaryTree<int32_t>(8);
	binary_tree->left->left->right = new CBinaryTree<int32_t>(9);
	binary_tree->left->right->left = new CBinaryTree<int32_t>(10);
	binary_tree->left->right->right = new CBinaryTree<int32_t>(11);
	
	// Fill right-subtree
	binary_tree->right = new CBinaryTree<int32_t>(3);
	binary_tree->right->left = new CBinaryTree<int32_t>(6);
	binary_tree->right->right = new CBinaryTree<int32_t>(7);
	binary_tree->right->left->left = new CBinaryTree<int32_t>(12);
	binary_tree->right->left->right = new CBinaryTree<int32_t>(13);
	binary_tree->right->right->left = new CBinaryTree<int32_t>(14);
	binary_tree->right->right->right = new CBinaryTree<int32_t>(15);
	binary_tree->right->right->right->right = new CBinaryTree<int32_t>(16);
	binary_tree->right->right->right->right->left = new CBinaryTree<int32_t>(17);
	
	//	binary_tree.traverse_bfs(&binary_tree);
	
	std::cout<<std::endl<<"Height of the tree: "<<binary_tree->get_height(binary_tree)<<std::endl;
	
	std::cout<<"Traversing in BFS:"<<std::endl;
	binary_tree->traverse_bfs();
	
	std::cout<<std::endl<<"Traversing in pre-order: "<<std::endl;
	binary_tree->traverse_preorder(binary_tree);
	
	std::cout<<std::endl<<std::endl<<"Traversing in in-order: "<<std::endl;
	binary_tree->traverse_inorder(binary_tree);
	
	std::cout<<std::endl<<std::endl<<"Traversing in post-order: "<<std::endl;
	binary_tree->traverse_postorder(binary_tree);
	
	std::cout<<std::endl<<std::endl<<"Traversing outer layer: "<<std::endl;
	binary_tree->print_outer_layer(binary_tree);
	
	std::cout<<std::endl<<std::endl<<"Removing all the nodes"<<std::endl;
	// Remove the left and right subtrees
	binary_tree->remove_subtree(binary_tree->left);
	binary_tree->remove_subtree(binary_tree->right);
	
	std::cout<<std::endl;
  destroy(binary_tree);
}

template<typename T>
int get_binary_tree_height(CBinaryTree<T>* node) {
  if(!node) {
    return 0;
  }
  
  int left_height = get_binary_tree_height(node->left) + 1;
  int right_height = get_binary_tree_height(node->right) + 1;
  return std::max(left_height, right_height);
}

template<typename T>
void right_side_view(CBinaryTree<T>* node, int level, std::vector<int>& output) {
  if(!node) {
    return;
  }
  
  if(level > output.size()) {
    output.push_back(node->value);
  }
  
  right_side_view(node->right, level + 1, output);
  right_side_view(node->left, level + 1, output);
}
void invoke_right_side_view() {
  std::vector<int> output;
  CBinaryTree<int32_t>* binary_tree = new CBinaryTree<int32_t>(1);
  binary_tree->left = new CBinaryTree<int32_t>(2);
  binary_tree->left->left = new CBinaryTree<int32_t>(4);
  binary_tree->right = new CBinaryTree<int32_t>(3);
  right_side_view(binary_tree, 1, output);
  std::cout<<"The right-side view: ";
  std::for_each(output.begin(), output.end(), [](int node_value) {
    std::cout<<node_value<<"->";
  });
  destroy(binary_tree);
}

/*
    3
   /  \
  9   20
     /  \
    15   7
 
RC: O(nh), SC: O(n+h)
*/
void level_order_traversal(CBinaryTree<int32_t>* node, int level, int actual_level, std::unordered_map<int, std::vector<int>>& value_map) {
  if(!node) {
    return;
  }
  
  if(level == 1) {
    value_map[actual_level].push_back(node->value);
  } else if(level > 1) {
    level_order_traversal(node->left, level - 1, actual_level, value_map);
    level_order_traversal(node->right, level - 1, actual_level, value_map);
  }
}
void invoke_level_order_traversal() {
  std::vector<std::vector<int>> output;
  std::unordered_map<int, std::vector<int>> value_map;
  CBinaryTree<int32_t>* binary_tree = new CBinaryTree<int32_t>(3);
  binary_tree->left = new CBinaryTree<int32_t>(9);
  binary_tree->right = new CBinaryTree<int32_t>(20);
  binary_tree->right->left = new CBinaryTree<int32_t>(15);
  binary_tree->right->right = new CBinaryTree<int32_t>(7);
  
  int tree_height = get_binary_tree_height(binary_tree);
  for(int level = 1; level <= tree_height; ++level) {
    level_order_traversal(binary_tree, level, level, value_map);
  }
  
  for(int level = 1; level <= tree_height; ++level) {
    output.push_back(value_map[level]);
  }
  
  std::cout<<"The level-order traversal: ";
  std::for_each(output.begin(), output.end(), [&](std::vector<int>& nodes) {
    for(auto& node: nodes) {
      std::cout<<node<<", ";
    }
    std::cout<<"; ";
  });
  destroy(binary_tree);
}

bool validate_binary_search_tree(CBinaryTree<int32_t>* root, CBinaryTree<int32_t>* left,
                                 CBinaryTree<int32_t>* right) {
  if(!root) {
    return true;
  }
  
  if(left && left->value >= root->value || right && right->value <= root->value) {
    return false;
  }
  
  return validate_binary_search_tree(root->left, left, root) &&
  validate_binary_search_tree(root->right, root, right);
}
void invoke_validate_binary_search_tree() {
  CBinaryTree<int32_t>* binary_tree = new CBinaryTree<int32_t>(5);
  binary_tree->left = new CBinaryTree<int32_t>(1);
  binary_tree->right = new CBinaryTree<int32_t>(4);
  binary_tree->right->left = new CBinaryTree<int32_t>(3);
  binary_tree->right->right = new CBinaryTree<int32_t>(6);
  std::cout<<std::boolalpha<<validate_binary_search_tree(binary_tree, nullptr, nullptr);
  destroy(binary_tree);
}

/*
Input: [4,2,5,null,3], k: 2, Output: 2
Process:
     4
  2     5
    3
*/
// RC: O(H + k), SC: O(H) using stack
int kth_smallest_element_in_a_bst(CBinaryTree<int32_t>* node, int kth_value) {
  std::stack<CBinaryTree<int32_t>*> node_stack;
  
  while(1) {
    while(node) {
      node_stack.push(node);
      node = node->left;
    }
    
    node = node_stack.top();
    node_stack.pop();
    if(--kth_value == 0) {
      return node->value;
    }
    
    node = node->right;
  }
}
// RC: O(n)
void kth_smallest_element_in_a_bst(CBinaryTree<int32_t>* node, std::vector<int>& nodes) {
  if(!node) {
    return;
  }
  
  kth_smallest_element_in_a_bst(node->left, nodes);
  nodes.push_back(node->value);
  kth_smallest_element_in_a_bst(node->right, nodes);
}
void invoke_kth_smallest_element_in_a_bst() {
  int kth_value = 2;
//  CBinaryTree<int32_t> binary_tree(5);
//  binary_tree.left = new CBinaryTree<int32_t>(3);
//  binary_tree.left->left = new CBinaryTree<int32_t>(2);
//  binary_tree.left->right = new CBinaryTree<int32_t>(4);
//  binary_tree.left->left->left = new CBinaryTree<int32_t>(1);
//  binary_tree.right = new CBinaryTree<int32_t>(6);
  CBinaryTree<int32_t>* binary_tree = new CBinaryTree<int32_t>(4);
  binary_tree->left = new CBinaryTree<int32_t>(2);
  binary_tree->left->right = new CBinaryTree<int32_t>(3);
  binary_tree->right = new CBinaryTree<int32_t>(5);
  
//  std::vector<int> nodes;
//  kth_smallest_element_in_a_bst(&binary_tree, nodes);
//  std::cout<<"Kth smallest element in a BST: "<<nodes[kth_value - 1];
  std::cout<<"Kth smallest element in a BST: "<<kth_smallest_element_in_a_bst(binary_tree, 3);
  destroy(binary_tree);
}

/*
Refer to the Freeform diagram

Input: preorder: [3,9,12,20,25,28,30], inorder: [9,12,3,28,25,20,30]
Process:
    Pi
 [3,9,12,20,25,28,30]
  L H
 [9,12,3,28,25,20,30]
 
 preorder index map: {
    9: 0
    12: 1
    3: 2
    28: 3
    25: 4
    20: 5
    30: 6
 }
*/
CBinaryTree<int>* construct_binary_tree_from_pre_and_inorder_traversal(std::vector<int>& preorder,
                                                                       int& preorder_index,
                                                                       std::unordered_map<int, int>& inorder_index_map,
                                                                       int left_index, int right_index) {
  if(left_index > right_index) {
    return nullptr;
  }
  
  int root_value = preorder[preorder_index++];
  CBinaryTree<int>* root = new CBinaryTree<int>(root_value);
  
  root->left = construct_binary_tree_from_pre_and_inorder_traversal(preorder, preorder_index, inorder_index_map,
                                                                    left_index, inorder_index_map[root_value] - 1);
  root->right = construct_binary_tree_from_pre_and_inorder_traversal(preorder, preorder_index, inorder_index_map,
                                                                     inorder_index_map[root_value] + 1, right_index);
  
  return root;
}
void invoke_construct_binary_tree_from_pre_and_inorder_traversal() {
  std::vector<int> preorder = {3,9,12,20,25,28,30};
  std::vector<int> inorder = {9,12,3,28,25,20,30};
  
  // 9: 0, 12: 1, 3: 2, 28: 3, 25: 4, 20: 5, 30: 6
  std::unordered_map<int, int> inorder_index_map;
  for(int index = 0; index < inorder.size(); ++index) {
    inorder_index_map[inorder[index]] = index;
  }
  
  int preorder_index = 0;
  auto* binary_tree = construct_binary_tree_from_pre_and_inorder_traversal(preorder, preorder_index, inorder_index_map,
                                                                           0, preorder.size() - 1);
  std::cout<<"105. Construct Binary Tree from Preorder and Inorder Traversal: ";
  binary_tree->traverse_preorder(binary_tree);
  destroy(binary_tree);
}

void sum_root_to_leaf_number(CBinaryTree<int32_t>* node, int current_sum, int& sum) {
  if(!node) {
    return;
  }
  
  current_sum = node->value + (current_sum * 10);
  if(!node->left && !node->right) {
    sum += current_sum;
  }
  
  sum_root_to_leaf_number(node->left, current_sum, sum);
  sum_root_to_leaf_number(node->right, current_sum, sum);
}
void invoke_sum_root_to_leaf_number() {
  int sum = 0;
  CBinaryTree<int32_t>* binary_tree = new CBinaryTree<int32_t>(4);
  binary_tree->left = new CBinaryTree<int32_t>(9);
  binary_tree->left->left = new CBinaryTree<int32_t>(5);
  binary_tree->left->right = new CBinaryTree<int32_t>(3);
  binary_tree->right = new CBinaryTree<int32_t>(0);
  sum_root_to_leaf_number(binary_tree, 0, sum);
  std::cout<<"Sum of root to leaf numbers: "<<sum;
  destroy(binary_tree);
}

/*
Refer to Freeform diagram: 114. Flatten Binary Tree to Linked List
*/
// RC: O(n), SC: O(n)
void flatten_binary_tree_to_linked_list_preorder_traversal(CBinaryTree<int32_t>* node,
                                                           std::vector<int>& node_values) {
  if(!node) {
    return;
  }
  
  node_values.push_back(node->value);
  
  flatten_binary_tree_to_linked_list_preorder_traversal(node->left, node_values);
  flatten_binary_tree_to_linked_list_preorder_traversal(node->right, node_values);
}
void flatten_binary_tree_to_linked_list(CBinaryTree<int32_t>* node) {
  std::vector<int> node_values;
  flatten_binary_tree_to_linked_list_preorder_traversal(node, node_values);
  
  for(int index = 0; index < node_values.size(); ++index) {
    (*node).value = node_values[index];
    node->left = nullptr;
    while(!node->right && index < node_values.size() - 1) {
      node->right = new CBinaryTree<int32_t>(node_values[++index]);
      node = node->right;
    }
    node = node->right;
  }
}
void invoke_flatten_binary_tree_to_linked_list() {
  CBinaryTree<int32_t>* binary_tree = new CBinaryTree<int32_t>(1);
  binary_tree->left = new CBinaryTree<int32_t>(2);
  binary_tree->left->left = new CBinaryTree<int32_t>(3);
  binary_tree->left->right = new CBinaryTree<int32_t>(4);
  binary_tree->right = new CBinaryTree<int32_t>(5);
  binary_tree->right->right = new CBinaryTree<int32_t>(6);
  flatten_binary_tree_to_linked_list(binary_tree);
  destroy(binary_tree);
}

/*
Refer to Freeform diagram: 106. Construct Binary Tree from Inorder and Postorder Traversal
Input: inorder = [4,5,3,7,6,8,9], postorder = [5,4,7,9,8,6,3]
Process
 Hash map from inorder: {
   4: 0
   5: 1
   3: 2
   7: 3
   6: 4
   8: 5
   9: 6
 }
              R
              L
  0 1 2 3 4 5 6
 [4,5,3,7,6,8,9]
 
        Pi
  0 1 2 3 4 5 6
 [5,4,7,9,8,6,3]
*/
CBinaryTree<int32_t>* construct_binary_tree_from_inorder_and_postorder_traversal(std::vector<int>& postorder,
                                                                                 int& postorder_index,
                                                                                 std::unordered_map<int, int>& inorder_map,
                                                                                 int left_index, int right_index) {
  if(left_index > right_index) {
    return nullptr;
  }
  
  int node_value = postorder[postorder_index--];
  CBinaryTree<int>* node = new CBinaryTree<int>(node_value);
  
  node->right = construct_binary_tree_from_inorder_and_postorder_traversal(postorder, postorder_index, inorder_map,
                                                                           inorder_map[node_value] + 1, right_index);
  node->left = construct_binary_tree_from_inorder_and_postorder_traversal(postorder, postorder_index, inorder_map,
                                                                          left_index, inorder_map[node_value] - 1);
  
  return node;
}
void invoke_construct_binary_tree_from_inorder_and_postorder_traversal() {
  std::vector<int> inorder = {4,5,3,7,6,8,9};
  std::vector<int> postorder = {5,4,7,9,8,6,3};
  
  std::unordered_map<int, int> inorder_map;
  for(int index = 0; index < inorder.size(); ++index) {
    inorder_map[inorder[index]] = index;
  }
  int postorder_index = postorder.size() - 1;
  auto* tree = construct_binary_tree_from_inorder_and_postorder_traversal(postorder, postorder_index, inorder_map, 0, postorder.size() - 1);
  std::cout<<"106. Construct Binary Tree from Inorder and Postorder Traversal: ";
  tree->traverse_preorder(tree);
  destroy(tree);
}

/*
Refer to Freeform: 236. Lowest Common Ancestor of a Binary Tree
*/
CBinaryTree<int32_t>* lowest_common_ancestor_binary_tree(CBinaryTree<int32_t>* root, CBinaryTree<int32_t>* p, CBinaryTree<int32_t>* q) {
  if(!root || root == p || root == q) {
    return root;
  }
  
  auto* left = lowest_common_ancestor_binary_tree(root->left, p, q);
  auto* right = lowest_common_ancestor_binary_tree(root->right, p, q);
  
  if(left && right) {
    return root;
  }
  
  return left ? left : right;
}
void invoke_lowest_common_ancestor_binary_tree() {
  CBinaryTree<int32_t>* binary_tree = new CBinaryTree<int32_t>(3);
  binary_tree->left = new CBinaryTree<int32_t>(5);
  binary_tree->left->left = new CBinaryTree<int32_t>(6);
  binary_tree->left->right = new CBinaryTree<int32_t>(2);
  binary_tree->left->right->left = new CBinaryTree<int32_t>(7);
  binary_tree->left->right->right = new CBinaryTree<int32_t>(4);
  binary_tree->right = new CBinaryTree<int32_t>(1);
  binary_tree->right->left = new CBinaryTree<int32_t>(0);
  binary_tree->right->right = new CBinaryTree<int32_t>(8);
  auto* output = lowest_common_ancestor_binary_tree(binary_tree, binary_tree->left->right->left, binary_tree->right->right);
  std::cout<<"236. Lowest Common Ancestor of a Binary Tree: "<<output->value;
  destroy(binary_tree);
}
