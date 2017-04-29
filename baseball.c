#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct team {
	char teamName[200]; //����W��
	int score;
	struct players *next;
}Team;

typedef struct players {
	char name[200];
	//���� : �w���ơB���S���ơB�Q�T���ơB�Q�|�a�y�O�e����
	//��� : �n�y�ơB�a�y�ơB�Q�w�����ơB�Q���S������
	int A,B,C,D; 
	struct players *next;
}Players;

int main(){
	srand(time(NULL));
	int i,j,num,pp;
	char *INFO[10]={"1.","2.","3.","4.","5.","6.","7.","8.","9.","���:"};
	char *TOP[2] = {"�W","�U"};
	char *BASE[3] = {"��","��","��"};
	char *OD[2] = {"��y","����"};
	int CHOSE[7][7] = {{0,0,0,0,0,0,0},{0,1,2,3,4,5,0},{0,6,7,8,9,10,0},{0,11,12,13,14,15,0},{0,16,17,18,19,20,0},{0,21,22,23,24,25,0},{0,0,0,0,0,0,0}};
	int GOOD[9] = {7,8,9,12,13,14,17,18,19};
	Team *T_head[2],*T_temp[2];
	Players *head[2],*temp[2],*P[2],*t[2];
	
	printf("-----------------------------------------\n");
	do{	
		printf("�βy���ɹC�� 1.��H 2.���H : ");
		fflush(stdin);
		scanf("%d",&pp);
		printf("-----------------------------------------\n");
	}while(pp!=1 && pp!=2);
	
	for(num = 0;num < 2;num++){
		T_head[num] = (Team*)malloc(sizeof(Team));
		T_temp[num] = T_head[num];
		head[num] = (Players*)malloc(sizeof(Players));
		temp[num] = head[num];
	}

	for(num = 0;num < 2;num++){
		printf("�п�J���a %d ���y���W�١G",num+1);
		scanf("%s",T_head[num]->teamName);
		T_head[num]->score = 0;
		T_temp[num]->next = head[num];
	}

	for(num = 0;num < 2;num++){
		printf("\n�п�J %s �Φ��H���W�� �H�� ���G\n",T_head[num]->teamName);
		for(i = 0;i<10;i++){
			printf("%s",INFO[i]);
			temp[num]->next = (Players*)malloc(sizeof(Players));
			scanf("%s",temp[num]->next->name);
			temp[num]->A = 0;
			temp[num]->B = 0;
			temp[num]->C = 0;
			temp[num]->D = 0;
			temp[num] = temp[num]->next;
			if(i == 9){
				P[num] = temp[num];
			}
		}
		temp[num]->next = NULL;
		printf("\n");
	}

	int NEXT = 0;
	int flag = 0;
	int con = 0;
	int in,out;
	int base[4] = {0},b_temp = 0;
	int ball[3] = {0};
	int order[2] = {0};
	int grade[3][9] = {0};
	t[0] = head[0]->next;
	t[1] = head[1]->next;
	system("COLOR 0A");
	
	//9���ɧ� 
	for(num = 0;num<18;num++){		
		//��u�������m
		ball[0] = 0;
		ball[1] = 0;
		ball[2] = 0;
		base[0] = 0;
		base[1] = 0;
		base[2] = 0;
		b_temp = 0;
		con = 0;
		NEXT = 0;
		flag = 0;
		
		while(flag == 0){
			system("cls");
			//�C����y�������m 
			if(con%2 == 0){
				in = -1;
				out = -1;	
			}

			//��n�� �Wor�U	
			printf("%d��%s ",num/2+1,TOP[num%2]);
			printf("%s %d : %d %s\n",T_head[0]->teamName,T_head[0]->score,T_head[1]->score,T_head[1]->teamName);
			printf("�y��  �n�y�G%d �a�y�G%d �X���G%d\n",ball[0],ball[1],ball[2]);		
			
			//�y����
			printf("�S�]\n\n");
			printf("              %s               \n\n\n\n",BASE[base[1]]);
			printf("%s                          %s\n\n\n\n",BASE[base[2]],BASE[base[0]]);
			printf("              %s               \n",BASE[2]);
			printf("------------------------------------\n");
			
			//����or��y��	
			printf("          %s�Ͽ��\n\n",OD[con%2]);
			//�L�X1~25(5*5)�x�} 
			for(i = 1;i<=5;i++){
				printf("        ");
				for(j = 1;j<=5;j++){
					printf("%02d ",CHOSE[i][j]);
				}
				printf("\n");
			}
			printf("\n"); //����or��y��END 
						
			//��y�� 
			if(con%2==0){
				do{
					printf("��� %s ��y(�п�� 1~25) : ",P[(num+1)%2]->name);
					//���Hor��H����
					if(pp == 1 && num%2 == 0){
						in = rand() % 25 + 1;
						printf("%d\n",in);
					}
					else{
						fflush(stdin);
						//in = rand() % 25 + 1;
						scanf("%d",&in);
					}	
				}while(in<1 || in>25);	
			}
			//������ 
			else{
				if(NEXT == 1){
					t[num%2] = t[num%2]->next;
					order[num%2]++;
					NEXT = 0;
				}
				if(order[num%2] >= 9){
					t[num%2] = head[num%2]->next;//���Y�쵲 
					order[num%2] = 0;
				}
				do{
					printf("%s �Φ� %d(%s) ���� (�п�� 1~25�A�����Ϋh��J 0) : ",T_head[num%2]->teamName,order[num%2]%9+1,t[num%2]->name);
					//���Hor��H����
					if(pp == 1 && num%2 == 1){
						out = rand() % 26;
						printf("%d\n",out);
					}
					else{
						fflush(stdin);
						//out = rand() % 26;
						scanf("%d",&out);
					}
				}while(out<0 || out>25);
			}
				
			//���ΧP�_
			if(con%2==1){			
				if(out == 0){//������
					for(i = 0;i<9;i++){
						if(in == GOOD[i]){//�n�y 
							ball[0]++;
							i = 9;
							b_temp = 0;
							//--�y�Ƭ���--(���->�n�y)
							P[(num+1)%2]->A++; 
						}
						else if(i == 8){//�a�y 
							ball[1]++;
							b_temp = 0;	
							//--�y�Ƭ���--(���->�a�y)
							P[(num+1)%2]->B++; 
						}		
					} 	
				}
				else{
					for(i = 1;i<=5;i++){
						for(j = 1;j<=5;j++){
							if(CHOSE[i][j] == in){//����y�I 
								//���S��
								if(out == CHOSE[i][j]){
									b_temp = 4;
									NEXT = 1;						
									ball[0] = 0;
									ball[1] = 0;
									//--�y�Ƭ���--(���->�n�y)
										P[(num+1)%2]->A++; 
									//--�y�Ƭ���--(���->�Q���S��)
									P[(num+1)%2]->D++; 
									//--�y�Ƭ���--(����->���S��)
									t[num%2]->B++;
								}
								//1~3�S�w��
								else if(out == CHOSE[i][j+1] || out == CHOSE[i][j-1] || out == CHOSE[i-1][j] || out == CHOSE[i+1][j]){
									if(rand() % 2 == 0){
										b_temp = rand() % 3 + 1;
										NEXT = 1;										
										//--�y�Ƭ���--(���->�n�y)
										P[(num+1)%2]->A++; 
										//--�y�Ƭ���--(���->�Q�w��)
										P[(num+1)%2]->C++;																	
										//--�y�Ƭ���--(����->�w��)
										t[num%2]->A++;	
									}
									//50%���v�Q�~���Ⱶ���X��
									else{
										printf("\nINFO: ���� %s �Q�~���Ⱶ���X��\n",t[num%2]->name);
										ball[2]++;
										NEXT = 1;									
										//--�y�Ƭ���--(���->�n�y)
										P[(num+1)%2]->A++; 
									}
									ball[0] = 0;
									ball[1] = 0;								
								}
								//���θ��� �n�y 
								else{
									ball[0]++;
									b_temp = 0;		
									//--�y�Ƭ���--(���->�n�y)
									P[(num+1)%2]->A++; 
								}
							}
						}
					}
				}
			} //���ΧP�_END
			
				
			//�n�y�a�y�X���p�� 
			if(con%2==1){
				if(ball[0] == 3){
					ball[2]++;		
					ball[0] = 0;
					ball[1] = 0;
					NEXT = 1;
					printf("\nINFO: ���� %s �Q�T���X��\n",t[num%2]->name);
					//--�y�Ƭ���--(����->�Q�T��)
					t[num%2]->C++;	
				}
				else if(ball[1] == 4){
					if(base[0] == 0){
						base[0] = 1;
					}
					else if(base[1]==0){
						base[1] = 1;
					}
					else if(base[2]==0){
						base[2] = 1;
					}
					else{
						b_temp = 1;
					}	
					ball[1] = 0;
					ball[0] = 0;
					NEXT = 1;
					printf("\nINFO: ���� %s �|�a�y�O�e\n",t[num%2]->name);
					//--�y�Ƭ���--(����->�Q�|�a�O�e)
					t[num%2]->D++;
				}
	
				if(ball[2] == 3){
					flag = 1;//�ǳƵ��� 
				}
			} //�n�y�a�y�X���p��END 
			

			//�S�]���i�αo���p�� 	
			/*  1
			2       0
			    3     */
			if(con%2==1){			
				for(i = 0;i<b_temp;i++){
					for(j = 3;j>0;j--){
						base[j] = base[j] + base[j-1];
						base[j-1] = 0;
					}
				}
				base[b_temp-1]++;
				//�ݪO�έp
				grade[num%2][num/2] = grade[num%2][num/2] + base[3];
				T_head[num%2]->score = T_head[num%2]->score + base[3];
				base[3] = 0;//�o�����Y�M�� 
			} //�S�]���i�αo���p��END 
			printf("\n\n\n\n\n");
			con++;
		};
	} //9���ɧ�END 
 
 
	//�ݪO��T
	system("cls");
	printf("�έp��T----------------------------------------------------\n");
	printf("�y���@����  �U 1�U 2�U 3�U 4�U 5�U 6�U 7�U 8�U 9�U�̲פ���U\n");
	
	for(num = 0;num<2;num++){
		printf("%-12s�U",T_head[num]->teamName);
		for(i = 0;i<9;i++){
			printf("%2d�U",grade[num][i]);
		}
		printf("%8d�U\n",T_head[num]->score);
	}
	printf("------------------------------------------------------------\n\n");
	
	for(num = 0;num < 2;num++){
		printf("%s�y����{( �w���� | ���S���� | �Q�T���� | �Q�|�a�y�O�e�� )�G\n",T_head[num]->teamName);
		Players *temp = head[num]->next;
		for(i = 0;i<10;i++){
			if(i==9){
				printf("����{(�n�y�� | �a�y�� | �Q�w������ | �Q���S������)�G\n");
			}
			printf("%s %s",INFO[i],temp->name);
			printf("(%d�U%d�U%d�U%d)\n",temp->A,temp->B,temp->C,temp->D);
			temp = temp->next;
		}
	printf("\n");
	} //�ݪO��TEND 
	
	return 0;
}
/*
2
A��
B��
a����1 
a����2
a����3
a����4
a����5
a����6
a����7
a����8
a����9
A���
b����1
b����2
b����3
b����4
b����5
b����6
b����7
b����8
b����9
B���
*/ 
