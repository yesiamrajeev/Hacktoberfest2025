SELECT Email, COUNT(*) AS Occurrences
FROM Users
GROUP BY Email
HAVING COUNT(*) > 1;
