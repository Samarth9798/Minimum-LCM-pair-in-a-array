//**********************************
//Problem name: G. Minimum Possible LCM (Codeforces Round #552 (Div. 3))
//time limit: 4s
//contraints: 2 <= n <= 10^6
//            1 <= a[i] <= 10^7
//**********************************

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main()
{
    fast
    
    ll n;
    
    cin >> n;
    
    ll a[n+1];
    
    bitset<10000005> bt;
    
    map<ll, vector<ll> > m;
    
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        
        bt[a[i]] = 1;
        
        m[a[i]].push_back(i);
    }
    
    pair< ll, pair<ll,ll> > pp;
    
    pp = make_pair(1e18 , make_pair(0, 0 ) );
    
    for(ll i = 1; i <= 1e7; i++)
    {
        int c = 0;
        
        pair<ll , ll> p;
        
        for(ll j = i; j <= 1e7; j += i)
        {
            if(c == 2)
                break;
                
            if(!bt[j])
                continue;
                
            if(c == 0)
            {
                if(m[j].size() == 1)
                {
                    p.first = m[j][0];
                    c = 1;
                }
                else
                {
                    p = make_pair(m[j][0] , m[j][1]);
                    c = 2;
                }
            }
            else
            {
                p.second = m[j][0];
                c = 2;
            }
        }
        
        if(c == 2)
        {
            ll LCM = (a[p.first]* a[p.second]) / __gcd(a[p.first], a[p.second]);
            
            pp = min( pp , make_pair(LCM , p) );
        }
    }
    
    pair<ll , ll> ans = pp.second;
    
    cout << min(ans.first, ans.second) << ' ' << max(ans.first, ans.second);
}


Language Version:  g++ 14 GCC 8.1.0
