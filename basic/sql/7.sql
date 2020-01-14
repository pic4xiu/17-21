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
Pleft int check (Pleft>0),
Pcreate_time nchar(10),
Xno int,
);

CREATE TABLE ChuXu
(
Xno int PRIMARY KEY,
Xname nchar(10),
Xaddr nchar(10),
Xnum int check (Xnum>0),
Xcity nchar(10)
);



create procedure chuxusuo
@´¢ÐîËù±àºÅ	int
as 
begin
select * from ChuXu where Xno=@´¢ÐîËù±àºÅ
end

begin
if  not exists(select Pno from People where Xno=@´¢ÐîËù±àºÅ)
begin
	DELETE FROM ChuXu WHERE Xno = @´¢ÐîËù±àºÅ
end
end

begin 
if (select sum(Pleft) from  People where Xno=@´¢ÐîËù±àºÅ)<1000000
begin
	INSERT INTO People(Pno) VALUES (5)
end
end

exec chuxusuo 1