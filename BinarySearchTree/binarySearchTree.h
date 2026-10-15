

#ifndef BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
//Binary Search Tree Node Interface/Declaration
class BSTNode
{
    private:
    int key;
    BSTNode *leftNode;
    BSTNode *rightNode;
    BSTNode *parent;
    friend class binarySearchTree;
    public:
    BSTNode(int keyinfo, BSTNode *left = nullptr, BSTNode *right=nullptr);

};
//Binary Search Tree Interface/Declaration
class binarySearchTree
{
    private:
    BSTNode *root;
    void deleteTree(BSTNode *subTreeRoot);
    public:
    binarySearchTree();
    void insertNode(BSTNode *newNode, int key);
    BSTNode* searchNode(int key);
    bool containsNode( int key);
    bool insertKey(int key);
    bool deleteKey(int key);

    ~binarySearchTree();
};


#endif //BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
