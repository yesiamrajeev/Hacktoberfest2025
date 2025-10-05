/*
 Hacktoberfest 2025 Contribution
 Problem: Employee Maximum Earnings

 Description:
 We define an employee's total earnings to be (months * salary).
 We need to:
   1. Find the maximum total earnings among all employees.
   2. Find the number of employees who have this maximum earnings.
   3. Print both values as space-separated integers.

 Table Structure:
   Employee(employee_id INT, name VARCHAR, months INT, salary INT)
*/

-- Query to get maximum earnings and number of employees with it
SELECT
    MAX(total_earnings) AS max_earnings,
    COUNT(*) AS num_employees
FROM (
    SELECT
        employee_id,
        name,
        months * salary AS total_earnings
    FROM Employee
) AS earnings
WHERE total_earnings = (
    SELECT MAX(months * salary) FROM Employee
);
