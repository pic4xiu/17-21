CREATE VIEW first1

AS 

select ChuXu_.Xname,count(Pno)'�ʻ�����',sum(Pleft)'�������' from 
ChuXu_ left join People on ChuXu_.Xno
 = People.Xno group by ChuXu_.Xname

select * from first1

select top 1 Xname from first1
order by ������� asc