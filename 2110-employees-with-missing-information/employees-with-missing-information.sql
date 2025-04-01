/* Write your T-SQL query statement below */

select isNull(e.employee_id, s.employee_id) as employee_id
from Employees e
full join Salaries s
on e.employee_id = s.employee_id
where e.employee_id is NUll or s.employee_id is null
order by employee_id