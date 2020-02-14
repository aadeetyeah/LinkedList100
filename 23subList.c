#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
int length(struct node*);

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

}
int detectSubList(struct node **src,struct node **dest){
	struct node *s=*src;
	struct node *d=*dest;
	int pos;
	int itr1=1;
	int cnt=0;
	int it;
	struct node *d1=NULL;
	int len=length(s);
	while(d!=NULL){
		d1=d;
		it=itr1;
		while(s!=NULL){
			if(s->data==d1->data){
				cnt++;
				pos=it;
				s=s->next;
				d1=d1->next;
				it++;
			}else{
				break;
			}
		}
		d=d->next;
		itr1++;
	}
		printf("len:%d\ncnt:%d\n",len,cnt);
	if(len==cnt){
		printf("len:%d\ncnt:%d\n",len,cnt);
		return pos-cnt;
	}
}
int length(struct node *head){
	struct node *temp=head;
	int len=1;
	if(head==NULL){
		return 0;
	}
	while(temp->next!=NULL){
		temp=temp->next;
		len++;
	}
	return len;
}
int main(){
	struct node *src=NULL;
	struct node *dest=NULL;
	int s,d;
	printf("Enter no. of src nodes to be created.\n");
	scanf("%d",&s);
	for(int itr1=0;itr1<s;itr1++){
		createNode(&src);
	}
	printf("Enter no. of dest nodes to be created.\n");
	scanf("%d",&d);
	for(int itr1=0;itr1<d;itr1++){
		createNode(&dest);
	}
	int pos=detectSubList(&src,&dest);
	printf("Pos:%d\n",pos);
	return 0;
}
