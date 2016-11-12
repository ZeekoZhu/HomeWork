#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class HNode
{
public:
    int Weight = 0;
    int Left;
    int Right;
    int Parent = -1;
    char Value = 0;
};

class HTable
{
public:
    char Value;
    string Code = "";
};

class Huffman
{
public:
    string Content;
    HNode* Tree;
    HTable* CodeTable;
    Huffman(string str)
    {
        Content = str;
        int len = str.length();
        Tree = new HNode[len * 2 - 1];
        int index = -1;

        for (char c : str)
        {
            bool added = false;
            for (int i = 0; i <= index; i++)
            {
                if (Tree[i].Value == c)
                    // add the char to nodes to get the weight
                {
                    Tree[i].Weight++;
                    added = true;
                    break;
                }
            }
            if (!added)
            {
                index++;
                Tree[index].Value = c;
                Tree[index].Weight = 1;
            }
        }

        // 所有字符个数
        len = index + 1;    
        
        // construct new sub tree
        // select 2 min node;
        bool flag = true;
        while (flag)
        {
            flag = false;
            int left = -1;
            int right = -1;
            GetSubTree(left, right, index + 1);
            if (left >= 0 && right >= 0)
            {
                // 最终得到树根的位置
                index++;
                Tree[index].Left = left;
                Tree[index].Right = right;
                Tree[index].Weight = Tree[left].Weight + Tree[right].Weight;
                Tree[left].Parent = index;
                Tree[right].Parent = index;
                flag = true;
                //len++;
            }
        }

        GetCodeTable(index + 1);
        for (int i = 0; i < len; i++)
        {
            cout << CodeTable[i].Value << "  " << CodeTable[i].Code << endl;
        }
    }


    /// <summary>
    /// Gets the code table.
    /// </summary>
    /// <param name="len">The count of chars.</param>
    void GetCodeTable(int len)
    {
        CodeTable = new HTable[len];
        int i = 0;
        stack<int> trace;

        trace.push(len - 1);
        string prefix = "";
        while (!trace.empty())
        {
            int tmp = trace.top();
            // 生成编码
            if (Tree[tmp].Parent >= 0)
            {
                int pl = Tree[Tree[tmp].Parent].Left;
                prefix += pl == tmp ? "0" : "1";
            }
            // 叶子结点
            if (Tree[tmp].Value > 0)
            {
                CodeTable[i].Value = Tree[tmp].Value;
                CodeTable[i].Code = prefix;
                i++;
                trace.pop();
                // 左孩子
                if (prefix.back() == '0')
                {
                    prefix = prefix.substr(0, prefix.length() - 1);
                }
                prefix = prefix.substr(0, prefix.length() - 1);
            }
            // 普通节点
            else
            {
                trace.pop();
                trace.push(Tree[tmp].Left);
                trace.push(Tree[tmp].Right);
            }
        }
    }
    
    /// <summary>
    /// Gets the sub tree.
    /// </summary>
    /// <param name="left">The left.</param>
    /// <param name="right">The right.</param>
    /// <param name="len">The length.</param>
    void GetSubTree(int& left, int& right, int len)
    {
        left = right = -1;
        for (int i = 0; i < len; i++)
        {
            if (Tree[i].Parent == -1 && (left < 0 || (Tree[i].Weight < Tree[left].Weight)))
            {
                left = i;
            }
        }
        for (int i = 0; i < len; i++)
        {
            if ((Tree[i].Parent == -1 && left != i)
                && (right < 0 || (Tree[i].Weight >= Tree[left].Weight
                    && Tree[i].Weight < Tree[right].Weight)))
            {
                right = i;
            }
        }
    }
};