#include <stdio.h>
#include <stdlib.h>
#include<time.h>                 // remember to "include" the time function when using it 

int main(void)
{
	int sum=0;//record the times the user wins the lottory
	srand((unsigned)time(NULL)); // initialize random number generator
	for(int i=0;i<100000000;i++){//run 1000000 times to raise the precision of the data
	    float ans;
	
	    ans=(float)rand()/RAND_MAX;  // produce a float number between 0~1 in radom
		if(ans<=0.006){
			sum=sum+1;
		}
    }
    float answer;
    answer=0.00000001*sum*100;
    printf("⒱ㄴㄽ촒Ħ╈ず업쾤О %.2f%%\n",answer);
    
    
    
	int sum1=0;//record the times the user wins the lottory
	for(int i=0;i<100000000;i++){//run 1000000 times to raise the precision of the data
	    float ans1;
	
	    ans1=(float)rand()/RAND_MAX;  // produce a float number between 0~1 in radom
		if(ans1<=0.051){
			sum1=sum1+1;
		}
    }
    float answer1;
    answer1=0.00000001*sum1*100;
    printf("⒱ㄴ�|촒Ħ╈ず업쾤О %.2f%%",answer1);
	return 0;
}
