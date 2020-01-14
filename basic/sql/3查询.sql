select Pname,Pleft from People where Xno in
(
select Xno from Chuxu
where Xaddr='长春南湖路'
)

select People.Pname,People.Pleft from People,Chuxu
where People.Xno=Chuxu.Xno and Chuxu.Xaddr='长春南湖路'

select Pname,Pleft from People where Pno in
(
select Pno from Jiedai
where Jiedai.Jtype='借贷' and Jiedai.Jmoney>10000
)

select Pno,Pname from People where Pleft>(
select MAX(Pleft) from People where Xno in
(
select Xno from Chuxu
where Xaddr='长春南湖路'
))

select Pno,Pname from People where Pleft> all (
select Pleft from People where Xno in
(
select Xno from Chuxu
where Xaddr='长春南湖路'
))