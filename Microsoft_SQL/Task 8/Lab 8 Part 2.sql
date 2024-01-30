-- Lab 8 Part 2
use SD

--------------------------------------------------------------------------------------------------------------------------------
-- 1)	Create view named   “v_clerk” that will display employee#,project#, the date of hiring of all the jobs of the type 'Clerk'.

ALTER VIEW v_clerk
	WITH ENCRYPTION
		AS
			SELECT CONCAT(E.EmpFname, ' ', E.EmpLname) AS [Full Name], P.ProjectName, W.Enter_Date 
			FROM SD.dbo.Employee E JOIN SD.dbo.Works_on W 
			ON E.EmpNo = W.EmpNo 
			JOIN SD.dbo.Project P 
			ON W.ProjectNo = P.ProjectNo 
			WHERE W.Job = 'Clerk'

GO
	SELECT * FROM v_clerk

--------------------------------------------------------------------------------------------------------------------------------
-- 2)	 Create view named  “v_without_budget” that will display all the projects data without budget

ALTER VIEW v_without_budget
	WITH ENCRYPTION
		AS
			SELECT ProjectNo, ProjectName FROM SD.dbo.Project

GO
	SELECT * FROM v_without_budget

--------------------------------------------------------------------------------------------------------------------------------
-- 3)	Create view named  “v_count “ that will display the project name and the # of jobs in it

SELECT * FROM SD.dbo.Project
select * from Works_on
SELECT * FROM Project

ALTER VIEW v_count(Project_Name, NumberofJobs)
	WITH ENCRYPTION
		AS
			SELECT P.ProjectName, COUNT(W.Job) AS [Number of Jobs] FROM Project P JOIN Works_on W ON P.ProjectNo = W.ProjectNo GROUP BY P.ProjectName

GO
	SELECT * FROM v_count

--------------------------------------------------------------------------------------------------------------------------------
-- 4)	 Create view named ” v_project_p2” that will display the emp#  for the project# ‘p2’ use the previously created view  “v_clerk”

ALTER VIEW v_project_p2
	WITH ENCRYPTION
		AS
			SELECT P.ProjectName, V.NumberofJobs FROM v_count V JOIN Project P ON V.Project_Name = P.ProjectName WHERE P.ProjectNo = 'p2'

GO
	SELECT * FROM v_project_p2

--------------------------------------------------------------------------------------------------------------------------------
-- 5)	modifey the view named  “v_without_budget”  to display all DATA in project p1 and p2 

ALTER VIEW v_without_budget
	WITH ENCRYPTION
		AS
			SELECT ProjectNo, ProjectName FROM Project WHERE ProjectNo IN ('p1', 'p2')
GO
	SELECT * FROM v_without_budget

--------------------------------------------------------------------------------------------------------------------------------
-- 6)	Delete the views  “v_ clerk” and “v_count”

DROP VIEW v_clerk, v_count

--------------------------------------------------------------------------------------------------------------------------------
--7)	Create view that will display the emp# and emp lastname who works on dept# is ‘d2’
SELECT * FROM Department

ALTER VIEW EMPNLname
	WITH ENCRYPTION
		AS
			SELECT E.EmpNo, E.EmpLname FROM Employee E JOIN Department D ON E.DeptNo = D.DeptNo WHERE D.DeptNo = 'd2'
GO
	SELECT * FROM EMPNLname

--------------------------------------------------------------------------------------------------------------------------------
--8)	Display the employee  lastname that contains letter “J” Use the previous view created in Q#7

CREATE VIEW EmpJ
	WITH ENCRYPTION
		AS
			SELECT * FROM EMPNLname WHERE EmpLname LIKE '%J%'
GO
	SELECT * FROM EmpJ

--------------------------------------------------------------------------------------------------------------------------------
-- 9)	Create view named “v_dept” that will display the department# and department name.

CREATE VIEW v_dept
	WITH ENCRYPTION
		AS
			SELECT DeptNO, DeptName FROM Department
GO
	SELECT * FROM v_dept

--------------------------------------------------------------------------------------------------------------------------------
--10)	using the previous view try enter new department data where dept# is ’d4’ and dept name is ‘Development’

INSERT INTO v_dept VALUES ('d4', 'Development')

--------------------------------------------------------------------------------------------------------------------------------
--11)	Create view name “v_2006_check” that will display employee#, the project #where he works and the date of joining the project which must be from the first of January and the last of December 2006.

ALTER VIEW v_2006_check
	WITH ENCRYPTION
		AS
			SELECT E.EmpNo, W.ProjectNo, W.Enter_Date FROM Employee E JOIN Works_on W ON E.EmpNo = W.EmpNo WHERE Enter_Date BETWEEN '2006-1-1' AND '2006-12-31'
GO
	SELECT * FROM v_2006_check