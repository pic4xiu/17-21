Create table Ա��
(Ա����� varchar(10) not null primary key,
  ����  char(8)not null,
  �Ա�  char(2) not null check(�Ա� in ('��','Ů')), 
  ����  int not null,
  ѧ�� varchar(10) not null,	
  ��������   varchar(15) not null,
  ��ҵԺУ varchar(30) not null,
  ������ò varchar(8) not null,
  ��ѧרҵ varchar(40) not null,
  �������� varchar(15) not null,
  ������Ϣ varchar(4) not null,
  FOREIGN KEY (��������) REFERENCES ����(��������)
 );
Create table  ����
(ID  int  primary key,
 Ա����� varchar(10)not null,
 ����� varchar(50),
 ���ʵ����� varchar(100),
 FOREIGN KEY(Ա�����)REFERENCES Ա��(Ա�����)
); 

Create table ��ְ
(ID int  primary key,
Ա����� varchar(10)not null ,
��ְԭ�� varchar(40),
��ְʱ�� varchar(20),
��׼�� varchar(8),
FOREIGN KEY(Ա�����)REFERENCES Ա��(Ա�����)

);

Create table ��λ���
( ID  int  primary key,
Ա����� varchar(10) not null ,
��ʼ��λ varchar(20),
������� varchar(20),
���ڸ�λ varchar(20),
FOREIGN KEY(Ա�����)REFERENCES Ա��(Ա�����)
  );

CREATE  TABLE ����
(����ID  int  primary key ,
Ա����� varchar(10)not null,
�������� decimal not null,
��������˰ decimal not null,
ȱ�ڿۿ� decimal,
�Ӱ๤��  decimal ,
���乤�� decimal not null,
����Ӧ���� decimal,
����Ӧ���� decimal,
��λ���� decimal not null,
Ӧ������ decimal,
ʵ������ decimal,
�������� varchar (15),
FOREIGN KEY(Ա�����)REFERENCES Ա��(Ա�����)
);

CREATE TABLE ����
(����ID  int  primary key ,
Ա����� varchar (10)not null,
�������� varchar(15),
����ԭ�� varchar (15),
������� varchar(15)
FOREIGN KEY(Ա�����)REFERENCES Ա��(Ա�����)
);

CREATE  TABLE ������ʷ
( ID  int  primary key ,
Ա����� varchar(10),
���Ž�� decimal,
�������� varchar(20),
FOREIGN KEY(Ա�����)REFERENCES Ա��(Ա�����)
);

Create  table ����
(
����ID int  primary key ,
Ա����� varchar(10) not null ,
�Ӱ� int,
�ݼ� int,
��� int,
���� varchar(15),
FOREIGN KEY(Ա�����)REFERENCES Ա��(Ա�����)
);

Create table ����
(�������� varchar(15) primary key,
 �������� int,
 ���Ÿ����� varchar(15)
);

Create table Ȩ��
(Ա����� int,
���� int,
Ȩ�޴�С int 
FOREIGN KEY(Ա�����)REFERENCES Ա��(Ա�����)
);
