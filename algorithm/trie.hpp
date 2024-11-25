//
//  trie.hpp
//  algorithm
//
//  Created by Asesh Shrestha on 17/11/2024.
//  Copyright © 2024 Asesh Shrestha. All rights reserved.
//

#ifndef TRIE_H
#define TRIE_H

class CTrie {
public:
  CTrie() = default;
  ~CTrie() = default; // TODO: Implement freeing of memory in the future or use smart pointers

  void insert(std::string word);
  bool search(std::string word);
  bool starts_with(std::string word);
  
  CTrie *m_child[26] = {};
  bool m_end = false;
  std::string m_current_word;
};

/*
208. Implement Trie (Prefix Tree): https://leetcode.com/problems/implement-trie-prefix-tree
211. Design Add and Search Words Data Structure: https://leetcode.com/problems/design-add-and-search-words-data-structure
*/
void invoke_trie_methods();

#endif // TRIE_H
