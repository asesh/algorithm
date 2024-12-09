//
//  linked_list.h
//  consoleApp_1
//
//  Created by Asesh Shrestha on 2/19/20.
//  Copyright © 2020 Asesh Shrestha. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

template<typename Data>
class CSingleLinkedList {
public:
	CSingleLinkedList() = default;
	CSingleLinkedList(Data data) {
		value = data;
	}
	CSingleLinkedList(const std::initializer_list<Data>& input_list) {
		for(const auto& node_data: input_list) {
      next = new CSingleLinkedList(node_data);
      next = next->next;
		}
	}

	Data get_value() const {
    return value;
	}

	// Clear all the nodes starting from the root node
	void destroy() {
		auto current_node = this;
		while(current_node) {
			auto next_node = current_node->next;
			delete current_node;
			current_node = next_node;
		}
	}

public:
	CSingleLinkedList<Data>* next = nullptr;
	Data value = 0;
};

// Double linked list
template<typename DataType>
class CDoubleLinkedList {
public:
	CDoubleLinkedList(DataType new_data) {
		previous = next = nullptr;
		value = new_data;
	}

	void add_previous_node(DataType new_data) {
		CDoubleLinkedList<DataType>* temp_node = nullptr;
		if(previous) {
			// Previous node exists already
			temp_node = previous;
			previous = new CDoubleLinkedList<DataType>(new_data);
			previous->next = temp_node;
		}
		else {
			// Previous node doesn't exist
			previous = new CDoubleLinkedList(new_data);
			previous->next = this;
		}
	}

	void add_next_node(DataType new_data) {
		if(next) {
			// Next node exits already
			auto temp_node = next;
			next = new CDoubleLinkedList<DataType>(new_data);
			next->previous = temp_node;
		}
		else {
			// Next node doesn't exists
			next = new CDoubleLinkedList<DataType>(new_data);
			next->previous = this;
		}
	}

	void destroy() {
		if(previous) {
			// Previous node exists so we iterate through all the nodes from it
			while(previous) {
				auto temp_previous_node = previous->m_next;
				delete previous;
				previous = temp_previous_node;
			}
			previous = nullptr;
		}
		else {
			while(next) {
				auto temp_previous_node = next->previous;
				delete next;
				next = temp_previous_node;
			}
			next = nullptr;
		}
	}

	void print_all() const {
		CDoubleLinkedList<DataType>* next_node = nullptr;
		if(previous) {
			next_node = previous;
			while(next_node) {
				std::cout<< next_node->value << std::endl;
				next_node = next_node->next;
			}
		}
		else {
			std::cout<< value << std::endl;
			if(next) {
				std::list<DataType> node_data;
				auto previous_node = next; // Next is pointing to the last element
				while(previous_node) {
					node_data.push_front(previous_node->value);
					previous_node = previous_node->previous;
				}
				for(const auto& data: node_data) {
					std::cout << data << std::endl;
				}
			}
		}
	}

protected:
	CDoubleLinkedList* previous, *next;

	DataType value;
};

void invoke_reverse_linked_list();
CSingleLinkedList<int>&& reverse_linked_list(const CSingleLinkedList<int>& input_linked_list);

/*
2. Add Two Numbers: https://leetcode.com/problems/add-two-numbers/
*/
void invoke_add_two_linked_list_numbers();

/*
92. Reverse Linked List II: https://leetcode.com/problems/reverse-linked-list-ii
*/
void invoke_reverse_linked_list();

/*
148. Sort List: https://leetcode.com/problems/sort-list
*/
void invoke_sort_linked_list();

/*
19. Remove Nth Node From End of List: https://leetcode.com/problems/remove-nth-node-from-end-of-list
*/
void invoke_remove_nth_node_from_end_of_list();

/*
82. Remove Duplicates from Sorted List II: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
*/
void invoke_remove_duplicates_from_sorted_list_ii();

#endif /* linked_list_h */
