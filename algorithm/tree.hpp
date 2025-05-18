//
//  tree.hpp
//  algorithm
//
//  Created by Asesh Shrestha on 31/01/2025.
//  Copyright © 2025 Asesh Shrestha. All rights reserved.
//

struct TreeNode {
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;
  
  TreeNode() {}
  TreeNode(int x) : val(x) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct QuadTree {
  bool val = false;
  bool is_leaf = false;
  QuadTree* top_left = nullptr;
  QuadTree* top_right = nullptr;
  QuadTree* bottom_left = nullptr;
  QuadTree* bottom_right = nullptr;
  
  QuadTree(bool val, bool is_leaf) {
    this->val = val;
    this->is_leaf = is_leaf;
  }
  
  QuadTree(bool val, bool is_leaf,
           QuadTree* top_left, QuadTree* top_right, QuadTree* bottom_left, QuadTree* bottom_right) {
    this->val = val;
    this->is_leaf = is_leaf;
    this->top_left = top_left;
    this->top_right = top_right;
    this->bottom_left = bottom_left;
    this->bottom_right = bottom_right;
  }
};

void destroy_quad_tree(QuadTree* root_node);

/*
 427. Construct Quad Tree: https://leetcode.com/problems/construct-quad-tree
*/
void invoke_construct_quad_tree();

/*
100. Same Tree: https://leetcode.com/problems/same-tree
*/
void invoke_same_tree();
