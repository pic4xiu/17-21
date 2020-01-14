
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
rollback tran
commit tran 

select * from ChuXu


--delete from People where Xno=1
--drop view te
