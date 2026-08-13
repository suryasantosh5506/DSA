/* Write your T-SQL query statement below */
select (
    select distinct(salary) from employee
    order by salary desc
    offset 1 row
    fetch next 1 row only
) as SecondHighestSalary;