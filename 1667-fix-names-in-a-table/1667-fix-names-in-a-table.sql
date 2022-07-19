# Write your MySQL query statement below
select user_id, CONCAT(SUBSTR(UPPER(name),1,1),SUBSTR(LOWER(name),2)) as name from Users order by user_id;

