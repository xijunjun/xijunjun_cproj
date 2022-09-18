#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <algorithm>
#include<fstream>
#include<string>
using namespace std;

double distTo[100];
//int edgeTo[100]; 
list<int> edgeTo[100];
int V, E;
const double INF_MAX = 9999999.9;
map<int, vector<tuple<int, int, double>>> EWD;

stack<int> path;
int coutSP = -1;

struct GreaterThanByDist
{
	bool operator()(const int i, const int j) const
	{
		return distTo[i] > distTo[j];
	}
};
priority_queue<int, vector<int>, GreaterThanByDist> Minpq;
void relax(tuple<int, int, double> edge)
{
	int v = get<0>(edge);
	int w = get<1>(edge);
	double weight = get<2>(edge);
	if (distTo[w] > distTo[v] + weight) {
		distTo[w] = distTo[v] + weight;
		//edgeTo[w] = v;
		edgeTo[w].clear();
		edgeTo[w].push_back(v);
		Minpq.push(w);
	}
	else if (distTo[w] == distTo[v] + weight)
	{
		edgeTo[w].push_back(v);
	}
}


void DijkstraSP(int s, int V)
{
	for (int v = 0; v < V; v++)
		distTo[v] = INF_MAX;
	distTo[s] = 0.0;

	Minpq.push(s);
	while (!Minpq.empty())
	{
		int v = Minpq.top();
		Minpq.pop();
		for (vector<tuple<int, int, double>>::iterator ii = EWD[v].begin();
			ii != EWD[v].end();
			ii++)
		{
			relax(*ii);
		}
	}
}

void dfs(int source, int vertex)
{
	coutSP++;
	if (vertex == source) coutSP = 0;
	for (list<int>::iterator ii = edgeTo[vertex].begin(); ii != edgeTo[vertex].end(); ii++)
	{
		if (coutSP == 0)  path.push(vertex);
		path.push(*ii);
		dfs(source, *ii);
	}
}



void computeSP(int source, int vertex)
{


	cout << "shortest path : ";

	DijkstraSP(source, V);
	cout << source << " to " << vertex << " ( " << distTo[vertex] << " ) " << " : ";

	dfs(source, vertex);

	while (!path.empty())
	{
		cout << path.top() << " ";
		path.pop();
	}

	cout << endl;
}

void showEWD()
{
	cout << "EdgeWeightedDigraph : " << endl;
	for (int v = 0; v < V; v++)
	{
		cout << v << " : ";
		for (vector<tuple<int, int, double>>::iterator ii = EWD[v].begin();
			ii != EWD[v].end();
			ii++)
		{
			cout << get<0>(*ii) << "->" << get<1>(*ii) << " " << get<2>(*ii) << "  ";
		}
		cout << endl;
	}
}
vector<string>split_str(string &s, string p)
{
	vector<string>res;
	string subtmp;
	int st = 0, ed = s.size();
	while (1)
	{
		int i = s.find_first_of(p, st);
		if (i == string::npos&&ed == -1)
			break;
		if ((i == string::npos || i == ed) && ed != -1){
			i = ed;
			ed = -1;
		}
		subtmp = s.substr(st, i - st);
		if (!subtmp.empty())
			res.push_back(subtmp);
		st = i + 1;
	}
	return res;
}
int main()
{
	//cin >> V >> E;
	//for (int i = 0; i < E; i++)
	//{
	//	int v, w;
	//	double weight;
	//	cin >> v >> w >> weight;
	//	EWD[v].push_back(make_tuple(v, w, weight));
	//}

	////showEWD();    

	//int source, vertex;
	//cout << "source  :  ";
	//cin >> source;
	//cout << "vertex : ";
	//cin >> vertex;

	//computeSP(source, vertex);
	#define CIN myin
	ifstream myin("input.txt");
	string word;

	int st=0, ed=3;
	//CIN >> st >> ed;
	V = 4;
	E=4;
	while (getline(CIN, word))
	{
		//cout << word << endl;
		vector<string> tmp = split_str(word, " ");
		int v = tmp[0][0]-'a';
		//cout << endl;
		for (int i = 1; i <= int(tmp.size() - 2); i+=2)
		{
			int w, weight;
			w = tmp[i][0] - 'a';
			weight = stoi(tmp[i+1]);
			EWD[v].push_back(make_tuple(v, w, weight));
			//cout << char(v) << "->" << char(w) << ":" << weight << endl;
		}
		//cout << word << endl;
	}
	showEWD();
	computeSP(st, ed);

	system("pause");
}