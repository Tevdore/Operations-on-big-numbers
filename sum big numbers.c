#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *sum (char *num1, char *num2)
{
char *result="";
int dot1=0,dot2=0,j=0,i=0,k=1,counter,forDot,length1,length2,length3,carry=0;
__int64 operand1,operand2,sum;
char operand[2][18],sum_char[19],zeros[19]="";

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
length3=strlen(result);

	for(k=1; length1-17*(k-1)>0 || length2-17*(k-1)>0; k++)
	{
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

sum = operand1 + operand2 + carry;
_i64toa( sum, sum_char,10);

carry=0;

	if(strlen(sum_char)==18)
	carry=1;

	if(strlen(sum_char)==17 || strlen(sum_char)==18)
	memmove(result+length3-17*k,&sum_char[carry],17);

	if(strlen(sum_char)<17 && (strlen(operand[0])==strlen(sum_char)-carry || strlen(operand[1])==strlen(sum_char)-carry) )//im shemtxvevebistvis roca 17 simbolos gadmotanisas dasawyisshi tu 0 ebia
	memmove(result+length3-17*(k-1)-strlen(sum_char),&sum_char[0],strlen(sum_char));//result+length3-17*(k-1)-strlen(sum_char)+1
	
	else if(strlen(sum_char)<17)
	{
	memmove(result+length3-17*k+(17-strlen(sum_char)),&sum_char[0],strlen(sum_char)+carry );//result+length3-17*(k-1)-strlen(sum_char)+1
	for(counter=0;result[length3-17*k+counter]==-51 || result[length3-17*k+counter]<=0 || result[length3-17*k+counter]<=9 ;counter++)
	memset(result+length3-17*k+counter,'0',1);

	}
memset(&operand,0,sizeof(operand));
memset(&sum_char,0,sizeof(sum_char));
memset(&zeros,0,sizeof(zeros));
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
str1=(char *) malloc(2000);
str2=(char *) malloc(2000);
result=(char *) malloc(2000);
strcpy(str1,"722222212345124562300000000000000000000000004722222212345124562300000000000000000000000004722222212345124562300000000000000000000000004");
strcpy(  str2,"923456543245345230000000000000000000000054792345654324534523000000000000000000000005479234565432453452300000000000000000000000547");
result=sum(str1,str2);
}