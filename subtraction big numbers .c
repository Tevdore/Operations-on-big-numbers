#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char *subtraction (char *num1, char *num2)
{
char *result="";
int dot1=0,dot2=0,j=0,i=0,k=1,counter=0,forDot,length1,length2,length3,carry=0;
__int64 operand1,operand2,sub,turnToPositive;
char operand[2][18],sub_char[20],zeros[19]="";

	if(strchr(num1,'.')!=0)
	{
		while(num1[dot1]!='.')
		dot1++;
	}
	else if(strchr(num1,'.'==0))
		dot1=strlen(num1);
	
	if(strchr(num2,'.')!=0)
	{
		while(num2[dot2]!='.')
		dot2++;
	}
	else if(strchr(num2,'.'==0))
		dot2=strlen(num2);
i=strlen(num1)-dot1-1;
j=strlen(num2)-dot2-1;

	if(i>j)
	forDot=i;
	else if(i<=j)
	forDot=j;
	while(num1[dot1]=='.' || num2[dot2]=='.' || (num1[dot1]>='0' && num1[dot1]<='9') || (num2[dot2]>='0' && num2[dot2]<='9') )
	{
		if(num1[dot1+1]>='0' && num1[dot1+1]<='9')
		num1[dot1]=num1[dot1+1];
		else if(num1[dot1+1]<'0' || num1[dot1+1]>'9')
		num1[dot1]='0';
	dot1++;	
		if(num2[dot2+1]>='0' && num2[dot2+1]<='9')
		num2[dot2]=num2[dot2+1];
		else if (num2[dot2+1]<'0' || num2[dot2+1]>'9')
		num2[dot2]='0';
	dot2++;
	}
dot1--;
dot2--;

	if(strchr(num1,'.')!=0)
	num1[dot1-1]=0;	
	if(strchr(num2,'.')!=0)
	num2[dot2-1]=0;


	if(dot1>=dot2)
	result = (char *) malloc(dot1-3);

	if(dot1<dot2)
	result = (char *) malloc(dot2-3);

length1=dot1+1;
length2=dot2+1;
length3=strlen(result)+1;


	for(k=1; length1-17*(k-1)>0 || length2-17*(k-1)>0; k++)
	{
	memset(&operand,0,sizeof(operand));
	memset(&sub_char,0,sizeof(sub_char));
	memset(&zeros,0,sizeof(zeros));
		
		if(length1-17*(k-1)>=17)
		{
		memmove( &operand[0], num1+length1-17*k,17);
		operand1 = _atoi64(operand[0]);
		}

		else if(length1-17*(k-1)>=0 && length1-17*(k-1)<17)
		{
		memmove( &operand[0], num1,length1-17*(k-1));
		operand1 = _atoi64(operand[0]);
		}
		
		else if (length1-17*(k-1) < 0)
		operand1=0;

		
		if(length2-17*(k-1)>=17)
		{
		memmove( &operand[1], num2+length2-17*k,17);
		operand2 = _atoi64(operand[1]);
		}

		else if(length2-17*(k-1)>=0 && length2-17*(k-1)<17)
		{
		memmove( &operand[1], num2,length2-17*(k-1));
		operand2 = _atoi64(operand[1]);
		}	
		
		else if(length2-17*(k-1) < 0)
		operand2=0;

	sub = operand1 - operand2 + carry;//carry is either -1 or 0

	carry=0;

		if(sub>=0)
		{
		_i64toa( sub, sub_char,10);

			if(strlen(sub_char)==17)
			memmove(result+length3-17*k,&sub_char,17);

			else if(strlen(sub_char)<17)
			{
			memmove(result+length3-17*k+(17-strlen(sub_char)),&sub_char[0],strlen(sub_char) );
				for(counter=0;result[length3-17*k+counter]==-51 || result[length3-17*k+counter]<=0 || result[length3-17*k+counter]<=9 ;counter++)
				memset(result+length3-17*k+counter,'0',1);
	
			}
		}
		else if(sub<0)
		{
			if(length3-17*k>0)
			{
				_i64toa( sub, sub_char,10);
				for(turnToPositive=1,counter=1;counter<strlen(sub_char);counter++)
				turnToPositive=10*turnToPositive;
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM			sub=100000000000000000+sub;
			sub=turnToPositive+sub;
			}
			_i64toa( sub, sub_char,10);

			if(strlen(sub_char)==18)
			memmove(result+length3-17*k,&sub_char,18);
			else if(strlen(sub_char)==17)
			memmove(result+length3-17*k,&sub_char,17);
		
			else if(strlen(sub_char)<17)
			{
			memmove(result+length3-17*k+(17-strlen(sub_char)),&sub_char[0],strlen(sub_char) );
			for(counter=0;result[length3-17*k+counter]==-51 || result[length3-17*k+counter]<=0 || result[length3-17*k+counter]<=9 ;counter++)
			memset(result+length3-17*k+counter,'0',1);
			}
		carry=-1;
		}
}
	for(counter=0;counter<forDot;counter++)
	result[length3-counter]=result[length3-counter-1];
result[length3-forDot]='.';


return result;
}


void main()
{
char *str1;
char *str2;
char *result;
str1=(char *) malloc(200);
str2=(char *) malloc(200);
result=(char *) malloc(200);
strcpy(str1,"178678678657585643530000040000062434675435");
strcpy(str2,"212331243232345111234512345123451234512345");
result=subtraction(str1,str2);
}



