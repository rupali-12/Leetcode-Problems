# Write your MySQL query statement below

# subquery 

# select round( (sum(case when order_date = customer_pref_delivery_date then 1 else 0 end)*100)/ count(distinct customer_id) ,2) as immediate_percentage from delivery where (customer_id, order_date) in (select customer_id, min(order_date) as first_order_date from delivery group by customer_id);




# Using rank 

with cte as (
select *, rank() over(partition by customer_id order by order_date) as order_number, case when order_date= customer_pref_delivery_date then 'immediate' else 'scheduled' end as order_type from delivery
)

select round(sum(case when order_type='immediate' then 1 else 0 end)/count(*)*100 ,2) as immediate_percentage from cte where order_number =1;