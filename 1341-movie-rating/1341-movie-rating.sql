# Write your MySQL query statement below
with cte as(
select mr.*, u.name, m.title from MovieRating mr left join users u on mr.user_id= u.user_id left join movies m on mr.movie_id =m.movie_id 
)

# +-------------+--------------+--------------+-------------+
# | movie_id    | user_id      | rating       | created_at  |  name |     title
# +-------------+--------------+--------------+-------------+   
# | 1           | 1            | 3            | 2020-01-12  |  daniel     avengers
# | 1           | 2            | 4            | 2020-02-11  |  monica     avengers
# | 1           | 3            | 2            | 2020-02-12      marie     avengers
# | 1           | 4            | 1            | 2020-01-01  |   james     avengers
# | 2           | 1            | 5            | 2020-02-17  |    daniel    frozen
# | 2           | 2            | 2            | 2020-02-01  |  monica      frozen
# | 2           | 3            | 2            | 2020-03-01  |   marie      frozen
# | 3           | 1            | 3            | 2020-02-22  |  daniel      joker
# | 3           | 2            | 4            | 2020-02-25  |   monica     joker 
# +-------------+--------------+--------------+-------------+


(select name as results from cte group by name order by count(*) desc, name limit 1)
union all
(select title  from cte where DATE_FORMAT(created_at, '%Y-%m')='2020-02' group by title
 order by avg(rating) desc, title limit 1)