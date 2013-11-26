#include<stdio.h>
#include "support.h"
#include "head.h"

void logic1()
{
int count,flag,i,j,k,lgn,lgm;
int tempr,tempc;

flag=1;
while(flag==1)
{
flag=0; //for terminate

// (a) check for row
for( i=0;i<9;i++)
{
	for(j=0;j<9;j++)
	{
		count=0;
		for(k=0;k<9;k++)
		{
		if(num[i].matrix[j][k]==1)
		{
			count++;
			tempr=j;tempc=k;
		}
		if(count==2)
			break;
		}
		if(count==1)
		{
			flag=1;
			insert(tempr,tempc,i+1);	
		}// end of if	
	}// end of loop
}// end of loop

// for column
for( i=0;i<9;i++)	{
	for(j=0;j<9;j++)	{
		count=0;
		for(k=0;k<9;k++)
		{
		if(num[i].matrix[k][j]==1)
		{
			count++;
			tempr=k;tempc=j;
		}
		if(count==2)
			break;
		}
		if(count==1)
		{
			flag=1;
			insert(tempr,tempc,i+1);
		}// end of if	
	}// end of loop
}// end of loop

// for box

for(i=0;i<9;i++)
{
for(j=0;j<9;j=j+3)
{
for(k=0;k<9;k=k+3)
{
	count=0;
	for(m=j;m<=(j+2);m++)
	{
	for(n=k;n<=(k+2);n++)
	{
		if(num[i].matrix[m][n]==1)
		{
			count++;
			tempr=m;tempc=n;
		}
		if(count==2)
			break;
	}
	}
	
	if(count==1)
	{
		flag=1;
		insert(tempr,tempc,i+1);
	}// end of if	

	}
	}
	}
// end of box

} // end of flag-while
} // end of logic1


int logic2()
{
int i,j,k,flag=1,more=0;
while(flag==1)
{
	flag=0;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if((list[i][j].size==1)&&(list[i][j].done==0))
			{
			flag=1;
			for(k=0;k<9;k++)
				if(list[i][j].prob[k]!=-1)
					break;
			insert(i,j,list[i][j].prob[k]);		
			more=1;
			}
		}
	}
}// end of while loop
return more;
}// end of confine function

int main()
{
int chek;
//step1 intialization
	intilization();
//step2 input from user
	input();
//step4 confine the result

do{
	logic1(); 
	chek=logic2(); // if flop+update (do again) else 
		// flop-update (exit) if not flop (exit)
}while((status()!=1)&&(chek==1));

//step5 display result
printf("\n\nSudoku Solution is \n");
	display();

return 0;
}
