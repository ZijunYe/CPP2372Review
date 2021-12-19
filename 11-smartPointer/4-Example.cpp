

#include <iostream>
#include <memory>
#include <vector>

class Node {
    int value;
  public:
    Node(int v) : value(v) {}
    ~Node() { std::cout << "Node: " << value << " destroyed!" << std::endl; }
    //std::shared_ptr<Node> parent; // no!
    std::weak_ptr<Node> parent; // important to avoid circular dependency
    std::pair <std::shared_ptr<Node>,std::shared_ptr<Node>> children;
    int getValue() const { return value; }
};

void inordre(std::shared_ptr<Node> n) {
    
    if (n==nullptr) return;
    inordre(n->children.first);
    std::cout << n->getValue() <<" ";
    inordre(n->children.second);
}

int main() {
    
    std::cout << "Construction of the tree\n";
    // The root of the tree.
    std::shared_ptr<Node> root(new Node(1));
    // left sub-tree
    std::shared_ptr<Node> n(new Node(2));
    n->children.first= std::make_shared<Node>(3);
    n->children.second= std::make_shared<Node>(4);
    n->children.first->parent=n;
    n->children.second->parent=n;
    root->children.first= n;
    n->parent= root;
    // right sub-tree
    n= std::make_shared<Node>(5);
    n->children.first= std::make_shared<Node>(6);
    n->children.second= std::make_shared<Node>(7);
    n->children.first->parent=n;
    n->children.second->parent=n;
    root->children.second= n;
    n->parent= root;
    n.reset();
    std::cout << "End of construction\n";
    
    inordre(root);
    std::cout << std::endl;
    
    // destruction of the child on the right
    root->children.first.reset();
    inordre(root);
    std::cout << std::endl;
    
    std::cout << "End of the program\n";
}
    /*----------------- results ----------------------*\
   Construction of the tree
	End of construction
	3 2 4 1 6 5 7
	Node: 2 destroyed!
	Node: 4 destroyed!
	Node: 3 destroyed!
	1 6 5 7
	End of the program
	Node: 1 destroyed!
	Node: 5 destroyed!
	Node: 7 destroyed!
N	ode: 6 destroyed!
    \*-------------------------------------------------*/





