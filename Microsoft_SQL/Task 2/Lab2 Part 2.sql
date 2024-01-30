--Lab 2_Part_2
USE Company_SD


--Query 1 --------------------------------------------------------------------------------------------------------------------------------
SELECT * FROM Employee

--Query 2 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.Fname AS [First Name], E.Lname AS [Last Name], E.Salary AS [Salary], E.Dno AS [Department Number]
FROM Employee E

--Query 3 --------------------------------------------------------------------------------------------------------------------------------
SELECT P.Pname AS [Project Name], P.Plocation AS [Project Location], P.Dnum AS [Department Number]
FROM Project P

--Query 4 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.Fname + ' ' + E.Lname AS [Employee Full Name], 0.10*12*E.Salary AS [Annual Commission]
FROM Employee E

--Query 5 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.SSN AS [Employee ID], E.Fname + ' ' + E.Lname AS [Employee Full Name]
FROM Employee E
WHERE Salary > 1000

--Query 6 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.SSN AS [Employee ID], E.Fname + ' ' + E.Lname AS [Employee Full Name]
FROM Employee E
WHERE Salary*12 > 10000

--Query 7 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.Fname + ' ' + E.Lname AS [Employee Full Name], E.Salary AS [Salary]
FROM Employee E
WHERE Sex = 'F'

--Query 8 --------------------------------------------------------------------------------------------------------------------------------
SELECT D.Dnum AS [Department ID], D.Dname AS [Department Name]
FROM Departments D
WHERE MGRSSN = 968574

--Query 9 --------------------------------------------------------------------------------------------------------------------------------
SELECT P.Pnumber AS [Project ID], P.Pname AS [Project Name], P.Plocation AS [Project Location]
FROM Project P
WHERE P.Dnum = 10
