#include <iostream>
#include <stdio.h>
#include <string>
#include "path00.h"
#include "Welcome.h"
//#include "allPath.h"
using namespace std;


int main()
{
    welcome();
    system("color E4");
    int x,y,z,w;
    string a;
    bool f = true;

    while(f)
    {
        cout << "Please input the entrance:" << endl;
        cout<<"X= ";
        cin>>x;
        cout<<"Y= ";
        cin>>y;
        cout<<"START:"<<endl;

        if(findPath(x,y))
            outputPath();
        else
            cout<<"NO path";
        cout << "�Ƿ������ YES OR NO"<<endl;
        while(true)
        {
            cin>>a;
            if(!a.compare("YES")==0 && !a.compare("NO")==0)
                cout<<"����ȷ����YES\NO"<<endl;
            else{
                if(a.compare("NO")==0)
                    f=false;
                break;
            }
        }

    }
/*

    cout << "Please input the entrance:" << endl;
    cout<<"X= ";
    cin>>x;
    cout<<"Y= ";
    cin>>y;
    bool visited[90];
    for(int i=0; i<90;i++)
        visited[i]=false;
    stack<direction> sstack[90];
    int chess[14][13];//����
    ini_chess(chess);//��ʼ��

    Vexnode vv[90];
    flist(chess,vv);//���ʼ��
    for(int i=0; i<90;i++)
        vv[i].reset1(i);
    Vexnode v1,v90;//��ʼ�ڽ���
    v1=vv[1]; v90=vv[90];
    for(int i=1; i<10; i++)
        for(int j=1; j<9; j++)
            findPath(v1, v90, visited, sstack);

*/

    return 0;
}
