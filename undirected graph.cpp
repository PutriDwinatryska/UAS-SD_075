#include<stdio.h>
#include<stdlib.h>
int no_vertices;
struct node
{
	int data;
	struct node *next;
};
void readgraph(struct node *ad[]);
void printgraph(struct node *ad[]);
int main()
{
	//input total vertex yang akan diinput
	int i,j,k,ch,start;
	printf("Enter the total numbe of vertex :");
	scanf("%d",&no_vertices);
	int visited[no_vertices];
	struct node *adj[no_vertices];
	for(i=0;i<no_vertices;i++)
	{
		adj[i] = NULL;
	}
	readgraph(adj);

	do{ //pemilihan menu output data pilihan 1 print adjacency list dan 2 exit
		printf("\n Enter 1 for Print the adjacency list\nEnter 2 to Exit : ");
		scanf("%d",&ch);
		switch(ch)
		{ // program output
			case 1: printgraph(adj);break;

			case 2: break;
		}
	}while(ch!= 2);
	
	return 0;
}// rumusan output edge 
void readgraph(struct node *ad[])
{
	struct node *newnode; 
	int i,j,k,data;

	for(i=0;i<no_vertices;i++) 
	{// input jumlah vertex yang berhubungan contohnya 1 berhubungan dengan 2 vertex yaitu 5 dan 4
		struct node *last =NULL;
		printf("\nEnter the Number of neighbours of %d  :",i);
		scanf("%d",&k);

		for(j=0;j<k;j++)
		{// input data yang berhubungan dengan vertex contohnya 1 berhubungan dengan angkan 5 dan 4 
			printf("Enter the value of %d neighbour of %d : ",j,i);
			scanf("%d",&data);
// perumusan data yang iinput
			newnode = (struct node*)malloc(sizeof(struct node*));
			newnode->data = data;
			newnode->next = NULL;
			if(ad[i]==NULL)
			{
				ad[i] = newnode;
			}
			else
				last->next = newnode;

			last = newnode;
		}
	}
} //output data
void printgraph(struct node *ad[])
{
	struct node *ptr  = NULL;
	int i,j;
	for(i=0;i<no_vertices;i++)
	{
		ptr = ad[i]; // output data angka yang telah diinput akan digolongkan per vertex contohnya pada vertex 1 ada 2 4 3 dan berlanjut sampai vertex twrakhir
		printf("\n The neighbour of %d are :",i);
		while(ptr != NULL)
		{
			printf("%d\t",ptr->data); 
			ptr = ptr->next;
		}
	}
}


