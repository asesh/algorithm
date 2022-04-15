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
class CLinkedList {
public:
	CLinkedList(Data input_data) {
		m_next_node = new CLinkedList<Data>(input_data);
		m_next_node = m_next_node->m_next_node;
	}
	CLinkedList(const std::initializer_list<Data>& input_list) {
		for(const auto& input_data: input_list) {
			m_next_node = new CLinkedList<Data>(input_data);
			m_next_node = m_next_node->m_next_node;
		}
	}
	~CLinkedList() {
		while(m_next_node) {
			auto next_node = m_next_node->m_next_node;
			delete m_next_node;
			m_next_node = next_node;
		}
	}
	
	void add_node(Data input_data) {
		m_next_node = new CLinkedList<Data>(input_data);
		m_next_node = m_next_node->m_next_node;
	}
	
	CLinkedList* m_next_node = nullptr;
	Data m_data;
};

template<typename Data>
class CSingleLinkedList {
public:
	CSingleLinkedList() = default;
	CSingleLinkedList(Data data) {
		m_data = data;
	}
	CSingleLinkedList(const std::initializer_list<Data>& input_list) {
		for(const auto& input_data: input_list) {
			add_node(input_data);
		}
	}
	~CSingleLinkedList() {
		if(m_root_node) {
			// Free all the nodes starting from the root node
			auto current_node = m_root_node;
			while(current_node) {
				auto buffer_node = current_node->m_next_node;
				delete current_node;
				current_node = buffer_node;
			}
			m_root_node = nullptr;
		}
	}

	void add_node(Data data) {
		if(m_root_node) {
			// Root node exists already
			if(m_next_node) {
				auto buffer_node = new CSingleLinkedList<Data>(data);
				m_next_node = m_next_node->m_next_node = buffer_node;
			} else {
				// Node past root node doesn't exists
				m_root_node->m_next_node = new CSingleLinkedList<Data>(data);
				m_next_node = m_root_node->m_next_node;
			}
		} else {
			// Root node has not been initialized
			m_root_node = new CSingleLinkedList<Data>(data);
		}
	}
	
	void operator=(Data input_data) {
		if(m_root_node) {
			m_root_node->m_data = input_data;
		} else {
			m_next_node->m_data = input_data;
		}
	}
	
	CSingleLinkedList<Data>* next() {
		if(m_next_node) {
			auto current_node = m_next_node;
			m_next_node = m_next_node->m_next_node;
			return current_node;
		} else {
			m_next_node = m_root_node->m_next_node;
			return m_root_node;
		}
	}

	CSingleLinkedList<Data> operator++() {
		if(m_root_node) {
			return m_next_node;
		} else {
			return m_root_node;
		}
	}

	Data get_value() const {
		if(m_root_node) {
			return m_root_node->m_data;
		} else {
			return m_next_node->m_data;
		}
	}

	// Clear all the nodes starting from the root node
	void clear_nodes() {
		auto current_node = m_root_node;
		while(current_node) {
			auto next_node = current_node->m_next_node;
			delete current_node;
			current_node = next_node;
		}
	}

public:
	CSingleLinkedList<Data>* m_root_node = nullptr;
	CSingleLinkedList<Data>* m_next_node = nullptr;
	Data m_data = 0;
};

// Double linked list
template<typename DataType>
class CDoubleLinkedList {
public:
	CDoubleLinkedList(DataType new_data) {
		m_previous_node = m_next_node = nullptr;
		m_data = new_data;
	}

	void add_previous_node(DataType new_data) {
		CDoubleLinkedList<DataType>* temp_node = nullptr;
		if(m_previous_node) {
			// Previous node exists already
			temp_node = m_previous_node;
			m_previous_node = new CDoubleLinkedList<DataType>(new_data);
			m_previous_node->m_next_node = temp_node;
		}
		else {
			// Previous node doesn't exist
			m_previous_node = new CDoubleLinkedList(new_data);
			m_previous_node->m_next_node = this;
		}
	}

	void add_next_node(DataType new_data) {
		if(m_next_node) {
			// Next node exits already
			auto temp_node = m_next_node;
			m_next_node = new CDoubleLinkedList<DataType>(new_data);
			m_next_node->m_previous_node = temp_node;
		}
		else {
			// Next node doesn't exists
			m_next_node = new CDoubleLinkedList<DataType>(new_data);
			m_next_node->m_previous_node = this;
		}
	}

	void destroy() {
		if(m_previous_node) {
			// Previous node exists so we iterate through all the nodes from it
			while(m_previous_node) {
				auto temp_previous_node = m_previous_node->m_next;
				delete m_previous_node;
				m_previous_node = temp_previous_node;
			}
			m_previous_node = nullptr;
		}
		else {
			while(m_next_node) {
				auto temp_previous_node = m_next_node->m_previous_node;
				delete m_next_node;
				m_next_node = temp_previous_node;
			}
			m_next_node = nullptr;
		}
	}

	void print_all() const {
		CDoubleLinkedList<DataType>* next_node = nullptr;
		if(m_previous_node) {
			next_node = m_previous_node;
			while(next_node) {
				std::cout<< next_node->m_data << std::endl;
				next_node = next_node->m_next_node;
			}
		}
		else {
			std::cout<< m_data << std::endl;
			if(m_next_node) {
				std::list<DataType> node_data;
				auto previous_node = m_next_node; // Next is pointing to the last element
				while(previous_node) {
					node_data.push_front(previous_node->m_data);
					previous_node = previous_node->m_previous_node;
				}
				for(const auto& data: node_data) {
					std::cout << data << std::endl;
				}
			}
		}
	}

protected:
	CDoubleLinkedList* m_previous_node, *m_next_node;

	DataType m_data;
};

void invoke_reverse_linked_list();
CSingleLinkedList<int>&& reverse_linked_list(const CSingleLinkedList<int>& input_linked_list);

#endif /* linked_list_h */
