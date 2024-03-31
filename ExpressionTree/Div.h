/**
 * @class Div.h
 * @brief This file defines the Div class, which represents a division operation in an expression tree.
 *
 * The Div class is derived from the OperatorNodes class. A division operation has two operands, which are the left and right children of the operation node.
 * The derivative of a division operation is computed using the quotient rule, and its value is the quotient of the values of its operands.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#pragma once
#include"OperatorNodes.h"

class Div : public OperatorNodes {
private:
	/**
	 * @brief Print the division operation to an output stream.
	 *
	 * @param out The output stream to print to.
	 * @return std::ostream& The output stream after printing.
	 */
	virtual std::ostream& print(std::ostream& out) const override;

public:
	/**
	 * @brief Construct a new Div object with given left and right children.
	 *
	 * @param left The left child of the operation node.
	 * @param right The right child of the operation node.
	 */
	Div(node_ptr left, node_ptr right);

	/**
	 * @brief Destroy the Div object.
	 */
	virtual ~Div() = default;

	/**
	 * @brief Set the right child of the operation node.
	 *
	 * @param right The new right child of the operation node.
	 */
	void setRight(node_ptr right);

	/**
	 * @brief Compute the derivative of the division operation with respect to a variable.
	 *
	 * The derivative of a division operation is computed using the quotient rule.
	 *
	 * @param var The variable to differentiate with respect to.
	 * @return node_ptr The derivative of the division operation.
	 */
	virtual node_ptr derivative(std::string var) const override;

	/**
	 * @brief Evaluate the value of the division operation.
	 *
	 * The value of a division operation is the quotient of the values of its operands.
	 *
	 * @return double The value of the division operation.
	 */
	virtual double evaluate() const override;
};
