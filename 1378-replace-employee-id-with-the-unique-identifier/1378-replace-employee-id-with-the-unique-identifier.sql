# Write your MySQL query statement below
select e2.unique_id as unique_id , e1.name as name from employees as e1 left  join employeeuni as e2 on e1.id= e2.id;

