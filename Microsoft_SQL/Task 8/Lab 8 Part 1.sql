-- Lab 8 Part 1
use ITI

--------------------------------------------------------------------------------------------------------------------------------
-- 1. Create a view that displays student full name, course name if the student has a grade more than 50. 
SELECT * FROM Student

ALTER VIEW StudView(Fullname, Cname)
	WITH ENCRYPTION
		AS
			SELECT CONCAT(S.St_Fname, ' ', S.St_Lname), CS.Crs_Name FROM Student S JOIN Stud_Course C ON S.St_Id = C.St_Id JOIN Course CS ON C.Crs_Id = CS.Crs_Id WHERE C.Grade > 50  

SELECT * FROM StudView

--------------------------------------------------------------------------------------------------------------------------------	
-- 2. Create an Encrypted view that displays manager names and the topics they teach. 
SELECT * FROM Names
SELECT * FROM Course
SELECT * FROM Topic
SELECT * FROM Ins_Course
SELECT * FROM Instructor
SELECT * FROM Department
SELECT * FROM Student

ALTER VIEW ManagerTopics(Mname, TopName)
	WITH ENCRYPTION
		AS
			SELECT I.Ins_Name, T.Top_Name FROM Instructor I JOIN Ins_Course IC ON I.Ins_Id = IC.Ins_Id JOIN Course C ON IC.Crs_Id = C.Crs_Id JOIN Topic T ON C.Top_Id = T.Top_Id

GO
	SELECT * FROM ManagerTopics

--------------------------------------------------------------------------------------------------------------------------------
-- 3. Create a view that will display Instructor Name, Department Name for the ‘SD’ or ‘Java’ Department 
ALTER VIEW InsDepSDJAVA(InsName, DepName)
	WITH ENCRYPTION
		AS
			SELECT I.Ins_Name, D.Dept_Name FROM Instructor I JOIN Department D ON I.Dept_Id = D.Dept_Id WHERE D.Dept_Name IN ('Java', 'SD')
GO

	SELECT * FROM InsDepSDJAVA

--------------------------------------------------------------------------------------------------------------------------------
/* 4.	 Create a view “V1” that displays student data for student who lives in Alex or Cairo. 
Note: Prevent the users to run the following query 
Update V1 set st_address=’tanta’
Where st_address=’alex’;
*/

-- Firstway changed the name

ALTER VIEW StdD(Stid, Stn, stl, stadd, sta, sdpt, sts)
	WITH ENCRYPTION
		AS
			SELECT * FROM Student WHERE St_Address IN ('Cairo', 'Alex')

GO
	SELECT * FROM StdD
	UPDATE StdD SET St_address = 'tanta'

-- Secondway used Check Option

CREATE VIEW StdD2
	WITH ENCRYPTION
		AS
			SELECT * FROM Student WHERE St_Address IN ('Cairo', 'Alex')
			WITH CHECK OPTION

GO
	SELECT * FROM StdD
	UPDATE StdD2 SET St_address = 'tanta'

--------------------------------------------------------------------------------------------------------------------------------
--5.	Create a view that will display the project name and the number of employees work on it. “Use SD database”
USE SD
SELECT * FROM Department
SELECT * FROM Employee
SELECT * FROM Project 
SELECT * FROM Works_on

ALTER VIEW PnameE([Project name], [Number of Employees])
	WITH ENCRYPTION
		AS
			SELECT P.ProjectName, COUNT(W.ProjectNO) FROM SD.dbo.Project P JOIN SD.dbo.Works_on W ON P.ProjectNo = W.ProjectNo GROUP BY P.ProjectName
		WITH CHECK OPTION
GO
	SELECT * FROM PnameE

--------------------------------------------------------------------------------------------------------------------------------
--6.	Create index on column (Hiredate) that allow u to cluster the data in table Department. What will happen?
use ITI
SELECT * FROM Department

CREATE CLUSTERED INDEX HireD
	ON Department(Manager_hiredate)

/* --Results: 
-- Cannot create more than one clustered index on table 'Department'. Drop the existing clustered index 'PK_Department' before creating another.

 The primary key of the table is a clustered index by default
and you are only allowed (one clustered key per Table) */ 


--------------------------------------------------------------------------------------------------------------------------------
-- 7.	Create index that allow u to enter unique ages in student table. What will happen?

SELECT * FROM Student

CREATE UNIQUE INDEX StAge
	ON Student(St_age)

--Results: 
--The CREATE UNIQUE INDEX statement terminated because a duplicate key was found for the object name 'dbo.Student' a
--nd the index name 'i4'. The duplicate key value is (21).

/* We already have duplicates so we can't create a unique index on that column*/

--------------------------------------------------------------------------------------------------------------------------------
-- 8.	Using Merge statement between the following two tables [User ID, Transaction Amount]
	CREATE TABLE DailyTransactions
	(
		UserID INT,
		TransactionAmount INT
	)
GO
	INSERT INTO DailyTransactions VALUES (1,1000), (2, 2000), (3, 1000)

GO

	CREATE TABLE LastTransactions
	(
		UserID INT,
		TransactionAmount INT
	)
GO
	INSERT INTO LastTransactions VALUES (1,4000), (4, 2000), (2, 10000)

--Merging
	
	MERGE INTO LastTransactions AS L
	USING DailyTransactions AS D
	ON D.UserID = L.UserID

	WHEN MATCHED THEN
		UPDATE SET L.UserID = D.UserID, L.TransactionAmount = D.TransactionAmount
	
	WHEN NOT MATCHED THEN
		INSERT (UserID, TransactionAmount)
		VALUES (D.UserID, D.TransactionAmount);
GO
	SELECT * FROM LastTransactions ORDER BY UserID
	SELECT * FROM DailyTransactions
