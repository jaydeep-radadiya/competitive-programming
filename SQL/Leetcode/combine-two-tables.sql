-- PK has unique values and can't be NULL value
-- FK used to reference another row usually in different table
-- FK value can be NULL or refered value of another table


SELECT p.firstName, p.lastName, a.city, a.state
FROM Person p
LEFT JOIN Address a
ON p.personId=a.personId