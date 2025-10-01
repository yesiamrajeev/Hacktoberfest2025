-- Increase salary by 10% for employees earning less than 40,000.
UPDATE employees
SET salary = salary * 1.10
WHERE salary < 40000;

-- Verify changes
SELECT employee_id, first_name, last_name, salary
FROM employees
WHERE salary < 44000;