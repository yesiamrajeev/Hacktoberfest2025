-- Find all employees whose salary is greater than 50,000.
SELECT employee_id, first_name, last_name, salary
FROM employees
WHERE salary > 50000
ORDER BY salary DESC;