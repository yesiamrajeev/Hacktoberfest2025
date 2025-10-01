-- Join employees and departments to get department names.
SELECT e.employee_id, e.first_name, e.last_name, d.department_name
FROM employees e
         JOIN departments d
              ON e.department_id = d.department_id
ORDER BY d.department_name;