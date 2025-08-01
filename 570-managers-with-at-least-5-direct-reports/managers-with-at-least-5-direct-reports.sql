# Write your MySQL query statement below
SELECT name 
FROM Employee 
WHERE id IN (
    SELECT managerId 
    FROM Employee 
    GROUP BY managerId 
    HAVING COUNT(*) >= 5)
    #inner query groups by the manager and returns the id of those manager which have the managerid >= 5
    #then we find the names for those who have the managerid >= 5.