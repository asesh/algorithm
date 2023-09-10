//
//  graph_algorithm.cpp
//  algorithm
//
//  Created by Asesh Shrestha on 09/09/2023.
//  Copyright © 2023 Asesh Shrestha. All rights reserved.
//

#include "header.h"
#include "graph_algorithm.h"

void create_directed_graph() {
  // Adjanceny list representation of graph
  /*
   
   3 - 8 - 6 - 9 - 11 - 10
   |       |    |        |
   1 - 7 - 0 - 12 - 19 - 17
       |   |    |    |
   4 - 5 - 13 - 18 - 20
   
   Adjacency list:
   Node   Adjacent nodes
   3      8 - 1
   8      3 - 6
   6      8 - 9 - 0
   0      6 - 7 - 12 - 13
   ...
   20     18 - 19
   */
  std::unordered_map<int, std::list<int>> directed_graph = {
    {1, {3, 7}},
    {3, {1, 8}}
  };
  CDirectedGraph<int, int> di_graph(directed_graph);
  
}
