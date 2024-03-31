/**
 * @class Sub.h
 * @brief This file defines the Sub class, which represents a subtraction operation in an expression tree.
 *
 * The Sub class is derived from the OperatorNodes class. A subtraction operation has two operands, which are the left and right children of the operation node.
 * The derivative of a subtraction operation is the difference of the derivatives of its operands, and its value is the difference of the values of its operands.
 *
 * * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#pragma once
#include"OperatorNodes.h"

class Sub : public OperatorNodes {
private:
	/**
	 * @brief Print the subtraction operation to an output stream.
	 *
	 * @param out The output stream to print to.
	 * @return std::ostream& The output stream after printing.
	 */
	virtual std::ostream& print(std::ostream& out) const override;

public:
	/**
	 * @brief Construct a new Sub object with given left and right children.
	 *
	 * @param left The left child of the operation node.
	 * @param right The right child of the operation node.
	 */
	Sub(node_ptr left, node_ptr right);

	/**
	 * @brief Destroy the Sub object.
	 */
	virtual ~Sub() = default;

	/**
	 * @brief Compute the derivative of the subtraction operation with respect to a variable.
	 *
	 * The derivative of a subtraction operation is the difference of the derivatives of its operands.
	 *
	 * @param var The variable to differentiate with respect to.
	 * @return node_ptr The derivative of the subtraction operation.
	 */
	virtual node_ptr derivative(std::string var) const override;

	/**
	 * @brief Evaluate the value of the subtraction operation.
	 *
	 * The value of a subtraction operation is the difference of the values of its operands.
	 *
	 * @return double The value of the subtraction operation.
	 */
	virtual double evaluate() const override;
};
