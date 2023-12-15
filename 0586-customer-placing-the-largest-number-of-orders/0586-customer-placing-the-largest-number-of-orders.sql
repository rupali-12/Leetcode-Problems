# Write your MySQL query statement below
with cte as (
select customer_number, count(order_number) as numOrd from orders group by customer_number)

select customer_number from cte where numOrd = (select max(numOrd) from cte);