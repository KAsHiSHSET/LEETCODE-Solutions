# Write your MySQL query statement below
SELECT TEACHER_ID, COUNT(DISTINCT SUBJECT_ID) AS CNT FROM TEACHER GROUP BY TEACHER_ID;
#first group by teacher_id then show teacher_id, count(distinct subject_id) from the table