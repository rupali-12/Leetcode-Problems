# Write your MySQL query statement below


with cte as(
select query_name, rating/position as ratio, case when rating<3 then 1 else 0 end as quality_bin from queries)


select query_name, round(avg(ratio), 2) as quality, round((sum(quality_bin) / count(*)) * 100 ,2) as poor_query_percentage
from cte 
where query_name is not null
group by query_name;

