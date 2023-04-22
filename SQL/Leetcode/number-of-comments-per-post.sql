-- no need to write WITH everytime, just put comma


WITH posts AS (
    SELECT DISTINCT sub_id
    FROM Submissions
    WHERE parent_id IS NULL
),
comments AS (
    SELECT parent_id, count(DISTINCT sub_id) AS number_of_comments
    FROM Submissions
    WHERE parent_id is not null
    GROUP BY parent_id
)
SELECT sub_id AS post_id,
    CASE WHEN number_of_comments IS NULL THEN 0
    ELSE number_of_comments END
FROM posts p
LEFT JOIN comments c
ON p.sub_id=c.parent_id
ORDER BY post_id