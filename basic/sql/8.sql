begin transaction 
declare @tmp int
select @tmp=avg(Xnum) from ChuXu
while @tmp < 30
begin
 update ChuXu set Xnum = Xnum + 2
 select @tmp = avg(Xnum) from ChuXu
 --insert into People (Pno,Xno) values ((select count(*) from People)+1,1)
 --insert into People (Pno,Xno) values ((select count(*) from People)+1,1)
 --insert into People (Pno,Xno) values ((select count(*) from People)+1,2)
 --insert into People (Pno,Xno) values ((select count(*) from People)+1,2)
 select * from ChuXu
end

select * from ChuXu

if ((select top 1 Xnum from ChuXu order by Xnum desc) > 80)
begin
 print'be rollbacked'
 rollback
 return
end

commit transaction 

select * from ChuXu

/*
/*CREATE VIEW te(Xno,num)
as
select Xno,count(*) from People group by Xno
*/
---¿ªÆôÊÂÎñ
begin tran
while((select avg(num) from te)<30)
begin
   insert into People (Pno,Xno) values ((select count(*) from People)+1,1)
   insert into People (Pno,Xno) values ((select count(*) from People)+1,1)
   insert into People (Pno,Xno) values ((select count(*) from People)+1,2)
   insert into People (Pno,Xno) values ((select count(*) from People)+1,2)
end
select * from ChuXu
if((select top 1 num  from te order by num desc)>80)
rollback-- tran
commit tran 

select * from ChuXu
UPDATE ChuXu SET Xnum = 1

--delete from People where Pno=1
--drop view te
*/