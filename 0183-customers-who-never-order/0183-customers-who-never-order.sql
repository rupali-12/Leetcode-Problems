# Write your MySQL query statement below

# Without join
select name as Customers from Customers where id not in (select customerid from orders);