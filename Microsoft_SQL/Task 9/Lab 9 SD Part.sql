-- Lab 9 SD Part
USE SD

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 /*
	2)  Create a stored procedure that will check for the # of employees in 
	the project p1 if they are more than 3 print message to the user 
	“'The number of employees in the project p1 is 3 or more'” if they 
	are less display a message to the user “'The following employees 
	work for the project p1'” in addition to the first name and last 
	name of each one. [Company DB] 
*/

SELECT * FROM SD.dbo.Project
GO

	CREATE PROCEDURE CheckEmployeeProjectP1
		AS
			DECLARE @NoEmp INT
			SELECT @NoEmp = COUNT(W.EmpNo) FROM SD.dbo.Employee E JOIN SD.dbo.Works_on W ON E.EmpNo = W.EmpNo JOIN SD.dbo.Project P ON P.ProjectNo = W.ProjectNo GROUP BY W.ProjectNo HAVING W.ProjectNo = 'p1'
			IF @NoEmp >= 3
				BEGIN
					SELECT 'The number of employees in the project p1 is 3 or more'
				END
			ELSE
				BEGIN
					SELECT 'The following employees work for the project p1'
					SELECT E.EmpFname AS [Employee First Name], E.EmpLname AS [Employee Last Name] FROM SD.dbo.Employee E JOIN SD.dbo.Works_on W ON E.EmpNo = W.EmpNo JOIN SD.dbo.Project P ON P.ProjectNo = W.ProjectNo WHERE P.ProjectNo = 'p1'
				END
GO
	EXECUTE CheckEmployeeProjectP1

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
	3)  Create a stored procedure that will be used in case there is an old employee has left the project
	and a new one become instead of him. The procedure should take 3 parameters (old Emp. number, new Emp.
	number and the project number) and it will be used to update works_on table. [Company DB]
*/

SELECT * FROM SD.dbo.Works_on

GO

	ALTER PROCEDURE ChangeEmp @OldEmpID INT, @NEWEmpID INT, @ProjectNo NVARCHAR(10)
		AS
			BEGIN
				IF NOT EXISTS ( SELECT E.EmpNo FROM SD.dbo.Employee E WHERE E.EmpNo = @OldEmpID) OR 
				NOT EXISTS (SELECT E.EmpNo FROM SD.dbo.Employee E WHERE E.EmpNo = @NEWEmpID)
				BEGIN
					SELECT 'Invalid Employee ID' AS Result
				END

				ELSE
					BEGIN
						UPDATE SD.dbo.Works_on SET EmpNo = @NEWEmpID WHERE EmpNo = @OldEmpID AND ProjectNo = @ProjectNo
					END
			END

GO
	EXECUTE ChangeEmp 25348, 10102, 'p1'
	EXECUTE ChangeEmp 29346, 9031, 'p1'

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
	4)  add column budget in project table and insert any draft values in it then 
	then Create an Audit table with the following structure 
	ProjectNo 	UserName 	ModifiedDate 	Budget_Old 	Budget_New 
	p2 	Dbo 	2008-01-31	95000 	200000 

	This table will be used to audit the update trials on the Budget column (Project table, Company DB)
	Example:
	If a user updated the budget column then the project number, user name that made that update, the date of the modification and the value of the old and the new budget will be inserted into the Audit table
	Note: This process will take place only if the user updated the budget column
*/

SELECT * FROM SD.dbo.Project
GO
	CREATE TABLE AuditTABLE
	(
		ProjectNo NVARCHAR(50),
		UserName NVARCHAR(50),
		ModifiedDate DATE,
		Budget_Old INT,
		Budget_New INT
	)
GO
	INSERT AuditTABLE VALUES ('p2', 'Dbo', '2008-01-31', 95000, 200000)
GO
	SELECT * FROM AuditTABLE
GO
	
	ALTER TRIGGER AuditTableProject
		ON Project
			AFTER UPDATE
				AS
					IF UPDATE(Budget)
						BEGIN
							DECLARE @OldBudget INT, @NewBudget INT, @ProjectNo NVARCHAR(5)
							SELECT @OldBudget=Budget FROM deleted
							SELECT @NewBudget=Budget FROM inserted
							SELECT @ProjectNo = ProjectNo FROM deleted

							INSERT INTO AuditTABLE VALUES (@ProjectNo, SUSER_NAME(), GETDATE(), @OldBudget, @NewBudget)
						END
GO 
	UPDATE SD.dbo.Project SET Budget = 5000 WHERE ProjectNo = 'p2'
	SELECT * FROM AuditTABLE
	UPDATE Project SET Budget = 95000 WHERE ProjectNo ='p2'


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
	 6)  Create a trigger that prevents the insertion Process for Employee table in March [Company DB].
*/
SELECT * FROM Employee
GO
	ALTER TRIGGER PreventONMarch
		ON Employee
			INSTEAD OF INSERT
				AS
					DECLARE @CurrentMonth NVARCHAR(10)
					SELECT @CurrentMonth= MONTH(GETDATE())
						IF @CurrentMonth = '3'
							BEGIN
								SELECT 'You cannot insert on Employee Table in March'
							END
						ELSE
							BEGIN
								INSERT INTO Employee 
								SELECT * FROM inserted
							END
GO
	INSERT INTO Employee VALUES ('124356','Ibrahim', 'Hassan', 'd2',43400)


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- 11)  Use the following variable to create a new table “customers” inside the company DB.Use OpenXML

	declare @docs xml ='<customers>
              <customer FirstName="Bob" Zipcode="91126">
                     <order ID="12221">Laptop</order>
              </customer>
              <customer FirstName="Judy" Zipcode="23235">
                     <order ID="12221">Workstation</order>
              </customer>
              <customer FirstName="Howard" Zipcode="20009">
                     <order ID="3331122">Laptop</order>
              </customer>
              <customer FirstName="Mary" Zipcode="12345">
                     <order ID="555555">Server</order>
              </customer>
       </customers>'

declare @hdocs int
Exec sp_xml_preparedocument @hdocs output, @docs

SELECT * into  xmlCustomers
	FROM OPENXML (@hdocs, '//customer')  --levels  XPATH Code
	WITH (
		FirstName varchar(20) '@FirstName',
		Zipcode varchar(20) '@Zipcode',
		orderID int 'order/@ID',
		product varchar(20) 'order'
	)

	Exec sp_xml_removedocument @hdocs
GO

	select * from xmlCustomers