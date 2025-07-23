# Write your MySQL query statement below
# makes self join 
select e.name as Employee 
from  Employee e
JOIN 
    Employee m 
ON 
    e.managerId = m.id
WHERE 
    e.salary > m.salary;
