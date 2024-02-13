#include <iostream>
#include <algorithm>
#include <memory>

#define endl '\n'

using namespace std;

template<typename T>
class BinaryTree
{
private:
    struct Node
    {
        T key;
        unique_ptr<Node> left;
        unique_ptr<Node> right;

        Node(T key) : key(key), left(nullptr), right(nullptr) {}
    };

    unique_ptr<Node> root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(const T& key)
    {
        insert_(root, key);
    }

    bool contains(const T& key) const
    {
        return contains_(root, key);
    }

    void preorder_traversal() const
    {
        preorder_traversal_(root);
    }

    void postorder_traversal() const
    {
        postorder_traversal_(root);
    }

private:
    void insert_(unique_ptr<Node>& node, const T& key)
    {
        if (!node)
        {
            node = make_unique<Node>(key);
            return;
        }

        if (key < node -> key) 
        {
            insert_(node->left, key);
        }
        else
        {
            insert_(node->right, key);
        }
    }

    bool contains_(const unique_ptr<Node>& node, const T& key) const
    {
        if (!node) return false;

        if (node->key == key) return true;
        else if (key < node->key) return contains_(node->left, key);
        else return contains_(node->right, key);
    }

    void preorder_traversal_(const unique_ptr<Node>& node) const
    {
        if (!node) return;

        cout << node->key << " ";
        preorder_traversal_(node->left);
        preorder_traversal_(node->right);
    }

    void postorder_traversal_(const unique_ptr<Node>& node) const
    {
        if (!node) return;

        postorder_traversal_(node->left);
        postorder_traversal_(node->right);

        cout << node->key << " ";
    }
};

int main()
{
    BinaryTree<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(24);
    tree.insert(5);
    tree.insert(28);
    tree.insert(45);
    tree.insert(98);
    tree.insert(52);
    tree.insert(60);

    cout << "Contains(28)?: " << tree.contains(28) << endl;
    cout << "Contains(10)?: " << tree.contains(10) << endl;

    cout << "Pre-order traversal: ";
    tree.preorder_traversal();
    
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postorder_traversal();

    return 0;
}