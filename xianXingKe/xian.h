#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;
typedef struct
{
    int x,y;
}section;//�����洢�û���������п�

//���ڽ�����ķ�����ʾͼ
class ke{
private:
    int **ss;
    int *indegree;
    int n;   //ͼ�Ķ������
public:
    ke(int n);
    void methed(section s[],int sn);//s���û�����Ŀγ�˳��,sn��s�ĳ���
};

ke::ke(int n)

{
    this->n = n;
       ss = new int*[this->n+1];
    indegree = new int[this->n+1];
    //��ʼ��
    for(int i=0; i<=this->n; i++)
    {
        ss[i] = new int[this->n+1];
        for(int j=0; j<=this->n; j++)
            ss[i][j] = 0;
        indegree[i]=0;// ��ʼ��
    }
}

void ke::methed(section s[],int sn)
{
    int i,j;
    stack<int> store;//ջ���洢ÿ��ѧ�ڵĿγ̣�
    int Count =0, sTop;//ѧ����

    for(i=1; i<=n; i++)///
        for(j=1; j<=n; j++)
            for(int k=0; k<=sn; k++)
            if(s[k].x==i&&ss[i][j]==0)
            {
                ss[i][j]=s[k].y;
                indegree[s[k].y]++;//������ȣ�s[k]��ÿ��Ԫ��ֻ����һ�Σ�
                s[k].x=0;//��ֹ��μ���
            }
    cout<<"�������ڽ�����Ϊ��"<<endl;
    for(i=1; i<=n; i++)///
    {
        for(j=1; j<=n; j++)
            cout<<ss[i][j];
        cout<<endl;
    }
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
            if(indegree[i]==0)//���������Ϊ0�ĵ����ջ
            {
                store.push(i);
                Count++;
            }
        //��û�е���Լӽ�ȥ��ʱ��ջ���ǿյģ�������û�������˳��Ļ������������л�
        if(store.empty())
        {
            cout<<"�޷������ҳ�ѧ������������������п������Ƿ�����";
            exit(1);
        }

        cout<<"��"<<j<<"��ѧ�ڵĿγ̣�";
        while(!store.empty())
        {
            sTop=store.top();
            store.pop();
            cout<<sTop<<"��";
            //Ȼ���ͼ��ɾ����Щ�㣬�������ǳ��ȵĵ����ȼ�һ
            for(int k=1; k<=n; k++)
            {
                if(ss[sTop][k]!=0)
                    indegree[ss[sTop][k]]--;
                indegree[sTop]++;//���Ϊ0�ĵ�ҲҪ������Ȼ���ٴμ��뵽ջ��
            }
        }
        cout<<endl;
        if(Count==n)//����㴦������
            exit(0);
    }
}

/*
void methed(int n, section s[], int sn)//n�ǿγ�������
{
    int ss[n][n];
    int i,j;
    int indegree[n];//�洢ÿ��������
    stack<int> store;//ջ���洢ÿ��ѧ�ڵĿγ̣�
    int Count =0, sTop;//ѧ����

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
            ss[i][j] = 0;
        indegree[i]=0;// ��ʼ��
    }
    for(i=1; i<=n; i++)///
        for(j=1; j<=n; j++)
            for(int k=0; k<=sn; k++)
            if(s[k].x==i&&ss[i][j]==0)
            {
                ss[i][j]=s[k].y;
                indegree[s[k].y]++;//������ȣ�s[k]��ÿ��Ԫ��ֻ����һ�Σ�
                s[k].x=0;//��ֹ��μ���
            }
    cout<<"�������ڽ�����Ϊ��"<<endl;
    for(i=1; i<=n; i++)///
    {
        for(j=1; j<=n; j++)
            cout<<ss[i][j];
        cout<<endl;
    }
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
            if(indegree[i]==0)//���������Ϊ0�ĵ����ջ
            {
                store.push(i);
                Count++;
            }

        cout<<"��"<<j<<"��ѧ�ڵĿγ̣�";
        while(!store.empty())
        {
            sTop=store.top();
            store.pop();
            cout<<sTop<<"��";
            //Ȼ���ͼ��ɾ����Щ�㣬�������ǳ��ȵĵ����ȼ�һ
            for(int k=1; k<=n; k++)
            {
                if(ss[sTop][k]!=0)
                    indegree[ss[sTop][k]]--; //���ô���ss[sTop][k]=0���������Ϊindegree�Ǵ�indegree[1]��ʼ
                indegree[sTop]++;//���Ϊ0�ĵ�ҲҪ������Ȼ���ٴμ��뵽ջ��
            }
        }
        cout<<endl;
        if(Count==n)//����㴦������
            break;
    }
}
*/
