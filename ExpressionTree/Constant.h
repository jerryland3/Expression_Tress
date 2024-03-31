/**
 * @class Constant.h
 * @brief This file defines the Constant class, which represents a constant value in an expression tree.
 *
 * The Constant class is derived from the Node class. A constant has a value, which can be set and retrieved.
 * The derivative of a constant with respect to any variable is zero, and its value is the constant itself.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#pragma once
#include<string>
#include"Node.h"

class Constant : public Node {
private:
	// the value of the constant
	double value;

	/**
	 * @brief Print the constant to an output stream.
	 *
	 * @param out The output stream to print to.
	 * @return std::ostream& The output stream after printing.
	 */
	virtual std::ostream& print(std::ostream& out) const override;

public:
	/**
	 * @brief Construct a new Constant object with a given value.
	 *
	 * @param value The value of the constant.
	 */
	Constant(double value);

	/**
	 * @brief Destroy the Constant object.
	 */
	virtual ~Constant() = default;

	/**
	 * @brief Compute the derivative of the constant with respect to a variable.
	 *
	 * The derivative of a constant with respect to any variable is zero.
	 *
	 * @param var The variable to differentiate with respect to.
	 * @return node_ptr The derivative of the constant.
	 */
	virtual node_ptr derivative(std::string var) const override;

	/**
	 * @brief Evaluate the value of the constant.
	 *
	 * The value of a constant is the constant itself.
	 *
	 * @return double The value of the constant.
	 */
	virtual double evaluate() const override;

	/**
	 * @brief Set the value of the constant.
	 *
	 * @param value The new value of the constant.
	 */
	void setConstant(double value);
};