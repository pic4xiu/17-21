Create table 员工
(员工编号 varchar(10) not null primary key,
  姓名  char(8)not null,
  性别  char(2) not null check(性别 in ('男','女')), 
  年龄  int not null,
  学历 varchar(10) not null,	
  部门名称   varchar(15) not null,
  毕业院校 varchar(30) not null,
  政治面貌 varchar(8) not null,
  所学专业 varchar(40) not null,
  出生日期 varchar(15) not null,
  退休信息 varchar(4) not null,
  FOREIGN KEY (部门名称) REFERENCES 部门(部门名称)
 );
Create table  简历
(ID  int  primary key,
 员工编号 varchar(10)not null,
 获奖情况 varchar(50),
 社会实践情况 varchar(100),
 FOREIGN KEY(员工编号)REFERENCES 员工(员工编号)
); 

Create table 离职
(ID int  primary key,
员工编号 varchar(10)not null ,
离职原因 varchar(40),
离职时间 varchar(20),
批准人 varchar(8),
FOREIGN KEY(员工编号)REFERENCES 员工(员工编号)

);

Create table 岗位变更
( ID  int  primary key,
员工编号 varchar(10) not null ,
初始岗位 varchar(20),
变更日期 varchar(20),
现在岗位 varchar(20),
FOREIGN KEY(员工编号)REFERENCES 员工(员工编号)
  );

CREATE  TABLE 工资
(工资ID  int  primary key ,
员工编号 varchar(10)not null,
基本工资 decimal not null,
个人所得税 decimal not null,
缺勤扣款 decimal,
加班工资  decimal ,
工龄工资 decimal not null,
其他应减款 decimal,
其他应增款 decimal,
岗位工资 decimal not null,
应发工资 decimal,
实发工资 decimal,
工资年月 varchar (15),
FOREIGN KEY(员工编号)REFERENCES 员工(员工编号)
);

CREATE TABLE 奖惩
(奖惩ID  int  primary key ,
员工编号 varchar (10)not null,
奖惩日期 varchar(15),
奖惩原因 varchar (15),
解除日期 varchar(15)
FOREIGN KEY(员工编号)REFERENCES 员工(员工编号)
);

CREATE  TABLE 工资历史
( ID  int  primary key ,
员工编号 varchar(10),
发放金额 decimal,
发放日期 varchar(20),
FOREIGN KEY(员工编号)REFERENCES 员工(员工编号)
);

Create  table 考勤
(
考勤ID int  primary key ,
员工编号 varchar(10) not null ,
加班 int,
休假 int,
请假 int,
日期 varchar(15),
FOREIGN KEY(员工编号)REFERENCES 员工(员工编号)
);

Create table 部门
(部门名称 varchar(15) primary key,
 部门人数 int,
 部门负责人 varchar(15)
);

Create table 权限
(员工编号 int,
密码 int,
权限大小 int 
FOREIGN KEY(员工编号)REFERENCES 员工(员工编号)
);
