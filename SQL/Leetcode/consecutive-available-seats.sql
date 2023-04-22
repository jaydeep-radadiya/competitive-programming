-- when you write query inside the query => try to alias sub query


SELECT DISTINCT c1.seat_id
FROM cinema c1 JOIN cinema c2
ON abs(c1.seat_id-c2.seat_id)=1
WHERE c1.free='1' AND c2.free='1'
ORDER BY c1.seat_id