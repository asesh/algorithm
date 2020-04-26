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
	CSingleLinkedList() {
		m_root_node = m_next_node = nullptr;
	}
	~CSingleLinkedList() {
		
	}
	
protected:
	CSingleLinkedList(Data new_data) {
		m_root_node = m_next_node = nullptr;
		
		m_data = new_data;
	}
	
public:
	
	// o -> o -> o -> o -> nullptr
	void add_data(Data new_data) {
		if(!m_root_node) {
			m_root_node = new CSingleLinkedList<Data>(new_data);
		}
		else {
			if(!m_next_node) {
				// Root child node doesn't exists
				m_next_node = new CSingleLinkedList<Data>(new_data);
				m_root_node->m_next_node = m_next_node;
			}
			else {
				// Root child node exists
				auto temp_node = new CSingleLinkedList<Data>(new_data);
				m_next_node = m_next_node->m_next_node = temp_node;
			}
		}
	}
	
	void destroy() {
		if(m_root_node) {
			auto temp_node = m_root_node->m_next_node;
			delete m_root_node;
			m_root_node = nullptr;
			while(temp_node) {
				auto another_temp_node = temp_node->m_next_node;
				delete temp_node;
				temp_node = another_temp_node;
			}
		}
	}
	
	void print_all() {
		if(m_root_node) {
			auto next_node = m_root_node->m_next_node;
			std::cout << m_root_node->m_data << std::endl;
			while(next_node) {
				std::cout << next_node->m_data << std::endl;
				next_node = next_node->m_next_node;
			}
		}
	}
	
private:
	CSingleLinkedList<Data>* m_root_node, *m_next_node;
	Data m_data;
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

#endif /* linked_list_h */
