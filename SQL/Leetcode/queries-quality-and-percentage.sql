WITH cte AS (
  SELECT query_name, rating/position AS ratio,
    CASE WHEN rating<3 THEN 1
    ELSE 0 END AS quality_binary
  FROM Queries
)
SELECT query_name, round(avg(ratio),2) AS quality, round((sum(quality_binary)/count(*))*100,2) AS poor_query_percentage
FROM cte
GROUP BY query_name