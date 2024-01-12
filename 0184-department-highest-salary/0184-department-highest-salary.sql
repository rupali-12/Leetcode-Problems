# Write your MySQL query statement below
with cte as(
select e.name as employee, e.salary, e.departmentId, d.name as department, max(salary) over(partition by e.departmentId) as mxsalary 
from  department d  left join employee e on d.id =  e.departmentId 
)

select  department, employee, salary from cte where salary = mxsalary
