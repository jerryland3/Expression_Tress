/**
 * @file Constant.cpp
 * @brief This file implements the Constant class defined in Constant.h.
 *
 * The Constant class represents a constant value in an expression tree. This file provides the implementation
 * for the constructor, print, derivative, evaluate, and setConstant functions of the Constant class.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#include"Constant.h"
using namespace std;

/**
 * @brief Construct a new Constant object with a given value.
 *
 * @param value The value of the constant.
 */
Constant::Constant(double value) : Node(), value{ value } {
}

/**
 * @brief Set the value of the constant.
 *
 * @param value The new value of the constant.
 */
void Constant::setConstant(double value) {
	this->value = value;
}

/**
 * @brief Compute the derivative of the constant with respect to a variable.
 *
 * The derivative of a constant with respect to any variable is zero.
 *
 * @param var The variable to differentiate with respect to.
 * @return node_ptr The derivative of the constant.
 */
Node::node_ptr Constant::derivative(string var) const {
	return std::make_shared<Constant>(0);
}

/**
 * @brief Print the constant to an output stream.
 *
 * @param out The output stream to print to.
 * @return std::ostream& The output stream after printing.
 */
ostream& Constant::print(ostream& out) const {
	out << value;
	return out;
}

/**
 * @brief Evaluate the value of the constant.
 *
 * The value of a constant is the constant itself.
 *
 * @return double The value of the constant.
 */
double Constant::evaluate() const {
	return value;
}