/**
 * @file OperatorNodes.cpp
 * @brief This file implements the OperatorNodes class defined in OperatorNodes.h.
 *
 * The OperatorNodes class represents an operation in an expression tree. This file provides the implementation
 * for the constructor, setLeft, and setRight functions of the OperatorNodes class.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#include"OperatorNodes.h"

 /**
  * @brief Construct a new OperatorNodes object with given left and right children.
  *
  * @param left The left child of the operation node.
  * @param right The right child of the operation node.
  */
OperatorNodes::OperatorNodes(node_ptr left, node_ptr right) : Node() {
	setLeft(left);
	setRight(right);
}

/**
 * @brief Set the left child of the operation node.
 *
 * This function checks if the left child is null. If it is, it throws an exception. Otherwise, it sets the left child of the operation node.
 *
 * @param left The new left child of the operation node.
 */
void OperatorNodes::setLeft(node_ptr left) {
	// make sure the left node is not null
	if (left == nullptr) {
		throw std::invalid_argument("left node is null");
	}
	this->leftPtr = left;
}

/**
 * @brief Set the right child of the operation node.
 *
 * This function checks if the right child is null. If it is, it throws an exception. Otherwise, it sets the right child of the operation node.
 *
 * @param right The new right child of the operation node.
 */
void OperatorNodes::setRight(node_ptr right) {
	// make sure the right node is not null
	if (right == nullptr) {
		throw std::invalid_argument("right node is null");
	}
	this->rightPtr = right;
}