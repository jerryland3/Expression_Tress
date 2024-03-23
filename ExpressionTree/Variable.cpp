#include"Variable.h"

std::map<std::string, double> Variable::mapTable;

using namespace std;

Variable::Variable(string varName) : Node(), variableName{ varName } {
}

void Variable::setMapTable(map<string, double> hashMap) {
	mapTable = hashMap;
}

void Variable::setVariable(string varName) {
	variableName = varName;
}

shared_ptr<Node> Variable::derivative(string varName) const {
	if (varName == variableName) {
		return std::make_shared<Constant>(1);
	}
	else {
		return std::make_shared<Constant>(0);
	}
}

ostream& Variable::print(ostream& out) const {
	out << variableName;
	return out;
}

double Variable::evaluate() const {
	return mapTable.at(variableName);
}