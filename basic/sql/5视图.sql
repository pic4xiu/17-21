CREATE VIEW first1

AS 

select ChuXu_.Xname,count(Pno)'帐户个数',sum(Pleft)'余额总数' from 
ChuXu_ left join People on ChuXu_.Xno
 = People.Xno group by ChuXu_.Xname

select * from first1

select top 1 Xname from first1
order by 余额总数 asc