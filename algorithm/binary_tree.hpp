//
//  binary_tree.hpp
//  consoleApp_1
//
//  Created by Asesh Shrestha on 1/25/20.
//  Copyright © 2020 Asesh Shrestha. All rights reserved.
//

#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

template<typename GenericData>
class CBinarySearchTree {
public:
	CBinarySearchTree(GenericData generic_data) {
		
	}
	
	/*
	 1 2 3 4 5 6 7 8 9 10
								5
							4		5
						3
	 */
	void insert(std::vector<GenericData>& generic_data) {
		// Sort the numbers: O(nlogn)
//		std::sort(generic_data.begin(), generic_data.end());
	}
	
	void remove(GenericData generic_data) {
	}
	
	void lookup(GenericData generic_data) {
	}
	
private:
	GenericData m_generic_data;
	std::unique_ptr<CBinarySearchTree> left;
	std::unique_ptr<CBinarySearchTree> right;
};

// Insertion methods:
//	Between two nodes
//	After a leaf node
template<typename GenericData>
class CBinaryTree {
public:
	CBinaryTree(GenericData input_data) {
		value = input_data;
	}
	/*
	 Visualization of binary tree
								1
						/				\
					2						3
				/		\				/		\
				4		5				6			7
			/	\		/	\		 / \   /  \
			8	9	 10	 11	12 13  14  15
															\
																16
															/
														17
	 */
	void print_outer_layer(CBinaryTree<GenericData>* node) {
		if(!node) {
			return;
		}
		std::cout<<node->value<<" ";
		
		print_outer_layer(node->right);
	}
	
	void traverse_inorder(CBinaryTree<GenericData>* node) {
		if(!node) {
			return;
		}
		
		traverse_inorder(node->left);
		std::cout<<node->value<<" ";
		traverse_inorder(node->right);
	}
	
	void traverse_postorder(CBinaryTree<GenericData>* node) {
		if(!node) {
			return;
		}
		
		traverse_postorder(node->left);
		traverse_postorder(node->right);
		std::cout<<node->value<<" ";
	}
	
	void traverse_preorder(CBinaryTree<GenericData>* node) {
		if(!node) {
			return;
		} else {
			std::cout<<node->value << " ";
			
			traverse_preorder(node->left);
			traverse_preorder(node->right);
		}
	}
	
	void remove_subtree(CBinaryTree<GenericData>* parent_node) {
		while(parent_node) {
			auto left_child_node = parent_node->left;
			auto right_child_node = parent_node->right;
			std::cout<<"Deleting: " << parent_node->value << " ";
			delete parent_node;
			parent_node = nullptr;
			
			if(left_child_node) {
				remove_subtree(left_child_node);
			}
			if(right_child_node) {
				remove_subtree(right_child_node);
			}
		}
	}
	
	int32_t get_height(CBinaryTree<GenericData>* node) {
		if(node == nullptr) {
			return 0;
		} else {
			auto left_subtree_height = get_height(node->left) + 1;
			auto right_subtree_height = get_height(node->right) + 1;
			return std::max(left_subtree_height, right_subtree_height);
		}
	}
	
	void print_level(CBinaryTree<GenericData>* node, int32_t level) {
		if(!node) {
			return;
		} else if(level == 0) {
			std::cout<<node->value<< " ";
		} else {
			print_level(node->left, level - 1);
			print_level(node->right, level - 1);
		}
	}
	
	void traverse_bfs() {
		for(int32_t level_counter = 0; level_counter < get_height(this); ++level_counter) {
			std::cout<<"Level " << level_counter + 1 << ": ";
			print_level(this, level_counter);
			std::cout<<std::endl;
		}
	}
  
	bool add_new_item(GenericData new_value) {
		return true;
	}
	
	bool remove_item(GenericData existing_node) {
		return true;
	}
  
public:
  CBinaryTree<GenericData>* left = nullptr;
  CBinaryTree<GenericData>* right = nullptr;
  CBinaryTree<GenericData>* next = nullptr;
  
  GenericData value;
  
  std::size_t m_number_of_items;
};

template<typename T>
void destroy(CBinaryTree<T>* node) {
  if(!node) {
    return;
  }
  
  destroy(node->left);
  destroy(node->right);
  
  delete node;
  node = nullptr;
}

void invoke_binary_tree();
void invoke_binary_search_tree();

/*
199. Binary Tree Right Side View: https://leetcode.com/problems/binary-tree-right-side-view
*/
void invoke_right_side_view();

/*
102. Binary Tree Level Order Traversal: https://leetcode.com/problems/binary-tree-level-order-traversal
*/
void invoke_level_order_traversal();

/*
98. Validate Binary Search Tree: https://leetcode.com/problems/validate-binary-search-tree
*/
void invoke_validate_binary_search_tree();

/*
230. Kth Smallest Element in a BST: https://leetcode.com/problems/kth-smallest-element-in-a-bst
*/
void invoke_kth_smallest_element_in_a_bst();

/*
105. Construct Binary Tree from Preorder and Inorder Traversal: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/
void invoke_construct_binary_tree_from_pre_and_inorder_traversal();

/*
129. Sum Root to Leaf Numbers: https://leetcode.com/problems/sum-root-to-leaf-numbers
*/
void invoke_sum_root_to_leaf_number();

/*
114. Flatten Binary Tree to Linked List: https://leetcode.com/problems/flatten-binary-tree-to-linked-list
*/
void invoke_flatten_binary_tree_to_linked_list();

/*
106. Construct Binary Tree from Inorder and Postorder Traversal: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
*/
void invoke_construct_binary_tree_from_inorder_and_postorder_traversal();

/*
236. Lowest Common Ancestor of a Binary Tree: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
*/
void invoke_lowest_common_ancestor_binary_tree();

/*
117. Populating Next Right Pointers in Each Node II: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii
*/
void invoke_populating_next_right_pointers_in_each_node_ii();

/*
103. Binary Tree Zigzag Level Order Traversal: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
*/
void invoke_binary_tree_zigzag_level_order_traversal();

/*
112. Path Sum: https://leetcode.com/problems/path-sum
*/
void invoke_path_sum();

/*
226. Invert Binary Tree: https://leetcode.com/problems/invert-binary-tree
*/
void invoke_invert_binary_tree();

/*
101. Symmetric Tree: https://leetcode.com/problems/symmetric-tree
*/
void invoke_symmetric_tree();

/*
222. Count Complete Tree Nodes: https://leetcode.com/problems/count-complete-tree-nodes
*/
void invoke_count_complete_tree_nodes();

/*
637. Average of Levels in Binary Tree: https://leetcode.com/problems/average-of-levels-in-binary-tree
*/
void invoke_average_of_levels_in_binary_tree();

/*
530. Minimum Absolute Difference in BST: https://leetcode.com/problems/minimum-absolute-difference-in-bst
*/
void invoke_minimum_absolute_difference_in_bst();

/*
108. Convert Sorted Array to Binary Search Tree: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
*/
void invoke_convert_sorted_array_to_binary_search_tree();

/*
1161. Maximum Level Sum of a Binary Tree: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree
*/
void invoke_maximium_level_sum_of_a_binary_tree();

#endif /* BINARY_TREE_HPP */
