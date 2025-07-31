# Write your MySQL query statement below
 select s.name
from SalesPerson s
where s.name not in
    (select s.name
    from SalesPerson s
        left join Orders o on s.sales_id = o.sales_id
        left join Company c on o.com_id = c.com_id
    where c.name = 'Red')
--     1. FROM SalesPerson s
-- You start with the SalesPerson table.

-- 2. LEFT JOIN Orders o ON s.sales_id = o.sales_id
-- You bring in matching orders made by each salesperson (if any).

-- If a salesperson has no orders, you still keep the row — with NULL in Orders.

-- 3. LEFT JOIN Company c ON o.com_id = c.com_id
-- For each order, you attach the company info.

-- If the order's com_id doesn't match any company, c.name will be NULL.