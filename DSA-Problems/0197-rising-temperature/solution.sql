# Write your MySQL query statement below
select curr.id from weather curr join weather prev on 
curr.recordDate = prev.recordDate + interval 1 Day
where curr.temperature > prev.temperature;
