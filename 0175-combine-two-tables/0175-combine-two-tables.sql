# Write your MySQL query statement below
select p.firstName, p.lastname, a.city, a.state from person as p left join address as a using (personId);  