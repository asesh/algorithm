//
//  tree.cpp
//  algorithm
//
//  Created by Asesh Shrestha on 31/01/2025.
//  Copyright © 2025 Asesh Shrestha. All rights reserved.
//

#include "header.h"
#include "tree.hpp"

void destroy_quad_tree(QuadTree* node) {
  if(!node) {
    return;
  }
  
  destroy_quad_tree(node->top_left);
  destroy_quad_tree(node->top_right);
  destroy_quad_tree(node->bottom_left);
  destroy_quad_tree(node->bottom_right);
  
  delete node;
  node = nullptr;
}

QuadTree* construct_quad_tree(std::vector<std::vector<int>>& grid, int row, int column, int grid_size) {
  if(grid_size == 1) {
    return new QuadTree(grid[row][column], true);
  }
  
  QuadTree* top_left = construct_quad_tree(grid, row, column, grid_size / 2);
  QuadTree* top_right = construct_quad_tree(grid, row, column + (grid_size/2), grid_size / 2);
  QuadTree* bottom_left = construct_quad_tree(grid, row + (grid_size/2), column, grid_size / 2);
  QuadTree* bottom_right = construct_quad_tree(grid, row + (grid_size/2), column + (grid_size/2), grid_size / 2);
  
  if(top_left->is_leaf && top_right->is_leaf && bottom_left->is_leaf &&
     bottom_right->is_leaf && top_left->val == top_right->val &&
     top_left->val == bottom_left->val && top_left->val == bottom_right->val) {
    return new QuadTree(top_left->val, true);
  }
  
  return new QuadTree(top_left->val, false, top_left, top_right, bottom_left, bottom_right);
}
void invoke_construct_quad_tree() {
  std::vector<std::vector<int>> grid = {
    {1,1,1,1,0,0,0,0},
    {1,1,1,1,0,0,0,0},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,0,0,0,0},
    {1,1,1,1,0,0,0,0},
    {1,1,1,1,0,0,0,0},
    {1,1,1,1,0,0,0,0}
  };
  auto* root_node = construct_quad_tree(grid, 0, 0, grid.size());
  std::cout<<"427. Construct Quad Tree: "<<root_node->val<<", "<<std::boolalpha<<root_node->is_leaf;
  destroy_quad_tree(root_node);
}

bool same_tree(TreeNode* p, TreeNode* q) {
  if(!p && !q) {
    return true;
  }

  if((!p && q) || (p && !q)) {
    return false;
  }

  if(p->val != q->val) {
    return false;
  }

  return same_tree(p->left, q->left) && same_tree(p->right, q->right);
}
void invoke_same_tree() {
  TreeNode* tree_node_one = new TreeNode(1);
  tree_node_one->left = new TreeNode(2);
  TreeNode* tree_node_two = new TreeNode(1);
  tree_node_one->right = new TreeNode(2);
  std::cout<<std::boolalpha<<"100. Same Tree: "<<same_tree(tree_node_one, tree_node_two);
}
