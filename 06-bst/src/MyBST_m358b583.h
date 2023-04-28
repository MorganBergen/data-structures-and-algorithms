#ifndef __MYBST_H__
#define __MYBST_H__

#include <iostream>
#include <fstream>
#include <cstdlib>

enum TreeTravOrderType {
    PreOrder,
    InOrder,
    PostOrder
};

enum NodePosType {
    Left,
    Right,
    Root
};

template <typename ComparableType>
class MyBST {
  private:
    struct BinaryNode {
        ComparableType element;
        size_t height;
        BinaryNode *left;
        BinaryNode *right;
        
        BinaryNode(const ComparableType & x, const size_t h, BinaryNode *l, BinaryNode *r) : 
            element{x}, 
            height{h},
            left{l}, 
            right{r} {  }

        BinaryNode(ComparableType && x, const size_t h, BinaryNode *l, BinaryNode *r) : 
            element{std::move(x)}, 
            height{h},
            left{l},
            right{r} {  }
    };

    BinaryNode *root;       
    size_t theSize;         

    // finds the minimum data element from the tree rooted at t
    BinaryNode* findMin(BinaryNode *t) const {
        if (t == nullptr) {
            return nullptr;
        } if (t -> left == nullptr) {
            return (t);
        } 
        return findMin(t -> left);
    }

    // finds the maximum data element from the tree rooted at t
    BinaryNode* findMax(BinaryNode *t) const {
        if (t == nullptr) {
            return nullptr;
        } while (t -> right != nullptr) {
            t = t -> right;
        }
        return (t);
    }

    // checks if x is contained in the tree rooted at t
    bool contains(const ComparableType& x, BinaryNode *t) const {
        if (t == nullptr)
            return false;
        else if (x < t->element)
            return contains(x, t->left);
        else if (t->element < x)
            return contains(x, t->right);
        else
            return true; // match
    }

    // deletes the tree rooted at t
    void clear(BinaryNode*& t) {
        if (t != nullptr) {
            clear(t->left);
            clear(t->right);
            delete t;
            t = nullptr;
            theSize--;
        }
    }

    // returns the height of the node
    // leave nodes have a height of 1
    size_t height(BinaryNode* t) const {
        return (t == nullptr ? 0 : t->height);
    }

    // balances tree node t
    void balance(BinaryNode*& t) {
        if (t == nullptr) return;

        // balance the right subtree
        if (height(t->right) - height(t->left) > 1)
        {
            // balance the right subtree of the right child
            if (height(t->right->right) >= height(t->right->left))
            {
                rotateLeft(t);
            }
            // balance the left subtree of the right child
            else
            {
                doubleRotateRight(t);
            }
        }
        // balance the left subtree
        else if (height(t->left) - height(t->right) > 1)
        {
            // balance the left subtree of the left child
            if (height(t->left->left) >= height(t->left->right))
            {
                rotateRight(t);
            }
            // balance the right subtree of the left child
            else
            {
                doubleRotateLeft(t);
            }
        }

        // update height
        t->height = std::max(height(t->left), height(t->right)) + 1;
    }
    
    // single rotation that reduces left branch depth
    void rotateLeft(BinaryNode*& t) {
        BinaryNode* pivot = t->right;
        t->right = pivot->left;
        pivot->left = t;
        t->height = std::max(height(t->left), height(t->right)) + 1;
        pivot->height = std::max(height(pivot->left), height(pivot->right)) + 1;
        t = pivot;
    }

    // single rotation that reduces right branch depth
    void rotateRight(BinaryNode*& t) {
        BinaryNode* pivot = t->left;
        t->left = pivot->right;
        pivot->right = t;
        t->height = std::max(height(t->left), height(t->right)) + 1;
        pivot->height = std::max(height(pivot->left), height(pivot->right)) + 1;
        t = pivot;
    }

    // double rotation that reduces left branch depth
    void doubleRotateLeft(BinaryNode*& t) {
        rotateRight(t -> left);
        rotateLeft(t);
    }

    // double rotation that reduces right branch depth
    void doubleRotateRight(BinaryNode*& t) {
        rotateLeft(t -> right);
        rotateRight(t);
    }

