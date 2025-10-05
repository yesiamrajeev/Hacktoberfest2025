SELECT *
FROM (
  SELECT *, ROW_NUMBER() OVER (PARTITION BY DepartmentID ORDER BY Salary DESC) AS rn
  FROM Employee
) AS Ranked
WHERE rn <= 3;
