# Write your MySQL query statement below
       
with cte as (
select *, lead(num, 1) over() as next1, lead(num, 2) over() as next2next from logs
)

# +----+-----+
# | id | num |  next1 |   next2next
# +----+-----+
# | 1  | 1   |   1          1
# | 2  | 1   |   1          2
# | 3  | 1   |   2          1
# | 4  | 2   |   1          2
# | 5  | 1   |   2          2
# | 6  | 2   |   2         null
# | 7  | 2   |  null       null
# +----+-----+

select distinct num as ConsecutiveNums from cte where num=next1 and num=next2next;