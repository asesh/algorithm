//
//  binary_tree.hpp
//  consoleApp_1
//
//  Created by Asesh Shrestha on 1/25/20.
//  Copyright © 2020 Asesh Shrestha. All rights reserved.
//

#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

// Insertion methods:
//	Between two nodes
//	After a leaf node
template<typename GenericData>
class CBinaryTree {
public:
	CBinaryTree(GenericData input_data) {
		m_data = input_data;
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
	 
	 */
	
	void remove_subtree(CBinaryTree<GenericData>* parent_node) {
		while(parent_node) {
			auto left_child_node = parent_node->m_left_node;
			auto right_child_node = parent_node->m_right_node;
			std::cout<<"Deleting: " << parent_node->m_data << " ";
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
			auto left_subtree_height = get_height(node->m_left_node) + 1;
			auto right_subtree_height = get_height(node->m_right_node) + 1;
			return left_subtree_height > right_subtree_height ? left_subtree_height : right_subtree_height;
		}
	}
	
	void traverse_bfs(CBinaryTree<GenericData>* node, int32_t level) {
		if(!node) {
			return;
		}
		else if(level == 1) {
			std::cout<<"*"<<node->m_data<<" ";
		}
	}
	
	void print_nodes_at_level(CBinaryTree<GenericData>* node, int32_t height) {
		if(node) {
			if(height == 1) {
				std::cout<<node->m_data;
			} else if(height > 1) {
				
			}
		}
	}
  
	bool add_new_item(GenericData new_value) {
		return true;
	}
	
	bool remove_item(GenericData existing_node) {
		return true;
	}
  
public:
  CBinaryTree<GenericData>* m_left_node = nullptr;
  CBinaryTree<GenericData>* m_right_node = nullptr;
  
  GenericData m_data;
  
  std::size_t m_number_of_items;
};

#endif /* BINARY_TREE_HPP */
