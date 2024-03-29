# Write your MySQL query statement below
with cte as(
select o.com_id , o.sales_id from orders o left join company c on o.com_id = c.com_id where c.name like 'RED'
)

# com_id   sales_id 
#   1         1
#   1         4
# # Way-1>>>>
# select s.name from salesperson s left join cte c on c.sales_id = s.sales_id where c.com_id is null;

# # way-2>> 
select name from salesperson where sales_id  not in (select distinct sales_id from cte);