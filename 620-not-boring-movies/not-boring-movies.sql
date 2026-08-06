# Write your MySQL query statement below
select *
from cinema
where id %2 = 1 
And description != 'boring'
order by rating desc;