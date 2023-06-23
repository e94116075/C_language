#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char str[5],guess[5];//use two array in sring type to save the guessed number and the answer 
int cp(int n){
    int ans,count=0,sum=0;//use variable count to record the number of digits we have found. 
    int anss[n];//record the number that has to return
    for(int i=0;i<n;i++){
    	anss[i]=-1;
	}
	for (int i=0;count<n;i++){//find the number having different numbers in different digits
		ans=rand()%10;//find a number in random
		for (int j=0;j<n;j++){
			if(ans==anss[j]){//if the number is the same as the numbers in other digits
				break;	
			}
			else if(j==n-1){//if the number isn't the same as the numbers in other digits
				anss[count]=ans;//record the number
				count++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			anss[i]=anss[i]*10;
		}
		sum+=anss[i];//sum up the number that has to return
	}
	return sum ;
}
int test(int n){
	int A=0;
	int B=0;
	for(int i=0;i<n;i++){
		if(str[i]==guess[i]){//if the number is right and it's in the right place
			A++;
		}
		else{
			for (int j=0;j<n;j++){
				if(str[i]==guess[j]){//if the number is right but in the wrong place
					B++;
				}
			}	
		}
	}
	printf(">>%dA%dB\n",A,B);
	if(A==n&&B==0){//if every number is in the right place
		printf("恭喜答對!\n");
		return 0;	
	}
	else{
		return 1;
	}
		
} 
int stupidproof(int n,char guesspro[]){
	if(strlen(guesspro)!=n){//if the user send the number in wrong digits.
		printf("您輸入錯的位數\n");
		printf("請重新輸入\n");
		return -1;
	}
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(i==j){
				continue;
			}
			else if(guesspro[j]==guesspro[i]){
				printf("您輸入的%d位數字中不得有重複數字\n",n);
				printf("請重新輸入\n");
				i=n;
				return -1;
			}
		}
	}
	return 0;
}

int main(void) {	
	int n,ans1,ans2,flag=0;
	srand(time(NULL));
	printf("1A2B遊戲規則：出題者給定一組四位數為謎底，且這四個數字不重複。每猜一個數，出題者須做出XAYB形式的提直出題說出4A0B時停。其中，A代表數字對且位置對，B代表數字對但位置錯。玩家可選擇四種模式，分別為:\n");//print out following four lines to let users know the rules of the game
	printf("1：四位數版本，電腦為出題者，使用者為答題者。謎底由電腦亂數給定。\n");
	printf("2：四位數版本，使用者為出題者，電腦為答題者。謎底由使用者輸入。\n");
	printf("3：五位數版本之電腦為出題者，使用者為答題者。\n");
	printf("4：遊戲結束\n");
		for(int j=0;j>=0;j++){
			printf("遊戲開始，請輸入模式1/2/3/4\n");
			scanf("%d",&n);//type the number which stands for the specific mode
			switch(n){
				case 1:
					n=4;
					flag=0;	
					ans1=cp(n);//call the function to give a random number without repeated number in each digit
					sprintf(str,"%04d",ans1);//change the number in int type into the string type
					//printf("%s",str); 
					for(int i=0;i>=0;i++){
						char guess1[100];	
						printf("請輸入您所猜測的答案(須為一四位數且各位數字不得重複)\n");
						printf("Input:");
						scanf("%s",guess1);
						if(stupidproof(n,guess1)==-1){
							continue;
						}
						
						for(int i=0;i<n;i++){
							guess[i]=guess1[i];//send what the user type to the array 'guess'
						}
						ans2=test(n);//call the function to compare the guess number and answer
						if(ans2==0){//if user or computer find the answer
							break;
						}
					}	
					break;
				case 2:
					n=4;//four digits
					printf("請輸入謎底:");
					scanf("%s",str);//user type the answer 	
					for(int i=0;i>=0;i++){
						ans1=cp(n);//call computer to guess
						sprintf(guess,"%d",ans1);
						printf("Input:%s",guess);
						ans2=test(n);
						if(ans2==0){
							break;
						}
					}
					break;
				case 3:
					n=5;//five digits
					ans1=cp(n);//call the function to give a random number without repeated number in each digit
					sprintf(str,"%05d",ans1);//change the number in int type into the string type
		    		/*printf("%s",str);*/ 
					for(int i=0;i>=0;i++){
						char guess2[100];	
						printf("請輸入您所猜測的答案(須為一五位數且各位數字不得重複)\n");
						printf("Input:");
						scanf("%s",guess2);
						if(stupidproof(n,guess2)==-1){
							continue;
						}
						
						for(int i=0;i<n;i++){
							guess[i]=guess2[i];//send what the user type to the array 'guess'
						}
						ans2=test(n);//call the function to compare the guess number and answer
						if(ans2==0){//if user or computer find the answer
							break;
						}
					}
				break;
				case 4:
					printf("遊戲結束\n");//end the game
				    return 0;
		    }
		}
}
