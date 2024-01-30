-- Lab 4
USE Company_SD

--Query 1 --------------------------------------------------------------------------------------------------------------------------------
SELECT D.DEPENDENT_NAME, D.SEX
FROM Dependent D
JOIN Employee E
ON E.SSN = D.ESSN
AND D.SEX = 'F' AND E.Sex = 'F'
UNION
SELECT D.DEPENDENT_NAME, D.SEX
FROM Dependent D
JOIN Employee E
ON E.SSN = D.ESSN
AND D.SEX = 'M' AND E.Sex = 'M'

--Query 2 --------------------------------------------------------------------------------------------------------------------------------
SELECT P.PNAME, SUM(W.Hours)*7
FROM Project P
JOIN Works_for W
ON P.Pnumber = W.Pno
GROUP BY P.PNAME

--Query 3 --------------------------------------------------------------------------------------------------------------------------------
SELECT * FROM Departments D
JOIN Employee E
ON D.Dnum = E.Dno
WHERE E.SSN IN (SELECT MIN(SSN) FROM Employee WHERE Dno IS NOT NULL)

--Query 4 --------------------------------------------------------------------------------------------------------------------------------
SELECT D.Dname, MAX(E.Salary), MIN(E.Salary), AVG(E.Salary)
FROM Departments D
JOIN Employee E
ON E.Dno = D.Dnum
GROUP BY D.Dname

--Query 5 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.Fname + ' ' + E.Lname AS [Manager Full Name]
FROM Employee E
JOIN Departments M
ON E.SSN = M.MGRSSN
AND E.SSN NOT IN (SELECT ESSN FROM Dependent)

--Query 6 --------------------------------------------------------------------------------------------------------------------------------
SELECT D.Dnum, D.Dname, COUNT(E.SSN)
FROM Departments D
JOIN Employee E
ON D.Dnum = E.Dno
GROUP BY D.Dnum, D.Dname
HAVING AVG(E.Salary) < (SELECT AVG(Salary) FROM Employee)

--Query 7 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.Fname + ' ' + E.Lname AS [Empoyee Full Name], P.Pname
FROM Employee E
JOIN Works_for W
ON E.SSN = W.ESSn
JOIN Project P
ON W.Pno = P.Pnumber
JOIN Departments D
ON D.Dnum = P.Dnum
ORDER BY D.Dnum, E.Lname, E.Fname

--Query 8 --------------------------------------------------------------------------------------------------------------------------------
SELECT Max(E.Salary), MAX(M.Salary) FROM Employee E, Employee M
WHERE M.Salary < E.Salary


--Query 9 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.Fname + ' ' + E.Lname AS [Employee Full Name]
FROM Employee E
JOIN Dependent D
ON E.Fname + ' ' + E.Lname = D.Dependent_name

SELECT * FROM Dependent
SELECT * FROM Employee

--Query 10 --------------------------------------------------------------------------------------------------------------------------------
SELECT E.SSN, E.Fname
FROM Employee E
JOIN Dependent D
ON E.SSN = D.ESSN
WHERE EXISTS (SELECT ESSN FROM Dependent)

--Query 11 --------------------------------------------------------------------------------------------------------------------------------
INSERT INTO Departments(Dname, Dnum, MGRSSN, [MGRStart Date])
VALUES ('DEPT IT',100,112233,1/11/2006)

--Testing
DELETE FROM Departments WHERE Dname = 'DEPT IT'
SELECT * FROM Departments
SELECT * FROM Employee

--Query 12 --------------------------------------------------------------------------------------------------------------------------------
--Inserting My SSN
INSERT INTO Employee(SSN,Fname,Lname,Bdate,Address,Sex)
VALUES (102672,'Ibrahim', 'Hassan', 3/16/1997, '15 El Salam st','M')
--A
UPDATE Departments
SET MGRSSN = 968574
WHERE Dnum = 100

--B
UPDATE Departments
SET MGRSSN = 102672
WHERE Dnum = 20

--C
INSERT INTO Employee(SSN)
VALUES (102660)

UPDATE Employee
SET Superssn = 102672
WHERE SSN = 102660

--Query 13 --------------------------------------------------------------------------------------------------------------------------------

--Information Gathering

--Department He manage
SELECT * FROM Departments
JOIN Employee
ON MGRSSN = SSN
AND Fname = 'Kamel' AND Lname = 'Mohamed'

--Employees he Supervised
SELECT * FROM Employee E
JOIN Employee M
ON E.Superssn = M.SSN
AND M.SSN IN (SELECT SSN FROM Employee WHERE Fname = 'Kamel' AND Lname = 'Mohamed')

--Dependents He have
SELECT * FROM Dependent
JOIN Employee
ON ESSN = SSN
AND SSN IN (SELECT SSN FROM Employee WHERE Fname = 'Kamel' AND Lname = 'Mohamed')

--Projects he Works
SELECT * FROM Project P
JOIN Works_for W
ON P.Pnumber = W.Pno
JOIN Employee E
ON E.SSN = W.ESSn
AND E.SSN IN (SELECT SSN FROM Employee WHERE Fname = 'Kamel' AND Lname = 'Mohamed')

SELECT * FROM Employee WHERE Fname = 'Kamel' AND Lname = 'Mohamed'
--Kamel Mohamed 223344 1970-10-15 38 Mohy el dien abo el Ezz St.Cairo M 1800 321654 Dno 10

--Set myself in his position
UPDATE Departments
SET MGRSSN = 102672
WHERE Dnum = 10

--Supervise His Employees
UPDATE Employee
SET Superssn = 102672
WHERE Superssn = 223344

--Delete his Dependents
DELETE FROM Dependent WHERE ESSN = 223344

--Manage his Projects
UPDATE Works_for
SET ESSn = 102672
WHERE ESSN = 223344

--Delete his Record IN Employee
DELETE FROM Employee WHERE SSN = 223344

--Query 14 --------------------------------------------------------------------------------------------------------------------------------
UPDATE Employee
SET Salary *= 1.3
WHERE SSN IN (SELECT ESSN FROM Works_for JOIN Project ON Pno = Pnumber AND Pname = 'Al Rabwah')

-- Check for Kamel Mohamed
SELECT * FROM Employee WHERE Fname = 'Kamel' AND Lname = 'Mohamed'