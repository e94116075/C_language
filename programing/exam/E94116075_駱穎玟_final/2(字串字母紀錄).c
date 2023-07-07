#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char s[100] ,ch[26]={},n=0;
	int chsum[26]={0};
	while( scanf("%s",&s) ){
		int chsum[26]={0};
		for(int i=0;i<strlen(s);i++){
			if(s[i]>=97&&s[i]<=122){
				chsum[s[i]-97]++;
				
			}
			if(s[i]>=65&&s[i]<=90){
				chsum[s[i]-65]++;
			}
		}
		for(int i=0;i<26;i++){
			if(chsum[i]!=0){
				printf("%c: %d\n",i+65,chsum[i]);
			}
		}
	}
	return 0;
}
