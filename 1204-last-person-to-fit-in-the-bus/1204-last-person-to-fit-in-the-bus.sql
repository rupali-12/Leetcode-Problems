# Write your MySQL query statement below
with cte as(
select *, sum(weight) over(order by turn rows between unbounded preceding and current row) as currweight from queue
)

# +-----------+-------------+--------+------+
# | person_id | person_name | weight | turn | currweight
# +-----------+-------------+--------+------+
# | 5         | Alice       | 250    | 1    |    250
# | 3         | Alex        | 350    | 2    |    600
# | 6         | John Cena   | 400    | 3    |    1000
# | 2         | Marie       | 200    | 4    |    1200
# | 4         | Bob         | 175    | 5    |    1375
# | 1         | Winston     | 500    | 6    |    1875
# +-----------+-------------+--------+------+

select person_name from cte where currweight <= 1000 order by currweight desc limit 1;