create database cont
on primary
(
name='cont.mdf',
filename='d:\cont.mdf',
size=5mb,
maxsize=100mb,
filegrowth=10%
)
log on
(
name='cont.ldf',
filename='d:\cont.ldf',
size=5,
maxsize=unlimited,
filegrowth=1mb
)

CREATE TABLE People
(
Pno int PRIMARY KEY,
Pname nchar(10),
Pleft float check (Pleft>0),
Pcreate_time nchar(10),
Xno int,
FOREIGN KEY(Xno) REFERENCES ChuXu_(Xno),
);

CREATE TABLE ChuXu_
(
Xno int PRIMARY KEY,
Xname nchar(10),
Xaddr nchar(10),
Xnum int check (Xnum>0),
Xcity nchar(10)
);

CREATE TABLE Jiedai
(
Jno int,
Jtype nchar(10),
Jmoney float,
Pcreate_time nchar(10)
);

