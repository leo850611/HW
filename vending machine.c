//�m�W:�\���� �Ǹ�:D0381718 �Z��:��T�@�� 
#include<stdio.h>
int main(){
	char NY,select;
	char *AtoQ[8] = {"A","B","C","D","E","F","G","H"};
	char *EW[8] = {"�i��","����","�q�u��","���ؤ�","�����","�d�}��","��Q�w��","�p���氮"};
	char temp_b;
	int many[8] = {0,0,0,0,0,0,0,0};
	int coco[4] = {0,0,0,0},coco$[4] = {1,5,10,50};
	int EW$[8] = {30,30,20,25,10,20,50,35};
	int EWall$ = 0,all$ = 0,zero$,i,temp,temp_a,temp_c,temp_d,end = 0;
	//��ܥثe������A
	void print(int all$){
		printf("########################################\n");
		printf("  �ثe������A\n");
		printf("    �w��J���B�G %d\n",all$);
		temp = 0;
		for(i = 0;i < 8;i++){
			temp = temp + many[i];
		}
		if(temp == 0){
			printf("    �|����ܰӫ~\n");
		}
		else{
			for(i = 0;i < 8;i++){
				EWall$ = EWall$ + (many[i]) * (EW$[i]);
			}
			printf("    ��ܰӫ~�`���G %d\n",EWall$);
			printf("    �w��ܰӫ~���ءG\n");
			for(i = 0;i < 8;i++){
				if(many[i] != 0){
					printf("      %s : %d\n",EW[i],many[i]);
				}
			}
		EWall$ = 0;
		}
		printf("########################################\n\n");
	}
//�c����j�� 
do{
	//YorN�A�C���������l��
	do{
		printf(">>> �p�n�~���ʶR�ӫ~�A�п�J 'Y'�F�p�n�����ʶR�A�п�J 'N'�G\n");
		scanf("%s",&NY);		
		//wipe
		end = 0,EWall$ = 0,all$ = 0;
		for(i = 0;i < 8;i++){
			many[i] = 0;
			coco[i] = 0;	
		}
		if(NY == 'N') return 0; //�����I 
	}while(NY != 'Y');
	//���h�קK���X�^���l�]�w 
	do{
	do{
		//���s���,��call���A 
		print(all$);
		printf("        ���s��ܡG\n");
		printf("          a: ��J�w��\n");
		printf("          b: ��ܰӫ~\n");
		printf("          c: �����ӫ~\n");
		printf("          d: �ʶR�ӫ~\n");
		printf("          e: �������\n\n");
		printf(">>> �п�ܫ��s�G ");	
		scanf("%s",&select);
		printf("\n");
		//a���,0 end
		if(select == 'a'){
			do{
				printf(">>> �Ч�J 1 ���A5 ���A10 ���ΡA50 �����w�� (��������п�J 0)�G");
				scanf("%d",&temp_a);
				for(i = 0;i < 4;i++){
					if(temp_a == coco$[i]){
						coco[i] = coco[i] + 1;
						printf("$$$$ ��J�@�� %d ���w��\n\n",coco$[i]);
						all$ = all$ + coco$[i];
						print(all$);
					}
				}
				if(temp_a == 0){
					printf("$$$$ �������\n\n");
				}
			}while(temp_a != 0);
		break;
		}
		//b�ӫ~���,Q end
		if(select == 'b'){
			do{
				print(all$);
				printf("        �ӫ~�ﶵ�G\n");
				for(i = 0;i < 8;i++){
					printf("          %s: %s %d\n",AtoQ[i],EW[i],EW$[i]);
				}
				printf("          Q: �����ӫ~���\n\n");	
				printf(">>> �п�J��ܪ��ӫ~�N���G");
				scanf("%s",&temp_b);
				printf("\n");
				for(i = 0;i < 8;i++){
					if(temp_b == *AtoQ[i]){
						many[i] = many[i] + 1;
						printf("**** ��ܰӫ~�G%s\n",EW[i]);
					}
				}
				if(temp_b == 'Q') printf("**** �����ӫ~���\n");
			}while(temp_b != 'Q');	
		} 
		//c�����\��,�@���� 
		if(select == 'c'){
			printf("        �ӫ~�ﶵ�G\n");
			for(i = 0;i < 8;i++){
				printf("          %s: %s %d\n",AtoQ[i],EW[i],EW$[i]);
			}
			printf("\n");
			printf(">>> �п�J�������ӫ~�N���G");
			scanf("%s",&temp_c);
			for(i = 0;i < 8;i++){
				if(temp_c == *AtoQ[i]){
					if(many[i] == 0) printf("**** �ӫ~�����L��\n\n");
					else{
						many[i] = many[i] - 1;
						printf("**** �����ӫ~�G%s\n\n",EW[i]);
					}
				}
			}
		}
		//d BUY
		if(select == 'd'){		
			for(i = 0;i < 8;i++){
				EWall$ = EWall$ + (many[i]) * (EW$[i]);
			}
			if(all$ >= EWall$){
				printf("**** �ʶR�ӫ~�G\n");
				for(i = 0;i < 8;i++){
					if(many[i] != 0) printf("       %s �G %d\n",EW[i],many[i]);
				}
				zero$ = all$ - EWall$;  
				printf("**** �h�^�s�� %d ���G\n",zero$);
				temp_d = all$ - EWall$;
				for(i = 3;i >=0;i--){
					coco[i] = temp_d / coco$[i];
					temp_d = temp_d - coco[i]*coco$[i];
					if(coco[i] != 0) printf("       %2d ���w��%2d ��\n",coco$[i],coco[i]);			
				}
				printf("\n");
			end++; //�����I1
			}
			else{
				printf("**** ���B����\n\n");
			}			
		}
		//e�h$ 
		if(select == 'e'){
			printf("**** �h�^�s�� %d ���G\n",all$);
			if(all$ != 0){
				for(i = 3;i >=0;i--){
					if(coco[i] != 0) printf("       %2d ���w��%2d ��\n",coco$[i],coco[i]);
				}
			}
			printf("\n");
		end++; //�����I2
		}
			
	}while(end == 0);
	}while(end == 0);
}while(1);
return 0;	
}
