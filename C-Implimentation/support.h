#define row 9
#define col 9
struct info{
	int value;	int done;	int size;	int prob[9];
};

struct item{
int matrix[10][10];	int done;
};
void insert(int ,int , int );
void start_push(int , int , int );
int status();
	int c,r,m,n,t,c1,r1;
	int inp[row][col];
	struct info list[row][col];
	struct item num[9];

void intilization()	{
	int i,j,k;
	for(i=0;i<row;i++)	{
	for(j=0;j<col;j++)	{
		list[i][j].value=-1;	list[i][j].size=9;
		list[i][j].done=0;
		for(k=0;k<9;k++)
			list[i][j].prob[k]=k+1;	}	}

	for(i=0;i<9;i++)	{
		for(j=0;j<9;j++)	{
			for(k=0;k<9;k++)	{
		num[i].matrix[j][k]=1;	}	}	}
}	// end of intilization

void input()
{
	int i,j,k;
	for(i=0;i<row;i++)
	{
	for(j=0;j<col;j++)
	{
		scanf("%d ",&inp[i][j]);
		if(inp[i][j]!=-1)
		{
			insert(i,j,inp[i][j]);
			start_push(i,j,inp[i][j]);
		}
	}
	}
}	// end of input function

void display()
{
	int i,j,k;
	for(i=0;i<row;i++)
	{
		if(i%3==0)
			printf("\n");
		for(j=0;j<col;j++)
		{
			if(j%3==0)
				printf("\t");
			printf("%d ",list[i][j].value);
		}
		printf("\n");
	}
}	// end of display function

int status()
{
int st=1,i,j;
	for(i=0;i<9;i++)
	{
	for(j=0;j<9;j++)
	{
		if(list[i][j].value==-1)
		{	
		st=0;
		break;
		}
	}
	}
return st;
}

