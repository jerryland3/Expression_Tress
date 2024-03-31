/**
 * @class OperatorNodes.h
 * @brief This file defines the abstract OperatorNodes class, which represents an operation in an expression tree.
 *
 * The OperatorNodes class is derived from the Node class. An operation has two operands, which can be any nodes.
 * The operands are represented as left and right children of the operation node. The derivative and value of an operation
 * depend on the specific type of operation.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#pragma once
#include"Node.h"

class OperatorNodes : public Node {
private:

	// left and right children of the operation node
	node_ptr leftPtr;
	node_ptr rightPtr;

	/**
	 * @brief Print the operation to an output stream.
	 *
	 * This is a pure virtual function, so it must be overridden by all derived classes.
	 *
	 * @param out The output stream to print to.
	 * @return std::ostream& The output stream after printing.
	 */
	virtual std::ostream& print(std::ostream& out) const = 0;

public:
	/**
	 * @brief Construct a new OperatorNodes object with given left and right children.
	 *
	 * @param left The left child of the operation node.
	 * @param right The right child of the operation node.
	 */
	OperatorNodes(node_ptr left, node_ptr right);

	/**
	 * @brief Destroy the OperatorNodes object.
	 */
	virtual ~OperatorNodes() = default;

	/**
	 * @brief Compute the derivative of the operation with respect to a variable.
	 *
	 * This is a pure virtual function, so it must be overridden by all derived classes.
	 *
	 * @param var The variable to differentiate with respect to.
	 * @return node_ptr The derivative of the operation.
	 */
	virtual node_ptr derivative(std::string var) const = 0;

	/**
	 * @brief Evaluate the value of the operation.
	 *
	 * This is a pure virtual function, so it must be overridden by all derived classes.
	 *
	 * @return double The value of the operation.
	 */
	virtual double evaluate() const = 0;

	/**
	 * @brief Get the left child of the operation node.
	 *
	 * @return node_ptr The left child of the operation node.
	 */
	node_ptr getLeft() const { return leftPtr; }

	/**
	 * @brief Get the right child of the operation node.
	 *
	 * @return node_ptr The right child of the operation node.
	 */
	node_ptr getRight() const { return rightPtr; }

	/**
	 * @brief Set the left child of the operation node.
	 *
	 * @param left The new left child of the operation node.
	 */
	void setLeft(node_ptr left);

	/**
	 * @brief Set the right child of the operation node.
	 *
	 * @param right The new right child of the operation node.
	 */
	void setRight(node_ptr right);
};
