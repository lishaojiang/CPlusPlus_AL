select Email from Person group by Email having count(*) > 1


#use self join
select distinct a.Email from Person a JOIN Person b ON (a.Email = b.Email) where a.ID <> b.ID

#use subquery with exists
select distinct a.Email from Person a Where Exists (Select 1 from Person b where a.Email = b.Email limit 1,1)

#basic idea this query
select distinct a.Email from Person a left join (select ID,Email from Person Group BY Email)
b ON (a.Email = b.Email) AND (a.Id = b.Id) where b.Email IS NULL