//
//  trie.cpp
//  algorithm
//
//  Created by Asesh Shrestha on 17/11/2024.
//  Copyright © 2024 Asesh Shrestha. All rights reserved.
//

#include "header.h"
#include "trie.hpp"

/*
Trie visualization:
         (*)
        /  \
      (a)   (h)
      /    /  \
    (s)  (e)  (i)
         /       \
       (r)        (m)
*/
void CTrie::insert(std::string word) {
  CTrie* current_node = this;
  
  for(auto& character: word) {
    if(!current_node->m_child[character - 'a']) {
      CTrie* new_node = new CTrie();
      current_node->m_child[character - 'a'] = new_node;
    }
    
    current_node = current_node->m_child[character - 'a'];
  }
  
  current_node->m_end = true;
}

bool CTrie::search(std::string word) {
  CTrie* current_node = this;
  for(int index = 0; index < word.size(); ++index) {//for(auto& character: word) {
    auto character = word[index];
    if(character == '.') {
      for(auto& child_node: current_node->m_child) {
        if(child_node && child_node->search(word.substr(index + 1))) {
          return true;
        }
      }
      return false;
    }
    if(!current_node->m_child[character - 'a']) {
      return false;
    }
    
    current_node = current_node->m_child[character - 'a'];
  }
  return current_node->m_end;
}

bool CTrie::starts_with(std::string word) {
  CTrie* current_node = this;
  for(auto& character: word) {
    if(!current_node->m_child[character - 'a']) {
      return false;
    }
    
    current_node = current_node->m_child[character - 'a'];
  }
  return true;
}

void invoke_trie_methods() {
  CTrie trie;
  trie.insert("hello");
  auto search_one = trie.search("hello");
  auto search_two = trie.search("foo");
  auto search_three = trie.search("..llo");
  auto starts_with = trie.starts_with("hel");
  std::cout<<"Trie (prefix tree): "
    <<std::boolalpha
    <<"search result for 'hello': "<<search_one
    <<", search result for 'foo': "<<search_two
    <<", search result for '..llo': "<<search_three
    <<", starts with 'hel': "<<starts_with<<std::endl;
}
