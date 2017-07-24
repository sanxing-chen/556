const int mod = 1000000009;
const int maxn = 10005;
int inv[maxn];
inv[1] = 1;
for (int i = 2; i < 10000; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;


//快速一个
inline long long pow_mod(long long a,long long n)  
{  
    long long ans=1;  
    while(n)  
    {  
        if(n&1) ans=ans*a%mod;  
        a=a*a%mod;  
        n>>=1;  
    }  
    return ans;  
}
long long getinv(long long n)  
{  
    return pow_mod(n,mod-2);  
}