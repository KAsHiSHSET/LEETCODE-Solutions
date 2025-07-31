# Write your MySQL query statement below
SELECT P.product_name, S.year, S.price
FROM Sales AS S, Product AS P
WHERE P.product_id=S.product_id;