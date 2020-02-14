#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
int countNodes(struct node*);
void accept(struct node**,struct node**);
int concatList(struct node**,struct node**,int);
int insertLast(struct node**,int);
void display(struct node*);
int main(){
	int no;
	struct node *head1=NULL,*head2=NULL;
	accept(&head1,&head2);
	printf("Input source linked list: ");
	display(head1);
	printf("\nInput destination linked list: ");
	display(head2);
	printf("Number of Elements to be linked.\n");
	scanf(" %d",&no);
	concatList(&head2,&head1,no);
	printf("\nOutput destination linked list: ");
	display(head2);
	return 0;
}
int countNodes(struct node* head){
	struct node* temp=head;
	int cnt=1;
	while(temp->next!=NULL){
		temp=temp->next;
		cnt++;
	}
	return cnt;
}
void accept(struct node **head1,struct node **head2){
	int itr1,num,data;
	printf("Enter number of nodes to be created for List -1.\n");
	scanf("%d",&num);
	for(itr1=0;itr1<num;itr1++){
		printf("Enter data of node %d\n",itr1+1);
		scanf(" %d",&data);
		insertLast(head1,data);
	}
	printf("Enter number of nodes to be created for List -2.\n");
	scanf("	%d",&num);
	for(itr1=0;itr1<num;itr1++){
		printf("Enter data of node %d\n",itr1+1);
		scanf(" %d",&data);
		insertLast(head2,data);
	}
}
int insertLast(struct node **head,int data){
	struct node *temp=*head;
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	if(*head==NULL){
		*head=newNode;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
	return 0;
}
int concatList(struct node **src,struct node **dest,int no){
	struct node *temp=*dest;
	int cnt=countNodes(*dest);
	int num=cnt-no;
	if(no>cnt){
		printf("Max %d elements can be linked.\n",cnt);
		exit(1);
	}
	while(temp->next!=NULL && num!=0){
		temp=temp->next;
		num--;
	}
	while(temp->next!=NULL){
		insertLast(src,temp->data);
		temp=temp->next;
	}
		insertLast(src,temp->data);	
	return 0;
}
void display(struct node *head){
	struct node *temp=head;
	while(temp->next!=NULL){
		printf("|%d|->",temp->data);
		temp=temp->next;
	}
	printf("|%d|\n",temp->data);
}
