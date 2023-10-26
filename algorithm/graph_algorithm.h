//
//  graph_algorithm.h
//  algorithm
//
//  Created by Asesh Shrestha on 15/05/2022.
//  Copyright © 2022 Asesh Shrestha. All rights reserved.
//

#ifndef GRAPH_ALGORITHM_H
#define GRAPH_ALGORITHM_H

template<typename NodeType>
class CBaseGraph {
public:
  CBaseGraph(std::unordered_map<NodeType, std::list<NodeType>>&& adjacency_list) {
    m_adjacency_list = std::move(adjacency_list);
  }
  
  virtual void traverse_dfs(int starting_node = -1) {
    std::unordered_set<NodeType> visited_nodes;
    
    if(!m_adjacency_list.contains(starting_node)) {
      return;
    }
    
    std::stack<int> nodes_to_be_visited;
    nodes_to_be_visited.push(starting_node);
    
    visited_nodes.insert(starting_node);
    
    std::cout<<std::endl<<"DFS: ";
    
    while(!nodes_to_be_visited.empty()) {
      auto top_node = nodes_to_be_visited.top();
      std::cout<<top_node<<", ";
      nodes_to_be_visited.pop();
      
      for(const auto& adjacent_node: m_adjacency_list[top_node]) {
        if(!visited_nodes.contains(adjacent_node)) {
          nodes_to_be_visited.push(adjacent_node);
          visited_nodes.insert(adjacent_node);
        }
      }
    }
  }
  
  virtual void traverse_bfs(int starting_node = -1) {
    std::unordered_set<NodeType> visited_nodes;
    
    if(!m_adjacency_list.contains(starting_node)) {
      return;
    }
    
    visited_nodes.insert(starting_node);
    
    std::queue<int> nodes_to_be_visited;
    nodes_to_be_visited.push(starting_node);
    
    std::cout<<"BFS: ";
    
    while(!nodes_to_be_visited.empty()) {
      for(const auto& adjacent_node: m_adjacency_list[nodes_to_be_visited.front()]) {
        if(!visited_nodes.contains(adjacent_node)) {
          visited_nodes.insert(adjacent_node);
          nodes_to_be_visited.push(adjacent_node);
        }
      }
      
      std::cout<<nodes_to_be_visited.front()<<", ";
      nodes_to_be_visited.pop();
    }
  }
  
protected:
  virtual void make_graph() {
  }
	
protected:
  std::unordered_map<NodeType, std::list<NodeType>> m_adjacency_list;
};

template<typename NodeType, typename DistanceType>
class CDirectedGraph : public CBaseGraph<NodeType> {
public:
  CDirectedGraph(std::unordered_map<NodeType, std::list<NodeType>>&& adjacency_list) :
    CBaseGraph<NodeType>(std::move(adjacency_list)) {
  }
  
protected:
  void make_graph() override {
  }
  
private:
};

void create_undirected_graph();
void create_directed_graph();

#endif /* GRAPH_ALGORITHM_H */
