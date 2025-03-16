/* Write your T-SQL query statement below */

SELECT e.name as Employee
FROM Employee as e 
LEFT JOIN Employee as m on e.managerId = m.id
WHERE e.salary > m.salary