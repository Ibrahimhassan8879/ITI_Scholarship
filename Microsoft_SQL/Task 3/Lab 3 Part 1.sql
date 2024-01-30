--Lab 3 Part 1
USE Company_SD

--Query 1 --------------------------------------------------------------------------------------------------------------------------------
SELECT D.Dnum AS [Department ID], D.Dname AS [Department Name], D.MGRSSN AS [Manager ID],
E.Fname + ' ' + E.Lname AS [Manager Full Name]
FROM Departments D, Employee E

--Query 2 --------------------------------------------------------------------------------------------------------------------------------
SELECT D.Dname AS [Department Name], P.Pname AS [Project Name]
FROM Departments D, Project P
WHERE D.Dnum = P.Dnum

--Query 3 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.Fname + ' ' + E.Lname AS [Employee Full Name], D.*
FROM Employee E
JOIN Dependent D
ON E.SSN = D.ESSN

--Query 4 --------------------------------------------------------------------------------------------------------------------------------
SELECT P.Pnumber AS [Project ID], P.Pname AS [Project Name], P.Plocation AS [Project Location]
FROM Project P
WHERE City IN ('Cairo','Alex')

--Query 5 --------------------------------------------------------------------------------------------------------------------------------
SELECT * FROM Project WHERE Pname LIKE 'a%'

--Query 6 --------------------------------------------------------------------------------------------------------------------------------
SELECT * FROM Employee
WHERE Dno = 30 AND Salary BETWEEN 1000 AND 2000

--Query 7 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.Fname + ' ' + E.Lname AS [Employee Full Name]
FROM Employee E
JOIN Works_for W
ON E.SSN = W.ESSn
JOIN Project P
ON P.Pnumber = W.Pno
WHERE E.Dno = 10 AND W.Hours >= 10 AND P.Pname = 'AL Rabwah'

--Query 8 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.Fname + ' ' + E.Lname AS [Employee Full Name]
FROM Employee E
JOIN Employee M
ON E.Superssn = M.SSN
WHERE M.Fname + ' ' + M.Lname = 'Kamel Mohamed'

--Query 9 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.Fname + ' ' + E.Lname AS [Employee Full Name], P.Pname AS [Project Name]
FROM Employee E
JOIN Works_for W
ON E.SSN = W.ESSn
JOIN Project P
ON W.Pno = P.Pnumber
ORDER BY P.Pname

--Query 10 --------------------------------------------------------------------------------------------------------------------------------
SELECT P.Pnumber AS [Project Number], D.Dname AS [Controlling Department Name],
E.Lname AS [Department Manager Last Name], E.Address AS [Address], E.Bdate AS [Birth Date]
FROM Project P
JOIN Departments D
ON P.Dnum = D.Dnum
JOIN Employee E
ON D.MGRSSN = E.SSN
WHERE P.City = 'Cairo'


--Query 11 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.* FROM Employee E
JOIN Departments D
ON E.SSN = D.MGRSSN

--Query 12 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.* FROM Employee E
LEFT JOIN Dependent D
ON E.SSN = D.ESSN

--Query 13 --------------------------------------------------------------------------------------------------------------------------------
INSERT INTO Employee(Dno, SSN, Superssn, Salary, Fname, Lname)
VALUES (30, 102672, 112233, 3000, 'Ibrahim', 'Hassan')

--Query 14 --------------------------------------------------------------------------------------------------------------------------------
INSERT INTO Employee(Dno, SSN, Fname, Lname)
VALUES (30, 102660, 'Raouf', 'Alladin')

--Query 15 --------------------------------------------------------------------------------------------------------------------------------
UPDATE Employee
SET Salary *= 1.2
WHERE SSN = 102672