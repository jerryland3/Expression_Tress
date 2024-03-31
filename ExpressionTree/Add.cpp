/**
 * @file Add.cpp
 * @brief This file implements the Add class defined in Add.h.
 *
 * The Add class represents an addition operation in an expression tree. This file provides the implementation
 * for the constructor, print, derivative, and evaluate functions of the Add class.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#include"Add.h"

 /**
  * @brief Construct a new Add object with given left and right children.
  *
  * @param left The left child of the operation node.
  * @param right The right child of the operation node.
  */
Add::Add(node_ptr left, node_ptr right) : OperatorNodes(left, right) {
}

/**
 * @brief Print the addition operation to an output stream.
 *
 * @param out The output stream to print to.
 * @return std::ostream& The output stream after printing.
 */
std::ostream& Add::print(std::ostream& out) const {
	out << "(" << getLeft() << " + " << getRight() << ")";
	return out;
}

/**
 * @brief Compute the derivative of the addition operation with respect to a variable.
 *
 * The derivative of an addition operation is the sum of the derivatives of its operands.
 *
 * @param var The variable to differentiate with respect to.
 * @return node_ptr The derivative of the addition operation.
 */
Node::node_ptr Add::derivative(std::string var) const {
	return std::make_shared<Add>(getLeft()->derivative(var), getRight()->derivative(var));
}

/**
 * @brief Evaluate the value of the addition operation.
 *
 * The value of an addition operation is the sum of the values of its operands.
 *
 * @return double The value of the addition operation.
 */
double Add::evaluate() const {
	return getLeft()->evaluate() + getRight()->evaluate();
}