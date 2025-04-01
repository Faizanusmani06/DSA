/* Write your T-SQL query statement below */

select *
from Patients
where conditions LIKE 'DIAB1%' or conditions LIKE '% DIAB1%'