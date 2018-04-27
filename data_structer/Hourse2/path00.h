
//用矩阵存储中国象棋盘9*10，
//
#include <iostream>
#include <stdio.h>
#include <stack>
//#include "linkedStack.h"

using namespace std;


int chess[8][8];//类似于迷宫老鼠，马走日，在棋盘的周围建两堵墙，

typedef struct
{
    int row, col;
}direction; //坐标

stack<direction> path;//栈指针

direction dir[8] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}}; //马的八个方向

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
    //输出棋盘
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
    //初始化棋盘
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            chess[i][j]=0;
    for(int i=0; i<8; i++)
        chess[i][0] = chess[i][1] = chess[i][7] = chess[i][6] = 1;//左边和右边
    for(int i=0; i<8; i++)
        chess[0][i] = chess[1][i] = chess[7][i] = chess[6][i] = 1;//上面和下面


/****************************************************************************************/
    direction here = {row, col}; //当前位置(2,2)
    chess[row][col] = 1;//防止倒回到当前位置

    int option = 0;//下一步，
    int lastOption = 7; //边界

    //寻找通向出口的路径
    while(path.size() < 16)
    {
        int r, c;
        while(option<=lastOption)
        {
            r = here.row + dir[option].row;
            c = here.col + dir[option].col;
            if(chess[r][c]==0) break;
            option++;//下一个选择
        }
        //下一位存在
        if(option <= lastOption)
        {
            display();
            cout<<"next"<<endl;
            path.push(here);//入栈
            here.row = r;
            here.col = c;
            //移动到下一位，并标记上(4,3)
            chess[here.row][here.col] = 1;
            option = 0;

        }else{
            //不存在，即option=8；有两种情况,一种是走完了棋盘；一种是走投无路，棋盘还有。通过栈里的数量来判断
         /**************************************************************************************************************/
            cout<<path.size()<<endl;

            if(path.size() >= 16)
                 return true;
            else{
                if(path.empty())
                    return false;

                direction next = path.top();
                path.pop();
                //已回退，寻找回退点的下一个可行方向
                if(next.row==here.row-2 && next.col==here.col-1) //从第一个位置来的，该往第二个方向走
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
                 cout<<"回退回退回退回退:"<<endl;
                chess[here.row][here.col] = 0;//回到上一个点，当前点置零。
                 display();
                here = next;
            }

        }
    }

    return true;
}

