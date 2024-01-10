# Write your MySQL query statement below

with cte as(
select reports_to, count(employee_id) as reports_count, round(avg(age), 0) as average_age from employees where reports_to is not null  group by reports_to 
)

select e.employee_id, e.name, c.reports_count, c.average_age from employees e left join cte c on e.employee_id =c.reports_to where c.reports_to is not null order by employee_id;