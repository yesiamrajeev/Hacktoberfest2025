SELECT ProductID, SUM(Quantity) AS TotalSold,
       RANK() OVER (ORDER BY SUM(Quantity) DESC) AS Rank
FROM OrderDetails
GROUP BY ProductID;
