# Write your MySQL query statement below


with cte as(
select employee_id, case when count(department_id)=1 then department_id when count(department_id)>1  then sum((primary_flag='Y')*department_id) end as department_id
from employee group by employee_id
)

select * from cte where department_id>0;

# # way-2 -> union 
# select employee_id, department_id from employee where primary_flag='Y'
# union 
# select employee_id, department_id from employee group by employee_id having count(department_id) =1;