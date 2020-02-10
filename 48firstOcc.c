#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* newNode(int no);
int insertLast(struct node **head,int);
int createNode(struct node **);
void display(struct node**);
int insertFirst(struct node **head,struct node **tail,int);
int insertAtPos(struct node**,struct node**,int no,int pos);
int deleteFirst(struct node**,struct node**);
int deleteLast(struct node**,struct node**);
int deleteAtPos(struct node**,struct node**,int);
int length(struct node**);
int searchFirstOcc(struct node**,struct node**,int);

int main(){
	int data;
	struct node *head=NULL;
	createNode(&head);
	display(&head);	
	struct node *tail=head;
	while(tail->next!=head){
		tail=tail->next;
	}
	int num;
	printf("\nInsert  number to be searched\n");
	scanf("%d",&num);
	int pos=searchFirstOcc(&head,&tail,num);
	printf("Output: %d\n",pos);
	//deleteAtPos(&head,&tail,pos);
	//deleteLast(&head,&tail);
//	display(&head);	
	return 0;
}

int searchFirstOcc(struct node** head,struct node** tail,int num){
	struct node *temp=*head;
	int pos=1;
	if(*head==NULL){
		printf("No Nodes to display.\n");
		exit(1);
	}else{
		while(temp->next!=*head){
			if(temp->data==num){
				return pos;
			}
			temp=temp->next;
			pos++;
		}
		if(temp->data==num){
			return pos;
		}else{
			printf("%d is not present in linked list.\n",num);
			return -1;
		}
	}
}

int deleteAtPos(struct node** head,struct node** tail,int pos){
	int len=0,cnt=1;
	struct node *temp=*head;
	struct node *prevDel=*head;
	struct node* delPos=*head;
	if(*head==NULL){
		printf("Nothing to print.\n");
		exit(1);
	}else{
		len=length(head);
		if(pos>len){
			printf("Position is greater than length\n");
			exit(1);
		}else if(pos==len){
			deleteLast(head,tail);
		}else if(pos==1){
			deleteFirst(head,tail);
		}else{
			while(cnt<pos && temp->next!=*head){
				prevDel=temp;
				temp=temp->next;
				cnt++;
				delPos=temp;
			}
			prevDel->next=delPos->next;
			delPos->next=NULL;
			free(delPos);
			delPos=NULL;
		}
		return 0;
	}
}
int length(struct node **head){
	int len=0;
	struct node *temp=*head;
	if(*head==NULL){
		return 0;
	}else{
		len=1;
		while(temp->next!=*head){
			temp=temp->next;
			len++;
		}
		return len;
	}
}

int deleteLast(struct node** head,struct node** tail){
	struct node* delL=NULL;
	struct node* sLast=*head;
	if(*head==NULL){
		printf("Nothing to display.\n");
		exit(1);
	}else if(*tail==*head){
		delL=*head;
		*head=NULL;
		*tail=NULL;
		delL->next=NULL;
		free(delL);
		delL=NULL;
	}else{
		while(sLast->next!=*tail){
			sLast=sLast->next;
		}
		delL=*tail;
		sLast->next=*head;
		*tail=sLast;
		delL->next=NULL;
		free(delL);
		delL=NULL;
	}
	return 0;
}

int deleteFirst(struct node** head,struct node** tail){
	struct node* tempH=*head;
	struct node* delF=NULL;
	if(*head==NULL){
		printf("Nothing to delete.\n");
		exit(1);
	}else{
		delF=*head;
		*head=tempH->next;
		delF->next=NULL;
		(*tail)->next=*head;
		free(delF);
		delF=NULL;
		return 0;
	}
}
int insertAtPos(struct node **head,struct node **tail,int no,int pos){
	int cnt=1;
	struct node *temp=*head;
	struct node *newN=NULL;
	if(head==NULL){
		printf("No Linked list present.\n");
	}else{
		if(pos==1){
			insertFirst(head,tail,no);
			return 0;
		}
		while(temp->next!=*head && cnt<pos-1){
			temp=temp->next;
			cnt++;
		}
		newN=newNode(no);
		newN->next=temp->next;
		temp->next=newN;
	}
	return 0;
}
int insertFirst(struct node **head,struct node **tail,int no){
	struct node *temp=*head;
	struct node *newN=NULL;
	if(*head==NULL){
		newN=newNode(no);
		*head=newN;
		newN->next=*head;
	}else{
		newN=newNode(no);
		newN->next=*head;
		*head=newN;
		(*tail)->next= *head;
	}
	return 0;
}

int createNode(struct node **head){
	int itr1,data,num;
	printf("How many nodes to be created.\n");
	scanf("%d",&num);
	for(itr1=0;itr1<num;itr1++){
		printf("Enter element no. %d : ",itr1+1);
		scanf("%d",&data);
		insertLast(head,data);
	}
}

int insertLast(struct node **head,int no){
	struct node *temp=*head;
	struct node *newN=NULL;
	if(*head==NULL){
		newN=newNode(no);
		*head=newN;
		newN->next=*head;
	}else{
		while(temp->next!=*head){
			temp=temp->next;
		}
		newN=newNode(no);
		temp->next=newN;
		newN->next=*head;
	}
	return 0;
}

struct node* newNode(int no){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	if(new==NULL){
		printf("Memory allocation failed.\n");
		exit(1);
	}
	new->data=no;
	new->next=NULL;
	return new;
}

void display(struct node **head){
	struct node *temp=*head;
	printf("\n\nOUTPUT:\n");
	if(*head==NULL){
		printf("Nothing to display.\n");
	}else{
		//printf("\n\nOUTPUT:\n");
		while(temp->next!=*head){
			printf("|%d|->",temp->data);
			temp=temp->next;
		}
		printf("|%d|\n",temp->data);
	}
}
