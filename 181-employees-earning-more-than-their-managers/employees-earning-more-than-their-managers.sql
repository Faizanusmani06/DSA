/* Write your T-SQL query statement below */

SELECT e.name as Employee
FROM Employee as e 
INNER JOIN Employee as m on e.managerId = m.id
WHERE e.salary > m.salary