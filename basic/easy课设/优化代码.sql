/*

create procedure savedevidebyname
@表名	varchar(200)
as

begin

declare @file_path varchar(200);--导出EXCEl文件路径；

declare @file_name varchar(200);--导出EXCEl文件名；

declare @exec_sql  varchar(200);--SQL语句；

set @file_path = 'H:\'

set @file_name = 'dept' + CONVERT(varchar(100), GETDATE(), 112)+'.xls'

set @exec_sql = 'select * from wagemanage.dbo.'+@表名  ---数据表完整路径；

set @exec_sql = ' bcp "'+@exec_sql+'" queryout "'+@file_path+''+@file_name+'" -c -T -U "sa" -P "P "1"';

exec master..xp_cmdshell @exec_sql

end

*/

exec savedevidebyname  工资
--利用存储过程导出报表
backup database wagemanage to disk='H:/Test.bak'

restore database test from disk='H:/Test.bak'
--数据库备份
create view 基本
as
select (基本工资+个人所得税)  from 工资
--查询统计demo

create trigger delte
on 权限
for DELETE
as
declare @a int
select @a=账户 from deleted
if @a>20
begin
	print'you can not delete'
	rollback
end
--一个安全触发器