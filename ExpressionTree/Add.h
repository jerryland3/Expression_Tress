/**
 * @class Add.h
 * @brief This file defines the Add class, which represents an addition operation in an expression tree.
 *
 * The Add class is derived from the OperatorNodes class. An addition operation has two operands, which are the left and right children of the operation node.
 * The derivative of an addition operation is the sum of the derivatives of its operands, and its value is the sum of the values of its operands.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#pragma once
#include"OperatorNodes.h"

class Add : public OperatorNodes {
private:
	/**
	 * @brief Print the addition operation to an output stream.
	 *
	 * @param out The output stream to print to.
	 * @return std::ostream& The output stream after printing.
	 *
	 */
	virtual std::ostream& print(std::ostream& out) const override;

public:
	/**
	 * @brief Construct a new Add object with given left and right children.
	 *
	 * @param left The left child of the operation node.
	 * @param right The right child of the operation node.
	 */
	Add(node_ptr left, node_ptr right);

	/**
	 * @brief Destroy the Add object.
	 */
	virtual ~Add() = default;

	/**
	 * @brief Compute the derivative of the addition operation with respect to a variable.
	 *
	 * The derivative of an addition operation is the sum of the derivatives of its operands.
	 *
	 * @param var The variable to differentiate with respect to.
	 * @return node_ptr The derivative of the addition operation.
	 */
	virtual node_ptr derivative(std::string var) const override;

	/**
	 * @brief Evaluate the value of the addition operation.
	 *
	 * The value of an addition operation is the sum of the values of its operands.
	 *
	 * @return double The value of the addition operation.
	 */
	virtual double evaluate() const override;
};
