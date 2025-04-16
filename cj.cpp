#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

typedef struct UserN {
	char name[11];
} usern;

typedef struct UserP {
	char password[7];
} userp;

typedef struct UserT {
	char tnum[12];
} usert;

typedef struct Role {
	char uname[50];  //�û���
	int work;    //����
	int sex;    //�Ա�
	long long int life;   //����ֵ
	int power;   //������
	int magic;   //����ֵ
	int race;    //����
	int state = 0;  //����
	long long int exp = 0;  //����ֵ
} role;

typedef struct Mapr {
	char rname[20];
	int num1;
	long long int rlife;
	int rpower;
	int state1;
} mapr;

typedef struct Node {
	mapr a;
	struct Node *next;
} node;

void login1();
void regist();
void signin();
void find();
void help();
void creatrole();
int getwork();
void printproperty(role b);
void getproperty(int work,role a);
void login2();
void help2();
void start();
void out();
void exercise();
void promote();
void save(role b);
void gamechange();
void inchange();
void out2();
void maplook(node *head);
node *creatlist();
node *creatnode(mapr a);
void insertbyend(node *head,mapr a);
void printlist(node *head);
void mapchange();
void mapselect(node *head);


int main(void) {
	SetConsoleTitle("�������� Designed by zjx");
	login1();
}

void help() {
	system("cls");
	system("color 71");
	printf("\a\a\a\a\a\a");
	printf("\t\t1.�˺����֧��ʮλ����,�����볬��ʮλ����,������ע��\n");
	printf("\t\t2.����Ϊ��λ����\n");
	printf("\t\t3.�ֻ���Ϊ�һع���,��������д\n");
	printf("\a\t\t");
	system("pause");
	system("cls");
}

void login1() {
	fflush(stdin);//��������
	fflush(stdin);
	system("color 71");
	system("cls");
	printf("\t\t\t*************************************************************************\n");
	printf("\t\t\t***************************  �˺�ϵͳ��ӭ��   ***************************\n");
	printf("\t\t\t*************************************************************************\n");
	printf("\t\t\t********************  ��ѡ�����Ĳ���(����Сд����)  *********************\n");
	printf("\t\t\t*************************************************************************\n");
	printf("       \t\t\t\t*****************    һ.�˺�ע��    *****************\n");
	printf("       \t\t\t\t*****************    ��.�˺ŵ�¼    *****************\n");
	printf("       \t\t\t\t*****************    ��.�˺��һ�    *****************\n");
	printf("       \t\t\t\t*****************    ��.�˳�ϵͳ    *****************\n");
	printf("       \t\t\t\t*****************************************************\n");
	printf(" \n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\aDesigned by zjx\n\n\n\n\n\n\n");
	printf("\t\t\t\t��������Ҫ���еĲ���:[\t]\b\b\b");
	int x;
	scanf("%d",&x);
	switch(x) {
		case 1:
			regist();
			break;
		case 2:
			signin();
			break;
		case 3:
			find();
			break;
		case 4:
			printf("\a\t\t\t\t�����˳�ϵͳ\n");
			Sleep(1000);
			printf("\t\t\t\t");
			exit(0);
			break;
		default:
			system("cls");
			printf("\a\t\t\t\t��������ȷ������\n");
			printf("\t\t\t\t");
			system("pause");
			return login1();
	}
}

