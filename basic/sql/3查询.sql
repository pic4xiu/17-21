select Pname,Pleft from People where Xno in
(
select Xno from Chuxu
where Xaddr='�����Ϻ�·'
)

select People.Pname,People.Pleft from People,Chuxu
where People.Xno=Chuxu.Xno and Chuxu.Xaddr='�����Ϻ�·'

select Pname,Pleft from People where Pno in
(
select Pno from Jiedai
where Jiedai.Jtype='���' and Jiedai.Jmoney>10000
)

select Pno,Pname from People where Pleft>(
select MAX(Pleft) from People where Xno in
(
select Xno from Chuxu
where Xaddr='�����Ϻ�·'
))

select Pno,Pname from People where Pleft> all (
select Pleft from People where Xno in
(
select Xno from Chuxu
where Xaddr='�����Ϻ�·'
))