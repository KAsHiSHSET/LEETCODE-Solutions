# Write your MySQL query statement below
SELECT 
    d.Name AS Department,      -- Selects department name
    e.Name AS Employee,        -- Selects employee name
    e.Salary  AS Salary               -- Selects employee salary
FROM 
    Employee e                 -- Main table is Employee
JOIN 
    Department d ON e.DepartmentId = d.Id  -- Join with Department to get department names
WHERE 
    e.Salary = (                             -- Filter only those employees...
        SELECT MAX(Salary)                   -- ...whose salary is equal to the max salary
        FROM Employee                        -- ...within the same department
        WHERE DepartmentId = e.DepartmentId  -- (correlated subquery)
    );
