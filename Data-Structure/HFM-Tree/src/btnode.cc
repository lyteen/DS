#include<iostream>

#define ElemType int
typedef struct node
{
    ElemType element;
    struct node *lChild;
    struct node *rChild;
}Node;

using namespace std;

// Init the btNode
void Init(Node *node)
{
    node->element = 0;
    node->lChild = NULL;
    node->rChild = NULL;
}

// insert node
Node *insertNode(Node *node, ElemType val)
{
    if(!node)
    {
        node = new Node;
        Init(node);
        node->element = val;
        return node; 
    } else if(node->element < val)
    {
        node->lChild = insertNode(node->lChild, val);
    } else if(node->element > val)
    {
        node->rChild = insertNode(node->rChild, val);
    }
    return node;
}
// Traversal
void Pre_Order(Node *node)
{
    if(!node)
    {
        return;
    }
    cout << node->element << " ";
    Pre_Order(node->lChild);
    Pre_Order(node->rChild);
}

void In_Order(Node *node)
{
    if(!node)
    {
        return;
    }
    In_Order(node->lChild);
    cout << node->element << " ";
    In_Order(node->rChild);
}

void Post_Order(Node *node)
{
    if(!node)
    {
        return;
    }
    Post_Order(node->lChild);
    Post_Order(node->rChild);
    cout << node->element << " ";
}

// Search for a node
bool searchNode(Node *node, ElemType val)
{
    if(!node) return false;
    if(node->element == val) return true;
    if(node->element > val) return searchNode(node->lChild, val);
    if(node->element < val) return searchNode(node->rChild, val);
    return false;
}

Node* findMin(Node* node) {
        while (node->lChild) node = node->lChild;
        return node;
}

Node* Delect(Node *node, ElemType val)
{
    if (!node) return nullptr;
        if (val < node->element) {
            node->lChild = Delect(node->lChild, val);
        } else if (val > node->element) {
            node->rChild = Delect(node->rChild, val);
        } else {
            // Case 1: No children
            if (!node->lChild && !node->rChild) {
                delete node;
                node = nullptr;
            }
            // Case 2: One child
            else if (!node->lChild) {
                Node* temp = node;
                node = node->rChild;
                delete temp;
            } else if (!node->rChild) {
                Node* temp = node;
                node = node->lChild;
                delete temp;
            }
            // Case 3: Two children
            else {
                Node* temp = findMin(node->rChild);
                node->element = temp->element;
                node->rChild = Delect(node->rChild, temp->element);
            }
        }
        return node;
}



int countNodes(Node* node) {
    if (!node) return 0;
    return 1 + countNodes(node->lChild) + countNodes(node->rChild);
}

int height(Node* node) {
    if (!node) return 0;
    return 1 + std::max(height(node->lChild), height(node->rChild));
}

int countLeafNodes(Node* node) {
    if (!node) return 0;
    if (!node->lChild && !node->rChild) return 1;
    return countLeafNodes(node->lChild) + countLeafNodes(node->rChild);
}

void swapChildren(Node* node) {
    if(!node)
    {
        return;
    }
    Node* temp = node->lChild;
    node->lChild = node->rChild;
    node->rChild = temp;
    swapChildren(node->lChild);
    swapChildren(node->rChild);
}

int main()
{
    Node* root = nullptr;
    root = insertNode(root, 10);
    root = insertNode(root, 15);
    root = insertNode(root, 20);
    root = insertNode(root, 25);
    root = insertNode(root, 30);
    root = insertNode(root, 35);
    root = insertNode(root, 40);
    root = insertNode(root, 45);
    cout << "Pre-Order:" << endl;
    Pre_Order(root);
    cout << '\n' << endl;
    cout << "In-Order:" << endl;
    In_Order(root);
    cout << '\n' << endl;
    cout << "Post-Order:" << endl;
    Post_Order(root);
    cout << '\n' << endl;
    int num = 25;
    if(searchNode(root, num)) {cout << "node:" << num << "in tree" <<endl;}
    Delect(root, num);
    cout << "Delect node:" << num << endl;
    In_Order(root);
    cout << '\n' << endl;
    cout << "Node number:" << countNodes(root) << endl;
    cout << "tree height:" << height(root) << endl;
    cout << "leaf node number:" << countLeafNodes(root) << endl;
    cout << "Swap Child node:" << endl;
    swapChildren(root);
    In_Order(root);
}