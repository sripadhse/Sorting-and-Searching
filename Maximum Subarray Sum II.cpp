#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll,ll>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define vi vector<ll>
#define vii vector<pii>
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define yes cout<<"YES"<<endl; return;
#define no cout<<"NO"<<endl; return;
#define flus fflush(stdin); fflush(stdout);
#define F first
#define S second
#define np next_permutation
#define inf 1e18
#define mod 1000000007
#define N 200100
#define pi (double)2*acos(0.0)
#define minpq priority_queue <ll, vector<ll>, greater<ll>>
#define maxpq priority_queue<ll> 
void sout(){
	cout<<endl;
}
template <typename T,typename... Types>
void sout(T var1,Types... var2){
	cout<<var1<<" ";
	sout(var2...);
}
/*******************************************************************/
 
 
ll arr[N];
ll pre[N];
ll tree[4*N];
ll n,a,b;
void build(ll s,ll e,ll ind=1){
	if(s==e){
		tree[ind]=pre[s];
		return;
	}
	ll mid=(s+e)/2;
	build(s,mid,2*ind);
	build(mid+1,e,2*ind+1);
	tree[ind]=max(tree[2*ind],tree[2*ind+1]);
}
ll getmax(ll s,ll e,ll l,ll r,ll ind=1){
	if(e<l or s>r)
		return -2*inf;
	if(s>=l and e<=r)
		return tree[ind];
	ll mid=(s+e)/2;
	ll a=getmax(s,mid,l,r,2*ind);
	ll b=getmax(mid+1,e,l,r,2*ind+1);
	return max(a,b);
}
ll getmax(ll l,ll r){
	return getmax(0,n,l,r);
}
void solve(){
	
	cin>>n>>a>>b;
	
	rep(i,1,n+1){
		cin>>arr[i];
	}
	
	pre[0]=0;
	rep(i,1,n+1){
		pre[i]=pre[i-1]+arr[i];
	}
	
	build(0,n);
	ll ans=-inf;
	for(ll i=a;i<=n;i++){
		ll x=getmax(min(n,i+1),min(n,i+b-a));
		x=x-pre[i];
		x=max(x,0LL);
		// sout("x",x);
		ll loc=x+pre[i]-pre[i-a];
		ans=max(ans,loc);
	}
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}