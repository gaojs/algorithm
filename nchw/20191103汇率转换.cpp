#include <cstdio>
#include <iostream>
#include <string>
using namespace std; 

int main()
{
	long long cny2hkd, usd2cny, gbp2usd, count;
	long long gbp, usd, cny, hkd; 
	long long gbp2hkd, usd2hkd; 
	string type, mode;
	
	cin>>cny2hkd>>usd2cny>>gbp2usd>>count>>type>>mode;
	if((cny2hkd<=0 || usd2cny<=0|| gbp2usd<=0||count<=0)
		|| (type!="HKD"&&type!="CNY"&&type!="USD"&&type!="GBP")
		|| (mode!="MAX"&&mode!="MIN"))
	{
		//cout<<"ERROR";//<<endl;
		printf("ERROR");
	}
	else
	{
		gbp2hkd=gbp2usd*usd2cny*cny2hkd;
		usd2hkd=gbp2usd*usd2cny; 
		if(type=="GBP")
		{
			hkd = count*gbp2hkd; 
		}
		else if(type=="USD")
		{			
			hkd = count*usd2hkd; 
		}
		else if(type=="CNY")
		{
			hkd = count*gbp2usd; 		
		}
		else //if(type=="HKD")
		{
			hkd = count; 			
		}
		
		if(mode=="MIN") 
		{	
			//cout<<hkd<<" HKD";//<<endl;
			printf("%lld HKD", hkd);
		}
		else// if(mode=="MAX") 
		{
			gbp = hkd / (gbp2hkd);
			hkd = hkd % (gbp2hkd);
			usd = hkd / (usd2hkd);
			hkd = hkd % (usd2hkd);
			cny = hkd / (cny2hkd);
			hkd = hkd % (cny2hkd);
			if(gbp > 0)
			{
				//cout<<gbp<<" GBP";
				printf("%lld GBP", gbp);
				//if(hkd>0) cout<<" "; 
				if(hkd>0) printf(" "); 
			}
			if(usd > 0)
			{
				//cout<<usd<<" USD";
				printf("%lld USD", usd);
				//if(hkd>0) cout<<" "; 
				if(hkd>0) printf(" "); 
			}
			if(cny > 0)
			{
				//cout<<cny<<" CNY";
				printf("%lld CNY", cny);
				//if(hkd>0) cout<<" "; 
				if(hkd>0) printf(" "); 
			}
			if(hkd > 0)
			{
				//cout<<hkd<<" HKD";
				printf("%lld HKD", hkd);
			}		
			//cout<<endl;
		} 	
	} 
	return 0;
}
