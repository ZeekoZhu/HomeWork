#include <stack>

using namespace std;

typedef char T;
class BinaryTree;
class BinaryNode
{
    friend class BinaryTree;
    T data;
    BinaryNode* lchild;
    BinaryNode* rchild;
    BinaryNode() :lchild(nullptr), rchild(nullptr)
    {
    }
    BinaryNode(T& data) : lchild(nullptr), rchild(nullptr)
    {
        this->data = data;
    }
};

class BinaryTree
{
    BinaryNode* root = nullptr;

public:
    BinaryTree(T* datas, int count)
    {
        this->root = new BinaryNode(datas[0]);
        BinaryNode* that = this->root->lchild;
        stack<BinaryNode*> trace;
        trace.push(this->root);
        bool isLeft = true;

        for (int i = 1; i < count; i++)
        {
            BinaryNode* parent = trace.top();
            if (datas[i] == ' ')
            {
                if (trace.empty())
                {
                    return;
                }

                if (isLeft)
                {
                    that = parent->rchild;
                    isLeft = false;
                }
                else
                {
                    do
                    {
                        trace.pop();
                        if (trace.empty())
                        {
                            return;
                        }
                        parent = trace.top();
                    } while (parent->rchild != nullptr);
                    that = parent->rchild;
                }
            }
            else
            {
                isLeft ? that = parent->lchild = new BinaryNode(datas[i])
                    : that = parent->rchild = new BinaryNode(datas[i]);
                trace.push(that);
                that = that->lchild;
                isLeft = true;
            }
        }
    }
};

