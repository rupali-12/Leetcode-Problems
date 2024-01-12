# Write your MySQL query statement below
select e1.name from employee as e1 join employee as e2 where e1.id= e2.managerId group by e2.managerId having count(e2.managerId)>=5;


# # way 2 
# with cte as(
# select managerId from employee group by managerId having count(id)>=5
# )

# select name from employee where id in (select managerId from cte)