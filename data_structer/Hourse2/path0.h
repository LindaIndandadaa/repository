//���õݹ�

#include <iostream>
#include <stdlib.h>
#include "stack.h"

using namespace std;

int canPass[14][13][8];//��Щ�����ߵ�ͨ��

typedef struct
{
    int x, y;
}direction; //����

stack<direction> p;//ջ

direction dir[8] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}}; //��İ˸�����

 //�����ߵķ���
int Count(int x, int y, int chess[][13])
{
    int ct=0, i=0;
    for(i=0; i<8; i++)
        if(chess[x+1+dir[i].x][y+1+dir[i].y]==0)
            ct++;
    return ct;
}
//Ѱ����һ����������ҵ�����ֵ
int findPath(int x, int y, int chess[14][13])
{
    int dire, min=9, count, d=9;
    for(dire=0; dire<8; dire++)
    {
        if(chess[x+1+dir[dire].x][y+1+dir[dire].y]==0 && canPass[x+1][y+1][dire]==0)
        {
            count = Count(x+dir[dire].x, y+dir[dire].y, chess);
            if(min > count) //Ѱ�ҿ��ߵķ���������һ������
            {
                min = count;
                d = dire;
            }
        }
    }
    if(d < 9)
        return d;
    else
        return -1;
}

//��ʼ����ǣ�ȫ�����Ϊ0����ʾ�˸�����
void mark_direction()
{
    int i,j,k;
    for(i=0;i<14;i++)
        for(j=0;j<13;j++)
            for(k=0;k<8;k++)
                canPass[i][j][k]=0;
}

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

//��ӡ·��
void printPath(int chess[][13])
{
    cout<<"The path is:"<<endl;
      for(int i=0; i<90;i++)
          cout<<"-<"<<p.Find(i).element.x<<","<<p.Find(i).element.y<<">-";
        cout<<endl<<"Printed by the chess of the path:"<<endl;
        for( int i=2; i<12; i++)
        {
            for(int j=2; j<11; j++)
                cout<<chess[i][j]<<"--";
            cout<<endl;
        }

}

//��̬չʾ����
void Dprint(int chess[][13])
{
    cout<<"/*******************************/"<<endl;
    for( int i=2; i<12; i++)
    {
        for(int j=2; j<11; j++)
            cout<<chess[i][j]<<"--";
        cout<<endl;
    }
}

/*
//չʾ����·��
void display(int num)
{
    for(int i=1; i<=num;i++)
          cout<<"-<"<<p.Find(i).element.x<<","<<p.Find(i).element.y<<">-";
}
*/

//��ı���
bool hourse(int x, int y)
{
    int chess[14][13];//�������Թ����������գ������̵���Χ������ǽ��
    int D[14][13];//������̬���������
    int num=1, t;
    pathNode<direction> f;
    //��ʼ��
    mark_direction();
    ini_chess(chess);
    ini_chess(D);

    for(num=1; num<=90; num++)
    {

        t = findPath(x,y,chess);
        //cout<<t<<endl;
        if(t!=-1)//�ҵ���һ������
        {
            //cout<<num<<endl;
            chess[x+1][y+1] = num;//�����
            D[x+1][y+1] = 1;
            f.element = {x,y};
            f.di = t;
            p.push(f);//��ջ
            Dprint(D);
            x = x+dir[t].x;
            y = y+dir[t].y;
        }
        else if(num==90 && chess[x+1][y+1]==0)
        {//�۲�findPath�������������һ����·���ߣ�����d=9������-1
            chess[x+1][y+1] = num;
            f.element = {x,y};
            f.di = t;
            p.push(f);
        }else{
            if(p.pop(&f)==-1)
            {//��վ��Ϊ��
                cout<<"Can't find the path!"<<endl;
                exit(0);
            }
            num-=2;//����ǰһ����
            x = f.element.x;
            y = f.element.y;
            canPass[x+1][y+1][f.di] = 1;//����ʧ�ܣ�����·��ͨ
        }
    }
    printPath(chess);//��ӡ��

}










