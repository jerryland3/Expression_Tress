/**
 * @file Div.cpp
 * @brief This file implements the Div class defined in Div.h.
 *
 * The Div class represents a division operation in an expression tree. This file provides the implementation
 * for the constructor, setRight, print, derivative, and evaluate functions of the Div class.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#include"Div.h"
#include"Mul.h"
#include"Sub.h"

 /**
  * @brief Construct a new Div object with given left and right children.
  *
  * @param left The left child of the operation node.
  * @param right The right child of the operation node.
  */
Div::Div(node_ptr left, node_ptr right) : OperatorNodes{ left, right } {
}

/**
 * @brief Set the right child of the operation node.
 *
 * This function checks if the right child is zero. If it is, it throws an exception. Otherwise, it sets the right child of the operation node.
 *
 * @param right The new right child of the operation node.
 */
void Div::setRight(node_ptr right) {
	// make sure right is not zero
	if (right->evaluate() == 0) {
		throw std::invalid_argument("Divisor cannot be zero");
	}
	OperatorNodes::setRight(right);
}

/**
 * @brief Print the division operation to an output stream.
 *
 * @param out The output stream to print to.
 * @return std::ostream& The output stream after printing.
 */
std::ostream& Div::print(std::ostream& out) const {
	out << "(" << getLeft() << " / " << getRight() << ")";
	return out;
}

/**
 * @brief Compute the derivative of the division operation with respect to a variable.
 *
 * The derivative of a division operation is computed using the quotient rule.
 *
 * @param var The variable to differentiate with respect to.
 * @return node_ptr The derivative of the division operation.
 */
Node::node_ptr Div::derivative(std::string var) const {
	return std::make_shared<Div>(std::make_shared<Sub>(std::make_shared<Mul>(getLeft()->derivative(var), getRight()), std::make_shared<Mul>(getLeft(), getRight()->derivative(var))), std::make_shared<Mul>(getRight(), getRight()));
}

/**
 * @brief Evaluate the value of the division operation.
 *
 * The value of a division operation is the quotient of the values of its operands.
 *
 * @return double The value of the division operation.
 */
double Div::evaluate() const {
	return getLeft()->evaluate() / getRight()->evaluate();
}