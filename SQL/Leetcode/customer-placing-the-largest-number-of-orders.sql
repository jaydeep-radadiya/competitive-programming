-- just 1 customer has max order
SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY count(order_number) DESC
LIMIT 1


-- more than 1 customer has max order
WITH cte AS (
  SELECT customer_number, count(order_number) AS num_orders
  FROM Orders
  GROUP BY customer_number
)
SELECT customer_number
FROM cte
WHERE num_orders=(SELECT max(num_orders) FROM cte)