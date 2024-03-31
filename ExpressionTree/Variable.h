/**
 * @class Variable.h
 * @brief This file defines the Variable class, which represents a variable in an expression tree.
 *
 * The Variable class is derived from the Node class. A variable has a name, which can be set and retrieved.
 * The derivative of a variable with respect to itself is one, and with respect to any other variable is zero.
 * The value of a variable is retrieved from a map table that maps variable names to their values.
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */

#pragma once
#include<string>
#include <map>
#include"Node.h"
#include"Constant.h"

class Variable : public Node {
private:

	// the name of the variable
	std::string variableName;

	/**
	 * @brief The map table that maps variable names to their values.
	 */
	static std::map<std::string, double> mapTable;

	/**
	 * @brief Print the variable to an output stream.
	 *
	 * @param out The output stream to print to.
	 * @return std::ostream& The output stream after printing.
	 */
	virtual std::ostream& print(std::ostream& out) const override;

public:
	/**
	 * @brief Construct a new Variable object with a given name.
	 *
	 * @param variableName The name of the variable.
	 */
	Variable(std::string variableName);

	/**
	 * @brief Destroy the Variable object.
	 */
	virtual ~Variable() = default;

	/**
	 * @brief Set the name of the variable.
	 *
	 * @param variableName The new name of the variable.
	 */
	void setVariable(std::string variableName);

	/**
	 * @brief Compute the derivative of the variable with respect to a variable.
	 *
	 * The derivative of a variable with respect to itself is one, and with respect to any other variable is zero.
	 *
	 * @param var The variable to differentiate with respect to.
	 * @return node_ptr The derivative of the variable.
	 */
	virtual node_ptr derivative(std::string var) const override;

	/**
	 * @brief Evaluate the value of the variable.
	 *
	 * The value of a variable is retrieved from the map table.
	 *
	 * @return double The value of the variable.
	 */
	virtual double evaluate() const override;

	/**
	 * @brief Set the map table that maps variable names to their values.
	 *
	 * @param mapTable The new map table.
	 */
	static void setMapTable(std::map<std::string, double> mapTable);

	/**
	 * @brief Get the map table that maps variable names to their values.
	 *
	 * @return const std::map<std::string, double>& The map table.
	 */
	static const std::map<std::string, double>& getMapTable() { return mapTable; }
};
