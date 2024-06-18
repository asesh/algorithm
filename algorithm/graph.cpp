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
