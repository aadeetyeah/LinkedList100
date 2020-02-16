#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* prev;
	int data;
	struct node* next;	
};

int insertFirst(struct node**,int);
struct node* newNode(int);
void display(struct node**);
int insertLast(struct node**,int);
int insertAtPos(struct node**,int,int);
int deleteFirst(struct node **);
int deleteLast(struct node **);
int deleteAtPos(struct node**,int);
int searchFirstOcc(struct node** Head,int no);
int searchLastOcc(struct node**,int);
int searchSecondLastOcc(struct node**,int no);
int searchAllOcc(struct node**,int no);

int main(){
	struct node* head=NULL;
	int itr1=0,num,no,num2;
	printf("How many nodes to be created.\n");
	scanf("%d",&num);

	for(itr1=0;itr1<num;itr1++){
		printf("Element no. %d :",itr1+1);
		scanf("%d",&no);
		insertLast(&head,no);
	}
	display(&head);
	printf("Enter digit to be searched.\n");
	scanf("%d",&num2);
	searchAllOcc(&head,num2);	
	return 0;
}

int searchAllOcc(struct node** Head,int no){
	int cnt=0;
	struct node *temp=*Head;
	if(*Head==NULL){
		printf("List does not exist.\n");
		return -1;
	}
	while(temp!=NULL){
		if(temp->data==no){
			cnt++;
		}
		temp=temp->next;
	}
	if(cnt==0){
		printf("Element does not exists.\n");
		return -1;
	}else{
		printf("Output: %d\n",cnt);
		return 0;
	}
}

int searchSecondLastOcc(struct node** Head,int no){
	int pos2=0,pos3=0;
	int pos=1;
	struct node *temp=*Head;
	if(*Head==NULL){
		printf("List does not exist.\n");
		return -1;
	}
	while(temp!=NULL){
		if(temp->data==no){
			pos3=pos2;
			pos2=pos;
		}
		temp=temp->next;
		pos++;
	}
	if(pos3==0){
		printf("Element %d does not exists at second last pos.\n",no);
		return -1;
	}else{
		printf("Output: %d\n",pos3);
		return 0;
	}
	
}

int searchLastOcc(struct node** Head,int no){
	int pos2=0;
	int pos=1;
	struct node *temp=*Head;
	if(*Head==NULL){
		printf("List does not exist.\n");
		return -1;
	}
	while(temp!=NULL){
		if(temp->data==no){
			pos2=pos;
		}
		temp=temp->next;
		pos++;
	}
	if(pos2==0){
		printf("Element %d does not exists.\n",no);
		return -1;
	}else{
		printf("Output: %d\n",pos2);
		return 0;
	}

}

int searchFirstOcc(struct node** Head,int no){
	struct node * temp=*Head;
	int pos=1;
	if(*Head==NULL){
		printf("List does not exist.\n");
		return -1;
	}
	printf("Output: ");
	while(temp!=NULL){
		if(temp->data==no){
			printf("%d\n",pos);
			return 0;
		}
		temp=temp->next;
		pos++;
	}
	printf("Element does not exists.\n");
}

int deleteAtPos(struct node ** Head,int pos){
	struct node * temp=*Head;
	if(*Head==NULL){
		printf("List does not exist.\n");
		return -1;
	}
	if(pos==1){
		deleteFirst(Head);
		return 0;
	}else{
		while(pos>1){
			temp=temp->next;
			pos--;
		}
		temp->prev->next=temp->next;
		if(temp->next!=NULL){
			temp->next->prev=temp->prev;
		}
		free(temp);
		temp=NULL;
	}
	//printf("%d",(*Head)->data);
	return 0;
}

int deleteLast(struct node** Head){
	struct node* temp=*Head;
	if(*Head==NULL){
		printf("List does not exist.\n");
		return -1;
	}	
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->prev->next=NULL;
	temp->prev=NULL;
	free(temp);
	temp=NULL;
	return 0;
}

int deleteFirst(struct node** Head){
	struct node* temp=*Head;
	if(*Head==NULL){
		printf("Nothing to delete.\n");
		return -1;
	}
	*Head=(*Head)->next;
	(*Head)->prev=NULL;
	free(temp);
	temp=NULL;
	return 0;
}

int insertAtPos(struct node** Head,int no,int pos){
	struct node * temp=*Head;
	struct node * tNew=NULL;
	if(*Head==NULL){
		printf("List is empty.\n");
		return -1;
	}
	if(pos==1){
		insertFirst(Head,no);
	}else{
		while(pos-1>1){
			temp=temp->next;
			pos--;
		}
		tNew=newNode(no);
		tNew->next=temp->next;
		tNew->prev=temp;
		tNew->next->prev=tNew;
		temp->next=tNew;
	}

}

int insertLast(struct node** Head,int no){
	struct node *temp=*Head;
	if(*Head==NULL){
		temp=newNode(no);
		*Head=temp;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode(no);
		temp->next->prev=temp;
	}
}
int insertFirst(struct node** Head,int no){
	struct node* temp=NULL;
	if(*Head==NULL){
		temp=newNode(no);
		*Head=temp;
	}else{
		temp=newNode(no);
		temp->prev=NULL;
		temp->next=*Head;
		temp->next->prev=temp;
		*Head=temp;		
	}
}

struct node* newNode(int no){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Was not able to allocate memory.\n");
		return 0;
	}
	temp->prev=NULL;
	temp->next=NULL;
	temp->data=no;
	return temp;
}

void display(struct node** Head){
	struct node *temp=*Head;
	if(*Head==NULL){
		printf("Nothing to display.\n");
		return;
	}else{
		while(temp->next!=NULL){
			printf("|%d|<=>",temp->data);
			temp=temp->next;
		}
		printf("|%d|\n",temp->data);
	}
}
