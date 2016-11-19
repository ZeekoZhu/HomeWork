#include <iostream>
#include "BinaryTree.h"
#include <string>

using namespace std;

int main()
{
    char datas[] = { '1','2',' ',' ','3','4','5',' ',' ',' ','1' };
    char datas1[] = { '1',' ','2',' ','3','4',' ','5',' ',' ',' ' };
    BinaryTree tree2(datas, 11);
    BinaryTree tree(datas1, 11);
    tree.PreVisit([](BinaryNode& c)->void {cout << c.data << " "; });
    string res;
    if (tree2.IsSimilarTo(tree))
    {
        res = "相似";
    }
    else
    {
        res = "不相似";
    }
    cout << endl << res << endl;

    // 孩子-兄弟表示法的树其实是一棵二叉树，这棵二叉树中的节点的左孩子指向孩子，右孩子指向兄弟，其叶子结点就是没有左孩子的节点
    // 辣么，统计叶子节点的个数可以这么求
    int count = 0;
    tree.PreVisit([&count](BinaryNode& n)->void {
        if (n.lchild == nullptr)
        {
            count++;
        }
    });
    cout << "叶子结点的个数为：" << count;
}