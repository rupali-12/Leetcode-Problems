# Write your MySQL query statement below
# select e2.unique_id , e1.name from employees as e1 left  join employeeuni as e2 on e1.id= e2.id;

select 
eu.unique_id as unique_id, e.name as name
from Employees e left join EmployeeUNI eu on e.id = eu.id