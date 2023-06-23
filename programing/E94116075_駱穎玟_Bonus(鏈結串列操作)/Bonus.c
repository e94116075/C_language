#include <stdio.h>
#include <stdlib.h>


struct node 
{
	int data;
	struct node *next;
};
typedef struct node NODE;

void printList(NODE *first){
	NODE* node=first;
	if(first==NULL){
		printf("List is empty\n");
	}
	else{
		while(node!=NULL){//end
			printf("%3d",node->data);
			node =node->next;//continue to go 
		}
		printf("\n");
	}
}
NODE *creatList(int arr[],int len){
	NODE *first ,*current ,*previous;
	for(int i=0;i<len;i++){
		current=(NODE*)malloc(sizeof(NODE));//give dynamic space
		current->data=arr[i];
		if(i==0){
			first=current;
		}
		else{
			previous->next=current;
		}
		current->next=NULL;
		previous=current;
	}
	return first;
}
void combineList(NODE *first1, NODE *first2){
	NODE* node=first1;
	while(node->next!=NULL){
			node =node->next;//continue to go 
		}
	node->next=first2;
}
NODE *insertFirstNode(NODE *node ,int item){
	NODE* firstnode;
	firstnode=(NODE *)malloc(sizeof(NODE));//give dynamic space
	firstnode->data=item;
	firstnode->next=node;
	return firstnode;
	}
int  listlength(NODE *first){
	NODE* node=first;
	int sum=1;//record the counts
	while(node->next!=NULL){
		sum++;
		node=node->next;
	}
	return sum;
}



NODE *reverseList(NODE *first){
	NODE *previous=NULL, *current=first, *preceding=first->next;
	while(current!=NULL){
		preceding=current->next;
		current->next=previous;//change the pointer
		previous=current;//move forward
		current=preceding;
	}
	return previous;
}
int main(){
	int arr1[] = {12, 43, 56, 34, 98};
	int arr2[] = {36, 77, 99};
	NODE *first ,*second;
	first=creatList(arr1,5);
	printList(first);
	second=creatList(arr2,3);
	printList(second);
	combineList(first,second);
	printList(first);
	first=insertFirstNode(first,0);
	printList(first);
	int sum=listlength(first);
	printf("The length of the list=%d\n",sum);
	first=reverseList(first);
	printList(first);
	
}
