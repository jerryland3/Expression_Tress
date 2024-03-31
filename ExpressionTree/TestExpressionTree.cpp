/**
 * @file TestExoressionTree.cpp
 * @brief Contains the main() function for testing expression tree classes.
 *
 *
 * @date 3/26/2024
 * @version New
 * @author Jerry Wang
 */
#include<iostream>
#include"Node.h"
#include"Constant.h"
#include"Variable.h"
#include"Add.h"
#include"Sub.h"
#include"Mul.h"
#include"Div.h"
#include <map>

using namespace std;

int main() {
	// Define a map table for the variables
	map<string, double> mapTable = { {"Xray", 2}, {"Yellow", 3}, {"Zebra", 5}, {"MassEarth", 5.97219e24}, {"MassMoon", 7.34767309e22} };

	// Set the map table for the variables
	Variable::setMapTable(mapTable);

	// Define constants and variables
	auto constant1 = make_shared<Constant>(2.3);
	auto variableX = make_shared<Variable>("Xray");
	auto variableY = make_shared<Variable>("Yellow");
	auto variableZ = make_shared<Variable>("Zebra");

	// Define intermediate nodes
	auto mulNode1 = make_shared<Mul>(constant1, variableX);
	auto subNode1 = make_shared<Sub>(variableZ, variableX);
	auto mulNode2 = make_shared<Mul>(variableY, subNode1);

	// Construct the expression tree for equation: 2.3 * Xray + Yellow * (Zebra - Xray)
	shared_ptr<Node> nodePtr = make_shared<Add>(mulNode1, mulNode2);

	// make equation for gravitational force between Earth and Moon
	double distanceValue = 384400000;
	auto massEarth = make_shared<Variable>("MassEarth");
	auto massMoon = make_shared<Variable>("MassMoon");
	auto distanceSquared = make_shared<Constant>(distanceValue * distanceValue);
	auto gravConst = make_shared<Constant>(6.67430e-11);

	// define the intermediate nodes
	auto mulNode3 = make_shared<Mul>(massEarth, massMoon);
	auto mulNode4 = make_shared<Mul>(gravConst, mulNode3);

	// Construct the expression tree for equation: G * MassEarth * MassMoon / (distanceValue * distanceValue)
	shared_ptr<Node> nodePtrGrav = make_shared<Div>(mulNode4, distanceSquared);

	// print the mapTable
	cout << "Variable Table:" << endl;
	for (auto& pair : mapTable) {
		cout << pair.first << " : " << pair.second << endl;
	}

	// Print expression tree and evaluate
	cout << "\nExpression Tree:" << endl;
	cout << "print : " << nodePtr << endl;
	cout << "evaluate: " << nodePtr->evaluate() << endl;

	// Compute derivative with respect to Xray
	shared_ptr<Node> nodePtr2 = nodePtr->derivative("Xray");
	cout << "derivative x: " << nodePtr2 << std::endl;
	cout << "derivative x evaluate: " << nodePtr2->evaluate() << endl;

	// Compute derivative with respect to Yellow
	shared_ptr<Node> nodePtr3 = nodePtr->derivative("Yellow");
	cout << "derivative y: " << nodePtr3 << std::endl;
	cout << "derivative y evaluate: " << nodePtr3->evaluate() << endl;

	// Print expression tree for gravitational force and evaluate
	cout << "\nExpression Tree for Gravitational Force Between Earth and Moon:" << endl;
	cout << "print : " << nodePtrGrav << endl;
	cout << "evaluate: " << nodePtrGrav->evaluate() << " Newtons" << endl;

	// Compute derivative with respect to MassEarth
	shared_ptr<Node> nodePtr4 = nodePtrGrav->derivative("MassEarth");
	cout << "derivative MassEarth: " << nodePtr4 << std::endl;
	cout << "derivative MassEarth evaluate: " << nodePtr4->evaluate() << " Newtons/Mass" << endl;

	return 0;
}