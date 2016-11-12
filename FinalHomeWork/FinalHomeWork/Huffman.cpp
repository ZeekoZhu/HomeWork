#include <string>

using namespace std;

class HNode
{
public:
    int Weight = 0;
    int Left;
    int Right;
    int Parent = -1;
    char Value;
};

class Huffman
{
public:
    string Content;
    HNode* Tree;
    Huffman(string str)
    {
        Content = str;
        int len = str.length();
        Tree = new HNode[len * 2 - 1];

        int index = -1;

        for (char c : str)
        {
            for (int i = 0; i < index; i++)
            {
                // add the char to nodes to get the weight
                if (Tree[i].Value == c)
                {
                    Tree[i].Weight++;
                    break;
                }
                else
                {
                    index++;
                    Tree[index].Value = c;
                    Tree[index].Weight = 1;
                }
            }
        }
    }

    void GetSubTree(int& left, int& right, int len)
    {
        left = right = -1;
        for (int i = 0; i < len; i++)
        {
            if (left < 0 || Tree[i].Weight < Tree[left].Weight)
            {
                left = i;
            }
        }
        for (int i = 0; i < len; i++)
        {
            if (left != right&&right<0
                || Tree[i].Weight>Tree[left].Weight
                && Tree[i].Weight < Tree[right].Weight)
            {
                right = i;
            }
        }
    }
};