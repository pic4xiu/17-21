#include<iostream>
#include <signal.h>
#include<cstdio>
#include<cstdlib>
#include<unistd.h>//linux/unix的系统调用
#include<sys/sem.h>//信号量
#include<errno.h>//查看错误代码
using namespace std;
static int i=1;
bool app_stopped = false;
pid_t id;
void sigint_handler(int sig){
	if(sig == SIGINT){
		// ctrl+c退出时执行的代码
		cout << "ctrl-c主动中断!"<< endl;
		app_stopped = true;
	}
}


//信号量数据结构
typedef union _semnu{
	int val;//信号量的值
	
	//semid_ds结构类型指针，其中semid_ds结构中包括信号量的权限和用户信息、最后一次setmop的操作时间和最后一次修改的时间
	//用于 IPC_STAT 和IPC_SET，即用于信号量的读权限和修改权限
	struct semid_ds *buf;
	
	//用于GETALL和SETALL，即用于返回当前系统设置的所有信号量的值和设置信号量集中所有信号量的值，并以数组的形式存储
	ushort * array;
}semun;

void v(int &sem_id)
{
	struct sembuf sem_b;
	sem_b.sem_num=0;//信号量的编号取0
	sem_b.sem_op=1;//信号量一次PV操作时加减的数值，V操作值取1
	sem_b.sem_flg=SEM_UNDO;//使操作系统跟踪当前进程对该信号量的修改情况
	if(semop(sem_id,&sem_b,1)==-1)//对于一个信号量sem_id进行v操作后，正常返回信号量的标识符，返回-1，表示出错
	{
		cout<<"v error"<<endl;//显示错误提示
		exit(0);
	}
}

void p(int &sem_id)
{
	struct sembuf sem_b;
	sem_b.sem_num=0;
	sem_b.sem_op=-1;//信号量一次PV操作时加减的数值，P操作值取-1
	sem_b.sem_flg=SEM_UNDO;
	if(semop(sem_id,&sem_b,1)==-1)//对于一个信号量sem_id进行P操作后，正常返回信号量的标识符，返回-1，表示出错
	{
	switch(errno) {
   		case 4: 
		cout<<"p操作遇到了中断"<<endl;//显示错误提示
		break;
   	default :
		cout<<"p操作出现错误"<<endl;//显示错误提示
	}
		
		exit(0);
	}
}

//设置信号量初值
void set(int &sem_id,int val=1)
{
	semun sem_un;
	sem_un.val=val;
	if(semctl(sem_id,0,SETVAL,sem_un)==-1)//返回值大于等于0，得到信号量标识符，返回值为-1，表示出错
	{
		if(errno==EEXIST)//错误代码为信号量已存在，无法创建
		cout<<"exist"<<endl;
		cout<<"set"<<val<<"error"<<endl;
		exit(0);
	}
}

int main()
{
	signal(SIGINT, sigint_handler);
	//设置1个信号量mutex,初值为1，实现写入进程和赋值进程对txt1的互斥
	int mutex=semget(1111,1,IPC_CREAT);
	set(mutex,1) ;
	
	//设置1个信号量full,初值为0，表示txt2的拷贝工作
	int full=semget(2222,1, IPC_CREAT) ;
	set(full,0) ;
	
	//设置1个信号量empty,初值为1，表示对txt1的写入进程
	int empty=semget(3333,1,IPC_CREAT) ;
	set(empty, 1) ;
	
	FILE *fp1=fopen( "./txt1", "w") ;
	FILE *fp2=fopen( "./txt1", "r") ;
	FILE *fp3=fopen( "./txt2", "w") ;
	id=fork() ;//通过系统调用创建一个与原来进程几乎完全相同的进程,父进程中返回子进程id,子进程中返回0
	
	if(id>0){//写入进程
		char buf[32]="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		while(true)
		{
			if (app_stopped){
				break;
			}
			p(empty);
			p(mutex);
			cout<< "第"<<i++<<"次写入"<<endl ;
			fseek (fp1,0,SEEK_SET) ;
			fputs (buf, fp1) ;
			fflush (fp1) ;
			sleep(1) ;
			cout<<"该次写入完成"<<endl ;
			v(mutex) ;
			v(full) ;

		}

	}
	else if(id==0)
	{//复制进程
	char buf[31];
	buf[30]='\x00';
	int j=1;
	while(true)
	{
		if (app_stopped){
			break;
		}
		p(full);
		p(mutex);
		cout<<"读取并写入中.第"<<j++<<"次"<<endl ;
		fseek(fp2,0,SEEK_SET);
		fgets(buf, 31,fp2);
		fputs(buf, fp3);
		fflush (fp3);
		cout<<buf<<endl;
		cout<<"完成" <<endl;
		cout<<endl;
		sleep(1) ;
		v(mutex);
		v(empty);

	}

	} 
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	sleep(1) ;
	
	//输出txt2中内容信息和字符数
	cout<<"\ntxt2:"<<endl;
	system("cat txt2\n");
	cout<<"\n共有" <<endl;
	system("grep -o 'a' txt2 | wc -l");
	cout<<"个字符" <<endl;
	cout<<"\n" <<endl;
	exit(0);
	return 0;
}

