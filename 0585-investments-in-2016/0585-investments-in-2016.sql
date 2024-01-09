# Write your MySQL query statement below
with cte as(
select concat(lat,',', lon) as location from Insurance group by lat, lon having count(pid)>1
), cte2 as
(select distinct I1.*
from Insurance I1 left join Insurance I2 on I1.tiv_2015 = I2.tiv_2015 where I1.pid != I2.pid
and concat(I1.lat, ',', I1.lon) not in (select location from cte))

select round(sum(tiv_2016) ,2) as tiv_2016 from cte2;
