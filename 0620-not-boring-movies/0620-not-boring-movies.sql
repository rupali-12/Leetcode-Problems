# Write your MySQL query statement below
# select * from cinema where description != "boring" and  id mod 2 !=0 order by rating desc; 
# select * from cinema where description <> "boring" and  id mod 2 !=0 order by rating desc; 

select * from cinema where description<> 'boring' and id mod 2=1 order by rating desc;