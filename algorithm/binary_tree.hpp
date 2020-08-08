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
							*
						/		\
					*				*
				/		\		/		\
				*		*		*		*
			/	\		/	\
			*	*		*	*
	 
	 */
	~CBinaryTree() {
		// Remove all the nodes from the left subtree
//		remove_subtree(m_left_node);
		
		// Remove all the nodes from the right subtree
//		remove_subtree(m_right_node);
	}
	
	void remove_subtree(CBinaryTree<GenericData>* parent_node) {
		while(parent_node) {
			auto left_child_node = parent_node->m_left_node;
			auto right_child_node = parent_node->m_right_node;
			std::cout<<"Deleting: " << parent_node->m_data << std::endl;
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
	
	// 1, 2, 3, 4, 5
//	CBinaryTree(const std::array<GenericData, number_of_items>& input_array) {
//		
//	}
  
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
