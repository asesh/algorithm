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
		
	}
	
	// 1, 2, 3, 4, 5
//	CBinaryTree(const std::array<GenericData, number_of_items>& input_array) {
//		
//	}
  
	bool add_new_item(GenericData new_value) {
		return true;
	}

  ~CBinaryTree();
  
protected:
  CBinaryTree<GenericData>* m_left_node = nullptr;
  CBinaryTree<GenericData>* m_right_node = nullptr;
  
  GenericData m_data;
  
  std::size_t m_number_of_items;
};

#endif /* BINARY_TREE_HPP */
