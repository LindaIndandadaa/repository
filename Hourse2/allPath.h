//思路：深度搜索，用栈来存储
//把每个点以及周围的点组成的数组定义为节点，即把整个棋盘看成一个图，输入开始点之后，依次把剩下89个点设置为终点，遍历寻找路径，当栈内的元素个数为90个即走完所有的点之后才能输出

#include <iostream>
#include <stdlib.h>
#include <stack>
#include <list>
using namespace std;

typedef struct
{
    int x, y;
}direction; //坐标
typedef struct Vexnode
{
    int index;//标记是否已经访问过
    direction dire;
    list<Vexnode> llist;

    Vexnode(){};
    void reset1(int ind )
        {  index=ind;  }
    void reset2 (int ind, direction element, list<Vexnode> lt)
        {  index=ind; dire=element;llist=lt;   }
};

direction dir[8] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}}; //马的八个方向

//初始化棋盘，
void ini_chess(int chess[][13])
{
    for(int i=0; i<14; i++)
        for(int j=0; j<13; j++)
            chess[i][j]=0;
    for(int i=0; i<14; i++)
        chess[i][0] = chess[i][1] = chess[i][12] = chess[i][11] = 1;//左边和右边
    for(int i=0; i<13; i++)
        chess[0][i] = chess[1][i] = chess[12][i] = chess[13][i] = 1;//上面和下面
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
             vv[a].reset1(a);//节点初始化
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

//打印
void Print(stack<direction> Stack)
{
    stack<direction> sstack = Stack;
    if(sstack->size()==90)//等于90的才能输出
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



void findPath(Vexnode curNode, Vexnode endNode, bool visited[], stack<direction> sstack)//当前点，结束点，标记数组，存放栈
{
   if(visited[curNode.index])   //假如当前点已经访问过，就返回
        return;
    sstack->push(curNode.dire);//当前点入栈
    visited[curNode.index]=true;//当前点已经访问
    if(curNode.dire.x == endNode.dire.x && curNode.dire.y == endNode.dire.y)//如果当前点是目标点，输出
    {
        Print(sstack);
        visited[curNode.index] = false;
        sstack->pop();
        return;
    }
    list<Vexnode> llist = curNode.llist;//当前点链表
    list<Vexnode>::iterator itor;  //定义迭代器
    itor = llist.begin();
    while(itor!=llist.end())//对相连的每个顶点进行搜索
        findPath(*itor++, endNode, visited, sstack);
    visited[curNode.index]=false;//搜索完毕后弹出，标志清除
    sstack->pop();
}




