#include <iostream>
#include <memory>

template <typename T>
struct btNode { 
	T data; 
	std::unique_ptr<btNode<T>> l, r;
};

template <typename T>
std::unique_ptr<btNode<T>> new_bt_Node(T data) {
	auto node = std::unique_ptr<btNode<T>>(new btNode<T>{data, nullptr, nullptr});
	return node;
}
	
template <typename T>
void printInorder(std::unique_ptr<btNode<T>>&node) 
{ 
	if (node == nullptr) 
		return; 
	printInorder(node->l); 
	std::cout << node->data << " ";
	printInorder(node->r); 
} 
