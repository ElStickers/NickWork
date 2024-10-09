// Lab 3 - BST_skeleton.cpp - rename it to BST.cpp
// Author: Nicklas Waananen

#include<iostream>
#include <vector>
#include <limits.h>
#include "BST.h"

// ***do not change the headers***

// you solutions go here
// remember that you do not need to implement all of them
// follow the document to see which ones you need to implement

BST::BST(){
}

BST::~BST(){}

std::shared_ptr < Node > BST::search(int target) {
  return search(root, target); // Begin search from the root
} 

std::shared_ptr < Node > BST::search(std::shared_ptr < Node > n, int target) {
  if (n == nullptr) {  // If the current node is null/doesn't exist, then return as null
    return nullptr;
  }

  if (n -> value == target) { // If current node fits target, return
    return n;
  }

  if (target < n -> value) { // If the target is smaller than current node, then go left 
    return search(n -> left, target);
  }
  return search(n -> right, target); // Or right if bigger
}

std::shared_ptr<Node> BST::minimum(){
  return nullptr;
}

std::shared_ptr<Node> BST::minimum(std::shared_ptr<Node> n){
  return nullptr;
}

std::shared_ptr<Node> BST::maximum(){
  return nullptr;
}

std::shared_ptr<Node> BST::maximum(std::shared_ptr<Node> n){
  return nullptr;
}

void BST::insertValue(int val) {
  if (root == nullptr) {
    root = std::make_shared <Node> (val); // Create a new root if current is null 
  } else {
    insertValue(root, val); // Otherwise, call for the insert
  }
}

std::shared_ptr <Node> BST::insertValue(std::shared_ptr < Node > n, int val) {
  if (n == nullptr) {
    return std::make_shared <Node> (val); 
  }
 
  if (val == n -> value) { // Don't want duplicates, return current node if the case
    return n;
  }

  if (val < n -> value) {
    n -> left = insertValue(n -> left, val); // If value less, go left, if more then go right
  } else {
    n -> right = insertValue(n -> right, val);
  }

  return n;
}

void BST::deleteValue(int val){
}

std::shared_ptr<Node> BST::deleteValue(std::shared_ptr<Node> n, int val){
  return nullptr;
}

bool BST::isBST(std::shared_ptr<Node> n){
  return false;
}

bool BST::isBST(std::shared_ptr<Node> n, int low, int high){
  return false;
}

void BST::preOrder(std::shared_ptr < Node > n, std::vector < std::shared_ptr < Node >> & order) {
  if (n != nullptr){ // Node that isn't null gets put in preOrder 

    order.push_back(n); // Used to add the current node in the proper traversal order

    preOrder(n -> left, order); // preorder left, and then right

    preOrder(n -> right, order);
  }
}

void BST::inOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
}

void BST::postOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
}
