#pragma once

#include <queue>
#include <vector>

namespace Data_Structures
{
	template<typename T>
	class Binary_Search_Tree
	{
	private:
		struct Node
		{
			T data {};
			Node* left = nullptr;
			Node* right = nullptr;
			Node* parent = nullptr;

			Node(const T& data) : data{data}, left{nullptr}, right{nullptr}, parent{nullptr}
			{}
		};

		Node* root = nullptr;

	public:
		Binary_Search_Tree()
		{}

		~Binary_Search_Tree()
		{}

		bool Contains(const T& data)
		{
			return Node_Pointer(data);
		}

		std::vector<T> Depth_First_Search_In_Order()
		{
			std::vector<T> vector;
			Traverse_In_Order(root, vector);
			return vector;
		}

		std::vector<T> Depth_First_Search_Pre_Order()
		{
			std::vector<T> vector;
			Traverse_Pre_Order(root, vector);
			return vector;
		}

		std::vector<T> Depth_First_Search_Post_Order()
		{
			std::vector<T> vector;
			Traverse_Post_Order(root, vector);
			return vector;
		}

		std::vector<T> Breadth_First_Search()
		{
			Node* node = root;
			std::vector<T> vector;
			std::queue<Node*> queue;

			queue.push(node);

			while(queue.size() > 0)
			{
				node = queue.front();
				queue.pop();
				vector.push_back(node->data);

				if(node->left != nullptr)
				{
					queue.push(node->left);
				}

				if(node->right != nullptr)
				{
					queue.push(node->right);
				}
			}

			return vector;
		}

		void Insert(const T& data)
		{
			if(Contains(data) == true)
			{
				return;
			}

			Node* pointer = root;
			Node* node = new Node(data);

			while(true)
			{
				if(root == nullptr)
				{
					root = node;
					return;
				}

				if(data < pointer->data)
				{
					if(pointer->left != nullptr)
					{
						pointer = pointer->left;
					}
					else if(pointer->left == nullptr)
					{
						pointer->left = node;
						node->parent = pointer;
						return;
					}
				}
				else if(data > pointer->data)
				{
					if(pointer->right != nullptr)
					{
						pointer = pointer->right;
					}
					else if(pointer->right == nullptr)
					{
						pointer->right = node;
						node->parent = pointer;
						return;
					}
				}
			}
		}

		void Remove(const T& data)
		{
			Node* node = Node_Pointer(data);

			if(node == nullptr)
			{
				return;
			}

			Node* successor = Node_Successor(node);

			if(node == root)
			{
				root = successor;
			}
			else if(node != root)
			{
				if(node == node->parent->left)
				{
					node->parent->left = successor;
				}
				else if(node == node->parent->right)
				{
					node->parent->right = successor;
				}
			}

			if(successor != nullptr)
			{
				if(successor == node->left)
				{
					successor->right = node->right;

					if(node->right != nullptr)
					{
						node->right->parent = successor;
					}
				}
				else if(successor == node->right)
				{
					successor->left = node->left;

					if(node->left != nullptr)
					{
						node->left->parent = successor;
					}
				}
				else if(successor != node->left && successor != node->right)
				{
					if(successor->right != nullptr)
					{
						successor->parent->left = successor->right;
					}

					successor->right = node->right;
				}

				successor->parent = node->parent;
			}

			delete node;
		}

	private:
		void Traverse_Pre_Order(Node* node, std::vector<T>& vector)
		{
			vector.push_back(node->data);

			if(node->left != nullptr)
			{
				Traverse_Pre_Order(node->left, vector);
			}

			if(node->right != nullptr)
			{
				Traverse_Pre_Order(node->right, vector);
			}
		}

		void Traverse_In_Order(Node* node, std::vector<T>& vector)
		{
			if(node->left != nullptr)
			{
				Traverse_In_Order(node->left, vector);
			}

			vector.push_back(node->data);

			if(node->right != nullptr)
			{
				Traverse_In_Order(node->right, vector);
			}
		}

		void Traverse_Post_Order(Node* node, std::vector<T>& vector)
		{
			if(node->left != nullptr)
			{
				Traverse_Post_Order(node->left, vector);
			}

			if(node->right != nullptr)
			{
				Traverse_Post_Order(node->right, vector);
			}

			vector.push_back(node->data);
		}

		Node* Node_Pointer(const T& data)
		{
			if(root == nullptr)
			{
				return nullptr;
			}

			Node* pointer = root;

			while(true)
			{
				if(pointer->data == data)
				{
					return pointer;
				}
				else
				{
					if(data < pointer->data)
					{
						if(pointer->left == nullptr)
						{
							return nullptr;
						}
						else
						{
							pointer = pointer->left;
							continue;
						}
					}
					else if(data > pointer->data)
					{
						if(pointer->right == nullptr)
						{
							return nullptr;
						}
						else
						{
							pointer = pointer->right;
							continue;
						}
					}
				}
			}
		}

		Node* Node_Successor(const Node* node)
		{
			if(node->left == nullptr && node->right == nullptr)
			{
				return nullptr;
			}
			else if(node->left != nullptr && node->right == nullptr)
			{
				return node->left;
			}
			else if(node->right != nullptr && node->right->left == nullptr)
			{
				return node->right;
			}
			else if(node->right != nullptr && node->right->left != nullptr)
			{
				Node* successor = node->right->left;

				while(successor->left != nullptr)
				{
					successor = successor->left;
					return successor;
				}
			}

			return nullptr;
		}
	};
}