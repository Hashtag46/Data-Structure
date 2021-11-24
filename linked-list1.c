#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start,*end,*temp,*p,*r;
char ch;
int c;

void insert();
void deleten();
void display();
void revdisplay();


int main()
{
	int c;
	start=NULL;
	end=NULL;
	while(1)
	{
		printf("\n\nLINKED LIST MENU\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.REVERSED DISPLAY\n5.EXIT\n");
		printf("Please select the option:");
		scanf("%d",&c);

		switch(c)
		{
		case 1: insert();
				break;
		case 2: deleten();
				break;
		case 3: display();
				break;
		case 4: revdisplay();
				break;
		case 5: exit(0);
				break;
		default:
				printf("Wrong Choice");
		}
	}
	return 0;
}


void insert()
{
	//insert at last 
	/*	temp=(struct node *)malloc(sizeof(struct node));
		int pos,e,n;
		e=1;
		p=start;
		printf("enter the number you want to insert:");
		scanf("%d",&n);
		temp->data=n;

		if(start==NULL)
		{
				temp->link=NULL;
				start=temp;
				end=temp;
		}
		else
		{
				while(p->link!=NULL)
				{p=p->link;}
				p->link=temp;
				temp->link=NULL;
				end=temp;
		}
		printf("insertion successful\n");
		*/
	
	
	//insert at any position
	int n;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter the number you want to insert:");
	scanf("%d",&n);
	temp->data=n;

	if(start==NULL) // empty linked list
	{
		temp->link=NULL;
		start=temp;
		end=temp;
	}
	else
	{
		int d,e=1;
		p=start;

		while(p->link!=NULL)
		{
			e++;
			p=p->link;
		}
		printf("enter the position at which you want to insert:");
		scanf("%d",&d);
		if(d>e+1)
		{
			printf("plz enter a valid node\n");
			return;
		}
		else if(d==1)
		{
			temp->link=start;
			start=temp;
		}
		else if(d==e+1)
		{
			temp->link= NULL;
			end->link=temp;
			end=temp;
		}
		else
		{
			p=start;
			for(int i=1; i<d; i++)
			{
				r=p;
				p=p->link; // p contains the address location of the node to be inserted
			}   ///output of p is the position at which node is being inserted
			temp->link=p;
			r->link=temp;
		}
		printf("insertion successful\n");
	}

}

void deleten()
{
	if(start==NULL)
		printf("\n sorry the list is empty\n");
	else
	{
		int d,e=1;
		p=start;

		while(p->link!=NULL)
		{
			e++;
			p=p->link;
		}
		printf("enter the node number you want to delete:\n");
		scanf("%d",&d);
		if(d>e)
		{
			printf("plz enter a valid node\n");
			return;
		}

		else if(d==1)
		{
			printf("deleted node is:%d",start->data);
			temp=start;
			start=start->link;
			free(temp);
		}
		else
		{
			p=start;
			for(int i=1; i<d; i++)
			{
				r=p;
				p=p->link;
			}
			temp=p;
			r->link=p->link;
			if(p->link==NULL)
				end = r;
			printf("deleted node is:%d",temp->data);
			free(temp);
		}
	}
}

void display()
{
	if(start==NULL)
		printf("\n sorry the list is empty\n");
	else if(start==end)
		printf("%d",start->data);
	else
	{
		p=start;
		while(p->link!=NULL)
		{
			printf("%d\t",p->data);
			p=p->link;
		}
		printf("%d",end->data);
	}
}

void revdisplay()
{
	int e=1;
	if(start==NULL)
		printf("\n sorry the list is empty\n");
	else if(start==end)
		printf("%d",start->data);
	else
	{

		p=start;
		while(p->link!=NULL)
		{
			e++;
			p=p->link;
		}                                     //e gives the total number of nodes
		int arr[e];
		p=start;
		int q;
		for(int i=0; i<e; i++)
		{
			arr[i]=p->data;
			p=p->link;
		}

		for(int i=e-1; i>=0; i--)
		{
			printf("%d", arr[i]);
			printf("  ");
		}

	}
}
