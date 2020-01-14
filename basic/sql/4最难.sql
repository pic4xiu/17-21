	1 统计各个储蓄所的帐户个数和余额总数。
select 储蓄所.储蓄所编号,count(帐户编号)'帐户个数',sum(余额)'余额总数' from 
储蓄所 left outer join 帐户 on 储蓄所.储蓄所编号
 = 帐户.储蓄所编号 group by 储蓄所.储蓄所编号 
	2 列出存钱总额10万元以上的日期
select 日期,借贷类型,sum(金额)'存款金额' from 借贷 group by 日期, 借贷类型 having 
借贷类型='存款' and sum(金额)>100000


select Pno from People
where Xno in (
select Xno from Chuxu_
where Xcity = 
(select Xcity
from
(select top 1 Xcity, count(Xcity) as [pidcount] from Chuxu_
group by Xcitys
order by pidcount asc) as a)
)


select * from 帐户 where 帐户编号 not in
(select 帐户编号 from 借贷 where 借贷类型='取款')


select * from 帐户 
intersect
select * from 帐户 where 帐户编号 not in
(select 帐户编号 from 借贷 where 借贷类型='取款')
