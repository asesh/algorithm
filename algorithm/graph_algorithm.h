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
class CGraph {
public:
  CGraph(std::unordered_map<NodeType, std::list<NodeType>>& adjacency_list) {
    m_adjacency_list = adjacency_list;
  }
	
protected:
  std::unordered_map<NodeType, std::list<NodeType>> m_adjacency_list;
};

template<typename NodeType, typename DistanceType>
class CDirectedGraph : CGraph<NodeType> {
public:
  CDirectedGraph(std::unordered_map<NodeType, std::list<NodeType>>& adjacency_list) :
    CGraph<NodeType>(adjacency_list) {
  }
  
private:
};

void create_directed_graph();

#endif /* GRAPH_ALGORITHM_H */
