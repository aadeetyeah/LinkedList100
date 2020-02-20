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
int concatList(struct node**,struct node**);
int concatFirstN(struct node**,struct node**,int);
int concatLastN(struct node**,struct node**,int);
int concatListRange(struct node**,struct node**,int,int);
int llCopy(struct node**,struct node**);
int llNCopy(struct node**,struct node**,int);
int llLastNCopy(struct node**,struct node**,int);
int llCopyRange(struct node**,struct node**,int,int);

int main(){
	struct node* head1=NULL,*head2=NULL;
	int itr1=0,num,no;
	printf("Linked list 1\n");
	printf("How many nodes to be created.\n");
	scanf("%d",&num);

	for(itr1=0;itr1<num;itr1++){
		printf("Element no. %d :",itr1+1);
		scanf("%d",&no);
		insertLast(&head1,no);
	}
	display(&head1);
	printf("Enter the range to be copied.\n");
	scanf("%d %d",&no,&num);
	printf("\nLinked list 2(copy of list-1)\n");
	llCopyRange(&head1,&head2,no,num);
	display(&head2);
	return 0;
}

int llCopyRange(struct node** src,struct node** dest,int start,int end){
	struct node *temp=*src;
	int cnt=1;
	if(*src==NULL){
		printf("No elements present to copy.\n");
		return -1;
	}
	while(cnt<=end){
		if(cnt>=start && cnt<=end){
			insertLast(dest,temp->data);
		}
		temp=temp->next;
		cnt++;
	}
	return 0;
}

int llLastNCopy(struct node** src,struct node** dest,int N){
	struct node *temp=*src;
	if(*src==NULL){
		printf("No elements present to copy.\n");
		return -1;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	while(N>0){
		insertFirst(dest,temp->data);
		temp=temp->prev;
		N--;
	}
	return 0;	
}

int llNCopy(struct node** src,struct node** dest,int N){
	struct node *temp=*src;
	if(*src==NULL){
		printf("No elements present to copy.\n");
		return -1;
	}
	while(N>0){
		insertLast(dest,temp->data);
		temp=temp->next;
		N--;
	}
	return 0;
}

int llCopy(struct node** src,struct node** dest){
	struct node  *temp=*src;
	if(*src==NULL){
		printf("Src list is empty.\n");
		return -1;
	}
	while(temp!=NULL){
		insertLast(dest,temp->data);
		temp=temp->next;
	}
	return 0;
}

int concatListRange(struct node ** src,struct node **dest,int start,int end){
	struct node* temp=*dest;
	struct node* tSrc=*src;
	int cnt=1;

	if(start>end || *src==NULL || *dest==NULL){
		printf("Start is greater than end. Enter correct values\n OR src/dest list is empty.\n");
		return -1;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	while(cnt<end){
		if(cnt==start){
			temp->next=tSrc;
			tSrc->prev=temp;
		}
		tSrc=tSrc->next;
		cnt++;
		if(cnt==end){
			tSrc->next=NULL;
		}
	}
}

int concatLastN(struct node** src,struct node **dest,int N){
	struct node *temp=*dest;
	struct node *temp2=*src;
	if(*src==NULL || *dest==NULL){
		printf("src/dest list is empty.\n");
		return -1;
	}
	while(temp2->next!=NULL || temp->next!=NULL){
		if(temp2->next!=NULL){
			temp2=temp2->next;
		}
		if(temp->next!=NULL){
			temp=temp->next;
		}
	}
	while(N-1>0){
		temp2=temp2->prev;
		N--;
	}
	temp->next=temp2;
	temp2->prev=temp;
}

int concatFirstN(struct node** src,struct node **dest,int N){
	struct node *temp=*dest;
	if(*src==NULL){
		printf("src list is empty.\n");
		return -1;
	}
	if(*dest==NULL){
		temp=*src;
		*dest=temp;	
		N=N-1;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=*src;
		(*src)->prev=temp;
	}
	while(N>0){
		temp=temp->next;
		N--;
	}
	temp->next=NULL;
	return 0;
}

int concatList(struct node** src,struct node **dest){
	struct node *temp=*dest;
	if(*dest==NULL){
		*dest=*src;
		return 0;
	}
	if(*src==NULL){
		return 0;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=*src;
	(*src)->prev=temp;
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
