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

            Node(const T& data) : data{data}
            {}
        };

        Node* root = nullptr;

    public:
    	Binary_Search_Tree()
		{}

        Binary_Search_Tree(const T& data) : root{new Node(data)}
        {}

        ~Binary_Search_Tree()
        {}

        T Min()
        {
            return Min(root);
        }

        T Max()
        {
            return Max(root);
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

        bool Search(const T& data)
        {
            Node* node = Search(root, data);

            return (node == nullptr) ? false : true;
        }

        void Insert(const T& data)
        {
            root = Insert(root, data);
        }

        void Remove(const T& data)
        {
            root = Remove(root, data);
        }

        T Successor(const T& data)
        {
            Node* node = Search(root, data);
            return node == nullptr ? 0 : Successor(node);
        }

        T Predecessor(const T& data)
        {
            Node* node = Search(root, data);
            return node == nullptr ? 0 : Predecessor(node);
        }

    private:
        T Min(Node* node)
        {
            if(node == nullptr)
            {
                return {};
            }
            else if(node->left == nullptr)
            {
                return node->data;
            }
            else
            {
                return Min(node->left);
            }

            return {};
        }

        T Max(Node* node)
        {
            if(node == nullptr)
            {
                return {};
            }
            else if(node->right == nullptr)
            {
                return node->data;
            }
            else
            {
                return Max(node->right);
            }

            return {};
        }

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

        Node* Search(Node* node, const T& data)
        {
            if(node == nullptr)
            {
                return nullptr;
            }
            else if(node->data == data)
            {
                return node;
            }
            else if(node->data < data)
            {
                return Search(node->right, data);
            }
            else if(node->data > data)
            {
                return Search(node->left, data);
            }
            else
            {
                return nullptr;
            }
        }

        Node* Insert(Node* node, const T& data)
        {
            if(node == nullptr)
            {
                node = new Node(data);
            }
            else if(node->data < data)
            {
                node->right = Insert(node->right, data);
                node->right->parent = node;
            }
            else if(node->data > data)
            {
                node->left = Insert(node->left, data);
                node->left->parent = node;
            }

            return node;
        }

        Node* Remove(Node* node, const T& data)
        {
            if(node == nullptr)
            {
                return nullptr;
            }

            if(node->data == data)
            {
                if(node->left == nullptr && node->right == nullptr)
                {
                    node = nullptr;
                }
                else if(node->left == nullptr && node->right != nullptr)
                {
                    node->right->parent = node->parent;
                    node = node->right;
                }
                else if(node->left != nullptr && node->right == nullptr)
                {
                    node->left->parent = node->parent;
                    node = node->left;
                }
                else
                {
                    T successor = Successor(data);
                    node->data = successor;
                    node->right = Remove(node->right, successor);
                }
            }
            else if(node->right->data == data)
            {
                node->right = Remove(node->right, data);
            }
            else if(node->left->data == data)
            {
                node->left = Remove(node->left, data);
            }

            return node;
        }

        T Successor(Node* node)
        {
            if(node->right != nullptr)
            {
                return Min(node->right);
            }
            else
            {
                Node* parent_node = node->parent;
                Node* current_node = node;

                while((parent_node != nullptr) && (current_node == parent_node->right))
                {
                    current_node = parent_node;
                    parent_node = current_node->parent;
                }

                return parent_node == nullptr ? 0 : parent_node->data;
            }
        }

        T Predecessor(Node* node)
        {
            if(node->left != nullptr)
            {
                return Max(node->left);
            }
            else
            {
                Node* parent_node = node->parent;
                Node* current_node = node;

                while((parent_node != nullptr) && (current_node == parent_node->left))
                {
                    current_node = parent_node;
                    parent_node = current_node->parent;
                }

                return parent_node == nullptr ? 0 : parent_node->data;
            }
        }
    };
}