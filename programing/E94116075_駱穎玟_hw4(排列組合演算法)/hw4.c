#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int total_num[10000000000][100];
int random(int n,char* s[],char* s1[],char* num[] ,char* num1[]){//find a group of different cards
		for(int i=0;i<n;i++){
			s1[i]=s[rand()%4];//find the color
			num1[i]=num[rand()%13];//find the number
			for(int j=0;j<i;j++){
				if(s1[i]==s1[j]&&num1[j]==num1[i]){//if the card is the same as the others
					i--;
					break;
				}
			}
		}
		for(int i=0;i<n;i++){//print all cards
			printf("%s %s\n",s1[i],num1[i]);
		}
	return 0;
	
}
int k=0,a=0; 
void dfs(int t,int n,long long int per_num,int queue_num[],int tag[],char* s1[],char* num1[])//set out all possible orders of cards 
{	
    if(t==0)//if there's no more number to choose from 
    { 
        for(int i=0;i<n;++i){
        	if(i==0){ 
            	printf("\ntype %d\n",k+1); 
            	k++;
        	}
            total_num[k][i]=queue_num[i];
            //printf("k=%d,i=%d %d\n",k,i,total_num[k][i]);
            printf("%s %s\n",s1[total_num[k][i]-1],num1[total_num[k][i]-1]);//print all 
            
    	} 
    	
        return 0;
    }
    for(int i=1;i<=n;++i){
        if(tag[i]==0){
            queue_num[n-t]=i;
            tag[i]=1;
            dfs(t-1,n,per_num,queue_num,tag,s1,num1);
            tag[i]=0;
        }
    }
}
int main() {
	int k=0;
	int tag[1000]={0};
	int n;
	printf("How many cards you want to get?(plz enter a number between 1 and 13)");
	scanf("%d",&n);
	long long int per_num=1;
	for(int i=1;i<=n;i++){
		per_num=per_num*i;
	}
	
	printf("%d",per_num);
	int queue_num[n];
	char* s[4]={"Spade","Heart","Diamond","Club"};
	char* s1[n];
	char* num[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"} ;
	char* num1[n];
	srand(time(NULL));
	char ans='y',ans1='y';
	while(ans=='y'){
  		random(n,s,s1,num,num1);
		printf("Do you want to resend your cards?\n") ; 
		printf("y/n?");
		fflush(stdin);
		scanf("%c",&ans);
	}
	
	/*for(int i=0;i<per_num;i++){
		for(int j=0;j<n;j++){
			printf("*j=%d,i=%d %d\n ",j,i,total_num[j][i]);
		}
		
	}
	*/
	char ans2;
	printf("Do you want to set out all your  orders of cards?");
	printf("y/n?");
	fflush(stdin);
	scanf("%c",&ans2);
	if(ans2=='y'){
		if(n>6){
			printf("The number of cards is numerous,are you sure you still want to set out your orders of cards?\n") ; 
			printf("y/n?");
			fflush(stdin);
			scanf("%c",&ans1);
			if(ans1=='y'){
				dfs(n,n,per_num,queue_num,tag,s1,num1);
			}
	     	else{
	     		return 0;
			}
		
		}
		else{
			dfs(n,n,per_num,queue_num,tag,s1,num1);
		}
	}
	else{
		return 0;
	}
	return 0;
}
   
	
	
