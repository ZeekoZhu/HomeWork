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
                    isLeft = false;
                }
                else
                {
                    trace.pop();
                    parent = trace.top();
                }
                that = parent->rchild;

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

    bool IsSimilarTo(BinaryTree& other)
    {
        BinaryNode* _this = this->root;
        BinaryNode* that = other.root;
        stack<BinaryNode*> thisTrace;
        stack<BinaryNode*> thatTrace;
        thisTrace.push(_this);
        thatTrace.push(that);
        _this = _this->lchild;
        that = that->lchild;
        bool isLeft = true;
        while (!thisTrace.empty() && !thatTrace.empty())
        {
            if ((_this == nullptr && that != nullptr)
                || (_this != nullptr && that == nullptr))
            {
                return false;
            }
            if (_this == nullptr)
            {
                if (isLeft)
                {
                    isLeft = false;
                }
                else
                {
                    thisTrace.pop();
                    thatTrace.pop();
                }
                _this = thisTrace.top()->rchild;
                that = thatTrace.top()->rchild;
            }
            else
            {
                thisTrace.push(_this);
                thatTrace.push(that);
                _this = _this->lchild;
                that = that->lchild;
                isLeft = true;
            }
        }
        return true;
    }
};

