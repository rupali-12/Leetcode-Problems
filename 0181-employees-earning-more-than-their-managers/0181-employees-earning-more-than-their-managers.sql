# Write your MySQL query statement below
select e1.name as Employee from employee e1 join employee e2 where e1.salary > e2.salary and e1.managerId = e2.id;

