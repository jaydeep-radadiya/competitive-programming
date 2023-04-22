-- to filter record 1) WHERE 2) HAVING
-- HAVING used to apply filter on aggregated values


SELECT email AS Email
FROM Person
GROUP BY email
HAVING count(id)>1