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

            Node(const T& data) : data{data}
            {}
        };

        Node* root = nullptr;

    public:
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

        void Print()
        {
            Print(root);
            std::cout << '\n';
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