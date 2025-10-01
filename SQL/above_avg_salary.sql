-- Find employees earning more than the average salary of their department.
SELECT e.employee_id, e.first_name, e.last_name, e.salary, e.department_id
FROM employees e
         JOIN (
    SELECT department_id, AVG(salary) AS avg_salary
    FROM employees
    GROUP BY department_id
) dept_avg
              ON e.department_id = dept_avg.department_id
WHERE e.salary > dept_avg.avg_salary
ORDER BY e.salary DESC;