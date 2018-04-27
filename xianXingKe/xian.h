#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;
typedef struct
{
    int x,y;
}section;//用来存储用户输入的先行课

//用邻接数组的方法表示图
class ke{
private:
    int **ss;
    int *indegree;
    int n;   //图的顶点个数
public:
    ke(int n);
    void methed(section s[],int sn);//s是用户输入的课程顺序,sn是s的长度
};

ke::ke(int n)

{
    this->n = n;
       ss = new int*[this->n+1];
    indegree = new int[this->n+1];
    //初始化
    for(int i=0; i<=this->n; i++)
    {
        ss[i] = new int[this->n+1];
        for(int j=0; j<=this->n; j++)
            ss[i][j] = 0;
        indegree[i]=0;// 初始化
    }
}

void ke::methed(section s[],int sn)
{
    int i,j;
    stack<int> store;//栈，存储每个学期的课程，
    int Count =0, sTop;//学期数

    for(i=1; i<=n; i++)///
        for(j=1; j<=n; j++)
            for(int k=0; k<=sn; k++)
            if(s[k].x==i&&ss[i][j]==0)
            {
                ss[i][j]=s[k].y;
                indegree[s[k].y]++;//计算入度，s[k]的每个元素只访问一次，
                s[k].x=0;//防止多次计算
            }
    cout<<"建立的邻接数组为："<<endl;
    for(i=1; i<=n; i++)///
    {
        for(j=1; j<=n; j++)
            cout<<ss[i][j];
        cout<<endl;
    }
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
            if(indegree[i]==0)//把所有入度为0的点加入栈
            {
                store.push(i);
                Count++;
            }
        //当没有点可以加进去的时候，栈就是空的，而程序没有正常退出的话，就是里面有环
        if(store.empty())
        {
            cout<<"无法继续找出学期数，请检查输入的先行课序列是否有误！";
            exit(1);
        }

        cout<<"第"<<j<<"个学期的课程：";
        while(!store.empty())
        {
            sTop=store.top();
            store.pop();
            cout<<sTop<<"，";
            //然后从图里删除这些点，并将它们出度的点的入度减一
            for(int k=1; k<=n; k++)
            {
                if(ss[sTop][k]!=0)
                    indegree[ss[sTop][k]]--;
                indegree[sTop]++;//入度为0的点也要处理；不然会再次加入到栈里
            }
        }
        cout<<endl;
        if(Count==n)//如果点处理完了
            exit(0);
    }
}

/*
void methed(int n, section s[], int sn)//n是课程数量，
{
    int ss[n][n];
    int i,j;
    int indegree[n];//存储每个点的入度
    stack<int> store;//栈，存储每个学期的课程，
    int Count =0, sTop;//学期数

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
            ss[i][j] = 0;
        indegree[i]=0;// 初始化
    }
    for(i=1; i<=n; i++)///
        for(j=1; j<=n; j++)
            for(int k=0; k<=sn; k++)
            if(s[k].x==i&&ss[i][j]==0)
            {
                ss[i][j]=s[k].y;
                indegree[s[k].y]++;//计算入度，s[k]的每个元素只访问一次，
                s[k].x=0;//防止多次计算
            }
    cout<<"建立的邻接数组为："<<endl;
    for(i=1; i<=n; i++)///
    {
        for(j=1; j<=n; j++)
            cout<<ss[i][j];
        cout<<endl;
    }
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
            if(indegree[i]==0)//把所有入度为0的点加入栈
            {
                store.push(i);
                Count++;
            }

        cout<<"第"<<j<<"个学期的课程：";
        while(!store.empty())
        {
            sTop=store.top();
            store.pop();
            cout<<sTop<<"，";
            //然后从图里删除这些点，并将它们出度的点的入度减一
            for(int k=1; k<=n; k++)
            {
                if(ss[sTop][k]!=0)
                    indegree[ss[sTop][k]]--; //不用处理ss[sTop][k]=0的情况，因为indegree是从indegree[1]开始
                indegree[sTop]++;//入度为0的点也要处理；不然会再次加入到栈里
            }
        }
        cout<<endl;
        if(Count==n)//如果点处理完了
            break;
    }
}
*/
