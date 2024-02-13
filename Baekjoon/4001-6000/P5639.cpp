// 이진 검색 트리
// https://www.acmicpc.net/problem/5639

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#define endl '\n'

using namespace std;

class BinaryTree
{
private:
    struct Node
    {
        int key;
        unique_ptr<Node> left;
        unique_ptr<Node> right;

        Node(int key) : key(key), left(nullptr), right(nullptr) {}
    };

    unique_ptr<Node> root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(const int& key)
    {
        insert_(root, key);
    }

    void postorder_traversal()
    {
        postorderTraversal_(root);
    }

private:
    void insert_(unique_ptr<Node>& node, const int& key)
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

    void postorderTraversal_(const unique_ptr<Node>& node) const
    {
        if (!node) return;

        postorderTraversal_(node->left);
        postorderTraversal_(node->right);

        cout << node->key << endl;
    }
};

int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    BinaryTree tree;

    int input;
    while (cin >> input)
    {
        int key = input;
        tree.insert(key);
    }

    tree.postorder_traversal();


    return 0;
}