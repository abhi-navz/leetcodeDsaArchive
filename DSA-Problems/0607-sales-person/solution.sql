# Write your MySQL query statement below
     
-- we'll use subquery to find the list of sale_id who sold to company red and then we'll use "NOT IN" clause to find those who didn't sold to red.

-- finding sales id of those who sold to red
-- select o.sales_id 
-- from orders o join company c
-- on o.com_id = c.com_id
-- where c.name = 'red'; 

select name 
from salesPerson
where sales_id
NOT IN (
        select o.sales_id 
        from orders o join company c
        on o.com_id = c.com_id
        where c.name = 'red'
    ) 
