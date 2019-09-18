#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

const int MAXN = 100100;
int n, pontos[MAXN];
vector<pair<int,int> > poligono1;
vector<pair<int,int> > poligono2;

int cross(pair<int,int> a, pair<int,int> b){
	long long int res = a.x*b.y - a.y*b.x;
	if(res < 0) return -1;
	if(res > 0) return 1;
	if(res == 0) return 0;
}

void constroibaixo(){

	for(int i=1; i<=n; i++){

		if(poligono2.size() <= 1) break;

		int tam1 = poligono2.size()-2;
		int tam2 = poligono2.size()-1;
		
		pair<int,int> a = make_pair(poligono2[tam1].x, poligono2[tam1].y);
		pair<int,int> b = make_pair(poligono2[tam2].x, poligono2[tam2].y);
		pair<int,int> c = make_pair(pontos[i].x, pontos[i].y);
		pair<int,int> v1 = make_pair(b.x-a.x, b.y-a.y);
		pair<int,int> v2 = make_pair(c.x-b.x, c.y-b.y);	

		if(cross(v1, v2) >= 0) break;
		poligono2.pop_back();

	}

	poligono2.push_back(make_pair(pontos[i].x, pontos[i].y));

}

void constroicima(){

	for(int i=1; i<=n; i++){

		if(poligono1.size() <= 1) break;

		int tam1 = poligono1.size()-2;
		int tam2 = poligono1.size()-1;

		pair<int,int> a = make_pair(poligono1[tam1].x, poligono1[tam1].y);
		pair<int,int> b = make_pair(poligono1[tam2].x, poligono1[tam2].y);
		pair<int,int> c = make_pair(pontos[i].x, pontos[i].y);
		pair<int,int> v1 = make_pair(b.x-a.x, b.y-a.y);
		pair<int,int> v2 = make_pair(c.x-b.x, c.y-b.y);	

		if(cross(v1, v2) <= 0) break;
		poligono1.pop_back();

	}

	poligono1.push_back(make_pair(pontos[i].x, pontos[i].y));

}

int main(){

	scanf("%d", &n);

	for(int i=1; i<=n; i++) scanf("%d%d", &pontos[i].x, &pontos[i].y);

	sort(pontos+1, pontos+1+n);

	constroicima();
	constroibaixo();

	for(int i=0; i<(int)poligono1.size()-1; i++) printf("%d %d\n", poligono1[i].x, poligono1[i].y);
	for(int i=(int)poligono2.size()-1; i>=1; i--) printf("%d %d\n", poligono2[i].x, poligono2[i].y);

	return 0;
}