    // inserts x to the tree rooted at t (copy)
    // if x exists, the do nothing
    void insert(const ComparableType& x, BinaryNode*& t) {
        if (t == nullptr) {
            t = new BinaryNode{x, 1, nullptr, nullptr};
            return;
        } else if (x < t -> element) {
            insert(x, t->left);
            balance(t);
        }
        else if (t -> element < x) {
            insert(x, t->right);
            balance(t);
        }
        else {
            return;
        }
    }

    // inserts x to the tree rooted at t (move)
    void insert(ComparableType && x, BinaryNode*& t) {
        if (t == nullptr) {
            t = new BinaryNode{std::move(x), 1, nullptr, nullptr};
            return;
        }
        else if (x < t -> element) {
            insert(std::move(x), t -> left);
            balance(t);
        }
        else if (t->element < x) {
            insert(std::move(x), t->right);
            balance(t);
        }
        else {
            return;
        }
    }

    // removes x from the tree rooted at t
    // when deleting a node with two children, replace it with the smallest child of the right subtree
    void remove(const ComparableType& x, BinaryNode*& t) {
        if (t == nullptr) {
            return;
        }

        if (x < t->element) {
            remove(x, t->left);
        } else if (t->element < x) {
            remove(x, t->right);
        } else if (t->left != nullptr && t->right != nullptr) { // node has two children
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        } else { // node has zero or one child
            BinaryNode* oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
            theSize--;
        }
    }

    // clones the node t and returns the clone
    BinaryNode* clone(BinaryNode* t) const {
        if( t == nullptr ) return nullptr;
        else
            return new BinaryNode{t->element, clone(t->left), clone(t->right)};
    }

    // prints all data elements rooted at t pre-order
    void printPreOrder(BinaryNode* t, std::ostream& out) const {
        const char delim = ' ';
        if (t != nullptr) {
            out << t -> element << delim;
            printPreOrder(t -> left, out);
            printPreOrder(t -> right, out);
        }
        return;
    }

    // prints all data elements rooted at t in-order
    void printInOrder(BinaryNode* t, std::ostream& out) const {
        const char delim = ' ';
        if (t != nullptr) {
            printInOrder(t -> left, out);
            out << t -> element << delim;
            printInOrder(t -> right, out);
        }
        return;
    }

    // prints all data elements rooted at t post-order
    void printPostOrder(BinaryNode* t, std::ostream& out) const {
        const char delim = ' ';
        if(t != nullptr)
        {
            printPostOrder(t->left, out);
            printPostOrder(t->right, out);
            out << t->element << delim;
        }
        return;
    }

    // prints the subtree rooted at t
    // lv is the level of t (the root corresponds to level 0)
    // p is the relative topological position of t (left/right/root) 
    void printTree(BinaryNode* t, const int lv, const NodePosType p) {
        if(t == nullptr)
            return;

        char pos;
        switch(p) {
            case Left:
                pos = 'L';
                break;
            case Right:
                pos = 'R';
                break;
            case Root:
                pos = 'T';
                break;
            default:
                std::cout << "Error: MyBST::printTree: unrecognized position type." << std::endl;
        }        
        std::cout << t->element << "|" << lv << "|" << pos << std::endl;
        printTree(t->left, lv + 1, Left);
        printTree(t->right, lv + 1, Right);
        return;
    }

  public:

    // default constructor
    MyBST() : 
        root{nullptr},
        theSize{0} { }

    // copy constructor
    MyBST(const MyBST& rhs) : 
        root{nullptr},
        theSize{rhs.theSize} {
        root = clone(rhs.root);
    }

    // move constructor
    MyBST(MyBST && rhs) : 
        root{rhs.root},
        theSize{rhs.theSize} {
        rhs.root = nullptr;
    }
      
    // destructor
    ~MyBST() {
        clear();
    }

    // finds the minimum data element in the tree
    const ComparableType& findMin() const {
        if (root == nullptr) {
            std::cout << "Error: Tree is empty" << std::endl;
            exit(EXIT_FAILURE);
        }
        BinaryNode* curr = root;
        while (curr->left != nullptr) {
            curr = curr->left;
        }
        return curr->element;
    }

