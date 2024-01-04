# Write your MySQL query statement below

# # way-1 USing subquery 
# select max(salary) as SecondHighestSalary from employee where salary <> (select max(salary) from employee

# way 2: usin CTE 
with cte as(
select *, dense_rank() over(order by salary desc) as r from employee
)

select ifnull((select salary from cte where r = 2 limit 1), null)  as SecondHighestSalary;