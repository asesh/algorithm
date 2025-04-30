//
//  graph_algorithm.h
//  algorithm
//
//  Created by Asesh Shrestha on 15/05/2022.
//  Copyright © 2022 Asesh Shrestha. All rights reserved.
//

#ifndef GRAPH_H
#define GRAPH_H

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


// Graph's node representation from LeetCode
class Node {
public:
  int val;
  std::vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }
  Node(int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

/*
133. Clone Graph: https://leetcode.com/problems/clone-graph/
*/
void invoke_clone_graph();

/*
         0
    1          2
 3     4    5    6
 
 Index: 0 1 2 3 4 5 6 <- Nodes' value
 Value: 0 0 0 0 0 0 0 <- Root nodes
 */
class UnionFind {
public:
  UnionFind(int total_nodes) : root_nodes(total_nodes) {
    for(int index = 0; index < total_nodes; ++index) {
      root_nodes[index] = index;
    }
  }
  
  // RC: O(1)
  int find(int node_value) {
    return root_nodes[node_value];
  }
  
  bool equal(int node_value_x, int node_value_y) {
    return find(node_value_x) == find(node_value_y);
  }
  
  // RC: O(n)
  void union_set(int node_value_x, int node_value_y) {
    int root_x = find(node_value_x);
    int root_y = find(node_value_y);
    if(root_x != root_y) {
      for(int index = 0; index < root_nodes.size(); ++index) {
        if(root_nodes[index] == root_y) {
          root_nodes[index] = root_x;
        }
      }
    }
  }
  
private:
  std::vector<int> root_nodes;
};

void invoke_union_find();

#endif /* GRAPH_H */
