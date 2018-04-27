//˼·�������������ջ���洢
//��ÿ�����Լ���Χ�ĵ���ɵ����鶨��Ϊ�ڵ㣬�����������̿���һ��ͼ�����뿪ʼ��֮�����ΰ�ʣ��89��������Ϊ�յ㣬����Ѱ��·������ջ�ڵ�Ԫ�ظ���Ϊ90�����������еĵ�֮��������

#include <iostream>
#include <stdlib.h>
#include <stack>
#include <list>
using namespace std;

typedef struct
{
    int x, y;
}direction; //����
typedef struct Vexnode
{
    int index;//����Ƿ��Ѿ����ʹ�
    direction dire;
    list<Vexnode> llist;

    Vexnode(){};
    void reset1(int ind )
        {  index=ind;  }
    void reset2 (int ind, direction element, list<Vexnode> lt)
        {  index=ind; dire=element;llist=lt;   }
};

direction dir[8] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}}; //��İ˸�����

//��ʼ�����̣�
void ini_chess(int chess[][13])
{
    for(int i=0; i<14; i++)
        for(int j=0; j<13; j++)
            chess[i][j]=0;
    for(int i=0; i<14; i++)
        chess[i][0] = chess[i][1] = chess[i][12] = chess[i][11] = 1;//��ߺ��ұ�
    for(int i=0; i<13; i++)
        chess[0][i] = chess[1][i] = chess[12][i] = chess[13][i] = 1;//���������
}
/*
void flist(int chess[][13], Vexnode vv[])
{
    list<Vexnode> fl;
    int a=0,b;
    for(int i=2; i<=11; i++)
    {
        for(int j=2; j<=10; j++)
        {
             a=(i-2)*9+j-1;
             vv[a].reset1(a);//�ڵ��ʼ��
             for(int k=0; k<8; k++)
                if(chess[i+dir[k].x][j+dir[k].y]==0)
                {
                    b=(i+dir[k].x-2)*9+(j+dir[k].y-1);
                    cout<<vv[b].index<<" ";
                    fl.push_back(vv[b]);
                }
             vv[a].reset2(a,{i-1,j-1},fl);
            /// cout<<vv[a].index<<"  "<<vv[a].dire.x<<"  "<<vv[a].dire.y<<"  "<<vv[a].llist.front().index<<endl;
             fl.clear();
        }
    }
}
*/

//��ӡ
void Print(stack<direction> Stack)
{
    stack<direction> sstack = Stack;
    if(sstack->size()==90)//����90�Ĳ������
    {
       cout<<"The path is:"<<endl;
        direction pf = sstack->top();
        while(!sstack->empty())
        {
            cout<<"-<"<<pf.x<<","<<pf.y<<">-";
            sstack->pop();
        }
    }

}



void findPath(Vexnode curNode, Vexnode endNode, bool visited[], stack<direction> sstack)//��ǰ�㣬�����㣬������飬���ջ
{
   if(visited[curNode.index])   //���統ǰ���Ѿ����ʹ����ͷ���
        return;
    sstack->push(curNode.dire);//��ǰ����ջ
    visited[curNode.index]=true;//��ǰ���Ѿ�����
    if(curNode.dire.x == endNode.dire.x && curNode.dire.y == endNode.dire.y)//�����ǰ����Ŀ��㣬���
    {
        Print(sstack);
        visited[curNode.index] = false;
        sstack->pop();
        return;
    }
    list<Vexnode> llist = curNode.llist;//��ǰ������
    list<Vexnode>::iterator itor;  //���������
    itor = llist.begin();
    while(itor!=llist.end())//��������ÿ�������������
        findPath(*itor++, endNode, visited, sstack);
    visited[curNode.index]=false;//������Ϻ󵯳�����־���
    sstack->pop();
}




