# Write your MySQL query statement below

SELECT p.project_id, ROUND(AVG(e.experience_years),2) AS average_years
FROM Project p 
LEFT JOIN Employee e
ON p.employee_id = e.employee_id
GROUP BY p.project_id

#do left join on condition that p.empid= e.empid, group by projectid, then calculate the mean of expereince years and then display it as average years.