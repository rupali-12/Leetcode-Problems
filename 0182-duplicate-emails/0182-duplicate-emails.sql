# Write your MySQL query statement below
# using group by 
# select email from person group by email having count(email)>1;

# Using join 
select distinct p1.email as email from person as p1 join person as p2 where p1.email= p2.email and p1.id != p2.id;

