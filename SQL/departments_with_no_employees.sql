-- Find departments which currently have no employees.
SELECT d.department_id, d.department_name
FROM departments d
         LEFT JOIN employees e
                   ON d.department_id = e.department_id
WHERE e.employee_id IS NULL;