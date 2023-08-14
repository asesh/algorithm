////
////  algorithm_impl.cpp
////  Algorithm challenges
////
////  Created by Asesh Shrestha on 13/03/2021.
////  Copyright © 2021 Asesh Shrestha. All rights reserved.
////
//

#include "header.h"
//#include <iostream>
//#include "algorithm_impl.h"
//
///*
// Input: 1 -> 2 -> 3
//#2 Add two numbers: https://leetcode.com/problems/add-two-numbers/
// */
////class ReverseLinkedList {
////public:
////	ReverseLinkedList(int number) {
////		m_value = number;
////	}
////	
////	~ReverseLinkedList() {
////		while(m_next_node) {
////			auto next_node = m_next_node->m_next_node;
////			delete m_next_node;
////			m_next_node = next_node;
////		}
////	}
////
////	void add(int number) {
////		if(!m_next_node) {
////			m_next_node = new ReverseLinkedList(number);
////		} else {
////			auto new_node = new ReverseLinkedList(number);
////			m_next_node = new_node;
////		}
////	}
////
////	void traverse() {
////		std::wcout<<m_value<<", ";
////		while(m_next_node) {
////			std::wcout<<m_next_node->m_value<<", ";
////			m_next_node = m_next_node->m_next_node;
////		}
////	}
////
////private:
////	int m_value;
////	ReverseLinkedList* m_next_node = nullptr;
////};
//
///*
// Inputs:
// 2 -> 4 -> 3
// 5 -> 6 -> 4
// 
// Output
// 7 -> 0 -> 8
// */
//ReverseLinkedList* add_reverse_linked_list(ReverseLinkedList* first_rll, ReverseLinkedList* second_rll) {
//	uint32_t carry = 0;
//	ReverseLinkedList* return_rll = nullptr;
//	
//	while(first_rll) {
//		uint32_t sum = first_rll->get() + second_rll->get();
//		
//		uint32_t value = 0;
//		if(sum > 9) {
//			carry /= 10;
//			value %= 10;
//		} else {
//			value = sum + carry;
//		}
//		
//		return_rll = new ReverseLinkedList(value);
//		
//		first_rll = first_rll->m_next_node;
//		second_rll = second_rll->m_next_node;
//	}
//	
//	return nullptr;
//}
