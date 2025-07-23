# Write your MySQL query statement below
SELECT 
    p.name as Customers 
   
    
FROM 
    Customers p
LEFT JOIN 
    Orders a
ON 
    p.id = a.customerId
WHERE
a.customerId IS NULL;

--     ##subquery
-- SELECT name AS Customers
-- FROM Customers
-- WHERE id NOT IN (SELECT customerId FROM Orders);
