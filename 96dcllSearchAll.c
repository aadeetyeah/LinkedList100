#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* prev;
	int data;
	struct node* next;
};

struct node* newNode(int no);
int insertFirst(struct node** src,struct node** tail,int no);
int insertLast(struct node** src,struct node** tail,int no);
int insertAtPos(struct node**,struct node**,int,int);
void display(struct node**);
struct node* findTail(struct node**);
int deleteFirst(struct node**,struct node**);
int deleteLast(struct node**,struct node**);
int deleteAtPos(struct node**,struct node**,int pos);
//int searchFirstOcc(struct node**,struct node**,int no);
int searchAllOcc(struct node**,struct node**,int no);

int main(){
	int itr1,num,data;
	struct node* head=NULL,*tail=NULL;
	printf("Insert number of nodes to be created.\n");
	scanf("%d",&num);
	for(itr1=0;itr1<num;itr1++){
		printf("Enter element %d: ",itr1+1);
		scanf("%d",&data);
		insertLast(&head,&tail,data);
	}
	display(&head);
	tail=findTail(&head);
	printf("Enter no. to be searched.\n");
	scanf("%d",&num);
	int pos=searchAllOcc(&head,&tail,num);
	printf("Output: %d\n",pos);
	return 0;
}

int searchAllOcc(struct node** Head,struct node** Tail,int no){
	struct node *temp=*Head;
	int cnt=0;
	if(*Head==NULL){
		printf("List is empty.\n");
		return -1;
	}
	while(temp->next!=*Head){
		if(temp->data==no){
			cnt++;
		}
		temp=temp->next;
	}
	if(temp->data==no){
		cnt++;
	}
	if(cnt==0){
		return -1;
	}
	return cnt;
}

int deleteAtPos(struct node** Head,struct node** Tail,int pos){
	struct node* temp=*Head;
	if(*Head==NULL){
		printf("List is empty.\n");
		return -1;
	}
	if(pos==1){
		deleteFirst(Head,Tail);
		return 0;
	}else{
		while(pos>1){
			temp=temp->next;
			pos--;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
		temp=NULL;
		return 0;
	}
}

int deleteLast(struct node** Head,struct node** Tail){
	struct node* temp1=*Head;
	struct node* temp2=*Tail;
	if(*Head==NULL){
		printf("List is empty.\n");
		return -1;
	}
	if(*Head==*Tail){
		free(*Head);
		*Head=NULL;
	}	
	else{
		temp2->prev->next=temp2->next;
		temp2->next->prev=temp2->prev;
		temp2->next=temp2->prev=NULL;
		free(temp2);
		temp2=NULL;
	}
	return 0;
}

int deleteFirst(struct node** Head,struct node** Tail){
	struct node* temp1=NULL;
	if(*Head==NULL){
		printf("List is empty.\n");
		return -1;
	}
	if((*Head)->next==*Head){
		temp1=*Head;
		free(temp1);
		temp1=NULL;
		*Head=temp1;
	}else{
		temp1=*Head;
		temp1->next->prev=temp1->prev;
		temp1->prev->next=temp1->next;
		*Head=temp1->next;
		free(temp1);
		temp1=NULL;

	}
}

int insertAtPos(struct node** src,struct node** tail,int pos,int no){
	struct node* temp1=*src;
	struct node* temp2=NULL;
	if(*src==NULL){
		printf("list is empty.\n");
	}
	if(pos==1){
		insertFirst(src,tail,no);
	}else{


		while(pos>1){
			temp1=temp1->next;
			pos--;
		}
		temp2=newNode(no);
		temp2->next=temp1;
		temp2->prev=temp1->prev;
		temp1->prev=temp2;
		temp2->prev->next=temp2;

	}
}

int insertLast(struct node** src,struct node** tail,int no){
	struct node* temp1=*src;
	struct node* Ttemp=*tail;
	struct node* temp2;
	if(*src==NULL){
		temp2=newNode(no);
		temp2->next=temp2->prev=temp2;
		*src=temp2;
		*tail=temp2->prev;	
	}else{
		temp2=newNode(no);
		temp2->next=Ttemp->next;
		Ttemp->next=temp2;
		temp2->prev=Ttemp;
		(*src)->prev=temp2;
		*tail=temp2;
	}
}

int insertFirst(struct node** src,struct node** tail,int no){
	struct node* temp1=*src;
	struct node* temp2;
	if(*src==NULL){
		temp1=newNode(no);
		temp1->prev=temp1->next=temp1;
		*src=temp1;
		*tail=temp1->prev;
		return 0;
	}else{
		temp2=newNode(no);
		temp2->next=temp1;
		temp2->prev=temp1->prev;
		temp1->prev=temp2;
		temp2->prev->next=temp2;
		*src=temp2;
		*tail=temp2->prev;
	}
}

struct node* findTail(struct node** head){
	struct node* temp=*head;
	if(*head==NULL){
		printf("list is empty.\n");
		return NULL;
	}
	while(temp->next!=*head){
		temp=temp->next;
	}
	return temp;
}

void display(struct node** head){
	struct node* temp=*head;
	if(*head==NULL){
		printf("List is empty.\n");
		return;
	}
	printf("Output:\n");
	while(temp->next!=*head){
		printf("|%d|<=>",temp->data);
		temp=temp->next;
	}
	printf("|%d|\n",temp->data);
}

struct node* newNode(int no){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=no;
	new->next=new->prev=NULL;
	return new;
}

