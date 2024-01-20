# Write your MySQL query statement below
with cte as(
select *, RANK() over(partition by s.product_id order by year) as rnk
from sales s 
)

select product_id, year as first_year, quantity, price from cte where rnk=1;