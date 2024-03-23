#pragma once
#include<string>
#include <map>
#include"Node.h"
#include"Constant.h"

class Variable : public Node {
private:
	std::string variableName;
	static std::map<std::string, double> mapTable;
	virtual std::ostream& print(std::ostream& out) const override;

public:
	Variable(std::string variableName);
	virtual ~Variable() = default;
	void setVariable(std::string variableName);

	virtual std::shared_ptr<Node> derivative(std::string var) const override;
	virtual double evaluate() const override;

	static void setMapTable(std::map<std::string, double> mapTable);
	static const std::map<std::string, double>& getMapTable() { return mapTable; }
};
