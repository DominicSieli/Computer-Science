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

		T min_value {};
		T max_value {};
		Node* root = nullptr;

	public:
		Binary_Search_Tree(const T& data) : min_value{data}, max_value{data}, root{new Node(data)}
		{}

		~Binary_Search_Tree()
		{}

		void Print() const noexcept
		{
			Print(root);
			std::cout << '\n';
		}

		constexpr T Min_Value() const noexcept
		{
			return min_value;
		}

		constexpr T Max_Value() const noexcept
		{
			return max_value;
		}

		bool Contains(const T& data) const noexcept
		{
			return Node_Pointer(data);
		}

		void Insert(const T& data) noexcept
		{
			if(Contains(data) == true)
			{
				return;
			}

			if(data < min_value)
			{
				min_value = data;
			}

			if(data > max_value)
			{
				max_value = data;
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

		void Remove(const T& data) noexcept
		{
			Node* pointer = Node_Pointer(data);

			if(pointer == nullptr)
			{
				return;
			}

			Node* successor = Node_Successor(pointer);

			if(successor == nullptr)
			{
				Remove_Leaf(pointer);
			}
			else if(successor != nullptr)
			{
				Remove_Branch(pointer, successor);
			}
		}

	private:
		void Print(Node* node) const noexcept
		{
			if(node == nullptr)
			{
				return;
			}

			Print(node->left);
			std::cout << node->data << " ";
			Print(node->right);
		}

		Node* Node_Pointer(const T& data) const noexcept
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

		Node* Node_Successor(const Node* node) const noexcept
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
				return node->right->left;
			}
			else
			{
				return nullptr;
			}
		}

		void Remove_Leaf(const Node* node)
		{
			if(node == root)
			{
				delete root;
				min_value = {};
				max_value = {};
				root = nullptr;
				return;
			}
			else if(node != root)
			{
				if(node == node->parent->left)
				{
					if(node->data == min_value)
					{
						min_value = node->parent->data;
					}

					node->parent->left = nullptr;
			    	delete node;
					return;
				}
				else if(node == node->parent->right)
				{
					if(node->data == max_value)
					{
						max_value = node->parent->data;
					}

					node->parent->right = nullptr;
			    	delete node;
					return;
				}
			}
		}

		void Remove_Branch(const Node* node, const Node* successor)
		{
			if(node == root)
			{
				delete root;
				min_value = {};
				max_value = {};
				root = nullptr;
				return;
			}
			else if(node != root)
			{
				if(node == node->parent->left)
				{
					if(node->data == min_value)
					{
						min_value = node->parent->data;
					}

					node->parent->left = nullptr;
			    	delete node;
					return;
				}
				else if(node == node->parent->right)
				{
					if(node->data == max_value)
					{
						max_value = node->parent->data;
					}

					node->parent->right = nullptr;
			    	delete node;
					return;
				}
			}
		}
	};
}