-- if values not in ascending order
-- CROSS JOIN return all posible combinations, so no need of ON clause

SELECT min(abs(p1.x-p2.x)) AS shortest
FROM Point p1
CROSS JOIN Point p2
WHERE p1.x!=p2.x


-- if values in ascending order

SELECT min(abs(p1.x-p2.x)) AS shortest
FROM Point p1
JOIN Point p2
WHERE p1.x<p2.x