# Write your MySQL query statement below
SELECT sell_date, count(DISTINCT(PRODUCT)) as num_sold ,
GROUP_CONCAT(DISTINCT product )
as products
from Activities group by sell_date ;