#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void display(struct node**);
void createNode(struct node**);
void reverse(struct node**);
int count(struct node**);
void LLcopyLastnEl(struct node**,struct node**);
int subList(struct node**,struct node**);

int main(){
	struct node *head=NULL;
	struct node *dest=NULL;
	int itr1,num,from;
	printf("Enter no. of nodes to be created.\n");
	scanf("%d",&num);
	for(itr1=0;itr1<num;itr1++){
		createNode(&head);	
	}
	printf("Input src Linked List: ");
	display(&head);
	printf("Enter no. of nodes to be created.\n");
	scanf("%d",&num);
	for(itr1=0;itr1<num;itr1++){
		createNode(&dest);	
	}
	printf("\ndestination Linked List: ");
	display(&dest);
	int pos=lastSubList(&head,&dest);
	printf("Pos: %d\n",pos);
	return 0;
}

int lastSubList(struct node** src,struct node** dest){
	struct node* temp1=*src,*bckupT2=NULL;
	struct node* temp2=*dest;
	int pos=0,cnt=1,cnt2=0,lenS;
	if(*src==NULL || *dest==NULL){
		printf("src or dest list is empty.\n");
		return -1;
	}else{
		lenS=count(src);	//count of sublist
		while(temp2!=NULL){	//running dest till last node
			if(temp1->data==temp2->data){	//if first element of both lists are equal then if condtn executes
				pos=cnt;	//save the first pos where first elements are equal
				bckupT2=temp2;	//save dest location before complete comparison with src list
				cnt2=0;		//src list counter to compare with its original length
				while(temp1!=NULL){	//src list compare with dest list from 1st equal location
					if(temp1->data==temp2->data){
						cnt2++;			//if elements equal increment to compare with leng
					}
					temp1=temp1->next;
					temp2=temp2->next;
				}
				if(lenS==cnt2){		//if length and equal counter are equal return saved pos of 1st node					
					
				}
				temp1=*src;	//if not equal again src will be at starting location
				temp2=bckupT2;	//saved dest location again assigned back to dest for further comparisons
			}
			cnt++;	//position counter	
			temp2=temp2->next;
		}
		return pos;
	}
}

int count(struct node **head){
	struct node *temp=*head;
	int cnt=1;
	if(*head==NULL){
		return 0;
	}
	while(temp->next!=NULL){
		temp=temp->next;
		cnt++;
	}
	return cnt;
}
void LLcopyLastnEl(struct node **head,struct node **dest){
	struct node *htemp=*head;
	int itr1,itr2;
	int cnt=count(head);
	int arr[cnt];
	for(itr1=0;itr1<cnt;itr1++){
		arr[itr1]=htemp->data;
		htemp=htemp->next;
	}
	int no,sum,no1,prime=0;
	struct node *dtemp=*dest;
	struct node *newNode=NULL;
	for(itr1=0;itr1<cnt;itr1++){
		no=arr[itr1];
		sum=0;
		prime=0;
		while(no>0){
			no1=no%10;
			sum=sum+no1;
			no=no/10;
		}
		for(itr2=1;itr2<=sum/2;itr2++){
			if(sum%itr2==0){
				prime++;
			}	
		}
		if(prime==1){
			dtemp=*dest;
			newNode=(struct node*)malloc(sizeof(struct node));
			newNode->data=arr[itr1];
			newNode->next=NULL;
			if(*dest==NULL){
				*dest=newNode;
			}else{
				while(dtemp->next!=NULL){
					dtemp=dtemp->next;
				}
				dtemp->next=newNode;
			}
		}
	}
}
void createNode(struct node **head){
	struct node *temp=*head;
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
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
void display(struct node **head){
	struct node *temp=*head;
	while(temp->next!=NULL){
		printf("|%d|->",temp->data);
		temp=temp->next;
	}
	printf("|%d|",temp->data);
}
void reverse(struct node **head){
	struct node *first=*head;
	struct node *next1=*head;
	struct node *temp=NULL;
	while(first->next!=NULL){
		next1=first->next;
		first->next=temp;
		temp=first;
		first=next1;
	}
	first->next=temp;
	*head=first;	
}

