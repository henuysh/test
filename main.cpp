#include <iostream>
#include <queue>

using namespace std;

int m = 0;
int n = 0;
int sum = 0;
int depth;
int num;
typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode,*BiTree;
BiTree T;
typedef struct{
    int weight;
    int parent,lchild,rchild;
}HTNode, *HuffmanTree;

void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
void CreateBiTree(BiTree &T);
int Depth(BiTree T);
int CountLeaves(BiTree T);
void levelTraverse(BiTree T);
void CreateHuffmanTree(HuffmanTree &HT,int n);
void Show();
void SwitchNum(int i);
int main()
{
    Show();
    int i;
    cout << "请输入编号(0退出):";
    cin >> i;
    while(i != 0)
    {
        SwitchNum(i);
        cout << "请输入编号(0退出):";
        cin >> i;
    }
    return 0;
}

void Show()
{
    cout << "1.创建树并初始化" << endl;
    cout << "2.先序遍历二叉树" << endl;
    cout << "3.中序遍历二叉树" << endl;
    cout << "4.后序遍历二叉树" << endl;
    cout << "5.层序遍历二叉树" << endl;
    cout << "6.输出二叉树的深度" <<endl;
    cout << "7.输出二叉树的叶子节点数" << endl;
    cout << "8.哈夫曼编码" << endl;
}

void SwitchNum(int i)
{
    switch(i)
    {
    case 1:
        cout << "输入#字符代表该节点为空:";
        CreateBiTree(T);
        cout << "初始化完成" << endl;
        break;
    case 2:
        cout << "先序遍历结果是:";
        PreOrderTraverse(T);
        cout << endl;
        break;
    case 3:
        cout << "中序遍历结果是:";
        InOrderTraverse(T);
        cout << endl;
        break;
    case 4:
        cout << "后序遍历结果是:";
        PostOrderTraverse(T);
        cout << endl;
        break;
    case 5:
        levelTraverse(T);
        break;
    case 6:
        depth = Depth(T);
        cout << "二叉树的深度是:" << depth << endl;
        break;
    case 7:
        num = CountLeaves(T);
        cout << "二叉树的叶子节点数是:" << num << endl;
        break;
    case 8:
        break;
    }
}

void PreOrderTraverse(BiTree T)
{
    if(T)
    {
        cout << T ->data;
        PreOrderTraverse(T ->lchild);
        PreOrderTraverse(T ->rchild);
    }
}
void InOrderTraverse(BiTree T)
{
    if(T)
    {
        InOrderTraverse(T ->lchild);
        cout << T ->data;
        InOrderTraverse(T ->rchild);
    }
}
void PostOrderTraverse(BiTree T)
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T ->rchild);
        cout << T ->data;
    }
}
void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if(ch == '#')
        T = NULL;
    else
    {
        T = new BiTNode;
        T -> data = ch;
        CreateBiTree(T ->lchild);
        CreateBiTree(T ->rchild);
    }
}
int Depth(BiTree T)
{
    if(T == NULL)
        return 0;
    else
    {
        m = Depth(T ->lchild);
        n = Depth(T ->rchild);
        return m > n? (m+1) : (n+1);
    }
}
void levelTraverse(BiTree T)
{
    {
        queue <BiTree> q;

        if (T != NULL)
        {
            q.push(T); //根节点进队列
        }
        while (q.empty() == false) //队列不为空判断
        {
            cout << q.front()->data << " → ";
            if (q.front()->lchild != NULL) //如果有左孩子，leftChild入队列
            {
                q.push(q.front()->lchild);
            }
            if (q.front()->rchild != NULL) //如果有右孩子，rightChild入队列
            {
                q.push(q.front()->rchild);
            }
            q.pop(); //已经遍历过的节点出队列
        }
    }
}
int CountLeaves(BiTree T)
{
    if(T)
    {
        if(!T ->lchild && !T->rchild)
        {
            sum++;
        }
        CountLeaves(T->lchild);
        CountLeaves(T ->rchild);

    }
    return sum;
}



