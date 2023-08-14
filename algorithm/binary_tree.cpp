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
	CBinaryTree<int32_t> binary_tree(1);
	// Fill left-subtree
	binary_tree.m_left_node = new CBinaryTree<int32_t>(2);
	binary_tree.m_left_node->m_left_node = new CBinaryTree<int32_t>(4);
	binary_tree.m_left_node->m_right_node = new CBinaryTree<int32_t>(5);
	binary_tree.m_left_node->m_left_node->m_left_node = new CBinaryTree<int32_t>(8);
	binary_tree.m_left_node->m_left_node->m_right_node = new CBinaryTree<int32_t>(9);
	binary_tree.m_left_node->m_right_node->m_left_node = new CBinaryTree<int32_t>(10);
	binary_tree.m_left_node->m_right_node->m_right_node = new CBinaryTree<int32_t>(11);
	
	// Fill right-subtree
	binary_tree.m_right_node = new CBinaryTree<int32_t>(3);
	binary_tree.m_right_node->m_left_node = new CBinaryTree<int32_t>(6);
	binary_tree.m_right_node->m_right_node = new CBinaryTree<int32_t>(7);
	binary_tree.m_right_node->m_left_node->m_left_node = new CBinaryTree<int32_t>(12);
	binary_tree.m_right_node->m_left_node->m_right_node = new CBinaryTree<int32_t>(13);
	binary_tree.m_right_node->m_right_node->m_left_node = new CBinaryTree<int32_t>(14);
	binary_tree.m_right_node->m_right_node->m_right_node = new CBinaryTree<int32_t>(15);
	binary_tree.m_right_node->m_right_node->m_right_node->m_right_node = new CBinaryTree<int32_t>(16);
	binary_tree.m_right_node->m_right_node->m_right_node->m_right_node->m_left_node = new CBinaryTree<int32_t>(17);
	
	//	binary_tree.traverse_bfs(&binary_tree);
	
	std::cout<<std::endl<<"Height of the tree: "<<binary_tree.get_height(&binary_tree)<<std::endl;
	
	std::cout<<"Traversing in BFS:"<<std::endl;
	binary_tree.traverse_bfs();
	
	std::cout<<std::endl<<"Traversing in pre-order: "<<std::endl;
	binary_tree.traverse_preorder(&binary_tree);
	
	std::cout<<std::endl<<std::endl<<"Traversing in in-order: "<<std::endl;
	binary_tree.traverse_inorder(&binary_tree);
	
	std::cout<<std::endl<<std::endl<<"Traversing in post-order: "<<std::endl;
	binary_tree.traverse_postorder(&binary_tree);
	
	std::cout<<std::endl<<std::endl<<"Traversing outer layer: "<<std::endl;
	binary_tree.print_outer_layer(&binary_tree);
	
	std::cout<<std::endl<<std::endl<<"Removing all the nodes"<<std::endl;
	// Remove the left and right subtrees
	binary_tree.remove_subtree(binary_tree.m_left_node);
	binary_tree.remove_subtree(binary_tree.m_right_node);
	
	std::cout<<std::endl;
}
