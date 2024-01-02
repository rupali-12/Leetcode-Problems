# Write your MySQL query statement below

with cte as(
select *, lead(id) over(order by id) as next, lag(id) over(order by id) as prev from seat
)

# +----+---------+
# | id | student | next    prev
# +----+---------+
# | 1  | Abbot   |  2       null
# | 2  | Doris   |  3         1
# | 3  | Emerson |  4         2
# | 4  | Green   |  5         3
# | 5  | Jeames  |  null      4
# +----+---------+

select case when (id%2!=0 and next is not null) then next when id%2=0 then prev else id end as id, student from cte order by id; 