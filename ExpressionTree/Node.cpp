#include"Node.h"

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Node> node) {
	return node->print(os);
}