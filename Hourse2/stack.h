//�Զ���ջ����������
#include <iostream>
#include <stdlib.h>

using namespace std;

//����ڵ�
template <class T>
struct pathNode
{
   // data members
   T element;
   int di;//����
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
    int top;//��¼λ�ú�վ��Ԫ�ظ���
};

