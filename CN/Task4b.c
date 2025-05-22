#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int gcd(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}
long long mod_exp(long long b, long long exp,long long mod)
{
    long long result=1;
    while(exp > 0)
    {
        if(exp%2==1)
        {
            result = (result*b)%mod;
        }
        b = (b*b)%mod;
        exp/=2;
    }
    return result;
}
int main()
{
    long long p,q,n,phi,e,d,msg,encrypt,decrypt;
    printf("Enter a Large Prime Number :");
    scanf("%lld",&p);
    printf("Enter a Large Prime Number :");
    scanf("%lld",&q);
    n = p*q;
    phi = (p-1)*(q-1);
    e=2;
    while(gcd(e,phi) != 1) e++;
    d=0;
    while((e*d)%phi != 1) d++;
    printf("Public Key (n = %lld, e = %lld)\n", n, e);
    printf("Private Key (n = %lld, d = %lld)\n", n, d);
    printf("Enter a number to decrypt:");
    scanf("%lld",&msg);
    encrypt = mod_exp(msg,e,n);
    printf("Encrypted Message = %lld\n",encrypt);
    decrypt = mod_exp(encrypt,d,n);
    printf("Decrypted Message = %lld\n",decrypt);
}
