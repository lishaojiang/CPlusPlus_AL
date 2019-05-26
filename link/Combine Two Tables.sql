# Write your MySQL query statement below

#first time use left join key value;

#2019/5/26

SELECT Person.FirstName,Person.LastName,Address.City,Address.State from Person Left Join Address on Person.PersonId = Address.PersonID