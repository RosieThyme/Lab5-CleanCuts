/* 
* Date: 09/10/2026
* TODO:
* Log:
*	   10/10/2026 - added insert Node Function
*	   00/00/00 -
*/

#include "binarySearchTree.h"
//Binary Search Tree Node Implementation/Definition
BSTNode::BSTNode(int keyinfo, BSTNode *left, BSTNode *right)
{
    this->key = keyinfo;
    this->leftNode = left;
    this->rightNode = right;
    this->parent = nullptr;
}
//Binary Search Tree Implementation/Definition
void binarySearchTree::deleteTree(BSTNode *subTreeRoot)
{
    if (subTreeRoot)
    {
        deleteTree(subTreeRoot->leftNode);
        deleteTree(subTreeRoot->rightNode);
        delete subTreeRoot;
    }
}
binarySearchTree::binarySearchTree()
{
    root = nullptr;
}
void binarySearchTree::insertNode(BSTNode *newNode, int key)
{
    if (root == nullptr)
    {
        root =newNode;
    }
    else
    {
        BSTNode *currentNode = root;
        while (currentNode != nullptr)
        {
            if (newNode->key < currentNode->key)
            {
                if (newNode->leftNode == nullptr)
                {
                    newNode->leftNode = newNode;
                }
                else
                {
                    currentNode = currentNode->leftNode;
                }
            }
            else
            {
                if (newNode->key < currentNode->key)
                {
                    if (newNode->rightNode == nullptr)
                    {
                        newNode->rightNode = newNode;
                    }
                    else
                    {
                        currentNode = currentNode->rightNode;
                    }
                }


            }

        }
    }
}
BSTNode* binarySearchTree::searchNode(int key)
{
    BSTNode *currentNode = root;
    while (currentNode)
    {
        if (key == currentNode->key)
        {
            return currentNode;
        }
        else if (key < currentNode->key)
        {
            currentNode = currentNode->leftNode;
        }
        else
        {
            currentNode = currentNode->rightNode;
        }
    }
    return nullptr;
}
bool binarySearchTree::containsNode(int key)
{
    return searchNode(key)!= nullptr;
}
bool binarySearchTree::insertKey(int key)
{
    if (containsNode(key))
    {
        return false;
    }
    insertNode(new BSTNode(key),key);
    return true;
}
bool binarySearchTree::deleteKey(int key)
{
    BSTNode* parentNode = nullptr;
    BSTNode *currentNode = root;
    while (currentNode)
    {
        //does the currentNode contain the matching key?
        if (currentNode->key == key)
        {
            if (currentNode->leftNode == nullptr && currentNode->rightNode == nullptr)
            {
                if (parentNode == nullptr)
                {
                    root = nullptr;
                }
                else if (parentNode->leftNode == currentNode)
                {
                    parentNode->leftNode = nullptr;
                }
                else
                {
                    parentNode->rightNode = nullptr;
                }
                delete currentNode;
                return true;
            }
            else if (currentNode->leftNode && currentNode->rightNode == nullptr)
            {
                if (parentNode == nullptr)
                {
                    root = currentNode->leftNode;
                }
                else if (parentNode->leftNode == currentNode)
                {
                    parentNode->leftNode = currentNode->leftNode;
                }
                else
                {
                    parentNode->rightNode = currentNode->leftNode;
                }
            }
            else if (currentNode->leftNode == nullptr && currentNode->rightNode)
            {
                if (parentNode == nullptr)
                {
                    root = currentNode->rightNode;

                }
                else if (parentNode->rightNode == currentNode)
            }
        }


    }
    return false;
}
binarySearchTree::~binarySearchTree()
{
    deleteTree(root);
}
