#pragma once

#include <stdio.h>
#include <string.h>

#define SIZE 256

namespace Data_Structures
{
	template<typename T>
	class Trie
	{
	private:
		struct Node
		{
			bool terminal = false;
			struct Node* chidren[SIZE];
		};

		Node* root = nullptr;

	public:
		Trie(){}
		~Trie(){}

		Node* Create_Node()
		{
			Node* node = new Node();

			for(int i = 0; i < SIZE; i++)
			{
				node->chidren[i] = nullptr;
			}

			node->terminal = false;
			return node;
		}

		bool Search(char* signed_text)
		{
			if(root == nullptr)
			{
				return false;
			}

			Node* root_pointer = root;
			int length = strlen(signed_text);
			unsigned char* text = (unsigned char*)signed_text;

			for(int i = 0; i < length; i++)
			{
				if(root_pointer->chidren[text[i]] == nullptr)
				{
					return false;
				}

				root_pointer = root_pointer->chidren[text[i]];
			}

			return root_pointer->terminal;
		}

		bool Insert(char* signedtext)
		{
			if(root == nullptr)
			{
				root = Create_Node();
			}

			Node* root_pointer = root;
			int length = strlen(signedtext);
			unsigned char* text = (unsigned char*)signedtext;

			for(int i = 0; i < length; i++)
			{
				if(root_pointer->chidren[text[i]] == nullptr)
				{
					root_pointer->chidren[text[i]] = Create_Node();
				}

				root_pointer = root_pointer->chidren[text[i]];
			}

			if(root_pointer->terminal == true)
			{
				return false;
			}
			else
			{
				root_pointer->terminal = true;
				return true;
			}
		}

		bool Node_Terminal(Node* node)
		{
			if(node == nullptr)
			{
				return false;
			}

			for(int i = 0; i < SIZE; i++)
			{
				if(node->chidren[i] != nullptr)
				{
					return true;
				}
			}

			return false;
		}

		Node* Delete_Recursive(Node* node, unsigned char* text, bool deleted)
		{
			if(node == nullptr)
			{
				return node;
			}

			if(*text == '\0')
			{
				if(node->terminal == true)
				{
					deleted = true;
					node->terminal = false;

					if(Node_Terminal(node) == false)
					{
						delete node;
						node = nullptr;
					}
				}

				return node;
			}

			node->chidren[text[0]] = Delete_Recursive(node->chidren[text[0]], text + 1, deleted);

			if(deleted == true && Node_Terminal(node) == false && node->terminal == false)
			{
				delete node;
				node = nullptr;
			}

			return node;
		}

		bool Delete(char* signedtext)
		{
			if(root == nullptr)
			{
				return false;
			}

			bool result = false;
			Node** node_pointer = &root;
			unsigned char* text = (unsigned char*)signedtext;
			*node_pointer = Delete_Recursive(*node_pointer, text, &result);
			return result;
		}

		void Print_Recursive(Node* node, unsigned char* prefix, int length)
		{
			unsigned char new_prefix[length + 2];
			memcpy(new_prefix, prefix, length);
			new_prefix[length + 1] = 0;

			if(node->terminal == true)
			{
				printf("%s\n", prefix);
			}

			for(int i = 0; i < SIZE; i++)
			{
				if(node->chidren[i] != nullptr)
				{
					new_prefix[length] = i;
					Print_Recursive(node->chidren[i], new_prefix, length + 1);
				}
			}
		}

		void Print()
		{
			if(root == nullptr)
			{
				printf("Empty\n");
				return;
			}

			Print_Recursive(root, nullptr, 0);
		}
	};
}