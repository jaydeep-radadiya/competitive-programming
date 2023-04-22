-- a+b>c && b+c>a && a+c>b


SELECT *,
CASE
    WHEN x+y>z AND y+z>x AND x+z>y THEN 'Yes'
    ELSE 'No'
END AS triangle
FROM Triangle