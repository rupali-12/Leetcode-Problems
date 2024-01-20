# Write your MySQL query statement below
with cte as(
select requester_id, accepter_id from RequestAccepted
union
select accepter_id as requester_id, requester_id as accepter_id from RequestAccepted
), cte2 as (select requester_id as id, count(*) as num
from cte group by requester_id)

select id, num from cte2 where num = (select max(num) from cte2);
