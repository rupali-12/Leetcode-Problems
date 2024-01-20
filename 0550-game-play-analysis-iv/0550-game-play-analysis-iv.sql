# Write your MySQL query statement below
with cte as(
select player_id ,min(event_date) as first_login from activity group by player_id
), cte2 as(
select *, DATE_ADD(first_login, INTERVAL 1 day) as next_date from cte 
)

select round((
select count(distinct player_id)
from activity where (player_id, event_date)  in (select player_id, next_date from cte2)
)/ (select count(distinct player_id) from activity) ,2) as fraction