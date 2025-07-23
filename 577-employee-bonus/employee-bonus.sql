# Write your MySQL query statement below
SELECT 
    p.name, 
    a.bonus
    
FROM 
    Employee p
LEFT JOIN 
    Bonus a
ON 
    p.empId = a.empId
WHERE
   a.Bonus <  1000 or a.Bonus IS NULL
