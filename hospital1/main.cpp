#include "dijkstra.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main() {
    int vexnum; int edge;
    cout << "输入村庄个数和村庄之间的路径的条数：" << endl;
    cin >> vexnum >> edge;
    int result[vexnum+1];
    int minum= INT_MAX, re=0;
    int a;


    Graph_DG graph(vexnum, edge);
    graph.createGraph();

    for(int i=1; i<=vexnum; i++)
    {
        result[i-1]=graph.Dijkstra(i);
        if(minum>result[i-1])
        {
             minum=result[i-1];
             re=i;
        }

    }
    cout<<"医院应该建在："<<re<<",总路径为："<<result[re-1]<<endl;
//    graph.print_path(2);
    return 0;
}




/*

1 3 10
1 5 30
1 6 100
3 2 5
3 4 50
4 6 10
5 6 60
5 4 20

*/
