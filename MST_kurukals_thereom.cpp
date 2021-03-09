#include<bits/stdc++.h>
#include<set>
#define lli int
#define pb push_back
#define rep(i,a,n) for(lli i=a;i<n;i++)
#define all(v) (v.begin(),v.end())
#define ppb pop_back
#define sz(v) v.size()
#define pi 3.141592653589793238
#define fr first;
#define sc second
#define ins insert
using namespace std;
lli pa[200001];

lli find_set(lli i){
	if(i==pa[i]) return i;
	return find_set(pa[i]);
}

void union_set(lli u,lli v){
    pa[u]=pa[v];
}

void  kruskals(lli n){
	rep(i,0,100001) pa[i]=i;
	lli ans=0;
	set<pair<lli ,pair<lli,lli>>>ss;
	set<pair<lli ,pair<lli,lli>>>kk;
	lli w,a,b,p1,p2;
	rep(i,0,n){
		cin>>a>>b>>w;
		ss.insert({w,{a,b}});
		
	}
	
	while(ss.size()!=0){
		w=(ss.begin()->first);
		a=(ss.begin()->second).first;
		b=(ss.begin()->second).second;
		
		p1=find_set(a);
		p2=find_set(b);
		ss.erase(ss.begin());
		
		if(p1!=p2)  {
		    ans+=w; 
		    kk.insert( { w, {a,b}} );
	    	union_set(p1,p2);
	   }
		
	}
	cout<<ans<<endl;
	
	while(kk.size()!=0){
	    	w=(kk.begin()->first);
		a=(kk.begin()->second).first;
		b=(kk.begin()->second).second;
		kk.erase(kk.begin());
		cout<<a<<" "<<b<<" "<<w<<endl;
	    
	}
	
	
	
}


int main()
{

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	lli t,n;
	cin>>n;
	
	kruskals(n);

	
	
	return 0;
}