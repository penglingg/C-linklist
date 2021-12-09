#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void pprint(){
	printf("(1)建立員工檔案\n");
	printf("(2)新增員工檔案\n");
	printf("(3)查詢員工檔案\n");
	printf("(4)刪除員工檔案\n");
	printf("(5)顯示報表\n");
	printf("(6)按薪水由少到多排序\n");
	printf("(7)結束\n");
}

struct staff{
		char name[10];
		int age;
		int salary;
		struct staff *next;
	};
	
int main(){
	printf("(1)建立員工檔案\n");
	printf("(7)結束\n");
	int choose;
	bool first=false;
	struct staff *begin=((struct staff*)malloc(sizeof(struct staff))); 
	struct staff *ptr=((struct staff*)malloc(sizeof(struct staff)));
	struct staff *pt=((struct staff*)malloc(sizeof(struct staff)));
	first=true;
	char cc;
	while(true){
		scanf("%d",&choose);
		if(choose==1){//建立 
			system("CLS");
			struct staff *in=((struct staff*)malloc(sizeof(struct staff)));
			
			char nname[10];
			if(first==true){
				printf("名字:");
				scanf("%s",&nname);	
				strcpy(in->name,nname);
				printf("年齡:");
				scanf("%d",&in->age);
				printf("薪水:");
				scanf("%d",&in->salary);
				in->next=NULL;
				ptr=in;
				begin=ptr;
				
				first=false;
				printf("q結束，其他任一鍵繼續: ");
				scanf(" %c",&cc);
			}
			
			else{
				printf("名字:");
				scanf("%s",&nname);	
				strcpy(in->name,nname);
				printf("年齡:");
				scanf("%d",&in->age);
				printf("薪水:");
				scanf("%d",&in->salary);
				in->next=NULL;
				ptr->next=in;
				ptr=ptr->next;
				
				printf("q結束，其他任一鍵繼續: ");
				scanf(" %c",&cc);
			}
			
			
		
			while(cc!='q'){
				struct staff *iin=((struct staff*)malloc(sizeof(struct staff)));
				printf("名字:");
				scanf("%s",&nname);
				strcpy(iin->name,nname);
				printf("年齡:");
				scanf("%d",&iin->age);
				printf("薪水:");
				scanf("%d",&iin->salary);
				printf("%s %d %d\n",iin->name,iin->age,iin->salary);
				iin->next=NULL;
				ptr->next=iin;
				ptr=ptr->next;
				
				printf("q結束，其他任一鍵繼續: ");
				scanf(" %c",&cc);
				
			}
	
			system("CLS");
			pprint();	
		}
		
		else if(choose==2 && first==false){//新增 
			system("CLS");
			struct staff *in=((struct staff*)malloc(sizeof(struct staff)));
			char nname[10];
			printf("名字:");
			scanf("%s",&nname);
			strcpy(in->name,nname);
			printf("年齡:");
			scanf("%d",&in->age);
			printf("薪水:");
			scanf("%d",&in->salary);
			in->next=NULL;
			ptr->next=in;
			ptr=ptr->next;

			system("CLS");
			pprint();	
		}
		
		else if(choose==3 && first==false){//查詢 
			system("CLS");
			printf("輸入的員工名字:");
			char nname[10];
			scanf(" %s",&nname);

			pt=begin;
			while(pt!=NULL){
				char nn[10];
				strcpy(nn,pt->name);
				if(strcmp(nname,nn)!=0){
					pt=pt->next;
				}
				else{
					printf("年齡:%d\n",pt->age);
					printf("薪水:%d\n",pt->salary);system("pause");
					break;
				}
			}
			system("CLS");
			pprint();
		}
		
		else if(choose==4 && first==false){//刪除 
			system("CLS");
			printf("輸入員工名字:\n");
			char nname[10];
			scanf("%s",&nname);
			pt=begin->next;
			struct staff *ptbefore=((struct staff*)malloc(sizeof(struct staff)));				ptbefore=begin;
			while(pt!=NULL){
				if(strcmp(nname,begin->name)==0){
					begin=begin->next;
					break;
				}
				else if(strcmp(nname,pt->name)==0){
					ptbefore->next=pt->next;
					break;
				}
				else{
					ptbefore=pt;
					pt=pt->next;
				}
			}	
			system("CLS");
			pprint();
		}
		else if(choose==5 && first==false){//顯示 
			system("CLS");
			pt=begin;
			while(pt!=NULL){
				printf("名字:%s\n",pt->name);
				printf("年齡:%d\n",pt->age);
				printf("薪水:%d\n",pt->salary);
				printf("-------------\n");
				pt=pt->next;
			}
			system("pause");
			system("CLS");
			pprint();
		}
		else if(choose==6 && first==false){//排序
			system("CLS");
			struct staff *tail=((struct staff*)malloc(sizeof(struct staff)));
			struct staff *tmp=((struct staff*)malloc(sizeof(struct staff)));
			struct staff *cur=((struct staff*)malloc(sizeof(struct staff)));
			struct staff *pre=((struct staff*)malloc(sizeof(struct staff)));
			tail=begin;
			tmp=begin;
			cur=begin;
			pre=begin;
			int size=0;
			while(tail!=NULL){
				tail=tail->next;
				size++;
			}
			for(int i=size;i>0;i--){
				cur=begin;
				pre=begin;
				for(int j=0;j<i-1 && cur->next ;j++){
					
					if(cur->salary>cur->next->salary){
						tmp=cur->next;
						cur->next=tmp->next;
						tmp->next=cur;
						
						if(cur==begin){
							begin=tmp;
							pre=tmp;
						}
						else{
							pre->next=tmp;
							pre=pre->next;
						}
					}
					else{
						cur=cur->next;
						if(j!=0){
							pre=pre->next;
						}
					}
				}
			}
			pt=begin;
				
			while(pt!=NULL){
				printf("名字:%s\n",pt->name);
				printf("年齡:%d\n",pt->age);
				printf("薪水:%d\n",pt->salary);
				printf("-------------\n");
				pt=pt->next;
			}
			system("pause");
			system("CLS");
			pprint();
		}
		else if(choose==7){//結束 
			break;
		}
		else if((choose==2||choose==3||choose==4||choose==5||choose==6) && first==true){
			printf("未有資料輸入，請輸入1(輸入資料)或7(離開)\n");
			system("pause");
			system("CLS");
			printf("(1)建立員工檔案\n");
			printf("(7)結束\n");
		}
		else if(choose!=1||choose!=2||choose!=3||choose!=4||choose!=5||choose!=6||choose!=7){
			printf("請輸入1~7\n");
			system("pause");
			system("CLS");
			pprint();
		}
	}		
	system("pause");
	return 0;
}

