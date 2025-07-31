# Write your MySQL query statement below
-- without making any transacion meANs null.
-- left join both tables , count the customers through repeated customer id , join both the ytable on the basis of equality factor on them which is visit_id and where they visited without any transaction
SELECT v.customer_id , COUNT(v.customer_id) AS count_no_trans
FROM Visits v LEFT JOIN Transactions t ON v.visit_id=t.visit_id
WHERE t.visit_id IS NULL
GROUP BY v.customer_id;