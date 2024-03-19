#include<iostream>
#include"Node.h"
#include"Constant.h"
#include"Variable.h"
#include"Add.h"
#include"Sub.h"
#include"Mul.h"
#include <map>

using namespace std;

int main() {
	// Define a map table for the variables
	map<string, double> mapTable = { {"x", 2}, {"y", 3}, {"z", 5} };
	Variable::setMapTable(mapTable);

	// Define constants and variables
	auto constant1 = make_shared<Constant>(2.3);
	auto variableX = make_shared<Variable>("x");
	auto variableY = make_shared<Variable>("y");
	auto variableZ = make_shared<Variable>("z");

	// Define intermediate nodes
	auto mulNode1 = make_shared<Mul>(constant1, variableX);
	auto subNode1 = make_shared<Sub>(variableZ, variableX);
	auto mulNode2 = make_shared<Mul>(variableY, subNode1);

	// Construct the expression tree
	shared_ptr<Node> nodePtr = make_shared<Add>(mulNode1, mulNode2);

	// Print expression tree and evaluate
	cout << "\nExpression Tree:" << endl;
	cout << "print : " << nodePtr << endl;
	cout << "evaluate: " << nodePtr->evaluate() << endl;

	// Compute derivative with respect to x
	shared_ptr<Node> nodePtr2 = nodePtr->derivative("x");
	cout << "derivative x: " << nodePtr2 << std::endl;
	cout << "derivative x evaluate: " << nodePtr2->evaluate() << endl;

	return 0;
}