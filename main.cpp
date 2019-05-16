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
    cout << "��������(0�˳�):";
    cin >> i;
    while(i != 0)
    {
        SwitchNum(i);
        cout << "��������(0�˳�):";
        cin >> i;
    }
    return 0;
}

void Show()
{
    cout << "1.����������ʼ��" << endl;
    cout << "2.�������������" << endl;
    cout << "3.�������������" << endl;
    cout << "4.�������������" << endl;
    cout << "5.�������������" << endl;
    cout << "6.��������������" <<endl;
    cout << "7.�����������Ҷ�ӽڵ���" << endl;
    cout << "8.����������" << endl;
}

void SwitchNum(int i)
{
    switch(i)
    {
    case 1:
        cout << "����#�ַ�����ýڵ�Ϊ��:";
        CreateBiTree(T);
        cout << "��ʼ�����" << endl;
        break;
    case 2:
        cout << "������������:";
        PreOrderTraverse(T);
        cout << endl;
        break;
    case 3:
        cout << "������������:";
        InOrderTraverse(T);
        cout << endl;
        break;
    case 4:
        cout << "������������:";
        PostOrderTraverse(T);
        cout << endl;
        break;
    case 5:
        levelTraverse(T);
        break;
    case 6:
        depth = Depth(T);
        cout << "�������������:" << depth << endl;
        break;
    case 7:
        num = CountLeaves(T);
        cout << "��������Ҷ�ӽڵ�����:" << num << endl;
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
            q.push(T); //���ڵ������
        }
        while (q.empty() == false) //���в�Ϊ���ж�
        {
            cout << q.front()->data << " �� ";
            if (q.front()->lchild != NULL) //��������ӣ�leftChild�����
            {
                q.push(q.front()->lchild);
            }
            if (q.front()->rchild != NULL) //������Һ��ӣ�rightChild�����
            {
                q.push(q.front()->rchild);
            }
            q.pop(); //�Ѿ��������Ľڵ������
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



