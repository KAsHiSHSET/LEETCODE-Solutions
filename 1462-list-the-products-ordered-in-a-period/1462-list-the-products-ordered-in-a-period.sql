# Write your MySQL query statement below
select P.product_name ,sum(O.unit) as unit
from Products P
join Orders O
on P.product_id= O.product_id
where order_date >= '2020-02-01' and order_date<='2020-02-29'
group by O.product_id
having sum(O.unit)>=100;