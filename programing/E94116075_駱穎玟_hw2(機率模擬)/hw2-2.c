#include <stdio.h>
#include <stdlib.h>
#include<time.h>               // remember to "include" the time function when using it

int main(void)
{
	int sum=0,count=0;	//record the times the user wins the lottory and the cycle between 1-90 relative to the odd 
	srand((unsigned)time(NULL)); // initialize random number generator
	for(int j=0;j<100000000;j++){//run 1000000 times to raise the precision of the data
		float ans;	
	    ans=(float)rand()/RAND_MAX;  // produce a float number between 0~1 in radom
		if(count<=73&&ans<=0.006){ //win the lottery before 74th times in the cycle 
			sum+=1;
			count=0;//return to zero
		}
		else if(count>73&&ans<=0.006+(count-73)*0.06){//win the lottery after 73th times in the cycle
			sum+=1;
			count=0;
		}
		else{//doesn't win the loterry
			count+=1;
		}
	} 

    float answer;
    answer=0.00000001*sum*100;
    printf("⒱ㄴㄽ촒Ħ╈(쬽첦㈂)ず업쾤О %.2f%%\n",answer);
    
    
    
    
	int sum1=0,count1=0;	//record the times the user wins the lottory and the times relative to the odd 
	srand((unsigned)time(NULL)); // initialize random number generator
	for(int j=0;j<100000000;j++){ //run 1000000 times to raise the precision of the data
		float ans1;	
	    ans1=(float)rand()/RAND_MAX;  // produce a float number between 0~1 in radom
	    count1+=1;
		if(count1<=8&&ans1<=0.051){//if the count1 is <= 8 and ans1 is <=0.051
			sum1+=1;
			count1=0;
		}
		else if(count1==9&&ans1<=0.562){
			sum1+=1;
			count1=0;
		}
		else if(count1==10){
			sum1+=1;
			count1=0;
		}
	} 
	 float answer1;
    answer1=0.00000001*sum1*100;
    printf("⒱ㄴ�|촒Ħ╈(쬽첦㈂)ず업쾤О %.2f%%",answer1);
	    return 0;
}
