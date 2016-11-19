#pragma once
#include <stack>
#include <functional>
#include <vector>
using namespace std;

typedef char T;
class BinaryTree;
class BinaryNode
{
public:
    friend class BinaryTree;
    T data;
    BinaryNode* lchild;
    BinaryNode* rchild;
    BinaryNode() : data(0), lchild(nullptr), rchild(nullptr)
    {
    }

    explicit BinaryNode(T& data) : lchild(nullptr), rchild(nullptr)
    {
        this->data = data;
    }
};

class BinaryTree
{
    BinaryNode* root = nullptr;

public:
    /*
     * 6.36
     */
    BinaryTree(T* datas, int count)
    {
        this->root = new BinaryNode(datas[0]);
        BinaryNode* that = this->root->lchild;
        stack<BinaryNode*> trace;
        trace.push(this->root);
        bool isLeft = true;         // 指示当前节点是不是左孩子
        bool shouldLink = false;    // 指示是否应该链接后继
        BinaryNode* before = this->root;
        for (int i = 1; i < count; i++)
        {
            BinaryNode* parent = trace.top();
            if (datas[i] == ' ')
            {
                // 栈为空则建树完毕
                if (trace.empty())
                {
                    return;
                }

                // 如果当前节点是左节点，则 that 指向右边的兄弟节点
                if (isLeft)
                {
                    isLeft = false;
                }
                // 如果当前节点是右节点，则向上寻找一个空的右子树
                else
                {
                    // 能到这里的节点的双亲是叶子结点，所以，要把当前节点的母亲记录下来，遇到下一个节点，就把后继设置过去
                    before = parent;
                    shouldLink = true;
                    do
                    {
                        // 寻找空的右子树
                        trace.pop();
                        if (trace.empty())
                        {
                            return;
                        }
                        parent = trace.top();
                    } while (parent->rchild != nullptr);
                }
                that = parent->rchild;
            }
            else
            {
                // 判断当前节点的左右位置
                isLeft ? that = parent->lchild = new BinaryNode(datas[i])
                    : that = parent->rchild = new BinaryNode(datas[i]);
                // 链接后继节点
                if (!isLeft && shouldLink)
                {
                    shouldLink = false;
                    before->rchild = that;
                }
                trace.push(that);
                that = that->lchild;
                isLeft = true;
            }
        }
    }

    /// <summary>
    /// 6.37 先序遍历二叉树，判断是否相似
    /// </summary>
    bool IsSimilarTo(BinaryTree& other) const
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
                    BinaryNode* thisTmp;
                    BinaryNode* thatTmp;
                    do
                    {
                        thisTmp = thisTrace.top();
                        thatTmp = thatTrace.top();
                        thisTrace.pop();
                        thatTrace.pop();
                        if (thisTrace.empty())
                        {
                            return thatTrace.empty();
                        }
                    } while ((thisTrace.top()->rchild == nullptr && thatTrace.top()->rchild == nullptr)
                        || (thisTrace.top()->rchild == thisTmp && thatTrace.top()->rchild == thatTmp));
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

    /// <summary>
    /// 6.56 先序遍历二叉树
    /// </summary>
    void PreVisit(function<void(BinaryNode&)> action) const
    {
        BinaryNode* that = this->root;
        stack<BinaryNode*> thatTrace;
        action(*that);
        thatTrace.push(that);
        that = that->lchild;
        bool isLeft = true;
        while (!thatTrace.empty())
        {
            if (that == nullptr)
            {
                if (isLeft)
                {
                    isLeft = false;
                }
                else
                {
                    BinaryNode* thatTmp;
                    do
                    {
                        thatTmp = thatTrace.top();
                        thatTrace.pop();
                        if (thatTrace.empty())
                        {
                            return;
                        }
                    } while ((thatTrace.top()->rchild == nullptr) || (thatTrace.top()->rchild == thatTmp));
                }
                that = thatTrace.top()->rchild;
            }
            else
            {
                thatTrace.push(that);
                action(*that);
                that = that->lchild;
                isLeft = true;
            }
        }
    }

    /// <summary>
    /// 6.60 获取后继节点，对存储结构并没啥特别的要求
    /// </summary>
    static BinaryNode* GetNextNode(BinaryNode* p)
    {
        return p->lchild == nullptr ? p->rchild : p->lchild;
    }
};

