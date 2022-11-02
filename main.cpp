#include<iostream>
#include<string.h>
#include<cmath>
#include<vector>
using namespace std;
const long long MAXN = 47000;
vector<int> allPrimes;
vector<int> Primes;
bool isPrime[MAXN];
void basePrime()
{
	memset(isPrime,true,sizeof(isPrime));	 //set 1
	isPrime[0]=isPrime[1]=false; // 0 & 1 not prime number
	
	for(int i=4;i<MAXN;i+=2) //multiples of 2 are not prime (not include 2) 
		isPrime[i] = false;
		
	int limit = sqrt(MAXN) + 1; //most import part
	for(int i=3;i<=limit;i+=2)
	{
		int count = (MAXN-1)/i;
		int product = count * i;
		for(;count>=i;count--,product-=i)
		{
			if(isPrime[count])
				isPrime[product] = false;
		}
			
	}
	
	//push the prime number (<47000) 
	allPrimes.push_back(2);
	for(int i=3;i<MAXN;i+=2)
	{
		if(isPrime[i])
			allPrimes.push_back(i);
	}
	
} 
bool is_Prime(int num)
{
	if(num < MAXN)
		return isPrime[num];
	for(int i=0;i<allPrimes.size()&&allPrimes[i]<num;i++)
	{
		if(num%allPrimes[i] == 0)
			return false;
	}
	return true;
}
void calPrime(int L,int U)
{
	Primes.clear();
	for(long long i=L;i<=U;i++) // remember to use long long
	{
		if(is_Prime(i))
			Primes.push_back(i);
	}
}
int main()
{
	basePrime();
	int L,U;
	while(cin>>L>>U)
	{
		//find the prime number between L and U
		calPrime(L,U);
		
		int max = 0;
		int min = 1000001;
		int maxx,maxy,minx,miny;
		
		//calculate distance
		if(Primes.size()<=1)
			cout<<"There are no adjacent primes."<<endl;
		else
		{
			for(int i=0;i<Primes.size()-1;i++)
			{
				if(Primes[i+1] - Primes[i] > max)
				{
					max = Primes[i+1] - Primes[i];
					maxx = Primes[i];
					maxy = Primes[i+1];	
				}
				if(Primes[i+1] - Primes[i] < min)
				{
					min = Primes[i+1] - Primes[i];
					minx = Primes[i];
					miny = Primes[i+1];
				}
			}
			cout<<minx<<","<<miny<<" are closest, "<<maxx<<","<<maxy<<" are most distant."<<endl;
		}
		
		
	}
}
