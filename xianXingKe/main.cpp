#include <iostream>
#include <stdlib.h>
#include "xian.h"

using namespace std;

int main()
{
    int n,sn,pre,las;
    cout<<"�γ�����"<<endl;
    cin>>n;
    cout<<"��������п�����������"<<endl;
    cin>>sn;
    cout<<"�������пε����У�"<<endl;
    ke K(n);
    section s[sn+1] ;//={ 1 3 1 4 3 4 3 6 2 4 2 5 5 6 4 6 };

    for(int i=0;i<sn;i++)
    {
        cin>>pre;
        s[i].x=pre;
        cin>>las;
        s[i].y=las;
    }

    K.methed(s,sn);

    return 0;
}
