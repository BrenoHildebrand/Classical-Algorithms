#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;
int n, tree[3*MAXN], q;
int v[MAXN];

int op(int a, int b){
	return a+b;
}

void build(int node, int l, int r){

	if(l==r){
		tree[node] = v[l];
		return;
	}

	int mid = (l+r)/2;
	build(node*2, l, mid);
	build(node*2+1, mid+1, r);

	tree[node] = op(tree[node*2], tree[node*2+1]);

}

void update(int node, int l, int r, int pos, int value){

	if(l==r){
		tree[node] = op(tree[node], value);
		return;
	}

	int mid = (l+r)/2;
	if(pos <= mid)
		update(node*2, l, mid, pos, value);
	else 
		update(node*2+1, mid+1, r, pos, value);

	tree[node] = op(tree[node*2], tree[node*2+1]);

	return;
}

int query(int node, int l, int r, int a, int b){

	if(a>b) swap(a,b);

	if(r < a || l > b) return 0;
	if(l >= a && r <= b) return tree[node];

	int mid = (l+r)/2;
	int direita = query(node*2, l, mid, a, b);
	int esquerda = query(node*2+1, mid+1, r, a, b);

	return op(direita, esquerda);
	
}

int main(){

	cin >> n;

	for(int i=1; i<=n; i++) cin >> v[i];

	build(1, 1, n);

	cin >> q;

	for(int i=1; i<=q; i++){

		char op;
		int a,b;

		cin >> op >> a >> b;

		if(op == 'u') update(1, 1, n, a, b);
		if(op == 'q') cout << query(1, 1, n, a, b) << "\n";

	}

	return 0;
}