/**
 * @file Mul.cpp
 * @brief This file implements the Mul class defined in Mul.h.
 *
 * The Mul class represents a multiplication operation in an expression tree. This file provides the implementation
 * for the constructor, print, derivative, and evaluate functions of the Mul class.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#include"Mul.h"
#include"Add.h"

 /**
  * @brief Construct a new Mul object with given left and right children.
  *
  * @param left The left child of the operation node.
  * @param right The right child of the operation node.
  */
Mul::Mul(node_ptr left, node_ptr right) : OperatorNodes{ left, right } {
}

/**
 * @brief Print the multiplication operation to an output stream.
 *
 * @param out The output stream to print to.
 * @return std::ostream& The output stream after printing.
 */
std::ostream& Mul::print(std::ostream& out) const {
	out << "(" << getLeft() << " * " << getRight() << ")";
	return out;
}

/**
 * @brief Compute the derivative of the multiplication operation with respect to a variable.
 *
 * The derivative of a multiplication operation is computed using the product rule.
 *
 * @param var The variable to differentiate with respect to.
 * @return node_ptr The derivative of the multiplication operation.
 */
Node::node_ptr Mul::derivative(std::string var) const {
	return std::make_shared<Add>(std::make_shared<Mul>(getLeft()->derivative(var), getRight()), std::make_shared<Mul>(getLeft(), getRight()->derivative(var)));
}

/**
 * @brief Evaluate the value of the multiplication operation.
 *
 * The value of a multiplication operation is the product of the values of its operands.
 *
 * @return double The value of the multiplication operation.
 */
double Mul::evaluate() const {
	return getLeft()->evaluate() * getRight()->evaluate();
}