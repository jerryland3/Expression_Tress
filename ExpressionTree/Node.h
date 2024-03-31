/**
 * @class Node.h
 * @brief This file defines the Node class, which serves as the base class for all types of nodes in an expression tree.
 *
 * The Node class provides a common interface for all types of nodes, including operations (like addition, subtraction, multiplication
 * and division) and operands (like constants and variables). Each node can print itself, compute its derivative, and evaluate its value.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#pragma once
#include<string>
#include<iostream>

class Node {
	/**
	 * @brief Overload the stream insertion operator to print the expression tree.
	 *
	 * This function is a friend of the Node class, so it can access its private and protected members.
	 *
	 * @param os The output stream to print to.
	 * @param node The node to print.
	 * @return std::ostream& The output stream after printing.
	 */
	friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Node> node);

protected:

	// Define a type alias for a shared pointer to a Node object
	using node_ptr = std::shared_ptr<Node>;

private:
	/**
	 * @brief Print the node to an output stream.
	 *
	 * This is a pure virtual function, so it must be overridden by all derived classes.
	 *
	 * @param out The output stream to print to.
	 * @return std::ostream& The output stream after printing.
	 */
	virtual std::ostream& print(std::ostream& out) const = 0;

public:
	/**
	 * @brief Construct a new Node object.
	 */
	Node() {};

	/**
	 * @brief Destroy the Node object.
	 */
	virtual ~Node() {}

	/**
	 * @brief Compute the derivative of the node with respect to a variable.
	 *
	 * This is a pure virtual function, so it must be overridden by all derived classes.
	 *
	 * @param var The variable to differentiate with respect to.
	 * @return node_ptr The derivative of the node.
	 */
	virtual node_ptr derivative(std::string var) const = 0;

	/**
	 * @brief Evaluate the value of the node.
	 *
	 * This is a pure virtual function, so it must be overridden by all derived classes.
	 *
	 * @return double The value of the node.
	 */
	virtual double evaluate() const = 0;
};