# Write your MySQL query statement below
# select s.student_id, s.student_name, sub.subject_name, count(e.student_id) as attended_exams from students s cross join subjects sub left join examinations e on s.student_id = e.student_id and e.subject_name = sub.subject_name group by s.student_id, s.student_name, sub.subject_name order by s.student_id, sub.subject_name;


# *****************************************************************
# way-2
# cte
# 1 alice math 
# 1 alice physics 
# .........

# cte2
# 1 math 3 
# 1 physics 2 
# .....

with cte as(
select * from students cross join subjects
), cte2 as(
select student_id, subject_name, count(subject_name) as countSub from examinations group by student_id, subject_name
) 

select cte.student_id, cte.student_name, cte.subject_name, case when countSub is not null then countSub else 0 end as attended_exams from cte left join cte2 on cte.student_id = cte2.student_id and  cte.subject_name = cte2.subject_name order by cte.student_id, cte.subject_name; 