    // finds the maximum data element in the tree
    const ComparableType& findMax( ) const {
        BinaryNode* maxNode = findMax(root);
        if (maxNode == nullptr) {
            throw std::out_of_range("Error: MyBST::findMax: tree is empty.");
        }
        return maxNode->element;
    }

    // checks whether x is contained in the tree
    bool contains(const ComparableType& x) const {
        return contains(x, root);
    }
    
    // returns the number of data elements in the tree
    size_t size(void) const {
        return theSize;
    }

    // returns the depth of the tree
    // depth defined as the longest path length from the root to any leaf
    // e.g. an empty tree has a depth of 0, a tree with a single node has a depth of 1
    size_t depth(void) const {
        if (root == nullptr) {
            return 0;
        } else {
            size_t leftDepth = depthHelper(root->left);
            size_t rightDepth = depthHelper(root->right);
            return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
        }

    }

    // checks whether the tree is empty
    bool empty() const {
        return (theSize == 0);
    }

    // delete all data elements in the tree
    void clear() {
        clear(root);
    }

    // insert x into the tree (copy)
    void insert(const ComparableType& x) {
        insert(x, root);
    }

    // insert x into the tree (move)
    void insert(ComparableType && x) {
        insert(x, root);
    }

    // removes x from the tree
    void remove(const ComparableType& x) {
        remove(x, root); 
    }

    // copy assignment
    MyBST& operator=(const MyBST& rhs) {
        if (this == &rhs) {
            return *this;
        }
        clear();

        theSize = rhs.theSize;
        root = clone(rhs.root);
        return *this;
    }

    // move assignment
    MyBST& operator=(MyBST && rhs) {
        if (this != &rhs) {
            clear(); 
            root = rhs.root; 
            theSize = rhs.theSize;
            rhs.root = nullptr; 
            rhs.theSize = 0; 
        }
        return *this;
    }

    // finds the lowest common ancestor (LCA) of x and y
    // if x and y are both in the tree, return true and store their LCA in lca
    // otherwise, return false
    bool lowestCommonAncestor(const ComparableType& x, const ComparableType& y, ComparableType& lca) {
        BinaryNode* nodeX = find(x, root);
        BinaryNode* nodeY = find(y, root);

        // If either node is not in the tree, return false
        if (nodeX == nullptr || nodeY == nullptr) {
            return false;
        }

        // Find the lowest common ancestor of nodes x and y
        lca = lowestCommonAncestor(root, nodeX, nodeY)->element;

        // Return true to indicate success
        return true;
    }

    BinaryNode* find(const ComparableType& x, BinaryNode* t) const {
        if (t == nullptr) {
            return nullptr;
        } else if (x < t->element) {
            return find(x, t->left);
        } else if (t->element < x) {
            return find(x, t->right);
        } else {
            return t;
        }
    }

    // Recursive helper function to find the lowest common ancestor of two nodes
    BinaryNode* findLCARecursive(BinaryNode* t, const ComparableType& x, const ComparableType& y) {
        // If the current node is null or one of the nodes we're looking for, return it
        if (t == nullptr || t->element == x || t->element == y) {
            return t;
        }

        // Recursively search the left and right subtrees
        BinaryNode* left = findLCARecursive(t->left, x, y);
        BinaryNode* right = findLCARecursive(t->right, x, y);

        // If we found one node in each subtree, this node is the LCA
        if (left != nullptr && right != nullptr) {
            return t;
        }

        // Otherwise, return whichever node we found (if any)
        return (left != nullptr) ? left : right;
    }


    // print all data elements in the tree
    void print(TreeTravOrderType order, std::ostream& out = std::cout) const {
        switch (order) {
            case PreOrder:
                printPreOrder(root, out);
                out << std::endl;
                break;
            case InOrder:
                printInOrder(root, out);
                out << std::endl;
                break;
            case PostOrder:
                printPostOrder(root, out);
                out << std::endl;
                break;
            default:
                out << "Error: MyBST::print: Unsupported print order." << std::endl;
                break;
        }
        return;
    }

    // print all data elements in the tree
    // including partial topological information (layer and relative position among siblings)
    void printTree(void) {
        printTree(root, 0, Root);
        return;
    }
      
};

#endif // __MYBST_H__
