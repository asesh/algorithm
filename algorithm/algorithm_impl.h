////
////  algorithm_impl.h
////  algorithm
////
////  Created by Asesh Shrestha on 13/03/2021.
////  Copyright © 2021 Asesh Shrestha. All rights reserved.
////
//
//#ifndef algorithm_impl_h
//#define algorithm_impl_h
//
///*
// #2 Add two numbers: https://leetcode.com/problems/add-two-numbers/
// */
//class ReverseLinkedList {
//public:
//	ReverseLinkedList(int number) {
//		m_value = number;
//	}
//	
//	~ReverseLinkedList() {
//	}
//	
//	/*
//	 
//	 * -> *
//	 
//	 */
//	void add(int number) {
//		if(!m_root_node) {
//			m_root_node = new ReverseLinkedList(number);
//		} else {
//			// Root node has been initialized already
//			auto buffer = new ReverseLinkedList(number);
//			m_root_node->m_next_node = buffer;
//		}
//	}
//	
//	int get() {
//		return m_value;
//	}
//	
//	void traverse() {
//	}
//	
//public:
//	int m_value;
//	ReverseLinkedList* m_root_node = nullptr, m_next_node = nullptr;
//};
//
//ReverseLinkedList* add_reverse_linked_list(ReverseLinkedList* first_rll, ReverseLinkedList* second_rll);
//
//#endif /* algorithm_impl_h */
