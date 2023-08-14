//
//  graph_algorithm.h
//  algorithm
//
//  Created by Asesh Shrestha on 15/05/2022.
//  Copyright © 2022 Asesh Shrestha. All rights reserved.
//

#ifndef GRAPH_ALGORITHM_H
#define GRAPH_ALGORITHM_H

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
template<typename DataType>
class CGraph {
public:
	
private:
  std::unordered_map<DataType, std::list<DataType>> m_adjacency_list;
};

template<typename DataType, typename DistanceType>
class CDirectedGraph : CGraph<DataType> {
public:
  
private:
};

#endif /* GRAPH_ALGORITHM_H */
