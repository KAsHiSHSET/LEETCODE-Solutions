# Write your MySQL query statement below
SELECT * FROM Cinema 
WHERE id % 2 <> 0 AND description <> "boring"
ORDER BY rating DESC;
#id is not div by 2 and description is not boring , order by descding.