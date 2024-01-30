-- Lab 5 Part 1
USE ITI



--Query 1 --------------------------------------------------------------------------------------------------------------------------------
SELECT COUNT(St_Age) FROM Student

--Query 2 --------------------------------------------------------------------------------------------------------------------------------
SELECT DISTINCT Ins_Name FROM Instructor

--Query 3 --------------------------------------------------------------------------------------------------------------------------------
SELECT ISNULL(St_Id , 'Studentid')  AS [Student ID], ISNULL(St_Fname + ' ' + St_Lname, 'Student Full Name') AS [Student Full Name], ISNULL(D.Dept_Name, 'Department Name') AS [Department Name]
FROM Student S
LEFT JOIN Department D
ON S.Dept_Id = D.Dept_Id


--Query 4 --------------------------------------------------------------------------------------------------------------------------------
SELECT Ins_Name, Dept_Name
FROM Instructor I
LEFT JOIN Department D
ON I.Dept_Id = D.Dept_Id


--Query 5 --------------------------------------------------------------------------------------------------------------------------------
SELECT S.St_Fname + S.St_Lname AS [Student Full Name], Crs_Name AS [Course Name]
FROM Student S
JOIN Stud_Course C
ON S.St_Id = C.St_Id
JOIN Course CR
ON CR.Crs_Id = C.Crs_Id
WHERE C.Grade IS NOT NULL


--Query 6 --------------------------------------------------------------------------------------------------------------------------------
SELECT COUNT(C.TOP_Id)
FROM Course C
JOIN Topic T
ON C.Top_Id = T.Top_Id
GROUP BY T.Top_Id

--Query 7 --------------------------------------------------------------------------------------------------------------------------------


--Adding Salaries to Table
UPDATE Instructor
SET Salary = NULL
WHERE Ins_Id = 14

--Checking Table
select * from Instructor

SELECT MAX(Salary) AS [MAX Salary], MIN(Salary) AS [Min Salary] FROM Instructor

--Query 8 --------------------------------------------------------------------------------------------------------------------------------
SELECT * FROM Instructor
WHERE Salary < (SELECT AVG(Salary) FROM Instructor)

--Query 9 --------------------------------------------------------------------------------------------------------------------------------
SELECT D.Dept_Name
FROM Department D
JOIN Instructor I
ON D.Dept_Id = I.Dept_Id
WHERE I.Salary = (SELECT MIN(Salary) FROM Instructor)

--Query 10 --------------------------------------------------------------------------------------------------------------------------------
SELECT TOP 2 Salary FROM Instructor ORDER BY Salary DESC

--Query 11 --------------------------------------------------------------------------------------------------------------------------------
SELECT Ins_Name, COALESCE(CONVERT(VARCHAR(10),Salary),'Bouns')
FROM Instructor

--Query 12 --------------------------------------------------------------------------------------------------------------------------------
SELECT AVG(Salary) FROM Instructor

--Query 13 --------------------------------------------------------------------------------------------------------------------------------
SELECT S.St_Fname, ST.*
FROM Student S
JOIN Student ST
ON ST.St_Id = S.St_super

--Query 14 --------------------------------------------------------------------------------------------------------------------------------
SELECT * FROM (SELECT Salary, DENSE_RANK() OVER(Partition BY dept_id ORDER BY Salary DESC) AS DR FROM Instructor) AS newTABLE WHERE DR <= 2

--Query 15 --------------------------------------------------------------------------------------------------------------------------------
SELECT * FROM (SELECT *,ROW_NUMBER() OVER(Partition BY dept_id ORDER BY newid()) AS RN FROM Student) as newtable
WHERE RN = 1


