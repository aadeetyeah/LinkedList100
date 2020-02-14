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
int searchLastOcc(struct node**,struct node**,int);
int secondLastOcc(struct node**,struct node**,int);
int searchAllOcc(struct node**,struct node**,int);
int concatList(struct node**,struct node**,struct node**,struct node**);
struct node* findTail(struct node**);
int concatListN(struct node**,struct node**,struct node**,struct node**,int);
int listReverse(struct node** head,struct node**);
int listPalindrome(struct node** head,struct node** tail);
int listSortDesc(struct node**,struct node**);
int ListCmp(struct node**,struct node**,struct node**,struct node**);
int listNCmp(struct node**,struct node**,struct node**,struct node**,int);

int main(){
	int data,num,res;
	struct node *head1=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL;
	printf("src linked list.\n");
	createNode(&head1);
	display(&head1);
	tail1=findTail(&head1);
	printf("dest linked list.\n");
	createNode(&head2);
	display(&head2);
	tail2=findTail(&head2);

	listNCmp(&head1,&tail1,&head2,&tail2,4);
	//display(&head1);	
	return 0;
}

int listNCmp(struct node** srcHead,struct node** srcTail,struct node** destHead,struct node** destTail,int N){
	struct node *temp1=*srcHead,*temp2=*destHead;
	int l1,l2,cnt=0;
	l1=length(srcHead);
	l2=length(destHead);
	if(l1<N || l2<N){
		printf("Value of N is greater than lists' length.\n");
		exit(1);
	}else{
	while(cnt<N){
		if(temp1->data!=temp2->data){
			printf("Lists are unequal.\n");
			exit(1);
		}
		cnt++;
		temp1=temp1->next;
		temp2=temp2->next;
	}
		printf("Lists are equal till node %d.\n",N);
	}
	
}
int ListCmp(struct node** srcHead,struct node** srcTail,struct node** destHead,struct node** destTail){
	struct node *temp1=*srcHead,*temp2=*destHead;
	int l1,l2;
	l1=length(srcHead);
	l2=length(destHead);
	if(l1!=l2){
		printf("Lists are not equal in lengths.\n");
	}else{
		while(temp1->next!=*srcHead && temp2->next!=*destHead){
			if(temp1->data!=temp2->data){
				printf("Linked lists are not equal.\n");
				return -1;
			}
			temp1=temp1->next;
			temp2=temp2->next;
		}
		if(temp1->data!=temp2->data){
			printf("Linked lists are not equal.\n");
			return -1;

		}else{
			printf("Both lists are equal.\n");
			return 0;
		}
	}
}	

int listSortDesc(struct node** head,struct node** tail){
	struct node *temp,*temp2;
	temp=*head;
	temp2=*head;
	int tempD;
	while(temp2->next!=*head){
		temp=*head;
		while(temp->next!=*head){
			if(temp->data<temp->next->data){
				tempD=temp->data;
				temp->data=temp->next->data;
				temp->next->data=tempD;	
			}
			temp=temp->next;
		}
		temp2=temp2->next;	
	}
}

int listPalindrome(struct node** head,struct node** tail){
	struct node *temp=*head;
	int len=length(head);
	int itr1,itr2;
	int arr[len];
	for(itr1=0;itr1<len;itr1++){
		arr[itr1]=temp->data;
		temp=temp->next;
	}
	itr1=len-1;
	itr2=0;
	while(itr2!=itr1){
		if(arr[itr2]!=arr[itr1]){
			return -1;
		}else{
			return 0;
		}
		itr2++;
		itr1--;
	}
}

int listReverse(struct node** head,struct node** tail){
	struct node *temp,*prev,*cur,*next;
	if(*head==NULL){
		printf("\nNo linked list present.\n");
		return 0;
	}else{
		temp=*head;
		prev=*tail;
		cur=*head;
		next=(*head)->next;
		while(temp->next!=*head){
			temp=temp->next;
			cur->next=prev;
			prev=cur;
			cur=next;
			next=temp->next;
		}	
		cur->next=prev;
		prev=cur;
		*head=cur;
	}
}

int concatListN(struct node** srcHead,struct node** srcTail,struct node** destHead,struct node** destTail,int N){
	int len=0,cnt=1;
	struct node *temp=NULL;
	if(*srcHead==NULL){
		printf("src list empty.\n");
		return 0;
	}else{	
		len=length(srcHead);
		if(N>len){
			printf("Number of elements to concat are greater than src-list's length\n");
			exit(1);
		}else{
			if(*destHead==NULL && *destTail==NULL){
				*destHead=*srcHead;
				temp=*destHead;
			}else{
				(*destTail)->next=*srcHead;			
				temp=(*destTail)->next;
			}
			while(cnt!=N){
				temp=temp->next;
				cnt++;
			}
			temp->next=*destHead;	
		}
	}
}

int concatList(struct node** srcHead,struct node** srcTail,struct node** destHead,struct node** destTail){
	if(*srcHead==NULL || *destHead==NULL){
		printf("One or both the Lists are empty.\n");
		exit(1);
	}else{
		(*srcTail)->next=*destHead;
		(*destTail)->next=*srcHead;
	}
	return 0;
}

struct node* findTail(struct node** head){
	struct node* temp=*head;
	if(*head==NULL){
		printf("Linked List not present.\n");
		return NULL;
	}
	while(temp->next!=*head){
		temp=temp->next;
	}
	return temp;
}

int searchAllOcc(struct node** head,struct node** tail,int num){
	int cnt=0;
	struct node *temp=*head;
	if(*head==NULL){
		printf("No Nodes to display.\n");
		exit(1);
	}else{
		while(temp->next!=*head){
			if(temp->data==num){
				cnt++;
			}
			temp=temp->next;
		}
		if(temp->data==num){
			cnt++;
		}
		if(cnt==0){
			printf("%d is not present in linked list.\n",num);
			return -1;
		}
		return cnt;
	}

}	

int secondLastOcc(struct node** head,struct node** tail,int num){
	struct node *temp=*head;
	int pos=1,num1=0,secondL=0;
	if(*head==NULL){
		printf("No Nodes to display.\n");
		exit(1);
	}else{
		while(temp->next!=*head){
			if(temp->data==num){
				secondL=num1;
				num1=pos;
			}
			temp=temp->next;
			pos++;
		}
		if(temp->data==num){
			secondL=num1;
			num1=pos;
		}
		if(*head==*tail || secondL==0){
			printf("there is no second last element.\n");
			exit(1);
		}/*else if(secondL==0){
		   printf("%d is not present in linked list.\n",num);
		   return -1;
		   }*/
		return secondL;
	}

}

int searchLastOcc(struct node** head,struct node** tail,int num){
	struct node *temp=*head;
	int pos=1,num1=0;
	if(*head==NULL){
		printf("No Nodes to display.\n");
		exit(1);
	}else{
		while(temp->next!=*head){
			if(temp->data==num){
				num1=pos;
			}
			temp=temp->next;
			pos++;
		}
		if(temp->data==num){
			num1=pos;
		}
		if(num1==0){
			printf("%d is not present in linked list.\n",num);
			return -1;
		}
		return num1;
	}
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
