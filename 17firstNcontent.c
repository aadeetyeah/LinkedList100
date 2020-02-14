#include<stdlib.h>

#include<stdio.h>
struct node{
	int data;
	struct node *next;
};
void createNode(struct node**);
void display(struct node**);
void LLCopy(struct node**,struct node**,int);
int main(){
	struct node *Head=NULL;
	struct node *Dest=NULL;
	int num,itr1,num1;
	printf("Enter no. of nodes to be created.\n");	
	scanf("%d",&num);
	for(itr1=0;itr1<num;itr1++){
		createNode(&Head);
	}
	display(&Head);
	printf("\nEnter no. of nodes to be copied.\n");
	scanf("%d",&num1);
	LLCopy(&Head,&Dest,num1);
	display(&Dest);
	return 0;
}
void LLCopy(struct node **head,struct node **dest ,int num){
	struct node *ht=*head;
	struct node *tt=*dest;
	struct node *newNode=NULL;
	while(num>0){
		tt=*dest;
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data=ht->data;
		newNode->next=NULL;
		if(*dest==NULL){
			*dest=newNode;
		}else{
			while(tt->next!=NULL){
				tt=tt->next;
			}
			tt->next=newNode;
		}
		num--;
		ht=ht->next;
	}
}
void createNode(struct node **head){
	struct node *htemp=*head;
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	printf("Enter element\n");
	scanf("%d",&newNode->data);
	newNode->next=NULL;
	if(*head==NULL){
		*head=newNode;
	}else{
		while(htemp->next!=NULL){
			htemp=htemp->next;
		}
		htemp->next=newNode;
	}
}
void display(struct node **Head){
	struct node *htemp=*Head;
	while(htemp->next!=NULL){
		printf("|%d|->",htemp->data);
		htemp=htemp->next;
	}
		printf("|%d|",htemp->data);
}
