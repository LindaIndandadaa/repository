#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
using namespace std;

/*
��������ʹ��Dijkstra�㷨ʵ��������·��������
���õ��ڽӾ������洢ͼ
*/

//��¼��㵽ÿ����������·������Ϣ
struct Dis {
    string path;
    int value;
    bool visit;
    Dis() {
        visit = false;
        value = 0;
        path = "";
    }
};

class Graph_DG {
private:
    int vexnum;   //ͼ�Ķ������
    int edge;     //ͼ�ı���
    int **arc;   //�ڽӾ���
    Dis * dis;   //��¼�����������·������Ϣ
public:
    //���캯��
    Graph_DG(int vexnum, int edge);
    //��������
    ~Graph_DG();
    // �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
    //�����1��ʼ���
    bool check_edge_value(int start, int end, int weight);
    //����ͼ
    void createGraph();
    //�����·��
    int Dijkstra(int begin);
    //��ӡ���·��
    void print_path(int);
};
/*******************************/
//���캯��
Graph_DG::Graph_DG(int vexnum, int edge) {
    //��ʼ���������ͱ���
    this->vexnum = vexnum;
    this->edge = edge;
    //Ϊ�ڽӾ��󿪱ٿռ�͸���ֵ
    arc = new int*[this->vexnum];
    dis = new Dis[this->vexnum];
    for (int i = 0; i < this->vexnum; i++) {
        arc[i] = new int[this->vexnum];
        for (int k = 0; k < this->vexnum; k++) {
            //�ڽӾ����ʼ��Ϊ�����
                arc[i][k] = INT_MAX;
        }
    }
}
//��������
Graph_DG::~Graph_DG() {
    delete[] dis;
    for (int i = 0; i < this->vexnum; i++) {
        delete this->arc[i];
    }
    delete arc;
}

// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
//�����1��ʼ���
bool Graph_DG::check_edge_value(int start, int end, int weight) {
    if (start<1 || end<1 || start>vexnum || end>vexnum || weight < 0) {
        return false;
    }
    return true;
}

void Graph_DG::createGraph() {
    cout << "������ÿ���ߵ������յ㣨�����Ŵ�1��ʼ���Լ���Ȩ��" << endl;
    int start;
    int end;
    int weight;
    int count = 0;
    while (count != this->edge) {
        cin >> start >> end >> weight;
        //�����жϱߵ���Ϣ�Ƿ�Ϸ�
        while (!this->check_edge_value(start, end, weight)) {
            cout << "����ıߵ���Ϣ���Ϸ�������������" << endl;
            cin >> start >> end >> weight;
        }
        //���ڽӾ����Ӧ�ϵĵ㸳ֵ
        arc[start - 1][end - 1] = weight;
        ++count;
    }
}

int Graph_DG::Dijkstra(int begin){
    //���ȳ�ʼ�����ǵ�dis����

    int i;
    for (i = 0; i < this->vexnum; i++) {
        //���õ�ǰ��·��
//        dis[i].path = to_string(begin) + "-->" + to_string(i + 1);
        dis[i].value = arc[begin - 1][i];
    }
    //�������ĵ�����·��Ϊ0
    dis[begin - 1].value = 0;
    dis[begin - 1].visit = true;

    int count = 1;
    //����ʣ��Ķ�������·����ʣ��this->vexnum-1�����㣩
    while (count != this->vexnum) {
        //temp���ڱ��浱ǰdis��������С���Ǹ��±�
        //min��¼�ĵ�ǰ����Сֵ
        int temp=0;
        int min = INT_MAX;
        for (i = 0; i < this->vexnum; i++) {//Ѱ��ʣ����е���Сֵ
            if (!dis[i].visit && dis[i].value<min) {
                min = dis[i].value;
                temp = i;
            }
        }
        //��temp��Ӧ�Ķ�����뵽�Ѿ��ҵ������·���ļ�����
        dis[temp].visit = true;
        count++;
        for (i = 0; i < this->vexnum; i++) {
            //ע�����������arc[temp][i]!=INT_MAX����ӣ���Ȼ�����������Ӷ���ɳ����쳣
            if (!dis[i].visit && arc[temp][i]!=INT_MAX && (dis[temp].value + arc[temp][i]) < dis[i].value) {
                //����µõ��ı߿���Ӱ������Ϊ���ʵĶ��㣬�Ǿ;͸����������·���ͳ���
                dis[i].value = dis[temp].value + arc[temp][i];
//                dis[i].path = dis[temp].path + "-->" + to_string(i + 1);
            }
        }
    }

    int a=0;//��¼ÿ�����㵽��������ľ�����С֮��
    for (i = 0; i < this->vexnum; i++)
    {
        if(dis[i].value==INT_MAX)
    		return INT_MAX;
    	else
    		a+=dis[i].value;
    }
    cout<<"a="<<a<<endl;
    return a;


}
/*
void Graph_DG::print_path(int begin) {
    string str;
//    str =to_string(begin);
    cout << "��"<<str<<"Ϊ����ͼ�����·��Ϊ��" << endl;
    for (int i = 0; i != this->vexnum; i++) {
        if(dis[i].value!=INT_MAX)
       		 cout << dis[i].path << "=" << dis[i].value << endl;
        else {
            cout << dis[i].path << "�������·����" << endl;
        }
    }
}
*/