void regist() {
	help();
	int i = 0;
	int q;
	system("cls");
	system("color 71");
	printf("\t\t**��ӭ�������˺�ע��**\n");
	printf("\t\t��������,Ŀǰ��֧�ִ���һ���˺�\n");
	usern a;
	userp b,c;
	usert d;
	FILE *user1 = fopen("User1.txt","w");
	FILE *user2,*user3;
	printf("\t\t*�����������˺�(10λ����):[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",a.name);
	if((q=strlen(a.name))<=10) {
		fprintf(user1,"%s",a.name);
		printf("\a\t\t�˺�����ɹ�\n");
		printf("\a");
		printf("\t\t");
		system("pause");
		system("cls");
		fclose(user1);
	} else {
		printf("\t\t�˺Ÿ�ʽ�����Ź淶,������ע��\n");
		printf("\a");
		printf("\t\t");
		system("pause");
		return regist();
	}
	printf("\t\t*�����������ֻ���,�Ա����һ�����:[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",d.tnum);
	user3 = fopen("User3.txt","w");
	fprintf(user3,"%s",d.tnum);
	printf("\a\t\t*�ֻ�������ɹ�\n");
	printf("\a");
	printf("\t\t");
	system("pause");
	system("cls");
	fclose(user3);
	while(1) {
		int time1 = 2;
		do {
			printf("\t\t*����������(����ʶ��ǰ��λ):[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
			i = 0;
			do {
				b.password[i]=getch();
				if(b.password[i]=='\r')
					break;
				if(b.password[i]=='\b') {
					if(i==0) {
						printf("\a");
						continue;
					}
					i=i-1;
					printf("\b");
				} else {
					i=i+1;
					printf("*");
				}
			} while(b.password[i]!='\n' && i<6);
			b.password[i]='\0';
			printf("\n");
			printf("\t\t*��ȷ������:[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
			i = 0;
			do {
				c.password[i]=getch();
				if(c.password[i]=='\r')
					break;
				if(c.password[i]=='\b') {
					if(i==0) {
						printf("\a");
						continue;
					}
					i=i-1;
					printf("\b");
				} else {
					i=i+1;
					printf("*");
				}
			} while(c.password[i]!='\n' && i<6);
			c.password[i]='\0';
			printf("\n");
			if(!strcmp(b.password,c.password)) {
				user2 = fopen("User2.txt","w");
				fprintf(user2,"%s", b.password);
				printf("\t\t*�˺�ע��ɹ�!\n");
				printf("\a");
				printf("\t\t");
				system("pause");
				fclose(user1);
				return login1();
			} else {
				if(time1!=0) {
					printf("\n\t\t������������벻��ͬ��\t����������(ʣ��%d�λ���)\n",time1);
					time1--;
					continue;
				} else {
					printf("\n\t\t���������󣬼����˳���");
					printf("\a\t\t");
					system("pause");
					return ;
				}
			}
		} while(time1 >= 0);
	}
}

void signin() {
	fflush(stdin);//��������
	fflush(stdin);
	fflush(stdin);
	system("cls");
	usern a,d;
	userp b,c;
	char e;
	FILE *user1;
	FILE *user2;
	user1 = fopen("User1.txt","r");
	e=fgetc(user1);
	fseek(user1,0,SEEK_SET);
	fclose(user1);
	if(e==EOF) {
		printf("\a\t\t*����û�д����˺�\n");
		printf("\t\t");
		system("pause");
		return login1();
	} else {
		user1 = fopen("User1.txt","r");
		printf("\t\t**��ӭ�������˺ŵ�¼!**\n\n");
		printf("\t\t*�����������˺�:[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%s",a.name);
		fscanf(user1,"%s",&d);
		while(1) {
			if (strcmp(a.name,d.name)==0) {
				break;
			} else {
				printf("\t\t��������˺Ŵ���!\n");
				printf("\a\t\t");
				system("pause");
				fclose(user1);
				return signin();
			}
		}
		fclose(user1);
		printf("\t\t*��������������:[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		int i = 0;
		do {
			b.password[i]=getch();
			if(b.password[i]=='\r')
				break;
			if(b.password[i]=='\b') {
				if(i==0) {
					printf("\a");
					continue;
				}
				i=i-1;
				printf("\b");
			} else {
				i=i+1;
				printf("*");
			}
		} while(b.password[i]!='\n' && i<7);
		b.password[i]='\0';
		printf("\n");
		user2 = fopen("User2.txt","r");
		fscanf(user2,"%s",c.password);
		if(strcmp(b.password,c.password)==0) {
			printf("\a\t\t*��¼�ɹ�!\n");
			fclose(user2);
			printf("\a");
			printf("\t\t");
			system("pause");
			return login2();
		} else {
			printf("\a\t\t��������������!\n");
			printf("\t\t����������ٴγ���");
			Sleep(3000);
			system("cls");
			return signin();
		}
	}
}

void find() {
	system("color 71");
	system("cls");
	usert a,b;
	usern c;
	userp d;
	char e;
	FILE *User3,*User2,*User1;
	User3 = fopen("User3.txt","r");
	e = fgetc(User3);
	fclose(User3);
	if(e==EOF) {
		printf("\a\t\t*����û�д����˺�");
		printf("\n");
		printf("\t\t");
		system("pause");
		return login1();
	} else {
		User3 = fopen("User3.txt","r");
		printf("\t\t*����������ֻ���:[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%s",a.tnum);
		fscanf(User3,"%s",b.tnum);
		if((strcmp(a.tnum,b.tnum))==0) {
			User2 = fopen("User2.txt","r");
			User1 = fopen("User1.txt","r");
			fscanf(User2,"%s",d.password);
			fscanf(User1,"%s",c.name);
			printf("\t\t*�����˺�Ϊ:%s\n",c.name);
			printf("\t\t*��������Ϊ:%s\n",d.password);
			printf("\a\t\t");
			system("pause");
			return login1();
		} else {
			printf("\t\t\a*��������ֻ��Ų���ȷ��������ٴ�����\n");
			printf("\a\t\t");
			system("pause");
			return find();
		}
	}
}

void creatrole() {
	system("cls");
	printf("\a\t\t1.����Ϸ�Կ���,��֧�ִ���һ����ɫ,���ظ�������ɫ,���ˢ�´浵\n");
	printf("\a\t\t2.����Ϸ�Կ���,�Ա����������������޹ء�ְҵ�������й�\n");
	printf("\a");
	printf("\t\t");
	system("pause");
	system("cls");
	system("color 71");
	role a;
	int work;
	printf("\n");
	printf("\t\t����������Ϸ��ɫ��������");
	scanf("%s",a.uname);
	printf("\t\t����������Ϸ��ɫ���Ա�0���ԣ�1Ů�ԣ���");
	scanf("%d",&a.sex);
	printf("\t\t��ѡ������Ϸ��ɫ�����壨0���壬1ħ�壬2���壬3���飬4���壩��");
	scanf("%d",&a.race);
	work=getwork();
	a.work = work;
	getproperty(work,a);
	printf("\t\t��ɫ�����ɹ�");
	printf("\t\t\t\t");
	system("pause");
	system("cls");
	return login2();
}

int getwork() {
	int work;
	printf("\t\t��ѡ���������ɣ�0���ң�1��ң�2��ħ���壬3������4�����5����)��");
	scanf("%d",&work);
	return work;
}

void printproperty(role b) {
	FILE *fp;
	fp=fopen("��ɫ����.txt","w");
	printf("\n\n");
	printf("\t\t====================\n");
	printf("\t\t����\t%s\n",b.uname);
	fprintf(fp,"%s",b.uname);
	printf("\t\t====================\n");
	if(b.work==0) {
		printf("\t\t����	����\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==1) {
		printf("\t\t����	���\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==2) {
		printf("\t\t����	��ħ����\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==3) {
		printf("\t\t����	����\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==4) {
		printf("\t\t����	���\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==5) {
		printf("\t\t����	����\n");
		fprintf(fp,"\t%d",b.work);
	}
	printf("\t\t====================\n");
	if(b.sex==0) {
		printf("\t\t�Ա�	����\n");
		fprintf(fp,"\t%d",b.sex);
	} else {
		printf("\t\t�Ա�	Ů��\n");
		fprintf(fp,"\t%d",b.sex);
	}
	printf("\t\t====================\n");
	switch(b.race) {
		case 0: {
			printf("\t\t����	����\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 1: {
			printf("\t\t����	ħ��\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 2: {
			printf("\t\t����	����\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 3: {
			printf("\t\t����	������\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 4: {
			printf("\t\t����	����\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
	}
	printf("\t\t====================\n");
	printf("\t\t������	%d\n",b.power);
	fprintf(fp,"\t%d",b.power);
	printf("\t\t====================\n");
	printf("\t\t����ֵ	%lld\n",b.life);
	fprintf(fp,"\t%lld",b.life);
	printf("\t\t====================\n");
	printf("\t\t����ֵ	%d\n",b.magic);
	fprintf(fp,"\t%d",b.magic);
	printf("\t\t====================\n");
	printf("\t\t����	������\n");
	fprintf(fp,"\t%d",b.state);
	printf("\t\t====================\n");
	printf("\t\t����	%lld\n",b.exp);
	fprintf(fp,"\t%lld\n",b.exp);
	printf("\t\t====================\n");
	printf("\n\n");
	fclose(fp);
}

void getproperty(int work,role a) {
	srand(time(NULL));
	switch(work) {
		case 0: {
			a.power=rand()%3+22;
			a.magic=rand()%3+30;
			a.life=a.power*20;
			break;
		}
		case 1: {
			a.power=rand()%3+21;
			a.magic=rand()%3+25;
			a.life=a.power*23;
			break;
		}
		case 2: {
			a.power=rand()%3+37;
			a.magic=rand()%3+15;
			a.life=a.power*25;
			break;
		}
		case 3: {
			a.power=rand()%3+37;
			a.magic=rand()%3+20;
			a.life=a.power*20;
			break;
		}
		case 4: {
			a.power=rand()%3+15;
			a.magic=rand()%3+40;
			a.life=a.power*19;
			break;
		}
		case 5: {
			a.power=rand()%3+18;
			a.magic=rand()%3+45;
			a.life=a.power*20;
			break;
		}
	}
	printproperty(a);
}

void out() {
	system("cls");
	system("color 71");
	role a;
	FILE *fp;
	char c;
	fp = fopen("��ɫ����.txt","r");
	c=fgetc(fp);
	fclose(fp);
	if(c==EOF) {
		printf("\t\t��û�д�����ɫ,�봴����ɫ\n");
		printf("\t\t");
		system("pause");
		return login2();
	} else {
		fp = fopen("��ɫ����.txt","r");
		fscanf(fp,"%s\t%d\t%d\t%d\t%d\t%lld\t%d\t%d\t%lld",a.uname,&a.work,&a.sex,&a.race,&a.power,&a.life,&a.magic,&a.state,&a.exp);
		printf("\a\t\t����ǰ��Ϣ����:\n");
		printf("\t\t����:%s\n",a.uname);
		if(a.sex==0) {
			printf("\t\t�Ա�:����\n");
		} else {
			printf("\t\t�Ա�:Ů��\n");
		}
		if(a.race==0) {
			printf("\t\t��������Ϊ:����\n");
		} else if(a.race==1) {
			printf("\t\t��������Ϊ:ħ��\n");
		} else if(a.race==2) {
			printf("\t\t��������Ϊ:����\n");
		} else if(a.race==3) {
			printf("\t\t��������Ϊ:������\n");
		} else if(a.race==4) {
			printf("\t\t��������Ϊ:����\n");
		}
		if(a.work==0) {
			printf("\t\t����:����\n");
		} else if(a.work==1) {
			printf("\t\t����:���\n");
		} else if(a.work==2) {
			printf("\t\t����:��ħ����\n");
		} else if(a.work==3) {
			printf("\t\t����:Ϊ����\n");
		} else if(a.work==4) {
			printf("\t\t����:���\n");
		} else if(a.work==5) {
			printf("\t\t����:����\n");
		}
		if(a.state==0) {
			printf("\t\t����:������\n");
		} else if(a.state==1) {
			printf("\t\t����:�麣��\n");
		} else if(a.state==2) {
			printf("\t\t����:���Ǿ�\n");
		} else if(a.state==3) {
			printf("\t\t����:��ؾ�\n");
		} else if(a.state==4) {
			printf("\t\t����:���˾�\n");
		} else if(a.state==5) {
			printf("\t\t����:����\n");
		} else if(a.state==6) {
			printf("\t\t����:*����*\n");
		} else if(a.state==7) {
			printf("\t\t����:*ת�־�*\n");
		} else if(a.state==8) {
			printf("\t\t����:*���*\n");
		} else if(a.state==9) {
			printf("\t\t����:*���������*\n");
		} else if(a.state==10) {
			printf("\t\t����:**�ɵ���**\n");
		} else {
			printf("\t\t����:***����***\n");
		}
		printf("\t\t����ֵ:%lld\n",a.exp);
		printf("\t\t����ֵ:%lld\n",a.life);
		printf("\t\t������:%d\n",a.power);
		printf("\t\t����ֵ:%d\n",a.magic);
		printf("\t\t");
		fclose(fp);
		system("pause");
		return start();
	}
}

void out2() {
	system("cls");
	system("color 71");
	role a;
	FILE *fp;
	char c;
	fp = fopen("��ɫ����.txt","r");
	c=fgetc(fp);
	fclose(fp);
	if(c==EOF) {
		printf("\t\t��û�д�����ɫ,�봴����ɫ\n");
		printf("\t\t");
		system("pause");
		return login2();
	} else {
		fp = fopen("��ɫ����.txt","r");
		fscanf(fp,"%s\t%d\t%d\t%d\t%d\t%lld\t%d\t%d\t%lld",a.uname,&a.work,&a.sex,&a.race,&a.power,&a.life,&a.magic,&a.state,&a.exp);
		printf("\a\t\t����ǰ��Ϣ����:\n");
		printf("\t\t����:%s\n",a.uname);
		if(a.sex==0) {
			printf("\t\t�Ա�:����\n");
		} else {
			printf("\t\t�Ա�:Ů��\n");
		}
		if(a.race==0) {
			printf("\t\t��������Ϊ:����\n");
		} else if(a.race==1) {
			printf("\t\t��������Ϊ:ħ��\n");
		} else if(a.race==2) {
			printf("\t\t��������Ϊ:����\n");
		} else if(a.race==3) {
			printf("\t\t��������Ϊ:������\n");
		} else if(a.race==4) {
			printf("\t\t��������Ϊ:����\n");
		}
		if(a.work==0) {
			printf("\t\t����:����\n");
		} else if(a.work==1) {
			printf("\t\t����:���\n");
		} else if(a.work==2) {
			printf("\t\t����:��ħ����\n");
		} else if(a.work==3) {
			printf("\t\t����:Ϊ����\n");
		} else if(a.work==4) {
			printf("\t\t����:���\n");
		} else if(a.work==5) {
			printf("\t\t����:����\n");
		}
		if(a.state==0) {
			printf("\t\t����:������\n");
		} else if(a.state==1) {
			printf("\t\t����:�麣��\n");
		} else if(a.state==2) {
			printf("\t\t����:���Ǿ�\n");
		} else if(a.state==3) {
			printf("\t\t����:��ؾ�\n");
		} else if(a.state==4) {
			printf("\t\t����:���˾�\n");
		} else if(a.state==5) {
			printf("\t\t����:����\n");
		} else if(a.state==6) {
			printf("\t\t����:*����*\n");
		} else if(a.state==7) {
			printf("\t\t����:*ת�־�*\n");
		} else if(a.state==8) {
			printf("\t\t����:*���*\n");
		} else if(a.state==9) {
			printf("\t\t����:*���������*\n");
		} else if(a.state==10) {
			printf("\t\t����:**�ɵ���**\n");
		} else {
			printf("\t\t����:***����***\n");
		}
		printf("\t\t����ֵ:%lld\n",a.exp);
		printf("\t\t����ֵ:%lld\n",a.life);
		printf("\t\t������:%d\n",a.power);
		printf("\t\t����ֵ:%d\n",a.magic);
		printf("\t\t");
		fclose(fp);
	}
}


void login2() {
	fflush(stdin);//��������
	fflush(stdin);
	system("color 71");
	system("cls");
	printf("\t\t\t*************************************************************************\n");
	printf("\t\t\t*************************  ��������ϵͳ��ӭ��  **************************\n");
	printf("\t\t\t*************************************************************************\n");
	printf("\t\t\t*******************   ��ѡ�����Ĳ���(����Сд����)  *********************\n");
	printf("\t\t\t*************************************************************************\n");
	printf("       \t\t\t\t*****************    һ.��ɫ����    *****************\n");
	printf("       \t\t\t\t*****************    ��.��ʼ��Ϸ    *****************\n");
	printf("       \t\t\t\t*****************    ��.�˺��˳�    *****************\n");
	printf("       \t\t\t\t*****************************************************\n");
	printf(" \n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\aDesigned by zjx\n\n\n\n\n\n\n");
	printf("\t\t\t\t��������Ҫ���еĲ���:[\t]\b\b\b");
	int x;
	scanf("%d",&x);
	switch(x) {
		case 1:
			creatrole();
			break;
		case 2:
			system("cls");
			printf("\n\n");
			printf("\t\t\t\t\t��\t\t��\n");
			printf("\n\n");
			printf("\t\t\t\t\t��\t\t��\n");
			printf("\n\n");
			printf("\t\t\t\t\t��\t\t��\n");
			printf("\n\n");
			printf("\t\t\t\t\t��\t\t��\n");
			printf("\n\n");
			printf("\t\t\t\t\t��\t\t��\n");
			printf("\n\n\n\n\n");
			printf("\t\t\t\t\t");
			system("pause");
			start();
			break;
		case 3:
			system("cls");
			printf("\a\t\t\t\t�˺��˳��ɹ�\n");
			printf("\t\t\t\t");
			system("pause");
			login1();
			break;
		default:
			system("cls");
			printf("\a\t\t\t\t��������ȷ������\n");
			printf("\t\t\t\t");
			system("pause");
			return login2();
	}
}

void save(role b) {
	FILE *fp;
	fp=fopen("��ɫ����.txt","w");
	printf("\n\n\n\n");
	printf("\t\t\t\t====================\n");
	printf("\t\t\t\t����\t%s\n",b.uname);
	fprintf(fp,"%s",b.uname);
	printf("\t\t\t\t====================\n");
	if(b.work==0) {
		printf("\t\t\t\t����	����\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==1) {
		printf("\t\t\t\t����	���\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==2) {
		printf("\t\t\t\t����	��ħ����\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==3) {
		printf("\t\t\t\t����	����\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==4) {
		printf("\t\t\t\t����	���\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==5) {
		printf("\t\t\t\t����	����\n");
		fprintf(fp,"\t%d",b.work);
	}
	printf("\t\t\t\t====================\n");
	if(b.sex==0) {
		printf("\t\t\t\t�Ա�	����\n");
		fprintf(fp,"\t%d",b.sex);
	} else {
		printf("\t\t\t\t�Ա�	Ů��\n");
		fprintf(fp,"\t%d",b.sex);
	}
	printf("\t\t\t\t====================\n");
	switch(b.race) {
		case 0: {
			printf("\t\t\t\t����	����\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 1: {
			printf("\t\t\t\t����	ħ��\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 2: {
			printf("\t\t\t\t����	����\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 3: {
			printf("\t\t\t\t����	������\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 4: {
			printf("\t\t\t\t����	����\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
	}
	printf("\t\t\t\t====================\n");
	printf("\t\t\t\t������	%d\n",b.power);
	fprintf(fp,"\t%d",b.power);
	printf("\t\t\t\t====================\n");
	printf("\t\t\t\t����ֵ	%lld\n",b.life);
	fprintf(fp,"\t%lld",b.life);
	printf("\t\t\t\t====================\n");
	printf("\t\t\t\t����ֵ	%d\n",b.magic);
	fprintf(fp,"\t%d",b.magic);
	printf("\t\t\t\t====================\n");
	if(b.state==0) {
		printf("\t\t\t\t����:	������\n");
	} else if(b.state==1) {
		printf("\t\t\t\t����:	�麣��\n");
	} else if(b.state==2) {
		printf("\t\t\t\t����:	���Ǿ�\n");
	} else if(b.state==3) {
		printf("\t\t\t\t����:	��ؾ�\n");
	} else if(b.state==4) {
		printf("\t\t\t\t����:	���˾�\n");
	} else if(b.state==5) {
		printf("\t\t\t\t����:	����\n");
	} else if(b.state==6) {
		printf("\t\t\t\t����:	*����*\n");
	} else if(b.state==7) {
		printf("\t\t\t\t����:	*ת�־�*\n");
	} else if(b.state==8) {
		printf("\t\t\t\t����:	*���*\n");
	} else if(b.state==9) {
		printf("\t\t\t\t����:	*���������*\n");
	} else if(b.state==10) {
		printf("\t\t\t\t����:	**�ɵ���**\n");
	} else {
		printf("\t\t\t\t����:	***����***\n");
	}
	fprintf(fp,"\t%d",b.state);
	printf("\t\t\t\t====================\n");
	printf("\t\t\t\t����	%lld\n",b.exp);
	fprintf(fp,"\t%lld\n",b.exp);
	printf("\t\t\t\t====================\n");
	printf("\n\n");
	fclose(fp);
}


void start() {
	node *head = creatlist();
	fflush(stdin);//��������
	fflush(stdin);
	system("color 71");
	system("cls");
	system("cls");
	printf("\a\t\t\t*************************************************************************\n");
	printf("\t\t\t**************************   ��Ϸϵͳ��ӭ��   ***************************\n");
	printf("\t\t\t*************************************************************************\n");
	printf("\t\t\t*******************   ��ѡ�����Ĳ���(����Сд����)  *********************\n");
	printf("\t\t\t*************************************************************************\n");
	printf("       \t\t\t\t*****************    һ.��Ϸ˵��    *****************\n");
	printf("       \t\t\t\t*****************    ��.��ɫ��ѯ    *****************\n");
	printf("       \t\t\t\t*****************    ��.��������    *****************\n");
	printf("       \t\t\t\t*****************    ��.�������    *****************\n");
	printf("       \t\t\t\t*****************    ��.��Ϸ�޸�    *****************\n");
	printf("       \t\t\t\t*****************    ��.��ͼ�鿴    *****************\n");
	printf("       \t\t\t\t*****************    ��.��ͼ�༭    *****************\n");
	printf("       \t\t\t\t*****************    ��.��ͼ��ս    *****************\n");
	printf("       \t\t\t\t*****************    ��.�����ϼ�    *****************\n");
	printf("       \t\t\t\t*****************************************************\n");
	printf(" \n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\aDesigned by zjx\n\n\n\n\n\n\n");
	printf("\t\t\t\t��������Ҫ���еĲ���:[\t]\b\b\b");
	int x;
	scanf("%d",&x);
	switch(x) {
		case 1:
			help2();
			break;
		case 2:
			out();
			break;
		case 4:
			promote();
			break;
		case 3:
			exercise();
			break;
		case 5:
			gamechange();
			break;
		case 6:
			maplook(head);
			break;
		case 7:
			mapchange();
			break;
		case 8:
			mapselect(head);
			break;
		case 9:
			return login2();
			break;
		default:
			system("cls");
			printf("\a\t\t\t\t��������ȷ������\n");
			printf("\t\t\t\t");
			system("pause");
			return start();
	}
}


void help2() {
	system("cls");
	system("color 71");
	printf("\a");
	printf("\t\tһ.����12������,�ӵ͵�������Ϊ0.��������1.�麣����2.���Ǿ���3.��ؾ���4.���˾���5.���󾳡�6.���򾳡�7.ת�־���8.�����9.�����������10.�ɵ�����11.����\n");
	printf("\t\t��.ͨ�������������ɻ�þ���ֵ,������ֵ�ﵽһ���̶ȿ��Խ�������\n");
	printf("\t\t��.���˾����Ͻ���������һ������ʧ��,����Խ��ʧ�ܸ���Խ��\n");
	printf("\t\t��.�����װ�����Զ���װ\n");
	printf("\t\teg:�����ҵ����,������ͼʱ���˱��27,��������ս\n");
	printf("\t\t");
	system("pause");
	return start();
}

void exercise() {
	system("cls");
	FILE *fp;
	fp = fopen("��ɫ����.txt","r");
	char c;
	c=fgetc(fp);
	fclose(fp);
	if(c==EOF) {
		printf("\t\t��û�д�����ɫ,�봴����ɫ\n");
		printf("\t\t");
		system("pause");
		return login2();
	} else {
		system("cls");
		role b;
		FILE *fp;
		fp = fopen("��ɫ����.txt","r");
		fscanf(fp,"%s\t%d\t%d\t%d\t%d\t%lld\t%d\t%d\t%lld",b.uname,&b.work,&b.sex,&b.race,&b.power,&b.life,&b.magic,&b.state,&b.exp);
		fclose(fp);
		char c;
		int sum1 = 0;
		long long int sum2 = 0;
		int sum3 = 100;
		if(b.state<3) {
			sum3 = 100;
		} else if(b.state>=3&&b.state<=7) {
			sum3 = 1000;
		} else {
			sum3 = 5000;
		}
		int x1 = 1,x2 = 1,x3 = 1,x4 = 1;
		printf("\a\t\t\t\t**��ӭ������������ϵͳ(�����ĸ��ʵ��!)**\n\n");
		printf("\t\t\t\t*����<3 ����һ��exp+100;����<=7 ����һ��exp+1000;����>7 ����һ��exp+5000*\n\n");
		printf("\t\t\t\t���»س�����exp��~(����eֹͣ����)\n\n\n");
		while(1) {
			if((c = getch())=='\r') {
				sum1++;
				sum2 = sum2+sum3;
				b.exp = b.exp+sum3;
				printf("\t\t����%d��,exp������%lld\n",sum1,sum2);
			} else if(c=='m') {
				if(x1>0) {
					printf("\a\t\t��ϲ��,�������زʵ�1,exp����1000\n");
					b.exp = b.exp+1000;
					sum2 = sum2+1000;
					x1--;
				} else {
					printf("\t\t���Ļ������þ�\n");
				}
			} else if(c=='x') {
				if(x2>0) {
					printf("\a\t\t��ϲ��,�������زʵ�2,exp����1000\n");
					b.exp = b.exp+1000;
					sum2 = sum2+1000;
					x2--;
				} else {
					printf("\t\t���Ļ������þ�\n");
				}
			} else if(c=='n') {
				if(x3>0) {
					printf("\a\t\t��ϲ��,�������زʵ�3,exp����1000\n");
					b.exp = b.exp+1000;
					sum2 = sum2+1000;
					x3--;
				} else {
					printf("\t\t���Ļ������þ�\n");
				}
			} else if(c=='b') {
				if(x4>0) {
					printf("\a\t\t��ϲ��,�������زʵ�4,exp����1000\n");
					b.exp = b.exp+1000;
					sum2 = sum2+1000;
					x4--;
				} else {
					printf("\t\t���Ļ������þ�\n");
				}
			} else if(c=='e') {
				break;
			}
		}
		save(b);
		printf("\t\t");
		system("pause");
		return start();
	}
}

void promote() {
	fflush(stdin);//��������
	fflush(stdin);
	system("cls");
	FILE *fp;
	fp = fopen("��ɫ����.txt","r");
	char c;
	c=fgetc(fp);
	fclose(fp);
	if(c==EOF) {
		printf("\t\t��û�д�����ɫ,�봴����ɫ\n");
		printf("\t\t");
		system("pause");
		return login2();
	} else {
		system("cls");
		role b;
		fp = fopen("��ɫ����.txt","r");
		fscanf(fp,"%s\t%d\t%d\t%d\t%d\t%lld\t%d\t%d\t%lld",b.uname,&b.work,&b.sex,&b.race,&b.power,&b.life,&b.magic,&b.state,&b.exp);
		fclose(fp);
		if(b.state==0) {
			printf("\a\t\t����ǰ�ľ���Ϊ���������Ƿ�Ҫ����Ϊ�麣��(����1Wexp)?(0����,1ȡ��)\n");
			int x;
			printf("\t\t��������Ҫ���еĲ���:[\t]\b\b\b");
			scanf("%d",&x);
			if(b.exp>=10000) {
				switch(x) {
					case 0:
						++b.state;
						b.life=b.life*2;
						b.power=b.power*2;
						b.magic=b.magic*2;
						b.exp=b.exp-10000;
						printf("\a\t\t�ɽٳɹ�\n");
						printf("\t\t���Ľ�ɫ��Ϣ����\n");
						save(b);
						printf("\t\t");
						system("pause");
						return start();
					case 1:
						return start();
						break;
					default:
						printf("\t\t��������ȷ������\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t���ľ���ֵ����,��Ŭ����������ֵ\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==1) {
			printf("\a\t\t����ǰ�ľ���Ϊ�麣�����Ƿ�Ҫ����Ϊ���Ǿ�(����5Wexp)?(0����,1ȡ��)\n");
			int x;
			printf("\t\t��������Ҫ���еĲ���:[\t]\b\b\b");
			scanf("%d",&x);
			if(b.exp>=50000) {
				switch(x) {
					case 0:
						++b.state;
						b.life=b.life*2;
						b.power=b.power*2;
						b.magic=b.magic*2;
						b.exp=b.exp-50000;
						printf("\a\t\t�ɽٳɹ�\n");
						printf("\t\t���Ľ�ɫ��Ϣ����\n");
						save(b);
						printf("\t\t");
						system("pause");
						return start();
					case 1:
						return start();
						break;
					default:
						printf("\t\t��������ȷ������\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t���ľ���ֵ����,��Ŭ����������ֵ\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==2) {
			printf("\a\t\t����ǰ�ľ���Ϊ���Ǿ����Ƿ�Ҫ����Ϊ��ؾ�(����10Wexp)?(0����,1ȡ��)\n");
			int x;
			printf("\t\t��������Ҫ���еĲ���:[\t]\b\b\b");
			scanf("%d",&x);
			if(b.exp>=100000) {
				switch(x) {
					case 0:
						++b.state;
						b.life=b.life*2;
						b.power=b.power*2;
						b.magic=b.magic*2;
						b.exp=b.exp-100000;
						printf("\a\t\t�ɽٳɹ�\n");
						printf("\t\t���Ľ�ɫ��Ϣ����\n");
						save(b);
						printf("\t\t");
						system("pause");
						return start();
					case 1:
						return start();
						break;
					default:
						printf("\t\t��������ȷ������\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t���ľ���ֵ����,��Ŭ����������ֵ\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==3) {
			printf("\a\t\t����ǰ�ľ���Ϊ��ؾ����Ƿ�Ҫ����Ϊ���˾�(����15Wexp)?(0����,1ȡ��)\n");
			int x;
			printf("\t\t��������Ҫ���еĲ���:[\t]\b\b\b");
			scanf("%d",&x);
			if(b.exp>=150000) {

				switch(x) {
					case 0:
						++b.state;
						b.life=b.life*2;
						b.power=b.power*2;
						b.magic=b.magic*2;
						b.exp=b.exp-150000;
						printf("\a\t\t�ɽٳɹ�\n");
						printf("\t\t���Ľ�ɫ��Ϣ����\n");
						save(b);
						printf("\t\t");
						system("pause");
						return start();
					case 1:
						return start();
						break;
					default:
						printf("\t\t��������ȷ������\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t���ľ���ֵ����,��Ŭ����������ֵ\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==4) {
			printf("\a\t\t����ǰ�ľ���Ϊ���˾����Ƿ�Ҫ����Ϊ����(����20Wexp)?(0����,1ȡ��)\n");
			int x;
			printf("\t\t��������Ҫ���еĲ���:[\t]\b\b\b");
			scanf("%d",&x);
			if(b.exp>=200000) {
				switch(x) {
					case 0:
						b.exp=b.exp-200000;
						int n;
						srand(time(0));
						n = 1+rand()%(10-1+1);
						if(n>=1&&n<=9) {
							++b.state;
							b.life=b.life*2;
							b.power=b.power*2;
							b.magic=b.magic*2;
							printf("\t\t�ɽٳɹ�\n");
							printf("\t\t���Ľ�ɫ��Ϣ����\n");
							save(b);
							printf("\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							b.exp=b.exp-200000;
							save(b);
							printf("\t\t");
							system("pause");
						}
					case 1:
						return start();
						break;
					default:
						printf("\t\t��������ȷ������\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t���ľ���ֵ����,��Ŭ����������ֵ\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==5) {
			printf("\a\t\t����ǰ�ľ���Ϊ���󾳣��Ƿ�Ҫ����Ϊ����(����25Wexp)?(0����,1ȡ��)\n");
			int x;
			printf("\t\t��������Ҫ���еĲ���:[\t]\b\b\b");
			scanf("%d",&x);
			if(b.exp>=250000) {
				switch(x) {
					case 0:
						b.exp=b.exp-250000;
						int n;
						srand(time(0));
						n = 1+rand()%(10-1+1);
						if(n>=2&&n<=9) {
							++b.state;
							b.life=b.life*2;
							b.power=b.power*2;
							b.magic=b.magic*2;
							printf("\t\t�ɽٳɹ�\n");
							printf("\t\t���Ľ�ɫ��Ϣ����\n");
							save(b);
							printf("\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							b.exp=b.exp-250000;
							save(b);
							printf("\t\t");
							system("pause");
						}
					case 1:
						return start();
						break;
					default:
						printf("\t\t��������ȷ������\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t���ľ���ֵ����,��Ŭ����������ֵ\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==6) {
			printf("\a\t\t����ǰ�ľ���Ϊ���򾳣��Ƿ�Ҫ����Ϊת�־�(����30Wexp)?(0����,1ȡ��)\n");
			int x;
			printf("\t\t��������Ҫ���еĲ���:[\t]\b\b\b");
			scanf("%d",&x);
			if(b.exp>=300000) {
				switch(x) {
					case 0:
						b.exp=b.exp-300000;
						int n;
						srand(time(0));
						n = 1+rand()%(10-1+1);
						if(n>=3&&n<=9) {
							++b.state;
							b.life=b.life*2;
							b.power=b.power*2;
							b.magic=b.magic*2;
							printf("\t\t�ɽٳɹ�\n");
							printf("\t\t���Ľ�ɫ��Ϣ����\n");
							save(b);
							printf("\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							b.exp=b.exp-300000;
							save(b);
							printf("\t\t");
							system("pause");
						}
					case 1:
						return start();
						break;
					default:
						printf("\t\t��������ȷ������\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t���ľ���ֵ����,��Ŭ����������ֵ\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==7) {
			printf("\a\t\t����ǰ�ľ���Ϊת�־����Ƿ�Ҫ����Ϊ���(����40Wexp)?(0����,1ȡ��)\n");
			int x;
			printf("\t\t��������Ҫ���еĲ���:[\t]\b\b\b");
			scanf("%d",&x);
			if(b.exp>=400000) {
				switch(x) {
					case 0:
						b.exp=b.exp-400000;
						int n;
						srand(time(0));
						n = 1+rand()%(10-1+1);
						if(n>=4&&n<=9) {
							++b.state;
							b.life=b.life*2;
							b.power=b.power*2;
							b.magic=b.magic*2;
							printf("\t\t�ɽٳɹ�\n");
							printf("\t\t���Ľ�ɫ��Ϣ����\n");
							save(b);
							printf("\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							b.exp=b.exp-400000;
							save(b);
							printf("\t\t");
							system("pause");
						}
					case 1:
						return start();
						break;
					default:
						printf("\t\t��������ȷ������\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t���ľ���ֵ����,��Ŭ����������ֵ\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==8) {
			printf("\a\t\t����ǰ�ľ���Ϊ������Ƿ�Ҫ����Ϊ���������(����50Wexp)?(0����,1ȡ��)\n");
			int x;
			printf("\t\t��������Ҫ���еĲ���:[\t]\b\b\b");
			scanf("%d",&x);
			if(b.exp>=500000) {
				switch(x) {
					case 0:
						b.exp=b.exp-500000;
						int n;
						srand(time(0));
						n = 1+rand()%(10-1+1);
						if(n>=5&&n<=9) {
							++b.state;
							b.power=b.power*2;
							b.magic =b.magic*2;
							printf("\t\t�ɽٳɹ�\n");
							printf("\t\t���Ľ�ɫ��Ϣ����\n");
							save(b);
							printf("\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							printf("\t\t�ɽ�ʧ��,�����Ŭ��\n");
							b.exp=b.exp-500000;
							save(b);
							printf("\t\t");
							system("pause");
						}
					case 1:
						return start();
						break;
					default:
						printf("\t\t��������ȷ������\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t���ľ���ֵ����,��Ŭ����������ֵ\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==9) {
			printf("\a\t\t����ǰ�ľ���Ϊ������������Ƿ�Ҫ����Ϊ�ɵ���(����100Wexp)?(0����,1ȡ��)\n");
			printf("\t\tҪ��:������ֵ����20w����������1.5w������ֵ����1w\n");
			int x;
			printf("\t\t��������Ҫ���еĲ���:[\t]\b\b\b");
			scanf("%d",&x);
			if(b.exp>=1000000) {
				switch(x) {
					case 0:
						b.exp=b.exp-1000000;
						if((b.life>=200000&&b.power>=15000)||(b.life>=150000&&b.magic>=10000)) {
							++b.state;
							b.life = b.life*9;
							b.power = b.power*9;
							b.magic = b.magic*9;
							printf("\t\t�ɽٳɹ�\n");
							printf("\t\t���Ľ�ɫ��Ϣ����\n");
							save(b);
							printf("\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t");
							system("pause");
						}
					case 1:
						return start();
						break;
					default:
						printf("\t\t��������ȷ������\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t���ľ���ֵ����,��Ŭ����������ֵ\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==10) {
			printf("\a\t\t����ǰ�ľ���Ϊ�ɵ������Ƿ�Ҫ����Ϊ����(����200Wexp)?(0����,1ȡ��)\n");
			printf("\t\tҪ��:������ֵ����200w�ڹ���������10w������ֵ����5w\n");
			printf("\t\t��������Ҫ���еĲ���:[\t]\b\b\b");
			int x;
			scanf("%d",&x);
			if(b.exp>=2000000) {
				switch(x) {
					case 0:
						b.exp=b.exp-2000000;
						if((b.life>=2000000&&b.power>=100000)||(b.life>=2000000&&b.magic>=50000)) {
							++b.state;
							b.life = b.life*9;
							b.power = b.power*9;
							b.magic = b.magic*9;
							printf("\t\t�ɽٳɹ�\n");
							printf("\t\t���Ľ�ɫ��Ϣ����\n");
							save(b);
							printf("\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t�������Ͻ�������,�����Ŭ��\n");
							printf("\t\t");
							system("pause");
						}
					case 1:
						return start();
						break;
					default:
						printf("\t\t��������ȷ������\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t���ľ���ֵ����,��Ŭ����������ֵ\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state>=11) {
			printf("\t\t������������֮��,ִ��һ�д��,����һ��\n");
			printf("\t\t");
			system("pause");
			return start();
		}
	}
}


void gamechange() {
	char c;
	FILE *fp;
	fp = fopen("��ɫ����.txt","r");
	c=fgetc(fp);
	fclose(fp);
	if(c==EOF) {
		printf("\t\t��û�д�����ɫ,�봴����ɫ\n");
		printf("\t\t");
		system("pause");
		return login2();
	} else {
		system("cls");
		printf("\a\t\t\t\t����,���Ƿ����������\n\n\n\n");
		printf("\a\t\t\t\t����mxnb������Ұ�\n");
		printf("\t\t\t\t�ٱ������������!!ǧ�����������!!\n");
		char a,b,c,d;
		if((a=getch())=='m') {
			printf("\t\t\t\tm");
			if((b=getch())=='x') {
				printf("x");
				if((c=getch())=='n') {
					printf("n");
					if((d=getch())=='b') {
						printf("b\n");
						printf("\a\t\t\t\t������Ҽ���ɹ�\n");
						printf("\t\t\t\t");
						system("pause");
						return inchange();
					} else {
						printf("\n\t\t\t\t������İ��Ų���ȷ��\n");
						printf("\t\t\t\t");
						system("pause");
						return start();

					}
				} else {
					printf("\n\t\t\t\t������İ��Ų���ȷ��\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
			} else {
				printf("\n\t\t\t\t������İ��Ų���ȷ��\n");
				printf("\t\t\t\t");
				system("pause");
				return start();
			}
		} else {
			printf("\n\t\t\t\t������İ��Ų���ȷ��\n");
			printf("\t\t\t\t");
			system("pause");
			return start();
		}
	}
}

void inchange() {
	fflush(stdin);//��������
	fflush(stdin);
	out2();
	FILE *fp;
	fp = fopen("��ɫ����.txt","r");
	role a;
	fscanf(fp,"%s\t%d\t%d\t%d\t%d\t%lld\t%d\t%d\t%lld",a.uname,&a.work,&a.sex,&a.race,&a.power,&a.life,&a.magic,&a.state,&a.exp);
	printf("\a\t\t\t\t��ѡ����Ҫ�޸ĵ�����:\n");
	printf("\t\t\t\t1.exp�޸�\n");
	printf("\t\t\t\t2.����ֵ�޸�\n");
	printf("\t\t\t\t3.�������޸�\n");
	printf("\t\t\t\t4.�����޸�\n");
	printf("\t\t\t\t5.�����޸�(�����������)\n");
	printf("\t\t\t\t6.�˳����\n");
	int x;
	printf("\t\t\t\t");
	scanf("%d",&x);
	switch(x) {
		case 1:
			system("cls");
			printf("\t\t\t\t��������Ҫ���ĵ�exp��ֵ:");
			scanf("%lld",&a.exp);
			printf("\a\t\t\t\t�޸ĳɹ�\n");
			save(a);
			printf("\t\t\t\t");
			system("pause");
			return inchange();
			break;
		case 2:
			system("cls");
			printf("\t\t\t\t��������Ҫ���ĵ�����ֵ:");
			scanf("%lld",&a.life);
			printf("\a\t\t\t\t�޸ĳɹ�\n");
			save(a);
			printf("\t\t\t\t");
			system("pause");
			return inchange();
			break;
		case 3:
			system("cls");
			printf("\t\t\t\t��������Ҫ���ĵĹ�����:");
			scanf("%d",&a.power);
			printf("\a\t\t\t\t�޸ĳɹ�\n");
			save(a);
			printf("\t\t\t\t");
			system("pause");
			return inchange();
			break;
		case 4:
			system("cls");
			printf("\t\t\t\t��������Ҫ���ĵ�����:");
			scanf("%d",&a.magic);
			printf("\a\t\t\t\t�޸ĳɹ�\n");
			save(a);
			printf("\t\t\t\t");
			system("pause");
			return inchange();
			break;
		case 5:
			system("cls");
			printf("\t\t\t\t��������Ҫ���ĵľ���(0-11)");
			scanf("%d",&a.state);
			save(a);
			printf("\t\t\t\t");
			system("pause");
			return inchange();
			break;
		case 6:
			system("cls");
			printf("\t\t\t\t");
			printf("\n");
			system("pause");
			return start();
			break;
		default:
			printf("\a\t\t\t\t��������ȷ��ѡ��\n");
			printf("\t\t\t\t");
			system("pause");
			return inchange();

	}
}

node *creatlist() {
	node *head = (struct Node*)malloc(sizeof(struct Node));
	head->next = NULL;
	return head;
}

node *creatnode(mapr a) {
	node *newnode = (node*)malloc(sizeof(node));
	newnode->a = a;
	newnode->next = NULL;
	return newnode;
}

void insertbyend(node *head,mapr a) {
	node *posnode = head;
	node *newnode = creatnode(a);
	while(posnode->next!=NULL) {
		posnode = posnode->next;
	}
	posnode->next = newnode;
}

void maplook(node *head) {
	system("cls");
	FILE *fp;
	mapr a;
	fp = fopen("map.txt","r");
	while (!feof(fp)) {
		fscanf(fp,"%s\t%d\t%lld\t%d\t%d\n",a.rname,&a.rpower,&a.rlife,&a.state1,&a.num1);
		insertbyend(head,a);
	}
	fclose(fp);
	printlist(head);
}


void printlist(node *head) { //������
	node *pmove = head->next;
	while(pmove) {
		printf("���:%d\t",pmove->a.num1);
		printf("��ɫ��:%s\t",pmove->a.rname);
		printf("������:%d\t",pmove->a.rpower);
		printf("����ֵ:%lld\t",pmove->a.rlife);
		if(pmove->a.state1==0) {
			printf("����:������\n");
		}
		if(pmove->a.state1==1) {
			printf("����:�麣��\n");
		}
		if(pmove->a.state1==2) {
			printf("����:���Ǿ�\n");
		}
		if(pmove->a.state1==3) {
			printf("����:��ؾ�\n");
		}
		if(pmove->a.state1==4) {
			printf("����:���˾�\n");
		}
		if(pmove->a.state1==5) {
			printf("����:����\n");
		}
		if(pmove->a.state1==6) {
			printf("����:����\n");
		}
		if(pmove->a.state1==7) {
			printf("����:ת�־�\n");
		}
		if(pmove->a.state1==8) {
			printf("����:���\n");
		}
		if(pmove->a.state1==9) {
			printf("����:���������\n");
		}
		if(pmove->a.state1==10) {
			printf("����:�ɵ���\n");
		}
		if(pmove->a.state1==11) {
			printf("����:����\n");
		}
		printf("====================================================================================\n");
		pmove = pmove->next;
	}
	printf("\n");
	printf("\t\t\t\t");
	system("pause");
	return start();
}


void mapchange() {
	system("cls");
	FILE *fp;
	mapr a;
	fp = fopen("map.txt","a");
	printf("1.�������ɫ��\n");
	scanf("%s",&a.rname);
	printf("2.�����빥����\n");
	scanf("%d",&a.rpower);
	printf("3.����������ֵ\n");
	scanf("%lld",&a.rlife);
	printf("4.���趨����(0-11)\n");
	scanf("%d",&a.state1);
	printf("5.���趨���:\n");
	scanf("%d",&a.num1);
	fprintf(fp,"%s\t%d\t%lld\t%d\t%d\n",a.rname,a.rpower,a.rlife,a.state1,a.num1);
	fclose(fp);
	return start();
}

void mapselect(node *head) {
	fflush(stdin);//��������
	fflush(stdin);
	system("cls");
	FILE *fp1;
	mapr a;
	char c;
	fp1 = fopen("map.txt","r");
	FILE *fp2;
	fp2 = fopen("��ɫ����.txt","r");
	c = fgetc(fp2);
	fseek(fp2,0,SEEK_SET); //�����ļ����λ��
	role b,q;
	if(c==EOF) {
		printf("\a\t\t\t\t���ȴ�����ɫ\n");
		printf("\t\t\t\t");
		system("pause");
		return login2();
	} else {
		fscanf(fp2,"%s\t%d\t%d\t%d\t%d\t%lld\t%d\t%d\t%lld",b.uname,&b.work,&b.sex,&b.race,&b.power,&b.life,&b.magic,&b.state,&b.exp);
	}
	while (!feof(fp1)) {
		fscanf(fp1,"%s\t%d\t%lld\t%d\t%d\n",a.rname,&a.rpower,&a.rlife,&a.state1,&a.num1);
		insertbyend(head,a);
	}
	fclose(fp1);
	q.power = b.power;
	q.life = b.life;
	q.magic = b.magic;
	fclose(fp2);
	node *pmove = head->next;
	int n;
	printf("\t\t\t\teg:�����ҵ����,������ͼʱ���˱��27,��������ս\n\n");
	printf("\a\t\t\t\t��������Ҫ��ս�ĵ�ͼ���:");
	scanf("%d",&n);
	srand(time(NULL));
	while(pmove->a.num1!=n) {
		pmove = pmove->next;
		if(pmove==NULL) {
			printf("\a\t\t\t\t��������ȷ�ĵ�ͼ���\n");
			printf("\t\t\t\t");
			system("pause");
			return start();
		}
	}
	if(b.state==0) {
		system("cls");
		while(pmove->a.rlife>0) {
			int d = 0;
			int f;
			int e;
			int i;
			if(q.magic>0) {
				d = rand()%(3-1+1)+1;
				if(d<=2) {
					if(q.life>0) {
						q.magic=q.magic-20;
						f = rand()%(q.power*3-q.power*2+1)+q.power*2;
						printf("\t\t\t\t������ɽ����������\n");
						printf("\t\t\t\t��ʹ�����ؼ� *ȭ����* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����5000exp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+5000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����5000exp");
							b.exp = b.exp+5000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ���ֽ���,����ֵ+100,������+15,����+10**");
							b.life = b.life+100;
							b.power = b.power+15;
							b.magic = b.magic+10;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
					}
				} else {
					if(q.life>0) {
						f = rand()%(q.power*2-q.power+1)+q.power;
						printf("\t\t\t\t��ʹ����ͨ������%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����5000exp");
							b.exp = b.exp+5000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����5000exp");
							b.exp = b.exp+5000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ���ֽ���,����ֵ+100,������+15,����+10**");
							b.life = b.life+100;
							b.power = b.power+15;
							b.magic = b.magic+10;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				}
			} else {
				if(q.life>0) {
					f = rand()%(q.power*2-q.power+1)+q.power;
					printf("\t\t\t\t��ʹ����ͨ������%s�����%d���˺�\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("�������ս��,�����Ŭ��\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����5000exp");
						b.exp = b.exp+5000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����5000exp");
						b.exp = b.exp+5000;
						printf("\n");
						printf("\t\t\t\t**����ò������ˡ���ֽ���,����ֵ+100,������+15,����+10**");
						printf("\n");
						b.life = b.life+100;
						b.power = b.power+15;
						b.magic = b.magic+10;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					break;
				}
			}
		}
	} else if(b.state==1) {
		system("cls");
		while(pmove->a.rlife>0) {
			int d = 0;
			int f;
			int e;
			int i;
			if(q.magic>0) {
				d = rand()%(4-1+1)+1;
				if(d<2) {
					if(q.life>0) {
						q.magic=q.magic-40;
						f = rand()%(q.power*5-q.power*2+1)+q.power*2;
						printf("\t\t\t\t������ɽ����������\n");
						printf("\t\t\t\t��ʹ�����ؼ� *ȭ����* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����10000exp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+10000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����10000exp");
							b.exp = b.exp+10000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ���������,����ֵ+200,������+10,����+15**");
							b.life = b.life+200;
							b.power = b.power+10;
							b.magic = b.magic+15;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
					}
				} else {
					if(q.life>0) {
						f = rand()%(q.power*4-q.power*3+1)+q.power*3;
						printf("\t\t\t\t������麣����\n");
						printf("\t\t\t\t��ʹ�����ؼ� *�١���* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-50;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����10000exp");
							b.exp = b.exp+10000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����10000exp");
							b.exp = b.exp+10000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ���������,����ֵ+200,������+10,����+15**");
							b.life = b.life+200;
							b.power = b.power+10;
							b.magic = b.magic+15;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				}
			} else {
				if(q.life>0) {
					f = rand()%(q.power*2-q.power+1)+q.power;
					printf("\t\t\t\t��ʹ����ͨ������%s�����%d���˺�\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("�������ս��,�����Ŭ��");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����10000exp");
						b.exp = b.exp+10000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����10000exp");
						b.exp = b.exp+10000;
						printf("\n");
						printf("\t\t\t\t**����ò������ˡ���������,����ֵ+200,������+10,����+15**");
						printf("\n");
						b.life = b.life+200;
						b.power = b.power+10;
						b.magic = b.magic+15;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					break;
				}
			}
		}
	} else if(b.state==2) {
		system("cls");
		while(pmove->a.rlife>0) {
			int d = 0;
			int f;
			int e;
			int i;
			if(q.magic>0) {
				d = rand()%(4-1+1)+1;
				if(d<2) {
					if(q.life>0) {
						q.magic=q.magic-80;
						f = rand()%(q.power*6-q.power*4+1)+q.power*4;
						printf("\t\t\t\t������ĺ�����ڽ���\n");
						printf("\t\t\t\t��ʹ�����ؼ� *������ĺ* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����1.5wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+15000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����1.5wexp");
							b.exp = b.exp+15000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ���ҹѥ��,����ֵ+200,������+20,����+15**");
							b.life = b.life+200;
							b.power = b.power+20;
							b.magic = b.magic+15;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
					}
				} else {
					if(q.life>0) {
						f = rand()%(q.power*7-q.power*3+1)+q.power*3;
						printf("\t\t\t\t����Ҷ������ӭ�缲��\n");
						printf("\t\t\t\t��ʹ�����ؼ� *�١�����* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-85;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����1.5wexp");
							b.exp = b.exp+15000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����10000exp");
							b.exp = b.exp+10000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ���ҹѥ��,����ֵ+200,������+20,����+15**");
							b.life = b.life+200;
							b.power = b.power+20;
							b.magic = b.magic+15;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				}
			} else {
				if(q.life>0) {
					f = rand()%(q.power*2-q.power+1)+q.power;
					printf("\t\t\t\t��ʹ����ͨ������%s�����%d���˺�\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("�������ս��,�����Ŭ��");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����1.5wexp");
						b.exp = b.exp+15000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����1.5wexp");
						b.exp = b.exp+15000;
						printf("\n");
						printf("\t\t\t\t**����ò������ˡ���ҹѥ��,����ֵ+200,������+20,����+15**");
						printf("\n");
						b.life = b.life+200;
						b.power = b.power+20;
						b.magic = b.magic+15;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					break;
				}
			}
		}
	} else if(b.state==3) {
		system("cls");
		while(pmove->a.rlife>0) {
			int d = 0;
			int f;
			int e;
			int i;
			if(q.magic>0) {
				d = rand()%(4-1+1)+1;
				if(d<=2) {
					if(q.life>0) {
						q.magic=q.magic-200;
						f = rand()%(q.power*7-q.power*4+1)+q.power*2;
						printf("\t\t\t\t��������ɽ�ػ𾵡�\n");
						printf("\t\t\t\t��ʹ�����ؼ� *�����ػ�* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����2wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+20000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����2wexp");
							b.exp = b.exp+20000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ������𰡿,����ֵ+400,������+20,����+30**");
							b.life = b.life+400;
							b.power = b.power+20;
							b.magic = b.magic+30;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
					}
				} else {
					if(q.life>0) {
						f = rand()%(q.power*6-q.power*4+1)+q.power*3;
						printf("\t\t\t\t�����������ֱ��֡�\n");
						printf("\t\t\t\t��ʹ�����ؼ� *��������* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-210;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����2wexp");
							b.exp = b.exp+20000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����2wexp");
							b.exp = b.exp+20000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ������𰡿,����ֵ+400,������+20,����+30**");
							b.life = b.life+400;
							b.power = b.power+20;
							b.magic = b.magic+30;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				}
			} else {
				if(q.life>0) {
					f = rand()%(q.power*2-q.power+1)+q.power;
					printf("\t\t\t\t��ʹ����ͨ������%s�����%d���˺�\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("�������ս��,�����Ŭ��");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����2wexp");
						b.exp = b.exp+20000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����2wexp");
						b.exp = b.exp+20000;
						printf("\n");
						printf("\t\t\t\t**����ò������ˡ������𰡿,����ֵ+400,������+20,����+30**");
						printf("\n");
						b.life = b.life+400;
						b.power = b.power+20;
						b.magic = b.magic+30;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					break;
				}
			}
		}
	} else if(b.state==4) {
		system("cls");
		while(pmove->a.rlife>0) {
			int d = 0;
			int f;
			int e;
			int i;
			if(q.magic>0) {
				d = rand()%(4-1+1)+1;
				if(d<=2) {
					if(q.life>0) {
						q.magic=q.magic-420;
						f = rand()%(q.power*6-q.power*3+1)+q.power*3;
						printf("\t\t\t\t���������򲻻���\n");
						printf("\t\t\t\t��ʹ�����ؼ� *ȭ�����촷* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����3wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+30000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����3wexp");
							b.exp = b.exp+30000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ�������衿,����ֵ+400,������+40,����+30**");
							b.life = b.life+400;
							b.power = b.power+40;
							b.magic = b.magic+30;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
					}
				} else {
					if(q.life>0) {
						f = rand()%(q.power*7-q.power*1+1)+q.power*1;
						printf("\t\t\t\t��������ͬ�����ޡ�\n");
						printf("\t\t\t\t��ʹ�����ؼ�* ����������* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-450;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����3wexp");
							b.exp = b.exp+30000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����2wexp");
							b.exp = b.exp+20000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ�������衿,����ֵ+400,������+40,����+30**");
							b.life = b.life+400;
							b.power = b.power+40;
							b.magic = b.magic+30;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				}
			} else {
				if(q.life>0) {
					f = rand()%(q.power*2-q.power+1)+q.power;
					printf("\t\t\t\t��ʹ����ͨ������%s�����%d���˺�\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("�������ս��,�����Ŭ��");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����3wexp");
						b.exp = b.exp+30000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����3wexp");
						b.exp = b.exp+30000;
						printf("\n");
						printf("\t\t\t\t**����ò������ˡ�������衿,����ֵ+400,������+40,����+30**");
						printf("\n");
						b.life = b.life+400;
						b.power = b.power+40;
						b.magic = b.magic+30;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					break;
				}
			}
		}
	} else if(b.state==5) {
		system("cls");
		while(pmove->a.rlife>0) {
			int d = 0;
			int f;
			int e;
			int i;
			if(q.magic>0) {
				d = rand()%(4-1+1)+1;
				if(d<=2) {
					if(q.life>0) {
						q.magic=q.magic-660;
						f = rand()%(q.power*7-q.power*2+1)+q.power*2;
						printf("\t\t\t\t��������ɱ¾��,һ�����̤������\n");
						printf("\t\t\t\t��ʹ�����ؼ� *���١�����* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����3wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+30000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����3wexp");
							b.exp = b.exp+30000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ�����̫�����,����ֵ+800,������+50,����+50**");
							b.life = b.life+800;
							b.power = b.power+50;
							b.magic = b.magic+50;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
					}
				} else {
					if(q.life>0) {
						f = rand()%(q.power*6-q.power*3+1)+q.power*3;
						printf("\t\t\t\t��ǧ��·,ת����,�ݺ�׺����ƿա�\n");
						printf("\t\t\t\t��ʹ�����ؼ� *�񾳡��ƿ�* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-650;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����3wexp");
							b.exp = b.exp+30000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����2wexp");
							b.exp = b.exp+20000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ�����̫�����,����ֵ+800,������+50,����+50**");
							b.life = b.life+800;
							b.power = b.power+50;
							b.magic = b.magic+50;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				}
			} else {
				if(q.life>0) {
					f = rand()%(q.power*3-q.power+1)+q.power;
					printf("\t\t\t\t��ǧ�����󾹻��ա�\n");
					printf("\t\t\t\t��ʹ���� *���󡤻�* ��%s�����%d���˺�\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("�������ս��,�����Ŭ��");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����3wexp");
						b.exp = b.exp+30000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����3wexp");
						b.exp = b.exp+30000;
						printf("\n");
						printf("\t\t\t\t**����ò������ˡ�����̫�����,����ֵ+800,������+50,����+50**");
						printf("\n");
						b.life = b.life+800;
						b.power = b.power+50;
						b.magic = b.magic+50;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					break;
				}
			}
		}
	} else if(b.state==6) {
		system("cls");
		while(pmove->a.rlife>0) {
			int d = 0;
			int f;
			int e;
			int i;
			if(q.magic>0) {
				d = rand()%(4-1+1)+1;
				if(d<=2) {
					if(q.life>0) {
						q.magic=q.magic-1400;
						f = rand()%(q.power*5-q.power*3+1)+q.power;
						printf("\t\t\t\t��Ī��ɣ����΢ϼ�����졿\n");
						printf("\t\t\t\t��ʹ�����ؼ� *��ϼ��* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����5wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+50000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����5wexp");
							b.exp = b.exp+50000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ�����̫��ס�,����ֵ+1200,������+50,����+50**");
							b.life = b.life+1200;
							b.power = b.power+50;
							b.magic = b.magic+50;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
					}
				} else {
					if(q.life>0) {
						f = rand()%(q.power*5-q.power*3+1)+q.power*2;
						printf("\t\t\t\t��ʬɽѪ��ب���㣬�����Ž�ս�쳤��\n");
						printf("\t\t\t\t��ʹ�����ؼ� *�񽣡��쳤 *��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-1650;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����5wexp");
							b.exp = b.exp+50000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����5wexp");
							b.exp = b.exp+50000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ�����̫��ס�,����ֵ+1200,������+50,����+50**");
							b.life = b.life+1200;
							b.power = b.power+50;
							b.magic = b.magic+50;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				}
			} else {
				if(q.life>0) {
					f = rand()%(q.power*3-q.power+1)+q.power;
					printf("\t\t\t\t�������Ի�����\n");
					printf("\t\t\t\t��ʹ���� *������* ��%s�����%d���˺�\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("�������ս��,�����Ŭ��");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����5wexp");
						b.exp = b.exp+50000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����5wexp");
						b.exp = b.exp+50000;
						printf("\n");
						printf("\t\t\t\t**����ò������ˡ�����̫��ס�,����ֵ+1200,������+50,����+50**");
						printf("\n");
						b.life = b.life+1200;
						b.power = b.power+50;
						b.magic = b.magic+50;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					break;
				}
			}
		}
	} else if(b.state==7) {
		system("cls");
		while(pmove->a.rlife>0) {
			int d = 0;
			int f;
			int e;
			int i;
			if(q.magic>0) {
				d = rand()%(4-1+1)+1;
				if(d<=2) {
					if(q.life>0) {
						q.magic=q.magic-2200;
						f = rand()%(q.power*5-q.power*3+1)+q.power*2;
						printf("\t\t\t\t��ͷ���������£���̤��ɽ���\n");
						printf("\t\t\t\t��ʹ�����ؼ� *�������º�ɽ* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����10wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+100000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����10wexp");
							b.exp = b.exp+100000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ�����̫��ܡ�,����ֵ+1500,������+50,����+100**");
							b.life = b.life+1500;
							b.power = b.power+50;
							b.magic = b.magic+100;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
					}
				} else {
					if(q.life>0) {
						f = rand()%(q.power*5-q.power*3+1)+q.power*3;
						printf("\t\t\t\t��һ��תս��ǧ�һ����������ʦ��\n");
						printf("\t\t\t\t��ʹ�����ؼ� *�񽣡�����* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-2300;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����10wexp");
							b.exp = b.exp+100000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����10wexp");
							b.exp = b.exp+100000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ�����̫��ܡ�,����ֵ+1500,������+50,����+100**");
							b.life = b.life+1500;
							b.power = b.power+50;
							b.magic = b.magic+100;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				}
			} else {
				if(q.life>0) {
					f = rand()%(q.power*3-q.power+1)+q.power;
					printf("\t\t\t\t��ת�ְ�ʫ��\n");
					printf("\t\t\t\t��ʹ���� *ת�֡���Ϯ* ��%s�����%d���˺�\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("�������ս��,�����Ŭ��");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����10wexp");
						b.exp = b.exp+100000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����10wexp");
						b.exp = b.exp+100000;
						printf("\n");
						printf("\t\t\t\t**����ò������ˡ�����̫��ܡ�,����ֵ+1500,������+50,����+100**");
						printf("\n");
						b.life = b.life+1500;
						b.power = b.power+50;
						b.magic = b.magic+100;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					break;
				}
			}
		}
	} else if(b.state==8) {
		system("cls");
		while(pmove->a.rlife>0) {
			int d = 0;
			int f;
			int e;
			int i;
			if(q.magic>0) {
				d = rand()%(4-1+1)+1;
				if(d<=2) {
					if(q.life>0) {
						q.magic=q.magic-4000;
						f = rand()%(q.power*5-q.power*3+1)+q.power*2;
						printf("\t\t\t\t����ѩ�ƶˣ��������졿\n");
						printf("\t\t\t\t��ʹ�����ؼ� *�����������ƶ�* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����10wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+100000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����10wexp");
							b.exp = b.exp+100000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ�����̫���ġ�,����ֵ+1500,������+100,����+100**");
							b.life = b.life+1500;
							b.power = b.power+100;
							b.magic = b.magic+100;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
					}
				} else {
					if(q.life>0) {
						f = rand()%(q.power*5-q.power*3+1)+q.power*3;
						printf("\t\t\t\t���񵶻�����������ת���������硿\n");
						printf("\t\t\t\t��ʹ�����ؼ� *����������* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-4500;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����10wexp");
							b.exp = b.exp+100000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����10wexp");
							b.exp = b.exp+100000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ�����̫���ġ�,����ֵ+1500,������+100,����+100**");
							b.life = b.life+1500;
							b.power = b.power+100;
							b.magic = b.magic+100;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				}
			} else {
				if(q.life>0) {
					f = rand()%(q.power*3-q.power+1)+q.power;
					printf("\t\t\t\t������쿪�\n");
					printf("\t\t\t\t��ʹ���� *�������* ��%s�����%d���˺�\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("�������ս��,�����Ŭ��");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����10wexp");
						b.exp = b.exp+100000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����10wexp");
						b.exp = b.exp+100000;
						printf("\n");
						printf("\t\t\t\t**����ò������ˡ�����̫���ġ�,����ֵ+1500,������+100,����+100**");
						printf("\n");
						b.life = b.life+1500;
						b.power = b.power+100;
						b.magic = b.magic+100;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					break;
				}
			}
		}
	} else if(b.state==9) {
		system("cls");
		while(pmove->a.rlife>0) {
			int d = 0;
			int f;
			int e;
			int i;
			if(q.magic>0) {
				d = rand()%(5-1+1)+1;
				if(d<2) {
					if(q.life>0) {
						q.magic=q.magic-5000;
						f = rand()%(q.power*5-q.power*3+1)+q.power*2;
						printf("\t\t\t\t����·��ͷ˭Ϊ�壬�����ʼ���ɿա�\n");
						printf("\t\t\t\t��ʹ�����ؼ� *��������ɿ�* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+150000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ��롤�����ϡ�,����ֵ+3000,������+200,����+200**");
							b.life = b.life+1500;
							b.power = b.power+100;
							b.magic = b.magic+100;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
					}
				} else if(d>=2&&d<4) {
					if(q.life>0) {
						f = rand()%(q.power*5-q.power*4+1)+q.power*4;
						printf("\t\t\t\t��ǧ�ؽ٣������ѣ�����꣬ب�ŴҴҡ�\n");
						printf("\t\t\t\t��ʹ�����ؼ� *���ɡ�����* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-5500;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ��롤�����ϡ�,����ֵ+3000,������+200,����+200**");
							b.life = b.life+3000;
							b.power = b.power+200;
							b.magic = b.magic+200;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				} else {
					if(q.life>0) {
						f = rand()%(q.power*6-q.power*3+1)+q.power*3;
						printf("\t\t\t\t�����᱾�ԣ�����������᱾�ģ��������䡿\n");
						printf("\t\t\t\t��ʹ�����ؼ� *���ɡ�����* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-6000;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ��롤�����ϡ�,����ֵ+3000,������+200,����+200**");
							b.life = b.life+3000;
							b.power = b.power+200;
							b.magic = b.magic+200;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				}
			} else {
				if(q.life>0) {
					f = rand()%(q.power*3-q.power+1)+q.power;
					printf("\t\t\t\t���������ȥ��\n");
					printf("\t\t\t\t��ʹ���� *�������������* ��%s�����%d���˺�\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("�������ս��,�����Ŭ��");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����15wexp");
						b.exp = b.exp+150000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����15wexp");
						b.exp = b.exp+150000;
						printf("\n");
						printf("\t\t\t\t**����ò������ˡ��롤�����ϡ�,����ֵ+3000,������+200,����+200**");
						printf("\n");
						b.life = b.life+3000;
						b.power = b.power+200;
						b.magic = b.magic+200;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					break;
				}
			}
		}
	} else if(b.state==10) {
		system("cls");
		while(pmove->a.rlife>0) {
			int d = 0;
			int f;
			int e;
			int i;
			if(q.magic>0) {
				d = rand()%(6-1+1)+1;
				if(d<2) {
					if(q.life>0) {
						q.magic=q.magic-6000;
						f = rand()%(q.power*3-q.power*2+1)+q.power*2;
						printf("\t\t\t\t������������\n");
						printf("\t\t\t\t��ʹ�����ؼ� *��������* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+150000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ��������潣��,����ֵ+3000,������+500,����+300**");
							b.life = b.life+3000;
							b.power = b.power+500;
							b.magic = b.magic+300;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
					}
				} else if(d>=2&&d<4) {
					if(q.life>0) {
						f = rand()%(q.power*3-q.power*2+1)+q.power*2;
						printf("\t\t\t\t��������������ֳ�����\n");
						printf("\t\t\t\t��ʹ�����ؼ� *���� ��� ����* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-6000;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ��������潣��,����ֵ+3000,������+500,����+300**");
							b.life = b.life+3000;
							b.power = b.power+500;
							b.magic = b.magic+300;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				} else if(d>=4&&d<=5) {
					if(q.life>0) {
						f = rand()%(q.power*3-q.power*2+1)+q.power*2;
						printf("\t\t\t\t�������ֻأ����������ڡ�\n");
						printf("\t\t\t\t��ʹ�����ؼ� *����������* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-6000;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t\t\t**����ò������ˡ��������潣��,����ֵ+3000,������+500,����+300**");
							b.life = b.life+3000;
							b.power = b.power+500;
							b.magic = b.magic+300;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				}
			} else {
				if(q.life>0) {
					f = rand()%(q.power*3-q.power+1)+q.power;
					printf("\t\t\t\t��ִ��-������\n");
					printf("\t\t\t\t��ʹ���� *����������þ�* ��%s�����%d���˺�\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("�������ս��,�����Ŭ��");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����15wexp");
						b.exp = b.exp+150000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����15wexp");
						b.exp = b.exp+150000;
						printf("\n");
						printf("\t\t\t\t**����ò������ˡ��������潣��,����ֵ+3000,������+500,����+300**");
						printf("\n");
						b.life = b.life+3000;
						b.power = b.power+500;
						b.magic = b.magic+300;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					break;
				}
			}
		}
	} else if(b.state==11) {
		system("cls");
		while(pmove->a.rlife>0) {
			int d = 0;
			int f;
			int e;
			int i;
			if(q.magic>0) {
				d = rand()%(6-1+1)+1;
				if(d<2) {
					if(q.life>0) {
						q.magic=q.magic-150000;
						f = rand()%(q.power*3-q.power*2+1)+q.power*2;
						printf("\t\t\t\t����������֮�ϡ�\n");
						printf("\t\t\t\t��ʹ�����ؼ� *�������ɡ�����* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+150000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t**����ò������ˡ�������ʱ��֮�顿,����ֵ+10000,������+1000,����+1000**");
							b.life = b.life+10000;
							b.power = b.power+1000;
							b.magic = b.magic+1000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
					}
				} else if(d>=2&&d<4) {
					if(q.life>0) {
						f = rand()%(q.power*3-q.power*2+1)+q.power*2;
						printf("\t\t\t\t��������С������\n");
						printf("\t\t\t\t��ʹ�����ؼ� *�������ɡ�����* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-150000;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t**����ò������ˡ�������ʱ��֮�顿,����ֵ+10000,������+1000,����+1000**");
							b.life = b.life+10000;
							b.power = b.power+1000;
							b.magic = b.magic+1000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				} else if(d>=4&&d<=5) {
					if(q.life>0) {
						f = rand()%(q.power*3-q.power*2+1)+q.power*2;
						printf("\t\t\t\t������������\n");
						printf("\t\t\t\t��ʹ�����ؼ� *�������ɡ�˼ά����* ��%s�����%d���˺�\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-150000;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�������ս��,�����Ŭ��");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a��սʤ�˶���");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("�����15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t**����ò������ˡ�������ʱ��֮�顿,����ֵ+10000,������+1000,����+1000**");
							b.life = b.life+10000;
							b.power = b.power+1000;
							b.magic = b.magic+1000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						}
						break;
					}
				}
			} else {
				if(q.life>0) {
					f = rand()%(q.power*3-q.power+1)+q.power;
					printf("\t\t\t\t����·֮�ա�\n");
					printf("\t\t\t\t��ʹ���� *�������ɡ���ת�籩* ��%s�����%d���˺�\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*���ܵ�%d���˺�\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("�������ս��,�����Ŭ��");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����15wexp");
						b.exp = b.exp+150000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a��սʤ�˶���");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("�����15wexp");
						b.exp = b.exp+150000;
						printf("\n");
						printf("\t\t**����ò������ˡ�������ʱ��֮�顿,����ֵ+10000,������+1000,����+1000**");
						printf("\n");
						b.life = b.life+10000;
						b.power = b.power+1000;
						b.magic = b.magic+1000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					break;
				}
			}
		}
	}
}
