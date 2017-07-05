#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include"list.h"

int main(void){
	int i,num;
	int price = 0;
	char input0[128] = "";
	char input1[128] = "";
	char input2[128] = "";
	char filename1[32] = "_for_Program.txt";
	char filename2[32] = "_for_customer.txt";
	char c;
	pack_type out[element];
	FILE *fp1,*fp2;

	srand((unsigned)time(NULL));
	Init_list(out);

	printf("島名を入力:");
	scanf("%s%c",input0,&c);

	strcpy(input1,input0);
	strcpy(input2,input0);
	strcat(input1,filename1);
	strcat(input2,filename2);

	printf("何連ガチャ？ ->");
	scanf("%d",&num);

	printf("お値段[億円]:");
	scanf("%d",&price);

	for(i=0;i<num;i++){
		out[i].data.type 	= 404;
		out[i].data.sex		= rand()%2;
		out[i].data.leg		= rand()%2;

		out[i].data.power	= rand()%100+1;
		if(out[i].data.power >= 85 ){
			out[i].data.power -= rand()%21 + rand()%11;
			if( (rand()%100+1) > 80 ){
				out[i].data.power += rand()%31 + 20;
			}
		}
		if(out[i].data.power > 100)out[i].data.power=100;

		out[i].data.stamina	= rand()%100+1;
		if(out[i].data.stamina > 70){
				out[i].data.stamina	= rand()%100+1;
		}

		if(out[i].data.power > 100)out[i].data.power=100;
		out[i].data.fight	= rand()%100+1;
			if(out[i].data.fight > 70){
				out[i].data.fight	= rand()%100+1;
		}
		out[i].data.energy	= rand()%51;
			if(out[i].data.energy > 35){
				out[i].data.energy	= rand()%51;
		}
		out[i].data.life	= 4;
		out[i].data.mat		= 404;
	}
	if((fp1 = fopen(input2,"w")) == NULL){
		puts("Can't Open Text File.");
		exit(1);
	}
	if((fp2 = fopen(input1,"w"))==NULL){
	puts("Can't Open Text File.");
	exit(1);
	}
	fprintf(fp1,"%s様ガチャ結果(%d回分)\n",input0,num);
	fprintf(fp1,"お値段:%d億円\n\n",price);
	for(i=0;i<num;i++){
		fprintf(fp1, "馬名:\n");
		fprintf(fp1, "オーナー名:\n");
		fprintf(fp1, "タイプ:未定\n");
		if(out[i].data.sex == 0)fprintf(fp1, "性別:オス\n");
		if(out[i].data.sex == 1)fprintf(fp1, "性別:メス\n");
		if(out[i].data.leg == 0)fprintf(fp1, "脚質:逃げ\n");
		if(out[i].data.leg == 1)fprintf(fp1, "脚質:差し\n");
		fprintf(fp1, "脚力:%d\n",out[i].data.power);
		fprintf(fp1, "スタミナ:%d\n",out[i].data.stamina);
		fprintf(fp1, "闘争心:%d\n",out[i].data.fight);
		fprintf(fp1, "精力:%d\n",out[i].data.energy);
		fprintf(fp1, "寿命:%d\n",out[i].data.life);
		fprintf(fp1, "交配可能回数:%d\n",out[i].data.mat);
		out[i].ID = Generation_ID();
		fprintf(fp1, "ID:%d\n",out[i].ID);
		fprintf(fp1, "\n");

		fprintf(fp2, "\n");
		fprintf(fp2, "\n");
		fprintf(fp2, "%d\n",out[i].data.type);
		fprintf(fp2, "%d\n",out[i].data.sex);
		fprintf(fp2, "%d\n",out[i].data.leg);
		fprintf(fp2, "%d\n",out[i].data.power);
		fprintf(fp2, "%d\n",out[i].data.stamina);
		fprintf(fp2, "%d\n",out[i].data.fight);
		fprintf(fp2, "%d\n",out[i].data.energy);
		fprintf(fp2, "%d\n",out[i].data.life);
		fprintf(fp2, "%d\n",out[i].data.mat);
		fprintf(fp2, "%d\n",out[i].ID);
	}fclose(fp1);
	 fclose(fp2);

	 puts("Completed");

	 return 0;

}