/**
 * @class Mul.h
 * @brief This file defines the Mul class, which represents a multiplication operation in an expression tree.
 *
 * The Mul class is derived from the OperatorNodes class. A multiplication operation has two operands, which are the left and right children of the operation
 * node.
 * The derivative of a multiplication operation is computed using the product rule, and its value is the product of the values of its operands.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#pragma once
#include"OperatorNodes.h"

class Mul : public OperatorNodes {
private:
	/**
	 * @brief Print the multiplication operation to an output stream.
	 *
	 * @param out The output stream to print to.
	 * @return std::ostream& The output stream after printing.
	 */
	virtual std::ostream& print(std::ostream& out) const override;

public:
	/**
	 * @brief Construct a new Mul object with given left and right children.
	 *
	 * @param left The left child of the operation node.
	 * @param right The right child of the operation node.
	 */
	Mul(node_ptr left, node_ptr right);

	/**
	 * @brief Destroy the Mul object.
	 */
	virtual ~Mul() = default;

	/**
	 * @brief Compute the derivative of the multiplication operation with respect to a variable.
	 *
	 * The derivative of a multiplication operation is computed using the product rule.
	 *
	 * @param var The variable to differentiate with respect to.
	 * @return node_ptr The derivative of the multiplication operation.
	 */
	virtual node_ptr derivative(std::string var) const override;

	/**
	 * @brief Evaluate the value of the multiplication operation.
	 *
	 * The value of a multiplication operation is the product of the values of its operands.
	 *
	 * @return double The value of the multiplication operation.
	 */
	virtual double evaluate() const override;
};
