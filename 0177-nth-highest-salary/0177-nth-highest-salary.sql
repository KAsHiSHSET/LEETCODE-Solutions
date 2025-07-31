#limit 1 means return 1 row and n-1 offset means skip n-1. 
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N-1;
  RETURN (
   SELECT DISTINCT(salary) from Employee order by salary DESC
    LIMIT 1 OFFSET N
  );
END
