#include"Variable.h"

std::map<std::string, double> Variable::mapTable;

using namespace std;

Variable::Variable(string symbol) : Node(symbol) {
}

void Variable::setMapTable(map<string, double> hashMap) {
	mapTable = hashMap;
}

shared_ptr<Node> Variable::derivative(string var) const {
	if (var == getSymbol()) {
		return std::make_shared<Constant>(1);
	}
	else {
		return std::make_shared<Constant>(0);
	}
}

ostream& Variable::print(ostream& out) const {
	out << getSymbol();
	return out;
}

double Variable::evaluate() const {
	return mapTable.at(getSymbol());
}