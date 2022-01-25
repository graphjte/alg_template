 
void Down(int id){
	t[id*2]+= Lazy[id];
	t[id*2+1]+= Lazy[id];
	Lazy[id*2]+= Lazy[id];
	Lazy[id*2+1]+= Lazy[id];
	Lazy[id] = 0;
}
 
void Build(int id, int l, int r){
	if (l==r){
		t[id] = a[l];
		return;
	}
	int mid = (l+r)/2;
	Build(id*2, l, mid);
	Build(id*2+1, mid+1, r);
}
 
void Update(int id, int l, int r, int L, int R, int val){
	if (r<L || R<l) return;
	if (L<=l && r<=R){
		Lazy[id] += val;
		if (l==r) t[id]+= val;
		return;
	}
	Down(id);
	int mid = (l+r)/2;
	Update(id*2, l, mid, L, R, val);
	Update(id*2+1, mid+1, r, L, R, val);
}
 
ll Query(int id, int l, int r, int pos){
	if (l==r && r==pos){
		return t[id];
	}
	Down(id);
	int mid = (l+r)/2;
	if (pos <= mid) return Query(id*2, l, mid, pos);
	else return Query(id*2+1, mid+1, r, pos);
}
