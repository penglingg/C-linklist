#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void pprint(){
	printf("(1)�إ߭��u�ɮ�\n");
	printf("(2)�s�W���u�ɮ�\n");
	printf("(3)�d�߭��u�ɮ�\n");
	printf("(4)�R�����u�ɮ�\n");
	printf("(5)��ܳ���\n");
	printf("(6)���~���Ѥ֨�h�Ƨ�\n");
	printf("(7)����\n");
}

struct staff{
		char name[10];
		int age;
		int salary;
		struct staff *next;
	};
	
int main(){
	printf("(1)�إ߭��u�ɮ�\n");
	printf("(7)����\n");
	int choose;
	bool first=false;
	struct staff *begin=((struct staff*)malloc(sizeof(struct staff))); 
	struct staff *ptr=((struct staff*)malloc(sizeof(struct staff)));
	struct staff *pt=((struct staff*)malloc(sizeof(struct staff)));
	first=true;
	char cc;
	while(true){
		scanf("%d",&choose);
		if(choose==1){//�إ� 
			system("CLS");
			struct staff *in=((struct staff*)malloc(sizeof(struct staff)));
			
			char nname[10];
			if(first==true){
				printf("�W�r:");
				scanf("%s",&nname);	
				strcpy(in->name,nname);
				printf("�~��:");
				scanf("%d",&in->age);
				printf("�~��:");
				scanf("%d",&in->salary);
				in->next=NULL;
				ptr=in;
				begin=ptr;
				
				first=false;
				printf("q�����A��L���@���~��: ");
				scanf(" %c",&cc);
			}
			
			else{
				printf("�W�r:");
				scanf("%s",&nname);	
				strcpy(in->name,nname);
				printf("�~��:");
				scanf("%d",&in->age);
				printf("�~��:");
				scanf("%d",&in->salary);
				in->next=NULL;
				ptr->next=in;
				ptr=ptr->next;
				
				printf("q�����A��L���@���~��: ");
				scanf(" %c",&cc);
			}
			
			
		
			while(cc!='q'){
				struct staff *iin=((struct staff*)malloc(sizeof(struct staff)));
				printf("�W�r:");
				scanf("%s",&nname);
				strcpy(iin->name,nname);
				printf("�~��:");
				scanf("%d",&iin->age);
				printf("�~��:");
				scanf("%d",&iin->salary);
				printf("%s %d %d\n",iin->name,iin->age,iin->salary);
				iin->next=NULL;
				ptr->next=iin;
				ptr=ptr->next;
				
				printf("q�����A��L���@���~��: ");
				scanf(" %c",&cc);
				
			}
	
			system("CLS");
			pprint();	
		}
		
		else if(choose==2 && first==false){//�s�W 
			system("CLS");
			struct staff *in=((struct staff*)malloc(sizeof(struct staff)));
			char nname[10];
			printf("�W�r:");
			scanf("%s",&nname);
			strcpy(in->name,nname);
			printf("�~��:");
			scanf("%d",&in->age);
			printf("�~��:");
			scanf("%d",&in->salary);
			in->next=NULL;
			ptr->next=in;
			ptr=ptr->next;

			system("CLS");
			pprint();	
		}
		
		else if(choose==3 && first==false){//�d�� 
			system("CLS");
			printf("��J�����u�W�r:");
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
					printf("�~��:%d\n",pt->age);
					printf("�~��:%d\n",pt->salary);system("pause");
					break;
				}
			}
			system("CLS");
			pprint();
		}
		
		else if(choose==4 && first==false){//�R�� 
			system("CLS");
			printf("��J���u�W�r:\n");
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
		else if(choose==5 && first==false){//��� 
			system("CLS");
			pt=begin;
			while(pt!=NULL){
				printf("�W�r:%s\n",pt->name);
				printf("�~��:%d\n",pt->age);
				printf("�~��:%d\n",pt->salary);
				printf("-------------\n");
				pt=pt->next;
			}
			system("pause");
			system("CLS");
			pprint();
		}
		else if(choose==6 && first==false){//�Ƨ�
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
				printf("�W�r:%s\n",pt->name);
				printf("�~��:%d\n",pt->age);
				printf("�~��:%d\n",pt->salary);
				printf("-------------\n");
				pt=pt->next;
			}
			system("pause");
			system("CLS");
			pprint();
		}
		else if(choose==7){//���� 
			break;
		}
		else if((choose==2||choose==3||choose==4||choose==5||choose==6) && first==true){
			printf("������ƿ�J�A�п�J1(��J���)��7(���})\n");
			system("pause");
			system("CLS");
			printf("(1)�إ߭��u�ɮ�\n");
			printf("(7)����\n");
		}
		else if(choose!=1||choose!=2||choose!=3||choose!=4||choose!=5||choose!=6||choose!=7){
			printf("�п�J1~7\n");
			system("pause");
			system("CLS");
			pprint();
		}
	}		
	system("pause");
	return 0;
}

