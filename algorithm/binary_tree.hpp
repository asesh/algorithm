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
	std::unique_ptr<CBinarySearchTree> m_left_node;
	std::unique_ptr<CBinarySearchTree> m_right_node;
};

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
															\
																16
															/
														17
	 */
	void print_outer_layer(CBinaryTree<GenericData>* node) {
		if(!node) {
			return;
		}
		std::cout<<node->m_data<<" ";
		
		print_outer_layer(node->m_right_node);
	}
	
	void traverse_inorder(CBinaryTree<GenericData>* node) {
		if(!node) {
			return;
		}
		
		traverse_inorder(node->m_left_node);
		std::cout<<node->m_data<<" ";
		traverse_inorder(node->m_right_node);
	}
	
	void traverse_postorder(CBinaryTree<GenericData>* node) {
		if(!node) {
			return;
		}
		
		traverse_postorder(node->m_left_node);
		traverse_postorder(node->m_right_node);
		std::cout<<node->m_data<<" ";
	}
	
	void traverse_preorder(CBinaryTree<GenericData>* node) {
		if(!node) {
			return;
		} else {
			std::cout<<node->m_data << " ";
			
			traverse_preorder(node->m_left_node);
			traverse_preorder(node->m_right_node);
		}
	}
	
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
			return std::max(left_subtree_height, right_subtree_height);
		}
	}
	
	void print_level(CBinaryTree<GenericData>* node, int32_t level) {
		if(!node) {
			return;
		} else if(level == 0) {
			std::cout<<node->m_data<< " ";
		} else {
			print_level(node->m_left_node, level - 1);
			print_level(node->m_right_node, level - 1);
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
  CBinaryTree<GenericData>* m_left_node = nullptr;
  CBinaryTree<GenericData>* m_right_node = nullptr;
  
  GenericData m_data;
  
  std::size_t m_number_of_items;
};

void invoke_binary_tree();
void invoke_binary_search_tree();

#endif /* BINARY_TREE_HPP */
