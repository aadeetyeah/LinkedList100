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
int sortDsc(struct node**);
int copyDsc(struct node**,struct node**);

int main(){
	int itr1,num;
	struct node* src=NULL;
	struct node* dest=NULL;
	printf("Enter no. of nodes to be created.\n");
	scanf("%d",&num);
	for(int itr1=0;itr1<num;itr1++){
		createNode(&src);
	}
	printf("Source Linked List: ");
	display(src);
	copyDsc(&src,&dest);
	printf("\n\nDestination Linked List: ");
	display(dest);
	return 0;
}
int copyDsc(struct node **src,struct node** dest){
	if(*src==NULL){
		printf("No linked list to copy.\n");
		return -1;
	}else{
		LLCopy(src,dest);
		sortDsc(dest);
	}
	return 0;
}

int sortDsc(struct node** src){
	struct node* temp1=*src;
	struct node* temp2=*src;
	int data;
	while(temp1->next!=NULL){
		temp2=*src;
		while(temp2->next!=NULL){
			if(temp2->data<temp2->next->data){
				data=temp2->data;
				temp2->data=temp2->next->data;
				temp2->next->data=data;
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
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

