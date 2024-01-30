-- Lab 9 ITI Part
USE ITI

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- 1) Create a stored procedure without parameters to show the number of students per department name.[use ITI DB] 
SELECT * FROM Student
SELECT * FROM Department
GO
	ALTER PROCEDURE StudentPerDep
		AS
			SELECT COUNT(*) AS [Student Per Department], D.Dept_Name FROM Student S JOIN Department D ON S.Dept_Id = D.Dept_Id GROUP BY D.Dept_Name ORDER BY D.Dept_Name

GO
	EXECUTE StudentPerDep

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*	
	5) Create a trigger to prevent anyone from inserting a new record in the Department table [ITI DB]
“Print a message for user to tell him that he can’t insert a new record in that table”
*/
SELECT * FROM Department
GO

	ALTER TRIGGER PreventInsertDep
		ON Department
			INSTEAD OF INSERT
				AS
					SELECT 'You cannot insert a new record in that table'

GO
	INSERT INTO Department VALUES (200,'SD', 'HTML', 'Aswan',15,'2002-10-10')

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
	7) Create a trigger on student table after insert to add Row in Student Audit table (Server User Name , Date, Note) 
	where note will be “[username] Insert New Row with Key=[Key Value] in table [table name]”
*/
DROP TABLE StudentAuditTable
GO
	CREATE TABLE StudentAuditTable
	(
		ServerUSERname NVARCHAR(50),
		Date DATE,
		Note NVARCHAR(100)
	)

GO
	SELECT * FROM Student

GO
	ALTER TRIGGER StInsert
		ON Student
			AFTER INSERT
				AS
					DECLARE @Key NVARCHAR(10)
					SELECT @Key = St_ID FROM inserted
					INSERT INTO StudentAuditTable VALUES (SUSER_NAME(),GETDATE(), SUSER_NAME() + ' Insert New Row with Key= ' + @Key + ' In table Student')

GO
	INSERT INTO Student VALUES (15,'Ahmed','Amer','Tanta',28, 10,9)
	SELECT * FROM StudentAuditTable

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
	 8) Create a trigger on student table instead of delete to add Row
	 in Student Audit table (Server User Name, Date, Note) where note 
	 will be“ try to delete Row with Key=[Key Value]”
*/

SELECT * FROM Student

GO
	ALTER TRIGGER InsDelStud
		ON Student
			INSTEAD OF DELETE
				AS
					DECLARE @Key2 NVARCHAR(10)
					SELECT @Key2= St_ID FROM deleted
					INSERT INTO StudentAuditTable VALUES (SUSER_NAME(),GETDATE(), SUSER_NAME() + ' try to delete Row with Key= ' + @Key2)

GO
	DELETE FROM Student WHERE St_id = 10
	SELECT * FROM StudentAuditTable
	
use ITI

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- 10) Display Each Department Name with its instructors. “Use ITI DB”
--A) Use XML Auto

go
select * from instructor
select * from department

select Department.Dept_Name,Instructor.Ins_Name
from Instructor,Department
where Instructor.Dept_Id = Department.Dept_Id
for xml auto,elements,ROOT('InstructorsInfo')

--B) Use XML Path

select Department.Dept_Name '@DeptName' ,
		Instructor.Ins_Name 'InsName'
from Instructor,Department
where Instructor.Dept_Id = Department.Dept_Id
for xml path('Department'),elements,ROOT('DeptInfo')