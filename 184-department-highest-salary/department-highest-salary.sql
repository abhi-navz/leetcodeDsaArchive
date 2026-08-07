# Write your MySQL query statement below
select d.name as Department, e1.name as Employee , e1.salary as Salary
from  Employee e1 join Department d 
on e1.departmentId = d.id
where e1.salary = (
    select max(salary) 
    from employee e2 
    where e2.departmentId = e1.departmentId  -- already restricts the department to just one dept
);


-- this is correlated subquery where the subquery runs for each row of outer query 
