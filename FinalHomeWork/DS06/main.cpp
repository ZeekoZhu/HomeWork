#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
    char datas[] = { '1','2',' ',' ','3','4',' ','5',' ',' ',' ' };
    BinaryTree tree2(datas, 12);
    BinaryTree tree(datas, 11);
    cout << tree2.IsSimilarTo(tree);
}