//自定义栈，数组描述
#include <iostream>
#include <stdlib.h>

using namespace std;

//定义节点
template <class T>
struct pathNode
{
   // data members
   T element;
   int di;//方向
};

/*******************************************************************************/
template<class T>
class stack
{
public:
    stack()
        {    top = -1;  }
    int push(const pathNode<T> Element)
        {
            if(top >= 89)
                return -1;
            else{
                top++;
                path[top] = Element;
                return 1;
            }
        }
    bool empty()
        {
            if(top < 0)
                return true;
            else
                return false;
        }
    int pop(pathNode<T> *f)
        {
            if(top < 0)
                return -1;
            else
            {
                *f = path[top--];
                return 1;
            }
        }
    pathNode<T> Find(const int a)
        {
                        return path[a];
        }
    int TOP()
    {
        return top;
    }

private:
    pathNode<T> path[90];
    int top;//记录位置和站内元素个数
};

