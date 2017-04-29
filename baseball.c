#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct team {
	char teamName[200]; //隊伍名稱
	int score;
	struct players *next;
}Team;

typedef struct players {
	char name[200];
	//打者 : 安打數、全壘打數、被三振數、被四壞球保送次數
	//投手 : 好球數、壞球數、被安打次數、被全壘打次數
	int A,B,C,D; 
	struct players *next;
}Players;

int main(){
	srand(time(NULL));
	int i,j,num,pp;
	char *INFO[10]={"1.","2.","3.","4.","5.","6.","7.","8.","9.","投手:"};
	char *TOP[2] = {"上","下"};
	char *BASE[3] = {"○","●","◎"};
	char *OD[2] = {"投球","打擊"};
	int CHOSE[7][7] = {{0,0,0,0,0,0,0},{0,1,2,3,4,5,0},{0,6,7,8,9,10,0},{0,11,12,13,14,15,0},{0,16,17,18,19,20,0},{0,21,22,23,24,25,0},{0,0,0,0,0,0,0}};
	int GOOD[9] = {7,8,9,12,13,14,17,18,19};
	Team *T_head[2],*T_temp[2];
	Players *head[2],*temp[2],*P[2],*t[2];
	
	printf("-----------------------------------------\n");
	do{	
		printf("棒球比賽遊戲 1.單人 2.雙人 : ");
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
		printf("請輸入玩家 %d 的球隊名稱：",num+1);
		scanf("%s",T_head[num]->teamName);
		T_head[num]->score = 0;
		T_temp[num]->next = head[num];
	}

	for(num = 0;num < 2;num++){
		printf("\n請輸入 %s 棒次人員名單 以及 投手：\n",T_head[num]->teamName);
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
	
	//9場賽局 
	for(num = 0;num<18;num++){		
		//攻守互換重置
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
			//每次投球打擊重置 
			if(con%2 == 0){
				in = -1;
				out = -1;	
			}

			//第n局 上or下	
			printf("%d局%s ",num/2+1,TOP[num%2]);
			printf("%s %d : %d %s\n",T_head[0]->teamName,T_head[0]->score,T_head[1]->score,T_head[1]->teamName);
			printf("球數  好球：%d 壞球：%d 出局：%d\n",ball[0],ball[1],ball[2]);		
			
			//球場圖
			printf("壘包\n\n");
			printf("              %s               \n\n\n\n",BASE[base[1]]);
			printf("%s                          %s\n\n\n\n",BASE[base[2]],BASE[base[0]]);
			printf("              %s               \n",BASE[2]);
			printf("------------------------------------\n");
			
			//打擊or投球區	
			printf("          %s區選擇\n\n",OD[con%2]);
			//印出1~25(5*5)矩陣 
			for(i = 1;i<=5;i++){
				printf("        ");
				for(j = 1;j<=5;j++){
					printf("%02d ",CHOSE[i][j]);
				}
				printf("\n");
			}
			printf("\n"); //打擊or投球區END 
						
			//投球方 
			if(con%2==0){
				do{
					printf("投手 %s 投球(請選擇 1~25) : ",P[(num+1)%2]->name);
					//雙人or單人控制
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
			//打擊方 
			else{
				if(NEXT == 1){
					t[num%2] = t[num%2]->next;
					order[num%2]++;
					NEXT = 0;
				}
				if(order[num%2] >= 9){
					t[num%2] = head[num%2]->next;//重頭鏈結 
					order[num%2] = 0;
				}
				do{
					printf("%s 棒次 %d(%s) 打擊 (請選擇 1~25，不揮棒則輸入 0) : ",T_head[num%2]->teamName,order[num%2]%9+1,t[num%2]->name);
					//雙人or單人控制
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
				
			//揮棒判斷
			if(con%2==1){			
				if(out == 0){//不揮棒
					for(i = 0;i<9;i++){
						if(in == GOOD[i]){//好球 
							ball[0]++;
							i = 9;
							b_temp = 0;
							//--球數紀錄--(投手->好球)
							P[(num+1)%2]->A++; 
						}
						else if(i == 8){//壞球 
							ball[1]++;
							b_temp = 0;	
							//--球數紀錄--(投手->壞球)
							P[(num+1)%2]->B++; 
						}		
					} 	
				}
				else{
					for(i = 1;i<=5;i++){
						for(j = 1;j<=5;j++){
							if(CHOSE[i][j] == in){//找到投球點 
								//全壘打
								if(out == CHOSE[i][j]){
									b_temp = 4;
									NEXT = 1;						
									ball[0] = 0;
									ball[1] = 0;
									//--球數紀錄--(投手->好球)
										P[(num+1)%2]->A++; 
									//--球數紀錄--(投手->被全壘打)
									P[(num+1)%2]->D++; 
									//--球數紀錄--(打者->全壘打)
									t[num%2]->B++;
								}
								//1~3壘安打
								else if(out == CHOSE[i][j+1] || out == CHOSE[i][j-1] || out == CHOSE[i-1][j] || out == CHOSE[i+1][j]){
									if(rand() % 2 == 0){
										b_temp = rand() % 3 + 1;
										NEXT = 1;										
										//--球數紀錄--(投手->好球)
										P[(num+1)%2]->A++; 
										//--球數紀錄--(投手->被安打)
										P[(num+1)%2]->C++;																	
										//--球數紀錄--(打者->安打)
										t[num%2]->A++;	
									}
									//50%機率被外野手接殺出局
									else{
										printf("\nINFO: 打者 %s 被外野手接殺出局\n",t[num%2]->name);
										ball[2]++;
										NEXT = 1;									
										//--球數紀錄--(投手->好球)
										P[(num+1)%2]->A++; 
									}
									ball[0] = 0;
									ball[1] = 0;								
								}
								//揮棒落空 好球 
								else{
									ball[0]++;
									b_temp = 0;		
									//--球數紀錄--(投手->好球)
									P[(num+1)%2]->A++; 
								}
							}
						}
					}
				}
			} //揮棒判斷END
			
				
			//好球壞球出局計算 
			if(con%2==1){
				if(ball[0] == 3){
					ball[2]++;		
					ball[0] = 0;
					ball[1] = 0;
					NEXT = 1;
					printf("\nINFO: 打者 %s 被三振出局\n",t[num%2]->name);
					//--球數紀錄--(打者->被三振)
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
					printf("\nINFO: 打者 %s 四壞球保送\n",t[num%2]->name);
					//--球數紀錄--(打者->被四壞保送)
					t[num%2]->D++;
				}
	
				if(ball[2] == 3){
					flag = 1;//準備結束 
				}
			} //好球壞球出局計算END 
			

			//壘包推進及得分計算 	
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
				//看板統計
				grade[num%2][num/2] = grade[num%2][num/2] + base[3];
				T_head[num%2]->score = T_head[num%2]->score + base[3];
				base[3] = 0;//得分完即清空 
			} //壘包推進及得分計算END 
			printf("\n\n\n\n\n");
			con++;
		};
	} //9場賽局END 
 
 
	//看板資訊
	system("cls");
	printf("統計資訊----------------------------------------------------\n");
	printf("球隊＼局數  ｜ 1｜ 2｜ 3｜ 4｜ 5｜ 6｜ 7｜ 8｜ 9｜最終比分｜\n");
	
	for(num = 0;num<2;num++){
		printf("%-12s｜",T_head[num]->teamName);
		for(i = 0;i<9;i++){
			printf("%2d｜",grade[num][i]);
		}
		printf("%8d｜\n",T_head[num]->score);
	}
	printf("------------------------------------------------------------\n\n");
	
	for(num = 0;num < 2;num++){
		printf("%s球員表現( 安打數 | 全壘打數 | 被三振數 | 被四壞球保送數 )：\n",T_head[num]->teamName);
		Players *temp = head[num]->next;
		for(i = 0;i<10;i++){
			if(i==9){
				printf("投手表現(好球數 | 壞球數 | 被安打次數 | 被全壘打次數)：\n");
			}
			printf("%s %s",INFO[i],temp->name);
			printf("(%d｜%d｜%d｜%d)\n",temp->A,temp->B,temp->C,temp->D);
			temp = temp->next;
		}
	printf("\n");
	} //看板資訊END 
	
	return 0;
}
/*
2
A隊
B隊
a打者1 
a打者2
a打者3
a打者4
a打者5
a打者6
a打者7
a打者8
a打者9
A投手
b打者1
b打者2
b打者3
b打者4
b打者5
b打者6
b打者7
b打者8
b打者9
B投手
*/ 
