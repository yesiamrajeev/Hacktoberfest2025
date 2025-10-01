-- List employees who joined in the last 6 months.
SELECT employee_id, first_name, last_name, hire_date
FROM employees
WHERE hire_date >= DATE_SUB(CURDATE(), INTERVAL 6 MONTH)
ORDER BY hire_date DESC;