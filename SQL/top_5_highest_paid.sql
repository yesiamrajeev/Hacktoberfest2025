-- Find the top 5 employees with the highest salary.
SELECT first_name, last_name, salary
FROM employees
ORDER BY salary DESC
    LIMIT 5;