---��������
begin tran
--������׽���ƣ�������������Ҳ�еġ����ҿ���Ƕ�ס�
   --�����ȷ
--   while()
   insert into People (Pno) values ((select count(*) from People)+1)
--if(@@trancount>0)


--����Ϊ�ձ�ID ,NumbΪint ���ͣ�����Ϊnvarchar����
select * from People

commit tran  --����ɹ�Lives���У�������3�����ݡ�

select count(*) from People where Xno=1

delete from People where Pno=1