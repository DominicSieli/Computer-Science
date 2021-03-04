#pragma once

#include <iostream>

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

		void Print()
        {
			if(root == nullptr)
			{
				return;
			}

            Print(root);
            std::cout << '\n';
        }

		bool Contains(const T& data)
		{
			return Node_Pointer(data);
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
		void Print(Node* node)
        {
            if(node == nullptr)
            {
                return;
            }

            Print(node->left);
            std::cout << node->data << " ";
            Print(node->right);
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