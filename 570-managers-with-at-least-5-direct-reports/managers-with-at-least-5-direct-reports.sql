# Write your MySQL query statement below
select m.name from employee m
left join employee e
on m.id = e.managerId 
group by m.id, m.name  -- m.name coz sql reqire every selected column to appear in either group by or aggreage.
having count(e.id) >= 5;
