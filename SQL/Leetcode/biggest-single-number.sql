WITH cte AS (
  SELECT num
  FROM MyNumbers
  GROUP BY num
  HAVING count(num)=1
)
SELECT
  CASE
    WHEN count(*)>0 THEN max(num)
    ELSE NULL
  END AS num
FROM cte