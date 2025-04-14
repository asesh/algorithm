//
//  graph_algorithm.cpp
//  algorithm
//
//  Created by Asesh Shrestha on 09/09/2023.
//  Copyright © 2023 Asesh Shrestha. All rights reserved.
//

#include "header.h"
#include "graph.hpp"

void create_undirected_graph() {
  // Adjacency list representation of graph
  /*
   3 - 8 - 6 - 9 - 11 - 10
   |       |    |        |
   1 - 7 - 0 - 12 - 19 - 17
       |   |    |    |
   4 - 5 - 13 - 18 - 20
   */
  std::unordered_map<int, std::list<int>> undirected_graph = {
    {3, {1, 8}},
    {8, {3, 6}},
    {6, {8, 9, 0}},
    {9, {6, 11, 12}},
    {11, {9, 10}},
    {10, {11, 17}},
    {1, {3, 7}},
    {7, {0, 1, 5}},
    {0, {6, 7, 12, 13}},
    {12, {0, 9, 18, 19}},
    {19, {12, 17, 20}},
    {17, {10, 19}},
    {4, {5}},
    {5, {4, 7, 13}},
    {13, {0, 5, 18}},
    {18, {12, 13, 20}},
    {20, {18, 19}}
  };
  
  CBaseGraph<int> undi_graph(std::move(undirected_graph));
  undi_graph.traverse_bfs(3);
  undi_graph.traverse_dfs(7);
}

void create_directed_graph() {
  // Adjanceny list representation of directed graph
  /*
   3 -> 8 -> 6 ->  9 -> 11 -> 10
   |         |     |           |
   1 -> 7 -> 0 -> 12 -> 19 -> 17
       |     |      |    |
   4 <- 5 <- 13 <- 18 <- 20
   
   Adjacency list:
   Node   Adjacent nodes
   3      8 - 1
   8      6
   6      9 - 0
   9      11 - 12
   11     10
   10     17
   1      7
   7      0 - 5
   0      12 - 13
   12     18 - 19
   19     17 - 20
   4
   5      4
   13     5
   18     13
   20     18
   */
  std::unordered_map<int, std::list<int>> directed_graph = {
    {3, {1, 8}},
    {8, {6}},
    {6, {9, 0}},
    {9, {11, 12}},
    {11, {10}},
    {10, {17}},
    {1, {7}},
    {7, {0, 5}},
    {0, {12, 13}},
    {12, {18, 19}},
    {19, {17, 20}},
    {5, {4}},
    {13, {5}},
    {18, {13}},
    {20, {18}}
  };
  CDirectedGraph<int, int> di_graph(std::move(directed_graph));
  di_graph.traverse_bfs();
}

/*
Input: [[2,4],[1,3],[2,4],[1,3]]
Process:
 1----------2
 |          |
 |          |
 |          |
 3----------4
*/
Node* clone_graph_dfs(Node* node, std::unordered_map<Node*, Node*>& visited_nodes) {
  if(!node) {
    return node;
  }
  
  if(visited_nodes.contains(node)) {
    return visited_nodes[node];
  }
  
  Node* new_node = new Node(node->val);
  visited_nodes[node] = new_node;
  
  for(auto& neighbor_node: node->neighbors) {
    visited_nodes[node]->neighbors.push_back(clone_graph_dfs(neighbor_node, visited_nodes));
  }
  
  return visited_nodes[node];
}
Node* clone_graph_bfs(Node* node, std::unordered_map<Node*, Node*>& visited_nodes) {
  if(!node) {
    return node;
  }
  
  std::queue<Node*> nodes_to_visit;
  
  visited_nodes[node] = new Node(node->val);
  nodes_to_visit.push(node);
  
  while(!nodes_to_visit.empty()) {
    auto* current_node = nodes_to_visit.front();
    nodes_to_visit.pop();
    
    for(auto& neighbor: current_node->neighbors) {
      if(!visited_nodes.contains(neighbor)) {
        visited_nodes[neighbor] = new Node(neighbor->val);
        nodes_to_visit.push(neighbor);
      }
      visited_nodes[current_node]->neighbors.push_back(visited_nodes[neighbor]);
    }
  }
  
  return visited_nodes[node];
}
void invoke_clone_graph() {
  Node* first = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);
  Node* fourth = new Node(4);
  first->neighbors = std::vector<Node*>({second, third});
  second->neighbors = std::vector<Node*>({first, fourth});
  third->neighbors = std::vector<Node*>({first, fourth});
  fourth->neighbors = std::vector<Node*>({second, third});
  std::unordered_map<Node*, Node*> visited_nodes;
//  auto* cloned_graph = clone_graph_bfs(first, visited_nodes);
  auto* cloned_graph = clone_graph_dfs(first, visited_nodes);
  std::cout<<"133. Clone Graph: "<<cloned_graph;
  
  // Memory deallocation
  for(auto& node: visited_nodes) {
    delete node.first;
    delete node.second;
  }
}
