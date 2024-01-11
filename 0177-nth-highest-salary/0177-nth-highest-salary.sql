CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    # Write your MySQL query statement below.
    with cte as(
        select *, DENSE_RANK() over(order by salary desc) as rnk from employee
    )
    select distinct salary from cte where rnk = N
  );
END

