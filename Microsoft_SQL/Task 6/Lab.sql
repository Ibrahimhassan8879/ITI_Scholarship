-- Lab 6
USE SD

--------------------------------------------------------------------------------------------------------------------------------
sp_addtype loc,'varchar(11)'
CREATE RULE x as @x IN ('NY','DS','KW')
CREATE DEFAULT def AS 'NY'
sp_bindrule x, loc 
sp_bindefault def, loc

CREATE TABLE Department
(
	DeptNo NCHAR(3) PRIMARY KEY,
	DeptName VARCHAR(20),
	Location loc,
);


CREATE TABLE Employee
(
	EmpNo INT PRIMARY KEY,
	EmpFname VARCHAR(15) NOT NULL,
	EmpLname VARCHAR(15) NOT NULL,
	DeptNo NCHAR(3) ,
	FOREIGN KEY(DeptNo) REFERENCES Department(DeptNo),
	Salary INT UNIQUE,
);

CREATE RULE Rule2 as @y < 6000
sp_bindrule Rule2, 'Employee.Salary'


--Query 1--------------------------------------------------------------------------------------------------------------------------------
INSERT INTO Department (DeptNo, DeptName, Location) VALUES
('d1', 'Research', 'NY'),
('d2', 'Accounting', 'DS'),
('d3', 'Marketing', 'KW');


--Query 2--------------------------------------------------------------------------------------------------------------------------------
INSERT INTO Employee (EmpNo, EmpFname, EmpLname, DeptNo, Salary) VALUES
(25348, 'Mathew', 'Smith', 'd3', 2500),
(10102, 'Ann', 'Jones', 'd3', 3000),
(18316, 'John', 'Barrimore', 'd1', 2400),
(29346, 'James', 'James', 'd2', 2800),
(9031, 'Lisa', 'Bertoni', 'd2', 4000),
(2581, 'Elisa', 'Hansel', 'd2', 3600),
(28559, 'Sybl', 'Moser', 'd1', 2900);

--Query 3--------------------------------------------------------------------------------------------------------------------------------
INSERT INTO Project (ProjectNo, ProjectName, Budget) VALUES
('p1', 'Apollo', 120000),
('p2', 'Gemini', 95000),
('p3', 'Mercury', 185600);

--Query 4--------------------------------------------------------------------------------------------------------------------------------
INSERT INTO Works_on (EmpNo, ProjectNo, Job, Enter_Date) VALUES
(10102, 'p1', 'Analyst', '2006-10-01'),
(10102, 'p3', 'Manager', '2012-01-01'),
(25348, 'p2', 'Clerk', '2007-02-15'),
(18316, 'p2', NULL, '2007-06-01'),
(29346, 'p2', NULL, '2006-12-15'),
(2581, 'p3', 'Analyst', '2007-10-15'),
(9031, 'p1', 'Manager', '2007-04-15'),
(28559, 'p1', NULL, '2007-08-01'),
(28559, 'p2', 'Clerk', '2012-02-01'),
(9031, 'p3', 'Clerk', '2006-11-15'),
(29346, 'p1', 'Clerk', '2007-01-04');


--Testing Queries--------------------------------------------------------------------------------------------------------------------------------
INSERT INTO Works_on (EmpNo) VALUES (11111);

UPDATE Works_on SET EmpNo = 11111
WHERE EmpNo = 10102

UPDATE Employee SET EmpNo = 22222
WHERE EmpNo = 10102

DELETE FROM Employee WHERE EmpNo = 10102

ALTER TABLE Employee ADD  TelephoneNumber INT

ALTER TABLE Employee DROP COLUMN TelephoneNumber

ALTER SCHEMA Company TRANSFER Project

DROP SCHEMA Company

ALTER SCHEMA Company TRANSFER dbo.Department

ALTER SCHEMA Human_Resource TRANSFER dbo.Employee


-- Query 4 --------------------------------------------------------------------------------------------------------------------------------
CREATE SYNONYM Emp 
for Employee

Select * FROM Employee
Select * FROM Human_Resource.Employee
Select * FROM Emp
Select * FROM Human_Resource.Emp

-- Query 5 --------------------------------------------------------------------------------------------------------------------------------
UPDATE Company.Project SET Budget = 1.1*Budget
WHERE ProjectNo IN (SELECT ProjectNo FROM Works_on WHERE Job = 'Manager' AND EmpNo = 10102)

-- Query 6 --------------------------------------------------------------------------------------------------------------------------------
UPDATE Company.Department SET DeptName = 'Sales'
WHERE DeptNo IN ( SELECT DeptNo FROM Human_Resource.Employee WHERE EmpFname = 'James')


-- Query 7 --------------------------------------------------------------------------------------------------------------------------------
UPDATE Works_on SET Enter_Date = '2007-12-12'
FROM Works_on W JOIN Company.Project P
ON W.ProjectNo = P.ProjectNo
JOIN Human_Resource.Employee E
ON W.EmpNo = E.EmpNo
JOIN Company.Department D
ON E.DeptNo = D.DeptNo
WHERE D.DeptName = 'Sales' AND P.ProjectNo='p1'


-- Query 8 --------------------------------------------------------------------------------------------------------------------------------
DELETE FROM Works_on
WHERE EmpNo IN ( SELECT EmpNo FROM Human_Resource.Employee E JOIN Company.Department  D ON E.DeptNo = D.DeptNo WHERE D.Location = 'KW')

