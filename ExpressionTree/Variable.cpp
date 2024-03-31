/**
 * @file Variable.cpp
 * @brief This file implements the Variable class defined in Variable.h.
 *
 * The Variable class represents a variable in an expression tree. This file provides the implementation
 * for the constructor, print, derivative, evaluate, setVariable, and setMapTable functions of the Variable class.
 */

#include"Variable.h"
using namespace std;

// Initialize the map table
std::map<std::string, double> Variable::mapTable;

/**
 * @brief Construct a new Variable object with a given name.
 *
 * @param varName The name of the variable.
 */
Variable::Variable(string varName) : Node(), variableName{ varName } {
}

/**
 * @brief Set the map table that maps variable names to their values.
 *
 * @param hashMap The new map table.
 */
void Variable::setMapTable(map<string, double> hashMap) {
	mapTable = hashMap;
}

/**
 * @brief Set the name of the variable.
 *
 * @param varName The new name of the variable.
 */
void Variable::setVariable(string varName) {
	variableName = varName;
}

/**
 * @brief Compute the derivative of the variable with respect to a variable.
 *
 * The derivative of a variable with respect to itself is one, and with respect to any other variable is zero.
 *
 * @param varName The variable to differentiate with respect to.
 * @return node_ptr The derivative of the variable.
 */
Node::node_ptr Variable::derivative(string varName) const {
	if (varName == variableName) {
		return std::make_shared<Constant>(1);
	}
	else {
		return std::make_shared<Constant>(0);
	}
}

/**
 * @brief Print the variable to an output stream.
 *
 * @param out The output stream to print to.
 * @return std::ostream& The output stream after printing.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */
ostream& Variable::print(ostream& out) const {
	out << variableName;
	return out;
}

/**
 * @brief Evaluate the value of the variable.
 *
 * The value of a variable is retrieved from the map table.
 *
 * @return double The value of the variable.
 */
double Variable::evaluate() const {
	return mapTable.at(variableName);
}