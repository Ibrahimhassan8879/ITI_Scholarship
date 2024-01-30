-- Lab 7
use ITI

--------------------------------------------------------------------------------------------------------------------------------
-- Function 1 -> Create a scalar function that takes date and returns Month name of that
DROP FUNCTION getMonthName

GO
	CREATE FUNCTION getMonthName(@x DATE)
	RETURNS NVARCHAR(10)
		BEGIN
			RETURN DATENAME(MONTH, @x)
		END
GO

	SELECT dbo.getMonthName(GETDATE())

--------------------------------------------------------------------------------------------------------------------------------
-- Function 2 -> Create a multi-statements table-valued function that takes 2 integers and returns the values between them.
GO
	ALTER FUNCTION getValuesBetweenTwoInts (@StartingNumber INT, @EndNumber INT)
	RETURNS @TableofNumbers TABLE (Numbers INT)
		
		BEGIN
		DECLARE @CurrentNumber INT = @StartingNumber
		WHILE @CurrentNumber < @EndNumber - 1
			BEGIN
				SET @CurrentNumber += 1
				INSERT @TableofNumbers VALUES (@CurrentNumber)
			END
		RETURN
	END
GO

	SELECT * FROM getValuesBetweenTwoInts(1, 6)
		

DROP FUNCTION getValuesBetweenTwoInts

--------------------------------------------------------------------------------------------------------------------------------
-- Function 3 -> Create inline function that takes Student No and returns Department Name with Student full name.
SELECT * FROM Student
SELECT * FROM Department

GO
	ALTER FUNCTION StudDep(@StudentNo INT)
	RETURNS @DataLine TABLE (StudentName NVARCHAR(25))

		BEGIN
		DECLARE @StudentName NVARCHAR(25)
		DECLARE @DepartmentName NVARCHAR(25)

		SELECT @DepartmentName = D.Dept_Name FROM Student S JOIN Department D ON S.Dept_Id = D.Dept_Id WHERE S.St_Id = @StudentNo
		SELECT @StudentName =CONCAT(S.St_Fname, ' ' ,S.St_Lname) FROM Student S WHERE St_Id = @StudentNo
		INSERT @DataLine VALUES (@StudentName)

		
	RETURN

	END
GO

	SELECT * FROM StudDep(5)

--------------------------------------------------------------------------------------------------------------------------------
--4. Create a scalar function that takes Student ID and returns a message to
--user
		--a. If first name and Last name are null then display 'First name &
		--last name are null'
		--b. If First name is null then display 'first name is null'
		--c. If Last name is null then display 'last name is null'
		--d. Else display 'First name & last name are not null'

GO
	ALTER FUNCTION NameVerfication(@StudentId INT)
	RETURNS NVARCHAR(100)

		BEGIN
			DECLARE @StudentFirstName NVARCHAR(20)
			DECLARE @StudentLastName  NVARCHAR(20)
			
			SELECT @StudentFirstName=ISNULL(St_Fname,'0') FROM Student WHERE St_Id = @StudentId
			SELECT @StudentLastName=ISNULL(St_Lname,'0') FROM Student WHERE St_Id = @StudentId

			IF ( @StudentFirstName = '0' AND @StudentLastName = '0' )
				RETURN 'First name & last name are not null'
			ELSE IF ( @StudentFirstName = '0' )
				RETURN 'first name is null'
			ELSE IF ( @StudentLastName = '0' )
				RETURN 'last name is null'

			RETURN 'First name & last name are not null'
		END
GO

select dbo.NameVerfication(1)  --first null
select dbo.NameVerfication(13)  --last null
select dbo.NameVerfication(5)  --nothing null

--------------------------------------------------------------------------------------------------------------------------------
--5. Create inline function that takes integer which represents manager ID
--and displays department name, Manager Name and hiring date


SELECT * FROM Student
SELECT * FROM Department
SELECT * FROM Instructor

SELECT * FROM Course
SELECT * FROM Stud_Course
SELECT * FROM Ins_Course

GO
		ALTER FUNCTION MangerInfo(@mangerID int)
		RETURNS TABLE
		AS
		RETURN (
			-- We must use (as) after CONCAT to define the result
			SELECT Dept_Name,Ins_Name AS MangerName,Manager_hiredate
			FROM Department inner join Instructor
			ON Department.Dept_Id = Instructor.Dept_Id
			WHERE Ins_Id = @mangerID
			)
GO


-- calling 

select * from MangerInfo(4)
select * from MangerInfo(15)

go

--------------------------------------------------------------------------------------------------------------------------------
--6. Create multi-statements table-valued function that takes a string
		--If string='first name' returns student first name
		--If string='last name' returns student last name
		--If string='full name' returns Full Name from student table
		--Note: Use “ISNULL” function


ALTER FUNCTION getStuds(@Entry VARCHAR(20))
RETURNS @Data TABLE (naming VARCHAR(50))
AS
BEGIN
    DECLARE @Message NVARCHAR(50)

    IF @Entry = 'first name'
        INSERT INTO @Data SELECT St_Fname FROM Student
    ELSE IF @Entry = 'last name'
        INSERT INTO @Data SELECT St_Lname FROM Student
    ELSE IF @Entry = 'fullname'
        INSERT INTO @Data SELECT CONCAT(St_Fname, ' ', St_Lname) FROM Student

    RETURN
END
GO

select * from getStuds('first name')

select * from getStuds('last name')

select * from getStuds('fullname')

--------------------------------------------------------------------------------------------------------------------------------
--7. Write a query that returns the Student No and Student first name
--without the last char

select * from Student -- testing
select * from Department -- testing
select * from Stud_Course -- testing

select St_Id, SUBSTRING(St_Fname,1,LEN(St_Fname)-1) as firstNameWithoutTheLastChar 
FROM Student;


--------------------------------------------------------------------------------------------------------------------------------
--8. Wirte query to delete all grades for the students Located in SD

delete from Stud_Course
from Department D inner join Student S
	on D.Dept_Id = S.Dept_Id inner join Stud_Course C
	on C.St_Id = S.St_Id
	where D.Dept_Name = 'SD'