# Write your MySQL query statement below
SELECT (
  SELECT DISTINCT salary
  FROM Employee
  ORDER BY salary DESC
  LIMIT 1 OFFSET 1
) AS SecondHighestSalary;
-- Use LIMIT 1 OFFSET 1 to skip the top salary and fetch the second unique one.
-- limit -Specifies how many rows you want to return.
-- offset-Specifies how many rows to skip before starting to return rows.