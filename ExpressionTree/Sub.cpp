/**
 * @file Sub.cpp
 * @brief This file implements the Sub class defined in Sub.h.
 *
 * The Sub class represents a subtraction operation in an expression tree. This file provides the implementation
 * for the constructor, print, derivative, and evaluate functions of the Sub class.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#include"Sub.h"

 /**
  * @brief Construct a new Sub object with given left and right children.
  *
  * @param left The left child of the operation node.
  * @param right The right child of the operation node.
  */
Sub::Sub(node_ptr left, node_ptr right) : OperatorNodes{ left, right } {
}

/**
 * @brief Print the subtraction operation to an output stream.
 *
 * @param out The output stream to print to.
 * @return std::ostream& The output stream after printing.
 */
std::ostream& Sub::print(std::ostream& out) const {
	out << "(" << getLeft() << " - " << getRight() << ")";
	return out;
}

/**
 * @brief Compute the derivative of the subtraction operation with respect to a variable.
 *
 * The derivative of a subtraction operation is the difference of the derivatives of its operands.
 *
 * @param var The variable to differentiate with respect to.
 * @return node_ptr The derivative of the subtraction operation.
 */
Node::node_ptr Sub::derivative(std::string var) const {
	return std::make_shared<Sub>(getLeft()->derivative(var), getRight()->derivative(var));
}

/**
 * @brief Evaluate the value of the subtraction operation.
 *
 * The value of a subtraction operation is the difference of the values of its operands.
 *
 * @return double The value of the subtraction operation.
 */
double Sub::evaluate() const {
	return getLeft()->evaluate() - getRight()->evaluate();
}