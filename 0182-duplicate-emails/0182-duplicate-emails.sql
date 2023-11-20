# Write your MySQL query statement below
# using group by 
select  email from Person group by email having count(email)>1;