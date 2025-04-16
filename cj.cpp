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
	char uname[50];  //用户名
	int work;    //流派
	int sex;    //性别
	long long int life;   //生命值
	int power;   //攻击力
	int magic;   //灵力值
	int race;    //种族
	int state = 0;  //境界
	long long int exp = 0;  //经验值
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
	SetConsoleTitle("文字修仙 Designed by zjx");
	login1();
}

void help() {
	system("cls");
	system("color 71");
	printf("\a\a\a\a\a\a");
	printf("\t\t1.账号最多支持十位数字,若输入超过十位数字,请重新注册\n");
	printf("\t\t2.密码为六位数字\n");
	printf("\t\t3.手机号为找回功能,请认真填写\n");
	printf("\a\t\t");
	system("pause");
	system("cls");
}

void login1() {
	fflush(stdin);//清理缓冲区
	fflush(stdin);
	system("color 71");
	system("cls");
	printf("\t\t\t*************************************************************************\n");
	printf("\t\t\t***************************  账号系统欢迎您   ***************************\n");
	printf("\t\t\t*************************************************************************\n");
	printf("\t\t\t********************  请选择您的操作(输入小写数字)  *********************\n");
	printf("\t\t\t*************************************************************************\n");
	printf("       \t\t\t\t*****************    一.账号注册    *****************\n");
	printf("       \t\t\t\t*****************    二.账号登录    *****************\n");
	printf("       \t\t\t\t*****************    三.账号找回    *****************\n");
	printf("       \t\t\t\t*****************    四.退出系统    *****************\n");
	printf("       \t\t\t\t*****************************************************\n");
	printf(" \n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\aDesigned by zjx\n\n\n\n\n\n\n");
	printf("\t\t\t\t请输入您要进行的操作:[\t]\b\b\b");
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
			printf("\a\t\t\t\t即将退出系统\n");
			Sleep(1000);
			printf("\t\t\t\t");
			exit(0);
			break;
		default:
			system("cls");
			printf("\a\t\t\t\t请输入正确的数字\n");
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
	printf("\t\t**欢迎您进行账号注册**\n");
	printf("\t\t因技术限制,目前仅支持创建一个账号\n");
	usern a;
	userp b,c;
	usert d;
	FILE *user1 = fopen("User1.txt","w");
	FILE *user2,*user3;
	printf("\t\t*请输入您的账号(10位数字):[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",a.name);
	if((q=strlen(a.name))<=10) {
		fprintf(user1,"%s",a.name);
		printf("\a\t\t账号输入成功\n");
		printf("\a");
		printf("\t\t");
		system("pause");
		system("cls");
		fclose(user1);
	} else {
		printf("\t\t账号格式不符号规范,请重新注册\n");
		printf("\a");
		printf("\t\t");
		system("pause");
		return regist();
	}
	printf("\t\t*请输入您的手机号,以便于找回密码:[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",d.tnum);
	user3 = fopen("User3.txt","w");
	fprintf(user3,"%s",d.tnum);
	printf("\a\t\t*手机号输入成功\n");
	printf("\a");
	printf("\t\t");
	system("pause");
	system("cls");
	fclose(user3);
	while(1) {
		int time1 = 2;
		do {
			printf("\t\t*请设置密码(最多仅识别前六位):[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
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
			printf("\t\t*请确认密码:[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
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
				printf("\t\t*账号注册成功!\n");
				printf("\a");
				printf("\t\t");
				system("pause");
				fclose(user1);
				return login1();
			} else {
				if(time1!=0) {
					printf("\n\t\t两次输入的密码不相同！\t请重新输入(剩余%d次机会)\n",time1);
					time1--;
					continue;
				} else {
					printf("\n\t\t多次输入错误，即将退出！");
					printf("\a\t\t");
					system("pause");
					return ;
				}
			}
		} while(time1 >= 0);
	}
}

void signin() {
	fflush(stdin);//清理缓冲区
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
		printf("\a\t\t*您还没有创建账号\n");
		printf("\t\t");
		system("pause");
		return login1();
	} else {
		user1 = fopen("User1.txt","r");
		printf("\t\t**欢迎您进行账号登录!**\n\n");
		printf("\t\t*请输入您的账号:[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%s",a.name);
		fscanf(user1,"%s",&d);
		while(1) {
			if (strcmp(a.name,d.name)==0) {
				break;
			} else {
				printf("\t\t您输入的账号错误!\n");
				printf("\a\t\t");
				system("pause");
				fclose(user1);
				return signin();
			}
		}
		fclose(user1);
		printf("\t\t*请输入您的密码:[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
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
			printf("\a\t\t*登录成功!\n");
			fclose(user2);
			printf("\a");
			printf("\t\t");
			system("pause");
			return login2();
		} else {
			printf("\a\t\t您输入的密码错误!\n");
			printf("\t\t请于三秒后再次尝试");
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
		printf("\a\t\t*您还没有创建账号");
		printf("\n");
		printf("\t\t");
		system("pause");
		return login1();
	} else {
		User3 = fopen("User3.txt","r");
		printf("\t\t*请输入你的手机号:[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%s",a.tnum);
		fscanf(User3,"%s",b.tnum);
		if((strcmp(a.tnum,b.tnum))==0) {
			User2 = fopen("User2.txt","r");
			User1 = fopen("User1.txt","r");
			fscanf(User2,"%s",d.password);
			fscanf(User1,"%s",c.name);
			printf("\t\t*您的账号为:%s\n",c.name);
			printf("\t\t*您的密码为:%s\n",d.password);
			printf("\a\t\t");
			system("pause");
			return login1();
		} else {
			printf("\t\t\a*您输入的手机号不正确，请检查后再次输入\n");
			printf("\a\t\t");
			system("pause");
			return find();
		}
	}
}

void creatrole() {
	system("cls");
	printf("\a\t\t1.由游戏性考虑,仅支持创建一个角色,若重复创建角色,则会刷新存档\n");
	printf("\a\t\t2.由游戏性考虑,性别、种族均与初生属性无关、职业与属性有关\n");
	printf("\a");
	printf("\t\t");
	system("pause");
	system("cls");
	system("color 71");
	role a;
	int work;
	printf("\n");
	printf("\t\t请输入您游戏角色的姓名：");
	scanf("%s",a.uname);
	printf("\t\t请输入您游戏角色的性别（0男性，1女性）：");
	scanf("%d",&a.sex);
	printf("\t\t请选择您游戏角色的种族（0人族，1魔族，2神族，3精灵，4妖族）：");
	scanf("%d",&a.race);
	work=getwork();
	a.work = work;
	getproperty(work,a);
	printf("\t\t角色创建成功");
	printf("\t\t\t\t");
	system("pause");
	system("cls");
	return login2();
}

int getwork() {
	int work;
	printf("\t\t请选择您的流派（0道家，1佛家，2神魔炼体，3剑道，4阵道，5法道)；");
	scanf("%d",&work);
	return work;
}

void printproperty(role b) {
	FILE *fp;
	fp=fopen("角色属性.txt","w");
	printf("\n\n");
	printf("\t\t====================\n");
	printf("\t\t姓名\t%s\n",b.uname);
	fprintf(fp,"%s",b.uname);
	printf("\t\t====================\n");
	if(b.work==0) {
		printf("\t\t流派	道家\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==1) {
		printf("\t\t流派	佛家\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==2) {
		printf("\t\t流派	神魔炼体\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==3) {
		printf("\t\t流派	剑道\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==4) {
		printf("\t\t流派	阵道\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==5) {
		printf("\t\t流派	法道\n");
		fprintf(fp,"\t%d",b.work);
	}
	printf("\t\t====================\n");
	if(b.sex==0) {
		printf("\t\t性别	男性\n");
		fprintf(fp,"\t%d",b.sex);
	} else {
		printf("\t\t性别	女性\n");
		fprintf(fp,"\t%d",b.sex);
	}
	printf("\t\t====================\n");
	switch(b.race) {
		case 0: {
			printf("\t\t种族	人族\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 1: {
			printf("\t\t种族	魔族\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 2: {
			printf("\t\t种族	神族\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 3: {
			printf("\t\t种族	精灵族\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 4: {
			printf("\t\t种族	妖族\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
	}
	printf("\t\t====================\n");
	printf("\t\t攻击力	%d\n",b.power);
	fprintf(fp,"\t%d",b.power);
	printf("\t\t====================\n");
	printf("\t\t生命值	%lld\n",b.life);
	fprintf(fp,"\t%lld",b.life);
	printf("\t\t====================\n");
	printf("\t\t灵力值	%d\n",b.magic);
	fprintf(fp,"\t%d",b.magic);
	printf("\t\t====================\n");
	printf("\t\t境界	凡极境\n");
	fprintf(fp,"\t%d",b.state);
	printf("\t\t====================\n");
	printf("\t\t经验	%lld\n",b.exp);
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
	fp = fopen("角色属性.txt","r");
	c=fgetc(fp);
	fclose(fp);
	if(c==EOF) {
		printf("\t\t您没有创建角色,请创建角色\n");
		printf("\t\t");
		system("pause");
		return login2();
	} else {
		fp = fopen("角色属性.txt","r");
		fscanf(fp,"%s\t%d\t%d\t%d\t%d\t%lld\t%d\t%d\t%lld",a.uname,&a.work,&a.sex,&a.race,&a.power,&a.life,&a.magic,&a.state,&a.exp);
		printf("\a\t\t您当前信息如下:\n");
		printf("\t\t姓名:%s\n",a.uname);
		if(a.sex==0) {
			printf("\t\t性别:男性\n");
		} else {
			printf("\t\t性别:女性\n");
		}
		if(a.race==0) {
			printf("\t\t您的种族为:人族\n");
		} else if(a.race==1) {
			printf("\t\t您的种族为:魔族\n");
		} else if(a.race==2) {
			printf("\t\t您的种族为:神族\n");
		} else if(a.race==3) {
			printf("\t\t您的种族为:精灵族\n");
		} else if(a.race==4) {
			printf("\t\t您的种族为:妖族\n");
		}
		if(a.work==0) {
			printf("\t\t流派:道家\n");
		} else if(a.work==1) {
			printf("\t\t流派:佛家\n");
		} else if(a.work==2) {
			printf("\t\t流派:神魔炼体\n");
		} else if(a.work==3) {
			printf("\t\t流派:为剑道\n");
		} else if(a.work==4) {
			printf("\t\t流派:阵道\n");
		} else if(a.work==5) {
			printf("\t\t流派:法道\n");
		}
		if(a.state==0) {
			printf("\t\t境界:凡极境\n");
		} else if(a.state==1) {
			printf("\t\t境界:灵海境\n");
		} else if(a.state==2) {
			printf("\t\t境界:神魄境\n");
		} else if(a.state==3) {
			printf("\t\t境界:归藏境\n");
		} else if(a.state==4) {
			printf("\t\t境界:天人境\n");
		} else if(a.state==5) {
			printf("\t\t境界:万象境\n");
		} else if(a.state==6) {
			printf("\t\t境界:*化域境*\n");
		} else if(a.state==7) {
			printf("\t\t境界:*转轮境*\n");
		} else if(a.state==8) {
			printf("\t\t境界:*开宇境*\n");
		} else if(a.state==9) {
			printf("\t\t境界:*入道三基境*\n");
		} else if(a.state==10) {
			printf("\t\t境界:**成道境**\n");
		} else {
			printf("\t\t境界:***道尊境***\n");
		}
		printf("\t\t经验值:%lld\n",a.exp);
		printf("\t\t生命值:%lld\n",a.life);
		printf("\t\t攻击力:%d\n",a.power);
		printf("\t\t灵力值:%d\n",a.magic);
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
	fp = fopen("角色属性.txt","r");
	c=fgetc(fp);
	fclose(fp);
	if(c==EOF) {
		printf("\t\t您没有创建角色,请创建角色\n");
		printf("\t\t");
		system("pause");
		return login2();
	} else {
		fp = fopen("角色属性.txt","r");
		fscanf(fp,"%s\t%d\t%d\t%d\t%d\t%lld\t%d\t%d\t%lld",a.uname,&a.work,&a.sex,&a.race,&a.power,&a.life,&a.magic,&a.state,&a.exp);
		printf("\a\t\t您当前信息如下:\n");
		printf("\t\t姓名:%s\n",a.uname);
		if(a.sex==0) {
			printf("\t\t性别:男性\n");
		} else {
			printf("\t\t性别:女性\n");
		}
		if(a.race==0) {
			printf("\t\t您的种族为:人族\n");
		} else if(a.race==1) {
			printf("\t\t您的种族为:魔族\n");
		} else if(a.race==2) {
			printf("\t\t您的种族为:神族\n");
		} else if(a.race==3) {
			printf("\t\t您的种族为:精灵族\n");
		} else if(a.race==4) {
			printf("\t\t您的种族为:妖族\n");
		}
		if(a.work==0) {
			printf("\t\t流派:道家\n");
		} else if(a.work==1) {
			printf("\t\t流派:佛家\n");
		} else if(a.work==2) {
			printf("\t\t流派:神魔炼体\n");
		} else if(a.work==3) {
			printf("\t\t流派:为剑道\n");
		} else if(a.work==4) {
			printf("\t\t流派:阵道\n");
		} else if(a.work==5) {
			printf("\t\t流派:法道\n");
		}
		if(a.state==0) {
			printf("\t\t境界:凡极境\n");
		} else if(a.state==1) {
			printf("\t\t境界:灵海境\n");
		} else if(a.state==2) {
			printf("\t\t境界:神魄境\n");
		} else if(a.state==3) {
			printf("\t\t境界:归藏境\n");
		} else if(a.state==4) {
			printf("\t\t境界:天人境\n");
		} else if(a.state==5) {
			printf("\t\t境界:万象境\n");
		} else if(a.state==6) {
			printf("\t\t境界:*化域境*\n");
		} else if(a.state==7) {
			printf("\t\t境界:*转轮境*\n");
		} else if(a.state==8) {
			printf("\t\t境界:*开宇境*\n");
		} else if(a.state==9) {
			printf("\t\t境界:*入道三基境*\n");
		} else if(a.state==10) {
			printf("\t\t境界:**成道境**\n");
		} else {
			printf("\t\t境界:***道尊境***\n");
		}
		printf("\t\t经验值:%lld\n",a.exp);
		printf("\t\t生命值:%lld\n",a.life);
		printf("\t\t攻击力:%d\n",a.power);
		printf("\t\t灵力值:%d\n",a.magic);
		printf("\t\t");
		fclose(fp);
	}
}


void login2() {
	fflush(stdin);//清理缓冲区
	fflush(stdin);
	system("color 71");
	system("cls");
	printf("\t\t\t*************************************************************************\n");
	printf("\t\t\t*************************  文字修仙系统欢迎您  **************************\n");
	printf("\t\t\t*************************************************************************\n");
	printf("\t\t\t*******************   请选择您的操作(输入小写数字)  *********************\n");
	printf("\t\t\t*************************************************************************\n");
	printf("       \t\t\t\t*****************    一.角色创建    *****************\n");
	printf("       \t\t\t\t*****************    二.开始游戏    *****************\n");
	printf("       \t\t\t\t*****************    三.账号退出    *****************\n");
	printf("       \t\t\t\t*****************************************************\n");
	printf(" \n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\aDesigned by zjx\n\n\n\n\n\n\n");
	printf("\t\t\t\t请输入您要进行的操作:[\t]\b\b\b");
	int x;
	scanf("%d",&x);
	switch(x) {
		case 1:
			creatrole();
			break;
		case 2:
			system("cls");
			printf("\n\n");
			printf("\t\t\t\t\t仙\t\t结\n");
			printf("\n\n");
			printf("\t\t\t\t\t人\t\t发\n");
			printf("\n\n");
			printf("\t\t\t\t\t抚\t\t受\n");
			printf("\n\n");
			printf("\t\t\t\t\t我\t\t长\n");
			printf("\n\n");
			printf("\t\t\t\t\t顶\t\t生\n");
			printf("\n\n\n\n\n");
			printf("\t\t\t\t\t");
			system("pause");
			start();
			break;
		case 3:
			system("cls");
			printf("\a\t\t\t\t账号退出成功\n");
			printf("\t\t\t\t");
			system("pause");
			login1();
			break;
		default:
			system("cls");
			printf("\a\t\t\t\t请输入正确的数字\n");
			printf("\t\t\t\t");
			system("pause");
			return login2();
	}
}

void save(role b) {
	FILE *fp;
	fp=fopen("角色属性.txt","w");
	printf("\n\n\n\n");
	printf("\t\t\t\t====================\n");
	printf("\t\t\t\t姓名\t%s\n",b.uname);
	fprintf(fp,"%s",b.uname);
	printf("\t\t\t\t====================\n");
	if(b.work==0) {
		printf("\t\t\t\t流派	道家\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==1) {
		printf("\t\t\t\t流派	佛家\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==2) {
		printf("\t\t\t\t流派	神魔炼体\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==3) {
		printf("\t\t\t\t流派	剑道\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==4) {
		printf("\t\t\t\t流派	阵道\n");
		fprintf(fp,"\t%d",b.work);
	} else if(b.work==5) {
		printf("\t\t\t\t流派	法道\n");
		fprintf(fp,"\t%d",b.work);
	}
	printf("\t\t\t\t====================\n");
	if(b.sex==0) {
		printf("\t\t\t\t性别	男性\n");
		fprintf(fp,"\t%d",b.sex);
	} else {
		printf("\t\t\t\t性别	女性\n");
		fprintf(fp,"\t%d",b.sex);
	}
	printf("\t\t\t\t====================\n");
	switch(b.race) {
		case 0: {
			printf("\t\t\t\t种族	人族\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 1: {
			printf("\t\t\t\t种族	魔族\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 2: {
			printf("\t\t\t\t种族	神族\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 3: {
			printf("\t\t\t\t种族	精灵族\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
		case 4: {
			printf("\t\t\t\t种族	妖族\n");
			fprintf(fp,"\t%d",b.race);
			break;
		}
	}
	printf("\t\t\t\t====================\n");
	printf("\t\t\t\t攻击力	%d\n",b.power);
	fprintf(fp,"\t%d",b.power);
	printf("\t\t\t\t====================\n");
	printf("\t\t\t\t生命值	%lld\n",b.life);
	fprintf(fp,"\t%lld",b.life);
	printf("\t\t\t\t====================\n");
	printf("\t\t\t\t灵力值	%d\n",b.magic);
	fprintf(fp,"\t%d",b.magic);
	printf("\t\t\t\t====================\n");
	if(b.state==0) {
		printf("\t\t\t\t境界:	凡极境\n");
	} else if(b.state==1) {
		printf("\t\t\t\t境界:	灵海境\n");
	} else if(b.state==2) {
		printf("\t\t\t\t境界:	神魄境\n");
	} else if(b.state==3) {
		printf("\t\t\t\t境界:	归藏境\n");
	} else if(b.state==4) {
		printf("\t\t\t\t境界:	天人境\n");
	} else if(b.state==5) {
		printf("\t\t\t\t境界:	万象境\n");
	} else if(b.state==6) {
		printf("\t\t\t\t境界:	*化域境*\n");
	} else if(b.state==7) {
		printf("\t\t\t\t境界:	*转轮境*\n");
	} else if(b.state==8) {
		printf("\t\t\t\t境界:	*开宇境*\n");
	} else if(b.state==9) {
		printf("\t\t\t\t境界:	*入道三基境*\n");
	} else if(b.state==10) {
		printf("\t\t\t\t境界:	**成道境**\n");
	} else {
		printf("\t\t\t\t境界:	***道尊境***\n");
	}
	fprintf(fp,"\t%d",b.state);
	printf("\t\t\t\t====================\n");
	printf("\t\t\t\t经验	%lld\n",b.exp);
	fprintf(fp,"\t%lld\n",b.exp);
	printf("\t\t\t\t====================\n");
	printf("\n\n");
	fclose(fp);
}


void start() {
	node *head = creatlist();
	fflush(stdin);//清理缓冲区
	fflush(stdin);
	system("color 71");
	system("cls");
	system("cls");
	printf("\a\t\t\t*************************************************************************\n");
	printf("\t\t\t**************************   游戏系统欢迎您   ***************************\n");
	printf("\t\t\t*************************************************************************\n");
	printf("\t\t\t*******************   请选择您的操作(输入小写数字)  *********************\n");
	printf("\t\t\t*************************************************************************\n");
	printf("       \t\t\t\t*****************    一.游戏说明    *****************\n");
	printf("       \t\t\t\t*****************    二.角色查询    *****************\n");
	printf("       \t\t\t\t*****************    三.电子修炼    *****************\n");
	printf("       \t\t\t\t*****************    四.境界晋升    *****************\n");
	printf("       \t\t\t\t*****************    五.游戏修改    *****************\n");
	printf("       \t\t\t\t*****************    六.地图查看    *****************\n");
	printf("       \t\t\t\t*****************    七.地图编辑    *****************\n");
	printf("       \t\t\t\t*****************    八.地图挑战    *****************\n");
	printf("       \t\t\t\t*****************    九.返回上级    *****************\n");
	printf("       \t\t\t\t*****************************************************\n");
	printf(" \n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\aDesigned by zjx\n\n\n\n\n\n\n");
	printf("\t\t\t\t请输入您要进行的操作:[\t]\b\b\b");
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
			printf("\a\t\t\t\t请输入正确的数字\n");
			printf("\t\t\t\t");
			system("pause");
			return start();
	}
}


void help2() {
	system("cls");
	system("color 71");
	printf("\a");
	printf("\t\t一.共有12个境界,从低到高依次为0.凡极境、1.灵海境、2.神魄境、3.归藏境、4.天人境、5.万象境、6.化域境、7.转轮境、8.开宇境、9.入道三基境、10.成道境、11.道尊境\n");
	printf("\t\t二.通过修炼、副本可获得经验值,当经验值达到一定程度可以晋升境界\n");
	printf("\t\t三.天人境以上晋升境界有一定几率失败,境界越高失败概率越大\n");
	printf("\t\t四.掉落的装备会自动安装\n");
	printf("\t\teg:由于我的疏忽,制作地图时少了编号27,请往后挑战\n");
	printf("\t\t");
	system("pause");
	return start();
}

void exercise() {
	system("cls");
	FILE *fp;
	fp = fopen("角色属性.txt","r");
	char c;
	c=fgetc(fp);
	fclose(fp);
	if(c==EOF) {
		printf("\t\t您没有创建角色,请创建角色\n");
		printf("\t\t");
		system("pause");
		return login2();
	} else {
		system("cls");
		role b;
		FILE *fp;
		fp = fopen("角色属性.txt","r");
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
		printf("\a\t\t\t\t**欢迎来到赛博修炼系统(共有四个彩蛋嗷!)**\n\n");
		printf("\t\t\t\t*境界<3 修炼一次exp+100;境界<=7 修炼一次exp+1000;境界>7 修炼一次exp+5000*\n\n");
		printf("\t\t\t\t按下回车增加exp吧~(输入e停止修炼)\n\n\n");
		while(1) {
			if((c = getch())=='\r') {
				sum1++;
				sum2 = sum2+sum3;
				b.exp = b.exp+sum3;
				printf("\t\t修炼%d次,exp共增加%lld\n",sum1,sum2);
			} else if(c=='m') {
				if(x1>0) {
					printf("\a\t\t恭喜你,发现隐藏彩蛋1,exp增加1000\n");
					b.exp = b.exp+1000;
					sum2 = sum2+1000;
					x1--;
				} else {
					printf("\t\t您的机会已用尽\n");
				}
			} else if(c=='x') {
				if(x2>0) {
					printf("\a\t\t恭喜你,发现隐藏彩蛋2,exp增加1000\n");
					b.exp = b.exp+1000;
					sum2 = sum2+1000;
					x2--;
				} else {
					printf("\t\t您的机会已用尽\n");
				}
			} else if(c=='n') {
				if(x3>0) {
					printf("\a\t\t恭喜你,发现隐藏彩蛋3,exp增加1000\n");
					b.exp = b.exp+1000;
					sum2 = sum2+1000;
					x3--;
				} else {
					printf("\t\t您的机会已用尽\n");
				}
			} else if(c=='b') {
				if(x4>0) {
					printf("\a\t\t恭喜你,发现隐藏彩蛋4,exp增加1000\n");
					b.exp = b.exp+1000;
					sum2 = sum2+1000;
					x4--;
				} else {
					printf("\t\t您的机会已用尽\n");
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
	fflush(stdin);//清理缓冲区
	fflush(stdin);
	system("cls");
	FILE *fp;
	fp = fopen("角色属性.txt","r");
	char c;
	c=fgetc(fp);
	fclose(fp);
	if(c==EOF) {
		printf("\t\t您没有创建角色,请创建角色\n");
		printf("\t\t");
		system("pause");
		return login2();
	} else {
		system("cls");
		role b;
		fp = fopen("角色属性.txt","r");
		fscanf(fp,"%s\t%d\t%d\t%d\t%d\t%lld\t%d\t%d\t%lld",b.uname,&b.work,&b.sex,&b.race,&b.power,&b.life,&b.magic,&b.state,&b.exp);
		fclose(fp);
		if(b.state==0) {
			printf("\a\t\t您当前的境界为凡极境，是否要晋升为灵海境(消耗1Wexp)?(0晋级,1取消)\n");
			int x;
			printf("\t\t请输入您要进行的操作:[\t]\b\b\b");
			scanf("%d",&x);
			if(b.exp>=10000) {
				switch(x) {
					case 0:
						++b.state;
						b.life=b.life*2;
						b.power=b.power*2;
						b.magic=b.magic*2;
						b.exp=b.exp-10000;
						printf("\a\t\t渡劫成功\n");
						printf("\t\t您的角色信息如下\n");
						save(b);
						printf("\t\t");
						system("pause");
						return start();
					case 1:
						return start();
						break;
					default:
						printf("\t\t请输入正确的数字\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t您的经验值不足,请努力提升经验值\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==1) {
			printf("\a\t\t您当前的境界为灵海境，是否要晋升为神魄境(消耗5Wexp)?(0晋级,1取消)\n");
			int x;
			printf("\t\t请输入您要进行的操作:[\t]\b\b\b");
			scanf("%d",&x);
			if(b.exp>=50000) {
				switch(x) {
					case 0:
						++b.state;
						b.life=b.life*2;
						b.power=b.power*2;
						b.magic=b.magic*2;
						b.exp=b.exp-50000;
						printf("\a\t\t渡劫成功\n");
						printf("\t\t您的角色信息如下\n");
						save(b);
						printf("\t\t");
						system("pause");
						return start();
					case 1:
						return start();
						break;
					default:
						printf("\t\t请输入正确的数字\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t您的经验值不足,请努力提升经验值\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==2) {
			printf("\a\t\t您当前的境界为神魄境，是否要晋升为归藏境(消耗10Wexp)?(0晋级,1取消)\n");
			int x;
			printf("\t\t请输入您要进行的操作:[\t]\b\b\b");
			scanf("%d",&x);
			if(b.exp>=100000) {
				switch(x) {
					case 0:
						++b.state;
						b.life=b.life*2;
						b.power=b.power*2;
						b.magic=b.magic*2;
						b.exp=b.exp-100000;
						printf("\a\t\t渡劫成功\n");
						printf("\t\t您的角色信息如下\n");
						save(b);
						printf("\t\t");
						system("pause");
						return start();
					case 1:
						return start();
						break;
					default:
						printf("\t\t请输入正确的数字\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t您的经验值不足,请努力提升经验值\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==3) {
			printf("\a\t\t您当前的境界为归藏境，是否要晋升为天人境(消耗15Wexp)?(0晋级,1取消)\n");
			int x;
			printf("\t\t请输入您要进行的操作:[\t]\b\b\b");
			scanf("%d",&x);
			if(b.exp>=150000) {

				switch(x) {
					case 0:
						++b.state;
						b.life=b.life*2;
						b.power=b.power*2;
						b.magic=b.magic*2;
						b.exp=b.exp-150000;
						printf("\a\t\t渡劫成功\n");
						printf("\t\t您的角色信息如下\n");
						save(b);
						printf("\t\t");
						system("pause");
						return start();
					case 1:
						return start();
						break;
					default:
						printf("\t\t请输入正确的数字\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t您的经验值不足,请努力提升经验值\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==4) {
			printf("\a\t\t您当前的境界为天人境，是否要晋升为万象境(消耗20Wexp)?(0晋级,1取消)\n");
			int x;
			printf("\t\t请输入您要进行的操作:[\t]\b\b\b");
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
							printf("\t\t渡劫成功\n");
							printf("\t\t您的角色信息如下\n");
							save(b);
							printf("\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							b.exp=b.exp-200000;
							save(b);
							printf("\t\t");
							system("pause");
						}
					case 1:
						return start();
						break;
					default:
						printf("\t\t请输入正确的数字\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t您的经验值不足,请努力提升经验值\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==5) {
			printf("\a\t\t您当前的境界为万象境，是否要晋升为化域境(消耗25Wexp)?(0晋级,1取消)\n");
			int x;
			printf("\t\t请输入您要进行的操作:[\t]\b\b\b");
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
							printf("\t\t渡劫成功\n");
							printf("\t\t您的角色信息如下\n");
							save(b);
							printf("\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							b.exp=b.exp-250000;
							save(b);
							printf("\t\t");
							system("pause");
						}
					case 1:
						return start();
						break;
					default:
						printf("\t\t请输入正确的数字\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t您的经验值不足,请努力提升经验值\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==6) {
			printf("\a\t\t您当前的境界为化域境，是否要晋升为转轮境(消耗30Wexp)?(0晋级,1取消)\n");
			int x;
			printf("\t\t请输入您要进行的操作:[\t]\b\b\b");
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
							printf("\t\t渡劫成功\n");
							printf("\t\t您的角色信息如下\n");
							save(b);
							printf("\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							b.exp=b.exp-300000;
							save(b);
							printf("\t\t");
							system("pause");
						}
					case 1:
						return start();
						break;
					default:
						printf("\t\t请输入正确的数字\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t您的经验值不足,请努力提升经验值\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==7) {
			printf("\a\t\t您当前的境界为转轮境，是否要晋升为开宇境(消耗40Wexp)?(0晋级,1取消)\n");
			int x;
			printf("\t\t请输入您要进行的操作:[\t]\b\b\b");
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
							printf("\t\t渡劫成功\n");
							printf("\t\t您的角色信息如下\n");
							save(b);
							printf("\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							b.exp=b.exp-400000;
							save(b);
							printf("\t\t");
							system("pause");
						}
					case 1:
						return start();
						break;
					default:
						printf("\t\t请输入正确的数字\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t您的经验值不足,请努力提升经验值\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==8) {
			printf("\a\t\t您当前的境界为开宇境，是否要晋升为入道三基境(消耗50Wexp)?(0晋级,1取消)\n");
			int x;
			printf("\t\t请输入您要进行的操作:[\t]\b\b\b");
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
							printf("\t\t渡劫成功\n");
							printf("\t\t您的角色信息如下\n");
							save(b);
							printf("\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							printf("\t\t渡劫失败,请继续努力\n");
							b.exp=b.exp-500000;
							save(b);
							printf("\t\t");
							system("pause");
						}
					case 1:
						return start();
						break;
					default:
						printf("\t\t请输入正确的数字\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t您的经验值不足,请努力提升经验值\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==9) {
			printf("\a\t\t您当前的境界为入道三基境，是否要晋升为成道境(消耗100Wexp)?(0晋级,1取消)\n");
			printf("\t\t要求:①生命值大于20w攻击力大于1.5w或灵力值大于1w\n");
			int x;
			printf("\t\t请输入您要进行的操作:[\t]\b\b\b");
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
							printf("\t\t渡劫成功\n");
							printf("\t\t您的角色信息如下\n");
							save(b);
							printf("\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t");
							system("pause");
						}
					case 1:
						return start();
						break;
					default:
						printf("\t\t请输入正确的数字\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t您的经验值不足,请努力提升经验值\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state==10) {
			printf("\a\t\t您当前的境界为成道境，是否要晋升为道尊境(消耗200Wexp)?(0晋级,1取消)\n");
			printf("\t\t要求:①生命值大于200w②攻击力大于10w③灵力值大于5w\n");
			printf("\t\t请输入您要进行的操作:[\t]\b\b\b");
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
							printf("\t\t渡劫成功\n");
							printf("\t\t您的角色信息如下\n");
							save(b);
							printf("\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t您不符合晋升条件,请继续努力\n");
							printf("\t\t");
							system("pause");
						}
					case 1:
						return start();
						break;
					default:
						printf("\t\t请输入正确的数字\n");
						return promote();
						break;
				}
			} else {
				printf("\t\t您的经验值不足,请努力提升经验值\n");
				printf("\t\t");
				system("pause");
				return start();
			}
		}
		if(b.state>=11) {
			printf("\t\t您已立于诸天之巅,执掌一切大道,傲视一切\n");
			printf("\t\t");
			system("pause");
			return start();
		}
	}
}


void gamechange() {
	char c;
	FILE *fp;
	fp = fopen("角色属性.txt","r");
	c=fgetc(fp);
	fclose(fp);
	if(c==EOF) {
		printf("\t\t您没有创建角色,请创建角色\n");
		printf("\t\t");
		system("pause");
		return login2();
	} else {
		system("cls");
		printf("\a\t\t\t\t少年,你是否渴望力量？\n\n\n\n");
		printf("\a\t\t\t\t输入mxnb激活外挂吧\n");
		printf("\t\t\t\t百倍攻击输入就送!!千万经验输入就送!!\n");
		char a,b,c,d;
		if((a=getch())=='m') {
			printf("\t\t\t\tm");
			if((b=getch())=='x') {
				printf("x");
				if((c=getch())=='n') {
					printf("n");
					if((d=getch())=='b') {
						printf("b\n");
						printf("\a\t\t\t\t您的外挂激活成功\n");
						printf("\t\t\t\t");
						system("pause");
						return inchange();
					} else {
						printf("\n\t\t\t\t您输入的暗号不正确捏\n");
						printf("\t\t\t\t");
						system("pause");
						return start();

					}
				} else {
					printf("\n\t\t\t\t您输入的暗号不正确捏\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
			} else {
				printf("\n\t\t\t\t您输入的暗号不正确捏\n");
				printf("\t\t\t\t");
				system("pause");
				return start();
			}
		} else {
			printf("\n\t\t\t\t您输入的暗号不正确捏\n");
			printf("\t\t\t\t");
			system("pause");
			return start();
		}
	}
}

void inchange() {
	fflush(stdin);//清理缓冲区
	fflush(stdin);
	out2();
	FILE *fp;
	fp = fopen("角色属性.txt","r");
	role a;
	fscanf(fp,"%s\t%d\t%d\t%d\t%d\t%lld\t%d\t%d\t%lld",a.uname,&a.work,&a.sex,&a.race,&a.power,&a.life,&a.magic,&a.state,&a.exp);
	printf("\a\t\t\t\t请选择您要修改的属性:\n");
	printf("\t\t\t\t1.exp修改\n");
	printf("\t\t\t\t2.生命值修改\n");
	printf("\t\t\t\t3.攻击力修改\n");
	printf("\t\t\t\t4.灵力修改\n");
	printf("\t\t\t\t5.境界修改(不会更改属性)\n");
	printf("\t\t\t\t6.退出外挂\n");
	int x;
	printf("\t\t\t\t");
	scanf("%d",&x);
	switch(x) {
		case 1:
			system("cls");
			printf("\t\t\t\t请输入您要更改的exp数值:");
			scanf("%lld",&a.exp);
			printf("\a\t\t\t\t修改成功\n");
			save(a);
			printf("\t\t\t\t");
			system("pause");
			return inchange();
			break;
		case 2:
			system("cls");
			printf("\t\t\t\t请输入您要更改的生命值:");
			scanf("%lld",&a.life);
			printf("\a\t\t\t\t修改成功\n");
			save(a);
			printf("\t\t\t\t");
			system("pause");
			return inchange();
			break;
		case 3:
			system("cls");
			printf("\t\t\t\t请输入您要更改的攻击力:");
			scanf("%d",&a.power);
			printf("\a\t\t\t\t修改成功\n");
			save(a);
			printf("\t\t\t\t");
			system("pause");
			return inchange();
			break;
		case 4:
			system("cls");
			printf("\t\t\t\t请输入您要更改的灵力:");
			scanf("%d",&a.magic);
			printf("\a\t\t\t\t修改成功\n");
			save(a);
			printf("\t\t\t\t");
			system("pause");
			return inchange();
			break;
		case 5:
			system("cls");
			printf("\t\t\t\t请输入您要更改的境界(0-11)");
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
			printf("\a\t\t\t\t请输入正确的选项\n");
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


void printlist(node *head) { //输出结点
	node *pmove = head->next;
	while(pmove) {
		printf("编号:%d\t",pmove->a.num1);
		printf("角色名:%s\t",pmove->a.rname);
		printf("攻击力:%d\t",pmove->a.rpower);
		printf("生命值:%lld\t",pmove->a.rlife);
		if(pmove->a.state1==0) {
			printf("境界:凡极境\n");
		}
		if(pmove->a.state1==1) {
			printf("境界:灵海境\n");
		}
		if(pmove->a.state1==2) {
			printf("境界:神魄境\n");
		}
		if(pmove->a.state1==3) {
			printf("境界:归藏境\n");
		}
		if(pmove->a.state1==4) {
			printf("境界:天人境\n");
		}
		if(pmove->a.state1==5) {
			printf("境界:万象境\n");
		}
		if(pmove->a.state1==6) {
			printf("境界:化域境\n");
		}
		if(pmove->a.state1==7) {
			printf("境界:转轮境\n");
		}
		if(pmove->a.state1==8) {
			printf("境界:开宇境\n");
		}
		if(pmove->a.state1==9) {
			printf("境界:入道三基境\n");
		}
		if(pmove->a.state1==10) {
			printf("境界:成道境\n");
		}
		if(pmove->a.state1==11) {
			printf("境界:道尊境\n");
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
	printf("1.请输入角色名\n");
	scanf("%s",&a.rname);
	printf("2.请输入攻击力\n");
	scanf("%d",&a.rpower);
	printf("3.请输入生命值\n");
	scanf("%lld",&a.rlife);
	printf("4.请设定境界(0-11)\n");
	scanf("%d",&a.state1);
	printf("5.请设定编号:\n");
	scanf("%d",&a.num1);
	fprintf(fp,"%s\t%d\t%lld\t%d\t%d\n",a.rname,a.rpower,a.rlife,a.state1,a.num1);
	fclose(fp);
	return start();
}

void mapselect(node *head) {
	fflush(stdin);//清理缓冲区
	fflush(stdin);
	system("cls");
	FILE *fp1;
	mapr a;
	char c;
	fp1 = fopen("map.txt","r");
	FILE *fp2;
	fp2 = fopen("角色属性.txt","r");
	c = fgetc(fp2);
	fseek(fp2,0,SEEK_SET); //设置文件光标位置
	role b,q;
	if(c==EOF) {
		printf("\a\t\t\t\t请先创建角色\n");
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
	printf("\t\t\t\teg:由于我的疏忽,制作地图时少了编号27,请往后挑战\n\n");
	printf("\a\t\t\t\t请输入您要挑战的地图编号:");
	scanf("%d",&n);
	srand(time(NULL));
	while(pmove->a.num1!=n) {
		pmove = pmove->next;
		if(pmove==NULL) {
			printf("\a\t\t\t\t请输入正确的地图编号\n");
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
						printf("\t\t\t\t【力拔山兮气盖世】\n");
						printf("\t\t\t\t您使用了秘技 *拳·力* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得5000exp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+5000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得5000exp");
							b.exp = b.exp+5000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【青钢剑】,生命值+100,攻击力+15,灵力+10**");
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
						printf("\t\t\t\t您使用普通攻击对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得5000exp");
							b.exp = b.exp+5000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得5000exp");
							b.exp = b.exp+5000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【青钢剑】,生命值+100,攻击力+15,灵力+10**");
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
					printf("\t\t\t\t您使用普通攻击对%s造成了%d点伤害\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*您受到%d点伤害\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("您输掉了战斗,请继续努力\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得5000exp");
						b.exp = b.exp+5000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得5000exp");
						b.exp = b.exp+5000;
						printf("\n");
						printf("\t\t\t\t**您获得并炼化了【青钢剑】,生命值+100,攻击力+15,灵力+10**");
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
						printf("\t\t\t\t【力拔山兮气盖世】\n");
						printf("\t\t\t\t您使用了秘技 *拳·力* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得10000exp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+10000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得10000exp");
							b.exp = b.exp+10000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【瑶光铠】,生命值+200,攻击力+10,灵力+15**");
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
						printf("\t\t\t\t【云清归海疾】\n");
						printf("\t\t\t\t您使用了秘技 *速·疾* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-50;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得10000exp");
							b.exp = b.exp+10000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得10000exp");
							b.exp = b.exp+10000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【瑶光铠】,生命值+200,攻击力+10,灵力+15**");
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
					printf("\t\t\t\t您使用普通攻击对%s造成了%d点伤害\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*您受到%d点伤害\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("您输掉了战斗,请继续努力");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得10000exp");
						b.exp = b.exp+10000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得10000exp");
						b.exp = b.exp+10000;
						printf("\n");
						printf("\t\t\t\t**您获得并炼化了【瑶光铠】,生命值+200,攻击力+10,灵力+15**");
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
						printf("\t\t\t\t【晨雨暮阳不悔剑】\n");
						printf("\t\t\t\t您使用了秘技 *剑·晨暮* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得1.5wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+15000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得1.5wexp");
							b.exp = b.exp+15000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【极夜靴】,生命值+200,攻击力+20,灵力+15**");
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
						printf("\t\t\t\t【秋叶春波俱迎风疾】\n");
						printf("\t\t\t\t您使用了秘技 *速·春秋* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-85;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得1.5wexp");
							b.exp = b.exp+15000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得10000exp");
							b.exp = b.exp+10000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【极夜靴】,生命值+200,攻击力+20,灵力+15**");
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
					printf("\t\t\t\t您使用普通攻击对%s造成了%d点伤害\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*您受到%d点伤害\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("您输掉了战斗,请继续努力");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得1.5wexp");
						b.exp = b.exp+15000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得1.5wexp");
						b.exp = b.exp+15000;
						printf("\n");
						printf("\t\t\t\t**您获得并炼化了【极夜靴】,生命值+200,攻击力+20,灵力+15**");
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
						printf("\t\t\t\t【日落西山藏火镜】\n");
						printf("\t\t\t\t您使用了秘技 *法·藏火* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得2wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+20000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得2wexp");
							b.exp = b.exp+20000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【神兵戈鸢】,生命值+400,攻击力+20,灵力+30**");
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
						printf("\t\t\t\t【月升东海现冰轮】\n");
						printf("\t\t\t\t您使用了秘技 *法·冰轮* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-210;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得2wexp");
							b.exp = b.exp+20000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得2wexp");
							b.exp = b.exp+20000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【神兵戈鸢】,生命值+400,攻击力+20,灵力+30**");
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
					printf("\t\t\t\t您使用普通攻击对%s造成了%d点伤害\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*您受到%d点伤害\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("您输掉了战斗,请继续努力");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得2wexp");
						b.exp = b.exp+20000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得2wexp");
						b.exp = b.exp+20000;
						printf("\n");
						printf("\t\t\t\t**您获得并炼化了【神兵戈鸢】,生命值+400,攻击力+20,灵力+30**");
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
						printf("\t\t\t\t【不来不向不回向】\n");
						printf("\t\t\t\t您使用了秘技 *拳·揽天捶* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得3wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+30000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得3wexp");
							b.exp = b.exp+30000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【名剑挽歌】,生命值+400,攻击力+40,灵力+30**");
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
						printf("\t\t\t\t【无异无同无有无】\n");
						printf("\t\t\t\t您使用了秘技* 境·撼天威* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-450;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得3wexp");
							b.exp = b.exp+30000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得2wexp");
							b.exp = b.exp+20000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【名剑挽歌】,生命值+400,攻击力+40,灵力+30**");
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
					printf("\t\t\t\t您使用普通攻击对%s造成了%d点伤害\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*您受到%d点伤害\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("您输掉了战斗,请继续努力");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得3wexp");
						b.exp = b.exp+30000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得3wexp");
						b.exp = b.exp+30000;
						printf("\n");
						printf("\t\t\t\t**您获得并炼化了【名剑挽歌】,生命值+400,攻击力+40,灵力+30**");
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
						printf("\t\t\t\t【万马奔腾杀戮起,一骑绝尘踏凌霄】\n");
						printf("\t\t\t\t您使用了秘技 *神速·腾霄* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得3wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+30000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得3wexp");
							b.exp = b.exp+30000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【极·太虚盔】,生命值+800,攻击力+50,灵力+50**");
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
						printf("\t\t\t\t【千里路,转从容,纵横沧海碧云空】\n");
						printf("\t\t\t\t您使用了秘技 *神境·云空* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-650;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得3wexp");
							b.exp = b.exp+30000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得2wexp");
							b.exp = b.exp+20000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【极·太虚盔】,生命值+800,攻击力+50,灵力+50**");
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
					printf("\t\t\t\t【千形万象竟还空】\n");
					printf("\t\t\t\t您使用了 *万象·击* 对%s造成了%d点伤害\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*您受到%d点伤害\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("您输掉了战斗,请继续努力");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得3wexp");
						b.exp = b.exp+30000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得3wexp");
						b.exp = b.exp+30000;
						printf("\n");
						printf("\t\t\t\t**您获得并炼化了【极·太虚盔】,生命值+800,攻击力+50,灵力+50**");
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
						printf("\t\t\t\t【莫道桑榆晚，微霞尚满天】\n");
						printf("\t\t\t\t您使用了秘技 *域·霞天* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得5wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+50000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得5wexp");
							b.exp = b.exp+50000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【极·太虚甲】,生命值+1200,攻击力+50,灵力+50**");
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
						printf("\t\t\t\t【尸山血海亘古香，琼霄九劫战天长】\n");
						printf("\t\t\t\t您使用了秘技 *神剑·天长 *对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-1650;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得5wexp");
							b.exp = b.exp+50000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得5wexp");
							b.exp = b.exp+50000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【极·太虚甲】,生命值+1200,攻击力+50,灵力+50**");
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
					printf("\t\t\t\t【化域自还春】\n");
					printf("\t\t\t\t您使用了 *化域·凝* 对%s造成了%d点伤害\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*您受到%d点伤害\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("您输掉了战斗,请继续努力");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得5wexp");
						b.exp = b.exp+50000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得5wexp");
						b.exp = b.exp+50000;
						printf("\n");
						printf("\t\t\t\t**您获得并炼化了【极·太虚甲】,生命值+1200,攻击力+50,灵力+50**");
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
						printf("\t\t\t\t【头顶青天日月，足踏江山万里】\n");
						printf("\t\t\t\t您使用了秘技 *神域·日月河山* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得10wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+100000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得10wexp");
							b.exp = b.exp+100000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【极·太虚盾】,生命值+1500,攻击力+50,灵力+100**");
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
						printf("\t\t\t\t【一身转战三千里，一剑曾当百万师】\n");
						printf("\t\t\t\t您使用了秘技 *神剑·拔天* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-2300;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得10wexp");
							b.exp = b.exp+100000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得10wexp");
							b.exp = b.exp+100000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【极·太虚盾】,生命值+1500,攻击力+50,灵力+100**");
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
					printf("\t\t\t\t【转轮八诗】\n");
					printf("\t\t\t\t您使用了 *转轮·破袭* 对%s造成了%d点伤害\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*您受到%d点伤害\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("您输掉了战斗,请继续努力");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得10wexp");
						b.exp = b.exp+100000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得10wexp");
						b.exp = b.exp+100000;
						printf("\n");
						printf("\t\t\t\t**您获得并炼化了【极·太虚盾】,生命值+1500,攻击力+50,灵力+100**");
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
						printf("\t\t\t\t【积雪云端，惊鸿在天】\n");
						printf("\t\t\t\t您使用了秘技 *极剑·惊鸿云端* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得10wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+100000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得10wexp");
							b.exp = b.exp+100000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【极·太虚履】,生命值+1500,攻击力+100,灵力+100**");
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
						printf("\t\t\t\t【狂刀挥起万物灭，逆转五行破三界】\n");
						printf("\t\t\t\t您使用了秘技 *极刀·寂墟* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-4500;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得10wexp");
							b.exp = b.exp+100000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得10wexp");
							b.exp = b.exp+100000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【极·太虚履】,生命值+1500,攻击力+100,灵力+100**");
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
					printf("\t\t\t\t【豁尔天开宇】\n");
					printf("\t\t\t\t您使用了 *开宇·凝宙* 对%s造成了%d点伤害\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*您受到%d点伤害\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("您输掉了战斗,请继续努力");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得10wexp");
						b.exp = b.exp+100000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得10wexp");
						b.exp = b.exp+100000;
						printf("\n");
						printf("\t\t\t\t**您获得并炼化了【极·太虚履】,生命值+1500,攻击力+100,灵力+100**");
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
						printf("\t\t\t\t【仙路尽头谁为峰，入道伊始道成空】\n");
						printf("\t\t\t\t您使用了秘技 *极域·万物成空* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+150000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【入·界墟障】,生命值+3000,攻击力+200,灵力+200**");
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
						printf("\t\t\t\t【千重劫，百世难，不灭魂，亘古匆匆】\n");
						printf("\t\t\t\t您使用了秘技 *禁忌·无灭* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-5500;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【入·界墟障】,生命值+3000,攻击力+200,灵力+200**");
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
						printf("\t\t\t\t【以吾本性，快意恩仇，以吾本心，遨游世间】\n");
						printf("\t\t\t\t您使用了秘技 *禁忌·本界* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-6000;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【入·界墟障】,生命值+3000,攻击力+200,灵力+200**");
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
					printf("\t\t\t\t【入道无来去】\n");
					printf("\t\t\t\t您使用了 *入道·长生自由* 对%s造成了%d点伤害\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*您受到%d点伤害\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("您输掉了战斗,请继续努力");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得15wexp");
						b.exp = b.exp+150000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得15wexp");
						b.exp = b.exp+150000;
						printf("\n");
						printf("\t\t\t\t**您获得并炼化了【入·界墟障】,生命值+3000,攻击力+200,灵力+200**");
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
						printf("\t\t\t\t【春梦往生】\n");
						printf("\t\t\t\t您使用了秘技 *道·往生* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+150000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【道·界墟剑】,生命值+3000,攻击力+500,灵力+300**");
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
						printf("\t\t\t\t【左手因果，右手长生】\n");
						printf("\t\t\t\t您使用了秘技 *道· 因果 长生* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-6000;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【道·界墟剑】,生命值+3000,攻击力+500,灵力+300**");
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
						printf("\t\t\t\t【身绕轮回，吾自无量在】\n");
						printf("\t\t\t\t您使用了秘技 *道·身化自在* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-6000;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t\t\t**您获得并炼化了【道·界墟剑】,生命值+3000,攻击力+500,灵力+300**");
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
					printf("\t\t\t\t【执掌-天命】\n");
					printf("\t\t\t\t您使用了 *入道·天命裁决* 对%s造成了%d点伤害\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*您受到%d点伤害\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("您输掉了战斗,请继续努力");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得15wexp");
						b.exp = b.exp+150000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得15wexp");
						b.exp = b.exp+150000;
						printf("\n");
						printf("\t\t\t\t**您获得并炼化了【道·界墟剑】,生命值+3000,攻击力+500,灵力+300**");
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
						printf("\t\t\t\t【无人在我之上】\n");
						printf("\t\t\t\t您使用了秘技 *极道禁忌·顶峰* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==2) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							printf("\n");
							printf("\n");
							b.exp = b.exp+150000;
							save(b);
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t**您获得并炼化了【极道·时空之灵】,生命值+10000,攻击力+1000,灵力+1000**");
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
						printf("\t\t\t\t【天命？小道尔】\n");
						printf("\t\t\t\t您使用了秘技 *极道禁忌·破妄* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-150000;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t**您获得并炼化了【极道·时空之灵】,生命值+10000,攻击力+1000,灵力+1000**");
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
						printf("\t\t\t\t【念起，事生】\n");
						printf("\t\t\t\t您使用了秘技 *极道禁忌·思维箴言* 对%s造成了%d点伤害\n",pmove->a.rname,f);
						printf("\t\t\t\t=====================================\n");
						q.magic = q.magic-150000;
						Sleep(200);
						pmove->a.rlife = pmove->a.rlife-f;
						e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
						q.life = q.life-e;
						printf("\t\t\t\t*您受到%d点伤害\n",e);
						printf("\t\t\t\t=====================================\n");
					} else {
						printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您输掉了战斗,请继续努力");
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					}
					if(pmove->a.rlife<0) {
						i = rand()%(2-1+1)+1;
						if(i==1) {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							save(b);
							printf("\n");
							printf("\t\t\t\t");
							system("pause");
							return start();
						} else {
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("\a您战胜了对手");
							printf("\n");
							printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
							printf("您获得15wexp");
							b.exp = b.exp+150000;
							printf("\n");
							printf("\t\t**您获得并炼化了【极道·时空之灵】,生命值+10000,攻击力+1000,灵力+1000**");
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
					printf("\t\t\t\t【道路之终】\n");
					printf("\t\t\t\t您使用了 *极道禁忌·逆转风暴* 对%s造成了%d点伤害\n",pmove->a.rname,f);
					printf("\t\t\t\t=====================================\n");
					Sleep(200);
					pmove->a.rlife = pmove->a.rlife-f;
					e = rand()%((pmove->a.rpower*3)-(pmove->a.rpower)+1)+pmove->a.rpower;
					q.life = q.life-e;
					printf("\t\t\t\t*您受到%d点伤害\n",e);
					printf("\t\t\t\t=====================================\n");
				} else {
					printf("\t\t\t\t[\t\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					printf("您输掉了战斗,请继续努力");
					printf("\n");
					printf("\t\t\t\t");
					system("pause");
					return start();
				}
				if(pmove->a.rlife<0) {
					i = rand()%(2-1+1)+1;
					if(i==1) {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得15wexp");
						b.exp = b.exp+150000;
						save(b);
						printf("\n");
						printf("\t\t\t\t");
						system("pause");
						return start();
					} else {
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("\a您战胜了对手");
						printf("\n");
						printf("\t\t\t\t[\t\t]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
						printf("您获得15wexp");
						b.exp = b.exp+150000;
						printf("\n");
						printf("\t\t**您获得并炼化了【极道·时空之灵】,生命值+10000,攻击力+1000,灵力+1000**");
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
