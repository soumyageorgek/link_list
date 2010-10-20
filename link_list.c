#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *new_node(int data)
{
	struct node *n;

	n = malloc(sizeof(struct node));
	n->data = data;
	n->next = 0;
}
struct node *append(struct node *n, struct node *l)
{
	struct node *t;

	if(l == 0)
		return n;
	t = l;
	while(t->next != 0)
		t = t->next;
	t->next = n;	
	return l;
}
void print_list(struct node *l)
{	
	if(l == 0)
		printf("There is no list created\n");
	while(l != 0){
		printf("%d->",l->data);
		l = l->next;
	}
	printf("\n");
}
struct node *reverse(struct node *l)
{
	struct node *p;
	struct node *q;
	struct node *r;
	int y = 0;

	p = l;
	if(p->next == 0)
		return p;
	q = p->next;
	if(q->next == 0){
		q->next = p;
		p->next = 0;
		return q;
	}else{
		r = q->next;
		while(r->next != 0 || y == 0){
			r = q->next;
			q->next = p;
			p = q;
			q = r;
			y = 1;
		}
		r->next = p;
	}
	l->next = 0;
	return r;		
}
struct node *rec_reverse(struct node *l)
{
	struct node *temph;
	struct node *temp;

	if(l==0)
		printf("There is no such a list\n");
	if(l->next==0){
		return l;
	}
	temph=rec_reverse(l->next);
	temp=temph;
	while(temp->next!=0)
		temp=temp->next;
	temp->next=l;
	l->next=0;
	return temph;		
}	
main()
{
	int choice,data,y;
	struct node *l;	
	struct node *l2;

	l=0;
	do{
	printf("1.insert\n2.print\n3.reverse\n4.rec_reverse\n");
	scanf("%d",&choice);
	switch(choice){
	case 1:
		scanf("%d",&data);
		l=append(new_node(data),l);
		break;
	case 2:
		print_list(l);
		break;
	case 3:
		l=reverse(l);
		print_list(l);
		break;
	case 4:
		l=rec_reverse(l);
		print_list(l);
		break;
	}
	scanf("%d",&y);
	}while(y==1);
}
