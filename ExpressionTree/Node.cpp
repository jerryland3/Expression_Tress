/**
 * @file Node.cpp
 * @brief This file implements the Node class defined in Node.h.
 *
 * The Node class is the base class for all types of nodes in an expression tree. This file provides the implementation
 * for the stream insertion operator, which is used to print a node.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#include"Node.h"

 /**
  * @brief Overload the stream insertion operator to print the node.
  *
  * This function is a friend of the Node class, so it can access its private and protected members. It calls the print
  * function of the node to print it to the output stream.
  *
  * @param os The output stream to print to.
  * @param node The node to print.
  * @return std::ostream& The output stream after printing.
  */
std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Node> node) {
	return node->print(os);
}