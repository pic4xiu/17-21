---开启事务
begin tran
--错误扑捉机制，看好啦，这里也有的。并且可以嵌套。
   --语句正确
--   while()
   insert into People (Pno) values ((select count(*) from People)+1)
--if(@@trancount>0)


--表本身为空表，ID ,Numb为int 类型，其它为nvarchar类型
select * from People

commit tran  --如果成功Lives表中，将会有3条数据。

select count(*) from People where Xno=1

delete from People where Pno=1