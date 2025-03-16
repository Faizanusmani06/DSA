/* Write your T-SQL query statement below */

SELECT c.name as Customers
FROM Customers as c LEFT JOIN Orders as o on c.Id = o.CustomerId
WHERE o.Id IS NULL