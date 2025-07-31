#it groups by the customer_number , arrange in asceding order the count and then it returns the first row which has the the given number of orders.
select customer_number
from orders
group by customer_number
order by count(*) DESC limit 1;