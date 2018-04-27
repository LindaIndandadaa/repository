
//�þ���洢�й�������9*10��
//
#include <iostream>
#include <stdio.h>
#include <stack>
//#include "linkedStack.h"

using namespace std;


int chess[8][8];//�������Թ����������գ������̵���Χ������ǽ��

typedef struct
{
    int row, col;
}direction; //����

stack<direction> path;//ջָ��

direction dir[8] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}}; //��İ˸�����

void outputPath()
{
    cout<<"The path is:"<<endl;
    direction here;
    while( !path.empty())
    {
        here = path.top();
        path.pop();
        cout<<"<"<<here.row<<","<<here.col<<">"<<"--";
    }
}

void display()
{
    //�������
    for(int i=2;i<6;i++)
    {
        for(int j=2;j<6;j++)
            cout<<chess[i][j]<<" ";
        cout<<endl;
    }
}


bool findPath(int row, int col)
{
    row++;col++;
    //��ʼ������
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            chess[i][j]=0;
    for(int i=0; i<8; i++)
        chess[i][0] = chess[i][1] = chess[i][7] = chess[i][6] = 1;//��ߺ��ұ�
    for(int i=0; i<8; i++)
        chess[0][i] = chess[1][i] = chess[7][i] = chess[6][i] = 1;//���������


/****************************************************************************************/
    direction here = {row, col}; //��ǰλ��(2,2)
    chess[row][col] = 1;//��ֹ���ص���ǰλ��

    int option = 0;//��һ����
    int lastOption = 7; //�߽�

    //Ѱ��ͨ����ڵ�·��
    while(path.size() < 16)
    {
        int r, c;
        while(option<=lastOption)
        {
            r = here.row + dir[option].row;
            c = here.col + dir[option].col;
            if(chess[r][c]==0) break;
            option++;//��һ��ѡ��
        }
        //��һλ����
        if(option <= lastOption)
        {
            display();
            cout<<"next"<<endl;
            path.push(here);//��ջ
            here.row = r;
            here.col = c;
            //�ƶ�����һλ���������(4,3)
            chess[here.row][here.col] = 1;
            option = 0;

        }else{
            //�����ڣ���option=8�����������,һ�������������̣�һ������Ͷ��·�����̻��С�ͨ��ջ����������ж�
         /**************************************************************************************************************/
            cout<<path.size()<<endl;

            if(path.size() >= 16)
                 return true;
            else{
                if(path.empty())
                    return false;

                direction next = path.top();
                path.pop();
                //�ѻ��ˣ�Ѱ�һ��˵����һ�����з���
                if(next.row==here.row-2 && next.col==here.col-1) //�ӵ�һ��λ�����ģ������ڶ���������
                    option = 1;
                if(next.row==here.row-1 && next.col==here.col-2)
                    option = 2;
                if(next.row==here.row+1 && next.col==here.col-2)
                    option = 3;
                if(next.row==here.row+2 && next.col==here.col-1)
                    option = 4;
                if(next.row==here.row+2 && next.col==here.col+1)
                    option = 5;
                if(next.row==here.row+1 && next.col==here.col+2)
                    option = 6;
                if(next.row==here.row-1 && next.col==here.col+2)
                    option = 7;
                if(next.row==here.row-2 && next.col==here.col+1)
                    option = 8;
                 cout<<"���˻��˻��˻���:"<<endl;
                chess[here.row][here.col] = 0;//�ص���һ���㣬��ǰ�����㡣
                 display();
                here = next;
            }

        }
    }

    return true;
}

