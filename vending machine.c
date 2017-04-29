//姓名:許哲源 學號:D0381718 班級:資訊一甲 
#include<stdio.h>
int main(){
	char NY,select;
	char *AtoQ[8] = {"A","B","C","D","E","F","G","H"};
	char *EW[8] = {"可樂","雪碧","礦泉水","茶裏王","科學麵","卡迪那","阿Q泡麵","小熊餅乾"};
	char temp_b;
	int many[8] = {0,0,0,0,0,0,0,0};
	int coco[4] = {0,0,0,0},coco$[4] = {1,5,10,50};
	int EW$[8] = {30,30,20,25,10,20,50,35};
	int EWall$ = 0,all$ = 0,zero$,i,temp,temp_a,temp_c,temp_d,end = 0;
	//顯示目前交易狀態
	void print(int all$){
		printf("########################################\n");
		printf("  目前交易狀態\n");
		printf("    已投入金額： %d\n",all$);
		temp = 0;
		for(i = 0;i < 8;i++){
			temp = temp + many[i];
		}
		if(temp == 0){
			printf("    尚未選擇商品\n");
		}
		else{
			for(i = 0;i < 8;i++){
				EWall$ = EWall$ + (many[i]) * (EW$[i]);
			}
			printf("    選擇商品總價： %d\n",EWall$);
			printf("    已選擇商品項目：\n");
			for(i = 0;i < 8;i++){
				if(many[i] != 0){
					printf("      %s : %d\n",EW[i],many[i]);
				}
			}
		EWall$ = 0;
		}
		printf("########################################\n\n");
	}
//販賣機迴圈 
do{
	//YorN，每次執行先初始化
	do{
		printf(">>> 如要繼續購買商品，請輸入 'Y'；如要停止購買，請輸入 'N'：\n");
		scanf("%s",&NY);		
		//wipe
		end = 0,EWall$ = 0,all$ = 0;
		for(i = 0;i < 8;i++){
			many[i] = 0;
			coco[i] = 0;	
		}
		if(NY == 'N') return 0; //中止點 
	}while(NY != 'Y');
	//雙層避免跳出回到初始設定 
	do{
	do{
		//按鈕選擇,先call狀態 
		print(all$);
		printf("        按鈕選擇：\n");
		printf("          a: 投入硬幣\n");
		printf("          b: 選擇商品\n");
		printf("          c: 取消商品\n");
		printf("          d: 購買商品\n");
		printf("          e: 取消交易\n\n");
		printf(">>> 請選擇按鈕： ");	
		scanf("%s",&select);
		printf("\n");
		//a投錢,0 end
		if(select == 'a'){
			do{
				printf(">>> 請投入 1 元，5 元，10 元或，50 元的硬幣 (投幣完成請輸入 0)：");
				scanf("%d",&temp_a);
				for(i = 0;i < 4;i++){
					if(temp_a == coco$[i]){
						coco[i] = coco[i] + 1;
						printf("$$$$ 投入一個 %d 元硬幣\n\n",coco$[i]);
						all$ = all$ + coco$[i];
						print(all$);
					}
				}
				if(temp_a == 0){
					printf("$$$$ 投幣結束\n\n");
				}
			}while(temp_a != 0);
		break;
		}
		//b商品選擇,Q end
		if(select == 'b'){
			do{
				print(all$);
				printf("        商品選項：\n");
				for(i = 0;i < 8;i++){
					printf("          %s: %s %d\n",AtoQ[i],EW[i],EW$[i]);
				}
				printf("          Q: 結束商品選擇\n\n");	
				printf(">>> 請輸入選擇的商品代號：");
				scanf("%s",&temp_b);
				printf("\n");
				for(i = 0;i < 8;i++){
					if(temp_b == *AtoQ[i]){
						many[i] = many[i] + 1;
						printf("**** 選擇商品：%s\n",EW[i]);
					}
				}
				if(temp_b == 'Q') printf("**** 結束商品選擇\n");
			}while(temp_b != 'Q');	
		} 
		//c取消功能,一次性 
		if(select == 'c'){
			printf("        商品選項：\n");
			for(i = 0;i < 8;i++){
				printf("          %s: %s %d\n",AtoQ[i],EW[i],EW$[i]);
			}
			printf("\n");
			printf(">>> 請輸入取消的商品代號：");
			scanf("%s",&temp_c);
			for(i = 0;i < 8;i++){
				if(temp_c == *AtoQ[i]){
					if(many[i] == 0) printf("**** 商品取消無效\n\n");
					else{
						many[i] = many[i] - 1;
						printf("**** 取消商品：%s\n\n",EW[i]);
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
				printf("**** 購買商品：\n");
				for(i = 0;i < 8;i++){
					if(many[i] != 0) printf("       %s ： %d\n",EW[i],many[i]);
				}
				zero$ = all$ - EWall$;  
				printf("**** 退回零錢 %d 元：\n",zero$);
				temp_d = all$ - EWall$;
				for(i = 3;i >=0;i--){
					coco[i] = temp_d / coco$[i];
					temp_d = temp_d - coco[i]*coco$[i];
					if(coco[i] != 0) printf("       %2d 元硬幣%2d 個\n",coco$[i],coco[i]);			
				}
				printf("\n");
			end++; //結束點1
			}
			else{
				printf("**** 金額不足\n\n");
			}			
		}
		//e退$ 
		if(select == 'e'){
			printf("**** 退回零錢 %d 元：\n",all$);
			if(all$ != 0){
				for(i = 3;i >=0;i--){
					if(coco[i] != 0) printf("       %2d 元硬幣%2d 個\n",coco$[i],coco[i]);
				}
			}
			printf("\n");
		end++; //結束點2
		}
			
	}while(end == 0);
	}while(end == 0);
}while(1);
return 0;	
}
