/*

create procedure savedevidebyname
@����	varchar(200)
as

begin

declare @file_path varchar(200);--����EXCEl�ļ�·����

declare @file_name varchar(200);--����EXCEl�ļ�����

declare @exec_sql  varchar(200);--SQL��䣻

set @file_path = 'H:\'

set @file_name = 'dept' + CONVERT(varchar(100), GETDATE(), 112)+'.xls'

set @exec_sql = 'select * from wagemanage.dbo.'+@����  ---���ݱ�����·����

set @exec_sql = ' bcp "'+@exec_sql+'" queryout "'+@file_path+''+@file_name+'" -c -T -U "sa" -P "P "1"';

exec master..xp_cmdshell @exec_sql

end

*/

exec savedevidebyname  ����
--���ô洢���̵�������
backup database wagemanage to disk='H:/Test.bak'

restore database test from disk='H:/Test.bak'
--���ݿⱸ��
create view ����
as
select (��������+��������˰)  from ����
--��ѯͳ��demo

create trigger delte
on Ȩ��
for DELETE
as
declare @a int
select @a=�˻� from deleted
if @a>20
begin
	print'you can not delete'
	rollback
end
--һ����ȫ������