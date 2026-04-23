# xiebaoma
# 2025-07-29

SELECT p.FirstName, p.LastName, a.City, a.state
FROM Person AS p
LEFT JOIN Address AS a
ON p.PersonId = a.PersonId;