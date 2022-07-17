# Write your MySQL query statement below
select name as Customers from Customers where NOT EXISTS (select * from Orders where  Orders.customerId = Customers.id);
