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

		void Print()
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
			if(root == nullptr)
			{
				return false;
			}

			Node* pointer = root;

			while(true)
			{
				if(pointer->data == data)
				{
					return true;
				}
				else
				{
					if(data < pointer->data)
					{
						if(pointer->left == nullptr)
						{
							return false;
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
							return false;
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
			if(Contains(data) == false)
			{
				return;
			}

			Node* pointer = Node_Pointer(data);
			Node* successor = Node_Successor(pointer);

			if(successor == nullptr)
			{
				if(pointer == root)
				{
					min_value = {};
					max_value = {};
					root = nullptr;
					delete pointer;
					return;
				}

				if(pointer->data < pointer->parent->data)
				{
					if(pointer->data == min_value)
					{
						min_value = pointer->parent->data;
					}

					pointer->parent->left = nullptr;
					delete pointer;
					return;
				}
				else if(pointer->data > pointer->parent->data)
				{
					if(pointer->data == max_value)
					{
						max_value = pointer->parent->data;
					}

					pointer->parent->right = nullptr;
					delete pointer;
					return;
				}
			}
			else if(successor != nullptr)
			{
				if(pointer == root)
				{
					root = successor;
					successor->parent = nullptr;

					if(pointer->left != successor)
					{
						successor->left = pointer->left;
					}

					if(pointer->right != successor)
					{
						successor->right = pointer->right;
					}

					delete pointer;
					return;
				}

				if(pointer->parent->left == pointer)
				{
					pointer->parent->left = successor;
				}
				else if(pointer->parent->right == pointer)
				{
					pointer->parent->right = successor;
				}

				if(pointer->left != successor)
				{
					successor->left = pointer->left;
				}

				if(pointer->right != successor)
				{
					successor->right = pointer->right;
				}

				if(successor == pointer->right->left)
				{
					pointer->right->left = nullptr;
				}

				delete pointer;
				return;
			}
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

		Node* Node_Pointer(const T& data) noexcept
		{
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
			else if(node->left == nullptr && node->right != nullptr)
			{
				return node->right;
			}
			else if(node->left != nullptr && node->right != nullptr)
			{
				if(node->right->left != nullptr)
				{
					return node->right->left;
				}
				else if(node->right->left == nullptr)
				{
					return node->right;
				}
			}

			return nullptr;
		}
	};
}