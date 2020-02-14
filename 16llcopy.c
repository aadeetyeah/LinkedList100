#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
void createNode(struct node**);
void LLCopy(struct node**,struct node**);
void display(struct node*);
int count(struct node*);
int main(){
	int itr1,num;
	struct node* src=NULL;
	struct node* dest=NULL;
	printf("Enter no. of nodes to be created.\n");
	scanf("%d",&num);
	for(int itr1=0;itr1<num;itr1++){
		createNode(&src);
	}
	printf("Source Linked List:");
	display(src);
	LLCopy(&src,&dest);
	printf("\nDest Linked List:");
	display(dest);
	return 0;
}
void LLCopy(struct node **src,struct node **dest){
	struct node *stemp,*dtemp;
	stemp=*src;
	dtemp=*dest;
	struct node *newNode=NULL;
	while(stemp!=NULL){
		dtemp=*dest;
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data=stemp->data;
		newNode->next=NULL;
		if(*dest==NULL){
			*dest=newNode;
		}else{
			while(dtemp->next!=NULL){
				dtemp=dtemp->next;
			}
			dtemp->next=newNode;
		}
		stemp=stemp->next;
	}
}
void display(struct node *head){
	struct node *temp=head;
	while(temp->next!=NULL){
		printf("|%d|->",temp->data);
		temp=temp->next;
	}
	printf("|%d|",temp->data);
}
void createNode(struct node **head){
	struct node *temp=*head;
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data");
	scanf("%d",&newNode->data);
	newNode->next=NULL;
	if(*head==NULL){
		*head=newNode;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
}
int count(struct node *head){
	struct node *temp=head;
	int cnt=1;
	if(head==NULL){
		return 0;
	}
	while(temp->next!=NULL){
		cnt++;
		temp=temp->next;
	}
	return cnt;
}

