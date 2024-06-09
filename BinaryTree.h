#pragma once

#include <iostream>
#include <cstdint>

template<typename T>
struct Node
{
    T Data;
    Node* Left;
    Node* Right;

    ~Node()
    {
        if (Left != nullptr)
            delete Left;
        if (Right != nullptr)
            delete Right;
        
        Left = nullptr;
        Right = nullptr;
    }
};

template<typename T>
class BinaryTree
{
public:
    BinaryTree()
    {
        m_Root = nullptr;
    }

    ~BinaryTree()
    {
        delete m_Root;
    }
public:
    void Insert(T data)
    {
        m_Size++;

        Node<T>* newNode = new Node<T>{};
        newNode->Data = data;
        newNode->Left = nullptr;
        newNode->Right = nullptr;

        if (m_Root == nullptr)
        {
            m_Root = newNode;
        }
        else
        {
            Node<T>* current = m_Root;
            while (true)
            {
                if (data < current->Data)
                {
                    if (current->Left == nullptr)
                    {
                        current->Left = newNode;
                        break;
                    }
                    else
                    {
                        current = current->Left;
                    }
                }
                else
                {
                    if (current->Right == nullptr)
                    {
                        current->Right = newNode;
                        break;
                    }
                    else
                    {
                        current = current->Right;
                    }
                }
            }
        }
    }
    bool Contains(T value)
    {
        Node<T>* currentNode = Root();

        for (uint32_t i = 0; i < Size(); i++)
        {
            if (value == currentNode->Data)
                return true;

            if (value < currentNode->Data)
            {
                if (currentNode->Left != nullptr)
                {
                    currentNode = currentNode->Left;
                }
                else
                    return false;
            }
            else if (value > currentNode->Data)
            {
                if (currentNode->Right != nullptr)
                {
                    currentNode = currentNode->Right;
                }
                else
                    return false;
            }
        }

        return false;
    }
    inline T Smallest() const 
    { 
        Node<T>* currentNode = m_Root;
        while (currentNode->Left != nullptr)
            currentNode = currentNode->Left;
        
        return currentNode->Data; 
    }
    inline T Largest() const
    {
        Node<T>* currentNode = m_Root;
        while (currentNode->Right != nullptr)
            currentNode = currentNode->Right;
        
        return currentNode->Data;
    }
public:
    inline Node<T>* Root() { return m_Root; }
    inline uint32_t Size() const { return m_Size;}
public:
    void Log()
    {
        Log(m_Root);
    }
private:
    void Log(Node<T> *node)
    {
        if (node == nullptr)
            return;

        Log(node->Left);
        std::cout << node->Data << " ";
        Log(node->Right);
    }
private:
    Node<T>* m_Root;
    uint32_t m_Size;
};