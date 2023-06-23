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
		printf("���ߵ���!\n");
		return 0;	
	}
	else{
		return 1;
	}
		
} 
int stupidproof(int n,char guesspro[]){
	if(strlen(guesspro)!=n){//if the user send the number in wrong digits.
		printf("�z��J�������\n");
		printf("�Э��s��J\n");
		return -1;
	}
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(i==j){
				continue;
			}
			else if(guesspro[j]==guesspro[i]){
				printf("�z��J��%d��Ʀr�����o�����ƼƦr\n",n);
				printf("�Э��s��J\n");
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
	printf("1A2B�C���W�h�G�X�D�̵��w�@�ե|��Ƭ������A�B�o�|�ӼƦr�����ơC�C�q�@�ӼơA�X�D�̶����XXAYB�Φ��������X�D���X4A0B�ɰ��C�䤤�AA�N��Ʀr��B��m��AB�N��Ʀr�����m���C���a�i��ܥ|�ؼҦ��A���O��:\n");//print out following four lines to let users know the rules of the game
	printf("1�G�|��ƪ����A�q�����X�D�̡A�ϥΪ̬����D�̡C�����ѹq���üƵ��w�C\n");
	printf("2�G�|��ƪ����A�ϥΪ̬��X�D�̡A�q�������D�̡C�����ѨϥΪ̿�J�C\n");
	printf("3�G����ƪ������q�����X�D�̡A�ϥΪ̬����D�̡C\n");
	printf("4�G�C������\n");
		for(int j=0;j>=0;j++){
			printf("�C���}�l�A�п�J�Ҧ�1/2/3/4\n");
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
						printf("�п�J�z�Ҳq��������(�����@�|��ƥB�U��Ʀr���o����)\n");
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
					printf("�п�J����:");
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
						printf("�п�J�z�Ҳq��������(�����@����ƥB�U��Ʀr���o����)\n");
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
					printf("�C������\n");//end the game
				    return 0;
		    }
		}
}
