-- Count how many employees hold each job title.
SELECT job_id, COUNT(*) AS total_employees
FROM employees
GROUP BY job_id
ORDER BY total_employees DESC;