#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
int countNodes(struct node*);
void accept(struct node**,struct node**);
int concatList(struct node**,struct node**,int);
int concatListRange(struct node**,struct node**,int,int);
int insertLast(struct node**,int);
void display(struct node*);
int main(){
	int start,end;
	struct node *head1=NULL,*head2=NULL;
	accept(&head1,&head2);
	printf("Input source linked list: ");
	display(head1);
	printf("\nInput destination linked list: ");
	display(head2);
	printf("Start and End Element no. to be linked.\n");
	scanf(" %d %d",&start,&end);
	concatListRange(&head2,&head1,start,end);
	printf("\nOutput destination linked list: ");
	display(head2);
	return 0;
}
int concatListRange(struct node **src,struct node **dest,int start,int end){
	int cnt=countNodes(*src);
	int arr[cnt],itr1=0,itr2;
	struct node *temp=*dest;
	while(temp->next!=NULL){
		arr[itr1]=temp->data;
		itr1++;
		temp=temp->next;
	}
	arr[itr1]=temp->data;
	itr1=start-1;
	itr2=end-1;
	while(itr1<=itr2){
		insertLast(src,arr[itr1]);
		itr1++;
	}
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
