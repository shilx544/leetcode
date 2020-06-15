# Write your MySQL query statement below

select FirstName, LastName, City, State
from
(select PersonId, FirstName, LastName from Person) a
left join
(select PersonId, City, State from Address) b
on a.PersonId = b.personId