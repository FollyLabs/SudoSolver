void start_push(int pi, int pj,int val)
{
int pk,pm,pn,pr,pc;
for(pk=0;pk<9;pk++)
{
	num[pk].matrix[pi][pj]=0;
}

for(pk=0;pk<9;pk++)
{
	num[val-1].matrix[pi][pk]=0;
	num[val-1].matrix[pk][pj]=0;
}

pc=pi-(pi%3);
pr=pj-(pj%3);
for(pm=pc;pm<=(pc+2);pm++)
{
	for(pn=pr;pn<=(pr+2);pn++)
	{
		num[val-1].matrix[pm][pn]=0;
	}
}
}	// end of function


void insert(int hi,int hj, int val)
{
int hk,hm,hn,hc,hr;

// for logic 2
	for(hk=0;hk<9;hk++)
	{
		num[hk].matrix[hi][hj]=0;
	}
	for(hk=0;hk<9;hk++)
	{		// for column
		num[val-1].matrix[hk][hj]=0;
		num[val-1].matrix[hi][hk]=0;
	}
		
	c=hi-(hi%3);			
	r=hj-(hj%3);
	for(m=c;m<=c+2;m++){
	for(n=r;n<=r+2;n++){
		num[val-1].matrix[m][n]=0;}}
// end of logic2

list[hi][hj].value=val;
list[hi][hj].size=1;
list[hi][hj].done=1;


for(hk=0;hk<9;hk++)
{
	if(list[hi][hk].size!=1)
	{
		if(list[hi][hk].prob[list[hi][hj].value-1]!=-1)
		{
			list[hi][hk].prob[list[hi][hj].value-1]=-1;
			list[hi][hk].size=(list[hi][hk].size)-1;
		}
	}

	if(list[hk][hj].size!=1)
	{
		if(list[hk][hj].prob[list[hi][hj].value-1]!=-1)
		{
			list[hk][hj].prob[list[hi][hj].value-1]=-1;
			list[hk][hj].size=(list[hk][hj].size)-1;
		}
	}
}

hc=hi-(hi%3);
hr=hj-(hj%3);

for(hm=hc;hm<=(hc+2);hm++)
{
	for(hn=hr;hn<=(hr+2);hn++)
	{
		if(list[hm][hn].size!=1)
		{
			if(list[hm][hn].prob[list[hi][hj].value-1]!=-1)
			{
				list[hm][hn].prob[list[hi][hj].value-1]=-1;
				list[hm][hn].size=(list[hm][hn].size)-1;
			}
		}
	}
}
	


} // end of function
